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
  ROTATED (0,-76,0) RELATIVE kidney_master

COMPONENT kidney_channel_1 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-68,0) RELATIVE kidney_master

COMPONENT kidney_channel_2 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-60,0) RELATIVE kidney_master

COMPONENT kidney_channel_3 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-52,0) RELATIVE kidney_master

COMPONENT kidney_channel_4 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-44,0) RELATIVE kidney_master

COMPONENT kidney_channel_5 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-36,0) RELATIVE kidney_master

COMPONENT kidney_channel_6 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-28,0) RELATIVE kidney_master

COMPONENT kidney_channel_7 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-20,0) RELATIVE kidney_master

COMPONENT kidney_channel_8 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-12,0) RELATIVE kidney_master

COMPONENT kidney_channel_9 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,-4,0) RELATIVE kidney_master

COMPONENT kidney_channel_10 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,4,0) RELATIVE kidney_master

COMPONENT kidney_channel_11 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,12,0) RELATIVE kidney_master

COMPONENT kidney_channel_12 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,20,0) RELATIVE kidney_master

COMPONENT kidney_channel_13 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,28,0) RELATIVE kidney_master

COMPONENT kidney_channel_14 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,36,0) RELATIVE kidney_master

COMPONENT kidney_channel_15 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,44,0) RELATIVE kidney_master

COMPONENT kidney_channel_16 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,52,0) RELATIVE kidney_master

COMPONENT kidney_channel_17 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,60,0) RELATIVE kidney_master

COMPONENT kidney_channel_18 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,68,0) RELATIVE kidney_master

COMPONENT kidney_channel_19 = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,76,0) RELATIVE kidney_master

// Filters that also check for scattering to select the correct channel
COMPONENT channel_0_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_0
  ROTATED (0,0,0) RELATIVE kidney_channel_0
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) {
        channel_selected = 0;
    }
  %}

COMPONENT channel_1_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 1;
  %}

COMPONENT channel_2_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 2;
  %}

COMPONENT channel_3_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_3
  ROTATED (0,0,0) RELATIVE kidney_channel_3
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 3;
  %}

COMPONENT channel_4_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_4
  ROTATED (0,0,0) RELATIVE kidney_channel_4
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 4;
  %}

COMPONENT channel_5_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_5
  ROTATED (0,0,0) RELATIVE kidney_channel_5
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 5;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_6_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_6
  ROTATED (0,0,0) RELATIVE kidney_channel_6
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 6;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_7_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_7
  ROTATED (0,0,0) RELATIVE kidney_channel_7
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 7;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_8_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_8
  ROTATED (0,0,0) RELATIVE kidney_channel_8
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 8;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_9_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_9
  ROTATED (0,0,0) RELATIVE kidney_channel_9
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 9;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_10_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_10
  ROTATED (0,0,0) RELATIVE kidney_channel_10
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 10;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_11_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_11
  ROTATED (0,0,0) RELATIVE kidney_channel_11
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 11;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_12_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_12
  ROTATED (0,0,0) RELATIVE kidney_channel_12
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 12;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_13_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_13
  ROTATED (0,0,0) RELATIVE kidney_channel_13
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 13;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_14_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_14
  ROTATED (0,0,0) RELATIVE kidney_channel_14
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 14;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_15_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_15
  ROTATED (0,0,0) RELATIVE kidney_channel_15
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 15;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_16_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_16
  ROTATED (0,0,0) RELATIVE kidney_channel_16
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 16;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_17_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_17
  ROTATED (0,0,0) RELATIVE kidney_channel_17
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 17;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_18_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_18
  ROTATED (0,0,0) RELATIVE kidney_channel_18
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 18;
    //printf("channel_selected = %d\n",channel_selected);
  %}

COMPONENT channel_19_filter = Slit_MACS(xwidth=filter_width, yheight=filter_height)
  AT (0,0,target_filter_dist) RELATIVE kidney_channel_19
  ROTATED (0,0,0) RELATIVE kidney_channel_19
  GROUP filter_group
  EXTEND %{
    if (SCATTERED) channel_selected = 19;
    //printf("channel_selected = %d\n",channel_selected);
  %}

// dummy arm that absorbs rays that did not hit any filter
COMPONENT channel_selector = Arm()
  AT (0,0,0) RELATIVE kidney_master
  ROTATED (0,0,0) RELATIVE kidney_master
  EXTEND %{
    //printf("channel_selected after slits: %d\n", channel_selected);
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

COMPONENT channel_3_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 3)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_3
  ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT channel_4_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 4)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_4
  ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT channel_5_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 5)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_5
  ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT channel_6_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 6)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_6
  ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT channel_7_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 7)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_7
  ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT channel_8_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 8)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_8
  ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT channel_9_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 9)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_9
  ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT channel_10_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 10)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_10
  ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT channel_11_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 11)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_11
  ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT channel_12_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 12)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_12
  ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT channel_13_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 13)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_13
  ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT channel_14_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 14)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_14
  ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT channel_15_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 15)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_15
  ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT channel_16_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 16)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_16
  ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT channel_17_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 17)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_17
  ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT channel_18_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 18)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_18
  ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT channel_19_colimator = Collimator_linear(xwidth=channel_colimator_width, yheight=channel_colimator_height,
      length=channel_colimator_length, divergence = channel_colimator_divergence_arcmin,transmission=channel_colimator_transmission)
  WHEN (channel_selected == 19)
  AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_19
  ROTATED (0,0,0) RELATIVE kidney_channel_19



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
    priority=300,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=305,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=302,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=303,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_1
  ROTATED (0,0,0) RELATIVE kidney_channel_1


COMPONENT channel_1_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_1

COMPONENT channel_1_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[1]*DEG2RAD)) RELATIVE channel_1_analyzer_1_center
  ROTATED (0,180-analyzer_theta[1],0) RELATIVE channel_1_analyzer_1_center

COMPONENT channel_1_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 320.0, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[0])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[0]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[0]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 320.1, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[1])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[1]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[1]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 320.2, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[2])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[2]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[2]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 320.3, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[3])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[3]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[3]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 320.4, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[4])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[4]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[4]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 320.5, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[5])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[5]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[5]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 320.6, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[6])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[6]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[6]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 320.7, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[7])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[7]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[7]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_1_analyzer_1_array_crystal_width, yheight = channel_1_analyzer_1_array_crystal_height, xwidth = channel_1_analyzer_1_array_crystal_depth,
   priority = 320.8, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[8])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[8]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[8]) RELATIVE channel_1_analyzer_1_rotated


COMPONENT channel_1_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_1_analyzer_1_center

COMPONENT channel_1_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[1]*DEG2RAD)) RELATIVE channel_1_analyzer_2_center
  ROTATED (0,-analyzer_theta[1],0) RELATIVE channel_1_analyzer_2_center

COMPONENT channel_1_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 321.0, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[0])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[0]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[0]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 321.1, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[1])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[1]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[1]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 321.2, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[2])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[2]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[2]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 321.3, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[3])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[3]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[3]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 321.4, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[4])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[4]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[4]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 321.5, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[5])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[5]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[5]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 321.6, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[6])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[6]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[6]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 321.7, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[7])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[7]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[7]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_1_analyzer_2_array_crystal_width, yheight = channel_1_analyzer_2_array_crystal_height, xwidth = channel_1_analyzer_2_array_crystal_depth,
   priority = 321.8, material_string = "PG_analyzer")
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[8])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[8]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[8]) RELATIVE channel_1_analyzer_2_rotated


COMPONENT channel_1_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=307.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_1_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_1_analyzer_2_center

COMPONENT channel_1_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=301,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_1_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_1_cave2_cyl1

COMPONENT channel_1_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=306,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_1_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_1_cave2_cyl1

COMPONENT channel_1_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=307,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_1_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_1_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_1 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_1_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_1_analyzer_1_center

COMPONENT inter_analyzer_colimator_1_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=325,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=326,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=327,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=328,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=329,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
  ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT diffraction_detector_1_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=331,material_string="Exit")
  AT (0,0,0) RELATIVE channel_1_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT spec_detector_1_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=332,material_string="Exit")
  AT (0,0,0) RELATIVE channel_1_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_1_analyzer_2_center

COMPONENT channel_2_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=400,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=405,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=402,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=403,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_2
  ROTATED (0,0,0) RELATIVE kidney_channel_2


COMPONENT channel_2_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_2

COMPONENT channel_2_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[2]*DEG2RAD)) RELATIVE channel_2_analyzer_1_center
  ROTATED (0,180-analyzer_theta[2],0) RELATIVE channel_2_analyzer_1_center

COMPONENT channel_2_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 420.0, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[0])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[0]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[0]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 420.1, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[1])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[1]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[1]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 420.2, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[2])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[2]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[2]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 420.3, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[3])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[3]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[3]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 420.4, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[4])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[4]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[4]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 420.5, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[5])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[5]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[5]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 420.6, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[6])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[6]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[6]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 420.7, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[7])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[7]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[7]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_2_analyzer_1_array_crystal_width, yheight = channel_2_analyzer_1_array_crystal_height, xwidth = channel_2_analyzer_1_array_crystal_depth,
   priority = 420.8, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[8])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[8]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[8]) RELATIVE channel_2_analyzer_1_rotated


COMPONENT channel_2_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_2_analyzer_1_center

COMPONENT channel_2_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[2]*DEG2RAD)) RELATIVE channel_2_analyzer_2_center
  ROTATED (0,-analyzer_theta[2],0) RELATIVE channel_2_analyzer_2_center

COMPONENT channel_2_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 421.0, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[0])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[0]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[0]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 421.1, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[1])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[1]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[1]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 421.2, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[2])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[2]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[2]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 421.3, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[3])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[3]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[3]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 421.4, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[4])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[4]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[4]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 421.5, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[5])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[5]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[5]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 421.6, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[6])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[6]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[6]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 421.7, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[7])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[7]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[7]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_2_analyzer_2_array_crystal_width, yheight = channel_2_analyzer_2_array_crystal_height, xwidth = channel_2_analyzer_2_array_crystal_depth,
   priority = 421.8, material_string = "PG_analyzer")
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[8])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[8]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[8]) RELATIVE channel_2_analyzer_2_rotated


COMPONENT channel_2_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=407.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_2_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_2_analyzer_2_center

COMPONENT channel_2_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=401,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_2_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_2_cave2_cyl1

COMPONENT channel_2_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=406,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_2_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_2_cave2_cyl1

COMPONENT channel_2_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=407,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_2_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_2_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_2 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_2_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_2_analyzer_1_center

COMPONENT inter_analyzer_colimator_2_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=425,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=426,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=427,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=428,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=429,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
  ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT diffraction_detector_2_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=431,material_string="Exit")
  AT (0,0,0) RELATIVE channel_2_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT spec_detector_2_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=432,material_string="Exit")
  AT (0,0,0) RELATIVE channel_2_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_2_analyzer_2_center

COMPONENT channel_3_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=500,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_3
  ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT channel_3_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=505,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_3
  ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT channel_3_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=502,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_3
  ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT channel_3_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=503,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_3
  ROTATED (0,0,0) RELATIVE kidney_channel_3


COMPONENT channel_3_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_3

COMPONENT channel_3_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[3]*DEG2RAD)) RELATIVE channel_3_analyzer_1_center
  ROTATED (0,180-analyzer_theta[3],0) RELATIVE channel_3_analyzer_1_center

COMPONENT channel_3_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_3_analyzer_1_array_crystal_width, yheight = channel_3_analyzer_1_array_crystal_height, xwidth = channel_3_analyzer_1_array_crystal_depth,
   priority = 520.0, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[0])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[0]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[0]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_3_analyzer_1_array_crystal_width, yheight = channel_3_analyzer_1_array_crystal_height, xwidth = channel_3_analyzer_1_array_crystal_depth,
   priority = 520.1, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[1])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[1]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[1]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_3_analyzer_1_array_crystal_width, yheight = channel_3_analyzer_1_array_crystal_height, xwidth = channel_3_analyzer_1_array_crystal_depth,
   priority = 520.2, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[2])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[2]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[2]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_3_analyzer_1_array_crystal_width, yheight = channel_3_analyzer_1_array_crystal_height, xwidth = channel_3_analyzer_1_array_crystal_depth,
   priority = 520.3, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[3])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[3]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[3]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_3_analyzer_1_array_crystal_width, yheight = channel_3_analyzer_1_array_crystal_height, xwidth = channel_3_analyzer_1_array_crystal_depth,
   priority = 520.4, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[4])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[4]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[4]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_3_analyzer_1_array_crystal_width, yheight = channel_3_analyzer_1_array_crystal_height, xwidth = channel_3_analyzer_1_array_crystal_depth,
   priority = 520.5, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[5])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[5]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[5]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_3_analyzer_1_array_crystal_width, yheight = channel_3_analyzer_1_array_crystal_height, xwidth = channel_3_analyzer_1_array_crystal_depth,
   priority = 520.6, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[6])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[6]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[6]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_3_analyzer_1_array_crystal_width, yheight = channel_3_analyzer_1_array_crystal_height, xwidth = channel_3_analyzer_1_array_crystal_depth,
   priority = 520.7, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[7])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[7]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[7]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_3_analyzer_1_array_crystal_width, yheight = channel_3_analyzer_1_array_crystal_height, xwidth = channel_3_analyzer_1_array_crystal_depth,
   priority = 520.8, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[8])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[8]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[8]) RELATIVE channel_3_analyzer_1_rotated


COMPONENT channel_3_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_3_analyzer_1_center

COMPONENT channel_3_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[3]*DEG2RAD)) RELATIVE channel_3_analyzer_2_center
  ROTATED (0,-analyzer_theta[3],0) RELATIVE channel_3_analyzer_2_center

COMPONENT channel_3_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_3_analyzer_2_array_crystal_width, yheight = channel_3_analyzer_2_array_crystal_height, xwidth = channel_3_analyzer_2_array_crystal_depth,
   priority = 521.0, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[0])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[0]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[0]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_3_analyzer_2_array_crystal_width, yheight = channel_3_analyzer_2_array_crystal_height, xwidth = channel_3_analyzer_2_array_crystal_depth,
   priority = 521.1, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[1])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[1]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[1]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_3_analyzer_2_array_crystal_width, yheight = channel_3_analyzer_2_array_crystal_height, xwidth = channel_3_analyzer_2_array_crystal_depth,
   priority = 521.2, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[2])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[2]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[2]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_3_analyzer_2_array_crystal_width, yheight = channel_3_analyzer_2_array_crystal_height, xwidth = channel_3_analyzer_2_array_crystal_depth,
   priority = 521.3, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[3])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[3]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[3]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_3_analyzer_2_array_crystal_width, yheight = channel_3_analyzer_2_array_crystal_height, xwidth = channel_3_analyzer_2_array_crystal_depth,
   priority = 521.4, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[4])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[4]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[4]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_3_analyzer_2_array_crystal_width, yheight = channel_3_analyzer_2_array_crystal_height, xwidth = channel_3_analyzer_2_array_crystal_depth,
   priority = 521.5, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[5])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[5]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[5]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_3_analyzer_2_array_crystal_width, yheight = channel_3_analyzer_2_array_crystal_height, xwidth = channel_3_analyzer_2_array_crystal_depth,
   priority = 521.6, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[6])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[6]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[6]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_3_analyzer_2_array_crystal_width, yheight = channel_3_analyzer_2_array_crystal_height, xwidth = channel_3_analyzer_2_array_crystal_depth,
   priority = 521.7, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[7])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[7]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[7]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_3_analyzer_2_array_crystal_width, yheight = channel_3_analyzer_2_array_crystal_height, xwidth = channel_3_analyzer_2_array_crystal_depth,
   priority = 521.8, material_string = "PG_analyzer")
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[8])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[8]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[8]) RELATIVE channel_3_analyzer_2_rotated


