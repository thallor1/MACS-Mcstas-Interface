// Start of initialize for generated monochromator

// Monochromator geometry
mono_theta = asin(mono_q/2./sqrt(EM/2.0717));

// distance from source to monochromator to calculate the focal point
dist_mono_L0	  = MPL-MPD/tan(2.*mono_theta) + L0_delta;
dist_mono_L0_pos = MPL-MPD/tan(2.*mono_theta);

// distance from monochromator to sample
dist_mono_L1     = 0.9+MPD/sin(2.*mono_theta) + L1_delta;
dist_mono_L1_pos = 0.9+MPD/sin(2.*mono_theta);

R_at_reference =2.*dist_mono_L0*dist_mono_L1/(dist_mono_L0+dist_mono_L1);
hight_at_reference =sin(asin((mono_crystal_width+0.001)/2./R_at_reference)*mono_number_of_rows)*R_at_reference*2.;

if (VF == 1) {
  mono_Radius_of_curvature = 2.*dist_mono_L0*dist_mono_L1*sin(mono_theta)/(dist_mono_L0+dist_mono_L1);
} else {
  mono_Radius_of_curvature = 300;
}

mono_total_height = sin(asin((mono_crystal_width+0.001)/2./mono_Radius_of_curvature)*mono_number_of_rows)*mono_Radius_of_curvature*2.;

mono_phi = atan2(sin(2.*mono_theta),cos(2.*mono_theta)+dist_mono_L1/dist_mono_L0);

for (mono_iterate=0;mono_iterate<21;mono_iterate++) {
  if (HF == 1)
    mono_psi[mono_iterate] =-(atan2(sin(mono_phi),cos(mono_phi)+mono_column_displacements[mono_iterate]/dist_mono_L0)-mono_theta)*RAD2DEG;
  else {
    mono_psi[mono_iterate] = 0;
    mono_phi = mono_theta;
  }
}

// Monochromator reflectivity and mosaicity
mono_mosaicity_eta_rad = mono_mosaicity_eta_min/60*DEG2RAD;
mono_g = 1/(2*sqrt(PI)*mono_mosaicity_eta_rad);
mono_Ff=4*mono_b_c;
mono_Vc = sqrt(3)*2.464*2.464*6.711/2;
mono_Qc = lambda*lambda*lambda*mono_Ff*mono_Ff/(mono_Vc*mono_Vc*sin(2*mono_theta));
mono_t = mono_crystal_thickness/sin(mono_theta);
mono_xx = sqrt(2)*mono_g*mono_Qc*mono_t;
mono_r0 = mono_xx/(mono_xx+1);
mono_mosaicity_rad = mono_mosaicity_eta_rad*sqrt(8*log(2+sqrt(2)*mono_g*mono_Qc*mono_crystal_thickness));
mono_mosaicity_min = mono_mosaicity_rad*RAD2DEG*60;
mono_array0_effective_radius_of_curvature = mono_array0_crystal_depth+mono_Radius_of_curvature;
mono_array0_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array0_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array0_crystal_depth) + mono_array0_crystal_height*mono_array0_crystal_height) - atan(mono_array0_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array0_crystal_depth)));
mono_array0_delta_theta = (2*mono_array0_theta_max) / ((double) mono_array0_number_of_crystals - 1);
for (mono_array0_iterate=0;mono_array0_iterate<17;mono_array0_iterate++)
    mono_array0_theta[mono_array0_iterate] = mono_array0_delta_theta * (double) mono_array0_iterate - mono_array0_theta_max;
