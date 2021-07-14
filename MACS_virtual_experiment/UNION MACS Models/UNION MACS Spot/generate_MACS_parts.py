import McStas_class


# Variables in instrument file input related to monochromator
# EM            [meV]   selected energy
# CPF           [m]     distance between focal point and the neutron source (negative behind source)
# MPL           [m]     distance between monochromator and source when 2 theta = 90
# MPD           [m]     distance between drum and monochromator when 2theta = 90
#                       (the distance between monochromator and ssample is 1.675 m when 2theta=90.)
# DIRDEV        [min]   misorientation of the monochromator blade (FWHM)
# DIVSOU        [deg]   acceptance angle (mosaicity? need to check)
# L0_delta      [m]     offset in focal point source
# L1_delta      [m]     offset in focal point sample
# mon_t         [m]     Monochromator translation
# mon_e         [m]     Monochromator elevation
# monrot_delta  [deg]   Monochromator stand delta rotation

monochromator = McStas_class.McStas_part("monochromator")
# Variables in instrument global scope used here
# lambda        [AA]    wavelength selected

# Settings in this file
#monochromator_collumns = 21     # if updated the necessary changes should also be done to the displacements list
monochromator_collumns = 21     # if updated the necessary changes should also be done to the displacements list
monochromator_rows = 17        # number of crystal rows in each column of the monochromator (easily changed)
#monochromator_rows = 3          # Setting for speed

#kidney_channels = 20
kidney_channels = 20 # For speed in testing

monochromator_q = 1.87325       # monochromator Q in [AA^-1]

use_slits_instead_of_filter = 1

# Enable conditonals (need loggers)
enable_conditional = []
for i in range(1,kidney_channels+1):
    enable_conditional.append(0)
# WAS ON FOR TOMS MACS RUN
#enable_conditional[10] = 1
#enable_conditional[11] = 1

# Enable exit volumes for diffraction detectors
enable_exit_diffraction = []
for i in range(1,kidney_channels+1):
    enable_exit_diffraction.append(1)

# Enable exit volumes for spectroscopy detectors
enable_exit_spectroscopy = []
for i in range(1,kidney_channels+1):
    enable_exit_spectroscopy.append(1)

#enable_conditional = [0]*kidney_channels
#enable_conditional[1] = 1
#enable_conditional[2] = 1
#enable_conditional[3] = 1
#enable_conditional[4] = 1
#enable_conditional[5] = 1

# contains a function from numerical recipies needs to be in the declare section, done manually.
#monochromator.append_initialize("%include \"splint.c\"")
# contains Jose Rodriguez monochromator functions, needs to be in the declare section, done manually.
#monochromator.append_initialize("%include \"monochromator.c\"")

# Declare parameters in the instrument file for the monochromator
monochromator.add_declare_var("double","mono_column_displacements",array=21,value=[-0.21, -0.189, -0.168, -0.147, -0.126, -0.105, -0.084, -0.063, -0.042, -0.021, 0, 0.021, 0.042, 0.063, 0.084, 0.105, 0.126, 0.147, 0.168, 0.189, 0.21])
#monochromator.add_declare_var("double","mono_column_displacements",array=21,value=[0, -0.021, 0.021, -0.147, -0.126, -0.105, -0.084, -0.063, -0.042, -0.189, -0.21, -0.168, 0.042, 0.063, 0.084, 0.105, 0.126, 0.147, 0.168, 0.189, 0.21])
monochromator.add_declare_var("double","mono_crystal_width",value=0.02) #dmtas_mon_w
monochromator.add_declare_var("double","mono_number_of_rows",value=monochromator_rows)
monochromator.add_declare_var("double","mono_q",value=monochromator_q)


# Initialize for the monochromator
monochromator.append_initialize("")

monochromator.append_initialize("// Monochromator geometry")
monochromator.add_declare_var("double","mono_theta")
monochromator.append_initialize("mono_theta = asin(mono_q/2./sqrt(EM/2.0717));")
monochromator.append_initialize("")

monochromator.add_declare_var("double","dist_mono_L0")     # focus distance source
monochromator.add_declare_var("double","dist_mono_L0_pos") # position of monochromator focus relative source
monochromator.append_initialize("// distance from source to monochromator to calculate the focal point")
monochromator.append_initialize("dist_mono_L0	  = MPL-MPD/tan(2.*mono_theta) + L0_delta;")
monochromator.append_initialize("dist_mono_L0_pos = MPL-MPD/tan(2.*mono_theta);")
monochromator.append_initialize("")

monochromator.add_declare_var("double","dist_mono_L1")     # focus distance
monochromator.add_declare_var("double","dist_mono_L1_pos") # position of monochromator focus relative source
monochromator.append_initialize("// distance from monochromator to sample")
monochromator.append_initialize("dist_mono_L1     = 0.9+MPD/sin(2.*mono_theta) + L1_delta;")
monochromator.append_initialize("dist_mono_L1_pos = 0.9+MPD/sin(2.*mono_theta);")
monochromator.append_initialize("")


monochromator.add_declare_var("double","R_at_reference")
monochromator.append_initialize("R_at_reference =2.*dist_mono_L0*dist_mono_L1/(dist_mono_L0+dist_mono_L1);")
monochromator.add_declare_var("double","height_at_reference")
monochromator.append_initialize("hight_at_reference =sin(asin((mono_crystal_width+0.001)/2./R_at_reference)*mono_number_of_rows)*R_at_reference*2.;")
monochromator.append_initialize("")

monochromator.add_declare_var("double","mono_Radius_of_curvature")
monochromator.append_initialize("if (VF == 1) {")
monochromator.append_initialize("  mono_Radius_of_curvature = 2.*dist_mono_L0*dist_mono_L1*sin(mono_theta)/(dist_mono_L0+dist_mono_L1);")
monochromator.append_initialize("} else {")
monochromator.append_initialize("  mono_Radius_of_curvature = 300;")
monochromator.append_initialize("}")
monochromator.append_initialize("")

monochromator.add_declare_var("double","mono_total_height")
monochromator.append_initialize("mono_total_height = sin(asin((mono_crystal_width+0.001)/2./mono_Radius_of_curvature)*mono_number_of_rows)*mono_Radius_of_curvature*2.;")
monochromator.append_initialize("")

monochromator.add_declare_var("double","mono_phi")
monochromator.append_initialize("mono_phi = atan2(sin(2.*mono_theta),cos(2.*mono_theta)+dist_mono_L1/dist_mono_L0);")
monochromator.append_initialize("")

monochromator.add_declare_var("double","mono_psi",array=21)
monochromator.add_declare_var("int","mono_iterate")
monochromator.append_initialize("for (mono_iterate=0;mono_iterate<" + str(monochromator_collumns) + ";mono_iterate++) {")
monochromator.append_initialize("  if (HF == 1)")
monochromator.append_initialize("    mono_psi[mono_iterate] =-(atan2(sin(mono_phi),cos(mono_phi)+mono_column_displacements[mono_iterate]/dist_mono_L0)-mono_theta)*RAD2DEG;")
monochromator.append_initialize("  else {")
monochromator.append_initialize("    mono_psi[mono_iterate] = 0;")
monochromator.append_initialize("    mono_phi = mono_theta;");
monochromator.append_initialize("  }")
monochromator.append_initialize("}")
monochromator.append_initialize("")

monochromator.append_initialize("// Monochromator reflectivity and mosaicity")
monochromator.add_declare_var("double","mono_mosaicity_eta_min",value=14.1070) # Value in file from Jose
monochromator.add_declare_var("double","mono_mosaicity_eta_rad")
monochromator.append_initialize("mono_mosaicity_eta_rad = mono_mosaicity_eta_min/60*DEG2RAD;")
monochromator.add_declare_var("double","mono_crystal_thickness",value=0.002E10) # thickness of monochromator crystals in AA. Check scientific value works

