#  MACS to McStas conversion script
#
#  Takes in a series of MACS ng0 files in a directory and makes a mcstas simulation for each one.
#  Writes the final output to a .sh file which can be run later. 
#
#  Thomas Halloran, Mads Bertelsen, July 2018

from __future__ import print_function
import sys
import re
import numpy as np
import os
import glob
import os.path

baseName='tiO2_110'
num_threads = 12
#number simulated neutrons 
n_mono = 1e6
n=1e6

def getParams(ng0file):
	# Gets all parameters relevant to the instrument simulation from the ng0 file
	# returns a dictionary. 
	#
	# Load in file line by line. 
	#
	# Monochromtor simulation takes following arguments:
	'''
	EM=2.7
	EF_all=2.5
	HF=1
	VF=1
	sample_diameter_d=0.02
	beta_1=1
	beta_2=1
	CPF=0
	MPL=6.06
	MPD=0.775
	APE_h=0.35
	APE_v=0.35
	misalign_mono_deg=0.15
	DIRDEV=0
	DIVSOU=3.0
	L0_delta=-1.06
	L1_delta=0.0
	mon_t=0.0
	mon_e=0.0
	monrot_delta=0
	'''
	# Kidney simulation takes following params:
	'''
	A3_angle=0 
	kidney_angle=35.15615 
	EM=2.5
	EF_all=2.5
	HF=1
	VF=1
	sample_diameter_d=0.02
	beta_1=1
	beta_2=1
	CPF=0
	MPL=6.06
	MPD=0.775
	APE_h=0.35
	APE_v=0.35
	misalign_mono_deg=0.15
	DIRDEV=0
	DIVSOU=3.0
	L0_delta=-1.06
	L1_delta=0.0
	mon_t=0.0
	mon_e=0.0
	monrot_delta=0
	slit_h=0.2
	slit_v=0.2
	resolution_mode=0
	res_radius=0.01
	res_height=0.03
	repeat_count=2
	E0_resolution=0
	dE_resolution=1
	'''
	#List of the params that are contained in the param dictionary output.
	'''

	'''
	# Sequentially read them all in from the input ng0 file or use a default value.
	param_dictionary = {}
	f = open(ng0file,'r')
	lines = f.readlines()
	#Can't guess the row numbers they're not consistent. We'll find them instead.
	k=0
	i=0
	for line in lines:
		if line.split()[0]=='#ScanDescr':
			ScanDescr_i=i
			k=k+1
		if line.split()[0]=='#Columns':
			label_index=i
			k=k+1
		i=i+1 
		if k==2:
			break
	labels = lines[label_index]
	labels= labels.split()[1:]
	#Other important details in the header are Npoints, temp, lattice, orient
	# ScanDescr column also has Npts, Counts, Range=A3=-90.0,90.0
	a3_column = np.where(labels=='A3')
	ScanDescr = lines[ScanDescr_i].split(':')
	for i in range(len(ScanDescr)):
		if ScanDescr[i].split('=')[0]=='Npts':
			N_i=i 
		if ScanDescr[i].split('=')[0]=='Counts':
			Counts_i=i 
		if ScanDescr[i].split('=')[0]=='Range':
			scan_i=i
	data  = np.genfromtxt(ng0file,names=labels)
	N = int(ScanDescr[N_i].split('=')[1])
	Counts = int(float(ScanDescr[Counts_i].split('=')[1]))
	scan = ScanDescr[scan_i].split('=')
	scan_type = scan[1]
	scan_min = np.min(data['A3'])
	scan_max = np.max(data['A3'])
	
	f.close()
	return param_dictionary,N,Counts,scan_type,scan_min,scan_max,data

class ProgressBar(object):
    DEFAULT = 'Progress: %(bar)s %(percent)3d%%'
    FULL = '%(bar)s %(current)d/%(total)d (%(percent)3d%%) %(remaining)d to go'

    def __init__(self, total, width=40, fmt=DEFAULT, symbol='=',
                 output=sys.stderr):
        assert len(symbol) == 1

        self.total = total
        self.width = width
        self.symbol = symbol
        self.output = output
        self.fmt = re.sub(r'(?P<name>%\(.+?\))d',
            r'\g<name>%dd' % len(str(total)), fmt)

        self.current = 0

    def __call__(self):
        percent = self.current / float(self.total)
        size = int(self.width * percent)
        remaining = self.total - self.current
        bar = '[' + self.symbol * size + ' ' * (self.width - size) + ']'

        args = {
            'total': self.total,
            'bar': bar,
            'current': self.current,
            'percent': percent * 100,
            'remaining': remaining}
        print('\r' + self.fmt % args,file=self.output, end='')

    def done(self):
        self.current = self.total
        self()
        print('', file=self.output)

