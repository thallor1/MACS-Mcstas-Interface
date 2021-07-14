#Python Script to convert McStas output to MACS
#Thomas Halloran

import numpy as np
import sys
import os, os.path
import glob 
import time
rootdir = os.path.dirname(os.path.realpath(__file__))

# First, the script will assume that it is being in run in the directory of
# a single kidney angle scanned over A3

output_file_name = input('Output file name : ')+'.ng0'

curr_time = time.clock()

#output_file_name = 'TiO2.ng0'

# This code will be taking intensity to be the same as counts, because in 
# Monte-Carlo simulations counts aren't meaningful

# Header info to be put at the top of text file every time:
# Need to make this customizable in the form of a config file / readin in from mcstas files:

# Lattice parameters can be adjusted here:

lattice_a = 4.594
lattice_b = 4.594
lattice_c = 2.959

theta_a = 90
theta_b = 90
theta_c = 90

orient_1 = '1 1 0'
orient_2 = '0 0 1'

line_str = '#Lattice     '+str(lattice_a)+' '+str(lattice_b)+' '+str(lattice_c)+' '+str(theta_a)+' '+str(theta_b)+' '+str(theta_c)+'\n'

def writeHeader(output_file):
	output_file.write('#ICE           0.4.0\n')
	output_file.write('#ICERepositoryInfo /ice/server/releases/ALL_2014_05_22 \n')
	output_file.write('#Filename    a3scan_elastic_1p6K_60273 \n')
	output_file.write('#Date        2016-07-27 17:57:57 EDT \n')
	output_file.write('#InstrName   NG0 \n')
	output_file.write('#Epoch       1469656677.57 \n')
	output_file.write('#ExptID      20160727\n')
	output_file.write('#ExptName    \n')
	output_file.write('#ExptParticipants  \n')
	output_file.write('#ExptDetails \n')
	output_file.write('#ExptComment \n')
	output_file.write('#User        ncnr\n')
	output_file.write('#Comment     \n')
	output_file.write('#Npoints     361\n')
	output_file.write('#TemperatureUnits Kelvin\n')
	output_file.write('#Ncolumns    138\n')
	output_file.write('#DetectorDims\n')
	output_file.write('#Signal      8 Monitor\n')
	output_file.write('#Reference   8 Monitor\n')
	output_file.write('#ScanType   ANGLE\n')
	output_file.write('#Scan        10 A3 \n')
	output_file.write('#ScanRanges: 10 A3 \n')
	output_file.write('#DetectorEfficiencies SPEC08=1.06822 DIFF08=1.0 SPEC13=1.02982 SPEC=1.0 DIFF12=1.0 DIFF06=1.0 DIFF20=1.0 SPEC18=1.65028 DIFF13=1.0 DIFF14=1.0 DIFF15=1.0 DIFF16=1.0 DIFF17=1.0 DIFF10=1.0 DIFF11=1.0 DIFF18=1.0 DIFF19=1.0 DIFF03=1.0 DIFF02=1.0 DIFF01=1.0 DIFF07=1.0 DIFF05=1.0 DIFF04=1.0 DIFF09=1.0 SPEC19=0.953006 SPARE=1.0 SPEC20=1.02213 Time=1.0 SPEC01=0.8707 SPEC10=0.791158 SPEC11=0.762235 SPEC14=1.15965 SPEC15=1.22142 SPEC16=1.00225 SPEC17=0.82556 SPEC12=0.807705 DIFF=1.0 SPEC06=0.914812 SPEC05=1.05829 SPEC04=0.842027 SPEC03=1.01165 SPEC02=1.06092 SPEC09=1.09363 SPEC07=0.854509 Monitor=1.0 \n')
	output_file.write('#FixedE     \n')
	output_file.write(line_str)
	output_file.write('#Orient      '+orient_1+' '+orient_2+'\n')
	output_file.write('#MonoSpacing 3.35416\n')
	output_file.write('#AnaSpacing  3.35416\n')
	output_file.write('#UBEnabled   0\n')
	output_file.write('#Fixed       All devices are free\n')
	output_file.write('#ScanDescr   Scan:SubID=20160727:JType=ANGLE:Npts=361:Counts=2600.0:Prefac=3.0:DetectorType=Monitor:CountType=Monitor:Filename=a3scan_elastic_1p6K_:HoldScan=0.0:Range=A3=-90.0 90.0 s:Title=a3scan_elastic\n')
	output_file.write('#Columns             QX            QY            QZ             E            A4          Time          Temp       Monitor            A2            A3            A5            A6           DFM            A1       AColMon AnalyzerTheta01 AnalyzerTheta02 AnalyzerTheta03 AnalyzerTheta04 AnalyzerTheta05 AnalyzerTheta06 AnalyzerTheta07 AnalyzerTheta08 AnalyzerTheta09 AnalyzerTheta10 AnalyzerTheta11 AnalyzerTheta12 AnalyzerTheta13 AnalyzerTheta14 AnalyzerTheta15 AnalyzerTheta16 AnalyzerTheta17 AnalyzerTheta18 AnalyzerTheta19 AnalyzerTheta20       BColMon BaseSampleTheta      BeFilMon         Beta1         Beta2        DFMDTS          DIFF        DIFF01        DIFF02        DIFF03        DIFF04        DIFF05        DIFF06        DIFF07        DIFF08        DIFF09        DIFF10        DIFF11        DIFF12        DIFF13        DIFF14        DIFF15        DIFF16        DIFF17        DIFF18        DIFF19        DIFF20          DMBT            Ef            Ei          FLIP         Focus             H           HKL             K        Kidney             L      MBTSlide          MCFX      MgFilMon    MonBlade01    MonBlade02    MonBlade03    MonBlade04    MonBlade05    MonBlade06    MonBlade07    MonBlade08    MonBlade09    MonBlade10    MonBlade11    MonBlade12    MonBlade13    MonBlade14    MonBlade15    MonBlade16    MonBlade17    MonBlade18    MonBlade19    MonBlade20    MonBlade21        MonRot      MonTrans          PTAI      PgFilMon         SPARE          SPEC        SPEC01        SPEC02        SPEC03        SPEC04        SPEC05        SPEC06        SPEC07        SPEC08        SPEC09        SPEC10        SPEC11        SPEC12        SPEC13        SPEC14        SPEC15        SPEC16        SPEC17        SPEC18        SPEC19        SPEC20     SmplLTilt     SmplUTilt         SmplX         SmplY         SmplZ          VBAH          VBAV         cfxbe       cfxhopg        cfxmgf TemperatureControlReading TemperatureSetpoint TemperatureHeaterPower TemperatureSensor2 TemperatureSensor3    timestamp\n')
	output_file.close()
