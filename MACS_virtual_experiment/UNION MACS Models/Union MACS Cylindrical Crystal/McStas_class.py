try: # check whether python knows about 'basestring'
   basestring
except NameError: # no, it doesn't (it's Python3); use 'str' instead
   print('Detected python 3')
   basestring=str

class declare_variable:
    def __init__(self,*args,**kwargs):
        self.type = args[0]
        self.name = str(args[1])
        if "value" in kwargs:
            self.value_set = 1
            self.value = kwargs["value"]
        else:
            self.value_set = 0
        if "array" in kwargs:
            self.vector = kwargs["array"]
        else:
            self.vector = 0

    def write_line(self,fo):
        if self.value_set == 0 and self.vector == 0:
            fo.write("%s %s;" % (self.type, self.name))
        if self.value_set == 1 and self.vector == 0:
            if self.type == "int":
                fo.write("%s %s = %d;" % (self.type, self.name, self.value))
            else:
                fo.write("%s %s = %f;" % (self.type, self.name, self.value))
        if self.value_set == 0 and self.vector != 0:
            fo.write("%s %s[%d];" % (self.type, self.name, self.vector))
        if self.value_set == 1 and self.vector != 0:
            fo.write("%s %s[%d] = {" % (self.type, self.name, self.vector))
            for i in range(0,len(self.value)-1):
                fo.write("%f," % self.value[i])
            fo.write("%f};" % self.value[-1])

class McStas_part:

    def __init__(self,name):
        self.name = name
        self.declare_list = []
        self.initialize_section = "// Start of initialize for generated " + name + "\n"
        self.trace_section = "// Start of trace section for generated " + name + "\n"

    def add_declare_var(self,*args,**kwargs):
        # type of variable, name of variable, options described in declare_variable class
        self.declare_list.append(declare_variable(*args,**kwargs))

    def append_initialize(self,string):
        self.initialize_section = self.initialize_section + string + "\n"
    
    def append_initialize_no_new_line(self,string):
        self.initialize_section = self.initialize_section + string
    
    def append_trace(self,string):
        self.trace_section = self.trace_section + string + "\n"
    
    def append_trace_no_new_line(self,string):
        self.trace_section = self.trace_section + string
    
    def write_c_files(self):
        fo = open("./generated_includes/" + self.name + "_declare.c","w")
        fo.write("// declare section for %s \n" % self.name)
        fo.close()
        fo = open("./generated_includes/" + self.name + "_declare.c","a")
        for dec_line in self.declare_list:
            dec_line.write_line(fo)
            fo.write("\n")
        fo.close()
        
        fo = open("./generated_includes/" + self.name + "_initialize.c","w")
        fo.write(self.initialize_section)
        fo.close()

        fo = open("./generated_includes/" + self.name + "_trace.c","w")
        fo.write(self.trace_section)
        fo.close()


