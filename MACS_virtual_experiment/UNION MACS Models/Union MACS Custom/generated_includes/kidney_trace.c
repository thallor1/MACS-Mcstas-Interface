// Start of trace section for generated kidney
COMPONENT kidney_master = Arm()
  AT (0,0,0) RELATIVE target
  ROTATED (0,kidney_angle,0) RELATIVE target
  EXTEND %{
    channel_selected = -1;
  %}

// Arms for each channel of MACS
COMPONENT kidney_channel_0 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-4,0) RELATIVE kidney_master

COMPONENT kidney_channel_1 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,4,0) RELATIVE kidney_master

COMPONENT kidney_channel_2 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,12,0) RELATIVE kidney_master

// Filters that also check for scattering to select the correct channel
COMPONENT channel_0_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_0
  ROTATED (0,0,0) RELATIVE kidney_channel_0
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 0;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_1_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 1;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_2_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 2;
    //printf("channel_selected = %d\n",channel_selected);
  %}

// dummy arm that absorbs rays that did not hit any filter
COMPONENT channel_selector = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,0,0) RELATIVE kidney_master
  EXTEND %{
    if (channel_selected == -1) ABSORB;
    detector_found = 0;
  %}

COMPONENT channel_0_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 0)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_0
  ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT channel_1_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 1)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_2_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 2)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT boron_plastic_incoherent = Incoherent_process(
    sigma=1.80, packing_factor=1, unit_cell_volume=1, interact_fraction=-1)
AT (0,0,0) ABSOLUTE

COMPONENT boron_plastic = Union_make_material(my_absorption=3495,
  process_string="boron_plastic_incoherent")
AT (0,0,0) ABSOLUTE

COMPONENT boron_plastic_enriched_incoherent = Incoherent_process(
    sigma=1.82, packing_factor=1, unit_cell_volume=1, interact_fraction=-1)
AT (0,0,0) ABSOLUTE

COMPONENT boron_plastic_enriched = Union_make_material(my_absorption=8071,
  process_string="boron_plastic_enriched_incoherent")
AT (0,0,0) ABSOLUTE

COMPONENT Collimator_gad = Union_make_material(my_absorption=1000.0*4/35.29*100, absorber=1,
  process_string="")
AT (0,0,0) ABSOLUTE

COMPONENT Incoherent_PG_analyzer = Incoherent_process(
    sigma=4*0.001, packing_factor=1, unit_cell_volume=35.29, interact_fraction=-1)
AT (0,0,0) ABSOLUTE

COMPONENT Single_crystal_PG_analyzer = Single_crystal_process(
     mosaic = 50, reflections = "C_graphite.lau",
     ax = 0,    ay = 2.14, az =-1.24,
     bx = 0,    by = 0,    bz = 2.47,
     cx = 6.71, cy = 0,    cz = 0,
     barns=0,packing_factor=1)
AT (0,0,0) ABSOLUTE
ROTATED (0,0,0) ABSOLUTE

COMPONENT PG_analyzer = Union_make_material(my_absorption=0.0035*4/35.29*100,
  process_string="Single_crystal_PG_analyzer,Incoherent_PG_analyzer")
AT (0,0,0) ABSOLUTE
COMPONENT kidney_hull = Union_cylinder(radius=kidney_hull_radius,yheight=kidney_hull_height,
      priority=100,material_string="boron_plastic",p_interact=0.3)
AT (0,0,0) RELATIVE kidney_master
ROTATED (0,0,0) RELATIVE kidney_master

COMPONENT kidney_hull_cut = Union_cylinder(radius=kidney_hull_inner_radius,yheight=1.002*kidney_hull_height,
      priority=100.5,material_string="Vacuum")
AT (0,0,0) RELATIVE kidney_master
ROTATED (0,0,0) RELATIVE kidney_master

COMPONENT kidney_hull_box_cut_arm1 = Arm()
AT (0,0,0) RELATIVE kidney_master
ROTATED (0,0.5*kidney_cylinder_angle+90,0) RELATIVE kidney_master

