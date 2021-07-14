// Start of initialize for generated analysator_test
first_array_effective_radius_of_curvature = first_array_crystal_depth+first_array_radius_of_curvature;
first_array_theta_max = asin(first_array_total_height/sqrt((2*first_array_radius_of_curvature + 2*first_array_crystal_depth)*(2*first_array_radius_of_curvature + 2*first_array_crystal_depth) + first_array_crystal_height*first_array_crystal_height) - atan(first_array_crystal_height/(2*first_array_radius_of_curvature + 2*first_array_crystal_depth)));
first_array_delta_theta = (2*first_array_theta_max) / ((double) first_array_number_of_crystals - 1);
for (first_array_iterate=0;first_array_iterate<11;first_array_iterate++)
    first_array_theta[first_array_iterate] = first_array_delta_theta * (double) first_array_iterate - first_array_theta_max;
