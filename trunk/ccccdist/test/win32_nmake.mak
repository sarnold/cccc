# makefile to control testing of CCCC

ifeq "$(CONF)" "w32vc"
RM=../w32bin/rm -f
RMDIR=../w32bin/rm -rf
MV=../w32bin/mv
ECHO=../w32bin/echo
DIFF=../w32bin/diff
else
CP=cp
RM=rm -f
RMDIR=rm -rf
MV=mv
ECHO=echo
DIFF=diff
endif

# We define a phony target extension to enable us to force 
.SUFFIXES : .do_the_test 

# The --report_mask qualifier controls which parts of the HTML report are
# generated.  We choose to generate all information in the main file,
# but not the separate HTML reports on each module or the source listing.
# We also supress the generation date, so that reports generated at different
# times can be compared. 
# At this stage we are happy if the numbers in the generated report look OK:
# some day soon we need to tidy up the code so that when a selective report
# like this is generated it does not contain loose HTML HREF tags.
.cc.do_the_test :
	-$(RMDIR) .cccc $*.html $*.db
	../cccc/cccc --report_mask=cspPrRojh $<
	$(MV) .cccc/cccc.html $*.html
	$(MV) .cccc/cccc.db $*.db
	$(DIFF) $*.db $*.dbref
	$(DIFF) $*.html $*.htmlref

.c.do_the_test :
	-$(RMDIR) .cccc $*.html $*.db
	../cccc/cccc --report_mask=cspPrRojh $<
	$(MV) .cccc/cccc.html $*.html
	$(MV) .cccc/cccc.db $*.db
	$(DIFF) $*.db $*.dbref
	$(DIFF) $*.html $*.htmlref

all : unit_tests regression_tests
	@$(ECHO) ================
	@$(ECHO) All tests passed
	@$(ECHO) ================

# the first test case is exercises the logic for procedural metrics
# the second test case is exercises the logic for structural metrics
# the third test case is exercises the logic for metrics arising out of the
# work of Chidamber and Kemerer
unit_tests : test1.do_the_test test2.do_the_test test3.do_the_test


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


