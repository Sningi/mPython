import fileinput                    	#  1 #  1 #  1
                                        			#  2 #  2 #  2
for line in fileinput.input():	#  3 #  3 #  3
    line= line.rstrip()                  	#  4 #  4 #  4
    num=fileinput.lineno()            	#  5 #  5 #  5
    print('%-40s # %2i' % (line,num))    #  6 #  6 #  6