mono_array0_arch_inner_radius = mono_Radius_of_curvature+mono_array0_crystal_depth+mono_array0_support_arch_spacing;
mono_array0_arch_outer_radius = mono_array0_arch_inner_radius + mono_array0_support_arch_thickness;
mono_array0_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array0_theta_max + 2*mono_array0_delta_theta));
mono_array1_effective_radius_of_curvature = mono_array1_crystal_depth+mono_Radius_of_curvature;
mono_array1_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array1_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array1_crystal_depth) + mono_array1_crystal_height*mono_array1_crystal_height) - atan(mono_array1_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array1_crystal_depth)));
mono_array1_delta_theta = (2*mono_array1_theta_max) / ((double) mono_array1_number_of_crystals - 1);
for (mono_array1_iterate=0;mono_array1_iterate<17;mono_array1_iterate++)
    mono_array1_theta[mono_array1_iterate] = mono_array1_delta_theta * (double) mono_array1_iterate - mono_array1_theta_max;
mono_array1_arch_inner_radius = mono_Radius_of_curvature+mono_array1_crystal_depth+mono_array1_support_arch_spacing;
mono_array1_arch_outer_radius = mono_array1_arch_inner_radius + mono_array1_support_arch_thickness;
mono_array1_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array1_theta_max + 2*mono_array1_delta_theta));
mono_array2_effective_radius_of_curvature = mono_array2_crystal_depth+mono_Radius_of_curvature;
mono_array2_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array2_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array2_crystal_depth) + mono_array2_crystal_height*mono_array2_crystal_height) - atan(mono_array2_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array2_crystal_depth)));
mono_array2_delta_theta = (2*mono_array2_theta_max) / ((double) mono_array2_number_of_crystals - 1);
for (mono_array2_iterate=0;mono_array2_iterate<17;mono_array2_iterate++)
    mono_array2_theta[mono_array2_iterate] = mono_array2_delta_theta * (double) mono_array2_iterate - mono_array2_theta_max;
mono_array2_arch_inner_radius = mono_Radius_of_curvature+mono_array2_crystal_depth+mono_array2_support_arch_spacing;
mono_array2_arch_outer_radius = mono_array2_arch_inner_radius + mono_array2_support_arch_thickness;
mono_array2_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array2_theta_max + 2*mono_array2_delta_theta));
mono_array3_effective_radius_of_curvature = mono_array3_crystal_depth+mono_Radius_of_curvature;
mono_array3_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array3_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array3_crystal_depth) + mono_array3_crystal_height*mono_array3_crystal_height) - atan(mono_array3_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array3_crystal_depth)));
mono_array3_delta_theta = (2*mono_array3_theta_max) / ((double) mono_array3_number_of_crystals - 1);
for (mono_array3_iterate=0;mono_array3_iterate<17;mono_array3_iterate++)
    mono_array3_theta[mono_array3_iterate] = mono_array3_delta_theta * (double) mono_array3_iterate - mono_array3_theta_max;
mono_array3_arch_inner_radius = mono_Radius_of_curvature+mono_array3_crystal_depth+mono_array3_support_arch_spacing;
mono_array3_arch_outer_radius = mono_array3_arch_inner_radius + mono_array3_support_arch_thickness;
mono_array3_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array3_theta_max + 2*mono_array3_delta_theta));
mono_array4_effective_radius_of_curvature = mono_array4_crystal_depth+mono_Radius_of_curvature;
mono_array4_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array4_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array4_crystal_depth) + mono_array4_crystal_height*mono_array4_crystal_height) - atan(mono_array4_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array4_crystal_depth)));
mono_array4_delta_theta = (2*mono_array4_theta_max) / ((double) mono_array4_number_of_crystals - 1);
for (mono_array4_iterate=0;mono_array4_iterate<17;mono_array4_iterate++)
    mono_array4_theta[mono_array4_iterate] = mono_array4_delta_theta * (double) mono_array4_iterate - mono_array4_theta_max;
mono_array4_arch_inner_radius = mono_Radius_of_curvature+mono_array4_crystal_depth+mono_array4_support_arch_spacing;
mono_array4_arch_outer_radius = mono_array4_arch_inner_radius + mono_array4_support_arch_thickness;
mono_array4_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array4_theta_max + 2*mono_array4_delta_theta));
mono_array5_effective_radius_of_curvature = mono_array5_crystal_depth+mono_Radius_of_curvature;
mono_array5_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array5_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array5_crystal_depth) + mono_array5_crystal_height*mono_array5_crystal_height) - atan(mono_array5_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array5_crystal_depth)));
mono_array5_delta_theta = (2*mono_array5_theta_max) / ((double) mono_array5_number_of_crystals - 1);
for (mono_array5_iterate=0;mono_array5_iterate<17;mono_array5_iterate++)
    mono_array5_theta[mono_array5_iterate] = mono_array5_delta_theta * (double) mono_array5_iterate - mono_array5_theta_max;