COMPONENT channel_3_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=507.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_3_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_3_analyzer_2_center

COMPONENT channel_3_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=501,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_3_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_3_cave2_cyl1

COMPONENT channel_3_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=506,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_3_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_3_cave2_cyl1

COMPONENT channel_3_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=507,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_3_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_3_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_3 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_3_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_3_analyzer_1_center

COMPONENT inter_analyzer_colimator_3_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=525,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
  ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT inter_analyzer_colimator_3_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=526,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
  ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT inter_analyzer_colimator_3_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=527,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
  ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT inter_analyzer_colimator_3_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=528,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
  ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT inter_analyzer_colimator_3_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=529,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
  ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT diffraction_detector_3_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=531,material_string="Exit")
  AT (0,0,0) RELATIVE channel_3_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT spec_detector_3_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=532,material_string="Exit")
  AT (0,0,0) RELATIVE channel_3_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_3_analyzer_2_center

COMPONENT channel_4_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=600,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_4
  ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT channel_4_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=605,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_4
  ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT channel_4_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=602,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_4
  ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT channel_4_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=603,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_4
  ROTATED (0,0,0) RELATIVE kidney_channel_4


COMPONENT channel_4_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_4

COMPONENT channel_4_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[4]*DEG2RAD)) RELATIVE channel_4_analyzer_1_center
  ROTATED (0,180-analyzer_theta[4],0) RELATIVE channel_4_analyzer_1_center

COMPONENT channel_4_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_4_analyzer_1_array_crystal_width, yheight = channel_4_analyzer_1_array_crystal_height, xwidth = channel_4_analyzer_1_array_crystal_depth,
   priority = 620.0, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[0])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[0]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[0]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_4_analyzer_1_array_crystal_width, yheight = channel_4_analyzer_1_array_crystal_height, xwidth = channel_4_analyzer_1_array_crystal_depth,
   priority = 620.1, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[1])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[1]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[1]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_4_analyzer_1_array_crystal_width, yheight = channel_4_analyzer_1_array_crystal_height, xwidth = channel_4_analyzer_1_array_crystal_depth,
   priority = 620.2, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[2])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[2]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[2]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_4_analyzer_1_array_crystal_width, yheight = channel_4_analyzer_1_array_crystal_height, xwidth = channel_4_analyzer_1_array_crystal_depth,
   priority = 620.3, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[3])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[3]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[3]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_4_analyzer_1_array_crystal_width, yheight = channel_4_analyzer_1_array_crystal_height, xwidth = channel_4_analyzer_1_array_crystal_depth,
   priority = 620.4, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[4])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[4]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[4]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_4_analyzer_1_array_crystal_width, yheight = channel_4_analyzer_1_array_crystal_height, xwidth = channel_4_analyzer_1_array_crystal_depth,
   priority = 620.5, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[5])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[5]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[5]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_4_analyzer_1_array_crystal_width, yheight = channel_4_analyzer_1_array_crystal_height, xwidth = channel_4_analyzer_1_array_crystal_depth,
   priority = 620.6, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[6])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[6]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[6]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_4_analyzer_1_array_crystal_width, yheight = channel_4_analyzer_1_array_crystal_height, xwidth = channel_4_analyzer_1_array_crystal_depth,
   priority = 620.7, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[7])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[7]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[7]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_4_analyzer_1_array_crystal_width, yheight = channel_4_analyzer_1_array_crystal_height, xwidth = channel_4_analyzer_1_array_crystal_depth,
   priority = 620.8, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[8])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[8]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[8]) RELATIVE channel_4_analyzer_1_rotated


COMPONENT channel_4_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_4_analyzer_1_center

COMPONENT channel_4_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[4]*DEG2RAD)) RELATIVE channel_4_analyzer_2_center
  ROTATED (0,-analyzer_theta[4],0) RELATIVE channel_4_analyzer_2_center

COMPONENT channel_4_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_4_analyzer_2_array_crystal_width, yheight = channel_4_analyzer_2_array_crystal_height, xwidth = channel_4_analyzer_2_array_crystal_depth,
   priority = 621.0, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[0])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[0]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[0]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_4_analyzer_2_array_crystal_width, yheight = channel_4_analyzer_2_array_crystal_height, xwidth = channel_4_analyzer_2_array_crystal_depth,
   priority = 621.1, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[1])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[1]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[1]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_4_analyzer_2_array_crystal_width, yheight = channel_4_analyzer_2_array_crystal_height, xwidth = channel_4_analyzer_2_array_crystal_depth,
   priority = 621.2, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[2])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[2]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[2]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_4_analyzer_2_array_crystal_width, yheight = channel_4_analyzer_2_array_crystal_height, xwidth = channel_4_analyzer_2_array_crystal_depth,
   priority = 621.3, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[3])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[3]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[3]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_4_analyzer_2_array_crystal_width, yheight = channel_4_analyzer_2_array_crystal_height, xwidth = channel_4_analyzer_2_array_crystal_depth,
   priority = 621.4, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[4])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[4]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[4]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_4_analyzer_2_array_crystal_width, yheight = channel_4_analyzer_2_array_crystal_height, xwidth = channel_4_analyzer_2_array_crystal_depth,
   priority = 621.5, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[5])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[5]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[5]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_4_analyzer_2_array_crystal_width, yheight = channel_4_analyzer_2_array_crystal_height, xwidth = channel_4_analyzer_2_array_crystal_depth,
   priority = 621.6, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[6])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[6]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[6]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_4_analyzer_2_array_crystal_width, yheight = channel_4_analyzer_2_array_crystal_height, xwidth = channel_4_analyzer_2_array_crystal_depth,
   priority = 621.7, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[7])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[7]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[7]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_4_analyzer_2_array_crystal_width, yheight = channel_4_analyzer_2_array_crystal_height, xwidth = channel_4_analyzer_2_array_crystal_depth,
   priority = 621.8, material_string = "PG_analyzer")
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[8])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[8]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[8]) RELATIVE channel_4_analyzer_2_rotated


COMPONENT channel_4_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=607.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_4_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_4_analyzer_2_center

COMPONENT channel_4_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=601,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_4_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_4_cave2_cyl1

COMPONENT channel_4_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=606,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_4_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_4_cave2_cyl1

COMPONENT channel_4_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=607,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_4_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_4_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_4 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_4_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_4_analyzer_1_center

COMPONENT inter_analyzer_colimator_4_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=625,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
  ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT inter_analyzer_colimator_4_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=626,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
  ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT inter_analyzer_colimator_4_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=627,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
  ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT inter_analyzer_colimator_4_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=628,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
  ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT inter_analyzer_colimator_4_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=629,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
  ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT diffraction_detector_4_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=631,material_string="Exit")
  AT (0,0,0) RELATIVE channel_4_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT spec_detector_4_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=632,material_string="Exit")
  AT (0,0,0) RELATIVE channel_4_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_4_analyzer_2_center

COMPONENT channel_5_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=700,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_5
  ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT channel_5_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=705,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_5
  ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT channel_5_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=702,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_5
  ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT channel_5_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=703,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_5
  ROTATED (0,0,0) RELATIVE kidney_channel_5


COMPONENT channel_5_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_5

COMPONENT channel_5_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[5]*DEG2RAD)) RELATIVE channel_5_analyzer_1_center
  ROTATED (0,180-analyzer_theta[5],0) RELATIVE channel_5_analyzer_1_center

COMPONENT channel_5_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_5_analyzer_1_array_crystal_width, yheight = channel_5_analyzer_1_array_crystal_height, xwidth = channel_5_analyzer_1_array_crystal_depth,
   priority = 720.0, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[0])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[0]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[0]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_5_analyzer_1_array_crystal_width, yheight = channel_5_analyzer_1_array_crystal_height, xwidth = channel_5_analyzer_1_array_crystal_depth,
   priority = 720.1, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[1])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[1]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[1]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_5_analyzer_1_array_crystal_width, yheight = channel_5_analyzer_1_array_crystal_height, xwidth = channel_5_analyzer_1_array_crystal_depth,
   priority = 720.2, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[2])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[2]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[2]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_5_analyzer_1_array_crystal_width, yheight = channel_5_analyzer_1_array_crystal_height, xwidth = channel_5_analyzer_1_array_crystal_depth,
   priority = 720.3, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[3])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[3]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[3]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_5_analyzer_1_array_crystal_width, yheight = channel_5_analyzer_1_array_crystal_height, xwidth = channel_5_analyzer_1_array_crystal_depth,
   priority = 720.4, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[4])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[4]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[4]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_5_analyzer_1_array_crystal_width, yheight = channel_5_analyzer_1_array_crystal_height, xwidth = channel_5_analyzer_1_array_crystal_depth,
   priority = 720.5, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[5])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[5]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[5]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_5_analyzer_1_array_crystal_width, yheight = channel_5_analyzer_1_array_crystal_height, xwidth = channel_5_analyzer_1_array_crystal_depth,
   priority = 720.6, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[6])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[6]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[6]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_5_analyzer_1_array_crystal_width, yheight = channel_5_analyzer_1_array_crystal_height, xwidth = channel_5_analyzer_1_array_crystal_depth,
   priority = 720.7, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[7])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[7]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[7]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_5_analyzer_1_array_crystal_width, yheight = channel_5_analyzer_1_array_crystal_height, xwidth = channel_5_analyzer_1_array_crystal_depth,
   priority = 720.8, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[8])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[8]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[8]) RELATIVE channel_5_analyzer_1_rotated


COMPONENT channel_5_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_5_analyzer_1_center

COMPONENT channel_5_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[5]*DEG2RAD)) RELATIVE channel_5_analyzer_2_center
  ROTATED (0,-analyzer_theta[5],0) RELATIVE channel_5_analyzer_2_center

COMPONENT channel_5_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_5_analyzer_2_array_crystal_width, yheight = channel_5_analyzer_2_array_crystal_height, xwidth = channel_5_analyzer_2_array_crystal_depth,
   priority = 721.0, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[0])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[0]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[0]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_5_analyzer_2_array_crystal_width, yheight = channel_5_analyzer_2_array_crystal_height, xwidth = channel_5_analyzer_2_array_crystal_depth,
   priority = 721.1, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[1])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[1]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[1]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_5_analyzer_2_array_crystal_width, yheight = channel_5_analyzer_2_array_crystal_height, xwidth = channel_5_analyzer_2_array_crystal_depth,
   priority = 721.2, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[2])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[2]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[2]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_5_analyzer_2_array_crystal_width, yheight = channel_5_analyzer_2_array_crystal_height, xwidth = channel_5_analyzer_2_array_crystal_depth,
   priority = 721.3, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[3])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[3]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[3]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_5_analyzer_2_array_crystal_width, yheight = channel_5_analyzer_2_array_crystal_height, xwidth = channel_5_analyzer_2_array_crystal_depth,
   priority = 721.4, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[4])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[4]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[4]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_5_analyzer_2_array_crystal_width, yheight = channel_5_analyzer_2_array_crystal_height, xwidth = channel_5_analyzer_2_array_crystal_depth,
   priority = 721.5, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[5])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[5]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[5]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_5_analyzer_2_array_crystal_width, yheight = channel_5_analyzer_2_array_crystal_height, xwidth = channel_5_analyzer_2_array_crystal_depth,
   priority = 721.6, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[6])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[6]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[6]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_5_analyzer_2_array_crystal_width, yheight = channel_5_analyzer_2_array_crystal_height, xwidth = channel_5_analyzer_2_array_crystal_depth,
   priority = 721.7, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[7])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[7]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[7]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_5_analyzer_2_array_crystal_width, yheight = channel_5_analyzer_2_array_crystal_height, xwidth = channel_5_analyzer_2_array_crystal_depth,
   priority = 721.8, material_string = "PG_analyzer")
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[8])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[8]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[8]) RELATIVE channel_5_analyzer_2_rotated


COMPONENT channel_5_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=707.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_5_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_5_analyzer_2_center

COMPONENT channel_5_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=701,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_5_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_5_cave2_cyl1

COMPONENT channel_5_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=706,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_5_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_5_cave2_cyl1

COMPONENT channel_5_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=707,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_5_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_5_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_5 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_5_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_5_analyzer_1_center

COMPONENT inter_analyzer_colimator_5_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=725,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
  ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT inter_analyzer_colimator_5_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=726,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
  ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT inter_analyzer_colimator_5_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=727,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
  ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT inter_analyzer_colimator_5_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=728,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
  ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT inter_analyzer_colimator_5_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=729,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
  ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT diffraction_detector_5_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=731,material_string="Exit")
  AT (0,0,0) RELATIVE channel_5_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT spec_detector_5_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=732,material_string="Exit")
  AT (0,0,0) RELATIVE channel_5_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_5_analyzer_2_center

COMPONENT channel_6_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=800,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_6
  ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT channel_6_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=805,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_6
  ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT channel_6_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=802,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_6
  ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT channel_6_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=803,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_6
  ROTATED (0,0,0) RELATIVE kidney_channel_6


COMPONENT channel_6_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_6

COMPONENT channel_6_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[6]*DEG2RAD)) RELATIVE channel_6_analyzer_1_center
  ROTATED (0,180-analyzer_theta[6],0) RELATIVE channel_6_analyzer_1_center

COMPONENT channel_6_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_6_analyzer_1_array_crystal_width, yheight = channel_6_analyzer_1_array_crystal_height, xwidth = channel_6_analyzer_1_array_crystal_depth,
   priority = 820.0, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[0])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[0]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[0]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_6_analyzer_1_array_crystal_width, yheight = channel_6_analyzer_1_array_crystal_height, xwidth = channel_6_analyzer_1_array_crystal_depth,
   priority = 820.1, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[1])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[1]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[1]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_6_analyzer_1_array_crystal_width, yheight = channel_6_analyzer_1_array_crystal_height, xwidth = channel_6_analyzer_1_array_crystal_depth,
   priority = 820.2, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[2])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[2]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[2]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_6_analyzer_1_array_crystal_width, yheight = channel_6_analyzer_1_array_crystal_height, xwidth = channel_6_analyzer_1_array_crystal_depth,
   priority = 820.3, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[3])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[3]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[3]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_6_analyzer_1_array_crystal_width, yheight = channel_6_analyzer_1_array_crystal_height, xwidth = channel_6_analyzer_1_array_crystal_depth,
   priority = 820.4, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[4])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[4]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[4]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_6_analyzer_1_array_crystal_width, yheight = channel_6_analyzer_1_array_crystal_height, xwidth = channel_6_analyzer_1_array_crystal_depth,
   priority = 820.5, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[5])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[5]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[5]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_6_analyzer_1_array_crystal_width, yheight = channel_6_analyzer_1_array_crystal_height, xwidth = channel_6_analyzer_1_array_crystal_depth,
   priority = 820.6, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[6])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[6]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[6]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_6_analyzer_1_array_crystal_width, yheight = channel_6_analyzer_1_array_crystal_height, xwidth = channel_6_analyzer_1_array_crystal_depth,
   priority = 820.7, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[7])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[7]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[7]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_6_analyzer_1_array_crystal_width, yheight = channel_6_analyzer_1_array_crystal_height, xwidth = channel_6_analyzer_1_array_crystal_depth,
   priority = 820.8, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[8])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[8]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[8]) RELATIVE channel_6_analyzer_1_rotated


