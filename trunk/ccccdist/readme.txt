README.TXT for CCCC version 3.0
===============================

This is a new version of the program CCCC (C and C++ Code Counter).  This 
program exists to analyze and report measurements on source code in C, C++
and Java.  The languages Ada83 and Ada95, which were supported in previous
versions are presently not supported, although support for these languages 
may be restored at some time in the future if there is demonstrable demand.
The Internet site for CCCC development is: http://cccc.sourceforge.net 
(hosting kindly donated by sourceforge.net to whom I am grateful).

CCCC is a command line tool, originally implemented for Linux and other 
POSIX-style platforms, but also buildable on the Win32 platform.  
Files to be analyzed are listed (typically on the command line, although 
support does exist for the list of files to be read from standard input.   
The program analyzes the files and generates a one or more reports in HTML 
format on the content.

This distribution is intended to be a single package containing everything
which is required to compile and install CCCC on either a POSIX or Win32 
platform.  Whereas previous distributions contained only a single directory,
containing the source code of CCCC, this distribution is divided into a 
number of subdirectories, with the following contents:
* A full distribution of the Purdue Compiler Construction Toolset (PCCTS) by
  Terence Parr and others, now maintained by Tom Moog of Polhode Inc. 
  PCCTS is required to compile CCCC: in the past the distribution has relied
  on the existence of a PCCTS package on the compilation platform, while this
  distribution chooses to include it as part of CCCC's own package.
* The source of a new version of CCCC, which I hope will turn out to be more
  efficient, accurate and useful than previous versions, although it is very
  similar in spirit and interface.
* The source of an accessory program called CcccDevStudioAddIn.dll which 
  provides integration between the command line CCCC program and the 
  Microsoft Visual Studio IDE (version 5.0 or 6.0).
* A directory of minimal test cases for the command line CCCC tool.
* Miscellaneous makefiles and Microsoft Visual Studio workspace and project
  files to support building, testing and installing the software under 
  POSIX and Win32.

The pccts directory contains software for which I am not the original 
author.  The software has been placed in the public domain, with
the expectation that appropriate credit will be given for use.  

As of version 3.pre62, the recommended way of building the software is by
using the BAT and SH scripts in the top directory of the distribution as
appropriate for your platform.  On Win32, the script build_w32vc.bat 
builds the software with Microsoft Visual C++ version 5 or 6 (locations
within the script may need to be modified according to which you have
and whether it is installed at the default position in the filesystem).
Thee is also a script to build the software using the Borland command
line C++ compiler, although the version this builds presently crashes
during the execution of the unit tests in the distribution (patches to
fix this would be gratefully received).  On Linux and similar platforms
the shell script build_posixgcc.sh should work. 

If you wish to try the Visual Studio integration, there are some additional
steps to perform.  Within Visual Studio, select menu option 
"Tools/Customize", then click on the "Macros and AddIns" tab.  Within this 
control, click on the "Browse" button, change the file type from "*.dsm" 
to "*.dll", browse to the directory C:\Program Files\CCCC, and select the
CcccDevStudioAddIn.dll file before pressing "OK".  This should cause 
Visual Studio to load the add-in, and a tool bar should appear with 
four different icons containing the text "C4" and six white icons.  The
fourth of the "C4" icons has a device like a steering wheel on it and is 
used to configure the add-in.  Press this icon and a dialog box should appear
containing 8 strings, of which the first should read 
"C:\Program Files\CCCC\CCCC.EXE" and the next should contain some path to 
Internet Explorer (IEXPLORE.EXE).  Verify that the path to IE is valid 
(or substitute a path to Netscape, Mozilla, Opera or any other HTML browser 
according to your tastes).

The add-in can now be used to run CCCC on either the current file (the "C4" 
icon with a "f" subscript), all files in the current active project ("C4"
with a "p" subscript), or all files in any project in the current workspace 
("C4" with a "w" subscript).  The add-in can also have up to 6 other commands
set in the configuration dialog defined above, which will be bound to
the six blank icons on the toolbar.  Each command will run in character
mode and standard output from each should be captured and redirected to
the "Macros" tab in the Visual Studio Output window.  This may be useful
for programs which generate messages in the same format as the Visual 
Studio compiler error messages or Find in Files, as conformance to this
format allows Visual Studio to implement the convenient "jump to source
line" behaviour.  I have on my list of issues for CCCC to convert the 
parser syntax error messages to this format, but it hasn't happened yet.
The add-in is experimental at this stage.  I am aware of some issues 
with projects in locations with spaces in the path, and I have also found
that the logic I am using to deduce the home directories of .dsp and .dsw 
files is not always correct.

As well as the addin, the current version includes a directory which contains
a script to build a wizard-style installer for the program under Win32.
Binary releases of the software made using this directory may be released
in the near future.  The binary release provides Windows start menu access
to a DOS prompt set up with an environment to enable CCCC to be run 
easily, and also provides a shortcut to the HTML documentation. The 
installer can be built from the supplied scripts using the splendid free
Inno Setup and Extensions packages by Martin Laan (Inno Setup) and Jordan
Russell (extensions), available from http://www.jrsoftware.org.

Previous versions of CCCC have been released like PCCTS into the public
domain with no restrictions, other than the pious hope that should anyone
base a derivative work on it I will be given due credit.  I have considered
applying the GNU Public License, not because of any strong adherence to the
GPL philosophy so much as because GPL is something of a standard for
free software and it may ease the work of software collators for people to
adhere to the standard.  I would be interested in hearing from such people
whether GPL would or would not make CCCC a more likely candidate for 
inclusion in distributions.

CCCC was originally developed as a proof-of-concept tool for some ideas 
relating to software metrics which I was investigating as an academic 
research project.  I have now completed the project and been awarded 
my PhD.  I am still getting a steady stream of enquiries about CCCC, 
and I am keen to put out a high quality reference version of the software
as a way of thanking the people who have assisted me by participating in
the various stages of my research.  The research project is described at
http://www-chs.ecu.edu.au/~tlittlef.  This page includes a link to a 
downloadable PDF version of the PhD thesis.

I am grateful to a number of people for assistance on this project, including
Terence Parr and his co-workers, and Tom Moog for the development and ongoing
maintenance of the excellent PCCTS tool; my academic supervisor, Dr Thomas
O'Neill; a number of developers who have contributed source patches; and
many people who have mailed me with constructive suggestions or merely to 
confirm that they were using the tool. Feedback on the value or otherwise 
of CCCC is always welcome, and will help me to decide how much effort I put 
into maintaining it over the coming months and years.  


Tim Littlefair (tim_littlefair@hotmail.com)
updated November 2001
--------------

This and future distributions of CCCC and related tools should be
available for the forseeable future from http://cccc.sourceforge.net