COMPONENT kidney_hull_box_cut1 = Union_box(xwidth=2.1*kidney_hull_radius,yheight=1.003*kidney_hull_height,zdepth=1.2*kidney_hull_radius,
  priority=101,material_string="Vacuum",visualize=0)
AT (0,0,0.6*kidney_hull_radius) RELATIVE kidney_hull_box_cut_arm1
ROTATED (0,0,0) RELATIVE kidney_hull_box_cut_arm1

COMPONENT kidney_hull_box_cut_arm2 = Arm()
AT (0,0,0) RELATIVE kidney_master
ROTATED (0,-0.5*kidney_cylinder_angle-90,0) RELATIVE kidney_master

COMPONENT kidney_hull_box_cut2 = Union_box(xwidth=2.1*kidney_hull_radius,yheight=1.004*kidney_hull_height,zdepth=1.2*kidney_hull_radius,
  priority=102,material_string="Vacuum",visualize=0)
AT (0,0,0.6*kidney_hull_radius) RELATIVE kidney_hull_box_cut_arm2
ROTATED (0,0,0) RELATIVE kidney_hull_box_cut_arm2

COMPONENT channel_0_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=200,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_0
  ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT channel_0_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=205,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_0
  ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT channel_0_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=202,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_0
  ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT channel_0_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=203,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_0
  ROTATED (0,0,0) RELATIVE kidney_channel_0


COMPONENT channel_0_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_0

COMPONENT channel_0_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[0]*DEG2RAD)) RELATIVE channel_0_analyzer_1_center
  ROTATED (0,180-analyzer_theta[0],0) RELATIVE channel_0_analyzer_1_center

COMPONENT channel_0_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_0_analyzer_1_array_crystal_width, yheight = channel_0_analyzer_1_array_crystal_height, xwidth = channel_0_analyzer_1_array_crystal_depth,
   priority = 220.0, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[0])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[0]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[0]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_0_analyzer_1_array_crystal_width, yheight = channel_0_analyzer_1_array_crystal_height, xwidth = channel_0_analyzer_1_array_crystal_depth,
   priority = 220.1, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[1])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[1]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[1]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_0_analyzer_1_array_crystal_width, yheight = channel_0_analyzer_1_array_crystal_height, xwidth = channel_0_analyzer_1_array_crystal_depth,
   priority = 220.2, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[2])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[2]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[2]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_0_analyzer_1_array_crystal_width, yheight = channel_0_analyzer_1_array_crystal_height, xwidth = channel_0_analyzer_1_array_crystal_depth,
   priority = 220.3, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[3])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[3]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[3]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_0_analyzer_1_array_crystal_width, yheight = channel_0_analyzer_1_array_crystal_height, xwidth = channel_0_analyzer_1_array_crystal_depth,
   priority = 220.4, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[4])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[4]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[4]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_0_analyzer_1_array_crystal_width, yheight = channel_0_analyzer_1_array_crystal_height, xwidth = channel_0_analyzer_1_array_crystal_depth,
   priority = 220.5, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[5])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[5]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[5]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_0_analyzer_1_array_crystal_width, yheight = channel_0_analyzer_1_array_crystal_height, xwidth = channel_0_analyzer_1_array_crystal_depth,
   priority = 220.6, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[6])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[6]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[6]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_0_analyzer_1_array_crystal_width, yheight = channel_0_analyzer_1_array_crystal_height, xwidth = channel_0_analyzer_1_array_crystal_depth,
   priority = 220.7, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[7])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[7]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[7]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_0_analyzer_1_array_crystal_width, yheight = channel_0_analyzer_1_array_crystal_height, xwidth = channel_0_analyzer_1_array_crystal_depth,
   priority = 220.8, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[8])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[8]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[8]) RELATIVE channel_0_analyzer_1_rotated


COMPONENT channel_0_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_0_analyzer_1_center

