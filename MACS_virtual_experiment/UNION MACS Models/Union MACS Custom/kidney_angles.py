#Kidney angle calculator for MACS in python
#Previously in IDL, sort of useless

import numpy as np 
import math 

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
#print(kpositions)