monochromator.add_declare_var("double","mono_g")
monochromator.append_initialize("mono_g = 1/(2*sqrt(PI)*mono_mosaicity_eta_rad);")
monochromator.add_declare_var("double","mono_Ff")
monochromator.add_declare_var("double","mono_b_c",value=6.646e-5)
monochromator.append_initialize("mono_Ff=4*mono_b_c;")
monochromator.add_declare_var("double","mono_Vc")
monochromator.append_initialize("mono_Vc = sqrt(3)*2.464*2.464*6.711/2;")
monochromator.add_declare_var("double","mono_Qc")
monochromator.append_initialize("mono_Qc = lambda*lambda*lambda*mono_Ff*mono_Ff/(mono_Vc*mono_Vc*sin(2*mono_theta));")

monochromator.add_declare_var("double","mono_t") # Do not understand this value
monochromator.append_initialize("mono_t = mono_crystal_thickness/sin(mono_theta);")
monochromator.add_declare_var("double","mono_xx")
monochromator.append_initialize("mono_xx = sqrt(2)*mono_g*mono_Qc*mono_t;")
monochromator.add_declare_var("double","mono_r0")
monochromator.append_initialize("mono_r0 = mono_xx/(mono_xx+1);")

monochromator.add_declare_var("double","mono_mosaicity_rad")
monochromator.append_initialize("mono_mosaicity_rad = mono_mosaicity_eta_rad*sqrt(8*log(2+sqrt(2)*mono_g*mono_Qc*mono_crystal_thickness));")
monochromator.add_declare_var("double","mono_mosaicity_min")
monochromator.append_initialize("mono_mosaicity_min = mono_mosaicity_rad*RAD2DEG*60;")


