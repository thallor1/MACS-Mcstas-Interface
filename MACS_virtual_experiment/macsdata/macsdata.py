import numpy as np
import os
import pandas as pd
import glob
class Data(object):
	'''
	Class to handle the results of McStas simulations and compare to 
	experimental data.

	Also used to convert to ng0 format for Mslice.

	The only parameters that are required from run to run by MSLICE are 
	A2,A3,A5,SPEC###,Diff##,SPEC,DIFF<AnalyzerTheta##,kidney,time,monitor,ptai
	'''
	def __init__(self,sample,exptName=None,kidney_result_dir=None,compile_mode='all',beta_1=1.0,beta_2=1.0,PTAI_det=3):
		#Note the sample object is defined in the same module.
		self.compile_mode=compile_mode #Specifies if output ng0 files should be combined, individual, etc
		self.kidney_sim_dir=None
		self.kidney_result_dir=kidney_result_dir
		self.exptName=exptName
		self.sample=sample
		self.data_matrix = False #This is a large matrix that is initialized later
		self.projected_QE_matrix = False #Projection into QE space to visualize results. 
		self.beta_1=beta_1
		self.beta_2=beta_2
		self.PTAI_det=PTAI_det
		self.csv_name='_dataMatrix.csv' #Specifies name of output file

		#Check if output csv files already exist in the directory. If so, add them all to the data matrix. 
		old_csvs = glob.glob(self.kidney_result_dir+'*.csv')
		if len(old_csvs)>0:
			self.combine_all_csv(fname='_total.csv')
			print('#########################')
			print('Old simulations found in '+self.kidney_result_dir)
			self.load_data_matrix_from_csv(csv_file='_total.csv')
			print(' ')
			print('Successfully combined old simulations into '+self.kidney_result_dir+self.exptName+'_total.csv')
			print('')
			print('Data matrix instantiated and ready to use.')
			print('#########################')
		
	def writeHeader(self,output_file_name):
		output_file = open(output_file_name, 'w')
		output_file.write('#ICE           0.4.0\n')
		output_file.write('#ICERepositoryInfo /ice/server/releases/ALL_2014_05_22 \n')
		output_file.write('#Filename    Simulated MCstas data \n')
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
		output_file.write('#TemperatureUnits Kelvin\n')
		output_file.write('#Ncolumns    131\n')
		output_file.write('#DetectorDims 48\n')
		output_file.write('#Signal      8 Monitor\n')
		output_file.write('#Reference   8 Monitor\n')
		output_file.write('#ScanType   ANGLE\n')
		output_file.write('#DetectorEfficiencies SPEC08=1.06822 DIFF08=1.0 SPEC13=1.02982 SPEC=1.0 DIFF12=1.0 DIFF06=1.0 DIFF20=1.0 SPEC18=1.65028 DIFF13=1.0 DIFF14=1.0 DIFF15=1.0 DIFF16=1.0 DIFF17=1.0 DIFF10=1.0 DIFF11=1.0 DIFF18=1.0 DIFF19=1.0 DIFF03=1.0 DIFF02=1.0 DIFF01=1.0 DIFF07=1.0 DIFF05=1.0 DIFF04=1.0 DIFF09=1.0 SPEC19=0.953006 SPARE=1.0 SPEC20=1.02213 Time=1.0 SPEC01=0.8707 SPEC10=0.791158 SPEC11=0.762235 SPEC14=1.15965 SPEC15=1.22142 SPEC16=1.00225 SPEC17=0.82556 SPEC12=0.807705 DIFF=1.0 SPEC06=0.914812 SPEC05=1.05829 SPEC04=0.842027 SPEC03=1.01165 SPEC02=1.06092 SPEC09=1.09363 SPEC07=0.854509 Monitor=1.0 \n')
		output_file.write('#FixedE     Ei 1\n')
		output_file.write('#Lattice     '+str(self.sample.a)+' '+str(self.sample.b)+' '+str(self.sample.c)+' '+str(self.sample.alpha)+' '+\
			str(self.sample.beta)+' '+str(self.sample.gamma)+'\n')
		orient_u = self.sample.orient_u
		orient_v = self.sample.orient_v 
		output_file.write('#Orient      '+str(orient_u[0])+' '+str(orient_u[1])+' '+str(orient_u[2])+' '+str(orient_v[0])+' '+str(orient_v[1])+' '+str(orient_v[2])+'\n')
		output_file.write('#MonoSpacing 3.35416\n')
		output_file.write('#AnaSpacing  3.35416\n')
		output_file.write('#UBEnabled   0\n')
		output_file.write('#Fixed       All devices are free\n')
		output_file.write('#Columns             QX            QY            QZ             E            A4          Time       Monitor            A2            A3            A5            A6           DFM            A1       AColMon AnalyzerTheta01 AnalyzerTheta02 AnalyzerTheta03 AnalyzerTheta04 AnalyzerTheta05 AnalyzerTheta06 AnalyzerTheta07 AnalyzerTheta08 AnalyzerTheta09 AnalyzerTheta10 AnalyzerTheta11 AnalyzerTheta12 AnalyzerTheta13 AnalyzerTheta14 AnalyzerTheta15 AnalyzerTheta16 AnalyzerTheta17 AnalyzerTheta18 AnalyzerTheta19 AnalyzerTheta20       BColMon BaseSampleTheta      BeFilMon         Beta1         Beta2        DFMDTS          DIFF        DIFF01        DIFF02        DIFF03        DIFF04        DIFF05        DIFF06        DIFF07        DIFF08        DIFF09        DIFF10        DIFF11        DIFF12        DIFF13        DIFF14        DIFF15        DIFF16        DIFF17        DIFF18        DIFF19        DIFF20          DMBT            Ef            Ei          FLIP         Focus             H           HKL             K        Kidney             L      MBTSlide          MCFX      MgFilMon    MonBlade01    MonBlade02    MonBlade03    MonBlade04    MonBlade05    MonBlade06    MonBlade07    MonBlade08    MonBlade09    MonBlade10    MonBlade11    MonBlade12    MonBlade13    MonBlade14    MonBlade15    MonBlade16    MonBlade17    MonBlade18    MonBlade19    MonBlade20    MonBlade21        MonRot      MonTrans          PTAI      PgFilMon         SPARE          SPEC        SPEC01        SPEC02        SPEC03        SPEC04        SPEC05        SPEC06        SPEC07        SPEC08        SPEC09        SPEC10        SPEC11        SPEC12        SPEC13        SPEC14        SPEC15        SPEC16        SPEC17        SPEC18        SPEC19        SPEC20     SmplLTilt     SmplUTilt         SmplX         SmplY         SmplZ          VBAH          VBAV         cfxbe       cfxhopg        cfxmgf    timestamp\n')
		output_file.close()

	def getIntensity(self,datfile):
		#Gets the Intensity total for both diff and spec files
		try:
			npArray = np.genfromtxt(datfile)
			Intensity = npArray[0:5]
			Ierr = npArray[5:10]
			N = npArray[10:15]
			#Note that we only care about intensity, as the MC simulation counts aren't meaningful
			TotIntensity = np.nansum(Intensity)
			try:
				float(TotIntensity)
			except ValueError:
				TotIntensity=0
		except ValueError:
			TotIntensity=0
		return TotIntensity

	def getParams(self,fname):
		#Extracts parameters provided at top of mcstas .dat file
		#Builds a dictionary of relevant params at top of the file
		#Note that non-param entries at top of file are nonsense in the dict 
		file=open(fname)
		file.seek(0)
		s = file.readline()
		if s=='# Format: McCode with text headers\n':
			a = s.split("=")
			b = s.split(':')
			dict = {}
			while b[0]!= '# statistics':
				check1 = type(a)==list 
				check2 = len(a)>1
				if check1*check2==1:
					dict[a[0]]=a[1][0:-1]
				else:
					x=1
				s= file.readline()
				a = s.split('=')
				b = s.split(':')
			file.close()
			return dict
		else:
			#This is for the weird case of just zeros instead of entries 
			#Happens for a few diff_detector files, not sure why
			print('File containing only 0s found')
			dict = {}
			dict['# Param: A3_angle']=0
			dict['# Param: kidney_angle']=0
			dict['# Param: beta_1']=0
			dict['# Param: beta_2']=0
			return dict 



	def load_data_matrix_from_csv(self,csv_file=False):
		#loads the data matrix from csv backup
		if csv_file==False:
			#use default
			csv_name=self.csv_name
		else:
			csv_name= csv_file
		#Check if the file exits:
		if not os.path.isfile(self.kidney_result_dir+self.exptName+csv_name):
			print('WARNING: Cannot generate data matrix. File '+str(self.kidney_result_dir+self.exptName+csv_name)+' not found.')
		else:
			self.data_matrix=False
			df = pd.read_csv(self.kidney_result_dir+self.exptName+csv_name,header=0)
			df.index=range(len(df.index))
			self.data_matrix=df
		return 1

	def combine_all_csv(self,fname='_total.csv'):
		#Combines all precalculated data matrices stored in the results directory
		all_csvs = glob.glob(self.kidney_result_dir+'*.csv')
		df = pd.concat(map(lambda file: pd.read_csv(file,header=0),all_csvs))
		df=df.drop_duplicates()
		self.data_matrix=df 
		#Save into a cumulative file
		if os.path.exists(self.kidney_result_dir+self.exptName+fname):
			print('WARNING: Overwriting previous total file '+self.exptName+str(fname))
		df.to_csv(self.kidney_result_dir+self.exptName+fname,header=True)
		return 1

	def append_data_matrix_from_csv(self,csv_file=False):
		#Adds a precalculated data matrix as specified to the data matrix. Filename is required for this operation.
		#Will be quite slow if used for large operations. Better to break into small batches.
		orig_frame = self.data.data_matrix
		new_frame = pd.read_csv(self.kidney_result_dir+csv_file,header=0)
		frames = [orig_frame,new_frame]
		final_frame = pd.concat(frames)
		final_frame=final_frame.drop_duplicates()
		self.data_matrix=final_frame
		return 1

	def scan_to_csv(self,simulation_folder,file_suffix=''):
		#Given one folder containing a simulation for a particular configuration, appends the folder to the overall data matrix. 
		col_labels=['A3','A2','A5','A6','H','K','L','Ei','Ef','DIFF','DIFF1','DIFF2','DIFF3','DIFF4','DIFF5','DIFF6','DIFF7','DIFF8','DIFF9','DIFF10','DIFF11',\
					'DIFF12','DIFF13','DIFF14','DIFF15','DIFF16','DIFF17','DIFF18','DIFF19','DIFF20','SPEC','SPEC1','SPEC2','SPEC3','SPEC4','SPEC5','SPEC6','SPEC7','SPEC8','SPEC9','SPEC10','SPEC11',\
					'SPEC12','SPEC13','SPEC14','SPEC15','SPEC16','SPEC17','SPEC18','SPEC19','SPEC20','Kidney','A4','Monitor','Time','AnalyzerTheta01','AnalyzerTheta02','AnalyzerTheta03','AnalyzerTheta04',
					'AnalyzerTheta05','AnalyzerTheta06','AnalyzerTheta07','AnalyzerTheta08','AnalyzerTheta09','AnalyzerTheta10','AnalyzerTheta11','AnalyzerTheta12','AnalyzerTheta13','AnalyzerTheta14','AnalyzerTheta15',\
					'AnalyzerTheta16','AnalyzerTheta17','AnalyzerTheta18','AnalyzerTheta19','AnalyzerTheta20','PTAI']	

		data_matrix = pd.DataFrame(index=[0],columns=col_labels)
		diffiles=[]
		specfiles=[]
		for det_ind in np.arange(0,20,1):
			diffiles.append(simulation_folder+'/diff_detector_'+str(det_ind)+'.dat')
			specfiles.append(simulation_folder+'/spec_detector_'+str(det_ind)+'.dat')
		index=0
		if len(diffiles)==20:
			#Iterate through detectors 1-20
			diff_arr = np.zeros(20)
			spec_arr = np.zeros(20)
			for det_i in range(len(diff_arr)):
				I_diff = self.getIntensity(diffiles[det_i])
				I_spec =self.getIntensity(specfiles[det_i])
				diff_arr[det_i]=I_diff 
				spec_arr[det_i]=I_spec
			params = self.getParams(diffiles[0])
			PTAI_ind = self.PTAI_det-1
			data_matrix.loc[index,'DIFF']=diff_arr[PTAI_ind]
			data_matrix.loc[index,'SPEC']=spec_arr[PTAI_ind]
			for i in np.arange(1,21,1):
				data_matrix.loc[index,'DIFF'+str(i)]=diff_arr[i-1]
				data_matrix.loc[index,'SPEC'+str(i)]=spec_arr[i-1]
			#Intensities successfully extracted. 
			data_matrix.loc[index,'PTAI']=self.PTAI_det
			#The rest of the params require the information in the header
			A3_param = float(params['# Param: A3_angle'])
			Ei_param = float(params['# Param: EM'])
			Ef_param = float(params['# Param: EF_all'])
			kidney_param = float(params['# Param: kidney_angle'])
			data_matrix.loc[index,'A3']=A3_param
			data_matrix.loc[index,'Ei']=Ei_param 
			data_matrix.loc[index,'Ef']=Ef_param
			data_matrix.loc[index,'Kidney']=kidney_param
			#Leaving H, K, L, alone for now. 
			data_matrix.loc[index,'H']='N/A'
			data_matrix.loc[index,'K']='N/A'
			data_matrix.loc[index,'L']='N/A'
			#Need to calculate A2, monochromator reflection is 002.
			neutron_lami = 9.045/np.sqrt(Ei_param)
			neutron_lamf = 9.045/np.sqrt(Ef_param)
			Q_002 = 1.873 #For pyrolitic graphite
			twoThetai = 2.0*np.arcsin(Q_002*neutron_lami/(4.0*np.pi))*180.0/np.pi
			twoThetaf = 2.0*np.arcsin(Q_002*neutron_lamf/(4.0*np.pi))*180.0/np.pi
			data_matrix.loc[index,'A2']=twoThetai
			data_matrix.loc[index,'A4']=kidney_param-60.0 #Might be off but Mslice doesn't use this anyway.
			data_matrix.loc[index,'A6']=twoThetaf
			data_matrix.loc[index,'A5']=twoThetaf/2.0
			data_matrix.loc[index,'Monitor']=1.0
			#Individual analyzers will be assume to be the same as A5
			for i in np.arange(1,21,1):
				colstr = '{num:02d}'.format(num=i)
				data_matrix.loc[index,'AnalyzerTheta'+colstr]=twoThetaf/2.0
			data_matrix.loc[index,'Time']=1.0
		#Need to make a unique name based on the scan. 
		scan_prefix='_Ei_'+'{:.3f}'.format(Ei_param)+'_Ef_'+'{:.3f}'.format(Ef_param)+'_A3_'+'{:.4f}'.format(A3_param)+'_kidney_'+'{:.4f}'.format(kidney_param)
		#Save the matrix, or append to old file if it exists.
		if not os.path.isfile(self.kidney_result_dir+self.exptName+scan_prefix+self.csv_name):
			data_matrix.to_csv(self.kidney_result_dir+self.exptName+scan_prefix+file_suffix+self.csv_name,header=True)
		else:
			data_matrix.to_csv(self.kidney_result_dir+self.exptName+scan_prefix+file_suffix+self.csv_name,mode='a',header=False)

		return 1

	def combine_csv_scans(self,preserve_old=False,flagstr=False):
		#Takes individual csvs which are the output of each scan and combines them into a master csv. Also updates the data matrix to reflect this.
		all_files = glob.glob(self.kidney_result_dir+'*.csv')

		flist = []
		for fname in all_files:
			if flagstr==False:
				suffix='_combined_'
				df = pd.read_csv(fname,header=0,index_col=0)
				flist.append(df)
			else:
				suffix=flagstr
				if flagstr in fname:
					df =pd.read_csv(fname,header=0,index_col=0)
					flist.append(df)
		data_matrix=pd.concat(flist,axis=0,ignore_index=True)
		#delete all of the previous files
		if preserve_old==False and flagstr==False:
			num_csv = len(glob.glob(self.kidney_result_dir+'*.csv'))
			while num_csv>0:
				try:
					os.system('rm -rf '+str(self.kidney_result_dir+'*.csv'))
				except Exception as e:
					print('Warning: \n'+str(e))
					time.sleep(0.01)
				num_csv = len(glob.glob(self.kidney_result_dir+'*.csv'))
		if preserve_old==False and type(flagstr)!=bool:
			num_csv = len(glob.glob(self.kidney_result_dir+'*'+flagstr+'*.csv'))
			while num_csv>0:
				try:
					os.system('rm -rf '+str(self.kidney_result_dir+'*'+flagstr+'*.csv'))
				except Exception as e:
					print('Warning: \n'+str(e))
					time.sleep(0.01)
				num_csv = len(glob.glob(self.kidney_result_dir+os.path.join(self.kidney_result_dir+'*'+flagstr+'*.csv')))
		#Save the data matrix at this point after removing duplicate rows.
		data_matrix = data_matrix.drop_duplicates()
		#In the case of specific names, data file should just be overwritten if it already exists.
		data_matrix.to_csv(self.kidney_result_dir+self.exptName+suffix+self.csv_name,header=True)
		return 1

	def project_data_QE(self,uvec=[1,1,0],vvec=[0,0,1],PTAI=False):
		'''
		If the data matrix has been generated, we can create a second matrix to visualize the data by projecting into the scattering plane. 

		u is in beam direction u=[0,0,1]
		v is in plane v=[1,0,0]

		Rotate these by A3 along y-axis

		Get the projection of the scattering angle of each detector onto u and v

		Magnitude of Q is given by Q=sqrt(ki^2 + kf^2 - 2 ki kf cos (2theta))
		Magnitude along each direction given by dot product
		'''
		if type(self.data_matrix)==bool:
			print('Need to generate data matrix.')
			return 1
		#Shape of the output will be 20 times the length of the data matrix (20 detectors)
		#Following columns: H,K,L,Qu,Qv,|Q|,Ei,DeltaE,DIFF,SPEC,PTAI (Y/N),Err (Sqrt I for now)
		num_files = len(self.data_matrix.index)
		#Make a pandas dataframe
		data_indices = np.arange(0,num_files*20,1)
		col_labels=['H','K','L','Qu','Qv','|Q|','Ei','DeltaE','DIFF','SPEC','PTAI','Err']
		proj_mat = pd.DataFrame(index=data_indices,columns=col_labels)
		self.qprojection=proj_mat
		out_mat = np.zeros(20*num_files,len(col_labels))
		A3_array = np.array(self.data_matrix['A3'].tolist())
		kid_array = np.array(self.data_matrix['kidney'].tolist())
		Ei_array = np.array(self.data_matrix['Ei'].tolist())
		Ef_array = np.array(self.data_matrix['Ef'].tolist())
		#DIFF and SPEC all have 20 columns of format "DIFF1, SPEC1"
		diff_label_list = ['DIFF1','DIFF2','DIFF3','DIFF4','DIFF5','DIFF6','DIFF7','DIFF8','DIFF9','DIFF10',\
			'DIFF11','DIFF12','DIFF13','DIFF14','DIFF15','DIFF16','DIFF17','DIFF18','DIFF19','DIFF20']
		spec_label_list = ['SPEC1','SPEC2','SPEC3','SPEC4','SPEC5','SPEC6','SPEC7','SPEC8','SPEC9','SPEC10','SPEC11',\
			'SPEC12','SPEC13','SPEC14','SPEC15','SPEC16','SPEC17','SPEC18','SPEC19','SPEC20']
		diff_array = self.data_matrix[diff_label_list].to_numpy()
		spec_array = self.data_matrix[spec_label_list].to_numpy()
		diff_PTAI_array = diff_array[:,self.data_matrix['PTAI'].tolist()]
		spec_PTAI_array = spec_array[:,self.data_matrix['PTAI'].tolist()]
		#Generate a list of detector angles:
		det_index_list = np.arange(1,21,1)
		# Centered at kidney angle, spaced 8 degrees from each other. -(4+9*8)+kidney=(-76)+kid is first det
		det_angle_mat = np.outer(-76.0+det_index_list*8.0,kid_array)
		
		for i in range(len(num_files)):
			#Now iterate through each row of the data matrix
			out_mat_index = np.zeros(20,len(col_labels))
		return 1 

	def write_data_to_ng0(self,filename='McStas_output_',beta_1=1.0,beta_2=1.0):
		'''
		Writes the generated data matrix to a data file. 
		'''
		#First open a file and write the header. 
		#Check if the file and output directory exists.
		current_dir = os.getcwd()
		if type(self.data_matrix)==bool:
			print('Need to generate data matrix before writing ng0.')
			return 1
		if not os.path.exists(current_dir+'/'+'Simulated ng0 files'):
			os.mkdir(current_dir+'/'+'Simulated ng0 files')
		output_dir = current_dir+'/'+'Simulated ng0 files/'
		#Simplest case, one large ng0 file. First open a file and write the header
		#If an old file exists, delete it.
		if filename.split('.')[-1]!='ng0':
			print("Filename requirement: must end in .ng0. Got "+str(filename))
		if os.path.exists(output_dir+filename+'.ng0'):
			os.remove(output_dir+filename+'.ng0')
		#output_file = open(output_dir+filename,'w')
		filename=output_dir+filename
		#output_file.close()
		self.writeHeader(filename)
		#Now iterate through the data matrix, appending each line to the file.
		f=open(filename,'a')
		for ind in self.data_matrix.index:
			#This is the format of the string:
			try:
				template_str ='                    N/A           N/A           N/A           N/A      A4             2         MONITOR       A2      A3       A5       A6       37.9822       37.9822           OUT         ANA_1         ANA_2         ANA_3         ANA_4         ANA_5         ANA_6         ANA_7         ANA_8         ANA_9         ANA_10         ANA_11         ANA_12         ANA_13         ANA_14         ANA_15         ANA_16         ANA_17         ANA_18         ANA_19         ANA_20           OUT        -18.7415           OUT       BETA_1       BETA_2      -190.585           DIFF           DIFF1           DIFF2           DIFF3           DIFF4          DIFF5          DIFF6          DIFF7          DIFF8          DIFF9          DIFF10          DIFF11          DIFF12        DIFF13         DIFF14          DIFF15          DIFF16          DIFF17          DIFF18          DIFF19          DIFF20            10       EF           Ei             A          1642      -1.03874 [-1.039,-1.039,0.076]      -1.03874      KIDNEY     0.0762141        3.9738            BE           OUT       -22.814       -22.976        -23.14       -23.301       -23.465       -23.629       -23.795        -23.96       -24.124       -24.292       -24.457       -24.626       -24.793       -24.961       -25.129       -25.299       -25.468       -25.638        -25.81        -25.98       -26.151        62.441         0.359             3           OUT             0            SPEC            SPEC_1            SPEC_2            SPEC_3            SPEC_4           SPEC_5           SPEC_6           SPEC_7           SPEC_8           SPEC_9           SPEC_10           SPEC_11          SPEC_12         SPEC_13          SPEC_14           SPEC_15           SPEC_16           SPEC_17           SPEC_18           SPEC_19           SPEC_20          0.18        1.0101       -0.0008        0.0391       -15.001        359.99       360.008           OUT           OUT           OUT    1518'
				#All elements in caps are replaced by their respective simulated value.
				diff_str_list = ['DIFF'+str(int(ii))+' ' for ii in np.arange(1,21,1)]
				spec_str_list = ['SPEC_'+str(int(ii))+' ' for ii in np.arange(1,21,1)]
				ana_str_list = ['ANA_'+str(int(ii))+' ' for ii in np.arange(0,20,1)]
				#colstr = '{num:02d}'.format(num=i)
				ana_theta_val_list = []

				spec_val_list = ['{:.4f}'.format(self.data_matrix.loc[ind,'SPEC'+str(ii+1)]) for ii in np.arange(0,20,1)]
				diff_val_list = ['{:.4f}'.format(self.data_matrix.loc[ind,'DIFF'+str(ii+1)]) for ii in np.arange(0,20,1)]
				ana_theta_val_list =['{:.4f}'.format(self.data_matrix.loc[ind,'AnalyzerTheta'+'{num:02d}'.format(num=ii)]) for ii in np.arange(1,21,1)]

				replace_strs=['A4','MONITOR','A2','A3','A5','A6',*ana_str_list,\
					'BETA_1','BETA_2','DIFF ',*diff_str_list,'EF','Ei','KIDNEY','PTAI','SPEC ',*spec_str_list]

				replace_elements=['{:.4f}'.format(self.data_matrix.loc[ind,'A4']),\
					str(self.data_matrix.loc[ind,'Monitor']),'{:.4f}'.format(self.data_matrix.loc[ind,'A2']),\
					'{:.4f}'.format(self.data_matrix.loc[ind,'A3']),'{:.4f}'.format(self.data_matrix.loc[ind,'A5']),\
					'{:.4f}'.format(self.data_matrix.loc[ind,'A6']),\
					*ana_theta_val_list,'{:.4f}'.format(self.beta_1),'{:.4f}'.format(self.beta_2),\
					'{:.4f}'.format(self.data_matrix.loc[ind,'DIFF']),*diff_val_list,'{:.3f}'.format(self.data_matrix.loc[ind,'Ef']),\
					'{:.3f}'.format(self.data_matrix.loc[ind,'Ei']),'{:.4f}'.format(self.data_matrix.loc[ind,'Kidney']),\
					str(int(self.PTAI_det)),\
					'{:.3f}'.format(self.data_matrix.loc[ind,'SPEC']),*spec_val_list]

				for j in range(len(replace_elements)):
					template_str=template_str.replace(replace_strs[j],replace_elements[j])
				#Edit the string to have column width of the same length as ng0 files
				line_str_split = template_str.split()
				#The column widths were manually extracted from an example ng0 file.
				col_widths=[24, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 14, 16, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 22, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 22]

				writestr = "".join(line_str_split[i].rjust(col_widths[i]) for i in range(len(line_str_split)))+'\n'
				writestr = writestr #Mslice expects this padding for some reason. 
				#Finally, write to the file. 
				f.write(writestr)
			except Exception as e:
				print('Warning: ')
				print(e)
		endstr = '#NG0:END	TYPE= FP	FIT_P1= 123.172887	FIT_P2= 0.000000	FIT_P3= 0	FIT_P4= 772.040954	FIT_P5= -41.483096	FIT_P6= 0.502625'
		f.write(endstr)
		f.close()
		return 1