output_file = open(output_file_name, 'w')
writeHeader(output_file)

def writeMatrix(matrix,output_file_name):
	np.savetxt('No_header_'+output_file_name,matrix,fmt='%s',delimiter='\t')

def getIntensity(file):
	file.seek(0)
	#Gets the Intensity total for both diff and spec files
	try:
		npArray = np.genfromtxt(file)
		Intensity = npArray[0:5]
		Ierr = npArray[5:10]
		N = npArray[10:15]
		#Note that we only care about intensity, as the MC simulation counts aren't meaningful
		TotIntensity = np.sum(Intensity)
		try:
			int(TotIntensity)
		except ValueError:
			TotIntensity=0
	except ValueError:
		TotIntensity=0
	return TotIntensity

def getParams(file):
	#Builds a dictionary of relevant params at top of the file
	#Note that non-param entries at top of file are nonsense in the dict 
	file.seek(0)
	s = file.readline()
	if s=='# Format: McCode with text headers\n':
		a = s.split("=")
		b = s.split(':')
		dict_out = {}
		while b[0]!= '# statistics':
			check1 = type(a)==list 
			check2 = len(a)>1
			if check1*check2==1:
				dict_out[a[0]]=a[1][0:-1]
			else:
				x=1
			s= file.readline()
			a = s.split('=')
			b = s.split(':')
		file.close()
		return dict_out
	else:
		#This is for the weird case of just zeros instead of entries 
		#Happens for a few diff_detector files, not sure why
		print('File containing only 0s found')
		dict_out = {}
		dict_out['# Param: A3_angle']=0
		dict_out['# Param: kidney_angle']=0
		dict_out['# Param: beta_1']=0
		dict_out['# Param: beta_2']=0
		return dict_out
		

	
