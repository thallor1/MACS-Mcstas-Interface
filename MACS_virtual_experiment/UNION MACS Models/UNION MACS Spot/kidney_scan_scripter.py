#Quick script to automate McStas kidney_angle scripts

import numpy as np 
import math 

#First determine the list of angles, call kidney_angles.py
#Angles now in array kpositions

angle_file = 'macs_kidneylimit_new.txt'

#Take in incident energy, i.e. monochromator

Ei = input('Ei = ')

#Take in number of kidney steps

da4 = input('A4 Angular Steps = ')

#Get initial, final kidney angles from that using predefined limits

dict= {}
angle_mat = np.genfromtxt(angle_file)
for row in angle_mat:
	dict[row[0]]=[row[1],row[2]]

#Find closest Ei in the dictionary

list_Ei= angle_mat[:,0]

def find_nearest(array,value):
    idx = (np.abs(array-value)).argmin()
    return array[idx]

Ei = find_nearest(list_Ei,Ei)

#Now have Init, Final kidney angles

Ki = dict[Ei][0]
Kf = dict[Ei][1]
#print(Ki)
#print(Kf)

#Calculate kidney step size

kidney_range = Kf - Ki 
a4_range = kidney_range+8.0*19.0
Ntot = a4_range/da4 
stepin = kidney_range / (Ntot / 20.0)

#Now calculate optimum angles to avoid overlap

N = max(round(Kf-Ki)/8 , 1)
m = int(round(8*N/stepin))
i=m 
for i in range(m,m+100):
	if((i/8)*8 != i):
		if((i/N)*N != i):
			break
	i=m 
steps = 8.0*N/i 

total_steps = int(math.floor((Kf - Ki)/steps)+1)
range = (total_steps-1)*(steps)+0.001
nnkcen=(Kf+Ki)/2 
kpositions = nnkcen-range/2+np.arange(total_steps)*steps

#Now take in the input energy, output energy, N, MPI, A3 Range

Ei = input('Monochromator Ei (5meV)= ') or 5
Ef = input('Analyzer energy Ef (5meV)= ') or 5

A3min = input('Minimum A3 (-90)= ') or -90
A3max = input('Max A3 (90)= ') or 90
Steps = input('Number A3 Steps (181)= ') or 181

n = input('Desired neutron count = (1E7)') or 1E7 
#MPI = input('Number of Threads cores = (4) ') or 4

beta_1 = raw_input('beta 1= (1)') or 1 
beta_2 = raw_input('beta_2= (1)') or 1

speed_mode = raw_input('Speed Mode? (Use more than one thread, y/n)')
if speed_mode=='y':
	num_cores = input('Enter number of CPU nodes to use.')
else:
	num_cores=8

#Take in a base file name to differentiate experiments

baseName = raw_input('Input base file name for experiment: ')

#Write param file for each kidney angle

def writeParams(param_file, kidney_angle, Ei, Ef):
	param_file.write('A3_angle=0 \n')
	param_file.write('kidney_angle='+str(kidney_angle)+' \n')
	param_file.write('EM='+str(Ei)+' \n')
	param_file.write('EF_all='+str(Ef)+' \n')
	param_file.write('HF=1 \n')
	param_file.write('VF=1 \n')
	param_file.write('sample_diameter_d=0.02 \n')
	param_file.write('beta_1=1 \n')
	param_file.write('beta_2=1 \n')
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
	param_file.write( 'monrot_delta=0 \n')
	param_file.write( 'slit_h=0.2 \n')
	param_file.write('slit_v=0.2 \n')
	param_file.write('resolution_mode=0 \n')
	param_file.write('res_radius=0.01 \n')
	param_file.write('res_height=0.03 \n')
	param_file.write('repeat_count=2 \n')
	param_file.write('E0_resolution=0 \n')
	param_file.write('dE_resolution=1 \n')
	param_file.close()


for angle in kpositions:
	param_file_name = baseName+'_param_'+str(round(angle,3))
	param_file = open(param_file_name, 'w')
	writeParams(param_file, angle, Ei, Ef)


#Write the script to a file

def writeScriptLine(script_file, angle, baseName):
	script_file.write('mcrun MACS_sample_kidney.instr -d '+baseName+'_'+str(round(angle,3))+' -n '+str(n)+' -N'+str(Steps)+' A3_angle='
		+str(A3min)+',' +str(A3max)+' EM='+str(Ei)+' EF_all='+str(Ef)+' kidney_angle='+str(kidney_angle)+' beta_1='+str(beta_1)+' beta_2='+str(beta_2)+' >/dev/null\n')

def speed_writeScriptLine(script_file, angle, baseName, speed_param):
	if speed_param==True:
		token = ' &'
	else:
		token = ''
	if MPI==1:
		script_file.write('mcrun MACS_sample_kidney.instr -d '+baseName+'_'+str(round(angle,3))+' -n '+str(n)+' -N'+str(Steps)+' A3_angle='
			+str(A3min)+',' +str(A3max)+' EM='+str(Ei)+' EF_all='+str(Ef)+' kidney_angle='+str(angle)+' beta_1='+str(beta_1)+' beta_2='+str(beta_2)+' >/dev/null '+token+'\n')
	else:
		script_file.write('mcrun -d '+baseName+'_'+str(round(angle,3))+' -p '+baseName+'_param_'
			+str(round(angle,3))+' -n '+str(n)+' --mpi='+str(MPI)+' -N'+str(Steps)+' A3_angle='
			+str(A3min)+',' +str(A3max)+' EM='+str(Ei)+' EF_all='+str(Ef)+' kidney_angle='+str(angle)+' beta_1='+str(beta_1)+' beta_2='+str(beta_2)+' >/dev/null\n')

script_file=open(baseName+'.sh', 'w')
if speed_mode=='y':
	#Write to the mpi number of different files
	#For example if there are 8 cores, and the user has requested 4 MPI, call 2 different processes.
	#If the user has 8 cores and calles 2 MPI, 4 different processes, etc
	#Same exact as normal case, but add an ampersand at the very end
	#Also adding a '>/dev/null' to suppress the silly amount of output
	i=0
	for angle in kpositions:
		if i >= (num_cores/MPI -1):
			speed_param=False
			i=0
		else:
			speed_param=True
			i=i+1
		speed_writeScriptLine(script_file, angle, baseName, speed_param)
		script_file.write('echo '+'\"Kidney angle '+str(round(angle,3))+' complete.\" \n')

else:
	for angle in kpositions:
		writeScriptLine(script_file, angle, baseName)
		script_file.write('echo '+'\"Kidney angle '+str(round(angle,3))+' complete.\" \n')
script_file.close()

print('Remember to do chmod +x script.sh to grant write permissions')