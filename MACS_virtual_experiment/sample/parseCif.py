import numpy as np
import shlex
import CifFile


def parseCIF(cif_file):
	'''
	A wrapper for the "ReadCif" untility from externaly python library.
	Given a cif, returns a dictionary with relevant attributes defined by the parameters in the line. 
	'''
	cif_import = CifFile.ReadCif(cif_file)
	if len(cif_import.dictionary)>1:
		#Multiple phases specified in cif file- get the one with data inside
		for i in range(len(cif_import.dictionary)):
			curr_key = cif_import.keys()[i]
			try:
				key = curr_key 
				cell_a = cif_import[curr_key]['_cell_length_a']
				#If this worked, this is good
				break
			except KeyError:
				cell_a = 0
	else:
		key = cif_import.keys()[0]
	return cif_import[key]