COMPONENT channel_6_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_6_analyzer_1_center

COMPONENT channel_6_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[6]*DEG2RAD)) RELATIVE channel_6_analyzer_2_center
  ROTATED (0,-analyzer_theta[6],0) RELATIVE channel_6_analyzer_2_center

COMPONENT channel_6_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_6_analyzer_2_array_crystal_width, yheight = channel_6_analyzer_2_array_crystal_height, xwidth = channel_6_analyzer_2_array_crystal_depth,
   priority = 821.0, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[0])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[0]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[0]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_6_analyzer_2_array_crystal_width, yheight = channel_6_analyzer_2_array_crystal_height, xwidth = channel_6_analyzer_2_array_crystal_depth,
   priority = 821.1, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[1])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[1]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[1]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_6_analyzer_2_array_crystal_width, yheight = channel_6_analyzer_2_array_crystal_height, xwidth = channel_6_analyzer_2_array_crystal_depth,
   priority = 821.2, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[2])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[2]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[2]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_6_analyzer_2_array_crystal_width, yheight = channel_6_analyzer_2_array_crystal_height, xwidth = channel_6_analyzer_2_array_crystal_depth,
   priority = 821.3, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[3])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[3]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[3]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_6_analyzer_2_array_crystal_width, yheight = channel_6_analyzer_2_array_crystal_height, xwidth = channel_6_analyzer_2_array_crystal_depth,
   priority = 821.4, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[4])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[4]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[4]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_6_analyzer_2_array_crystal_width, yheight = channel_6_analyzer_2_array_crystal_height, xwidth = channel_6_analyzer_2_array_crystal_depth,
   priority = 821.5, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[5])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[5]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[5]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_6_analyzer_2_array_crystal_width, yheight = channel_6_analyzer_2_array_crystal_height, xwidth = channel_6_analyzer_2_array_crystal_depth,
   priority = 821.6, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[6])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[6]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[6]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_6_analyzer_2_array_crystal_width, yheight = channel_6_analyzer_2_array_crystal_height, xwidth = channel_6_analyzer_2_array_crystal_depth,
   priority = 821.7, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[7])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[7]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[7]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_6_analyzer_2_array_crystal_width, yheight = channel_6_analyzer_2_array_crystal_height, xwidth = channel_6_analyzer_2_array_crystal_depth,
   priority = 821.8, material_string = "PG_analyzer")
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[8])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[8]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[8]) RELATIVE channel_6_analyzer_2_rotated


COMPONENT channel_6_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=807.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_6_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_6_analyzer_2_center

COMPONENT channel_6_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=801,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_6_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_6_cave2_cyl1

COMPONENT channel_6_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=806,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_6_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_6_cave2_cyl1

COMPONENT channel_6_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=807,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_6_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_6_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_6 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_6_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_6_analyzer_1_center

COMPONENT inter_analyzer_colimator_6_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=825,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
  ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT inter_analyzer_colimator_6_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=826,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
  ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT inter_analyzer_colimator_6_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=827,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
  ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT inter_analyzer_colimator_6_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=828,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
  ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT inter_analyzer_colimator_6_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=829,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
  ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT diffraction_detector_6_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=831,material_string="Exit")
  AT (0,0,0) RELATIVE channel_6_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT spec_detector_6_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=832,material_string="Exit")
  AT (0,0,0) RELATIVE channel_6_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_6_analyzer_2_center

COMPONENT channel_7_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=900,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_7
  ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT channel_7_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=905,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_7
  ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT channel_7_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=902,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_7
  ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT channel_7_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=903,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_7
  ROTATED (0,0,0) RELATIVE kidney_channel_7


COMPONENT channel_7_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_7

COMPONENT channel_7_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[7]*DEG2RAD)) RELATIVE channel_7_analyzer_1_center
  ROTATED (0,180-analyzer_theta[7],0) RELATIVE channel_7_analyzer_1_center

COMPONENT channel_7_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_7_analyzer_1_array_crystal_width, yheight = channel_7_analyzer_1_array_crystal_height, xwidth = channel_7_analyzer_1_array_crystal_depth,
   priority = 920.0, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[0])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[0]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[0]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_7_analyzer_1_array_crystal_width, yheight = channel_7_analyzer_1_array_crystal_height, xwidth = channel_7_analyzer_1_array_crystal_depth,
   priority = 920.1, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[1])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[1]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[1]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_7_analyzer_1_array_crystal_width, yheight = channel_7_analyzer_1_array_crystal_height, xwidth = channel_7_analyzer_1_array_crystal_depth,
   priority = 920.2, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[2])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[2]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[2]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_7_analyzer_1_array_crystal_width, yheight = channel_7_analyzer_1_array_crystal_height, xwidth = channel_7_analyzer_1_array_crystal_depth,
   priority = 920.3, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[3])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[3]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[3]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_7_analyzer_1_array_crystal_width, yheight = channel_7_analyzer_1_array_crystal_height, xwidth = channel_7_analyzer_1_array_crystal_depth,
   priority = 920.4, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[4])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[4]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[4]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_7_analyzer_1_array_crystal_width, yheight = channel_7_analyzer_1_array_crystal_height, xwidth = channel_7_analyzer_1_array_crystal_depth,
   priority = 920.5, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[5])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[5]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[5]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_7_analyzer_1_array_crystal_width, yheight = channel_7_analyzer_1_array_crystal_height, xwidth = channel_7_analyzer_1_array_crystal_depth,
   priority = 920.6, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[6])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[6]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[6]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_7_analyzer_1_array_crystal_width, yheight = channel_7_analyzer_1_array_crystal_height, xwidth = channel_7_analyzer_1_array_crystal_depth,
   priority = 920.7, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[7])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[7]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[7]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_7_analyzer_1_array_crystal_width, yheight = channel_7_analyzer_1_array_crystal_height, xwidth = channel_7_analyzer_1_array_crystal_depth,
   priority = 920.8, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[8])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[8]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[8]) RELATIVE channel_7_analyzer_1_rotated


COMPONENT channel_7_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_7_analyzer_1_center

COMPONENT channel_7_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[7]*DEG2RAD)) RELATIVE channel_7_analyzer_2_center
  ROTATED (0,-analyzer_theta[7],0) RELATIVE channel_7_analyzer_2_center

COMPONENT channel_7_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_7_analyzer_2_array_crystal_width, yheight = channel_7_analyzer_2_array_crystal_height, xwidth = channel_7_analyzer_2_array_crystal_depth,
   priority = 921.0, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[0])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[0]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[0]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_7_analyzer_2_array_crystal_width, yheight = channel_7_analyzer_2_array_crystal_height, xwidth = channel_7_analyzer_2_array_crystal_depth,
   priority = 921.1, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[1])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[1]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[1]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_7_analyzer_2_array_crystal_width, yheight = channel_7_analyzer_2_array_crystal_height, xwidth = channel_7_analyzer_2_array_crystal_depth,
   priority = 921.2, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[2])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[2]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[2]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_7_analyzer_2_array_crystal_width, yheight = channel_7_analyzer_2_array_crystal_height, xwidth = channel_7_analyzer_2_array_crystal_depth,
   priority = 921.3, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[3])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[3]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[3]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_7_analyzer_2_array_crystal_width, yheight = channel_7_analyzer_2_array_crystal_height, xwidth = channel_7_analyzer_2_array_crystal_depth,
   priority = 921.4, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[4])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[4]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[4]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_7_analyzer_2_array_crystal_width, yheight = channel_7_analyzer_2_array_crystal_height, xwidth = channel_7_analyzer_2_array_crystal_depth,
   priority = 921.5, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[5])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[5]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[5]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_7_analyzer_2_array_crystal_width, yheight = channel_7_analyzer_2_array_crystal_height, xwidth = channel_7_analyzer_2_array_crystal_depth,
   priority = 921.6, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[6])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[6]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[6]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_7_analyzer_2_array_crystal_width, yheight = channel_7_analyzer_2_array_crystal_height, xwidth = channel_7_analyzer_2_array_crystal_depth,
   priority = 921.7, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[7])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[7]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[7]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_7_analyzer_2_array_crystal_width, yheight = channel_7_analyzer_2_array_crystal_height, xwidth = channel_7_analyzer_2_array_crystal_depth,
   priority = 921.8, material_string = "PG_analyzer")
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[8])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[8]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[8]) RELATIVE channel_7_analyzer_2_rotated


COMPONENT channel_7_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=907.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_7_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_7_analyzer_2_center

COMPONENT channel_7_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=901,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_7_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_7_cave2_cyl1

COMPONENT channel_7_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=906,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_7_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_7_cave2_cyl1

COMPONENT channel_7_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=907,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_7_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_7_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_7 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_7_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_7_analyzer_1_center

COMPONENT inter_analyzer_colimator_7_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=925,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
  ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT inter_analyzer_colimator_7_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=926,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
  ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT inter_analyzer_colimator_7_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=927,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
  ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT inter_analyzer_colimator_7_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=928,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
  ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT inter_analyzer_colimator_7_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=929,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
  ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT diffraction_detector_7_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=931,material_string="Exit")
  AT (0,0,0) RELATIVE channel_7_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT spec_detector_7_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=932,material_string="Exit")
  AT (0,0,0) RELATIVE channel_7_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_7_analyzer_2_center

COMPONENT channel_8_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1000,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_8
  ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT channel_8_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1005,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_8
  ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT channel_8_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1002,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_8
  ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT channel_8_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1003,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_8
  ROTATED (0,0,0) RELATIVE kidney_channel_8


COMPONENT channel_8_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_8

COMPONENT channel_8_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[8]*DEG2RAD)) RELATIVE channel_8_analyzer_1_center
  ROTATED (0,180-analyzer_theta[8],0) RELATIVE channel_8_analyzer_1_center

COMPONENT channel_8_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_8_analyzer_1_array_crystal_width, yheight = channel_8_analyzer_1_array_crystal_height, xwidth = channel_8_analyzer_1_array_crystal_depth,
   priority = 1020.0, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[0])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[0]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[0]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_8_analyzer_1_array_crystal_width, yheight = channel_8_analyzer_1_array_crystal_height, xwidth = channel_8_analyzer_1_array_crystal_depth,
   priority = 1020.1, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[1])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[1]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[1]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_8_analyzer_1_array_crystal_width, yheight = channel_8_analyzer_1_array_crystal_height, xwidth = channel_8_analyzer_1_array_crystal_depth,
   priority = 1020.2, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[2])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[2]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[2]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_8_analyzer_1_array_crystal_width, yheight = channel_8_analyzer_1_array_crystal_height, xwidth = channel_8_analyzer_1_array_crystal_depth,
   priority = 1020.3, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[3])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[3]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[3]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_8_analyzer_1_array_crystal_width, yheight = channel_8_analyzer_1_array_crystal_height, xwidth = channel_8_analyzer_1_array_crystal_depth,
   priority = 1020.4, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[4])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[4]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[4]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_8_analyzer_1_array_crystal_width, yheight = channel_8_analyzer_1_array_crystal_height, xwidth = channel_8_analyzer_1_array_crystal_depth,
   priority = 1020.5, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[5])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[5]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[5]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_8_analyzer_1_array_crystal_width, yheight = channel_8_analyzer_1_array_crystal_height, xwidth = channel_8_analyzer_1_array_crystal_depth,
   priority = 1020.6, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[6])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[6]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[6]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_8_analyzer_1_array_crystal_width, yheight = channel_8_analyzer_1_array_crystal_height, xwidth = channel_8_analyzer_1_array_crystal_depth,
   priority = 1020.7, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[7])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[7]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[7]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_8_analyzer_1_array_crystal_width, yheight = channel_8_analyzer_1_array_crystal_height, xwidth = channel_8_analyzer_1_array_crystal_depth,
   priority = 1020.8, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[8])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[8]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[8]) RELATIVE channel_8_analyzer_1_rotated


COMPONENT channel_8_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_8_analyzer_1_center

COMPONENT channel_8_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[8]*DEG2RAD)) RELATIVE channel_8_analyzer_2_center
  ROTATED (0,-analyzer_theta[8],0) RELATIVE channel_8_analyzer_2_center

COMPONENT channel_8_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_8_analyzer_2_array_crystal_width, yheight = channel_8_analyzer_2_array_crystal_height, xwidth = channel_8_analyzer_2_array_crystal_depth,
   priority = 1021.0, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[0])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[0]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[0]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_8_analyzer_2_array_crystal_width, yheight = channel_8_analyzer_2_array_crystal_height, xwidth = channel_8_analyzer_2_array_crystal_depth,
   priority = 1021.1, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[1])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[1]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[1]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_8_analyzer_2_array_crystal_width, yheight = channel_8_analyzer_2_array_crystal_height, xwidth = channel_8_analyzer_2_array_crystal_depth,
   priority = 1021.2, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[2])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[2]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[2]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_8_analyzer_2_array_crystal_width, yheight = channel_8_analyzer_2_array_crystal_height, xwidth = channel_8_analyzer_2_array_crystal_depth,
   priority = 1021.3, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[3])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[3]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[3]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_8_analyzer_2_array_crystal_width, yheight = channel_8_analyzer_2_array_crystal_height, xwidth = channel_8_analyzer_2_array_crystal_depth,
   priority = 1021.4, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[4])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[4]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[4]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_8_analyzer_2_array_crystal_width, yheight = channel_8_analyzer_2_array_crystal_height, xwidth = channel_8_analyzer_2_array_crystal_depth,
   priority = 1021.5, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[5])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[5]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[5]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_8_analyzer_2_array_crystal_width, yheight = channel_8_analyzer_2_array_crystal_height, xwidth = channel_8_analyzer_2_array_crystal_depth,
   priority = 1021.6, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[6])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[6]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[6]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_8_analyzer_2_array_crystal_width, yheight = channel_8_analyzer_2_array_crystal_height, xwidth = channel_8_analyzer_2_array_crystal_depth,
   priority = 1021.7, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[7])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[7]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[7]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_8_analyzer_2_array_crystal_width, yheight = channel_8_analyzer_2_array_crystal_height, xwidth = channel_8_analyzer_2_array_crystal_depth,
   priority = 1021.8, material_string = "PG_analyzer")
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[8])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[8]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[8]) RELATIVE channel_8_analyzer_2_rotated


COMPONENT channel_8_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1007.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_8_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_8_analyzer_2_center

COMPONENT channel_8_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1001,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_8_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_8_cave2_cyl1

COMPONENT channel_8_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1006,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_8_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_8_cave2_cyl1

COMPONENT channel_8_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1007,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_8_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_8_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_8 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_8_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_8_analyzer_1_center

