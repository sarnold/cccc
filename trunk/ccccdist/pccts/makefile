#
# Main makefile for PCCTS 1.33MR20	/* MRXXX */
#
# Terence Parr
# Parr Research Corporation
#
# verbosity versus silence...
PSss=
#
# this can be set to /user/local/bin etc...
BINDIR=bin
# This part added by Thomas Herter, M"unchen, Germany. See also manpages
# target.
MANDIR=$(HOME)/man
MANEXT=1
MANFILES=pccts.1 dlg/dlg.1 antlr/antlr.1

#CC=cc

.SILENT:

pccts:
	echo " "
	echo "             Welcome to PCCTS 1.33MR20a installation"
	echo " "
	echo "             (Version 1.33 Maintenance Release #20a)"
	echo " "
	echo "                  Released 10 August 1999"
	echo " "
	echo "                        Featuring"
	echo "         ANTLR     -- ANother Tool for Language Recognition"
	echo "         DLG       -- DFA-based Lexical Analyzer Generator"
	echo "         SORCERER  -- Source-to-source translator (tree walker)" 
	echo " "
	echo "                  http://www.antlr.org"	
	echo " "
	echo "             Trouble reports to tmoog@polhode.com"
	echo "             Additional PCCTS 1.33 information at"
	echo "                  http://www.polhode.com"
	echo
#
	if [ ! -d $(BINDIR) ] ; then mkdir $(BINDIR) ; fi
	echo Making executables...
	(cd antlr; make -s)
	echo antlr executable now in $(BINDIR)
	(cd dlg; make -s)
	echo dlg executable now in $(BINDIR)
	(cd sorcerer; make -s)
	echo sorcerer executable now in $(BINDIR)
	(cd support/genmk; make -s; mv genmk ../../$(BINDIR))
	echo genmk executable now in $(BINDIR)
	echo
	echo "       PCCTS 1.33MR20 installation complete"

clean:
	(cd antlr; make -s clean)
	(cd dlg; make -s clean)
	(cd sorcerer; make -s clean)
	(cd support/genmk; make -s clean)


manpages:
	if [ ! -d $(MANDIR) ] ; then mkdir $(MANDIR) ; fi
	cp -p $(MANFILES) $(MANDIR)/man$(MANEXT)