# temporary position, will probably make a seperate function file
def append_vertical_crystal_array(mcstas_class_instance, name, crystal_width, crystal_height, crystal_depth, number_of_crystals, total_height, radius_of_curvature, arm_name, material_name, priority_start, priority_end,x_position_string="0",y_position_string="0",z_position_string="0",x_rotation_string="0",y_rotation_string="0",z_rotation_string="0",number_of_crystals_value=0):

    if isinstance(crystal_width, basestring): # If crystal width is a string, assume the variable have already been declared
        crystal_width_name = crystal_width
    else:
        crystal_width_name = name + "_crystal_width"
        mcstas_class_instance.add_declare_var("double",crystal_width_name,value=crystal_width)

    if isinstance(crystal_height, basestring): # If crystal width is a string, assume the variable have already been declared
        crystal_height_name = crystal_height
    else:
        crystal_height_name = name + "_crystal_height"
        mcstas_class_instance.add_declare_var("double",crystal_height_name,value=crystal_height)

    if isinstance(crystal_depth, basestring): # If crystal width is a string, assume the variable have already been declared
        crystal_depth_name = crystal_depth
    else:
        crystal_depth_name = name + "_crystal_depth"
        mcstas_class_instance.add_declare_var("double",crystal_depth_name,value=crystal_depth)

    if isinstance(number_of_crystals, basestring): # If crystal width is a string, assume the variable have already been declared
        number_of_crystals_name = number_of_crystals
        if number_of_crystals_value == 0:
            print "ERROR, append_vertical_crystal_array, if a string is given for number_of_crystals, a number_of_crystals_value is needed as well"
        else:
            number_of_crystals_value = number_of_crystals_value
    else:
        number_of_crystals_value = number_of_crystals
        number_of_crystals_name = name + "_number_of_crystals"
        mcstas_class_instance.add_declare_var("int",number_of_crystals_name,value=number_of_crystals)

    if isinstance(total_height, basestring): # If crystal width is a string, assume the variable have already been declared
        total_height_name = total_height
    else:
        total_height_name = name + "_total_height"
        mcstas_class_instance.add_declare_var("double",total_height_name,value=total_height)

    if isinstance(radius_of_curvature, basestring): # If crystal width is a string, assume the variable have already been declared
        radius_of_curvature_name = radius_of_curvature
    else:
        radius_of_curvature_name = name + "_radius_of_curvature"
        mcstas_class_instance.add_declare_var("double",radius_of_curvature_name,value=radius_of_curvature)
    
    #mcstas_class_instance.add_declare_var("double",name + "_crystal_height",value=crystal_height)
    #mcstas_class_instance.add_declare_var("double",name + "_crystal_depth",value=crystal_depth)
    #mcstas_class_instance.add_declare_var("int",name + "_number_of_crystals",value=number_of_crystals)
    #mcstas_class_instance.add_declare_var("double",name + "_total_height",value=total_height)
    #mcstas_class_instance.add_declare_var("double",name + "_radius_of_curvature",value=radius_of_curvature)
    
    delta_priority = (priority_end - priority_start)/number_of_crystals_value;
    

    # the depth of each crystal is along the vector between it's center and the focal point.
    # the center of the surface of each crystal traces the circle of curvature
    mcstas_class_instance.add_declare_var("double",name + "_effective_radius_of_curvature")
    # the total height is between the top and bottom corner of the top and bottom crystal
    #mcstas_class_instance.append_initialize(name + "_effective_radius_of_curvature = " + name + "_crystal_depth + " + name + "_radius_of_curvature;")
    mcstas_class_instance.append_initialize(name + "_effective_radius_of_curvature = " + crystal_depth_name + "+" + radius_of_curvature_name + ";")
    
    mcstas_class_instance.add_declare_var("double",name + "_theta_max")
    # may need other input methods than total_height, as it is probabily not known to often.
    # calculate theta max from geometry considerations
    mcstas_class_instance.append_initialize(name + "_theta_max = asin(" + total_height_name + "/sqrt((2*" + radius_of_curvature_name + " + 2*" + crystal_depth_name + ")*(2*" + radius_of_curvature_name + " + 2*" + crystal_depth_name + ") + " + crystal_height_name + "*" + crystal_height_name + ") - atan(" + crystal_height_name + "/(2*" + radius_of_curvature_name + " + 2*" + crystal_depth_name + ")));")
    # calculate rotation for each crystal, called theta
    mcstas_class_instance.add_declare_var("double",name + "_delta_theta")
    mcstas_class_instance.append_initialize(name + "_delta_theta = (2*" + name + "_theta_max) / ((double) " + number_of_crystals_name + " - 1);")
    # the theta array describes the angle between the horizontal and the vector between the crystal center and focal point
    mcstas_class_instance.add_declare_var("double",name + "_theta",array=number_of_crystals)
    mcstas_class_instance.add_declare_var("int",name + "_iterate")
    mcstas_class_instance.append_initialize("for (" + name + "_iterate=0;" + name + "_iterate<" + str(number_of_crystals) + ";" + name + "_iterate++)")
    mcstas_class_instance.append_initialize("    " + name + "_theta[" + name + "_iterate] = " + name + "_delta_theta * (double) " + name + "_iterate - " + name + "_theta_max;")
    

    for i in range(0,number_of_crystals_value):
    
        full_x_position_string = x_position_string + " + " + name + "_effective_radius_of_curvature * (1-cos(" + name + "_theta[" + str(i) + "]))"
        full_y_position_string = y_position_string + " + " + name + "_effective_radius_of_curvature * sin(" + name + "_theta[" + str(i) + "])"
        full_z_position_string = z_position_string
        
        full_x_rotation_string = x_rotation_string
        full_y_rotation_string = y_rotation_string
        full_z_rotation_string = z_rotation_string + "-RAD2DEG*" + name + "_theta[" + str(i) + "]"
    
        mcstas_class_instance.append_trace("COMPONENT " + name + "_crystal_array_" + str(i) + " = Union_box(")
        mcstas_class_instance.append_trace("   zdepth = " + crystal_width_name + ", yheight = " + crystal_height_name + ", xwidth = " + crystal_depth_name + ",")
        mcstas_class_instance.append_trace("   priority = " + str(i*delta_priority + priority_start) + ", material_string = \"" + material_name + "\")")
        #mcstas_class_instance.append_trace("AT (" + name + "_effective_radius_of_curvature * (1-cos(" + name + "_theta[" + str(i) + "]))," + name + "_effective_radius_of_curvature * sin(" + name + "_theta[" + str(i) + "]),0) RELATIVE " + arm_name)
        mcstas_class_instance.append_trace("AT (" + full_x_position_string + "," + full_y_position_string + "," + full_z_position_string + ") RELATIVE " + arm_name)
        #mcstas_class_instance.append_trace("ROTATED (0,0,-RAD2DEG*" + name + "_theta[" + str(i) + "]) RELATIVE " + arm_name + "\n")
        mcstas_class_instance.append_trace("ROTATED (" + full_x_rotation_string + "," + full_y_rotation_string + "," + full_z_rotation_string + ") RELATIVE " + arm_name + "\n")