mono_array5_arch_inner_radius = mono_Radius_of_curvature+mono_array5_crystal_depth+mono_array5_support_arch_spacing;
mono_array5_arch_outer_radius = mono_array5_arch_inner_radius + mono_array5_support_arch_thickness;
mono_array5_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array5_theta_max + 2*mono_array5_delta_theta));
mono_array6_effective_radius_of_curvature = mono_array6_crystal_depth+mono_Radius_of_curvature;
mono_array6_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array6_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array6_crystal_depth) + mono_array6_crystal_height*mono_array6_crystal_height) - atan(mono_array6_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array6_crystal_depth)));
mono_array6_delta_theta = (2*mono_array6_theta_max) / ((double) mono_array6_number_of_crystals - 1);
for (mono_array6_iterate=0;mono_array6_iterate<17;mono_array6_iterate++)
    mono_array6_theta[mono_array6_iterate] = mono_array6_delta_theta * (double) mono_array6_iterate - mono_array6_theta_max;
mono_array6_arch_inner_radius = mono_Radius_of_curvature+mono_array6_crystal_depth+mono_array6_support_arch_spacing;
mono_array6_arch_outer_radius = mono_array6_arch_inner_radius + mono_array6_support_arch_thickness;
mono_array6_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array6_theta_max + 2*mono_array6_delta_theta));
mono_array7_effective_radius_of_curvature = mono_array7_crystal_depth+mono_Radius_of_curvature;
mono_array7_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array7_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array7_crystal_depth) + mono_array7_crystal_height*mono_array7_crystal_height) - atan(mono_array7_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array7_crystal_depth)));
mono_array7_delta_theta = (2*mono_array7_theta_max) / ((double) mono_array7_number_of_crystals - 1);
for (mono_array7_iterate=0;mono_array7_iterate<17;mono_array7_iterate++)
    mono_array7_theta[mono_array7_iterate] = mono_array7_delta_theta * (double) mono_array7_iterate - mono_array7_theta_max;
mono_array7_arch_inner_radius = mono_Radius_of_curvature+mono_array7_crystal_depth+mono_array7_support_arch_spacing;
mono_array7_arch_outer_radius = mono_array7_arch_inner_radius + mono_array7_support_arch_thickness;
mono_array7_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array7_theta_max + 2*mono_array7_delta_theta));
mono_array8_effective_radius_of_curvature = mono_array8_crystal_depth+mono_Radius_of_curvature;
mono_array8_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array8_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array8_crystal_depth) + mono_array8_crystal_height*mono_array8_crystal_height) - atan(mono_array8_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array8_crystal_depth)));
mono_array8_delta_theta = (2*mono_array8_theta_max) / ((double) mono_array8_number_of_crystals - 1);
for (mono_array8_iterate=0;mono_array8_iterate<17;mono_array8_iterate++)
    mono_array8_theta[mono_array8_iterate] = mono_array8_delta_theta * (double) mono_array8_iterate - mono_array8_theta_max;
mono_array8_arch_inner_radius = mono_Radius_of_curvature+mono_array8_crystal_depth+mono_array8_support_arch_spacing;
mono_array8_arch_outer_radius = mono_array8_arch_inner_radius + mono_array8_support_arch_thickness;
mono_array8_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array8_theta_max + 2*mono_array8_delta_theta));
mono_array9_effective_radius_of_curvature = mono_array9_crystal_depth+mono_Radius_of_curvature;
mono_array9_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array9_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array9_crystal_depth) + mono_array9_crystal_height*mono_array9_crystal_height) - atan(mono_array9_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array9_crystal_depth)));
mono_array9_delta_theta = (2*mono_array9_theta_max) / ((double) mono_array9_number_of_crystals - 1);
for (mono_array9_iterate=0;mono_array9_iterate<17;mono_array9_iterate++)
    mono_array9_theta[mono_array9_iterate] = mono_array9_delta_theta * (double) mono_array9_iterate - mono_array9_theta_max;