COMPONENT inter_analyzer_colimator_8_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1025,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
  ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT inter_analyzer_colimator_8_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1026,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
  ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT inter_analyzer_colimator_8_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1027,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
  ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT inter_analyzer_colimator_8_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1028,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
  ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT inter_analyzer_colimator_8_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1029,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
  ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT diffraction_detector_8_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1031,material_string="Exit")
  AT (0,0,0) RELATIVE channel_8_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT spec_detector_8_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1032,material_string="Exit")
  AT (0,0,0) RELATIVE channel_8_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_8_analyzer_2_center

COMPONENT channel_9_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1100,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_9
  ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT channel_9_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1105,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_9
  ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT channel_9_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1102,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_9
  ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT channel_9_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1103,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_9
  ROTATED (0,0,0) RELATIVE kidney_channel_9


COMPONENT channel_9_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_9

COMPONENT channel_9_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[9]*DEG2RAD)) RELATIVE channel_9_analyzer_1_center
  ROTATED (0,180-analyzer_theta[9],0) RELATIVE channel_9_analyzer_1_center

COMPONENT channel_9_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_9_analyzer_1_array_crystal_width, yheight = channel_9_analyzer_1_array_crystal_height, xwidth = channel_9_analyzer_1_array_crystal_depth,
   priority = 1120.0, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[0])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[0]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[0]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_9_analyzer_1_array_crystal_width, yheight = channel_9_analyzer_1_array_crystal_height, xwidth = channel_9_analyzer_1_array_crystal_depth,
   priority = 1120.1, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[1])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[1]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[1]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_9_analyzer_1_array_crystal_width, yheight = channel_9_analyzer_1_array_crystal_height, xwidth = channel_9_analyzer_1_array_crystal_depth,
   priority = 1120.2, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[2])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[2]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[2]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_9_analyzer_1_array_crystal_width, yheight = channel_9_analyzer_1_array_crystal_height, xwidth = channel_9_analyzer_1_array_crystal_depth,
   priority = 1120.3, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[3])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[3]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[3]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_9_analyzer_1_array_crystal_width, yheight = channel_9_analyzer_1_array_crystal_height, xwidth = channel_9_analyzer_1_array_crystal_depth,
   priority = 1120.4, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[4])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[4]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[4]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_9_analyzer_1_array_crystal_width, yheight = channel_9_analyzer_1_array_crystal_height, xwidth = channel_9_analyzer_1_array_crystal_depth,
   priority = 1120.5, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[5])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[5]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[5]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_9_analyzer_1_array_crystal_width, yheight = channel_9_analyzer_1_array_crystal_height, xwidth = channel_9_analyzer_1_array_crystal_depth,
   priority = 1120.6, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[6])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[6]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[6]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_9_analyzer_1_array_crystal_width, yheight = channel_9_analyzer_1_array_crystal_height, xwidth = channel_9_analyzer_1_array_crystal_depth,
   priority = 1120.7, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[7])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[7]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[7]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_9_analyzer_1_array_crystal_width, yheight = channel_9_analyzer_1_array_crystal_height, xwidth = channel_9_analyzer_1_array_crystal_depth,
   priority = 1120.8, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[8])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[8]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[8]) RELATIVE channel_9_analyzer_1_rotated


COMPONENT channel_9_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_9_analyzer_1_center

COMPONENT channel_9_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[9]*DEG2RAD)) RELATIVE channel_9_analyzer_2_center
  ROTATED (0,-analyzer_theta[9],0) RELATIVE channel_9_analyzer_2_center

COMPONENT channel_9_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_9_analyzer_2_array_crystal_width, yheight = channel_9_analyzer_2_array_crystal_height, xwidth = channel_9_analyzer_2_array_crystal_depth,
   priority = 1121.0, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[0])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[0]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[0]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_9_analyzer_2_array_crystal_width, yheight = channel_9_analyzer_2_array_crystal_height, xwidth = channel_9_analyzer_2_array_crystal_depth,
   priority = 1121.1, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[1])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[1]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[1]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_9_analyzer_2_array_crystal_width, yheight = channel_9_analyzer_2_array_crystal_height, xwidth = channel_9_analyzer_2_array_crystal_depth,
   priority = 1121.2, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[2])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[2]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[2]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_9_analyzer_2_array_crystal_width, yheight = channel_9_analyzer_2_array_crystal_height, xwidth = channel_9_analyzer_2_array_crystal_depth,
   priority = 1121.3, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[3])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[3]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[3]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_9_analyzer_2_array_crystal_width, yheight = channel_9_analyzer_2_array_crystal_height, xwidth = channel_9_analyzer_2_array_crystal_depth,
   priority = 1121.4, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[4])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[4]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[4]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_9_analyzer_2_array_crystal_width, yheight = channel_9_analyzer_2_array_crystal_height, xwidth = channel_9_analyzer_2_array_crystal_depth,
   priority = 1121.5, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[5])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[5]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[5]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_9_analyzer_2_array_crystal_width, yheight = channel_9_analyzer_2_array_crystal_height, xwidth = channel_9_analyzer_2_array_crystal_depth,
   priority = 1121.6, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[6])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[6]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[6]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_9_analyzer_2_array_crystal_width, yheight = channel_9_analyzer_2_array_crystal_height, xwidth = channel_9_analyzer_2_array_crystal_depth,
   priority = 1121.7, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[7])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[7]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[7]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_9_analyzer_2_array_crystal_width, yheight = channel_9_analyzer_2_array_crystal_height, xwidth = channel_9_analyzer_2_array_crystal_depth,
   priority = 1121.8, material_string = "PG_analyzer")
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[8])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[8]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[8]) RELATIVE channel_9_analyzer_2_rotated


COMPONENT channel_9_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1107.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_9_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_9_analyzer_2_center

COMPONENT channel_9_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1101,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_9_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_9_cave2_cyl1

COMPONENT channel_9_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1106,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_9_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_9_cave2_cyl1

COMPONENT channel_9_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1107,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_9_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_9_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_9 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_9_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_9_analyzer_1_center

COMPONENT inter_analyzer_colimator_9_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1125,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
  ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT inter_analyzer_colimator_9_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1126,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
  ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT inter_analyzer_colimator_9_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1127,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
  ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT inter_analyzer_colimator_9_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1128,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
  ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT inter_analyzer_colimator_9_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1129,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
  ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT diffraction_detector_9_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1131,material_string="Exit")
  AT (0,0,0) RELATIVE channel_9_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT spec_detector_9_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1132,material_string="Exit")
  AT (0,0,0) RELATIVE channel_9_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_9_analyzer_2_center

COMPONENT channel_10_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1200,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_10
  ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT channel_10_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1205,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_10
  ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT channel_10_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1202,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_10
  ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT channel_10_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1203,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_10
  ROTATED (0,0,0) RELATIVE kidney_channel_10


COMPONENT channel_10_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_10

COMPONENT channel_10_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[10]*DEG2RAD)) RELATIVE channel_10_analyzer_1_center
  ROTATED (0,180-analyzer_theta[10],0) RELATIVE channel_10_analyzer_1_center

COMPONENT channel_10_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_10_analyzer_1_array_crystal_width, yheight = channel_10_analyzer_1_array_crystal_height, xwidth = channel_10_analyzer_1_array_crystal_depth,
   priority = 1220.0, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[0])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[0]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[0]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_10_analyzer_1_array_crystal_width, yheight = channel_10_analyzer_1_array_crystal_height, xwidth = channel_10_analyzer_1_array_crystal_depth,
   priority = 1220.1, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[1])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[1]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[1]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_10_analyzer_1_array_crystal_width, yheight = channel_10_analyzer_1_array_crystal_height, xwidth = channel_10_analyzer_1_array_crystal_depth,
   priority = 1220.2, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[2])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[2]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[2]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_10_analyzer_1_array_crystal_width, yheight = channel_10_analyzer_1_array_crystal_height, xwidth = channel_10_analyzer_1_array_crystal_depth,
   priority = 1220.3, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[3])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[3]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[3]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_10_analyzer_1_array_crystal_width, yheight = channel_10_analyzer_1_array_crystal_height, xwidth = channel_10_analyzer_1_array_crystal_depth,
   priority = 1220.4, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[4])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[4]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[4]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_10_analyzer_1_array_crystal_width, yheight = channel_10_analyzer_1_array_crystal_height, xwidth = channel_10_analyzer_1_array_crystal_depth,
   priority = 1220.5, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[5])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[5]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[5]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_10_analyzer_1_array_crystal_width, yheight = channel_10_analyzer_1_array_crystal_height, xwidth = channel_10_analyzer_1_array_crystal_depth,
   priority = 1220.6, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[6])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[6]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[6]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_10_analyzer_1_array_crystal_width, yheight = channel_10_analyzer_1_array_crystal_height, xwidth = channel_10_analyzer_1_array_crystal_depth,
   priority = 1220.7, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[7])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[7]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[7]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_10_analyzer_1_array_crystal_width, yheight = channel_10_analyzer_1_array_crystal_height, xwidth = channel_10_analyzer_1_array_crystal_depth,
   priority = 1220.8, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[8])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[8]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[8]) RELATIVE channel_10_analyzer_1_rotated


COMPONENT channel_10_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_10_analyzer_1_center

COMPONENT channel_10_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[10]*DEG2RAD)) RELATIVE channel_10_analyzer_2_center
  ROTATED (0,-analyzer_theta[10],0) RELATIVE channel_10_analyzer_2_center

COMPONENT channel_10_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_10_analyzer_2_array_crystal_width, yheight = channel_10_analyzer_2_array_crystal_height, xwidth = channel_10_analyzer_2_array_crystal_depth,
   priority = 1221.0, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[0])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[0]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[0]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_10_analyzer_2_array_crystal_width, yheight = channel_10_analyzer_2_array_crystal_height, xwidth = channel_10_analyzer_2_array_crystal_depth,
   priority = 1221.1, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[1])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[1]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[1]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_10_analyzer_2_array_crystal_width, yheight = channel_10_analyzer_2_array_crystal_height, xwidth = channel_10_analyzer_2_array_crystal_depth,
   priority = 1221.2, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[2])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[2]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[2]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_10_analyzer_2_array_crystal_width, yheight = channel_10_analyzer_2_array_crystal_height, xwidth = channel_10_analyzer_2_array_crystal_depth,
   priority = 1221.3, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[3])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[3]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[3]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_10_analyzer_2_array_crystal_width, yheight = channel_10_analyzer_2_array_crystal_height, xwidth = channel_10_analyzer_2_array_crystal_depth,
   priority = 1221.4, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[4])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[4]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[4]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_10_analyzer_2_array_crystal_width, yheight = channel_10_analyzer_2_array_crystal_height, xwidth = channel_10_analyzer_2_array_crystal_depth,
   priority = 1221.5, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[5])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[5]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[5]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_10_analyzer_2_array_crystal_width, yheight = channel_10_analyzer_2_array_crystal_height, xwidth = channel_10_analyzer_2_array_crystal_depth,
   priority = 1221.6, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[6])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[6]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[6]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_10_analyzer_2_array_crystal_width, yheight = channel_10_analyzer_2_array_crystal_height, xwidth = channel_10_analyzer_2_array_crystal_depth,
   priority = 1221.7, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[7])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[7]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[7]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_10_analyzer_2_array_crystal_width, yheight = channel_10_analyzer_2_array_crystal_height, xwidth = channel_10_analyzer_2_array_crystal_depth,
   priority = 1221.8, material_string = "PG_analyzer")
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[8])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[8]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[8]) RELATIVE channel_10_analyzer_2_rotated


COMPONENT channel_10_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1207.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_10_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_10_analyzer_2_center

COMPONENT channel_10_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1201,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_10_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_10_cave2_cyl1

COMPONENT channel_10_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1206,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_10_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_10_cave2_cyl1

COMPONENT channel_10_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1207,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_10_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_10_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_10 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_10_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_10_analyzer_1_center

COMPONENT inter_analyzer_colimator_10_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1225,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
  ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT inter_analyzer_colimator_10_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1226,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
  ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT inter_analyzer_colimator_10_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1227,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
  ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT inter_analyzer_colimator_10_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1228,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
  ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT inter_analyzer_colimator_10_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1229,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
  ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT diffraction_detector_10_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1231,material_string="Exit")
  AT (0,0,0) RELATIVE channel_10_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT spec_detector_10_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1232,material_string="Exit")
  AT (0,0,0) RELATIVE channel_10_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_10_analyzer_2_center

COMPONENT channel_11_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1300,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_11
  ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT channel_11_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1305,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_11
  ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT channel_11_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1302,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_11
  ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT channel_11_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1303,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_11
  ROTATED (0,0,0) RELATIVE kidney_channel_11


COMPONENT channel_11_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_11

COMPONENT channel_11_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[11]*DEG2RAD)) RELATIVE channel_11_analyzer_1_center
  ROTATED (0,180-analyzer_theta[11],0) RELATIVE channel_11_analyzer_1_center

COMPONENT channel_11_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_11_analyzer_1_array_crystal_width, yheight = channel_11_analyzer_1_array_crystal_height, xwidth = channel_11_analyzer_1_array_crystal_depth,
   priority = 1320.0, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[0])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[0]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[0]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_11_analyzer_1_array_crystal_width, yheight = channel_11_analyzer_1_array_crystal_height, xwidth = channel_11_analyzer_1_array_crystal_depth,
   priority = 1320.1, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[1])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[1]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[1]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_11_analyzer_1_array_crystal_width, yheight = channel_11_analyzer_1_array_crystal_height, xwidth = channel_11_analyzer_1_array_crystal_depth,
   priority = 1320.2, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[2])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[2]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[2]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_11_analyzer_1_array_crystal_width, yheight = channel_11_analyzer_1_array_crystal_height, xwidth = channel_11_analyzer_1_array_crystal_depth,
   priority = 1320.3, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[3])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[3]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[3]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_11_analyzer_1_array_crystal_width, yheight = channel_11_analyzer_1_array_crystal_height, xwidth = channel_11_analyzer_1_array_crystal_depth,
   priority = 1320.4, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[4])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[4]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[4]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_11_analyzer_1_array_crystal_width, yheight = channel_11_analyzer_1_array_crystal_height, xwidth = channel_11_analyzer_1_array_crystal_depth,
   priority = 1320.5, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[5])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[5]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[5]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_11_analyzer_1_array_crystal_width, yheight = channel_11_analyzer_1_array_crystal_height, xwidth = channel_11_analyzer_1_array_crystal_depth,
   priority = 1320.6, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[6])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[6]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[6]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_11_analyzer_1_array_crystal_width, yheight = channel_11_analyzer_1_array_crystal_height, xwidth = channel_11_analyzer_1_array_crystal_depth,
   priority = 1320.7, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[7])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[7]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[7]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_11_analyzer_1_array_crystal_width, yheight = channel_11_analyzer_1_array_crystal_height, xwidth = channel_11_analyzer_1_array_crystal_depth,
   priority = 1320.8, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[8])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[8]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[8]) RELATIVE channel_11_analyzer_1_rotated


COMPONENT channel_11_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_11_analyzer_1_center

COMPONENT channel_11_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[11]*DEG2RAD)) RELATIVE channel_11_analyzer_2_center
  ROTATED (0,-analyzer_theta[11],0) RELATIVE channel_11_analyzer_2_center