def writeParams(param_file, param_dict, data):
	'''
	Function to write a parameter file for a kidney sim.
	'''
	kidney_angle=np.mean(data['Kidney'])
	Ei = np.mean(data['Ei'])
	Ef = np.mean(data['Ef'])
	beta1 = np.mean(data['Beta1'])
	beta2=np.mean(data['Beta2'])


	param_file.write('A3_angle=0 \n')
	param_file.write('kidney_angle='+str(kidney_angle)+' \n')
	param_file.write('EM='+str(Ei)+'\n')
	param_file.write('EF_all='+str(Ef)+'\n')
	'''
	param_file.write('HF=1\n')
	param_file.write('VF=1\n')
	#param_file.write('sample_diameter_d=0.02\n')
	#param_file.write('beta_1='+str(beta1)+'\n')
	#param_file.write('beta_2='+str(beta2)+'\n')
	param_file.write('CPF=0\n')
	param_file.write('MPL=6.06\n')
	param_file.write('MPD=0.775\n')
	param_file.write('APE_h=0.35\n')
	param_file.write('APE_v=0.35\n')
	param_file.write('misalign_mono_deg=0.15\n')
	param_file.write('DIRDEV=0\n')
	param_file.write('DIVSOU=3.0\n')
	param_file.write('L0_delta=-1.06\n')
	param_file.write('L1_delta=0.0\n')
	param_file.write('mon_t=0.0\n')
	param_file.write('mon_e=0.0\n')
	param_file.write( 'monrot_delta=0\n')
	param_file.write( 'slit_h=0.2\n')
	param_file.write('slit_v=0.2\n')
	param_file.write('resolution_mode=0\n')
	param_file.write('res_radius=0.01\n')
	param_file.write('res_height=0.03\n')
	param_file.write('repeat_count=1\n')
	param_file.write('E0_resolution=0\n')
	param_file.write('dE_resolution=1\n')
	param_file.close()
	'''

def writeParams_mono(param_file,param_dict,data):
	'''
	Function to write a parameter file for a monochromator sim
	'''
	Ei = np.mean(data['Ei'])
	Ef = np.mean(data['Ef'])
	beta1 = np.mean(data['Beta1'])
	beta2=np.mean(data['Beta2'])

	param_file.write('EM='+str(Ei)+'\n')
	param_file.write('EF_all='+str(Ef)+'\n')
	'''
	param_file.write('HF=1\n')
	param_file.write('VF=1\n')
	param_file.write('sample_diameter_d=0.02\n')
	param_file.write('beta_1='+str(beta1)+'\n')
	param_file.write('beta_2='+str(beta2)+'\n')
	param_file.write('CPF=0\n')
	param_file.write('MPL=6.06\n')
	param_file.write('MPD=0.775\n')
	param_file.write('APE_h=0.35\n')
	param_file.write('APE_v=0.35\n')
	param_file.write('misalign_mono_deg=0.15\n')
	param_file.write('DIRDEV=0\n')
	param_file.write('DIVSOU=3.0\n')
	param_file.write('L0_delta=-1.06\n')
	param_file.write('L1_delta=0.0\n')
	param_file.write('mon_t=0.0\n')
	param_file.write('mon_e=0.0\n')
	param_file.write('monrot_delta=0\n')
	param_file.close()
	'''

def speed_writeScriptLine(script_file, angle,Ei_i,Ef, baseName, speed_param,N,A3min,A3max):
	'''
	Function to properly write Mcstas call in script. Specifically for Kidney.
	'''
	if speed_param==True:
		token = ' &'
	else:
		token = ''
	if 1==1:
		script_file.write('mcrun -d '+baseName+'_Ei='+str(round(Ei_i,3))+'meV_A4='+str(round(angle,3))+' -p '+baseName+'_param_'+str(round(angle,3))+'_Ei='+str(round(Ei_i,3))+'meV_Ef='+str(round(np.mean(data['Ef']),3))+'meV.txt -n '+str(n)+' -N'+str(N)+' A3_angle='
			+str(A3min)+',' +str(A3max)+' MACS_sample_kidney.instr >/dev/null'+token+'\n')
	else:
		script_file.write('mcrun -d '+baseName+'_Ei='+str(round(Ei_i,3))+'meV_A4='+str(round(angle,3))+' -p '+baseName+'_param_'+str(round(angle,3))+'_Ei='+str(round(Ei_i,3))+'meV_Ef='+str(round(np.mean(data['Ef']),3))+'meV.txt -n '+str(n)+' -N'+str(Steps)+' A3_angle='
			+str(A3min)+',' +str(A3max)+' MACS_sample_kidney.instr >/dev/null'+token+'\n')

