
# rules.mak
# This file contains cross-platform rules to support testing of CCCC
# it is intended to be included by a platform specific makefile.

# Before this file is included the following variables need to be
# defined:
# CP=<command to copy a file>
# RM=<program to remove a file>
# RMDIR=<program to remove a directory>
# MV=<program to move a file>
# ECHO=<echo program>
# DIFF=<differencing program>
# PATHSEP=<path separator - \ for win32, / for Unix>
# CCCC=<path to CCCC program>

# We may also want to define CCCC_DEBUG_FLAGS on the command line
# if we would like to see some or all of the debug output available
# from CCCC.
# CCCC_DEBUG_FLAGS= --debug_mask=0xFF

# We define a phony target extensions to enable us to force execution of tests
# under normal and debugging conditions and also to provide a shortcut way
# of 'blessing' the results of a run as the reference values
.SUFFIXES : .do_the_test .cc .c .java

all : unit_tests regression_tests
	@$(ECHO) ================
	@$(ECHO) All tests passed
	@$(ECHO) ================

# The --report_mask qualifier controls which parts of the HTML report are
# generated.  We choose to generate all information in the main file,
# but not the separate HTML reports on each module or the source listing.
# We also supress the generation date, so that reports generated at different
# times can be compared. 
# At this stage we are happy if the numbers in the generated report look OK:
# some day soon we need to tidy up the code so that when a selective report
# like this is generated it does not contain loose HTML HREF tags.
.cc.do_the_test :
	$(CCCC) --report_mask=cspPrRojh --db_outfile=$*.db --html_outfile=$*.html --xml_outfile=$*.xml $(CCCC_DEBUG_FLAGS) $<
	$(DIFF) $*.db $*.dbref
	$(DIFF) $*.html $*.htmlref
	$(DIFF) $*.xml $*.xmlref

.c.do_the_test :
	$(CCCC) --report_mask=cspPrRojh --db_outfile=$*.db --html_outfile=$*.html --xml_outfile=$*.xml $(CCCC_DEBUG_FLAGS) $<
	$(DIFF) $*.db $*.dbref
	$(DIFF) $*.html $*.htmlref
	$(DIFF) $*.xml $*.xmlref

.java.do_the_test :
	$(CCCC) --report_mask=cspPrRojh --db_outfile=$*.db --html_outfile=$*.html --xml_outfile=$*.xml $(CCCC_DEBUG_FLAGS) $<
	$(DIFF) $*.db $*.dbref
	$(DIFF) $*.html $*.htmlref
	$(DIFF) $*.xml $*.xmlref

# The command line for test4 is slightly different so it needs
# an explicit rule
test4.do_the_test :
	$(CCCC) --opt_infile=test4.opt --report_mask=cspPrRojh --db_outfile=test4.db --html_outfile=test4.html --xml_outfile=test4.xml $(CCCC_DEBUG_FLAGS) test4.cc
	$(DIFF) $*.db $*.dbref
	$(DIFF) $*.html $*.htmlref
	$(DIFF) $*.xml $*.xmlref

# the first test case is exercises the logic for procedural metrics
# the second test case is exercises the logic for structural metrics
# the third test case is exercises the logic for metrics arising out of the
# work of Chidamber and Kemerer
# the fourth test case applies to the ability to specify an option
# file to control CCCC's policies for parsing and presentation
unit_tests : test1.do_the_test test2.do_the_test test3.do_the_test \
	test4.do_the_test



# regression tests
# PRN1 and PRN2 sent in by Kenneth H. Cox
# PRN3 sent in by Dr D. Ruppert, against CCCC 3.pre39
# PRN4 prepared by TL to check for problems with classes being mapped
# to modules via their qualified name (CCCC policy is that the simple name
# is used)
# PRN5 prepared by TL to check for problem due to relationships being
# created involving built-in types
# PRN6 based on a test case reported by ??? 
# PRN7 based on a test case reported by Larry Peters of ATI
# PRN8 based on a test case reported by Eric Pischel
# PRN9-PRN12 based on test cases reported by Victor B Putz
# PRN13-PRN14 based on example programs from Sun's Java Tutorial.
# PRN15 based on a test case reported by Jordan Zimmerman
# PRN16 based on a test case reported by Colin Watson

regression_tests : \
	prn1.do_the_test prn2.do_the_test prn3.do_the_test \
	prn4.do_the_test prn5.do_the_test prn6.do_the_test \
	prn7.do_the_test prn8.do_the_test prn9.do_the_test \
	prn10.do_the_test prn11.do_the_test prn12.do_the_test \
	prn13.do_the_test prn14.do_the_test prn15.do_the_test \
	prn16.do_the_test