mono_array9_arch_inner_radius = mono_Radius_of_curvature+mono_array9_crystal_depth+mono_array9_support_arch_spacing;
mono_array9_arch_outer_radius = mono_array9_arch_inner_radius + mono_array9_support_arch_thickness;
mono_array9_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array9_theta_max + 2*mono_array9_delta_theta));
mono_array10_effective_radius_of_curvature = mono_array10_crystal_depth+mono_Radius_of_curvature;
mono_array10_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array10_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array10_crystal_depth) + mono_array10_crystal_height*mono_array10_crystal_height) - atan(mono_array10_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array10_crystal_depth)));
mono_array10_delta_theta = (2*mono_array10_theta_max) / ((double) mono_array10_number_of_crystals - 1);
for (mono_array10_iterate=0;mono_array10_iterate<17;mono_array10_iterate++)
    mono_array10_theta[mono_array10_iterate] = mono_array10_delta_theta * (double) mono_array10_iterate - mono_array10_theta_max;
mono_array10_arch_inner_radius = mono_Radius_of_curvature+mono_array10_crystal_depth+mono_array10_support_arch_spacing;
mono_array10_arch_outer_radius = mono_array10_arch_inner_radius + mono_array10_support_arch_thickness;
mono_array10_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array10_theta_max + 2*mono_array10_delta_theta));
mono_array11_effective_radius_of_curvature = mono_array11_crystal_depth+mono_Radius_of_curvature;
mono_array11_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array11_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array11_crystal_depth) + mono_array11_crystal_height*mono_array11_crystal_height) - atan(mono_array11_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array11_crystal_depth)));
mono_array11_delta_theta = (2*mono_array11_theta_max) / ((double) mono_array11_number_of_crystals - 1);
for (mono_array11_iterate=0;mono_array11_iterate<17;mono_array11_iterate++)
    mono_array11_theta[mono_array11_iterate] = mono_array11_delta_theta * (double) mono_array11_iterate - mono_array11_theta_max;
mono_array11_arch_inner_radius = mono_Radius_of_curvature+mono_array11_crystal_depth+mono_array11_support_arch_spacing;
mono_array11_arch_outer_radius = mono_array11_arch_inner_radius + mono_array11_support_arch_thickness;
mono_array11_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array11_theta_max + 2*mono_array11_delta_theta));
mono_array12_effective_radius_of_curvature = mono_array12_crystal_depth+mono_Radius_of_curvature;
mono_array12_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array12_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array12_crystal_depth) + mono_array12_crystal_height*mono_array12_crystal_height) - atan(mono_array12_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array12_crystal_depth)));
mono_array12_delta_theta = (2*mono_array12_theta_max) / ((double) mono_array12_number_of_crystals - 1);
for (mono_array12_iterate=0;mono_array12_iterate<17;mono_array12_iterate++)
    mono_array12_theta[mono_array12_iterate] = mono_array12_delta_theta * (double) mono_array12_iterate - mono_array12_theta_max;
mono_array12_arch_inner_radius = mono_Radius_of_curvature+mono_array12_crystal_depth+mono_array12_support_arch_spacing;
mono_array12_arch_outer_radius = mono_array12_arch_inner_radius + mono_array12_support_arch_thickness;
mono_array12_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array12_theta_max + 2*mono_array12_delta_theta));
mono_array13_effective_radius_of_curvature = mono_array13_crystal_depth+mono_Radius_of_curvature;
mono_array13_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array13_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array13_crystal_depth) + mono_array13_crystal_height*mono_array13_crystal_height) - atan(mono_array13_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array13_crystal_depth)));
mono_array13_delta_theta = (2*mono_array13_theta_max) / ((double) mono_array13_number_of_crystals - 1);
for (mono_array13_iterate=0;mono_array13_iterate<17;mono_array13_iterate++)
    mono_array13_theta[mono_array13_iterate] = mono_array13_delta_theta * (double) mono_array13_iterate - mono_array13_theta_max;