COMPONENT channel_11_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_11_analyzer_2_array_crystal_width, yheight = channel_11_analyzer_2_array_crystal_height, xwidth = channel_11_analyzer_2_array_crystal_depth,
   priority = 1321.0, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[0])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[0]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[0]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_11_analyzer_2_array_crystal_width, yheight = channel_11_analyzer_2_array_crystal_height, xwidth = channel_11_analyzer_2_array_crystal_depth,
   priority = 1321.1, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[1])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[1]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[1]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_11_analyzer_2_array_crystal_width, yheight = channel_11_analyzer_2_array_crystal_height, xwidth = channel_11_analyzer_2_array_crystal_depth,
   priority = 1321.2, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[2])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[2]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[2]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_11_analyzer_2_array_crystal_width, yheight = channel_11_analyzer_2_array_crystal_height, xwidth = channel_11_analyzer_2_array_crystal_depth,
   priority = 1321.3, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[3])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[3]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[3]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_11_analyzer_2_array_crystal_width, yheight = channel_11_analyzer_2_array_crystal_height, xwidth = channel_11_analyzer_2_array_crystal_depth,
   priority = 1321.4, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[4])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[4]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[4]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_11_analyzer_2_array_crystal_width, yheight = channel_11_analyzer_2_array_crystal_height, xwidth = channel_11_analyzer_2_array_crystal_depth,
   priority = 1321.5, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[5])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[5]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[5]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_11_analyzer_2_array_crystal_width, yheight = channel_11_analyzer_2_array_crystal_height, xwidth = channel_11_analyzer_2_array_crystal_depth,
   priority = 1321.6, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[6])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[6]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[6]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_11_analyzer_2_array_crystal_width, yheight = channel_11_analyzer_2_array_crystal_height, xwidth = channel_11_analyzer_2_array_crystal_depth,
   priority = 1321.7, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[7])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[7]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[7]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_11_analyzer_2_array_crystal_width, yheight = channel_11_analyzer_2_array_crystal_height, xwidth = channel_11_analyzer_2_array_crystal_depth,
   priority = 1321.8, material_string = "PG_analyzer")
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[8])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[8]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[8]) RELATIVE channel_11_analyzer_2_rotated


COMPONENT channel_11_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1307.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_11_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_11_analyzer_2_center

COMPONENT channel_11_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1301,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_11_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_11_cave2_cyl1

COMPONENT channel_11_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1306,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_11_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_11_cave2_cyl1

COMPONENT channel_11_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1307,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_11_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_11_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_11 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_11_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_11_analyzer_1_center

COMPONENT inter_analyzer_colimator_11_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1325,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
  ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT inter_analyzer_colimator_11_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1326,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
  ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT inter_analyzer_colimator_11_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1327,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
  ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT inter_analyzer_colimator_11_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1328,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
  ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT inter_analyzer_colimator_11_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1329,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
  ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT diffraction_detector_11_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1331,material_string="Exit")
  AT (0,0,0) RELATIVE channel_11_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT spec_detector_11_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1332,material_string="Exit")
  AT (0,0,0) RELATIVE channel_11_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_11_analyzer_2_center

COMPONENT channel_12_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1400,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_12
  ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT channel_12_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1405,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_12
  ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT channel_12_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1402,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_12
  ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT channel_12_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1403,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_12
  ROTATED (0,0,0) RELATIVE kidney_channel_12


COMPONENT channel_12_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_12

COMPONENT channel_12_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[12]*DEG2RAD)) RELATIVE channel_12_analyzer_1_center
  ROTATED (0,180-analyzer_theta[12],0) RELATIVE channel_12_analyzer_1_center

COMPONENT channel_12_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_12_analyzer_1_array_crystal_width, yheight = channel_12_analyzer_1_array_crystal_height, xwidth = channel_12_analyzer_1_array_crystal_depth,
   priority = 1420.0, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[0])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[0]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[0]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_12_analyzer_1_array_crystal_width, yheight = channel_12_analyzer_1_array_crystal_height, xwidth = channel_12_analyzer_1_array_crystal_depth,
   priority = 1420.1, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[1])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[1]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[1]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_12_analyzer_1_array_crystal_width, yheight = channel_12_analyzer_1_array_crystal_height, xwidth = channel_12_analyzer_1_array_crystal_depth,
   priority = 1420.2, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[2])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[2]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[2]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_12_analyzer_1_array_crystal_width, yheight = channel_12_analyzer_1_array_crystal_height, xwidth = channel_12_analyzer_1_array_crystal_depth,
   priority = 1420.3, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[3])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[3]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[3]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_12_analyzer_1_array_crystal_width, yheight = channel_12_analyzer_1_array_crystal_height, xwidth = channel_12_analyzer_1_array_crystal_depth,
   priority = 1420.4, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[4])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[4]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[4]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_12_analyzer_1_array_crystal_width, yheight = channel_12_analyzer_1_array_crystal_height, xwidth = channel_12_analyzer_1_array_crystal_depth,
   priority = 1420.5, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[5])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[5]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[5]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_12_analyzer_1_array_crystal_width, yheight = channel_12_analyzer_1_array_crystal_height, xwidth = channel_12_analyzer_1_array_crystal_depth,
   priority = 1420.6, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[6])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[6]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[6]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_12_analyzer_1_array_crystal_width, yheight = channel_12_analyzer_1_array_crystal_height, xwidth = channel_12_analyzer_1_array_crystal_depth,
   priority = 1420.7, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[7])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[7]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[7]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_12_analyzer_1_array_crystal_width, yheight = channel_12_analyzer_1_array_crystal_height, xwidth = channel_12_analyzer_1_array_crystal_depth,
   priority = 1420.8, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[8])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[8]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[8]) RELATIVE channel_12_analyzer_1_rotated


COMPONENT channel_12_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_12_analyzer_1_center

COMPONENT channel_12_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[12]*DEG2RAD)) RELATIVE channel_12_analyzer_2_center
  ROTATED (0,-analyzer_theta[12],0) RELATIVE channel_12_analyzer_2_center

COMPONENT channel_12_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_12_analyzer_2_array_crystal_width, yheight = channel_12_analyzer_2_array_crystal_height, xwidth = channel_12_analyzer_2_array_crystal_depth,
   priority = 1421.0, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[0])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[0]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[0]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_12_analyzer_2_array_crystal_width, yheight = channel_12_analyzer_2_array_crystal_height, xwidth = channel_12_analyzer_2_array_crystal_depth,
   priority = 1421.1, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[1])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[1]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[1]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_12_analyzer_2_array_crystal_width, yheight = channel_12_analyzer_2_array_crystal_height, xwidth = channel_12_analyzer_2_array_crystal_depth,
   priority = 1421.2, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[2])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[2]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[2]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_12_analyzer_2_array_crystal_width, yheight = channel_12_analyzer_2_array_crystal_height, xwidth = channel_12_analyzer_2_array_crystal_depth,
   priority = 1421.3, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[3])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[3]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[3]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_12_analyzer_2_array_crystal_width, yheight = channel_12_analyzer_2_array_crystal_height, xwidth = channel_12_analyzer_2_array_crystal_depth,
   priority = 1421.4, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[4])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[4]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[4]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_12_analyzer_2_array_crystal_width, yheight = channel_12_analyzer_2_array_crystal_height, xwidth = channel_12_analyzer_2_array_crystal_depth,
   priority = 1421.5, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[5])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[5]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[5]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_12_analyzer_2_array_crystal_width, yheight = channel_12_analyzer_2_array_crystal_height, xwidth = channel_12_analyzer_2_array_crystal_depth,
   priority = 1421.6, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[6])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[6]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[6]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_12_analyzer_2_array_crystal_width, yheight = channel_12_analyzer_2_array_crystal_height, xwidth = channel_12_analyzer_2_array_crystal_depth,
   priority = 1421.7, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[7])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[7]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[7]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_12_analyzer_2_array_crystal_width, yheight = channel_12_analyzer_2_array_crystal_height, xwidth = channel_12_analyzer_2_array_crystal_depth,
   priority = 1421.8, material_string = "PG_analyzer")
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[8])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[8]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[8]) RELATIVE channel_12_analyzer_2_rotated


COMPONENT channel_12_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1407.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_12_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_12_analyzer_2_center

COMPONENT channel_12_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1401,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_12_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_12_cave2_cyl1

COMPONENT channel_12_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1406,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_12_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_12_cave2_cyl1

COMPONENT channel_12_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1407,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_12_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_12_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_12 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_12_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_12_analyzer_1_center

COMPONENT inter_analyzer_colimator_12_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1425,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
  ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT inter_analyzer_colimator_12_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1426,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
  ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT inter_analyzer_colimator_12_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1427,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
  ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT inter_analyzer_colimator_12_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1428,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
  ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT inter_analyzer_colimator_12_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1429,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
  ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT diffraction_detector_12_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1431,material_string="Exit")
  AT (0,0,0) RELATIVE channel_12_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT spec_detector_12_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1432,material_string="Exit")
  AT (0,0,0) RELATIVE channel_12_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_12_analyzer_2_center

COMPONENT channel_13_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1500,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_13
  ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT channel_13_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1505,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_13
  ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT channel_13_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1502,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_13
  ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT channel_13_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1503,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_13
  ROTATED (0,0,0) RELATIVE kidney_channel_13


COMPONENT channel_13_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_13

COMPONENT channel_13_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[13]*DEG2RAD)) RELATIVE channel_13_analyzer_1_center
  ROTATED (0,180-analyzer_theta[13],0) RELATIVE channel_13_analyzer_1_center

COMPONENT channel_13_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_13_analyzer_1_array_crystal_width, yheight = channel_13_analyzer_1_array_crystal_height, xwidth = channel_13_analyzer_1_array_crystal_depth,
   priority = 1520.0, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[0])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[0]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[0]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_13_analyzer_1_array_crystal_width, yheight = channel_13_analyzer_1_array_crystal_height, xwidth = channel_13_analyzer_1_array_crystal_depth,
   priority = 1520.1, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[1])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[1]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[1]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_13_analyzer_1_array_crystal_width, yheight = channel_13_analyzer_1_array_crystal_height, xwidth = channel_13_analyzer_1_array_crystal_depth,
   priority = 1520.2, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[2])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[2]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[2]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_13_analyzer_1_array_crystal_width, yheight = channel_13_analyzer_1_array_crystal_height, xwidth = channel_13_analyzer_1_array_crystal_depth,
   priority = 1520.3, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[3])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[3]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[3]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_13_analyzer_1_array_crystal_width, yheight = channel_13_analyzer_1_array_crystal_height, xwidth = channel_13_analyzer_1_array_crystal_depth,
   priority = 1520.4, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[4])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[4]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[4]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_13_analyzer_1_array_crystal_width, yheight = channel_13_analyzer_1_array_crystal_height, xwidth = channel_13_analyzer_1_array_crystal_depth,
   priority = 1520.5, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[5])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[5]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[5]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_13_analyzer_1_array_crystal_width, yheight = channel_13_analyzer_1_array_crystal_height, xwidth = channel_13_analyzer_1_array_crystal_depth,
   priority = 1520.6, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[6])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[6]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[6]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_13_analyzer_1_array_crystal_width, yheight = channel_13_analyzer_1_array_crystal_height, xwidth = channel_13_analyzer_1_array_crystal_depth,
   priority = 1520.7, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[7])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[7]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[7]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_13_analyzer_1_array_crystal_width, yheight = channel_13_analyzer_1_array_crystal_height, xwidth = channel_13_analyzer_1_array_crystal_depth,
   priority = 1520.8, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[8])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[8]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[8]) RELATIVE channel_13_analyzer_1_rotated


COMPONENT channel_13_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_13_analyzer_1_center

COMPONENT channel_13_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[13]*DEG2RAD)) RELATIVE channel_13_analyzer_2_center
  ROTATED (0,-analyzer_theta[13],0) RELATIVE channel_13_analyzer_2_center

COMPONENT channel_13_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_13_analyzer_2_array_crystal_width, yheight = channel_13_analyzer_2_array_crystal_height, xwidth = channel_13_analyzer_2_array_crystal_depth,
   priority = 1521.0, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[0])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[0]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[0]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_13_analyzer_2_array_crystal_width, yheight = channel_13_analyzer_2_array_crystal_height, xwidth = channel_13_analyzer_2_array_crystal_depth,
   priority = 1521.1, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[1])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[1]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[1]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_13_analyzer_2_array_crystal_width, yheight = channel_13_analyzer_2_array_crystal_height, xwidth = channel_13_analyzer_2_array_crystal_depth,
   priority = 1521.2, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[2])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[2]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[2]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_13_analyzer_2_array_crystal_width, yheight = channel_13_analyzer_2_array_crystal_height, xwidth = channel_13_analyzer_2_array_crystal_depth,
   priority = 1521.3, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[3])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[3]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[3]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_13_analyzer_2_array_crystal_width, yheight = channel_13_analyzer_2_array_crystal_height, xwidth = channel_13_analyzer_2_array_crystal_depth,
   priority = 1521.4, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[4])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[4]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[4]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_13_analyzer_2_array_crystal_width, yheight = channel_13_analyzer_2_array_crystal_height, xwidth = channel_13_analyzer_2_array_crystal_depth,
   priority = 1521.5, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[5])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[5]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[5]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_13_analyzer_2_array_crystal_width, yheight = channel_13_analyzer_2_array_crystal_height, xwidth = channel_13_analyzer_2_array_crystal_depth,
   priority = 1521.6, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[6])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[6]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[6]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_13_analyzer_2_array_crystal_width, yheight = channel_13_analyzer_2_array_crystal_height, xwidth = channel_13_analyzer_2_array_crystal_depth,
   priority = 1521.7, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[7])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[7]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[7]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_13_analyzer_2_array_crystal_width, yheight = channel_13_analyzer_2_array_crystal_height, xwidth = channel_13_analyzer_2_array_crystal_depth,
   priority = 1521.8, material_string = "PG_analyzer")
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[8])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[8]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[8]) RELATIVE channel_13_analyzer_2_rotated


COMPONENT channel_13_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1507.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_13_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_13_analyzer_2_center

COMPONENT channel_13_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1501,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_13_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_13_cave2_cyl1

COMPONENT channel_13_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1506,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_13_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_13_cave2_cyl1

COMPONENT channel_13_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1507,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_13_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_13_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_13 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_13_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_13_analyzer_1_center

COMPONENT inter_analyzer_colimator_13_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1525,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
  ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT inter_analyzer_colimator_13_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1526,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
  ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT inter_analyzer_colimator_13_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1527,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
  ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT inter_analyzer_colimator_13_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1528,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
  ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT inter_analyzer_colimator_13_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1529,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
  ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT diffraction_detector_13_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1531,material_string="Exit")
  AT (0,0,0) RELATIVE channel_13_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT spec_detector_13_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1532,material_string="Exit")
  AT (0,0,0) RELATIVE channel_13_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_13_analyzer_2_center

COMPONENT channel_14_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1600,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_14
  ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT channel_14_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1605,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_14
  ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT channel_14_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1602,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_14
  ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT channel_14_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1603,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_14
  ROTATED (0,0,0) RELATIVE kidney_channel_14


COMPONENT channel_14_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_14

COMPONENT channel_14_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[14]*DEG2RAD)) RELATIVE channel_14_analyzer_1_center
  ROTATED (0,180-analyzer_theta[14],0) RELATIVE channel_14_analyzer_1_center

