import numpy as np
from .import_ng0 import import_ng0

def get_kidney_params(fname):
	#Given an input ng0 file, gets relevant params to simulate an A3 kidney scan. 
	'''
	Input - filename of MACS data 

	Output - Relevant parameters to the simulation:
		A3 angles
		Incident energies
		Final energies
		beta1 angles
		beta2 angles
	

	'''
	data, column_labels, file_params = import_ng0(fname)
	HF = 1 
	VF = 1
	sample_diameter_d=0.02
	misalign_mono_deg=0.15 
	slit_h = 0.2 
	slit_v = 0.2
	resolution_mode=0
	for i in range(len(column_labels)):
		if column_labels[i]=='A3':
			A3_i = i 
		if column_labels[i]=='Kidney':
			kidney_i = i 
		if column_labels[i]=='Ei':
			Ei_i = i 
		if column_labels[i]=='Ef':
			Ef_i = i 
		if column_labels[i]=='Beta1':
			beta_1_i = i 
		if column_labels[i]=='Beta2':
			beta_2_i = i 
	kidney_angle = np.mean(data[:,kidney_i].astype(float))
	Ei = np.mean(data[:,Ei_i].astype(float))
	Ef_all = np.mean(data[:,Ef_i].astype(float))
	beta1 = np.mean(data[:,beta_1_i].astype(float))
	beta2 = np.mean(data[:,beta_2_i].astype(float))
	#Need to get the A3 scan array 
	A3_arr = data[:,A3_i].astype(float)
	return A3_arr,kidney_angle,Ei,Ef_all,beta1,beta2