COMPONENT channel_0_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[0]*DEG2RAD)) RELATIVE channel_0_analyzer_2_center
  ROTATED (0,-analyzer_theta[0],0) RELATIVE channel_0_analyzer_2_center

COMPONENT channel_0_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_0_analyzer_2_array_crystal_width, yheight = channel_0_analyzer_2_array_crystal_height, xwidth = channel_0_analyzer_2_array_crystal_depth,
   priority = 221.0, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[0])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[0]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[0]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_0_analyzer_2_array_crystal_width, yheight = channel_0_analyzer_2_array_crystal_height, xwidth = channel_0_analyzer_2_array_crystal_depth,
   priority = 221.1, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[1])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[1]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[1]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_0_analyzer_2_array_crystal_width, yheight = channel_0_analyzer_2_array_crystal_height, xwidth = channel_0_analyzer_2_array_crystal_depth,
   priority = 221.2, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[2])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[2]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[2]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_0_analyzer_2_array_crystal_width, yheight = channel_0_analyzer_2_array_crystal_height, xwidth = channel_0_analyzer_2_array_crystal_depth,
   priority = 221.3, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[3])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[3]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[3]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_0_analyzer_2_array_crystal_width, yheight = channel_0_analyzer_2_array_crystal_height, xwidth = channel_0_analyzer_2_array_crystal_depth,
   priority = 221.4, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[4])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[4]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[4]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_0_analyzer_2_array_crystal_width, yheight = channel_0_analyzer_2_array_crystal_height, xwidth = channel_0_analyzer_2_array_crystal_depth,
   priority = 221.5, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[5])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[5]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[5]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_0_analyzer_2_array_crystal_width, yheight = channel_0_analyzer_2_array_crystal_height, xwidth = channel_0_analyzer_2_array_crystal_depth,
   priority = 221.6, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[6])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[6]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[6]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_0_analyzer_2_array_crystal_width, yheight = channel_0_analyzer_2_array_crystal_height, xwidth = channel_0_analyzer_2_array_crystal_depth,
   priority = 221.7, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[7])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[7]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[7]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_0_analyzer_2_array_crystal_width, yheight = channel_0_analyzer_2_array_crystal_height, xwidth = channel_0_analyzer_2_array_crystal_depth,
   priority = 221.8, material_string = "PG_analyzer")
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[8])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[8]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[8]) RELATIVE channel_0_analyzer_2_rotated


COMPONENT channel_0_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=207.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_0_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_0_analyzer_2_center

COMPONENT channel_0_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=201,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_0_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_0_cave2_cyl1

COMPONENT channel_0_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=206,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_0_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_0_cave2_cyl1

COMPONENT channel_0_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=207,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_0_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_0_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_0 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_0_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_0_analyzer_1_center

COMPONENT inter_analyzer_colimator_0_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=225,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
  ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT inter_analyzer_colimator_0_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=226,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
  ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT inter_analyzer_colimator_0_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=227,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
  ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT inter_analyzer_colimator_0_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=228,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
  ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT inter_analyzer_colimator_0_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=229,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
  ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT diffraction_detector_0_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=231,material_string="Exit")
  AT (0,0,0) RELATIVE channel_0_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT spec_detector_0_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=232,material_string="Exit")
  AT (0,0,0) RELATIVE channel_0_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_0_analyzer_2_center

COMPONENT channel_1_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=866,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=871,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=868,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=869,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1


COMPONENT channel_1_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_1

COMPONENT channel_1_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[1]*DEG2RAD)) RELATIVE channel_1_analyzer_1_center
  ROTATED (0,180-analyzer_theta[1],0) RELATIVE channel_1_analyzer_1_center

