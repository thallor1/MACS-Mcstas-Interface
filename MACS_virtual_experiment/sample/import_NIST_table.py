def import_NIST_table(nist_file='nist_scattering_table.txt'):
	#Imports the nist table of scattering data as a python dictionary.
	# Columns represetn the following:
	#     Isotope 	conc 	Coh b 	Inc b 	Coh xs 	Inc xs 	Scatt xs 	Abs xs
	f = open(nist_file,'r')
	f_lines=f.readlines()
	f.close()
	lines={}
	column_labels=f_lines[0]
	for i in range(len(f_lines))[1:]:
		#Skipping the first line, append all of the results to our dictionary
		line = f_lines[i].strip('\r\n').split('\t')
		line_strip = [element.strip(' ') for element in line]
		element = line_strip[0]
		data = line_strip[1:] 
		lines[element]=data 
	return lines