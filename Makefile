# Top level makefile for CCCC

# This distribution is a compilation of code, some of which comes from
# different sources, some of which builds different (e.g. Win32 DLL) kinds
# of targets.
# I would like to make it less inconsistent, but the first stage is to make 
# it work...

.PHONY : pccts cccc test install

all : pccts cccc

pccts :
	cd pccts && +$(MAKE) pccts

cccc :
	cd cccc && +$(MAKE) -f posixgcc.mak cccc

.NOTPARALLEL:	test
test :
	cd test && $(MAKE) -f posix.mak test