COMPONENT channel_1_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 886.0, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[0])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[0]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[0]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 886.1, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[1])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[1]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[1]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 886.2, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[2])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[2]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[2]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 886.3, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[3])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[3]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[3]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 886.4, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[4])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[4]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[4]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 886.5, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[5])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[5]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[5]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 886.6, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[6])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[6]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[6]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 886.7, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[7])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[7]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[7]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 886.8, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[8])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[8]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[8]) RELATIVE channel_1_analyzer_1_rotated


COMPONENT channel_1_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_1_analyzer_1_center

COMPONENT channel_1_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[1]*DEG2RAD)) RELATIVE channel_1_analyzer_2_center
  ROTATED (0,-analyzer_theta[1],0) RELATIVE channel_1_analyzer_2_center

COMPONENT channel_1_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 887.0, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[0])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[0]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[0]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 887.1, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[1])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[1]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[1]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 887.2, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[2])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[2]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[2]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 887.3, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[3])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[3]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[3]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 887.4, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[4])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[4]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[4]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 887.5, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[5])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[5]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[5]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 887.6, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[6])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[6]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[6]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 887.7, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[7])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[7]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[7]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 887.8, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[8])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[8]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[8]) RELATIVE channel_1_analyzer_2_rotated


COMPONENT channel_1_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=873.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_1_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_1_analyzer_2_center

COMPONENT channel_1_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=867,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_1_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_1_cave2_cyl1

COMPONENT channel_1_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=872,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_1_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_1_cave2_cyl1

COMPONENT channel_1_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=873,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_1_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_1_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_1 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_1_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_1_analyzer_1_center

COMPONENT inter_analyzer_colimator_1_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=891,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=892,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=893,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=894,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=895,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT diffraction_detector_1_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=897,material_string="Exit")
  AT (0,0,0) RELATIVE channel_1_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT spec_detector_1_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=898,material_string="Exit")
  AT (0,0,0) RELATIVE channel_1_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_1_analyzer_2_center

COMPONENT channel_2_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1532,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1537,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1534,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1535,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2


COMPONENT channel_2_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_2

COMPONENT channel_2_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[2]*DEG2RAD)) RELATIVE channel_2_analyzer_1_center
  ROTATED (0,180-analyzer_theta[2],0) RELATIVE channel_2_analyzer_1_center

COMPONENT channel_2_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 1552.0, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[0])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[0]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[0]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 1552.1, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[1])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[1]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[1]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 1552.2, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[2])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[2]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[2]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 1552.3, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[3])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[3]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[3]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 1552.4, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[4])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[4]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[4]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 1552.5, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[5])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[5]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[5]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 1552.6, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[6])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[6]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[6]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 1552.7, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[7])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[7]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[7]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 1552.8, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[8])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[8]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[8]) RELATIVE channel_2_analyzer_1_rotated


COMPONENT channel_2_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_2_analyzer_1_center

COMPONENT channel_2_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[2]*DEG2RAD)) RELATIVE channel_2_analyzer_2_center
  ROTATED (0,-analyzer_theta[2],0) RELATIVE channel_2_analyzer_2_center

COMPONENT channel_2_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 1553.0, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[0])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[0]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[0]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 1553.1, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[1])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[1]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[1]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 1553.2, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[2])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[2]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[2]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 1553.3, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[3])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[3]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[3]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 1553.4, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[4])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[4]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[4]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 1553.5, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[5])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[5]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[5]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 1553.6, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[6])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[6]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[6]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 1553.7, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[7])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[7]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[7]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 1553.8, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[8])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[8]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[8]) RELATIVE channel_2_analyzer_2_rotated


COMPONENT channel_2_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1539.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_2_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_2_analyzer_2_center

COMPONENT channel_2_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1533,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_2_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_2_cave2_cyl1

COMPONENT channel_2_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1538,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_2_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_2_cave2_cyl1

COMPONENT channel_2_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1539,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_2_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_2_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_2 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_2_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_2_analyzer_1_center

COMPONENT inter_analyzer_colimator_2_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1557,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1558,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1559,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1560,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1561,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT diffraction_detector_2_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1563,material_string="Exit")
  AT (0,0,0) RELATIVE channel_2_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT spec_detector_2_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1564,material_string="Exit")
  AT (0,0,0) RELATIVE channel_2_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_2_analyzer_2_center

