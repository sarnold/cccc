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


# We define a phony target extension to enable us to force execution of tests
.SUFFIXES : .do_the_test .cc

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
	$(CCCC) --report_mask=cspPrRojh --db_outfile=$*.db --html_outfile=$*.html $<
	$(DIFF) $*.db $*.dbref
	$(DIFF) $*.html $*.htmlref

.c.do_the_test :
	$(CCCC) --report_mask=cspPrRojh --db_outfile=$*.db --html_outfile=$*.html $<
	$(DIFF) $*.db $*.dbref
	$(DIFF) $*.html $*.htmlref

# The command line for test4 is slightly different so it needs
# an explicit rule
test4.do_the_test :
	$(CCCC) --opt_infile=test4.opt --report_mask=cspPrRojh --db_outfile=test4.db --html_outfile=test4.html test4.cc
	$(DIFF) $*.db $*.dbref
	$(DIFF) $*.html $*.htmlref

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
# PRN6 based on a test case sent in by ??? 
# PRN7 based on a test case sent in by Larry Peters of ATI
regression_tests : \
	prn1.do_the_test prn2.do_the_test prn3.do_the_test \
	prn4.do_the_test prn5.do_the_test prn6.do_the_test \
	prn7.do_the_test