def append_vertical_crystal_mono_array(mcstas_class_instance, name, crystal_width, crystal_height, crystal_depth, number_of_crystals, total_height, radius_of_curvature, arm_name, material_name, priority_start, support_arch_thickness, support_arch_width, support_arch_spacing, misalignment_deg, priority_end,x_position_string="0",y_position_string="0",z_position_string="0",x_rotation_string="0",y_rotation_string="0",z_rotation_string="0",number_of_crystals_value=0,mask_height_diviation=0,):

    if isinstance(crystal_width, basestring): # If crystal width is a string, assume the variable have already been declared
        crystal_width_name = crystal_width
    else:
        crystal_width_name = name + "_crystal_width"
        mcstas_class_instance.add_declare_var("double",crystal_width_name,value=crystal_width)

    if isinstance(crystal_height, basestring): # If crystal width is a string, assume the variable have already been declared
        crystal_height_name = crystal_height
    else:
        crystal_height_name = name + "_crystal_height"
        mcstas_class_instance.add_declare_var("double",crystal_height_name,value=crystal_height)

    if isinstance(crystal_depth, basestring): # If crystal width is a string, assume the variable have already been declared
        crystal_depth_name = crystal_depth
    else:
        crystal_depth_name = name + "_crystal_depth"
        mcstas_class_instance.add_declare_var("double",crystal_depth_name,value=crystal_depth)

    if isinstance(number_of_crystals, basestring): # If crystal width is a string, assume the variable have already been declared
        number_of_crystals_name = number_of_crystals
        if number_of_crystals_value == 0:
            print "ERROR, append_vertical_crystal_array, if a string is given for number_of_crystals, a number_of_crystals_value is needed as well"
        else:
            number_of_crystals_value = number_of_crystals_value
    else:
        number_of_crystals_value = number_of_crystals
        number_of_crystals_name = name + "_number_of_crystals"
        mcstas_class_instance.add_declare_var("int",number_of_crystals_name,value=number_of_crystals)

    if isinstance(total_height, basestring): # If crystal width is a string, assume the variable have already been declared
        total_height_name = total_height
    else:
        total_height_name = name + "_total_height"
        mcstas_class_instance.add_declare_var("double",total_height_name,value=total_height)

    if isinstance(radius_of_curvature, basestring): # If crystal width is a string, assume the variable have already been declared
        radius_of_curvature_name = radius_of_curvature
    else:
        radius_of_curvature_name = name + "_radius_of_curvature"
        mcstas_class_instance.add_declare_var("double",radius_of_curvature_name,value=radius_of_curvature)
    
    if isinstance(misalignment_deg, basestring): # If crystal width is a string, assume the variable have already been declared
        misalignment_deg_name = misalignment_deg
    else:
        misalignment_deg_name = name + "_misalignment_deg"
        mcstas_class_instance.add_declare_var("double",misalignment_deg_name,value=misalignment_deg)
    
    #mcstas_class_instance.add_declare_var("double",name + "_crystal_height",value=crystal_height)
    #mcstas_class_instance.add_declare_var("double",name + "_crystal_depth",value=crystal_depth)
    #mcstas_class_instance.add_declare_var("int",name + "_number_of_crystals",value=number_of_crystals)
    #mcstas_class_instance.add_declare_var("double",name + "_total_height",value=total_height)
    #mcstas_class_instance.add_declare_var("double",name + "_radius_of_curvature",value=radius_of_curvature)
    
    delta_priority = (priority_end - priority_start)/(number_of_crystals_value+3); # 3 extra needed for support arch
    

    # the depth of each crystal is along the vector between it's center and the focal point.
    # the center of the surface of each crystal traces the circle of curvature
    mcstas_class_instance.add_declare_var("double",name + "_effective_radius_of_curvature")
    # the total height is between the top and bottom corner of the top and bottom crystal
    #mcstas_class_instance.append_initialize(name + "_effective_radius_of_curvature = " + name + "_crystal_depth + " + name + "_radius_of_curvature;")
    mcstas_class_instance.append_initialize(name + "_effective_radius_of_curvature = " + crystal_depth_name + "+" + radius_of_curvature_name + ";")
    
    mcstas_class_instance.add_declare_var("double",name + "_theta_max")
    # may need other input methods than total_height, as it is probabily not known to often.
    # calculate theta max from geometry considerations
    mcstas_class_instance.append_initialize(name + "_theta_max = asin(" + total_height_name + "/sqrt((2*" + radius_of_curvature_name + " + 2*" + crystal_depth_name + ")*(2*" + radius_of_curvature_name + " + 2*" + crystal_depth_name + ") + " + crystal_height_name + "*" + crystal_height_name + ") - atan(" + crystal_height_name + "/(2*" + radius_of_curvature_name + " + 2*" + crystal_depth_name + ")));")
    # calculate rotation for each crystal, called theta
    mcstas_class_instance.add_declare_var("double",name + "_delta_theta")
    mcstas_class_instance.append_initialize(name + "_delta_theta = (2*" + name + "_theta_max) / ((double) " + number_of_crystals_name + " - 1);")
    # the theta array describes the angle between the horizontal and the vector between the crystal center and focal point
    mcstas_class_instance.add_declare_var("double",name + "_theta",array=number_of_crystals)
    mcstas_class_instance.add_declare_var("int",name + "_iterate")
    mcstas_class_instance.append_initialize("for (" + name + "_iterate=0;" + name + "_iterate<" + str(number_of_crystals) + ";" + name + "_iterate++)")
    mcstas_class_instance.append_initialize("    " + name + "_theta[" + name + "_iterate] = " + name + "_delta_theta * (double) " + name + "_iterate - " + name + "_theta_max;")
    

    mcstas_class_instance.append_trace("COMPONENT " + name + "_crystal_array_arm = Arm()")
    mcstas_class_instance.append_trace("AT (" + x_position_string + "," + y_position_string + "," + z_position_string + ") RELATIVE " + arm_name)
    mcstas_class_instance.append_trace("ROTATED (" + x_rotation_string + "," + y_rotation_string + "," + z_rotation_string + ") RELATIVE " + arm_name + "\n")

    for i in range(0,number_of_crystals_value):
    
        full_x_position_string = name + "_effective_radius_of_curvature * (1-cos(" + name + "_theta[" + str(i) + "]))"
        full_y_position_string = name + "_effective_radius_of_curvature * sin(" + name + "_theta[" + str(i) + "])"
        full_z_position_string = "0"
        
        full_x_rotation_string = "0"
        full_y_rotation_string = misalignment_deg_name + "*randnorm()"
        full_z_rotation_string = "-RAD2DEG*" + name + "_theta[" + str(i) + "] + " + misalignment_deg_name + "*randnorm()"
    
        mcstas_class_instance.append_trace("COMPONENT " + name + "_crystal_array_" + str(i) + " = Union_box(")
        mcstas_class_instance.append_trace("   zdepth = " + crystal_width_name + ", yheight = " + crystal_height_name + ", xwidth = " + crystal_depth_name + ", p_interact=0.0,")
        mcstas_class_instance.append_trace("   priority = " + str((i+3)*delta_priority + priority_start) + ", material_string = \"" + material_name + "\")")
        #mcstas_class_instance.append_trace("AT (" + name + "_effective_radius_of_curvature * (1-cos(" + name + "_theta[" + str(i) + "]))," + name + "_effective_radius_of_curvature * sin(" + name + "_theta[" + str(i) + "]),0) RELATIVE " + arm_name)
        mcstas_class_instance.append_trace("AT (" + full_x_position_string + "," + full_y_position_string + "," + full_z_position_string + ") RELATIVE " + name + "_crystal_array_arm")
        #mcstas_class_instance.append_trace("ROTATED (0,0,-RAD2DEG*" + name + "_theta[" + str(i) + "]) RELATIVE " + arm_name + "\n")
        mcstas_class_instance.append_trace("ROTATED (" + full_x_rotation_string + "," + full_y_rotation_string + "," + full_z_rotation_string + ") RELATIVE " + name + "_crystal_array_arm")
        mcstas_class_instance.append_trace("")


    if isinstance(support_arch_thickness, basestring): # If crystal width is a string, assume the variable have already been declared
        support_arch_thickness_name = support_arch_thickness
    else:
        support_arch_thickness_name = name + "_support_arch_thickness"
        mcstas_class_instance.add_declare_var("double",support_arch_thickness_name,value=support_arch_thickness)

    if isinstance(support_arch_width, basestring): # If crystal width is a string, assume the variable have already been declared
        support_arch_width_name = support_arch_width
    else:
        support_arch_width_name = name + "_support_arch_width"
        mcstas_class_instance.add_declare_var("double",support_arch_width_name,value=support_arch_width)

    if isinstance(support_arch_spacing, basestring): # If crystal width is a string, assume the variable have already been declared
        support_arch_spacing_name = support_arch_spacing
    else:
        support_arch_spacing_name = name + "_support_arch_spacing"
        mcstas_class_instance.add_declare_var("double",support_arch_spacing_name,value=support_arch_spacing)

    mcstas_class_instance.add_declare_var("double",name + "_arch_outer_radius")
    mcstas_class_instance.add_declare_var("double",name + "_arch_inner_radius")
    mcstas_class_instance.append_initialize(name + "_arch_inner_radius = " + radius_of_curvature_name + "+" + crystal_depth_name + "+" + support_arch_spacing_name + ";")
    mcstas_class_instance.append_initialize(name + "_arch_outer_radius = " + name + "_arch_inner_radius + " + support_arch_thickness_name + ";")
    '''
    mcstas_class_instance.add_declare_var("double",name + "_box_offset")
    #mcstas_class_instance.append_initialize(name + "_box_offset = " + name + "_arch_inner_radius * (1-cos(" + name + "_theta_max + " + name + "_delta_theta));")
    mcstas_class_instance.append_initialize(name + "_box_offset = " + radius_of_curvature_name + " * (1-cos(" + name + "_theta_max + 2*" + name + "_delta_theta));")
    '''
    mcstas_class_instance.add_declare_var("double",name + "_mask_depth")
    mcstas_class_instance.append_initialize(name + "_mask_depth = " + radius_of_curvature_name + " * (1-cos(" + name + "_theta_max + 2*" + name + "_delta_theta));")


    #mcstas_class_instance.append_trace("COMPONENT " + name + "_mounting_arch_arm = Arm()")
    #mcstas_class_instance.append_trace("AT (" + x_position_string + "," + y_position_string + "," + z_position_string + ") RELATIVE " + arm_name)
    #mcstas_class_instance.append_trace("ROTATED (" + x_rotation_string + "," + y_rotation_string + "," + z_rotation_string + ") RELATIVE " + arm_name + "\n")
    mcstas_class_instance.append_trace("")
    mcstas_class_instance.append_trace("COMPONENT " + name + "_crystal_array_mounting_arch = Union_cylinder(")
    mcstas_class_instance.append_trace("  radius = " + name + "_arch_outer_radius, yheight =" + support_arch_width_name + ",")
    mcstas_class_instance.append_trace("  priority = " + str(0*delta_priority + priority_start) + ", material_string = \"Al_mono\")")
    mcstas_class_instance.append_trace("AT (" + radius_of_curvature_name + ",0,0) RELATIVE " + name + "_crystal_array_arm")
    mcstas_class_instance.append_trace("ROTATED (90,0,0) RELATIVE " + name + "_crystal_array_arm")
    mcstas_class_instance.append_trace("")
    mcstas_class_instance.append_trace("COMPONENT " + name + "_crystal_array_mounting_arch_vacuum = Union_cylinder(")
    mcstas_class_instance.append_trace("  radius = " + name + "_arch_inner_radius, yheight = 0.0002+" + crystal_width_name + ",")
    mcstas_class_instance.append_trace("  priority = " + str(1*delta_priority + priority_start) + ", material_string = \"Vacuum\")")
    mcstas_class_instance.append_trace("AT (" + radius_of_curvature_name + ",0,0) RELATIVE " + name + "_crystal_array_arm")
    mcstas_class_instance.append_trace("ROTATED (90,0,0) RELATIVE " + name + "_crystal_array_arm")
    mcstas_class_instance.append_trace("")
    mcstas_class_instance.append_trace("COMPONENT " + name + "_crystal_array_mounting_arch_mask = Union_box(")
    #mcstas_class_instance.append_trace("  xwidth = 1.05*" + crystal_width_name + ", yheight = " + total_height_name + ", zdepth = " + name + "_mask_depth,")
    #mcstas_class_instance.append_trace("  zdepth = 1.05*" + crystal_width_name + ", yheight = 1.1*" + total_height_name + ", xwidth = " + name + "_mask_depth,")
    mcstas_class_instance.append_trace("  zdepth = 0.0004+" + crystal_width_name + ", yheight = 1.2*" + total_height_name + " + " + str(mask_height_diviation) + ", xwidth = 0.05,")
    mcstas_class_instance.append_trace("  priority = " + str(2*delta_priority + priority_start) + ",visualize=0, ")
    mcstas_class_instance.append_trace("  mask_string=\"" + name + "_crystal_array_mounting_arch," + name +  "_crystal_array_mounting_arch_vacuum\")")
    mcstas_class_instance.append_trace("AT (1.05*" + name + "_mask_depth-0.025,0,0) RELATIVE " + name + "_crystal_array_arm")
    mcstas_class_instance.append_trace("ROTATED (0,0,0) RELATIVE " + name + "_crystal_array_arm")
    mcstas_class_instance.append_trace("")

    '''
    mcstas_class_instance.append_trace("COMPONENT " + name + "_crystal_array_mounting_arch_vacuum2 = Union_box(")
    mcstas_class_instance.append_trace("  xwidth = 2*" + name + "_arch_outer_radius+0.0001, yheight = 2*" + name + "_arch_outer_radius+0.01, zdepth = 43*" + crystal_width_name + ",")
    mcstas_class_instance.append_trace("  priority = " + str(2*delta_priority + priority_start) + ", material_string = \"Vacuum\", visualize=0)")
    mcstas_class_instance.append_trace("AT (" + radius_of_curvature_name + "+" + name + "_box_offset,0,0) RELATIVE " + name + "_crystal_array_arm")
    mcstas_class_instance.append_trace("ROTATED (0,0,0) RELATIVE " + name + "_crystal_array_arm")
    mcstas_class_instance.append_trace("")
    '''
    
    


