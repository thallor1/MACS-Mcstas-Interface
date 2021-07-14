#Function to automate the scripting of a monochromator scan
#Assumption is made that beta1=beta2=1.0

import numpy as np 
import math 
import datetime
import os

from kidney_scan_scripter_spot import script_kidney_scan


def writeParams_mono(param_file,Ei,Ef,sample_diameter_d):
	'''
	Function to write a parameter file for a monochromator sim
	'''

	param_file.write('EM='+str(Ei)+'\n')
	param_file.write('EF_all='+str(Ef)+'\n')
	param_file.write('sample_diameter_d='+str(sample_diameter_d))

def speed_writeScriptLine_monochromator(script_file, Ei, baseName, speed_param,n_mono=1e6):
	'''
	Function to properly write McStas call in script. Specifically for Monochromator. 
	'''
	energy=Ei
	if speed_param==True:
		token = ' &'
	else:
		token = ''
	if 1==1:
		script_file.write('mcrun -d '+baseName+'_monochromator_Ei_'+str(round(Ei,3)).replace('.','p')+' -p '+baseName+'_monochromator_'+str(round(energy,3))+'meV.txt'+' -n '+str(n_mono)+' MACS_monochromator.instr'+token+'\n')
	else:
		script_file.write('mcrun -d '+baseName+'_monochromator_Ei_'+str(round(Ei,3)).replace('.','p') +' -p '+baseName+'_monochromator_'+str(round(energy,3))+'meV.txt'+' -n '+str(n_mono)+' MACS_monochromator.instr'+token+'\n')
	return 1

def initialize_monochromater_scans(Ei_list,baseName,num_threads,n_mono,Ef,sample_diameter_d):
	#Loop through and create necessary monochromator script file to be run first.
	if not os.path.exists('MACS_monochromator.c'):
		#Throw an error
		print('Monochromator must be compiled first!')
		print('Try running mcrun -c -n 1e7 MACS_monochromator.instr')
		#quit()
	Ei_vals = Ei_list
	mono_script_file = open(baseName+'_monochromator.sh','w')
	i=0
	for j in range(len(Ei_vals)):
		Ei = Ei_vals[j]
		#Check if this value exists already
		#if not, write a param file for it. 
		# also, add to the script either way.

		if not os.path.exists(baseName+'_monochromator_'+str(round(Ei,3))+'meV.txt'):
			mono_param_file = open(baseName+'_monochromator_'+str(round(Ei,3))+'meV.txt','w')
			writeParams_mono(mono_param_file,Ei,Ef,sample_diameter_d)
			mono_param_file.close()
		if i%num_threads==0:
			speed_param=False 
		else:
			speed_param=True
		#Add this value to the script
		speed_writeScriptLine_monochromator(mono_script_file, Ei, baseName,speed_param,n_mono)
		i=i+1
	mono_script_file.close()
	#Run the scans now
	os.system('chmod +x '+baseName+'_monochromator.sh')
	#os.system(baseName+'_monochromator.sh')
	return 1



def script_Ei_scan_spot(Ei_list=[5.0,5.5],n_mono=1e7,Ef=5.0,da4=0.5,A3min=-90.0,A3max=90.0,Steps=181,n=1e6,beta_1=1.0,beta_2=1.0,\
	speed_mode='y',num_cores=4,baseName=str(datetime.datetime.now())[0:19].replace('-','_').replace(' ','__').replace(':','_')
+'_mcstasSim',\
	spot_delta=1.0,spot_twoTheta=30.0,sample_tilt=60.0,sample_diameter_d=0.005,sample_length=0.02,MPI=4):
	x = initialize_monochromater_scans(Ei_list,baseName,num_cores,n_mono,Ef,sample_diameter_d)
	for Ei in Ei_list:

		print('\n###############')
		print('Monochromator scans either already done or successfully completed. ')
		print('Move the large .dat files from the individual folders to the main directory.')
		print('#################\n')
		#Now handle the kidney scans
		x=script_kidney_scan(Ei,Ef,da4,A3min,A3max,Steps,n,beta_1,beta_2,\
			speed_mode,num_cores,baseName,\
			spot_delta,spot_twoTheta,sample_tilt,sample_diameter_d,sample_length,MPI)
	print('Remember to use chmod +x to update permissions on the .sh file')
	return 1