# Create a class that makes an object for each detector file
# The object have a constructor for the following inputs from the diff_detector_x file:
#        -Table of intensities
#		 -Table of monitor counts
#		 -Calculated table of normalized intensities
#		 -A4  (functon of kidney_angle and detector number)
#        -A3  (Sample rotation)
#		 -EM  (Monochromator Energy to be converted to A2)
#        -EF  (Analyzer Energy to be converted to A6)
#

class MatRowObject:
	def __init__(self):
		self.Qx, self.Qy, self.Qz = 'N/A', 'N/A', 'N/A'
		self.E = 'N/A'
		self.A4 = 0# Ki - Kf 
		self.Time = 1#Make up a number for the config file
		self.Temp = 2#Put in config file
		self.Monitor = 780#Read in from line 47 in input file, NCount: x, or possibly make a standard number in the config file like 7800 since it isn't meaningful
		self.A2 = 74.2238#Angle from monochromator energy, calculate from EM line 13
		self.A3 = 5#Read in from line 11 
		self.A5 = 37.0862#Angle for analyzer energy, calculate from Ef_all line 14
		self.A6 = 74.1724#Not sure what this is, double of A5. I believe it's the 2nd analyzer ang.e
		self.DFM = 37.084 #No idea. Double focusing monochromator angle?
		self.A1 = 37.0834#I believe this is the source collimator angle, leave at something standard
		self.AcolMon = 'OUT'#Probably should just be OUT
		self.AnalyzerTheta = np.repeat(37.077,20)#Calculate from Ef_all, should be same as A5, angle for each detector
		self.BColMon = 'OUT' #Should be 'OUT'
		self.BaseSampleTheta = -56.8 # Not acactly sure, seems to go with A3
		self.BeFilMon ='OUT' #Probably should just be OUT
		self.Beta1 =3 # Mirror angle 1
		self.Beta2 =0.0001367 # Super mirror angle 1
		self.DFMDTS = -218.06#Don't know what this is. 
		self.DIFF = 100 #For use in Triple-axis mode
		self.DIFFi = np.repeat(0,20) #Sum of intensities rounded to closest value
		self.DMBT = 23156# Monochromator translation
		self.Ef = 5#Read in from file
		self.Ei = 5#Read in from file
		self.FLIP = 'A'#Probably just A
		self.focus = 1617#Think it is 1617, check for double focusing.
		self.H = 0#going to have to write a routine to calcluate this
		self.HKL = '[0,1,0]'#Array from calculated H K and L
		self.K = 1#write routine to calculate this
		self.Kidney = 0#Read in kidney_angle
		self.L =0 #Write a routine to calculate this
		self.MBTSlide = 5.4916#Don't know what this is. 5.4916
		self.MCFX = 'Be'#Go with "Be" I guess? 
		self.MgFilMon = 'OUT' # Guess this is out?
		self.MonBlade =np.repeat(-23.0,21) #Could potentially read from file but should just be 20 length array of 0
		self.MonRot =0 #I assume this can be calculated from Ei?
		self.MonTrans = 0#Translation of monochromator, will need to find standard value.
		self.PTAI = 4 #Detector Number when instrument is operated in triple axis mode 
		self.PgFilMon = 'OUT'#Should be OUT
		self.SPARE = 0 #Should be 0
		self.SPEC = 1 #For use in triple-axis mode 
		self.SPECi = np.repeat(0,20) #Caclculate from spec_detector file
		self.SmplLTilt =200 #Get from somewhere?
		self.SmplUTilt = 0 #Made up
		self.SmplX =0 #Get from file
		self.SmplY = 0#Get from file
		self.SmplZ = 0#Get from file
		self.VBAH = 0 #?
		self.VBAV = 0 #?
		self.cfxbe= 0#?
		self.cfxhope= 0#?
		self.cfxmgf=1 #?
		self.TemperatureControlReading= 1#Put in config file
		self.TemperatureSetpoint= 1#Put in config file
		self.TemperatureHeaterPower=1 
		self.TemperatureSensor2 = 1#Set to same as set point
		self.TemperatureSensor3 =1 #Set to same as set point
		self.timestamp= 563574#Make it up 