mono_array13_arch_inner_radius = mono_Radius_of_curvature+mono_array13_crystal_depth+mono_array13_support_arch_spacing;
mono_array13_arch_outer_radius = mono_array13_arch_inner_radius + mono_array13_support_arch_thickness;
mono_array13_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array13_theta_max + 2*mono_array13_delta_theta));
mono_array14_effective_radius_of_curvature = mono_array14_crystal_depth+mono_Radius_of_curvature;
mono_array14_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array14_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array14_crystal_depth) + mono_array14_crystal_height*mono_array14_crystal_height) - atan(mono_array14_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array14_crystal_depth)));
mono_array14_delta_theta = (2*mono_array14_theta_max) / ((double) mono_array14_number_of_crystals - 1);
for (mono_array14_iterate=0;mono_array14_iterate<17;mono_array14_iterate++)
    mono_array14_theta[mono_array14_iterate] = mono_array14_delta_theta * (double) mono_array14_iterate - mono_array14_theta_max;
mono_array14_arch_inner_radius = mono_Radius_of_curvature+mono_array14_crystal_depth+mono_array14_support_arch_spacing;
mono_array14_arch_outer_radius = mono_array14_arch_inner_radius + mono_array14_support_arch_thickness;
mono_array14_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array14_theta_max + 2*mono_array14_delta_theta));
mono_array15_effective_radius_of_curvature = mono_array15_crystal_depth+mono_Radius_of_curvature;
mono_array15_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array15_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array15_crystal_depth) + mono_array15_crystal_height*mono_array15_crystal_height) - atan(mono_array15_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array15_crystal_depth)));
mono_array15_delta_theta = (2*mono_array15_theta_max) / ((double) mono_array15_number_of_crystals - 1);
for (mono_array15_iterate=0;mono_array15_iterate<17;mono_array15_iterate++)
    mono_array15_theta[mono_array15_iterate] = mono_array15_delta_theta * (double) mono_array15_iterate - mono_array15_theta_max;
mono_array15_arch_inner_radius = mono_Radius_of_curvature+mono_array15_crystal_depth+mono_array15_support_arch_spacing;
mono_array15_arch_outer_radius = mono_array15_arch_inner_radius + mono_array15_support_arch_thickness;
mono_array15_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array15_theta_max + 2*mono_array15_delta_theta));
mono_array16_effective_radius_of_curvature = mono_array16_crystal_depth+mono_Radius_of_curvature;
mono_array16_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array16_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array16_crystal_depth) + mono_array16_crystal_height*mono_array16_crystal_height) - atan(mono_array16_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array16_crystal_depth)));
mono_array16_delta_theta = (2*mono_array16_theta_max) / ((double) mono_array16_number_of_crystals - 1);
for (mono_array16_iterate=0;mono_array16_iterate<17;mono_array16_iterate++)
    mono_array16_theta[mono_array16_iterate] = mono_array16_delta_theta * (double) mono_array16_iterate - mono_array16_theta_max;
mono_array16_arch_inner_radius = mono_Radius_of_curvature+mono_array16_crystal_depth+mono_array16_support_arch_spacing;
mono_array16_arch_outer_radius = mono_array16_arch_inner_radius + mono_array16_support_arch_thickness;
mono_array16_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array16_theta_max + 2*mono_array16_delta_theta));
mono_array17_effective_radius_of_curvature = mono_array17_crystal_depth+mono_Radius_of_curvature;
mono_array17_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array17_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array17_crystal_depth) + mono_array17_crystal_height*mono_array17_crystal_height) - atan(mono_array17_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array17_crystal_depth)));
mono_array17_delta_theta = (2*mono_array17_theta_max) / ((double) mono_array17_number_of_crystals - 1);
for (mono_array17_iterate=0;mono_array17_iterate<17;mono_array17_iterate++)
    mono_array17_theta[mono_array17_iterate] = mono_array17_delta_theta * (double) mono_array17_iterate - mono_array17_theta_max;
