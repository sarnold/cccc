CCCC is a command line tool.  
This window has been set up with a macro 'cccc' to allow the tool to 
be run conveniently. By default the CCCC program will generate its primary
output to the file .cccc\cccc.html (relative to the working directory).
The macro is configured to start the user's default browser on this file
after completion of the execution of the CCCC program, if options are used
to redirect the primary output, the browser window should be ignored.

Useful example commands:
cccc *.h *.cpp
	CCCC will analyze all .h and .cpp files in the current directory.
cccc --lang=c.ansi *.h *.c
	CCCC will analyze all .h and .c files in the current directory as
	ANSI C (by default .h files would be analyzed as C++).
dir . /b /s | cccc -
	CCCC will accept a list of files on standard input and analyze all 
	listed files with recognized extensions.  
cccc --help
	CCCC will generate a usage message on standard output.
explorer .cccc\cccc.html
	Start Internet Explorer on the top level HTML report from a run of CCCC.
