README.TXT for CCCC version 3.0
===============================

This is a new version of the program CCCC (C and C++ Code Counter).  This 
program exists to analyze and report measurements on source code in C, C++
and Java.  The languages Ada83 and Ada95, which were supported in previous
versions are presently not supported, although support for these languages 
may be restored at some time in the future if there is demonstrable demand.
The Internet site for CCCC development is: http://cccc.netpedia.net 
(hosting kindly donated by netpedia.net/netpedia.com to whom I am grateful).

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
  distribution chooses to include it in the package.
* A directory of Win32 binaries to enable POSIX-style parts of the build, test
  and install process to run similarly on Win32.  Most of the binaries are from
  the CygWin B20 release of tools, although there is a version of GNU MAKE for
  Win32 which I obtained from www.mozilla.org.
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

The pccts and w32bin directories contain software for which I am not the 
original author.  Each of these directories also contains documentation of 
the provenance and licensing requirements of these programs.  In the case of
the pccts directory, the software has been placed in the public domain, with
the expectation that appropriate credit will be given for use.  In the case
of the w32bin directory, all software is released under the GNU Public 
License, implying that it may be freely redistributed under certain conditions
including the requirement that the redistributor ensures that the recipients
are at least provided with information on where the source code for the 
binaries can be obtained from.  As noted above, these binaries are part of 
the CygWin B20 distribution of GNU POSIX utilities compiled using their port
of the GNU C compiler to the Win32 platform.  Source for the tools and the 
compiler may be downloaded from http://sourceware.cygnus.com.

The facilities for building, testing and installing the programs in this 
distribution are presently somewhat crude and less consistent than I
would like in the long term.  I have tried to make the two platform families
(i.e. POSIX and Win32) use the same tools as far as possible, and where this
is not possible to use differing tools which operate in similar ways.  Hence
the Win32 build does not use a slick InstallShield-type installation 
interface, but a rather clunky script implemented in a makefile which installs
things to a fixed directory.  The primary platform is the POSIX one, and I
have tried to maintain source and other text files as Unix-style text, but
I haven't been religious about this, so there may be some stray ctrl-M's in 
the code.  The only place this seems to make a difference in the interpretation
of makefiles under the Unix platform, where DOS line termination causes
ifeq lines etc. to be misinterpreted.

Under POSIX, the recommended way of operating is to simply run 'make' in
the top level directory of the distribution.  This should first build the
PCCTS binaries, then the CCCC program itself, then run a sequence of tests.
Providing the tests pass, the makefile should then attempt to install the
cccc binary in /usr/local/bin.  I have assumed that this will require root
privilege, so the top level makefile contains an 'su' command which should
cause a request for the root password unless the build/test/install process
is already running as root.  Please feel free to customize this process as
you see fit, especially if you are attempting to install CCCC in a location
convenient to you on a machine for which you do not have root privileges.

Under Win32, there is a Microsoft Visual Studio workspace ccccdist.dsw in the 
top level directory of the distribution.  This will also build the PCCTS 
binaries, then cccc.exe.  It will then run some tests on cccc.exe.  Providing
the testing has satisfactory results, the CcccDevStudioAddIn project will be
built, and the system will attempt to install the binaries cccc.exe and 
CcccDevStudioAddIn.dll to the directory C:\Program Files\CCCC.  The makefiles 
used to build cccc.exe and to control the testing and installation are the 
same ones used under POSIX, interpreted by an Win32 build of GNU make, 
wrapped in DevStudio .dsp projects (CcccDevStudioAddIn is a Win32 COM project,
is not compiled under POSIX, and hence uses a 'normal' Visual Studio project).

The DevStudio .dsw and .dsp files were all developed under version 5.0, but 
should be OK to load into a running instance of version 6.0.  I do not 
recommend starting DevStudio on these files by activating (double-clicking) 
them in Explorer, as on the version 6.0 development machine I use this tends 
to lead to DevStudio crashing as it starts up.

If you wish to use the Visual Studio integration, there are some additional
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
relating to software metrics which I was investigating as an MSc project.  
My candidature has recently been upgraded to PhD level, and I am hoping to 
complete and write up my research in the course of year 2000.  The research
to date and that proposed is described on my academic home page at 
http://www.fste.ac.cowan.edu.au/~tlittlef.  I plan to develop and distribute
bug fixes and enhancements to CCCC, but due to family, work and academic
commitments I am unable to commit to a specific schedule for these activities
beyond the current release.  

I am grateful to a number of people for assistance on this project, including
Terence Parr and his co-workers, and Tom Moog for the development and ongoing
maintenance of the excellent PCCTS tool; my academic supervisor, Dr Thomas
O'Neill; a number of developers who have contributed source patches; and
many people who have mailed me with constructive suggestions or merely to 
confirm that they were using the tool. Feedback on the value or otherwise 
of CCCC is always welcome, and will help me to decide how much effort I put 
into maintaining it over the coming months and years.  


Tim Littlefair (tim_littlefair@hotmail.com)
January 2000
--------------

This and future distributions of CCCC and related tools should be
available for the forseeable future from http://cccc.netpedia.net












