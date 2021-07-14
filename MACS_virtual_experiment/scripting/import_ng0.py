import numpy as np

def import_ng0(fname):
	#given a MACS ng0 file, generates a dictionary of all parameters and a numpy matrix with data
	#More generic than getParamsA3Scan function
	#print('Importing '+fname+'...')
	data = np.genfromtxt(fname,dtype=str)
	column_labels={}
	file_params = {}
	f=open(fname,'r')
	lines = f.readlines()
	#Write all params to a dictionary
	for line in lines:
		param = line.split('\n')[0]
		param_name = param.split()[0].strip('#')
		param_val = param.split()[1:]

		file_params[param_name]=param_val
		if param_name=='Columns':
			#after this is data - break the loop. 
			break
	column_labels=file_params['Columns']

	return data, column_labels, file_params