COMPONENT channel_14_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_14_analyzer_1_array_crystal_width, yheight = channel_14_analyzer_1_array_crystal_height, xwidth = channel_14_analyzer_1_array_crystal_depth,
   priority = 1620.0, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[0])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[0]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[0]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_14_analyzer_1_array_crystal_width, yheight = channel_14_analyzer_1_array_crystal_height, xwidth = channel_14_analyzer_1_array_crystal_depth,
   priority = 1620.1, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[1])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[1]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[1]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_14_analyzer_1_array_crystal_width, yheight = channel_14_analyzer_1_array_crystal_height, xwidth = channel_14_analyzer_1_array_crystal_depth,
   priority = 1620.2, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[2])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[2]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[2]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_14_analyzer_1_array_crystal_width, yheight = channel_14_analyzer_1_array_crystal_height, xwidth = channel_14_analyzer_1_array_crystal_depth,
   priority = 1620.3, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[3])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[3]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[3]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_14_analyzer_1_array_crystal_width, yheight = channel_14_analyzer_1_array_crystal_height, xwidth = channel_14_analyzer_1_array_crystal_depth,
   priority = 1620.4, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[4])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[4]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[4]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_14_analyzer_1_array_crystal_width, yheight = channel_14_analyzer_1_array_crystal_height, xwidth = channel_14_analyzer_1_array_crystal_depth,
   priority = 1620.5, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[5])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[5]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[5]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_14_analyzer_1_array_crystal_width, yheight = channel_14_analyzer_1_array_crystal_height, xwidth = channel_14_analyzer_1_array_crystal_depth,
   priority = 1620.6, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[6])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[6]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[6]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_14_analyzer_1_array_crystal_width, yheight = channel_14_analyzer_1_array_crystal_height, xwidth = channel_14_analyzer_1_array_crystal_depth,
   priority = 1620.7, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[7])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[7]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[7]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_14_analyzer_1_array_crystal_width, yheight = channel_14_analyzer_1_array_crystal_height, xwidth = channel_14_analyzer_1_array_crystal_depth,
   priority = 1620.8, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[8])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[8]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[8]) RELATIVE channel_14_analyzer_1_rotated


COMPONENT channel_14_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_14_analyzer_1_center

COMPONENT channel_14_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[14]*DEG2RAD)) RELATIVE channel_14_analyzer_2_center
  ROTATED (0,-analyzer_theta[14],0) RELATIVE channel_14_analyzer_2_center

COMPONENT channel_14_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_14_analyzer_2_array_crystal_width, yheight = channel_14_analyzer_2_array_crystal_height, xwidth = channel_14_analyzer_2_array_crystal_depth,
   priority = 1621.0, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[0])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[0]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[0]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_14_analyzer_2_array_crystal_width, yheight = channel_14_analyzer_2_array_crystal_height, xwidth = channel_14_analyzer_2_array_crystal_depth,
   priority = 1621.1, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[1])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[1]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[1]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_14_analyzer_2_array_crystal_width, yheight = channel_14_analyzer_2_array_crystal_height, xwidth = channel_14_analyzer_2_array_crystal_depth,
   priority = 1621.2, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[2])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[2]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[2]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_14_analyzer_2_array_crystal_width, yheight = channel_14_analyzer_2_array_crystal_height, xwidth = channel_14_analyzer_2_array_crystal_depth,
   priority = 1621.3, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[3])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[3]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[3]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_14_analyzer_2_array_crystal_width, yheight = channel_14_analyzer_2_array_crystal_height, xwidth = channel_14_analyzer_2_array_crystal_depth,
   priority = 1621.4, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[4])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[4]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[4]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_14_analyzer_2_array_crystal_width, yheight = channel_14_analyzer_2_array_crystal_height, xwidth = channel_14_analyzer_2_array_crystal_depth,
   priority = 1621.5, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[5])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[5]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[5]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_14_analyzer_2_array_crystal_width, yheight = channel_14_analyzer_2_array_crystal_height, xwidth = channel_14_analyzer_2_array_crystal_depth,
   priority = 1621.6, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[6])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[6]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[6]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_14_analyzer_2_array_crystal_width, yheight = channel_14_analyzer_2_array_crystal_height, xwidth = channel_14_analyzer_2_array_crystal_depth,
   priority = 1621.7, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[7])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[7]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[7]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_14_analyzer_2_array_crystal_width, yheight = channel_14_analyzer_2_array_crystal_height, xwidth = channel_14_analyzer_2_array_crystal_depth,
   priority = 1621.8, material_string = "PG_analyzer")
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[8])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[8]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[8]) RELATIVE channel_14_analyzer_2_rotated


COMPONENT channel_14_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1607.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_14_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_14_analyzer_2_center

COMPONENT channel_14_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1601,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_14_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_14_cave2_cyl1

COMPONENT channel_14_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1606,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_14_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_14_cave2_cyl1

COMPONENT channel_14_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1607,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_14_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_14_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_14 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_14_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_14_analyzer_1_center

COMPONENT inter_analyzer_colimator_14_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1625,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
  ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT inter_analyzer_colimator_14_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1626,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
  ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT inter_analyzer_colimator_14_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1627,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
  ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT inter_analyzer_colimator_14_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1628,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
  ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT inter_analyzer_colimator_14_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1629,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
  ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT diffraction_detector_14_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1631,material_string="Exit")
  AT (0,0,0) RELATIVE channel_14_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT spec_detector_14_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1632,material_string="Exit")
  AT (0,0,0) RELATIVE channel_14_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_14_analyzer_2_center

COMPONENT channel_15_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1700,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_15
  ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT channel_15_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1705,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_15
  ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT channel_15_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1702,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_15
  ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT channel_15_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1703,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_15
  ROTATED (0,0,0) RELATIVE kidney_channel_15


COMPONENT channel_15_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_15

COMPONENT channel_15_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[15]*DEG2RAD)) RELATIVE channel_15_analyzer_1_center
  ROTATED (0,180-analyzer_theta[15],0) RELATIVE channel_15_analyzer_1_center

COMPONENT channel_15_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_15_analyzer_1_array_crystal_width, yheight = channel_15_analyzer_1_array_crystal_height, xwidth = channel_15_analyzer_1_array_crystal_depth,
   priority = 1720.0, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[0])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[0]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[0]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_15_analyzer_1_array_crystal_width, yheight = channel_15_analyzer_1_array_crystal_height, xwidth = channel_15_analyzer_1_array_crystal_depth,
   priority = 1720.1, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[1])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[1]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[1]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_15_analyzer_1_array_crystal_width, yheight = channel_15_analyzer_1_array_crystal_height, xwidth = channel_15_analyzer_1_array_crystal_depth,
   priority = 1720.2, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[2])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[2]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[2]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_15_analyzer_1_array_crystal_width, yheight = channel_15_analyzer_1_array_crystal_height, xwidth = channel_15_analyzer_1_array_crystal_depth,
   priority = 1720.3, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[3])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[3]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[3]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_15_analyzer_1_array_crystal_width, yheight = channel_15_analyzer_1_array_crystal_height, xwidth = channel_15_analyzer_1_array_crystal_depth,
   priority = 1720.4, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[4])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[4]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[4]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_15_analyzer_1_array_crystal_width, yheight = channel_15_analyzer_1_array_crystal_height, xwidth = channel_15_analyzer_1_array_crystal_depth,
   priority = 1720.5, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[5])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[5]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[5]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_15_analyzer_1_array_crystal_width, yheight = channel_15_analyzer_1_array_crystal_height, xwidth = channel_15_analyzer_1_array_crystal_depth,
   priority = 1720.6, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[6])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[6]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[6]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_15_analyzer_1_array_crystal_width, yheight = channel_15_analyzer_1_array_crystal_height, xwidth = channel_15_analyzer_1_array_crystal_depth,
   priority = 1720.7, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[7])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[7]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[7]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_15_analyzer_1_array_crystal_width, yheight = channel_15_analyzer_1_array_crystal_height, xwidth = channel_15_analyzer_1_array_crystal_depth,
   priority = 1720.8, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[8])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[8]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[8]) RELATIVE channel_15_analyzer_1_rotated


COMPONENT channel_15_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_15_analyzer_1_center

COMPONENT channel_15_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[15]*DEG2RAD)) RELATIVE channel_15_analyzer_2_center
  ROTATED (0,-analyzer_theta[15],0) RELATIVE channel_15_analyzer_2_center

COMPONENT channel_15_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_15_analyzer_2_array_crystal_width, yheight = channel_15_analyzer_2_array_crystal_height, xwidth = channel_15_analyzer_2_array_crystal_depth,
   priority = 1721.0, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[0])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[0]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[0]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_15_analyzer_2_array_crystal_width, yheight = channel_15_analyzer_2_array_crystal_height, xwidth = channel_15_analyzer_2_array_crystal_depth,
   priority = 1721.1, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[1])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[1]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[1]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_15_analyzer_2_array_crystal_width, yheight = channel_15_analyzer_2_array_crystal_height, xwidth = channel_15_analyzer_2_array_crystal_depth,
   priority = 1721.2, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[2])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[2]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[2]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_15_analyzer_2_array_crystal_width, yheight = channel_15_analyzer_2_array_crystal_height, xwidth = channel_15_analyzer_2_array_crystal_depth,
   priority = 1721.3, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[3])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[3]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[3]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_15_analyzer_2_array_crystal_width, yheight = channel_15_analyzer_2_array_crystal_height, xwidth = channel_15_analyzer_2_array_crystal_depth,
   priority = 1721.4, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[4])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[4]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[4]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_15_analyzer_2_array_crystal_width, yheight = channel_15_analyzer_2_array_crystal_height, xwidth = channel_15_analyzer_2_array_crystal_depth,
   priority = 1721.5, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[5])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[5]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[5]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_15_analyzer_2_array_crystal_width, yheight = channel_15_analyzer_2_array_crystal_height, xwidth = channel_15_analyzer_2_array_crystal_depth,
   priority = 1721.6, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[6])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[6]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[6]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_15_analyzer_2_array_crystal_width, yheight = channel_15_analyzer_2_array_crystal_height, xwidth = channel_15_analyzer_2_array_crystal_depth,
   priority = 1721.7, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[7])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[7]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[7]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_15_analyzer_2_array_crystal_width, yheight = channel_15_analyzer_2_array_crystal_height, xwidth = channel_15_analyzer_2_array_crystal_depth,
   priority = 1721.8, material_string = "PG_analyzer")
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[8])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[8]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[8]) RELATIVE channel_15_analyzer_2_rotated


COMPONENT channel_15_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1707.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_15_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_15_analyzer_2_center

COMPONENT channel_15_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1701,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_15_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_15_cave2_cyl1

COMPONENT channel_15_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1706,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_15_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_15_cave2_cyl1

COMPONENT channel_15_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1707,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_15_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_15_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_15 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_15_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_15_analyzer_1_center

COMPONENT inter_analyzer_colimator_15_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1725,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
  ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT inter_analyzer_colimator_15_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1726,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
  ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT inter_analyzer_colimator_15_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1727,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
  ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT inter_analyzer_colimator_15_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1728,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
  ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT inter_analyzer_colimator_15_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1729,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
  ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT diffraction_detector_15_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1731,material_string="Exit")
  AT (0,0,0) RELATIVE channel_15_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT spec_detector_15_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1732,material_string="Exit")
  AT (0,0,0) RELATIVE channel_15_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_15_analyzer_2_center

COMPONENT channel_16_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1800,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_16
  ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT channel_16_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1805,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_16
  ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT channel_16_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1802,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_16
  ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT channel_16_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1803,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_16
  ROTATED (0,0,0) RELATIVE kidney_channel_16


COMPONENT channel_16_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_16

COMPONENT channel_16_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[16]*DEG2RAD)) RELATIVE channel_16_analyzer_1_center
  ROTATED (0,180-analyzer_theta[16],0) RELATIVE channel_16_analyzer_1_center

COMPONENT channel_16_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_16_analyzer_1_array_crystal_width, yheight = channel_16_analyzer_1_array_crystal_height, xwidth = channel_16_analyzer_1_array_crystal_depth,
   priority = 1820.0, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[0])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[0]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[0]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_16_analyzer_1_array_crystal_width, yheight = channel_16_analyzer_1_array_crystal_height, xwidth = channel_16_analyzer_1_array_crystal_depth,
   priority = 1820.1, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[1])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[1]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[1]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_16_analyzer_1_array_crystal_width, yheight = channel_16_analyzer_1_array_crystal_height, xwidth = channel_16_analyzer_1_array_crystal_depth,
   priority = 1820.2, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[2])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[2]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[2]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_16_analyzer_1_array_crystal_width, yheight = channel_16_analyzer_1_array_crystal_height, xwidth = channel_16_analyzer_1_array_crystal_depth,
   priority = 1820.3, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[3])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[3]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[3]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_16_analyzer_1_array_crystal_width, yheight = channel_16_analyzer_1_array_crystal_height, xwidth = channel_16_analyzer_1_array_crystal_depth,
   priority = 1820.4, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[4])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[4]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[4]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_16_analyzer_1_array_crystal_width, yheight = channel_16_analyzer_1_array_crystal_height, xwidth = channel_16_analyzer_1_array_crystal_depth,
   priority = 1820.5, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[5])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[5]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[5]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_16_analyzer_1_array_crystal_width, yheight = channel_16_analyzer_1_array_crystal_height, xwidth = channel_16_analyzer_1_array_crystal_depth,
   priority = 1820.6, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[6])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[6]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[6]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_16_analyzer_1_array_crystal_width, yheight = channel_16_analyzer_1_array_crystal_height, xwidth = channel_16_analyzer_1_array_crystal_depth,
   priority = 1820.7, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[7])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[7]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[7]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_16_analyzer_1_array_crystal_width, yheight = channel_16_analyzer_1_array_crystal_height, xwidth = channel_16_analyzer_1_array_crystal_depth,
   priority = 1820.8, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[8])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[8]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[8]) RELATIVE channel_16_analyzer_1_rotated


COMPONENT channel_16_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_16_analyzer_1_center

COMPONENT channel_16_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[16]*DEG2RAD)) RELATIVE channel_16_analyzer_2_center
  ROTATED (0,-analyzer_theta[16],0) RELATIVE channel_16_analyzer_2_center

