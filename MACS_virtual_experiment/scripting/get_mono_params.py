import numpy as np
from .import_ng0 import import_ng0


def get_mono_params(fname):
	#subroutine to gather naming info for monochromator simulation
	#Works using output from import_ng0
	#Input is a file string, output are the params relevant to simulation of monochromator
	data, column_labels, file_params = import_ng0.import_ng0(fname)

	Ei_index = 0
	beta1_index=0
	beta2_index=0
	Ef_index =0
	for i in range(len(column_labels)):
		if column_labels[i]=='Ei':
			Ei_index=i 
		if column_labels[i]=='Beta1':
			beta1_index=i 
		if column_labels[i]=='Beta2':
			beta2_index=i 
		if column_labels[i]=='Ef':
			Ef_index=i
		if Ei_index !=0 and beta1_index!=0 and beta2_index!=0 and Ef_index!=0:
			break
	#Extract values for Ei, beta1, beta2 
	Ei=np.around(np.mean(data[:,Ei_index].astype(float)),4)
	Ef=np.around(np.mean(data[:,Ef_index].astype(float)),4)
	beta1 = np.around(np.mean(data[:,beta1_index].astype(float)),4)
	beta2 = np.around(np.mean(data[:,beta2_index].astype(float)),4)
	return Ei,Ef,beta1,beta2