COMPONENT kidney_union_master = Union_master(inherit_number_of_scattering_events=1)
AT (0,0,0) RELATIVE target

COMPONENT diffraction_detector_0 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_0")
  AT (0,0,0) RELATIVE diffraction_detector_0_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_0_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =0;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_0 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_0")
  AT (0,0,0) RELATIVE spec_detector_0_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_0_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =0;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_1 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_1")
  AT (0,0,0) RELATIVE diffraction_detector_1_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_1_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =1;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_1 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_1")
  AT (0,0,0) RELATIVE spec_detector_1_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_1_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =1;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_2 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_2")
  AT (0,0,0) RELATIVE diffraction_detector_2_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_2_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =2;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_2 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_2")
  AT (0,0,0) RELATIVE spec_detector_2_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_2_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =2;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_history_0 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_0")
  WHEN(detector_channel_spec == 0 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_0_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_0_exit_volume
  EXTEND %{
    if (SCATTERED) {
      flag_sum=0;
      for (flag_index=1;flag_index<MAX_VOLUME_HISTORY_LENGTH;flag_index++) {
        if (scattering_history_sample_master[flag_index] > 0) {
          C_N[flag_index+1]++;
          C_p[flag_index+1] += p;
          C_p2[flag_index+1] += p*p;
          flag_sum++;
          flag_single = flag_index;
        };
      };
      if (flag_sum == 0) {
        C_N[1]++;
        C_p[1] += p;
        C_p2[1] += p*p;
      };
      if (flag_sum == 1) {
        if (scattering_history_sample_master[flag_single] == 1) {
          C_N[MAX_VOLUME_HISTORY_LENGTH+flag_single+1]++;
          C_p[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p;
          C_p2[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p*p;
        };
      };
    };
  %}

COMPONENT spec_detector_history_1 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_1")
  WHEN(detector_channel_spec == 1 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_1_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_1_exit_volume
  EXTEND %{
    if (SCATTERED) {
      flag_sum=0;
      for (flag_index=1;flag_index<MAX_VOLUME_HISTORY_LENGTH;flag_index++) {
        if (scattering_history_sample_master[flag_index] > 0) {
          C_N[flag_index+1]++;
          C_p[flag_index+1] += p;
          C_p2[flag_index+1] += p*p;
          flag_sum++;
          flag_single = flag_index;
        };
      };
      if (flag_sum == 0) {
        C_N[1]++;
        C_p[1] += p;
        C_p2[1] += p*p;
      };
      if (flag_sum == 1) {
        if (scattering_history_sample_master[flag_single] == 1) {
          C_N[MAX_VOLUME_HISTORY_LENGTH+flag_single+1]++;
          C_p[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p;
          C_p2[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p*p;
        };
      };
    };
  %}

COMPONENT spec_detector_history_2 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_2")
  WHEN(detector_channel_spec == 2 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_2_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_2_exit_volume
  EXTEND %{
    if (SCATTERED) {
      flag_sum=0;
      for (flag_index=1;flag_index<MAX_VOLUME_HISTORY_LENGTH;flag_index++) {
        if (scattering_history_sample_master[flag_index] > 0) {
          C_N[flag_index+1]++;
          C_p[flag_index+1] += p;
          C_p2[flag_index+1] += p*p;
          flag_sum++;
          flag_single = flag_index;
        };
      };
      if (flag_sum == 0) {
        C_N[1]++;
        C_p[1] += p;
        C_p2[1] += p*p;
      };
      if (flag_sum == 1) {
        if (scattering_history_sample_master[flag_single] == 1) {
          C_N[MAX_VOLUME_HISTORY_LENGTH+flag_single+1]++;
          C_p[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p;
          C_p2[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p*p;
        };
      };
    };
  %}