def get_nparray_from_MatRow(matRow):
	# Puts the matrowobj into a single array to use in the final ng0 file. This is quite painful.
	output_array = np.array([' ',matRow.Qx,matRow.Qy,matRow.Qz,matRow.E,matRow.A4,matRow.Time,matRow.Temp,matRow.Monitor,matRow.A2,matRow.A3,matRow.A5,matRow.A6,matRow.DFM,matRow.A1,\
		matRow.AcolMon,*matRow.AnalyzerTheta,matRow.BColMon,matRow.BaseSampleTheta,matRow.BeFilMon,matRow.Beta1,matRow.Beta2,matRow.DFMDTS,matRow.DIFFi[2],*matRow.DIFFi,\
		matRow.DMBT,matRow.Ef,matRow.Ei,matRow.FLIP,matRow.focus,matRow.H,matRow.HKL,matRow.K,matRow.Kidney,matRow.L,matRow.MBTSlide,matRow.MCFX,matRow.MgFilMon,*matRow.MonBlade,matRow.MonRot,\
		matRow.MonTrans,matRow.PTAI,matRow.PgFilMon,matRow.SPARE,matRow.SPECi[2],*matRow.SPECi,matRow.SmplLTilt,matRow.SmplUTilt,matRow.SmplX,matRow.SmplY,matRow.SmplZ,matRow.VBAH,matRow.VBAV,\
		matRow.cfxbe,matRow.cfxhope,matRow.cfxmgf,matRow.TemperatureControlReading,matRow.TemperatureSetpoint,matRow.TemperatureHeaterPower,matRow.TemperatureSensor2,matRow.TemperatureSensor3,\
		matRow.timestamp])
	return output_array

#Set of column numbers for references:
#1: Qx
#2: Qy
#3: Qz
#4: E
#5: A4
#6: Time
#7: Temp
#8: Monitor
#9: A2
#10: A3
#11: A5
#12: A6
#13: DFM
#14: A1
#15: AColMon
#16: AnalyzerTheta
#17: BeFilMon
#18: Beta1
#19: Beta2
#20: DFMDTS
#21: Diff
#22: DMBT
#23: Ei
#24: EF
#25: FLIP
#26: focus
#26: H
#27: HKL
#28: K
#29: Kidney
#30: L
#31: MBTSLIDE
#32: MCFX
#33: Monblade
#34: MonRot
#35: MonTrans
#36: PTAI
#37: PgFilMon
#38: Spare
#39: SPEC
#40: SmplLTilt
#41: SmplX
#42: SmplY
#43: SmplZ
#44: VBAH
#45: VBAV
#46: cfxbe
#47: cfxhope
#48: cfxmgf
#49: TemperatureControlReading
#50: TemperatureSetpoint
#51: TemperatureHeaterPower
#52: TemperatureSensor2
#53: TempearatureSensor3
#54: Timestamp

#Create a numpy array that we will append to our ng0 file at the end

ng0Matrix = np.array([])

# Write a loop to cycle through A3 directories
# Write a nested loop that creates a detectorObject from each file
# Append the self attributes contents of each DetectorObject to the np array