COMPONENT channel_16_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_16_analyzer_2_array_crystal_width, yheight = channel_16_analyzer_2_array_crystal_height, xwidth = channel_16_analyzer_2_array_crystal_depth,
   priority = 1821.0, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[0])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[0]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[0]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_16_analyzer_2_array_crystal_width, yheight = channel_16_analyzer_2_array_crystal_height, xwidth = channel_16_analyzer_2_array_crystal_depth,
   priority = 1821.1, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[1])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[1]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[1]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_16_analyzer_2_array_crystal_width, yheight = channel_16_analyzer_2_array_crystal_height, xwidth = channel_16_analyzer_2_array_crystal_depth,
   priority = 1821.2, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[2])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[2]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[2]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_16_analyzer_2_array_crystal_width, yheight = channel_16_analyzer_2_array_crystal_height, xwidth = channel_16_analyzer_2_array_crystal_depth,
   priority = 1821.3, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[3])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[3]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[3]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_16_analyzer_2_array_crystal_width, yheight = channel_16_analyzer_2_array_crystal_height, xwidth = channel_16_analyzer_2_array_crystal_depth,
   priority = 1821.4, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[4])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[4]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[4]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_16_analyzer_2_array_crystal_width, yheight = channel_16_analyzer_2_array_crystal_height, xwidth = channel_16_analyzer_2_array_crystal_depth,
   priority = 1821.5, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[5])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[5]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[5]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_16_analyzer_2_array_crystal_width, yheight = channel_16_analyzer_2_array_crystal_height, xwidth = channel_16_analyzer_2_array_crystal_depth,
   priority = 1821.6, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[6])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[6]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[6]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_16_analyzer_2_array_crystal_width, yheight = channel_16_analyzer_2_array_crystal_height, xwidth = channel_16_analyzer_2_array_crystal_depth,
   priority = 1821.7, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[7])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[7]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[7]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_16_analyzer_2_array_crystal_width, yheight = channel_16_analyzer_2_array_crystal_height, xwidth = channel_16_analyzer_2_array_crystal_depth,
   priority = 1821.8, material_string = "PG_analyzer")
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[8])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[8]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[8]) RELATIVE channel_16_analyzer_2_rotated


COMPONENT channel_16_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1807.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_16_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_16_analyzer_2_center

COMPONENT channel_16_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1801,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_16_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_16_cave2_cyl1

COMPONENT channel_16_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1806,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_16_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_16_cave2_cyl1

COMPONENT channel_16_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1807,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_16_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_16_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_16 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_16_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_16_analyzer_1_center

COMPONENT inter_analyzer_colimator_16_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1825,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
  ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT inter_analyzer_colimator_16_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1826,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
  ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT inter_analyzer_colimator_16_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1827,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
  ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT inter_analyzer_colimator_16_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1828,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
  ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT inter_analyzer_colimator_16_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1829,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
  ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT diffraction_detector_16_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1831,material_string="Exit")
  AT (0,0,0) RELATIVE channel_16_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT spec_detector_16_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1832,material_string="Exit")
  AT (0,0,0) RELATIVE channel_16_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_16_analyzer_2_center

COMPONENT channel_17_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=1900,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_17
  ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT channel_17_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=1905,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_17
  ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT channel_17_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=1902,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_17
  ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT channel_17_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=1903,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_17
  ROTATED (0,0,0) RELATIVE kidney_channel_17


COMPONENT channel_17_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_17

COMPONENT channel_17_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[17]*DEG2RAD)) RELATIVE channel_17_analyzer_1_center
  ROTATED (0,180-analyzer_theta[17],0) RELATIVE channel_17_analyzer_1_center

COMPONENT channel_17_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_17_analyzer_1_array_crystal_width, yheight = channel_17_analyzer_1_array_crystal_height, xwidth = channel_17_analyzer_1_array_crystal_depth,
   priority = 1920.0, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[0])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[0]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[0]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_17_analyzer_1_array_crystal_width, yheight = channel_17_analyzer_1_array_crystal_height, xwidth = channel_17_analyzer_1_array_crystal_depth,
   priority = 1920.1, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[1])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[1]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[1]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_17_analyzer_1_array_crystal_width, yheight = channel_17_analyzer_1_array_crystal_height, xwidth = channel_17_analyzer_1_array_crystal_depth,
   priority = 1920.2, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[2])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[2]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[2]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_17_analyzer_1_array_crystal_width, yheight = channel_17_analyzer_1_array_crystal_height, xwidth = channel_17_analyzer_1_array_crystal_depth,
   priority = 1920.3, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[3])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[3]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[3]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_17_analyzer_1_array_crystal_width, yheight = channel_17_analyzer_1_array_crystal_height, xwidth = channel_17_analyzer_1_array_crystal_depth,
   priority = 1920.4, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[4])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[4]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[4]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_17_analyzer_1_array_crystal_width, yheight = channel_17_analyzer_1_array_crystal_height, xwidth = channel_17_analyzer_1_array_crystal_depth,
   priority = 1920.5, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[5])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[5]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[5]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_17_analyzer_1_array_crystal_width, yheight = channel_17_analyzer_1_array_crystal_height, xwidth = channel_17_analyzer_1_array_crystal_depth,
   priority = 1920.6, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[6])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[6]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[6]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_17_analyzer_1_array_crystal_width, yheight = channel_17_analyzer_1_array_crystal_height, xwidth = channel_17_analyzer_1_array_crystal_depth,
   priority = 1920.7, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[7])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[7]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[7]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_17_analyzer_1_array_crystal_width, yheight = channel_17_analyzer_1_array_crystal_height, xwidth = channel_17_analyzer_1_array_crystal_depth,
   priority = 1920.8, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[8])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[8]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[8]) RELATIVE channel_17_analyzer_1_rotated


COMPONENT channel_17_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_17_analyzer_1_center

COMPONENT channel_17_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[17]*DEG2RAD)) RELATIVE channel_17_analyzer_2_center
  ROTATED (0,-analyzer_theta[17],0) RELATIVE channel_17_analyzer_2_center

COMPONENT channel_17_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_17_analyzer_2_array_crystal_width, yheight = channel_17_analyzer_2_array_crystal_height, xwidth = channel_17_analyzer_2_array_crystal_depth,
   priority = 1921.0, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[0])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[0]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[0]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_17_analyzer_2_array_crystal_width, yheight = channel_17_analyzer_2_array_crystal_height, xwidth = channel_17_analyzer_2_array_crystal_depth,
   priority = 1921.1, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[1])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[1]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[1]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_17_analyzer_2_array_crystal_width, yheight = channel_17_analyzer_2_array_crystal_height, xwidth = channel_17_analyzer_2_array_crystal_depth,
   priority = 1921.2, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[2])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[2]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[2]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_17_analyzer_2_array_crystal_width, yheight = channel_17_analyzer_2_array_crystal_height, xwidth = channel_17_analyzer_2_array_crystal_depth,
   priority = 1921.3, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[3])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[3]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[3]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_17_analyzer_2_array_crystal_width, yheight = channel_17_analyzer_2_array_crystal_height, xwidth = channel_17_analyzer_2_array_crystal_depth,
   priority = 1921.4, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[4])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[4]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[4]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_17_analyzer_2_array_crystal_width, yheight = channel_17_analyzer_2_array_crystal_height, xwidth = channel_17_analyzer_2_array_crystal_depth,
   priority = 1921.5, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[5])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[5]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[5]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_17_analyzer_2_array_crystal_width, yheight = channel_17_analyzer_2_array_crystal_height, xwidth = channel_17_analyzer_2_array_crystal_depth,
   priority = 1921.6, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[6])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[6]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[6]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_17_analyzer_2_array_crystal_width, yheight = channel_17_analyzer_2_array_crystal_height, xwidth = channel_17_analyzer_2_array_crystal_depth,
   priority = 1921.7, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[7])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[7]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[7]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_17_analyzer_2_array_crystal_width, yheight = channel_17_analyzer_2_array_crystal_height, xwidth = channel_17_analyzer_2_array_crystal_depth,
   priority = 1921.8, material_string = "PG_analyzer")
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[8])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[8]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[8]) RELATIVE channel_17_analyzer_2_rotated


COMPONENT channel_17_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=1907.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_17_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_17_analyzer_2_center

COMPONENT channel_17_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=1901,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_17_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_17_cave2_cyl1

COMPONENT channel_17_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=1906,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_17_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_17_cave2_cyl1

COMPONENT channel_17_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=1907,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_17_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_17_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_17 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_17_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_17_analyzer_1_center

COMPONENT inter_analyzer_colimator_17_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1925,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
  ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT inter_analyzer_colimator_17_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1926,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
  ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT inter_analyzer_colimator_17_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1927,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
  ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT inter_analyzer_colimator_17_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1928,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
  ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT inter_analyzer_colimator_17_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=1929,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
  ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT diffraction_detector_17_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1931,material_string="Exit")
  AT (0,0,0) RELATIVE channel_17_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT spec_detector_17_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=1932,material_string="Exit")
  AT (0,0,0) RELATIVE channel_17_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_17_analyzer_2_center

COMPONENT channel_18_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=2000,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_18
  ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT channel_18_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=2005,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_18
  ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT channel_18_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=2002,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_18
  ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT channel_18_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=2003,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_18
  ROTATED (0,0,0) RELATIVE kidney_channel_18


COMPONENT channel_18_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_18

COMPONENT channel_18_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[18]*DEG2RAD)) RELATIVE channel_18_analyzer_1_center
  ROTATED (0,180-analyzer_theta[18],0) RELATIVE channel_18_analyzer_1_center

COMPONENT channel_18_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_18_analyzer_1_array_crystal_width, yheight = channel_18_analyzer_1_array_crystal_height, xwidth = channel_18_analyzer_1_array_crystal_depth,
   priority = 2020.0, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[0])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[0]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[0]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_18_analyzer_1_array_crystal_width, yheight = channel_18_analyzer_1_array_crystal_height, xwidth = channel_18_analyzer_1_array_crystal_depth,
   priority = 2020.1, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[1])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[1]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[1]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_18_analyzer_1_array_crystal_width, yheight = channel_18_analyzer_1_array_crystal_height, xwidth = channel_18_analyzer_1_array_crystal_depth,
   priority = 2020.2, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[2])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[2]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[2]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_18_analyzer_1_array_crystal_width, yheight = channel_18_analyzer_1_array_crystal_height, xwidth = channel_18_analyzer_1_array_crystal_depth,
   priority = 2020.3, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[3])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[3]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[3]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_18_analyzer_1_array_crystal_width, yheight = channel_18_analyzer_1_array_crystal_height, xwidth = channel_18_analyzer_1_array_crystal_depth,
   priority = 2020.4, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[4])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[4]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[4]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_18_analyzer_1_array_crystal_width, yheight = channel_18_analyzer_1_array_crystal_height, xwidth = channel_18_analyzer_1_array_crystal_depth,
   priority = 2020.5, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[5])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[5]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[5]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_18_analyzer_1_array_crystal_width, yheight = channel_18_analyzer_1_array_crystal_height, xwidth = channel_18_analyzer_1_array_crystal_depth,
   priority = 2020.6, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[6])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[6]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[6]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_18_analyzer_1_array_crystal_width, yheight = channel_18_analyzer_1_array_crystal_height, xwidth = channel_18_analyzer_1_array_crystal_depth,
   priority = 2020.7, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[7])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[7]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[7]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_18_analyzer_1_array_crystal_width, yheight = channel_18_analyzer_1_array_crystal_height, xwidth = channel_18_analyzer_1_array_crystal_depth,
   priority = 2020.8, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[8])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[8]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[8]) RELATIVE channel_18_analyzer_1_rotated


COMPONENT channel_18_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_18_analyzer_1_center

COMPONENT channel_18_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[18]*DEG2RAD)) RELATIVE channel_18_analyzer_2_center
  ROTATED (0,-analyzer_theta[18],0) RELATIVE channel_18_analyzer_2_center

COMPONENT channel_18_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_18_analyzer_2_array_crystal_width, yheight = channel_18_analyzer_2_array_crystal_height, xwidth = channel_18_analyzer_2_array_crystal_depth,
   priority = 2021.0, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[0])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[0]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[0]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_18_analyzer_2_array_crystal_width, yheight = channel_18_analyzer_2_array_crystal_height, xwidth = channel_18_analyzer_2_array_crystal_depth,
   priority = 2021.1, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[1])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[1]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[1]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_18_analyzer_2_array_crystal_width, yheight = channel_18_analyzer_2_array_crystal_height, xwidth = channel_18_analyzer_2_array_crystal_depth,
   priority = 2021.2, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[2])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[2]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[2]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_18_analyzer_2_array_crystal_width, yheight = channel_18_analyzer_2_array_crystal_height, xwidth = channel_18_analyzer_2_array_crystal_depth,
   priority = 2021.3, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[3])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[3]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[3]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_18_analyzer_2_array_crystal_width, yheight = channel_18_analyzer_2_array_crystal_height, xwidth = channel_18_analyzer_2_array_crystal_depth,
   priority = 2021.4, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[4])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[4]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[4]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_18_analyzer_2_array_crystal_width, yheight = channel_18_analyzer_2_array_crystal_height, xwidth = channel_18_analyzer_2_array_crystal_depth,
   priority = 2021.5, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[5])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[5]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[5]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_18_analyzer_2_array_crystal_width, yheight = channel_18_analyzer_2_array_crystal_height, xwidth = channel_18_analyzer_2_array_crystal_depth,
   priority = 2021.6, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[6])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[6]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[6]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_18_analyzer_2_array_crystal_width, yheight = channel_18_analyzer_2_array_crystal_height, xwidth = channel_18_analyzer_2_array_crystal_depth,
   priority = 2021.7, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[7])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[7]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[7]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_18_analyzer_2_array_crystal_width, yheight = channel_18_analyzer_2_array_crystal_height, xwidth = channel_18_analyzer_2_array_crystal_depth,
   priority = 2021.8, material_string = "PG_analyzer")
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[8])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[8]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[8]) RELATIVE channel_18_analyzer_2_rotated


COMPONENT channel_18_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=2007.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_18_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_18_analyzer_2_center

COMPONENT channel_18_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=2001,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_18_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_18_cave2_cyl1

COMPONENT channel_18_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=2006,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_18_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_18_cave2_cyl1

COMPONENT channel_18_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=2007,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_18_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_18_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_18 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_18_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_18_analyzer_1_center

COMPONENT inter_analyzer_colimator_18_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2025,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
  ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT inter_analyzer_colimator_18_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2026,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
  ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT inter_analyzer_colimator_18_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2027,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
  ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT inter_analyzer_colimator_18_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2028,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
  ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT inter_analyzer_colimator_18_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2029,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
  ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT diffraction_detector_18_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=2031,material_string="Exit")
  AT (0,0,0) RELATIVE channel_18_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT spec_detector_18_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=2032,material_string="Exit")
  AT (0,0,0) RELATIVE channel_18_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_18_analyzer_2_center

COMPONENT channel_19_cave1_box1 = Union_box(
    xwidth= kidney_cave1_box1_width1,yheight=kidney_cave1_box1_height1,zdepth=kidney_cave1_box1_depth,
    xwidth2= kidney_cave1_box1_width2,yheight2=kidney_cave1_box1_height2,
    priority=2100,material_string="Vacuum")
  AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_19
  ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT channel_19_cave1_box2 = Union_box(
    xwidth= kidney_cave1_box2_width1,yheight=kidney_cave1_box2_height1,zdepth=kidney_cave1_box2_depth,
    xwidth2= kidney_cave1_box2_width2,yheight2=kidney_cave1_box2_height2,
    priority=2105,material_string="Vacuum")
  AT (kidney_cave1_box2_x_offset,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_19
  ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT channel_19_cave1_box3 = Union_box(
    xwidth= kidney_cave1_box3_width1,yheight=kidney_cave1_box3_height1,zdepth=kidney_cave1_box3_depth,
    xwidth2= kidney_cave1_box3_width2,yheight2=kidney_cave1_box3_height2,
    priority=2102,material_string="Vacuum")
  AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_19
  ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT channel_19_cave1_cyl1 = Union_cylinder(
    radius= kidney_cave1_cyl1_radius,yheight=kidney_cave1_cyl1_height,
    priority=2103,material_string="Vacuum")
  AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_19
  ROTATED (0,0,0) RELATIVE kidney_channel_19


COMPONENT channel_19_analyzer_1_center = Arm()
  AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_19

COMPONENT channel_19_analyzer_1_rotated = Arm()
  AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[19]*DEG2RAD)) RELATIVE channel_19_analyzer_1_center
  ROTATED (0,180-analyzer_theta[19],0) RELATIVE channel_19_analyzer_1_center

