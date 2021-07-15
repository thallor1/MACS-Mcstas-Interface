import os
import numpy as np
import sample 
import monochromator
import kidney 
import macsdata
import shutil
import copy
import subprocess
import time
import glob
from scripting import import_ng0
from scripting import get_kidney_params
from scripting import get_mono_params
from joblib import Parallel,delayed 
import multiprocessing as mp

'''
This is the main class for the package. Initializes all of the other parts of the experiment. 

Contains the following Methods:
	1. initialize_sample_from_cif - replaces default sample object with a user defined one
	2. All instrument parameters can be set in object. 
	3. Single MCstas scan can be run with a simple call after all parameters are set
	4. An A3 range can be given to run a scan in sample rotation, with specified kidney angle resolution.
	5. A set of Ei values can be given to run scans in energy. Note there are no angles assosciated with this
	6. A combined angle and energy scan with given number of A3 steps, Ei steps, and A4 resolution
	7. Initalize instrument parameters based on an ng0 file. 
	8. Iterate over a directory of ng0 files, running mcstas scans to match each angle/energy
	9. Iterate over a directory of mcstas scans to create ng0 files (one for each Ei) that are readable by DAVE


'''

class virtualMACS(object):
	'''
	Most of the parameters are stored in these objects:
	kidney 
	monochromator
	sample

	The Mcstas models theselves are prewritten and compiled so the user should not have to worry
	about that. Compilation only occurrs upon changing the .instr file itself.

	Input params are the following:
		exptName - directory in which all of the simulations will be stored
		cifName - not technically mandatory but if given will initialize the sample object
	'''
	def __init__(self,exptName,cifName=None,useOld=False):
		self.exptName=exptName
		if cifName is not None:
			self.sample=sample.Sample(ciffile=cifName)
		else:
			self.sample=sample.Sample()
		self.monochromator=monochromator.Monochromator()
		self.kidney=kidney.Kidney()
		#If it does not exist, make an experiment directory. 
		cwd=os.getcwd()
		if not os.path.exists(cwd+'/'+exptName):
			os.mkdir(cwd+'/'+exptName)
		self.exptdir=cwd+'/'+exptName 
		self.cwd = cwd
		self.data=macsdata.Data(self.sample,self.exptName,kidney_result_dir=self.exptdir+'/Kidney_simulations/')

		#Now some elements that are usually only needed for the simulations
		self.n_sample = 1e6
		self.n_mono = 1e6 
		self.A3_angle = 0.0
		self.kidney_angle_resolution = 1.0 #Should be set by user eventually
		self.repeat_count = 1 
		self.output_dir = self.exptdir+'/macs_kidney_scan_1'
		self.instr_template_dir =None 
		self.kidney_instr_dir=None
		self.monochromator_instr_file = 'MACS_monochromator.instr'
		self.mono_param_dir=None 
		self.kidney_param_dir=None
		self.useOld=useOld
		self.mono_scanList=[] # Will keep track of the scans that have been run. 
		self.kidney_scanList=[]
		self.instr_file_directory = cwd+'/'+self.exptName+'/Instrument_files/' 
		self.modified_kidney_flag=0 #keeps track of if the instr file must be recompiled.
		self.base_ng0 = False
		self.kidsim_dir = cwd+'/'+self.exptName+'/Kidney_simulations/'
		#Name of ramdisk directory for simulation output.
		self.ramdisk_dir = '/tmp/memory'
		self.ramdisk_size='2G'#This can be changed by user manually if needed but it should never get larger than this. 
		self.sudo_password = 'password' #Plaintext password for sudo access to disk, this needs to be fixed later.
		self.data.kidney_sim_dir=self.ramdisk_dir+'/Kidney_simulations/'
		self.preserve_kidney_scan_files = False #Flag to determine if files are deleted from ramdisk after each scan.
		self.preserve_kidney_param_files= False #Flag to determine if individual kidney parmeter files are preserved. 
		i=2
		while os.path.exists(self.output_dir):
			self.output_dir = self.exptdir+'/macs_kidney_scan_'+str(i) #Prevents default directory from already existing
			i+=1
		
		i=0

	def mount_ramdisk(self):
		#Mounts a ramdisk for use in simulation outputs
		#First check if it is already mounted or not.
		if os.path.ismount(self.ramdisk_dir):
			return 1
		else:
			if not os.path.exists(self.ramdisk_dir):
				os.system('echo \''+str(self.sudo_password)+'\' |sudo -S mkdir '+self.ramdisk_dir)
			os.system('echo \''+str(self.sudo_password)+'\' | sudo -S chmod 777 '+str(self.ramdisk_dir))
			os.system('echo \''+str(self.sudo_password)+'\' | sudo -S mount -t tmpfs -o size='+str(self.ramdisk_size)+' mcstasramdisk '+self.ramdisk_dir)
		print('RAMDISK mounted in '+self.ramdisk_dir)
		print('Ensure tmpfs is unmounted safely.')

	def unmount_ramdisk(self):
		#Deletes contents of the ramdisk and unmounts it, returning the disk to pure memory
		if os.path.ismount(self.ramdisk_dir):
			#Unount
			os.system('echo \''+str(self.sudo_password)+'\' | sudo -S umount -l '+self.ramdisk_dir)
		if os.path.exists(self.ramdisk_dir):
			#Delete this folder
			os.system('echo \''+str(self.sudo_password)+'\' | sudo -S rm -rf '+self.ramdisk_dir)
		return 1

	def clear_ramdisk(self):
		#Deletes contents of the ramdisk
		if os.path.exists(self.ramdisk_dir):
			#Delete this folder
			os.system('echo \''+str(self.sudo_password)+'\' | sudo -S rm -rf '+self.ramdisk_dir)
		return 1

	def prepare_old_expt_directory(self):
		#Prevents the instrument from needing to be recompiled, instantites the right simulation files
		#without moving them. 
		cwd=os.getcwd()
		if self.useOld==True:
			if not os.path.exists(cwd+'/'+self.exptName+'/Instrument_files/'):
				print('Experiment of title '+str(self.exptName)+' not found in this directory.')
				print('Will regenerate the instruement and recompile.')
			else:
				#Get the type of experiment this was
				macs_file = glob.glob(self.instr_file_directory+'MACS_sample_kidney_*.instr')[0]
				if 'cylinder' in macs_file:
					self.sample.sample_shape='cylinder'
					self.instr_main_file='MACS_sample_kidney_cylinder.instr'
				elif 'box' in macs_file:
					self.sample.sample_shape='box'
					self.instr_main_file='MACS_sample_kidney_box.instr'
				else:
					print('Sorry- not implemented yet. ')
				#Refer simulations to these files which should already be compiled.
			self.instr_main_file=self.instr_file_directory+self.instr_main_file
		return 1

	def clean_expt_directory(self):
		#Removes old files from the experiment directory excpet for monochromator scans
		cwd = os.getcwd()
		files_in_kidsims = glob.glob(cwd+'/'+self.exptName+'/Kidney_simulations/*')
		while len(files_in_kidsims)>=1:
			files_in_kidsims = glob.glob(cwd+'/'+self.exptName+'/Kidney_simulations/*')
			os.system('rm -rf '+cwd+'/'+self.exptName+'/param_files_kidney')
			os.system('rm -rf '+cwd+'/'+self.exptName+'/Kidney_simulations')
			time.sleep(1)
		return 1

	def prepare_expt_directory(self):
		#Geneartes an instrument file using the current instrument parameters. Places it in the experiment directory.
		#The template file will depend on the sample used. 
		if type(self.sample.laufile)==bool:
			#Need to generate and assign lau file
			self.sample.cif2lau()

		cwd=os.getcwd()
		self.instr_template_dir=os.path.dirname(__file__)+'/UNION MACS Models/UNION MACS Base/'
		self.kidney_instr_dir = os.path.dirname(__file__)+'/UNION MACS Models/UNION MACS Kidney Files/'
		if self.sample.sample_shape not in ['box','cylinder','powder','spot']:
			print('WARNING: Only allowed sample shapes are [box, cylinder, powder, spot]')
			print('Instr file not written. ')
		if self.sample.sample_shape=='cylinder':
			instr_main_file = 'MACS_sample_kidney_cylinder.instr'
			self.instr_main_file=instr_main_file
		if self.sample.sample_shape=='box':
			instr_main_file = 'MACS_sample_kidney_box.instr'
			self.instr_main_file=instr_main_file
			#first make a copy of the template files and put them into a new experiment directory
		while os.path.exists(cwd+'/'+self.exptName+'/Instrument_files'):
			print('WARNING: Old instrument directory found. Older files deleted, instrument will need to be recompiled.')
			os.system('rm -rf '+cwd+'/'+self.exptName.replace(' ','\ '))
			self.clean_expt_directory()
		self.instr_file_directory = cwd+'/'+self.exptName+'/Instrument_files/' 
		self.instr_main_file = self.instr_file_directory+self.instr_main_file #This now points directly to the instr file that will be modified
		#Copy the base files into the new instrument directory
		shutil.copytree(self.instr_template_dir,self.instr_file_directory)
		#Copy the particular instrument file into the instrument directory
		shutil.copy(self.kidney_instr_dir+instr_main_file,self.instr_file_directory)
		#Also need to move the lau file into the instrument directory
		shutil.copy(cwd+'/'+self.sample.laufile,self.instr_file_directory)
		shutil.copy(cwd+'/'+self.sample.ciffile,self.instr_file_directory)

		return 1

	def edit_instr_file(self):
		#Edits the currently active instrument file to match the sample parameters
		#First step is to load in the instr file.
		#self.prepare_expt_directory() #This has to be done if we are updating the file itself.
		print('Generating sample parameters using file '+str(self.sample.ciffile))
		print('Writing instrument file assuming scattering u='+str(self.sample.orient_u)+', v='+str(self.sample.orient_v))
		#Generate the labframe for the sample 
		self.sample.project_sample_realspace()
		sampmat = np.copy(self.sample.labframe_mat)
		#This is what is in the instr file by default and must be replaced by the relevant sample params. 
		if self.sample.sample_shape=='cylinder':
			blockstr='*/ \n'+\
			  '   samp_ax = '+str(sampmat[0,0])+'; //can be calculated from lattice params and u v matrix \n'+\
			  '   samp_ay = '+str(sampmat[0,1])+'; \n'+\
			  '   samp_az = '+str(sampmat[0,2])+'; \n'+\
			  '   samp_bx = '+str(sampmat[1,0])+'; \n'+\
			  '   samp_by = '+str(sampmat[1,1])+'; \n'+\
			  '   samp_bz = '+str(sampmat[1,2])+'; \n'+\
			  '   samp_cx = '+str(sampmat[2,0])+'; \n'+\
			  '   samp_cy = '+str(sampmat[2,1])+'; \n'+\
			  '   samp_cz = '+str(sampmat[2,2])+'; \n'+\
			  '   samp_abs_xc = '+str(self.sample.rho_abs)+'; \n'+\
			  '   samp_mosaic = '+str(self.sample.sample_mosaic)+'; \n'+ \
			  '   samp_delta_d = '+str(self.sample.delta_d)+'; \n'+\
			  '   samp_inc_xc = '+str(self.sample.sigma_inc)+'; \n'+\
			  '   samp_cell_vol = '+str(self.sample.cell_vol)+'; \n'+\
			  '   samp_length = '+str(self.sample.sample_length)+'; \n'+\
			  '   crystal_axis_xrot = '+str(self.sample.crystal_axis_xrot)+'; \n'+\
			  '   crystal_axis_yrot = '+str(self.sample.crystal_axis_yrot)+' ; \n'+\
			  '   crystal_axis_zrot = '+str(self.sample.crystal_axis_zrot)+'; \n'+\
			  '/*'
		elif self.sample.sample_shape=='box':
			blockstr='*/ \n'+\
			  '   samp_ax = '+str(sampmat[0,0])+'; //can be calculated from lattice params and u v matrix \n'+\
			  '   samp_ay = '+str(sampmat[0,1])+'; \n'+\
			  '   samp_az = '+str(sampmat[0,2])+'; \n'+\
			  '   samp_bx = '+str(sampmat[1,0])+'; \n'+\
			  '   samp_by = '+str(sampmat[1,1])+'; \n'+\
			  '   samp_bz = '+str(sampmat[1,2])+'; \n'+\
			  '   samp_cx = '+str(sampmat[2,0])+'; \n'+\
			  '   samp_cy = '+str(sampmat[2,1])+'; \n'+\
			  '   samp_cz = '+str(sampmat[2,2])+'; \n'+\
			  '   samp_abs_xc = '+str(self.sample.rho_abs)+'; \n'+\
			  '   samp_mosaic = '+str(self.sample.sample_mosaic)+'; \n'+ \
			  '   samp_delta_d = '+str(self.sample.delta_d)+'; \n'+\
			  '   samp_inc_xc = '+str(self.sample.sigma_inc)+'; \n'+\
			  '   samp_cell_vol = '+str(self.sample.cell_vol)+'; \n'+\
			  '   samp_xwidth = '+str(self.sample.sample_widx)+'; \n'+\
			  '   samp_ywidth = '+str(self.sample.sample_widy)+'; \n'+\
			  '   samp_zwidth = '+str(self.sample.sample_widz)+'; \n'+\
			  '   crystal_axis_xrot = '+str(self.sample.crystal_axis_xrot)+'; \n'+\
			  '   crystal_axis_yrot = '+str(self.sample.crystal_axis_yrot)+' ; \n'+\
			  '   crystal_axis_zrot = '+str(self.sample.crystal_axis_zrot)+'; \n'+\
			  '/*'
		#Replace the block in the instrument file with this.
		instr_f = open(self.instr_main_file,'r')
		contents = instr_f.readlines()
		instr_f.close()
		
		for i in range(len(contents)):
			#Find the index of the string /* BEGIN INSERT BLOCK
			if 'BEGIN INSERT BLOCK' in contents[i]:
				insert_i = i+1
				
		f=open(self.instr_main_file,'w')
		contents.insert(insert_i,blockstr)
		f.writelines(contents)
		f.close()
		
		#Also need to update the following strings : REPLACETHISSTRINGWITHLAUE , replacethiswithusersamplename
		with open(self.instr_main_file) as f:
			newText = f.read().replace('REPLACETHISSTRINGWITHLAUE',self.sample.laufile)
		with open(self.instr_main_file,'w') as f:
			f.write(newText)
		with open(self.instr_main_file) as f:
			newText = f.read().replace('replacethiswithusersamplename',self.sample.laufile.split('.')[0])
		with open(self.instr_main_file,'w') as f:
			f.write(newText)
		
		with open(self.instr_main_file,'r') as f:
			filedata = f.read()
		#Insert all of the values for the single crystal process
		if self.sample.sample_shape=='cylinder':
			filedata = filedata.replace('REPLACEsamp_delta_d',str(self.sample.delta_d))
			filedata = filedata.replace('REPLACEsamp_mosaic',str(self.sample.sample_mosaic))
			filedata = filedata.replace('REPLACEsamp_ax',str(sampmat[0,0]))
			filedata = filedata.replace('REPLACEsamp_ay',str(sampmat[0,1]))
			filedata = filedata.replace('REPLACEsamp_az',str(sampmat[0,2]))
			filedata = filedata.replace('REPLACEsamp_bx',str(sampmat[1,0]))
			filedata = filedata.replace('REPLACEsamp_by',str(sampmat[1,1]))
			filedata = filedata.replace('REPLACEsamp_bz',str(sampmat[1,2]))
			filedata = filedata.replace('REPLACEsamp_cx',str(sampmat[2,0]))
			filedata = filedata.replace('REPLACEsamp_cy',str(sampmat[2,1]))
			filedata = filedata.replace('REPLACEsamp_cz',str(sampmat[2,2]))
			filedata = filedata.replace('REPLACEsamp_abs_xc',str(self.sample.rho_abs))
			filedata = filedata.replace('REPLACEsamp_inc_xc',str(self.sample.sigma_inc))
			filedata = filedata.replace('REPLACEsamp_cell_vol',str(self.sample.cell_vol))
			filedata = filedata.replace('REPLACEsample_radius',str(self.sample.sample_diameter_d/2.0))
			filedata = filedata.replace('REPLACEsamp_length',str(self.sample.sample_length))
			filedata = filedata.replace('REPLACEcrystal_axis_xrot',str(self.sample.crystal_axis_xrot))
			filedata = filedata.replace('REPLACEcrystal_axis_yrot',str(self.sample.crystal_axis_yrot))
			filedata = filedata.replace('REPLACEcrystal_axis_zrot',str(self.sample.crystal_axis_zrot))
		elif self.sample.sample_shape=='box':
			filedata = filedata.replace('REPLACEsamp_delta_d',str(self.sample.delta_d))
			filedata = filedata.replace('REPLACEsamp_mosaic',str(self.sample.sample_mosaic))
			filedata = filedata.replace('REPLACEsamp_ax',str(sampmat[0,0]))
			filedata = filedata.replace('REPLACEsamp_ay',str(sampmat[0,1]))
			filedata = filedata.replace('REPLACEsamp_az',str(sampmat[0,2]))
			filedata = filedata.replace('REPLACEsamp_bx',str(sampmat[1,0]))
			filedata = filedata.replace('REPLACEsamp_by',str(sampmat[1,1]))
			filedata = filedata.replace('REPLACEsamp_bz',str(sampmat[1,2]))
			filedata = filedata.replace('REPLACEsamp_cx',str(sampmat[2,0]))
			filedata = filedata.replace('REPLACEsamp_cy',str(sampmat[2,1]))
			filedata = filedata.replace('REPLACEsamp_cz',str(sampmat[2,2]))
			filedata = filedata.replace('REPLACEsamp_abs_xc',str(self.sample.rho_abs))
			filedata = filedata.replace('REPLACEsamp_inc_xc',str(self.sample.sigma_inc))
			filedata = filedata.replace('REPLACEsamp_cell_vol',str(self.sample.cell_vol))
			filedata = filedata.replace('REPLACEsamp_xwidth',str(self.sample.sample_widx/2.0))
			filedata = filedata.replace('REPLACEsamp_ywidth',str(self.sample.sample_widy/2.0))
			filedata = filedata.replace('REPLACEsamp_zwidth',str(self.sample.sample_widz/2.0))
			filedata = filedata.replace('REPLACEcrystal_axis_xrot',str(self.sample.crystal_axis_xrot))
			filedata = filedata.replace('REPLACEcrystal_axis_yrot',str(self.sample.crystal_axis_yrot))
			filedata = filedata.replace('REPLACEcrystal_axis_zrot',str(self.sample.crystal_axis_zrot))
		else:
			print('WARNING: Invalid sample shape. Allowed values are currently cylinder, box.')	
		with open(self.instr_main_file,'w') as f:
			f.write(filedata)
		
		print(' ')
		print('Instrument file '+str(self.instr_main_file)+' successfully prepared.\n')
		print('Ready to compile.\n')
		print(' ')
		self.modified_kidney_flag=1
		return 1 

	def compileInstr(self):
		'''
		Simple function to run the instrument compiler before beginnning scan. 

		No arguments are taken it is simply called.

		'''
		#First generate c code, need to actually go into the directories to excecute these operations
		instr_dir = self.instr_file_directory
		instr_filename = self.instr_main_file.split('/')[-1]
		c_filename = instr_filename.replace('.instr','.c')
		out_filename = instr_filename.replace('.instr','.out')
		original_directory = os.getcwd()
		os.chdir(instr_dir)
		shellcommand = ['mcstas','-o',c_filename,instr_filename]
		shellcommandstr ='mcstas -o '+c_filename+' '+instr_filename
		#shellcommandstr = 'mcrun -c '+instr_filename
		p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
		(output,err)=p.communicate()
		p_status=p.wait()
		#os.system(shellcommandstr)
		#Give it a moment to make sure that code is written.
		os.system('python2 generate_MACS_parts.py')
		time.sleep(0.3)
		# Something like cc -O -o MACS_sample_kidney.out MACS_sample_kidney.c -lm

		shellcommand=['cc','-O','-o',out_filename,\
			c_filename,'-lm']
		shellcommandstr='cc -O -o '+out_filename+' '+\
			c_filename+' -lm'
		#shellcommandstr='mcrun -c '+instr_filename
		print('#################')
		print('\nStarting compilation of sample kidney geometry. This will take about an hour and use a')
		print('large amount of memory, on the order of 30 Gb.\n')
		print('Passing following compilation command:')
		print(shellcommandstr)
		p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
		(output,err)=p.communicate()
		p_status=p.wait()
		print('Compilation of sample kidney geometry successful.\n')
		print('#################\n')
		os.chdir(original_directory)
		self.modified_kidney_flag=0
		#Wait for this to finish. 
		return 1

	def compileMonochromator(self):
		'''
		Simple function to compile the monochromator
		'''
		#First generate c code, need to actually go into the directories to excecute these operations
		instr_dir = self.instr_file_directory
		instr_filename = 'MACS_monochromator.instr'
		c_filename = instr_filename.replace('.instr','.c')
		out_filename = instr_filename.replace('.instr','.out')
		original_directory = os.getcwd()
		os.chdir(instr_dir)
		shellcommand = ['mcstas','-o',c_filename,instr_filename]
		shellcommandstr ='mcstas -o '+c_filename+' '+instr_filename

		os.system(shellcommandstr)
		#Give it a moment to make sure that code is written.
		time.sleep(0.5)
		# Something like cc -O -o MACS_sample_kidney.out MACS_sample_kidney.c -lm

		shellcommand=['cc','-O','-o',out_filename,\
			c_filename,'-lm']
		shellcommandstr='cc -O -o '+out_filename+' '+\
			c_filename+' -lm'
		#shellcommandstr= 'mcrun -c'+instr_filename
		print('#################')
		print('\nStarting compilation of monochromator. This will take about around 10 minutes and use a')
		print('large amount of memory, on the order of 20 Gb.')
		#shellcommandstr='mcrun -c '+instr_filename
		print('Passing following compilation command:')
		print(shellcommandstr)
		p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
		(output,err)=p.communicate()
		p_status=p.wait()
		print('Compilation of monochromator geometry successful.\n')
		print('#################\n')

		os.chdir(original_directory)
		return 1


	def write_mono_paramfile_from_current_params(self):
		cwd=self.cwd
		if not os.path.exists(cwd+'/'+self.exptName+'/param_files_monochromator/'):
			os.mkdir(cwd+'/'+self.exptName+'/param_files_monochromator/')
		self.mono_param_dir = self.exptdir+'/param_files_monochromator/'
		out_name = self.mono_param_dir+'mono_params_ei'+'{:.2f}'.format(self.monochromator.Ei)+'_beta1_'+'{:.3f}'.format(self.monochromator.beta_1)+'_beta2_'+'{:.3f}'.format(self.monochromator.beta_2)+'_sample_diameter_d_'+'{:.4f}'.format(self.sample.sample_diameter_d)+'.txt'

		#Correctly format the parameter file with the current parameters.

		output_str='EM='+str(self.monochromator.Ei)+'\ndEM=0.1\nEF_all='+str(self.kidney.Ef)+'\nHF=1\nVF=1\nsample_diameter_d='+str(self.sample.sample_diameter_d)+'\nbeta_1='+str(self.monochromator.beta_1)+'\nbeta_2='+str(self.monochromator.beta_2)+'\nCPF=0\nMPL=6.06\nMPD=0.775\nAPE_h=0.35\nAPE_v=0.35\nmisalign_mono_deg=0.15\nkidney_angle=0\nDIRDEV=0\nDIVSOU=3.0\nL0_delta=-1.06\nL1_delta=0.0\nmon_t=0.0\nmon_e=0.0\nmonrot_delta=0\nwrite_virtual_out=1'
		param_file = open(out_name,'w')
		param_file.write(output_str)
		param_file.close()
		return out_name


	def write_kidney_paramfile_from_current_params(self):
		#First check if there exists a directory for parameter files
		orig_dir = self.cwd
		if not os.path.exists(orig_dir+'/'+self.exptName+'/param_files_kidney/'):
			os.mkdir(orig_dir+'/'+self.exptName+'/param_files_kidney/')
		self.kidney_param_dir=self.exptdir+'/param_files_kidney/'
		
		#Format the string with the most important information
		out_name_prefix = self.exptName+'_kidney_params_Ei_'+str(round(self.monochromator.Ei,2))+'_kid_angle_'+str(round(self.kidney.kidney_angle,4))+'_A3_angle_'+str(self.A3_angle)+'_Ef_'+str(round(self.kidney.Ef,2))+'.txt'
		out_name_prefix=out_name_prefix.replace('-','m')
		out_name = self.kidney_param_dir+out_name_prefix
		param_file = open(out_name,'w')
		param_file.write('A3_angle='+str(self.A3_angle)+' \n')
		param_file.write('kidney_angle='+str(self.kidney.kidney_angle)+' \n')
		param_file.write('EM='+str(self.monochromator.Ei)+' \n')
		param_file.write('EF_all='+str(self.kidney.Ef)+' \n') 
		param_file.write('HF=1 \n')
		param_file.write('VF=1 \n')
		param_file.write('sample_diameter_d='+str(self.sample.sample_diameter_d)+' \n')
		param_file.write('beta_1='+str(self.monochromator.beta_1)+' \n')
		param_file.write('beta_2='+str(self.monochromator.beta_2)+' \n')
		param_file.write('CPF=0 \n')
		param_file.write('MPL=6.06 \n')
		param_file.write('MPD=0.775 \n')
		param_file.write('APE_h=0.35 \n')
		param_file.write('APE_v=0.35 \n')
		param_file.write('misalign_mono_deg=0.15 \n')
		param_file.write('DIRDEV=0 \n')
		param_file.write('DIVSOU=3.0 \n')
		param_file.write('L0_delta=-1.06 \n')
		param_file.write('L1_delta=0.0 \n')
		param_file.write('mon_t=0.0 \n')
		param_file.write('mon_e=0.0 \n')
		param_file.write('monrot_delta=0 \n')
		param_file.write('slit_h=0.2 \n')
		param_file.write('slit_v=0.2 \n')
		param_file.write('resolution_mode=0 \n')
		param_file.write('res_radius=0.01 \n')
		param_file.write('res_height=0.03 \n')
		param_file.write('repeat_count=2 \n')
		param_file.write('E0_resolution=0 \n')
		param_file.write('dE_resolution=1 \n')
		param_file.close()
		return out_name

	def runMonoScan(self,Ei_set=False,Ef_set=False,kidney_set=False,A3_set=False,beta_1_set = False, beta_2_set =False):
		#Check if an output directory exists for monochromator scans
		cwd = self.cwd
		if not os.path.exists(self.exptdir+'/Monochromator_simulations/'):
			os.mkdir(cwd+'/'+self.exptName+'/Monochromator_simulations/')

		#Assign relevant parameters
		if Ei_set==False:
			Ei_set=self.monochromator.Ei 
		if Ef_set==False:
			Ef_set=self.kidney.Ef
		if kidney_set==False:
			kidney_set=self.kidney.kidney_angle
		if A3_set==False:
			A3_set = self.A3_angle
		if beta_1_set==False:
			beta_1_set=self.monochromator.beta_1 
		if beta_2_set==False:
			beta_2_set=self.monochromator.beta_2

		#Generate a parameter file for the current monochromator configuration
		param_fname = self.write_mono_paramfile_from_current_params()
		#Need to add the instrument directory for the imports to be recognized
		os.chdir(cwd+'/'+self.exptName+'/Instrument_files/')
		#Check if the file already exists. If it does, do not run the simulation.
		mono_file_dat_start='E'+'{:.2f}'.format(Ei_set)+'meV_HF1_VF1_Sample'+'{:.3f}'.format(self.sample.sample_diameter_d)+'_'+\
			'b1_'+'{:.2f}'.format(beta_1_set)+'_b2_'+'{:.2f}'.format(beta_2_set)+'*'
		try:
			if len(glob.glob(mono_file_dat_start))==0:
				mono_dir = 'Ei_'+str(Ei_set)+'_beta1_'+str(beta_1_set)\
				+'_beta2_'+str(beta_2_set)+'_n_'+str(self.n_mono)+'_sample_diam_'+str(self.sample.sample_diameter_d)
				#Run simulation and wait for it to end.

				shellcommandstr='mcrun -d '+mono_dir+' -n '+str(self.n_mono)+\
					' MACS_monochromator.instr EM='+str(Ei_set)+' dEM=0.1 EF_all='+str(Ef_set)+' HF=1 VF=1 sample_diameter_d='+str(self.sample.sample_diameter_d)+' beta_1='+str(beta_1_set)+\
					' beta_2='+str(beta_2_set)+' misalign_mono_deg=0.15 CPF=0 MPL=6.06 MPD=0.775 APE_h=0.35 APE_v=0.35 misalign_mono_deg=0.15 '+\
					'kidney_angle='+str(kidney_set)+' DIRDEV=0 DIVSOU=3.0 L0_delta=-1.06 L1_delta=0.0 mon_t=0.0 mon_e=0.0 monrot_delta=0 write_virtual_out=1'
				print('Passing the following to mcstas:')
				print(shellcommandstr)
				p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
				(output,err)=p.communicate()
				p_status=p.wait()
				#Move the output folder to the Monochromator_simulations directory
				shutil.move(mono_dir,cwd+'/'+self.exptName+'/Monochromator_simulations/')
				#Delete the old simulation.
				os.system('rm -rf '+str(mono_dir))
				time.sleep(0.1)
				os.chdir(cwd)
				#Iterate through mono_dir and add the data file outputs to the main instrument directory
				#Get the name of the monochromator data file 
				#mono_file_dat_start='E'+'{:.2f}'.format(self.monochromator.Ei)+'meV_HF1_VF1*'
				#the location of the monochromator file
				mono_dat_dir = cwd+'/'+self.exptName+'/Monochromator_simulations/'+mono_dir+'/'
				mono_file_dat_name = glob.glob(mono_dat_dir+mono_file_dat_start)[0]
				#Move the file to the instrument directory
				if not os.path.exists(self.instr_file_directory+mono_file_dat_name):
					shutil.copy(mono_file_dat_name,self.instr_file_directory)
					time.sleep(1)
			else:
				#print('Using previously run monochromator simulation that is already in the directory: ')
				#print(glob.glob(mono_file_dat_start)[0])
				os.chdir(cwd)
		except Exception as e:
			print('Warning: Execution error in monochromator scan. ')
			print(e)
		return 1


	def runKidneyScan(self,append_data_matrix=True,Ei_set=False,Ef_set=False,kidney_set=False,A3_set=False,beta_1_set=False,beta_2_set=False,\
		scan_suffix=False):
		#Runs a kidney scan using specified parameters.
		#If parameters are not specified, defaults to object settings
		if Ei_set==False:
			Ei_set=self.monochromator.Ei 
		if Ef_set==False:
			Ef_set=self.kidney.Ef
		if kidney_set==False:
			kidney_set=self.kidney.kidney_angle
		if A3_set==False:
			A3_set = self.A3_angle
		if beta_1_set==False:
			beta_1_set=self.monochromator.beta_1 
		if beta_2_set==False:
			beta_2_set=self.monochromator.beta_2
		self.monochromator.Ei=Ei_set
		self.kidney.Ef=Ef_set
		self.A3_angle=A3_set
		self.monochromator.beta_1=beta_1_set
		self.monochromator.beta_2=beta_2_set
		param_fname = self.write_kidney_paramfile_from_current_params()

		orig_dir = self.cwd
		#Make an output directory for the results
		if not os.path.exists(self.exptdir+'/Kidney_simulations/'):
			os.mkdir(orig_dir+'/'+self.exptName+'/Kidney_simulations/')
			self.kidsim_dir = orig_dir+'/'+self.exptName+'/Kidney_simulations/'
		param_fname = self.write_kidney_paramfile_from_current_params()
		#Change to the instrument directory 
		os.chdir(orig_dir+'/'+self.exptName+'/Instrument_files/')

		#If the scan was based off of an ng0 file need to add a string
		if self.base_ng0==False:
			ng0_string = ''
		else:
			ng0_string = '_'+self.base_ng0
		#Put this in a ramdisk to solve disk access problems large numbers of files for large simulations.
		kidney_output_dir = self.exptName+ng0_string+'_kidney_angle_'+'{:.4f}'.format(kidney_set)+'_Ei_'+\
			'{:.2f}'.format(Ei_set)+'_Ef_'+'{:.2f}'.format(Ef_set)+'_A3_angle_'+'{:.3f}'.format(A3_set)+\
			'_sample_diameter_d_'+'{:.4f}'.format(self.sample.sample_diameter_d)+'_n_'+str(self.n_sample)
		#Mcstas does not like minus signs or . in directory names
		kidney_output_dir=kidney_output_dir.replace('-','m')
		kidney_output_dir=kidney_output_dir.replace('.','p')
		#Mount the ramdisk if it has not been mounted yet. 
		if not os.path.ismount(self.ramdisk_dir):
			self.mount_ramdisk()
		kidney_output_dir=self.ramdisk_dir+'/'+kidney_output_dir
		#Check if the current simulation already exists in the data matrix.
		if type(self.data.data_matrix)==bool:
			#Not instantiated, scan definitely does not exist.
			scan_exists = False
		else:
			#Check if a row exits with the same Ei, Ef, A3, kidney_angle. That should cover the case of running the same scan.
			A3 = self.data.data_matrix['A3'].tolist()
			Ei = self.data.data_matrix['Ei'].tolist()
			Ef = self.data.data_matrix['Ef'].tolist()
			kidney = self.data.data_matrix['Kidney'].tolist()
			#Add a rounding error tolerance to each of these
			A3 = np.around(A3,3)
			Ei=np.around(Ei,3)
			Ef = np.around(Ef,3)
			kidney = np.around(kidney,3)
			#Turn these into a single numpy array where each row is a configuration
			config_mat = np.concatenate((A3[:,None],Ei[:,None],Ef[:,None],kidney[:,None]),axis=1)
			this_config = [np.around(A3_set,3),np.around(Ei_set,3),np.around(Ef_set,3),np.around(kidney_set,3)]
			if this_config in config_mat.tolist():
				scan_exists=True
			else:
				scan_exists=False

		if not scan_exists:
			#Folder does not exist, run the simulation
			#Run simulation and wait for it to end.
			shellcommandstr='mcrun -d '+kidney_output_dir+' -n '+str(self.n_sample)+' '+self.instr_main_file.split('/')[-1]+' A3_angle='+str(A3_set)+' kidney_angle='+str(kidney_set)+' EM='+str(Ei_set)+' EF_all='+str(Ef_set)+\
				' HF=1 VF=1 sample_diameter_d='+str(self.sample.sample_diameter_d)+' beta_1='+str(beta_1_set)+' beta_2='+str(beta_2_set)+' CPF=0 MPL=6.06 MPD=0.775 APE_h=0.35 APE_v=0.35 misalign_mono_deg=0.15 DIRDEV=0 DIVSOU=3.0 L0_delta=-1.06 L1_delta=0.0 mon_t=0.0 '+\
				'mon_e=0.0 monrot_delta=0.0 slit_h=0.2 slit_v=0.2 resolution_mode=0 res_radius=0.01 res_height=0.03 repeat_count=1 E0_resolution=0 dE_resolution=1'
			#print('Running the following command: ')
			#print(shellcommandstr)
			p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
			(output,err)=p.communicate()
			p_status=p.wait()
			#Scan is run at this point and output files are in the kidney_output_dir
			#Append the result to the data matrix if this is a single scan. Else wait to do this until later.
			#Either way write the csv file
			if scan_suffix==False:
				suffix=''
			else:
				suffix=scan_suffix
			self.data.scan_to_csv(kidney_output_dir,file_suffix=suffix)
			time.sleep(0.01)
			#Delete the directory after this
			if self.preserve_kidney_scan_files==False:
				while os.path.exists(kidney_output_dir):
					try:
						os.system('rm -rf '+str(kidney_output_dir))
					except Exception as e:
						print('Warning: \n'+str(e))
						time.sleep(0.01)
			if self.preserve_kidney_param_files==False:
				while os.path.exists(param_fname):
					try:
						os.system('rm '+param_fname)
					except Exception as e:
						print('Warning when trying to remove paramter file:')
						print(e)
			os.chdir(orig_dir)

		else:
			print('Found previous identical kidney simulation. If this is a mistake, ')
			print('delete the scan from the data matrix and try again. ')
			print(kidney_output_dir)
			os.chdir(orig_dir)
		#Delete the parameter file unless otherwise specified. 
		return 1

	def runKidneyScan_scripting(self,A3,kidney_angle,Ei,Ef,beta1,beta2,append_data_matrix=True,scan_suffix=False):
		#Run the simulation at this point 
		self.runKidneyScan(append_data_matrix=append_data_matrix,Ei_set=Ei,Ef_set=Ef,kidney_set=kidney_angle,A3_set=A3,beta_1_set = beta1, beta_2_set = beta2,scan_suffix=scan_suffix)
		return 1
	def runMonoScan_scripting(self,Ei,Ef,beta1,beta2):
		#Run the simulation at this point 
		self.runMonoScan(Ei_set=Ei,Ef_set=Ef,kidney_set=self.kidney.kidney_angle,A3_set=self.A3_angle,beta_1_set = beta1, beta_2_set = beta2)
		return 1

	def script_scan(self,A3_list,Ei_list=False,num_threads=1,scan_title=False):
		#Provided with a list of A3 angles, a kidney angle resolution, optionally a list\
		# of incident energies, simulates a MACS scan over the full range.
		# Num-threads parameter is for parallelization.
		if scan_title==False:
			suffix=False
		else:
			suffix=scan_title
		if type(Ei_list)==bool:
			Ei_list=[self.monochromator.Ei]
		elif type(Ei_list)==float or type(Ei_list)==int:
			Ei_list=np.array([Ei_list])
		elif type(Ei_list)==list or type(Ei_list)==np.ndarray:
			#This is good they did it right
			Ei_list = np.array(Ei_list)
		else:
			print('Warning- Ei input in a strange format. Using '+str(self.monochromator.Ei)+' meV')
			Ei_list = np.array([self.monochromator.Ei])
		#Mount the ramdisk
		self.mount_ramdisk()
		#Run the relevant monochromator scans.
		if num_threads>1:
			print('Running these Ei values:'+str(Ei_list))
			Parallel(n_jobs=num_threads)(delayed(self.runMonoScan_scripting)(Ei,self.kidney.Ef,self.monochromator.beta_1,self.monochromator.beta_2) for Ei in Ei_list)
		else:
			for Ei in Ei_list:
				self.monochromator.Ei = Ei 
				self.runMonoScan()
		#Generate kidney angles
		if num_threads==1:
			for energy in Ei_list:
				kid_angle_list = self.kidney.generate_kidney_positions(self.kidney_angle_resolution,energy)
				#Simple case first, num_threads=1
				for a3_angle in A3_list:
					for kid_angle in kid_angle_list:
						self.runKidneyScan_scripting(a3_angle,kid_angle,energy,self.kidney.Ef,True,suffix)
		if num_threads>1:
			#Now do the case of parallelized
			for energy in Ei_list:
				kid_angle_list = self.kidney.generate_kidney_positions(self.kidney_angle_resolution,energy)
				num_operations = len(kid_angle_list)*len(Ei_list)
				for kid_angle in kid_angle_list:
					#Parallelization happens here
					#A3,kidney_angle,Ei,Ef,beta1,beta2,append_data_matrix=True
					Parallel(n_jobs=num_threads)(delayed(self.runKidneyScan_scripting)\
							(A3_list[i],kid_angle,energy,self.kidney.Ef,self.monochromator.beta_1,self.monochromator.beta_2,True,suffix) \
							for i in range(len(A3_list)))

		#Unmount the ramdisk safely.
		if self.preserve_kidney_scan_files==False:
				self.unmount_ramdisk()
		#Combine the scan into a single csv, if a suffix marker has been specified
		if type(suffix)!=bool:
			self.data.combine_csv_scans(preserve_old=False,flagstr=suffix)
		return 1

	def simulate_ng0(self,ng0_file,in_scan=False,n_threads=1):
		#Mount the ramdisk
		self.mount_ramdisk()
		#Directly simulates an input ng0 file from start to finish.
		data, column_names, file_params = import_ng0(ng0_file)
		print('Emulating scan from '+str(ng0_file.split('/')[-1]))
		A3_list = np.array(data[:,file_params['Columns'].index('A3')]).astype(float)
		Ei_list = np.array(data[:,file_params['Columns'].index('Ei')]).astype(float)
		Ef_list = np.array(data[:,file_params['Columns'].index('Ef')]).astype(float)
		beta_1_list = np.array(data[:,file_params['Columns'].index('Beta1')]).astype(float)
		beta_2_list = np.array(data[:,file_params['Columns'].index('Beta2')]).astype(float)
		kid_list = np.array(data[:,file_params['Columns'].index('Kidney')]).astype(float)
		ptai_det = np.array(data[:,file_params['Columns'].index('PTAI')]).astype(int)
		self.data.PTAI_det=ptai_det[0]
		self.beta_1=beta_1_list[0]
		self.beta_2=beta_2_list[0]
		#Check if the file is in a directory 
		ng0_file = ng0_file.split('/')[-1]
		self.base_ng0=ng0_file
		#First run the monochromator jobs
		if n_threads==1 or in_scan==True:
			for i in range(len(A3_list)):
				self.runMonoScan_scripting(Ei_list[i],Ef_list[i],beta_1_list[i],beta_2_list[i])
			#The run the kidney / A3 jobs
			for i in range(len(A3_list)):
				self.runKidneyScan_scripting(A3_list[i],kid_list[i],Ei_list[i],Ef_list[i],beta_1_list[i],beta_2_list[i],append_data_matrix=True,\
					scan_suffix='_'+ng0_file.split('/')[-1])
		if n_threads>1 and in_scan==False:
			#Parallelize this process, not necessary for monochromator
			for i in range(len(A3_list)):
				self.runMonoScan_scripting(Ei_list[i],Ef_list[i],beta_1_list[i],beta_2_list[i])
			Parallel(n_jobs=n_threads)(delayed(self.runKidneyScan_scripting)\
							(A3_list[i],kid_list[i],Ei_list[i],Ef_list[i],beta_1_list[i],beta_2_list[i],True,\
								'_'+ng0_file.split('/')[-1]) for i in range(len(A3_list)))
		#Safely unmount ramdisk.
		if in_scan==False and self.preserve_kidney_scan_files==False:
			self.unmount_ramdisk()
		else:
			#Instead just delete the files in the ramdisk so as to not interrupt other scans.
			x=1
		#Combine the relevant data matrices into a single file
		self.data.combine_csv_scans(preserve_old=False,flagstr='_'+ng0_file.split('/')[-1])
		if in_scan==False:
			#Not parellelized, may write this data matrix to a matching ng0 file.
			csv_file = '_'+ng0_file.split('/')[-1]+\
					self.data.csv_name
			self.data.load_data_matrix_from_csv(csv_file)
			self.data.write_data_to_ng0(filename=ng0_file.split('/')[-1].replace('.ng0','_mcStas.ng0'))
		return 1

	def simulate_ng0dir(self,ng0_dir,n_threads=1):
		#Iterate of a directory containing ng0 files

		#First mount ramdisk
		self.mount_ramdisk()

		#They may also be in folders, but nothing else should be in this folder.
		file_list = []
		cwd=os.getcwd()
		for (dirpath,dirnames,filenames) in os.walk(ng0_dir):
			for file in filenames:
				if '.ng0' in file:
					file_list.append(file)
		if n_threads==1:
			for file in file_list:
				self.simulate_ng0(file,in_scan=False)
		else:
			#Need to do monochromator jobs FIRST, then kidney
			ei_ef_b1_b2_list = []
			for ng0_file in file_list:
				print('Ng0 file:')
				print(ng0_file)
				#Need to do monochromator jobs FIRST, then kidney
				#Accumulate all Ei, beta1, beta2 combinations and run.
				data, column_names, file_params = import_ng0(ng0_dir+ng0_file)
				A3_list = np.array(data[:,file_params['Columns'].index('A3')]).astype(float)
				Ei_list = np.array(data[:,file_params['Columns'].index('Ei')]).astype(float)
				Ef_list = np.array(data[:,file_params['Columns'].index('Ef')]).astype(float)
				beta_1_list = np.array(data[:,file_params['Columns'].index('Beta1')]).astype(float)
				beta_2_list = np.array(data[:,file_params['Columns'].index('Beta2')]).astype(float)
				kid_list = np.array(data[:,file_params['Columns'].index('Kidney')]).astype(float)
				ptai_det = np.array(data[:,file_params['Columns'].index('PTAI')]).astype(int)
				for i in range(len(Ei_list)):
					Ei = Ei_list[i]
					Ef = Ef_list[i]
					b1 = beta_1_list[i]
					b2 = beta_2_list[i]
					setting = [Ei,Ef,b1,b2]
					if setting not in ei_ef_b1_b2_list:
						ei_ef_b1_b2_list.append(setting)
			print('Monochromator List to simulate:')
			print('Ei, beta1, beta2 ='+str(ei_ef_b1_b2_list))
			#Run all of the relevant monochromator jobs
			Parallel(n_jobs=n_threads)(delayed(self.runMonoScan_scripting)(ei_ef_b1_b2_list[i][0],ei_ef_b1_b2_list[i][1],ei_ef_b1_b2_list[i][2],\
				ei_ef_b1_b2_list[i][3]) for i in range(len(ei_ef_b1_b2_list)))
			Parallel(n_jobs=n_threads)(delayed(self.simulate_ng0)(cwd+'/'+ng0_dir+file_list[i],in_scan=True) for i in range(len(file_list)))
			#After parellel jobs are done, iterate through the files and create matching ng0s as the measurements, but McStas
			for ng0_file in file_list:
				self.data.load_data_matrix_from_csv(self.exptdir+'/Kidney_simulations/'+self.exptName+'_'+ng0_file.split('/')[-1]+\
					self.data.csv_name)
				self.data.write_data_to_ng0(filename=ng0_file.split('/')[-1].replace('.ng0','_mcStas.ng0'))
		#At this point generate the data matrix. all files should be in the ramdisk. Information cannot be allowed to sit in the ramdisk.
		return 1