monochromator.append_trace("COMPONENT Incoherent_PG_mono = Incoherent_process(")
monochromator.append_trace("    sigma=4*0.001, packing_factor=1, unit_cell_volume=35.29, interact_fraction=-1)")
monochromator.append_trace("AT (0,0,0) ABSOLUTE")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT Single_crystal_PG_mono = Single_crystal_process(")
monochromator.append_trace("     mosaic = 36, reflections = \"C_graphite.lau\",")
monochromator.append_trace("     ax = 0,    ay = 2.14, az =-1.24,")
monochromator.append_trace("     bx = 0,    by = 0,    bz = 2.47,")
monochromator.append_trace("     cx = 6.71, cy = 0,    cz = 0,")
monochromator.append_trace("     barns=0,packing_factor=1)")
monochromator.append_trace("AT (0,0,0) ABSOLUTE")
monochromator.append_trace("ROTATED (0,0,0) ABSOLUTE")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT PG_mono = Union_make_material(my_absorption=0.0035*4/35.29*100,")
monochromator.append_trace("  process_string=\"Single_crystal_PG_mono,Incoherent_PG_mono\")")
monochromator.append_trace("AT (0,0,0) ABSOLUTE")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT Al_mono_incoherent = Incoherent_process(sigma=4*0.0082,packing_factor=1,unit_cell_volume=66.4)")
#monochromator.append_trace("COMPONENT Al_mono_incoherent = Incoherent_process(sigma=4*8.2,packing_factor=1,unit_cell_volume=66.4)")
monochromator.append_trace("AT (0,0,0) ABSOLUTE")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT Al_mono_powder = Powder_process(reflections=\"Al.laz\")")
monochromator.append_trace("AT (0,0,0) ABSOLUTE")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT Al_mono = Union_make_material(my_absorption=100*4*0.231/66.4,")
monochromator.append_trace("  process_string=\"Al_mono_incoherent,Al_mono_powder\")")
monochromator.append_trace("AT (0,0,0) ABSOLUTE")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT mono_support_pillar_1 = Union_cylinder(")
monochromator.append_trace("    radius=0.01255,yheight=1.2*mono_total_height,")
monochromator.append_trace("    priority=5,material_string=\"Al_mono\",p_interact=0.2)")
monochromator.append_trace("  AT (0.1976,0,0) RELATIVE mono ")
monochromator.append_trace("  ROTATED (0,0,0) RELATIVE mono")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT mono_support_pillar_vacuum_1 = Union_cylinder(")
monochromator.append_trace("    radius=0.0109,yheight=1.18*mono_total_height,")
monochromator.append_trace("    priority=6,material_string=\"Vacuum\")")
monochromator.append_trace("  AT (0.1976,0,0) RELATIVE mono ")
monochromator.append_trace("  ROTATED (0,0,0) RELATIVE mono")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT mono_support_pillar_2 = Union_cylinder(")
monochromator.append_trace("    radius=0.01255,yheight=1.2*mono_total_height,")
monochromator.append_trace("    priority=7,material_string=\"Al_mono\",p_interact=0.2)")
monochromator.append_trace("  AT (-0.0988,0,-0.1711) RELATIVE mono ")
monochromator.append_trace("  ROTATED (0,0,0) RELATIVE mono")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT mono_support_pillar_vacuum_2 = Union_cylinder(")
monochromator.append_trace("    radius=0.0109,yheight=1.18*mono_total_height,")
monochromator.append_trace("    priority=8,material_string=\"Vacuum\")")
monochromator.append_trace("  AT (-0.0988,0,-0.1711) RELATIVE mono ")
monochromator.append_trace("  ROTATED (0,0,0) RELATIVE mono")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT mono_support_pillar_3 = Union_cylinder(")
monochromator.append_trace("    radius=0.01255,yheight=1.2*mono_total_height,")
monochromator.append_trace("    priority=9,material_string=\"Al_mono\",p_interact=0.2)")
monochromator.append_trace("  AT (-0.0988,0,0.1711) RELATIVE mono ")
monochromator.append_trace("  ROTATED (0,0,0) RELATIVE mono")
monochromator.append_trace("")
monochromator.append_trace("COMPONENT mono_support_pillar_vacuum_3 = Union_cylinder(")
monochromator.append_trace("    radius=0.0109,yheight=1.18*mono_total_height,")
monochromator.append_trace("    priority=10,material_string=\"Vacuum\")")
monochromator.append_trace("  AT (-0.0988,0,0.1711) RELATIVE mono ")
monochromator.append_trace("  ROTATED (0,0,0) RELATIVE mono")

priority_value = 30 #start at priority 30

for i in range(0,monochromator_collumns):
    # Need to allow AT and rotated in the input
    McStas_class.append_vertical_crystal_mono_array(monochromator, name = "mono_array" + str(i), crystal_width = "mono_crystal_width", crystal_height = 0.02, crystal_depth = 0.002, number_of_crystals = monochromator_rows, total_height = "mono_total_height", radius_of_curvature = "mono_Radius_of_curvature", arm_name = "mono", priority_start = priority_value, priority_end = priority_value+0.85, material_name = "PG_mono",z_position_string="mono_column_displacements[" + str(i) + "]", y_rotation_string="mono_psi[" + str(i) + "]", support_arch_thickness=0.00183, support_arch_width=0.0188, support_arch_spacing=0.000251, mask_height_diviation=0.0002*i, misalignment_deg="misalign_mono_deg")
    # Need to set an individual priority for all 17 arrays
    priority_value = priority_value + 1;

    #monochromator.append_trace("COMPONENT monochromator_collumn" + str(i) +" = Vfocus_analyzer1(")
    #monochromator.append_trace("   R=mono_Radius_of_curvature, n=mono_number_of_rows,")
    #monochromator.append_trace("   h=mono_total_height, w=mono_crystal_width,")
    #monochromator.append_trace("   mosaich=mono_mosaicity_min, mosaicv=mono_mosaicity_min,")
    #monochromator.append_trace("   dirdev=DIRDEV, r0=mono_r0, Q=mono_q)")
    #monochromator.append_trace("AT (0,0,mono_column_displacements[" + str(i) + "]) RELATIVE mono")
    #monochromator.append_trace("ROTATED (0,mono_psi[" + str(i) + "],0) RELATIVE mono \n")

monochromator.append_trace("COMPONENT monochromator_union_master = Union_master()")
monochromator.append_trace("AT (0,0,0) RELATIVE mono")
monochromator.append_trace("ROTATED (0,0,0) RELATIVE mono")
monochromator.append_trace("")

monochromator.write_c_files()


kidney = McStas_class.McStas_part("kidney")

# Variable that contains the current channel number
kidney.add_declare_var("int","channel_selected")

kidney.append_trace("COMPONENT kidney_master = Arm()")
kidney.append_trace("  AT (0,0,0) RELATIVE target")
kidney.append_trace("  ROTATED (0,kidney_angle,0) RELATIVE target")
kidney.append_trace("  EXTEND %{")
kidney.append_trace("    channel_selected = -1;")
kidney.append_trace("  %}")
kidney.append_trace("")



# Works for even number of kidney channels
kidney_channel_seperation = 8 #deg
this_kidney_angle = -kidney_channel_seperation/2 - kidney_channels/2*kidney_channel_seperation

kidney.append_trace("// Arms for each channel of MACS")
for i in range(0,kidney_channels):
    this_kidney_angle = this_kidney_angle + kidney_channel_seperation
    kidney.append_trace("COMPONENT kidney_channel_" + str(i) + " = Arm()")
    kidney.append_trace("  AT (0,0,0) RELATIVE kidney_master")
    kidney.append_trace("  ROTATED (0," + str(this_kidney_angle) + ",0) RELATIVE kidney_master")
    kidney.append_trace("")

# Data input for filter
kidney.add_declare_var("double","target_filter_dist",value=0.35) #This value needs to be looked up
kidney.add_declare_var("double","filter_width",value=0.04) #this just needs to be small enough not to collide and large enough to cover colimator
kidney.add_declare_var("double","filter_height",value=0.12) #this just needs to be small enough not to collide and large enough to cover colimator

kidney.append_trace("// Filters that also check for scattering to select the correct channel")
for i in range(0,kidney_channels):
    if use_slits_instead_of_filter == 1:
        kidney.append_trace("COMPONENT channel_" + str(i) + "_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)")
    else:
        kidney.append_trace("COMPONENT channel_" + str(i) + "_filter = Filter_gen_no_absorb(xwidth=filter_width, yheight=filter_height, filename=\"Be.trm\")")
    #kidney.append_trace("COMPONENT channel_" + str(i) + "_filter = Filter_gen(xwidth=filter_width, yheight=filter_height, filename=\"Be.trm\")")
    kidney.append_trace("  AT (0,0,target_filter_dist) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  GROUP filter_group")
    kidney.append_trace("  EXTEND %{")
    kidney.append_trace("    if (SCATTERED) channel_selected = " + str(i) + ";")
    kidney.append_trace("    //printf(\"channel_selected = %d\\n\",channel_selected);")
    kidney.append_trace("  %}")
    kidney.append_trace("")

kidney.append_trace("// dummy arm that absorbs rays that did not hit any filter")
kidney.append_trace("COMPONENT channel_selector = Arm()")
kidney.append_trace("  AT (0,0,0) RELATIVE kidney_master")
kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_master")
kidney.append_trace("  EXTEND %{")
kidney.append_trace("    if (channel_selected == -1) ABSORB;")
kidney.append_trace("    detector_found = 0;")
kidney.append_trace("  %}")
kidney.append_trace("")

# Data input for colimators
kidney.add_declare_var("double","channel_colimator_length",value=0.06)
kidney.add_declare_var("double","channel_colimator_width",value=0.0346)
kidney.add_declare_var("double","channel_colimator_height",value=0.1184) #this is the height at exit, entry is 110.0 mm
kidney.add_declare_var("double","channel_colimator_divergence_arcmin",value=90)
kidney.add_declare_var("double","channel_colimator_transmission",value=0.9)
kidney.add_declare_var("double","channel_colimator_target_dist",value=0.4)

for i in range(0,kidney_channels):
    kidney.append_trace("COMPONENT channel_" + str(i) + "_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,")
    kidney.append_trace("      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)")
    kidney.append_trace("  WHEN (channel_selected == " + str(i) + ")")
    kidney.append_trace("  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")



# Calculated from 40% Polyurethane and 60% B4C mass mixture and natural occurances cross sections from NIST
kidney.append_trace("COMPONENT boron_plastic_incoherent = Incoherent_process(")
kidney.append_trace("    sigma=1.80, packing_factor=1, unit_cell_volume=1, interact_fraction=-1)")
kidney.append_trace("AT (0,0,0) ABSOLUTE")
kidney.append_trace("")
#kidney.append_trace("COMPONENT boron_plastic = Union_make_material(my_absorption=50.0*4/35.29*100,")
#kidney.append_trace("COMPONENT boron_plastic = Union_make_material(my_absorption=101*100,") # Value from MARI
kidney.append_trace("COMPONENT boron_plastic = Union_make_material(my_absorption=3495,") # 0.5*Value from MARI
kidney.append_trace("  process_string=\"boron_plastic_incoherent\")") # Done to save computational time
#kidney.append_trace("  absorber=1)")
#kidney.append_trace("  absorber=0)")
kidney.append_trace("AT (0,0,0) ABSOLUTE")
kidney.append_trace("")
# Calculated from 40% Polyurethane and 40% B4C mass mixture and natural occurances cross sections from NIST and 20% 10-B
kidney.append_trace("COMPONENT boron_plastic_enriched_incoherent = Incoherent_process(")
kidney.append_trace("    sigma=1.82, packing_factor=1, unit_cell_volume=1, interact_fraction=-1)")
kidney.append_trace("AT (0,0,0) ABSOLUTE")
kidney.append_trace("")
kidney.append_trace("COMPONENT boron_plastic_enriched = Union_make_material(my_absorption=8071,") # 0.5*Value from MARI
kidney.append_trace("  process_string=\"boron_plastic_enriched_incoherent\")") # Done to save computational time
#kidney.append_trace("  absorber=1)")
#kidney.append_trace("  absorber=0)")
kidney.append_trace("AT (0,0,0) ABSOLUTE")
kidney.append_trace("")
kidney.append_trace("COMPONENT Collimator_gad = Union_make_material(my_absorption=1000.0*4/35.29*100, absorber=1,")
kidney.append_trace("  process_string=\"\")")
kidney.append_trace("AT (0,0,0) ABSOLUTE")
kidney.append_trace("")
kidney.append_trace("COMPONENT Incoherent_PG_analyzer = Incoherent_process(")
kidney.append_trace("    sigma=4*0.001, packing_factor=1, unit_cell_volume=35.29, interact_fraction=-1)")
kidney.append_trace("AT (0,0,0) ABSOLUTE")
kidney.append_trace("")
kidney.append_trace("COMPONENT Single_crystal_PG_analyzer = Single_crystal_process(")
kidney.append_trace("     mosaic = 50, reflections = \"C_graphite.lau\",")
kidney.append_trace("     ax = 0,    ay = 2.14, az =-1.24,")
kidney.append_trace("     bx = 0,    by = 0,    bz = 2.47,")
kidney.append_trace("     cx = 6.71, cy = 0,    cz = 0,")
kidney.append_trace("     barns=0,packing_factor=1)")
kidney.append_trace("AT (0,0,0) ABSOLUTE")
kidney.append_trace("ROTATED (0,0,0) ABSOLUTE")
kidney.append_trace("")
kidney.append_trace("COMPONENT PG_analyzer = Union_make_material(my_absorption=0.0035*4/35.29*100,")
kidney.append_trace("  process_string=\"Single_crystal_PG_analyzer,Incoherent_PG_analyzer\")")
kidney.append_trace("AT (0,0,0) ABSOLUTE")

# Data input for outer shape of kidney
kidney.add_declare_var("double","kidney_hull_radius",value=1.375) # from CAD model
kidney.add_declare_var("double","kidney_hull_height",value=0.4) # from CAD moddel (largest, there are some small steps/gaps and surface detail)
kidney.add_declare_var("double","kidney_hull_inner_radius",value=0.685) # from CAD model
kidney.add_declare_var("double","kidney_cylinder_angle",value=160) # from CAD (but the channels are not equally far from the edges)

kidney.append_trace("COMPONENT kidney_hull = Union_cylinder(radius=kidney_hull_radius,yheight=kidney_hull_height,")
kidney.append_trace("      priority=100,material_string=\"boron_plastic\",p_interact=0.3)")
kidney.append_trace("AT (0,0,0) RELATIVE kidney_master")
kidney.append_trace("ROTATED (0,0,0) RELATIVE kidney_master")
kidney.append_trace("")

kidney.append_trace("COMPONENT kidney_hull_cut = Union_cylinder(radius=kidney_hull_inner_radius,yheight=1.002*kidney_hull_height,")
kidney.append_trace("      priority=100.5,material_string=\"Vacuum\")")
kidney.append_trace("AT (0,0,0) RELATIVE kidney_master")
kidney.append_trace("ROTATED (0,0,0) RELATIVE kidney_master")
kidney.append_trace("")

kidney.append_trace("COMPONENT kidney_hull_box_cut_arm1 = Arm()")
kidney.append_trace("AT (0,0,0) RELATIVE kidney_master")
kidney.append_trace("ROTATED (0,0.5*kidney_cylinder_angle+90,0) RELATIVE kidney_master")
kidney.append_trace("")

# When allowed starting list updated i can add a bit of height to conceal the center vacuum in mcdisplay
kidney.append_trace("COMPONENT kidney_hull_box_cut1 = Union_box(xwidth=2.1*kidney_hull_radius,yheight=1.003*kidney_hull_height,zdepth=1.2*kidney_hull_radius,")
kidney.append_trace("  priority=101,material_string=\"Vacuum\",visualize=0)")
kidney.append_trace("AT (0,0,0.6*kidney_hull_radius) RELATIVE kidney_hull_box_cut_arm1")
kidney.append_trace("ROTATED (0,0,0) RELATIVE kidney_hull_box_cut_arm1")
kidney.append_trace("")

kidney.append_trace("COMPONENT kidney_hull_box_cut_arm2 = Arm()")
kidney.append_trace("AT (0,0,0) RELATIVE kidney_master")
kidney.append_trace("ROTATED (0,-0.5*kidney_cylinder_angle-90,0) RELATIVE kidney_master")
kidney.append_trace("")

kidney.append_trace("COMPONENT kidney_hull_box_cut2 = Union_box(xwidth=2.1*kidney_hull_radius,yheight=1.004*kidney_hull_height,zdepth=1.2*kidney_hull_radius,")
kidney.append_trace("  priority=102,material_string=\"Vacuum\",visualize=0)")
kidney.append_trace("AT (0,0,0.6*kidney_hull_radius) RELATIVE kidney_hull_box_cut_arm2")
kidney.append_trace("ROTATED (0,0,0) RELATIVE kidney_hull_box_cut_arm2")
kidney.append_trace("")


kidney.add_declare_var("double","zx_log_z_min",value=-0.5)
kidney.add_declare_var("double","zx_log_z_max",value=1.5)
kidney.add_declare_var("double","zx_log_x_min",value=-1.5)
kidney.add_declare_var("double","zx_log_x_max",value=1.5)
kidney.add_declare_var("int","zx_log_z_pixels",value=1000)
kidney.add_declare_var("int","zx_log_x_pixels",value=1000)

kidney.add_declare_var("double","zy_log_z_min",value=-0.5)
kidney.add_declare_var("double","zy_log_z_max",value=1.5)
kidney.add_declare_var("double","zy_log_y_min",value=-0.2)
kidney.add_declare_var("double","zy_log_y_max",value=0.2)
kidney.add_declare_var("int","zy_log_z_pixels",value=1000)
kidney.add_declare_var("int","zy_log_y_pixels",value=300)

for i in range(0,kidney_channels):
    if (enable_conditional[i] == 1):
        kidney.append_trace("COMPONENT logger_zx_spatial_con_channel_" + str(i) + "_all = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zx_spatial_con_channel_" + str(i) + "_all.dat\",")
        kidney.append_trace("n1=zx_log_z_pixels,D_direction_1=\"z\",D1_min=zx_log_z_min,D1_max=zx_log_z_max,")
        kidney.append_trace("n2=zx_log_x_pixels,D_direction_2=\"x\",D2_min=zx_log_x_min,D2_max=zx_log_x_max)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

        kidney.append_trace("COMPONENT logger_zy_spatial_con_channel_" + str(i) + "_all = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zy_spatial_con_channel_" + str(i) + "_all.dat\",")
        kidney.append_trace("n1=zy_log_z_pixels,D_direction_1=\"z\",D1_min=zy_log_z_min,D1_max=zy_log_z_max,")
        kidney.append_trace("n2=zy_log_y_pixels,D_direction_2=\"y\",D2_min=zy_log_y_min,D2_max=zy_log_y_max)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

        kidney.append_trace("COMPONENT logger_zx_spatial_con_channel_" + str(i) + "_1 = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zx_spatial_con_channel_" + str(i) + "_1.dat\",")
        kidney.append_trace("n1=zx_log_z_pixels,D_direction_1=\"z\",D1_min=zx_log_z_min,D1_max=zx_log_z_max,")
        kidney.append_trace("n2=zx_log_x_pixels,D_direction_2=\"x\",D2_min=zx_log_x_min,D2_max=zx_log_x_max,")
        kidney.append_trace("order_total=1)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

        kidney.append_trace("COMPONENT logger_zy_spatial_con_channel_" + str(i) + "_1 = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zy_spatial_con_channel_" + str(i) + "_1.dat\",")
        kidney.append_trace("n1=zy_log_z_pixels,D_direction_1=\"z\",D1_min=zy_log_z_min,D1_max=zy_log_z_max,")
        kidney.append_trace("n2=zy_log_y_pixels,D_direction_2=\"y\",D2_min=zy_log_y_min,D2_max=zy_log_y_max,")
        kidney.append_trace("order_total=1)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

        kidney.append_trace("COMPONENT logger_zx_spatial_con_channel_" + str(i) + "_2 = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zx_spatial_con_channel_" + str(i) + "_2.dat\",")
        kidney.append_trace("n1=zx_log_z_pixels,D_direction_1=\"z\",D1_min=zx_log_z_min,D1_max=zx_log_z_max,")
        kidney.append_trace("n2=zx_log_x_pixels,D_direction_2=\"x\",D2_min=zx_log_x_min,D2_max=zx_log_x_max,")
        kidney.append_trace("order_total=2)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

        kidney.append_trace("COMPONENT logger_zy_spatial_con_channel_" + str(i) + "_2 = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zy_spatial_con_channel_" + str(i) + "_2.dat\",")
        kidney.append_trace("n1=zy_log_z_pixels,D_direction_1=\"z\",D1_min=zy_log_z_min,D1_max=zy_log_z_max,")
        kidney.append_trace("n2=zy_log_y_pixels,D_direction_2=\"y\",D2_min=zy_log_y_min,D2_max=zy_log_y_max,")
        kidney.append_trace("order_total=2)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

        kidney.append_trace("COMPONENT logger_zx_spatial_con_channel_" + str(i) + "_3 = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zx_spatial_con_channel_" + str(i) + "_3.dat\",")
        kidney.append_trace("n1=zx_log_z_pixels,D_direction_1=\"z\",D1_min=zx_log_z_min,D1_max=zx_log_z_max,")
        kidney.append_trace("n2=zx_log_x_pixels,D_direction_2=\"x\",D2_min=zx_log_x_min,D2_max=zx_log_x_max,")
        kidney.append_trace("order_total=3)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

        kidney.append_trace("COMPONENT logger_zy_spatial_con_channel_" + str(i) + "_3 = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zy_spatial_con_channel_" + str(i) + "_3.dat\",")
        kidney.append_trace("n1=zy_log_z_pixels,D_direction_1=\"z\",D1_min=zy_log_z_min,D1_max=zy_log_z_max,")
        kidney.append_trace("n2=zy_log_y_pixels,D_direction_2=\"y\",D2_min=zy_log_y_min,D2_max=zy_log_y_max,")
        kidney.append_trace("order_total=3)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

        kidney.append_trace("COMPONENT logger_zx_spatial_con_channel_" + str(i) + "_4 = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zx_spatial_con_channel_" + str(i) + "_4.dat\",")
        kidney.append_trace("n1=zx_log_z_pixels,D_direction_1=\"z\",D1_min=zx_log_z_min,D1_max=zx_log_z_max,")
        kidney.append_trace("n2=zx_log_x_pixels,D_direction_2=\"x\",D2_min=zx_log_x_min,D2_max=zx_log_x_max,")
        kidney.append_trace("order_total=4)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

        kidney.append_trace("COMPONENT logger_zy_spatial_con_channel_" + str(i) + "_4 = Union_logger_2D_space(")
        kidney.append_trace("filename=\"logger_zy_spatial_con_channel_" + str(i) + "_4.dat\",")
        kidney.append_trace("n1=zy_log_z_pixels,D_direction_1=\"z\",D1_min=zy_log_z_min,D1_max=zy_log_z_max,")
        kidney.append_trace("n2=zy_log_y_pixels,D_direction_2=\"y\",D2_min=zy_log_y_min,D2_max=zy_log_y_max,")
        kidney.append_trace("order_total=4)")
        kidney.append_trace("AT (0,0,0) RELATIVE target")

# Data input on the analyzer "caves"
kidney.add_declare_var("double","kidney_cave1_width",value=0.04874) #At the edge from CAD (at 917.76: 57.1148 mm)
kidney.add_declare_var("double","kidney_cave1_height",value=0.140) #At the edge from CAD
kidney.add_declare_var("double","kidney_cave1_depth",value=0.55)
kidney.add_declare_var("double","kidney_cave1_start_target_dist",value=0.59) #less than kidney_inner_hull_radius
kidney.append_initialize("kidney_cave1_start_target_dist = kidney_hull_inner_radius-0.001;")




# New cave data input
kidney.add_declare_var("double","kidney_cave1_box1_width1",value=0.04803) # width when starting 2 cm before radius
kidney.add_declare_var("double","kidney_cave1_box1_width2",value=0.057166)
kidney.add_declare_var("double","kidney_cave1_box1_center_to_target")
kidney.append_initialize("kidney_cave1_box1_center_to_target = kidney_hull_inner_radius+0.5*(0.23989-0.02);")
kidney.add_declare_var("double","kidney_cave1_box1_depth",value=0.23989+0.021) # made this 1mm to large to intentionally overlap box2
kidney.add_declare_var("double","kidney_cave1_box1_height1",value=0.140) # updated later
kidney.add_declare_var("double","kidney_cave1_box1_height2",value=0.173) # updated later

kidney.add_declare_var("double","kidney_cave1_box2_width1",value=0.062634)
kidney.add_declare_var("double","kidney_cave1_box2_width2",value=0.067257)
kidney.add_declare_var("double","kidney_cave1_box2_center_to_target")
kidney.append_initialize("kidney_cave1_box2_center_to_target = kidney_hull_inner_radius+0.30609;")
kidney.add_declare_var("double","kidney_cave1_box2_x_offset",value=-0.5*0.005528)
kidney.add_declare_var("double","kidney_cave1_box2_depth",value=0.13240)
kidney.add_declare_var("double","kidney_cave1_box2_height1",value=0.2061) # updated later
kidney.add_declare_var("double","kidney_cave1_box2_height2",value=0.2061) # updated later

kidney.add_declare_var("double","kidney_cave1_box3_width1",value=0.061729)
#kidney.add_declare_var("double","kidney_cave1_box3_width2",value=0.04800)
kidney.add_declare_var("double","kidney_cave1_box3_width2",value=0.04534) # Updated to match the slope of the cylinder walls
kidney.add_declare_var("double","kidney_cave1_box3_center_to_target")
kidney.append_initialize("kidney_cave1_box3_center_to_target = kidney_hull_inner_radius+0.38819-0.001-0.01163*0.125;")
kidney.add_declare_var("double","kidney_cave1_box3_depth",value=0.03380+0.0005-0.01163*0.25) # can make this large
#kidney.add_declare_var("double","kidney_cave1_box3_depth",value=0.03380+0.0005-0.01163) # can make this large, slope match
kidney.add_declare_var("double","kidney_cave1_box3_height1",value=0.206) # updated later
kidney.add_declare_var("double","kidney_cave1_box3_height2",value=0.206) # updated later

kidney.add_declare_var("double","kidney_cave1_cyl1_radius",value=0.024)
kidney.add_declare_var("double","kidney_cave1_cyl1_center_to_target")
#kidney.append_initialize("kidney_cave1_cyl1_center_to_target = kidney_hull_inner_radius+0.40609;")
kidney.append_initialize("kidney_cave1_cyl1_center_to_target = kidney_hull_inner_radius+0.40609-0.01163;") # Correction for making the slopes match
kidney.add_declare_var("double","kidney_cave1_cyl1_height",value=0.25) # updated later

# Cave 2
kidney.add_declare_var("double","kidney_cave2_box1_y_rotation",value=106.4-90+1.71)
#kidney.add_declare_var("double","kidney_cave2_box1_y_rotation",value=0)
kidney.add_declare_var("double","kidney_cave2_box1_width1",value=0.063) #This value is not measured from CAD, but set close using geometry in the McStas file (approx)
kidney.add_declare_var("double","kidney_cave2_box1_depth",value=0.1129) #This value is not measured from CAD, but set close using geometry in the McStas file (approx)
#kidney.add_declare_var("double","kidney_cave2_box1_depth",value=0.1145) # Old version before spec detector misplacement found
kidney.add_declare_var("double","kidney_cave2_box1_width2")
kidney.append_initialize("kidney_cave2_box1_width2 = kidney_cave2_box1_width1 + 2*kidney_cave2_box1_depth*sin((106.4-90)*DEG2RAD);") #different angle, measured in cad

kidney.add_declare_var("double","kidney_cave2_box1_center_to_spec_detector_z")
kidney.add_declare_var("double","kidney_cave2_box1_center_to_spec_detector_x")
# These calculations are made from the CAD drawings and measurements therein.
kidney.append_initialize("kidney_cave2_box1_center_to_spec_detector_z = -0.29044 - 0.5*kidney_cave2_box1_width1*sin(kidney_cave2_box1_y_rotation*DEG2RAD) + 0.5*kidney_cave2_box1_depth*cos(kidney_cave2_box1_y_rotation*DEG2RAD);")
#kidney.append_initialize("kidney_cave2_box1_center_to_spec_detector_x = -0.029095 + 0.5*kidney_cave2_box1_width1*cos(kidney_cave2_box1_y_rotation*DEG2RAD) +  0.5*kidney_cave2_box1_depth*sin(kidney_cave2_box1_y_rotation*DEG2RAD);")
kidney.append_initialize("kidney_cave2_box1_center_to_spec_detector_x = -0.031 + 0.5*kidney_cave2_box1_width1*cos(kidney_cave2_box1_y_rotation*DEG2RAD) +  0.5*kidney_cave2_box1_depth*sin(kidney_cave2_box1_y_rotation*DEG2RAD);")

kidney.add_declare_var("double","kidney_cave2_box1_height1",value=0.206)
kidney.add_declare_var("double","kidney_cave2_box1_height2",value=0.206)

#box 2
kidney.add_declare_var("double","kidney_cave2_box2_width1",value=0.06017)
kidney.add_declare_var("double","kidney_cave2_box2_width2",value=0.05721)
kidney.add_declare_var("double","kidney_cave2_box2_center_to_detector",value=-0.19611)
kidney.add_declare_var("double","kidney_cave2_box2_depth",value=0.04962) # can make this large
kidney.add_declare_var("double","kidney_cave2_box2_height1",value=0.2061)
kidney.add_declare_var("double","kidney_cave2_box2_height2",value=0.2061)

#box 3
kidney.add_declare_var("double","kidney_cave2_box3_width1",value=0.05721)
kidney.add_declare_var("double","kidney_cave2_box3_width2",value=0.0470)
kidney.add_declare_var("double","kidney_cave2_box3_center_to_detector",value=-0.08565)
kidney.add_declare_var("double","kidney_cave2_box3_depth",value=0.17130+0.0005) # can make this large
kidney.add_declare_var("double","kidney_cave2_box3_height1",value=0.185)
kidney.add_declare_var("double","kidney_cave2_box3_height2",value=0.120)

# cyl1
kidney.add_declare_var("double","kidney_cave2_cyl1_radius",value=0.0235)
#kidney.add_declare_var("double","kidney_cave2_cyl1_height",value=0.340)
kidney.add_declare_var("double","kidney_cave2_cyl1_height",value=0.25)



kidney.add_declare_var("double","kidney_cave2_start_target_dist",value=0.96)

kidney.add_declare_var("double","analyzer_1_center_to_sample",value=0.99939)
kidney.add_declare_var("double","analyzer_seperation",value=0.07)

# temp
kidney.add_declare_var("double","analyzer_2theta_min",value=40)
kidney.add_declare_var("double","analyzer_2theta_max",value=140)
kidney.add_declare_var("double","delta_analyzer_2theta")
kidney.add_declare_var("double","analyzer_2theta",array=kidney_channels)
kidney.add_declare_var("double","analyzer_theta",array=kidney_channels)

# demo mode, all analyzers have different angles
'''
if kidney_channels != 1:
    kidney.add_declare_var("int","kidney_iterate")
    kidney.append_initialize("delta_analyzer_2theta = (analyzer_2theta_max - analyzer_2theta_min)/" + str(kidney_channels-1) + ";")
    kidney.append_initialize("for (kidney_iterate=0;kidney_iterate<" + str(kidney_channels) + ";kidney_iterate++) {")
    kidney.append_initialize("  analyzer_2theta[kidney_iterate] = analyzer_2theta_min + (double) kidney_iterate * delta_analyzer_2theta;")
    kidney.append_initialize("  analyzer_theta[kidney_iterate] = 0.5*analyzer_2theta[kidney_iterate];")
    kidney.append_initialize("}")
else:
    kidney.append_initialize("")
    kidney.append_initialize("  analyzer_2theta[0] = 0.5*(analyzer_2theta_min + analyzer_2theta_max);")
    kidney.append_initialize("  analyzer_theta[0] = 0.5*analyzer_2theta[0];")
    kidney.append_initialize("")
'''


kidney.add_declare_var("int","kidney_iterate")
kidney.append_initialize("delta_analyzer_2theta = (analyzer_2theta_max - analyzer_2theta_min)/" + str(kidney_channels-1) + ";")
kidney.append_initialize("for (kidney_iterate=0;kidney_iterate<" + str(kidney_channels) + ";kidney_iterate++) {")
kidney.append_initialize("  analyzer_theta[kidney_iterate] = RAD2DEG*asin(1.87325/2./sqrt(EF_all/2.0717));")
kidney.append_initialize("  analyzer_2theta[kidney_iterate] = 2.0*analyzer_theta[kidney_iterate];")
kidney.append_initialize("}")

    

# colimator
kidney.add_declare_var("double","inter_analyzer_colimator_width",value=0.0006) # 0.6 mm width from document
kidney.add_declare_var("double","inter_analyzer_colimator_height",value=0.202) # from cad
kidney.add_declare_var("double","inter_analyzer_colimator_depth",value=0.0127) # from cadq
kidney.add_declare_var("double","inter_analyzer_colimator_start_pos",value=0.016*2)
kidney.add_declare_var("double","inter_analyzer_colimator_seperation",value=0.016)


# detector input
kidney.add_declare_var("double","detector_radius",value=0.018)
kidney.add_declare_var("double","detector_height",value=0.14)
kidney.add_declare_var("double","diffraction_detector_to_sample")
kidney.append_initialize("diffraction_detector_to_sample=kidney_cave1_cyl1_center_to_target;")
kidney.add_declare_var("double","spec_detector_to_sample",value=1.25)
kidney.add_declare_var("double","spec_detector_to_analyzer_2_center")
# I don't believe this calculation is correct, when layering simulation output and cad, this seems like ~1 cm off.
kidney.append_initialize("spec_detector_to_analyzer_2_center = sqrt(spec_detector_to_sample*spec_detector_to_sample-analyzer_seperation*analyzer_seperation)-analyzer_1_center_to_sample;")
# Corrected version (Second detector is 1.250 m from sample, the two analyzers are almost on a sphere
kidney.append_initialize("spec_detector_to_analyzer_2_center = spec_detector_to_sample-analyzer_1_center_to_sample;")

# Input of priority range of cave1
priority_start = 200
priority_end   = 2200
this_priority = priority_start - (priority_end-priority_start)/kidney_channels

for i in range(0,kidney_channels):
    this_priority = this_priority + (priority_end-priority_start)/kidney_channels
    '''
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave1 = Union_box(")
    kidney.append_trace("    xwidth= kidney_cave1_width,yheight=kidney_cave1_height,zdepth=kidney_cave1_depth,")
    kidney.append_trace("    priority=" + str(this_priority) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (0,0,kidney_cave1_start_target_dist+0.5*kidney_cave1_depth) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave2 = Union_box(")
    kidney.append_trace("    xwidth= kidney_cave2_width,yheight=kidney_cave2_height,zdepth=kidney_cave2_depth,")
    kidney.append_trace("    priority=" + str(this_priority+1) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (-0.95*(kidney_cave1_width+kidney_cave2_width)*0.5,0,kidney_cave2_start_target_dist+0.5*kidney_cave2_depth) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")
    '''
    
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave1_box1 = Union_box(")
    kidney.append_trace("    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,")
    kidney.append_trace("    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,")
    kidney.append_trace("    priority=" + str(this_priority) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave1_box2 = Union_box(")
    kidney.append_trace("    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,")
    kidney.append_trace("    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,")
    kidney.append_trace("    priority=" + str(this_priority+5) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave1_box3 = Union_box(")
    kidney.append_trace("    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,")
    kidney.append_trace("    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,")
    kidney.append_trace("    priority=" + str(this_priority+2) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave1_cyl1 = Union_cylinder(")
    kidney.append_trace("    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,")
    kidney.append_trace("    priority=" + str(this_priority+3) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_analyzer_1_center = Arm()")
    kidney.append_trace("  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_analyzer_1_rotated = Arm()")
    kidney.append_trace("  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[" + str(i) + "]*DEG2RAD)) RELATIVE channel_" + str(i) + "_analyzer_1_center")
    kidney.append_trace("  ROTATED (0,180-analyzer_theta[" + str(i) + "],0) RELATIVE channel_" + str(i) + "_analyzer_1_center")
    kidney.append_trace("")
    McStas_class.append_vertical_crystal_array(kidney, name = "channel_" + str(i) + "_analyzer_1_array", crystal_width = 0.06, crystal_height = 0.02, crystal_depth = 0.002, number_of_crystals = 9, total_height = 0.18, radius_of_curvature = 0.5, arm_name = "channel_" + str(i) + "_analyzer_1_rotated", priority_start = this_priority+20, priority_end = this_priority+20.9, material_name = "PG_analyzer")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_analyzer_2_center = Arm()")
    kidney.append_trace("  AT (-analyzer_seperation,0,0) RELATIVE channel_" + str(i) + "_analyzer_1_center")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_analyzer_2_rotated = Arm()")
    kidney.append_trace("  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[" + str(i) + "]*DEG2RAD)) RELATIVE channel_" + str(i) + "_analyzer_2_center")
    kidney.append_trace("  ROTATED (0,-analyzer_theta[" + str(i) + "],0) RELATIVE channel_" + str(i) + "_analyzer_2_center")
    kidney.append_trace("")
    McStas_class.append_vertical_crystal_array(kidney, name = "channel_" + str(i) + "_analyzer_2_array", crystal_width = 0.06, crystal_height = 0.02, crystal_depth = 0.002, number_of_crystals = 9, total_height = 0.18, radius_of_curvature = 0.5, arm_name = "channel_" + str(i) + "_analyzer_2_rotated", priority_start = this_priority+21, priority_end = this_priority+21.9, material_name = "PG_analyzer")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave2_cyl1 = Union_cylinder(")
    kidney.append_trace("    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,")
    kidney.append_trace("    priority=" + str(this_priority+7.5) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_" + str(i) + "_analyzer_2_center")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE channel_" + str(i) + "_analyzer_2_center")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave2_box1 = Union_box(")
    kidney.append_trace("    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,")
    kidney.append_trace("    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,")
    kidney.append_trace("    priority=" + str(this_priority+1) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_" + str(i) + "_cave2_cyl1")
    kidney.append_trace("  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_" + str(i) + "_cave2_cyl1")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave2_box2 = Union_box(")
    kidney.append_trace("    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,")
    kidney.append_trace("    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,")
    kidney.append_trace("    priority=" + str(this_priority+6) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_" + str(i) + "_cave2_cyl1")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE channel_" + str(i) + "_cave2_cyl1")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT channel_" + str(i) + "_cave2_box3 = Union_box(")
    kidney.append_trace("    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,")
    kidney.append_trace("    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,")
    kidney.append_trace("    priority=" + str(this_priority+7) + ",material_string=\"Vacuum\")")
    kidney.append_trace("  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_" + str(i) + "_cave2_cyl1")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE channel_" + str(i) + "_cave2_cyl1")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT inter_analyzer_colimator_center_" + str(i) + " = Arm()")
    kidney.append_trace("  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_" + str(i) + "_analyzer_1_center")
    kidney.append_trace("  ROTATED (0,0,0)  RELATIVE channel_" + str(i) + "_analyzer_1_center")
    kidney.append_trace("")
    for j in range(0,5):
        kidney.append_trace("COMPONENT inter_analyzer_colimator_" + str(i) + "_blade_" + str(j) + " = Union_box(")
        kidney.append_trace("    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,")
        kidney.append_trace("    priority=" + str(this_priority+25+j) + ",material_string=\"Collimator_gad\")")
        kidney.append_trace("  AT (0,0,inter_analyzer_colimator_start_pos - " + str(j) + "*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_" + str(i) )
        kidney.append_trace("  ROTATED (0,-analyzer_2theta[" + str(i) + "],0) RELATIVE inter_analyzer_colimator_center_" + str(i) )
        kidney.append_trace("")

    # This section of code is to be used with cylinder He3 detectors to be added later
    '''
    kidney.append_trace("COMPONENT diffraction_detector_" + str(i) + "_exit_volume = Union_cylinder(")
    kidney.append_trace("    radius = 1.01*detector_radius, yheight = 1.01*detector_height,")
    kidney.append_trace("    priority=" + str(this_priority+10) + ",material_string=\"Exit\")")
    kidney.append_trace("  AT (0,0,diffraction_detector_to_sample) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")
    kidney.append_trace("COMPONENT spec_detector_" + str(i) + "_exit_volume = Union_cylinder(")
    kidney.append_trace("    radius = 1.01*detector_radius, yheight = 1.01*detector_height,")
    kidney.append_trace("    priority=" + str(this_priority+11) + ",material_string=\"Exit\")")
    kidney.append_trace("  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_" + str(i) + "_analyzer_2_center")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE channel_" + str(i) + "_analyzer_2_center")
    kidney.append_trace("")
    '''
    
    
    kidney.append_trace("COMPONENT diffraction_detector_" + str(i) + "_exit_volume = Union_box(")
    kidney.append_trace("    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,")
    if enable_exit_diffraction[i] == 1:
        kidney.append_trace("    priority=" + str(this_priority+31) + ",material_string=\"Exit\")")
    else:
        kidney.append_trace("    priority=" + str(this_priority+31) + ",material_string=\"Vacuum\")")
    #kidney.append_trace("  AT (0,0,diffraction_detector_to_sample) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("  AT (0,0,0) RELATIVE channel_" + str(i) + "_cave1_cyl1")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE kidney_channel_" + str(i) )
    kidney.append_trace("")
    
    
    kidney.append_trace("COMPONENT spec_detector_" + str(i) + "_exit_volume = Union_box(")
    kidney.append_trace("    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,")
    if enable_exit_spectroscopy[i] == 1:
        kidney.append_trace("    priority=" + str(this_priority+32) + ",material_string=\"Exit\")")
    else:
        kidney.append_trace("    priority=" + str(this_priority+32) + ",material_string=\"Vacuum\")")
    #kidney.append_trace("  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_" + str(i) + "_analyzer_2_center")
    kidney.append_trace("  AT (0,0,0) RELATIVE channel_" + str(i) + "_cave2_cyl1")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE channel_" + str(i) + "_analyzer_2_center")
    kidney.append_trace("")

    if (enable_conditional[i] == 1):
        kidney.append_trace("COMPONENT spec_detector_" + str(i) + "_conditional = Union_conditional_PSD(")
        #kidney.append_trace("  target_loggers=\"logger_zx_spatial_con_channel_" + str(i) + ",logger_zy_spatial_con_channel_" + str(i) +"\",")
        kidney.append_trace("  target_loggers=\"logger_zx_spatial_con_channel_" + str(i) + "_all,logger_zy_spatial_con_channel_" + str(i) +"_all,logger_zx_spatial_con_channel_" + str(i) + "_1,logger_zy_spatial_con_channel_" + str(i) +"_1,logger_zx_spatial_con_channel_" + str(i) + "_2,logger_zy_spatial_con_channel_" + str(i) +"_2,logger_zx_spatial_con_channel_" + str(i) + "_3,logger_zy_spatial_con_channel_" + str(i) +"_3,logger_zx_spatial_con_channel_" + str(i) + "_4,logger_zy_spatial_con_channel_" + str(i) +"_4\",")
        kidney.append_trace("  xwidth = 2.0*detector_radius, yheight = 1.0*detector_height,overwrite_logger_weight=1)")
        kidney.append_trace("  AT (0,0,0.01) RELATIVE channel_" + str(i) + "_cave2_cyl1")
        kidney.append_trace("  ROTATED (0,0,0) RELATIVE channel_" + str(i) + "_analyzer_2_center")
        kidney.append_trace("")
        kidney.append_trace("")


kidney.append_trace("COMPONENT kidney_union_master = Union_master(inherit_number_of_scattering_events=1)")
#kidney.append_trace("AT (0,0,0) RELATIVE kidney_master")
kidney.append_trace("AT (0,0,0) RELATIVE target")
kidney.append_trace("")

kidney.add_declare_var("int","detector_channel_diff")
kidney.add_declare_var("int","detector_channel_spec")
kidney.add_declare_var("int","nx_detector",value=5)
kidney.add_declare_var("int","ny_detector",value=5)
kidney.add_declare_var("int","detector_found")

for i in range(0,kidney_channels):
    
    kidney.append_trace("COMPONENT diffraction_detector_" + str(i) + " = PSD_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nx=5, ny=5, filename=\"diff_detector_"+ str(i) + "\")")
    kidney.append_trace("  AT (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  GROUP detector_group")
    kidney.append_trace("  EXTEND %{")
    kidney.append_trace("    if (SCATTERED) {")
    kidney.append_trace("      detector_channel_diff =" + str(i) + ";")
    kidney.append_trace("      detector_channel_spec =-1;")
    kidney.append_trace("      detector_found = 1;")
    kidney.append_trace("    }")
    kidney.append_trace("  %}")
    kidney.append_trace("")
    
    kidney.append_trace("COMPONENT spec_detector_" + str(i) + " = PSD_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nx=5, ny=5, filename=\"spec_detector_"+ str(i) + "\")")
    kidney.append_trace("  AT (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  GROUP detector_group")
    kidney.append_trace("  EXTEND %{")
    kidney.append_trace("    if (SCATTERED) {")
    kidney.append_trace("      detector_channel_spec =" + str(i) + ";")
    kidney.append_trace("      detector_channel_diff =-1;")
    kidney.append_trace("      detector_found = 1;")
    kidney.append_trace("    }")
    kidney.append_trace("  %}")
    kidney.append_trace("")
    
    
    
    
    '''
    kidney.append_trace("COMPONENT diffraction_detector_sample_" + str(i) + " = PSD_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nx=5, ny=5, filename=\"diff_detector_sample_"+ str(i) + "\")")
    kidney.append_trace("  WHEN(detector_channel_diff == " + str(i) + " && only_sample_scattering == 1)")
    kidney.append_trace("  AT (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT diffraction_detector_environment_" + str(i) + " = PSD_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nx=5, ny=5, filename=\"diff_detector_environment_"+ str(i) + "\")")
    kidney.append_trace("  WHEN(detector_channel_diff == " + str(i) + " && scatter_events_in_sample_environment > 0)")
    kidney.append_trace("  AT (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT diffraction_detector_single_sample_" + str(i) + " = PSD_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nx=5, ny=5, filename=\"diff_detector_single_sample_"+ str(i) + "\")")
    kidney.append_trace("  WHEN(detector_channel_diff == " + str(i) + " && scatter_events_in_sample == 1)")
    kidney.append_trace("  AT (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("")
    '''

    
for i in range(0,kidney_channels):

    kidney.add_declare_var("int","flag_sum");
    kidney.add_declare_var("int","flag_single");
    kidney.append_trace("COMPONENT spec_detector_history_" + str(i) + " = extend_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename=\"spec_detector_history_"+ str(i) + "\")")
    kidney.append_trace("  WHEN(detector_channel_spec == " + str(i) + " && detector_found ==1)")
    kidney.append_trace("  AT (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  EXTEND %{")
    kidney.append_trace("    if (SCATTERED) {")
    kidney.append_trace("      flag_sum=0;")
    kidney.append_trace("      for (flag_index=1;flag_index<MAX_VOLUME_HISTORY_LENGTH;flag_index++) {")
    kidney.append_trace("        if (scattering_history_sample_master[flag_index] > 0) {")
    kidney.append_trace("          C_N[flag_index+1]++;")
    kidney.append_trace("          C_p[flag_index+1] += p;")
    kidney.append_trace("          C_p2[flag_index+1] += p*p;")
    kidney.append_trace("          flag_sum++;")
    kidney.append_trace("          flag_single = flag_index;")
    kidney.append_trace("        };")
    kidney.append_trace("      };")
    kidney.append_trace("      if (flag_sum == 0) {")
    kidney.append_trace("        C_N[1]++;")
    kidney.append_trace("        C_p[1] += p;")
    kidney.append_trace("        C_p2[1] += p*p;")
    kidney.append_trace("      };")
    kidney.append_trace("      if (flag_sum == 1) {")
    kidney.append_trace("        if (scattering_history_sample_master[flag_single] == 1) {")
    kidney.append_trace("          C_N[MAX_VOLUME_HISTORY_LENGTH+flag_single+1]++;")
    kidney.append_trace("          C_p[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p;")
    kidney.append_trace("          C_p2[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p*p;")
    kidney.append_trace("        };")
    kidney.append_trace("      };")
    kidney.append_trace("    };")
    kidney.append_trace("  %}")
    kidney.append_trace("")
    
    '''
    # Resolution monitor
    kidney.append_trace("COMPONENT spec_detector_" + str(i) + "_resolution = Res_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    res_sample_comp=Resolution_sample,filename=\"spec_detector_res_"+ str(i) + "\")")
    kidney.append_trace("  WHEN(detector_channel_spec == " + str(i) + " && detector_found ==1)")
    kidney.append_trace("  AT (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("")
    '''
    
    '''
    # Only needed if the resolution monitor takes the place of the regular detector
    kidney.append_trace("  GROUP detector_group")
    kidney.append_trace("  EXTEND %{")
    kidney.append_trace("    if (SCATTERED) {")
    kidney.append_trace("      detector_channel_spec =" + str(i) + ";")
    kidney.append_trace("      detector_channel_diff =-1;")
    kidney.append_trace("      detector_found = 1;")
    kidney.append_trace("    }")
    kidney.append_trace("  %}")
    kidney.append_trace("")
    '''
    
    '''
    # Debug monitor used to trace down rays that somehow end up in the center detectors after scattering in the sample and getting energies way outside of the analysator target. The energies are evenly spred in the entire spectrum. Only occurs in the center channels for some reason.
    kidney.append_trace("COMPONENT spec_detector_history_" + str(i) + "_E_off = extend_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nb=MAX_VOLUME_HISTORY_LENGTH, filename=\"spec_detector_history_E_off_"+ str(i) + "\")")
    kidney.append_trace("  WHEN(detector_channel_spec == " + str(i) + " && E_off == 1  && detector_found ==1)")
    kidney.append_trace("  AT (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  EXTEND %{")
    kidney.append_trace("    if (SCATTERED) {")
    kidney.append_trace("      flag_sum=0;")
    kidney.append_trace("      for (flag_index=1;flag_index<MAX_VOLUME_HISTORY_LENGTH;flag_index++) {")
    kidney.append_trace("        if (scattering_history_sample_master[flag_index] > 0) {")
    kidney.append_trace("          C_N[flag_index+1]++;")
    kidney.append_trace("          C_p[flag_index+1] += p;")
    kidney.append_trace("          C_p2[flag_index+1] += p*p;")
    kidney.append_trace("          flag_sum++;")
    kidney.append_trace("        };")
    kidney.append_trace("      };")
    kidney.append_trace("      if (flag_sum == 0) {")
    kidney.append_trace("        C_N[1]++;")
    kidney.append_trace("        C_p[1] += p;")
    kidney.append_trace("        C_p2[1] += p*p;")
    kidney.append_trace("      };")
    kidney.append_trace("    };")
    kidney.append_trace("  %}")
    '''

    '''
    kidney.append_trace("COMPONENT spec_detector_sample_" + str(i) + " = PSD_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nx=5, ny=5, filename=\"spec_detector_sample_"+ str(i) + "\")")
    kidney.append_trace("  WHEN(detector_channel_spec == " + str(i) + " && only_sample_scattering == 1)")
    kidney.append_trace("  AT (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT spec_detector_environment_" + str(i) + " = PSD_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nx=5, ny=5, filename=\"spec_detector_environment_"+ str(i) + "\")")
    kidney.append_trace("  WHEN(detector_channel_spec == " + str(i) + " && scatter_events_in_sample_environment > 0)")
    kidney.append_trace("  AT (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT spec_detector_single_sample_" + str(i) + " = PSD_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,")
    kidney.append_trace("    nx=5, ny=5, filename=\"spec_detector_single_sample_"+ str(i) + "\")")
    kidney.append_trace("  WHEN(detector_channel_spec == " + str(i) + " && scatter_events_in_sample == 1)")
    kidney.append_trace("  AT (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    '''
    
    '''
    # Tof detectors for Jonas
    kidney.append_trace("COMPONENT diffraction_detector_" + str(i) + " = TOF_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,")
    kidney.append_trace("    tmin=1.07E3, tmax=1.140E3,nt=1000, filename=\"diff_detector_tof"+ str(i) + "\")")
    kidney.append_trace("  AT (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE diffraction_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  GROUP detector_group")
    kidney.append_trace("")
    kidney.append_trace("COMPONENT spec_detector_" + str(i) + " = TOF_monitor(")
    kidney.append_trace("    xwidth=2.0*detector_radius, yheight=1.0*detector_height,")
    kidney.append_trace("    tmin=1.3E3, tmax=1.36E3,nt=1000, filename=\"spec_detector_tof"+ str(i) + "\")")
    kidney.append_trace("  AT (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  ROTATED (0,0,0) RELATIVE spec_detector_" + str(i) + "_exit_volume")
    kidney.append_trace("  GROUP detector_group")
    '''
    

kidney.write_c_files()




analyzator_test = McStas_class.McStas_part("analysator_test")
McStas_class.append_vertical_crystal_array(analyzator_test, name = "first_array", crystal_width = 0.03, crystal_height = 0.02, crystal_depth = 0.002, number_of_crystals = 11, total_height = 0.24, radius_of_curvature = 2, arm_name = "analysator_array_pos", priority_start = 42.1, priority_end = 42.2, material_name = "PG")

analyzator_test.write_c_files()

