mono_array17_arch_inner_radius = mono_Radius_of_curvature+mono_array17_crystal_depth+mono_array17_support_arch_spacing;
mono_array17_arch_outer_radius = mono_array17_arch_inner_radius + mono_array17_support_arch_thickness;
mono_array17_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array17_theta_max + 2*mono_array17_delta_theta));
mono_array18_effective_radius_of_curvature = mono_array18_crystal_depth+mono_Radius_of_curvature;
mono_array18_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array18_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array18_crystal_depth) + mono_array18_crystal_height*mono_array18_crystal_height) - atan(mono_array18_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array18_crystal_depth)));
mono_array18_delta_theta = (2*mono_array18_theta_max) / ((double) mono_array18_number_of_crystals - 1);
for (mono_array18_iterate=0;mono_array18_iterate<17;mono_array18_iterate++)
    mono_array18_theta[mono_array18_iterate] = mono_array18_delta_theta * (double) mono_array18_iterate - mono_array18_theta_max;
mono_array18_arch_inner_radius = mono_Radius_of_curvature+mono_array18_crystal_depth+mono_array18_support_arch_spacing;
mono_array18_arch_outer_radius = mono_array18_arch_inner_radius + mono_array18_support_arch_thickness;
mono_array18_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array18_theta_max + 2*mono_array18_delta_theta));
mono_array19_effective_radius_of_curvature = mono_array19_crystal_depth+mono_Radius_of_curvature;
mono_array19_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array19_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array19_crystal_depth) + mono_array19_crystal_height*mono_array19_crystal_height) - atan(mono_array19_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array19_crystal_depth)));
mono_array19_delta_theta = (2*mono_array19_theta_max) / ((double) mono_array19_number_of_crystals - 1);
for (mono_array19_iterate=0;mono_array19_iterate<17;mono_array19_iterate++)
    mono_array19_theta[mono_array19_iterate] = mono_array19_delta_theta * (double) mono_array19_iterate - mono_array19_theta_max;
mono_array19_arch_inner_radius = mono_Radius_of_curvature+mono_array19_crystal_depth+mono_array19_support_arch_spacing;
mono_array19_arch_outer_radius = mono_array19_arch_inner_radius + mono_array19_support_arch_thickness;
mono_array19_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array19_theta_max + 2*mono_array19_delta_theta));
mono_array20_effective_radius_of_curvature = mono_array20_crystal_depth+mono_Radius_of_curvature;
mono_array20_theta_max = asin(mono_total_height/sqrt((2*mono_Radius_of_curvature + 2*mono_array20_crystal_depth)*(2*mono_Radius_of_curvature + 2*mono_array20_crystal_depth) + mono_array20_crystal_height*mono_array20_crystal_height) - atan(mono_array20_crystal_height/(2*mono_Radius_of_curvature + 2*mono_array20_crystal_depth)));
mono_array20_delta_theta = (2*mono_array20_theta_max) / ((double) mono_array20_number_of_crystals - 1);
for (mono_array20_iterate=0;mono_array20_iterate<17;mono_array20_iterate++)
    mono_array20_theta[mono_array20_iterate] = mono_array20_delta_theta * (double) mono_array20_iterate - mono_array20_theta_max;
mono_array20_arch_inner_radius = mono_Radius_of_curvature+mono_array20_crystal_depth+mono_array20_support_arch_spacing;
mono_array20_arch_outer_radius = mono_array20_arch_inner_radius + mono_array20_support_arch_thickness;
mono_array20_mask_depth = mono_Radius_of_curvature * (1-cos(mono_array20_theta_max + 2*mono_array20_delta_theta));