#First get total number of A3_angles:
num_f = 0

for subdirectory, directory, files, in os.walk(rootdir):
	#Each subdirectory represents a A3 angle, aka one line in the final ng0 file
	#need to check if this directory is actually an A3 Angle:
	dir_end = subdirectory.split('/')[-1]
	try:
		A3 = int(dir_end)
		num_f+=1
		good_file=True
	except:
		num_f +=0
		good_file=False

print('Found total of '+str(num_f)+' A3_angles / kidney / Ei combinations')
tempRow=MatRowObject()
test_row = get_nparray_from_MatRow(tempRow)
num_cols = len((test_row).flatten())

#Output is a matrix of shape num_f by num_cols
output_matrix = np.empty((num_f,num_cols),dtype=object)
row=0
for subdirectory, directory, files, in os.walk(rootdir):
	#Each subdirectory represents a A3 angle, aka one line in the final ng0 file
	#need to check if this directory is actually an A3 Angle:
	dir_end = subdirectory.split('/')[-1]
	try:
		A3 = int(dir_end)
		good_file=True
	except:
		good_file=False

	for file in files:
		#This only works if the detector file names are unchanged
		#All of these entries will be compiled into a new row for the ng0Matrix
		
		#Determine the current number and type of file (spec or diff, detector num)
		filestr=str(file)
		filestrSplit = filestr.split("_")
		fileType = filestrSplit[0] #Should be 'diff' or 'spec'. Build in a filter for all other files
		fileextension = filestrSplit[-1]

		if filestrSplit[0] in ['diff','spec'] and ('history' not in filestr):
			fileExt = filestrSplit[-1]
			fileNum = int(fileExt.split('.')[0])
			#print(str(file))
			f = open(subdirectory+'/' + str(file))
		if(fileType=='diff'):
			tempRow.DIFFi[fileNum]=getIntensity(f)
			#Get params like kidney angle and A3_angle from generated
			#dictionary, possibly more in future
			params = getParams(f)
			tempRow.A3=params['# Param: A3_angle']
			tempRow.Kidney = params['# Param: kidney_angle']
			tempRow.Beta1 = params['# Param: beta_1']
			tempRow.Beta2 = params['# Param: beta_2']
			tempRow.Ei=params['# Param: EM']
			tempRow.Ef=params['# Param: EF_all']
	
		if(fileType=='spec') and ('history' not in filestr):
			tempRow.SPECi[fileNum]=getIntensity(f)
			tempRow.A3=params['# Param: A3_angle']
			tempRow.Kidney = params['# Param: kidney_angle']
			tempRow.Beta1 = params['# Param: beta_1']
			tempRow.Beta2 = params['# Param: beta_2']
			tempRow.Ei=params['# Param: EM']
			tempRow.Ef=params['# Param: EF_all']
	#Add this row to the final matrix.
	if good_file==True:
		np_row = get_nparray_from_MatRow(tempRow)
		output_matrix[row,:]=np_row
		row+=1
	else:
		print('WARNING: Other file found in directory that is not McStas output.')
		print(dir_end)
	if row%10==0 and good_file==True:
		print('Done with: '+str(row)+'/'+str(num_f))
		print('Written EM='+str(tempRow.Ei))
		print('Number of columns: '+str(len(np_row)))

finalMat=np.copy(output_matrix)

writeMatrix(finalMat, output_file_name)

#Combine the two textfiles for our final result:
output_files = glob.glob("*.ng0")
output_files = [output_file_name, 'No_header_'+output_file_name]
with open('MSlice-'+output_file_name, "wb") as outfile:
	for f in output_files:
		with open(f, "rb") as infile:
			outfile.write(infile.read())

#First write the header:
#outfile = open('MSlice-'+output_file_name, 'wb')
#with open(output_file_name, 'rb'):
#	outfile.write(output_file_name.read())
#Then the data
#with open('No_header_'+output_file_name,'rb'):
#	outfile.write('No_header_'+output_file_name.read())
