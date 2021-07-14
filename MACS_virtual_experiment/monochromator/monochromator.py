import numpy as np

class Monochromator(object):
	'''
	This object contains parameters for the monochromator calculation.

	*  INPUT PARAMETERS:
	*    repeat_count=1:    how many times the virtual out from MACS_monochromator is used
	*    EM=3.4             monochromator energy setting [meV]
	*    HF=1               Horizontal focusing (ALWAYS 1, 0 mode broken)
	*    sample_diameter_d=0.02
	*    beta_1=1
	*    beta_2=1
	*    misalign_mono_deg=0.15
	*    slit_h=0.2         Slit after guide horizontal [m]
	*    slit_v=0.2         Slit after guide vertical [m]
	*    CPF(m):	distance between the focal point and the neutron source
	*		negative if the focal point is behind the source
	*    MPL(m):	distance between monochromator and source when 2theta=90 
	*    MPD(m):	distance between drum and monochromator when 2theta=90
	*               (The distance btw monoch. and sample is 1.675 m when 2theta=90.)
	*    APE_h:	vertical aperture
	*    APE_v:	horizontal aperture
	*    DIRDEV(min):misorientation of the monochromator blade(FWHM)
	*    DIVSOU(deg):	aceptance angle
	*    L0_delta (m)  special feature to scan L0 delta to optimize the focal point.
	*    L1_delta (m)  special feature to scan L0 delta to optimize the focal point.
	*    mon_t(m)  Monochormator translation  (montrans)
	*    mon_e(m)  Monochomator elevation (monrot)
	*    monrot_delta(deg)  monochromator stand delta rotation
	*
	*

	'''
	def __init__(self,repeat_count=1,Ei=5.0,HF=1,VF=1,beta_1=1.0,beta_2=1.0,misalign_deg=0.15,slit_h=0.2,slit_v=0.2,MPL=6.06,MPD=0.775,\
		DIRDEV=0.0,DIVSOU=3.0,L0_delta=-1.06,L1_delta=0.0,mon_t=0.0,mon_e=0.0,monrot_delta=0.0):
		self.repeat_count=repeat_count
		self.Ei = Ei 
		self.HF=HF 
		self.VF=VF
		self.beta_1 = beta_1 
		self.beta_2 = beta_2 
		self.misalign_deg = misalign_deg 
		self.slit_h = slit_h 
		self.slit_v = slit_v 
		self.MPL = MPL 
		self.MPD = MPD 
		self.DIRDEV = DIRDEV 
		self.DIVOU = DIVSOU 
		self.L0_delta = L0_delta
		self.L1_delta=L1_delta 
		self.mon_t = mon_t 
		self.mon_e = mon_e 
		self.monrot_delta = monrot_delta 

	#Eventually add a function to calculate optimal dmbt, betas. 
	