//## test4.cc
//## This file is intended to test the operation of the CCCC feature
//## of being able to define an options file which affects the 
//## execution of CCCC in a number of ways.
//## There is a companion file test4.opt which modifies the behaviour 
//## of CCCC in the following ways:
//##   display format of L_C has one decimal place;
//##   threshold for L_C to be displayed in red is 3.0 
//##   default dialect assignment for extension .cc is set to c++.test4
//##   treatment of the pseudo-keyword TEST4_EXT in dialect c++.test4 is 
//##   to be ignored.
//## Ultimately, the format of the opt file needs to be documented,
//## for the time being users keen to try the facility out may be
//## able to infer enough to apply it to their needs by reading
//## rules.mak to see how to invoke cccc with the opt file
//## output, and by diffing test4.opt against vanilla.opt,
//## which contains the version of the opt file obtained when 
//## the compiled-in default options (see cccc_opt.cc) are
//## exported using 'cccc --opt_outfile=vanilla.opt'

class Test4a
{
public:
	TEST4_EXT void dummy()
	{
		// Comment line one
		// Comment line two
		int i;
		i = 1;
		i = 2;
		i = 3;
	}
};