COMPONENT channel_19_analyzer_1_array_crystal_array_0 = Union_box(
   zdepth = channel_19_analyzer_1_array_crystal_width, yheight = channel_19_analyzer_1_array_crystal_height, xwidth = channel_19_analyzer_1_array_crystal_depth,
   priority = 2120.0, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[0])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[0]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[0]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_1 = Union_box(
   zdepth = channel_19_analyzer_1_array_crystal_width, yheight = channel_19_analyzer_1_array_crystal_height, xwidth = channel_19_analyzer_1_array_crystal_depth,
   priority = 2120.1, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[1])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[1]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[1]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_2 = Union_box(
   zdepth = channel_19_analyzer_1_array_crystal_width, yheight = channel_19_analyzer_1_array_crystal_height, xwidth = channel_19_analyzer_1_array_crystal_depth,
   priority = 2120.2, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[2])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[2]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[2]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_3 = Union_box(
   zdepth = channel_19_analyzer_1_array_crystal_width, yheight = channel_19_analyzer_1_array_crystal_height, xwidth = channel_19_analyzer_1_array_crystal_depth,
   priority = 2120.3, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[3])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[3]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[3]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_4 = Union_box(
   zdepth = channel_19_analyzer_1_array_crystal_width, yheight = channel_19_analyzer_1_array_crystal_height, xwidth = channel_19_analyzer_1_array_crystal_depth,
   priority = 2120.4, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[4])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[4]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[4]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_5 = Union_box(
   zdepth = channel_19_analyzer_1_array_crystal_width, yheight = channel_19_analyzer_1_array_crystal_height, xwidth = channel_19_analyzer_1_array_crystal_depth,
   priority = 2120.5, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[5])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[5]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[5]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_6 = Union_box(
   zdepth = channel_19_analyzer_1_array_crystal_width, yheight = channel_19_analyzer_1_array_crystal_height, xwidth = channel_19_analyzer_1_array_crystal_depth,
   priority = 2120.6, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[6])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[6]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[6]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_7 = Union_box(
   zdepth = channel_19_analyzer_1_array_crystal_width, yheight = channel_19_analyzer_1_array_crystal_height, xwidth = channel_19_analyzer_1_array_crystal_depth,
   priority = 2120.7, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[7])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[7]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[7]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_8 = Union_box(
   zdepth = channel_19_analyzer_1_array_crystal_width, yheight = channel_19_analyzer_1_array_crystal_height, xwidth = channel_19_analyzer_1_array_crystal_depth,
   priority = 2120.8, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[8])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[8]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[8]) RELATIVE channel_19_analyzer_1_rotated


COMPONENT channel_19_analyzer_2_center = Arm()
  AT (-analyzer_seperation,0,0) RELATIVE channel_19_analyzer_1_center

COMPONENT channel_19_analyzer_2_rotated = Arm()
  AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[19]*DEG2RAD)) RELATIVE channel_19_analyzer_2_center
  ROTATED (0,-analyzer_theta[19],0) RELATIVE channel_19_analyzer_2_center

COMPONENT channel_19_analyzer_2_array_crystal_array_0 = Union_box(
   zdepth = channel_19_analyzer_2_array_crystal_width, yheight = channel_19_analyzer_2_array_crystal_height, xwidth = channel_19_analyzer_2_array_crystal_depth,
   priority = 2121.0, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[0])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[0]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[0]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_1 = Union_box(
   zdepth = channel_19_analyzer_2_array_crystal_width, yheight = channel_19_analyzer_2_array_crystal_height, xwidth = channel_19_analyzer_2_array_crystal_depth,
   priority = 2121.1, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[1])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[1]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[1]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_2 = Union_box(
   zdepth = channel_19_analyzer_2_array_crystal_width, yheight = channel_19_analyzer_2_array_crystal_height, xwidth = channel_19_analyzer_2_array_crystal_depth,
   priority = 2121.2, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[2])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[2]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[2]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_3 = Union_box(
   zdepth = channel_19_analyzer_2_array_crystal_width, yheight = channel_19_analyzer_2_array_crystal_height, xwidth = channel_19_analyzer_2_array_crystal_depth,
   priority = 2121.3, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[3])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[3]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[3]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_4 = Union_box(
   zdepth = channel_19_analyzer_2_array_crystal_width, yheight = channel_19_analyzer_2_array_crystal_height, xwidth = channel_19_analyzer_2_array_crystal_depth,
   priority = 2121.4, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[4])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[4]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[4]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_5 = Union_box(
   zdepth = channel_19_analyzer_2_array_crystal_width, yheight = channel_19_analyzer_2_array_crystal_height, xwidth = channel_19_analyzer_2_array_crystal_depth,
   priority = 2121.5, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[5])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[5]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[5]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_6 = Union_box(
   zdepth = channel_19_analyzer_2_array_crystal_width, yheight = channel_19_analyzer_2_array_crystal_height, xwidth = channel_19_analyzer_2_array_crystal_depth,
   priority = 2121.6, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[6])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[6]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[6]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_7 = Union_box(
   zdepth = channel_19_analyzer_2_array_crystal_width, yheight = channel_19_analyzer_2_array_crystal_height, xwidth = channel_19_analyzer_2_array_crystal_depth,
   priority = 2121.7, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[7])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[7]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[7]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_8 = Union_box(
   zdepth = channel_19_analyzer_2_array_crystal_width, yheight = channel_19_analyzer_2_array_crystal_height, xwidth = channel_19_analyzer_2_array_crystal_depth,
   priority = 2121.8, material_string = "PG_analyzer")
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[8])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[8]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[8]) RELATIVE channel_19_analyzer_2_rotated


COMPONENT channel_19_cave2_cyl1 = Union_cylinder(
    radius= kidney_cave2_cyl1_radius,yheight=kidney_cave2_cyl1_height,
    priority=2107.5,material_string="Vacuum")
  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_19_analyzer_2_center
  ROTATED (0,0,0) RELATIVE channel_19_analyzer_2_center

COMPONENT channel_19_cave2_box1 = Union_box(
    xwidth= kidney_cave2_box1_width1,yheight=kidney_cave2_box1_height1,zdepth=kidney_cave2_box1_depth,
    xwidth2= kidney_cave2_box1_width2,yheight2=kidney_cave2_box1_height2,
    priority=2101,material_string="Vacuum")
  AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_19_cave2_cyl1
  ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_19_cave2_cyl1

COMPONENT channel_19_cave2_box2 = Union_box(
    xwidth= kidney_cave2_box2_width1,yheight=kidney_cave2_box2_height1,zdepth=kidney_cave2_box2_depth,
    xwidth2= kidney_cave2_box2_width2,yheight2=kidney_cave2_box2_height2,
    priority=2106,material_string="Vacuum")
  AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_19_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_19_cave2_cyl1

COMPONENT channel_19_cave2_box3 = Union_box(
    xwidth= kidney_cave2_box3_width1,yheight=kidney_cave2_box3_height1,zdepth=kidney_cave2_box3_depth,
    xwidth2= kidney_cave2_box3_width2,yheight2=kidney_cave2_box3_height2,
    priority=2107,material_string="Vacuum")
  AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_19_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_19_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_19 = Arm()
  AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_19_analyzer_1_center
  ROTATED (0,0,0)  RELATIVE channel_19_analyzer_1_center

COMPONENT inter_analyzer_colimator_19_blade_0 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2125,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
  ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT inter_analyzer_colimator_19_blade_1 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2126,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
  ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT inter_analyzer_colimator_19_blade_2 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2127,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
  ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT inter_analyzer_colimator_19_blade_3 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2128,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
  ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT inter_analyzer_colimator_19_blade_4 = Union_box(
    xwidth= inter_analyzer_colimator_width, yheight=inter_analyzer_colimator_height, zdepth=inter_analyzer_colimator_depth,
    priority=2129,material_string="Collimator_gad")
  AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
  ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT diffraction_detector_19_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=2131,material_string="Exit")
  AT (0,0,0) RELATIVE channel_19_cave1_cyl1
  ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT spec_detector_19_exit_volume = Union_box(
    xwidth=2.01*detector_radius, yheight=1.01*detector_height, zdepth = 0.001,
    priority=2132,material_string="Exit")
  AT (0,0,0) RELATIVE channel_19_cave2_cyl1
  ROTATED (0,0,0) RELATIVE channel_19_analyzer_2_center

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

COMPONENT diffraction_detector_3 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_3")
  AT (0,0,0) RELATIVE diffraction_detector_3_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_3_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =3;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_3 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_3")
  AT (0,0,0) RELATIVE spec_detector_3_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_3_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =3;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_4 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_4")
  AT (0,0,0) RELATIVE diffraction_detector_4_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_4_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =4;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_4 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_4")
  AT (0,0,0) RELATIVE spec_detector_4_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_4_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =4;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_5 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_5")
  AT (0,0,0) RELATIVE diffraction_detector_5_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_5_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =5;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_5 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_5")
  AT (0,0,0) RELATIVE spec_detector_5_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_5_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =5;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_6 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_6")
  AT (0,0,0) RELATIVE diffraction_detector_6_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_6_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =6;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_6 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_6")
  AT (0,0,0) RELATIVE spec_detector_6_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_6_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =6;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_7 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_7")
  AT (0,0,0) RELATIVE diffraction_detector_7_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_7_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =7;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_7 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_7")
  AT (0,0,0) RELATIVE spec_detector_7_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_7_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =7;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_8 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_8")
  AT (0,0,0) RELATIVE diffraction_detector_8_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_8_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =8;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_8 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_8")
  AT (0,0,0) RELATIVE spec_detector_8_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_8_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =8;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_9 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_9")
  AT (0,0,0) RELATIVE diffraction_detector_9_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_9_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =9;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_9 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_9")
  AT (0,0,0) RELATIVE spec_detector_9_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_9_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =9;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_10 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_10")
  AT (0,0,0) RELATIVE diffraction_detector_10_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_10_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =10;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_10 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_10")
  AT (0,0,0) RELATIVE spec_detector_10_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_10_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =10;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_11 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_11")
  AT (0,0,0) RELATIVE diffraction_detector_11_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_11_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =11;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_11 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_11")
  AT (0,0,0) RELATIVE spec_detector_11_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_11_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =11;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_12 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_12")
  AT (0,0,0) RELATIVE diffraction_detector_12_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_12_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =12;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_12 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_12")
  AT (0,0,0) RELATIVE spec_detector_12_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_12_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =12;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_13 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_13")
  AT (0,0,0) RELATIVE diffraction_detector_13_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_13_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =13;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_13 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_13")
  AT (0,0,0) RELATIVE spec_detector_13_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_13_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =13;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_14 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_14")
  AT (0,0,0) RELATIVE diffraction_detector_14_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_14_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =14;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_14 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_14")
  AT (0,0,0) RELATIVE spec_detector_14_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_14_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =14;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_15 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_15")
  AT (0,0,0) RELATIVE diffraction_detector_15_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_15_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =15;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_15 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_15")
  AT (0,0,0) RELATIVE spec_detector_15_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_15_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =15;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_16 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_16")
  AT (0,0,0) RELATIVE diffraction_detector_16_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_16_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =16;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_16 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_16")
  AT (0,0,0) RELATIVE spec_detector_16_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_16_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =16;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_17 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_17")
  AT (0,0,0) RELATIVE diffraction_detector_17_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_17_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =17;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_17 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_17")
  AT (0,0,0) RELATIVE spec_detector_17_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_17_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =17;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_18 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_18")
  AT (0,0,0) RELATIVE diffraction_detector_18_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_18_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =18;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_18 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_18")
  AT (0,0,0) RELATIVE spec_detector_18_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_18_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =18;
      detector_channel_diff =-1;
      detector_found = 1;
    }
  %}

COMPONENT diffraction_detector_19 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="diff_detector_19")
  AT (0,0,0) RELATIVE diffraction_detector_19_exit_volume
  ROTATED (0,0,0) RELATIVE diffraction_detector_19_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =19;
      detector_channel_spec =-1;
      detector_found = 1;
    }
  %}

COMPONENT spec_detector_19 = PSD_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nx=5, ny=5, filename="spec_detector_19")
  AT (0,0,0) RELATIVE spec_detector_19_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_19_exit_volume
  GROUP detector_group
  EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =19;
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

COMPONENT spec_detector_history_3 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_3")
  WHEN(detector_channel_spec == 3 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_3_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_3_exit_volume
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

COMPONENT spec_detector_history_4 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_4")
  WHEN(detector_channel_spec == 4 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_4_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_4_exit_volume
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

COMPONENT spec_detector_history_5 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_5")
  WHEN(detector_channel_spec == 5 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_5_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_5_exit_volume
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

COMPONENT spec_detector_history_6 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_6")
  WHEN(detector_channel_spec == 6 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_6_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_6_exit_volume
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

COMPONENT spec_detector_history_7 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_7")
  WHEN(detector_channel_spec == 7 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_7_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_7_exit_volume
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

COMPONENT spec_detector_history_8 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_8")
  WHEN(detector_channel_spec == 8 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_8_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_8_exit_volume
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

COMPONENT spec_detector_history_9 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_9")
  WHEN(detector_channel_spec == 9 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_9_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_9_exit_volume
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

COMPONENT spec_detector_history_10 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_10")
  WHEN(detector_channel_spec == 10 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_10_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_10_exit_volume
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

COMPONENT spec_detector_history_11 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_11")
  WHEN(detector_channel_spec == 11 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_11_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_11_exit_volume
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

COMPONENT spec_detector_history_12 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_12")
  WHEN(detector_channel_spec == 12 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_12_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_12_exit_volume
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

COMPONENT spec_detector_history_13 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_13")
  WHEN(detector_channel_spec == 13 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_13_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_13_exit_volume
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

COMPONENT spec_detector_history_14 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_14")
  WHEN(detector_channel_spec == 14 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_14_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_14_exit_volume
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

COMPONENT spec_detector_history_15 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_15")
  WHEN(detector_channel_spec == 15 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_15_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_15_exit_volume
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

COMPONENT spec_detector_history_16 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_16")
  WHEN(detector_channel_spec == 16 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_16_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_16_exit_volume
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

COMPONENT spec_detector_history_17 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_17")
  WHEN(detector_channel_spec == 17 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_17_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_17_exit_volume
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

COMPONENT spec_detector_history_18 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_18")
  WHEN(detector_channel_spec == 18 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_18_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_18_exit_volume
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

COMPONENT spec_detector_history_19 = extend_monitor(
    xwidth=2.0*detector_radius, yheight=1.0*detector_height,restore_neutron=1,
    nb=DOUBLE_MAX_VOLUME_HISTORY_LENGTH, filename="spec_detector_history_19")
  WHEN(detector_channel_spec == 19 && detector_found ==1)
  AT (0,0,0) RELATIVE spec_detector_19_exit_volume
  ROTATED (0,0,0) RELATIVE spec_detector_19_exit_volume
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


