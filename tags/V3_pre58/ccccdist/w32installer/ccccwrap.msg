CCCC is a command line tool.  
This window has been set up with a command path to allow the tool to 
be run conveniently.

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
