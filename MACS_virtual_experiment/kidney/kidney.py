'''
The purpose of this object is to store the experimentally relevant information regarding the detector bank, also known as the kidney
'''

import numpy as np 
import os
import math

class Kidney(object):
	'''
	Parameters are the following:

	kidney_angle - angle between ki and the center of the kidney itself
	slit_h - horizontal width of presample slit
	slit_v - height of slit before smaple 

	'''
	def __init__(self,kidney_angle=0,Ef=5.0,slit_h=0.2,slit_v=0.2):
		self.kidney_angle=kidney_angle
		self.slit_h=slit_h
		self.slit_v=slit_v
		self.Ef=Ef

	def generate_kidney_positions(self,da4,Ei=5.0):
		'''
		Generates a list of kidney positions for an A4 scan given a desired angle resolution
		'''
		angle_file = os.path.dirname(__file__)+'/macs_kidneylimit_new.txt'
		print(angle_file)
		angle_dict= {}
		angle_mat = np.genfromtxt(angle_file)
		for row in angle_mat:
			angle_dict[row[0]]=[row[1],row[2]]
		#Find closest Ei in the dictionary
		list_Ei= angle_mat[:,0]
		def find_nearest(array,value):
		    idx = (np.abs(array-value)).argmin()
		    return array[idx]

		Ei = find_nearest(list_Ei,Ei)

		#Now have Init, Final kidney angles

		Ki = angle_dict[Ei][0]
		Kf = angle_dict[Ei][1]

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
		rangeT = (total_steps-1)*(steps)+0.001
		nnkcen=(Kf+Ki)/2.0
		kpositions = nnkcen-rangeT/2.0+np.arange(total_steps)*steps

		return kpositions