def speed_writeScriptLine_monochromator(script_file, Ei, angle, baseName, speed_param,n_mono=1e6):
	'''
	Function to properly write McStas call in script. Specifically for Monochromator. 
	'''
	energy=Ei
	if speed_param==True:
		token = ' &'
	else:
		token = ''
	if 1==1:
		script_file.write('mcrun -d '+baseName+'_monochromator_Ei_'+str(round(Ei,3))+' -p '+baseName+'_monochromator_'+str(round(energy,3))+'meV.txt'+' -n '+str(n_mono)+' MACS_monochromator.instr'+token+'\n')
	else:
		script_file.write('mcrun -d '+baseName+'_monochromator_Ei_'+str(round(Ei,3)) +' -p '+baseName+'_monochromator_'+str(round(energy,3))+'meV.txt'+' -n '+str(n_mono)+' MACS_monochromator.instr'+token+'\n')


#This first bit should only be done if the monochromator Ei's haven't been simulated already

#First gather a list of all .ng0 files in the directory.
ng0_files = glob.glob('*.ng0')
#Loop through and create necessary monochromator script file to be run first.
if not os.path.exists('MACS_monochromator.c'):
	#Throw an error
	print('Monochromator must be compiled first!')
	print('Try running mcrun -c -n 1e7 MACS_monochromator.instr')
	#quit()
Ei_vals = []
mono_script_file = open(baseName+'_monochromator.sh','w')
i=0
for file in ng0_files:
	param_dictionary,N,Counts,scan_type,scan_min,scan_max,data = getParams(file)
	Ei = np.mean(data['Ei'])
	angle = np.mean(data['Kidney'])
	#Check if this value exists already
	#if not, write a param file for it. 
	# also, add to the script either way.

	if not os.path.exists(baseName+'_monochromator_'+str(round(Ei,3))+'meV.txt'):
		Ei_vals.append(Ei)
		mono_param_file = open(baseName+'_monochromator_'+str(round(Ei,3))+'meV.txt','w')
		writeParams_mono(mono_param_file,param_dictionary,data)
		mono_param_file.close()
	if Ei not in Ei_vals:
		if i%num_threads==0:
			speed_param=False 
		else:
			speed_param=True
		Ei_vals.append(Ei)
		#Add this value to the script

		speed_writeScriptLine_monochromator(mono_script_file, Ei, angle, baseName, speed_param,n_mono=1e6,)
		i=i+1
#Monochromator sim should be ready at this point.
mono_script_file.close()
os.system('chmod +x '+baseName+'_monochromator.sh')

#Prepare the kidney scans, almost always a particular kidney angle with A3 scan.
kidney_script_file = open(baseName+'.sh','w')
i=1

progress= ProgressBar(len(ng0_files),fmt=ProgressBar.FULL)

for file in ng0_files:
	param_dictionary,N,Counts,scan_type,scan_min,scan_max,data = getParams(file)
	#Check to make sure this is an A3 scan- other types not supported.
	if scan_type != 'a3' and scan_type!='A3':
		#Throw an error 
		print(' ')
		print('Deteted Scan type: '+str(scan_type))
		print('Warning- scan types that are not A3 are not yet supported')
	#Write the param file. 
	angle = np.mean(data['Kidney'])
	param_file_name = baseName+'_param_'+str(round(angle,3))+'_Ei='+str(round(np.mean(data['Ei']),3))+'meV_Ef='+str(round(np.mean(data['Ef']),3))+'meV.txt'
	param_file = open(param_file_name,'w')
	writeParams(param_file, param_dictionary, data)
	if i%num_threads==0:
		speed_param=False
	else:
		speed_param=True 
	speed_writeScriptLine(kidney_script_file, angle,np.mean(data['Ei']),round(np.mean(data['Ef']),3), baseName, speed_param,N,scan_min,scan_max)
	i=i+1
	progress.current+=1
	progress()
kidney_script_file.close()
os.system('chmod +x '+baseName+'.sh')