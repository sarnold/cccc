#
# Main makefile for PCCTS 1.33MR33	/* MRXXX */
#
# Terence Parr
# Parr Research Corporation
#
# verbosity versus silence...
#PSss=
#
# this can be set to /user/local/bin etc...
BINDIR=bin
# This part added by Thomas Herter, M"unchen, Germany. See also manpages
# target.
MANDIR=$(HOME)/man
MANEXT=1
MANFILES=dlg/dlg.1 antlr/antlr.1

#CC=cc

# Set COPT if your build setup does not pass it in CFLAGS
#COPT=-O2

#
# 13 July 2015 - SLA
# Updated to split out make targets (for cccc) and enable jobserver.
# 

.PHONY : pccts dlg antlr sorcerer genmk pre welcome fini

pccts:	pre welcome antlr dlg sorcerer genmk fini

pre:
	@if [ ! -d $(BINDIR) ] ; then mkdir -p $(BINDIR) ; fi

welcome	:	pre
	@echo " "
	@echo "             Welcome to PCCTS 1.33MR33 installation"
	@echo " "
	@echo "             (Version 1.33 Maintenance Release #33)" # mrxxx
	@echo " "
	@echo "                  Released 19 April 2002"
	@echo " "
	@echo "                        Featuring"
	@echo "         ANTLR     -- ANother Tool for Language Recognition"
	@echo "         DLG       -- DFA-based Lexical Analyzer Generator"
	@echo "         SORCERER  -- Source-to-source translator (tree walker)" 
	@echo " "
	@echo "                  http://www.antlr.org"	
	@echo " "
	@echo "             Trouble reports to tmoog@polhode.com"
	@echo "             Additional PCCTS 1.33 information at"
	@echo "                  http://www.polhode.com"
	@echo
	@echo
	@echo "To substitute gcc for CC to invoke compiler: make CC=gcc"
	@echo "If there are problems with cr and lf try: unzip -a ..."
	@echo
	@echo Making executables...

antlr	:	pre
	$(MAKE) -C antlr $@ || exit $$?
	@echo antlr executable now in $(BINDIR)

dlg	:	pre
	$(MAKE) -C dlg $@ || exit $$?
	@echo dlg executable now in $(BINDIR)

genmk:
	$(MAKE) -C support/genmk CC="$(CC)" COPT="$(COPT)" $@ || exit $$?
	cd support/genmk && mv genmk ../../$(BINDIR) || exit $$?
	@echo genmk executable now in $(BINDIR)

fini:
	@echo
	@echo "       PCCTS 1.33MR33 installation complete"  # MRXXX

clean:
	(cd ./antlr; $(MAKE) -s clean)
	(cd ./dlg; $(MAKE) -s clean)
	(cd ./support/genmk; $(MAKE) -s clean)

scrub:
	(cd ./antlr; $(MAKE) -s scrub)
	(cd ./dlg; $(MAKE) -s scrub)

manpages:
	# mkdir -p $(MANDIR)/man$(MANEXT)
	if [ ! -d $(MANDIR) ] ; then \
	  mkdir $(MANDIR) ; fi
	if [ ! -d $(MANDIR)/man$(MANEXT) ] ; then \
	  mkdir $(MANDIR)/man$(MANEXT); fi
	cp -p $(MANFILES) $(MANDIR)/man$(MANEXT)
