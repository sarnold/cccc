# Top level makefile for CCCC

# This distribution is a compilation of code, some of which comes from
# different sources, some of which builds different (e.g. Win32 DLL) kinds
# of targets.
# I would like to make it less inconsistent, but the first stage is to make
# it work...
#
# 13 July 2015 - SLA
# Updated to split out make targets (for cccc) and enable the jobserver.
#  - Note that only antlr and dlg are required for building cccc

.PHONY : pccts cccc test mini all

all : pccts cccc

mini :
	cd pccts && $(MAKE) -Orecurse antlr dlg || exit $$?

pccts :
	cd pccts && $(MAKE) -Orecurse $@ || exit $$?

cccc :
	cd cccc && $(MAKE) -Orecurse -f posixgcc.mak $@ || exit $$?

.NOTPARALLEL:	test
test :
	cd test && $(MAKE) -f posix.mak test

