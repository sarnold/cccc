# Top level makefile for CCCC

AR ?= ar
CPP ?= cpp -E
CC ?= gcc
CCC ?= g++
LD ?= g++

# This distribution is a compilation of code, some of which comes from
# different sources, some of which builds different (e.g. Win32 DLL) kinds
# of targets.
# I would like to make it less inconsistent, but the first stage is to make 
# it work...

DOX	= doxygen
CCCC	= ./cccc/cccc
CCCOPTS	= --lang=c++
CCCCSRC = ./cccc/*.cc ./cccc/*.h
GENSRC	= cccc/CLexer.cpp \
          cccc/CLexer.h \
          cccc/CParser.cpp \
          cccc/CParser.h \
          cccc/Ctokens.h \
          cccc/JLexer.cpp \
          cccc/JLexer.h \
          cccc/JParser.cpp \
          cccc/JParser.h \
          cccc/Jtokens.h \
          cccc/cccc.cpp \
          cccc/java.cpp \
          cccc/parser.dlg

.PHONY : all mini pccts cccc test

all : mini cccc test

mini :
	$(MAKE) DEBUG=$(DEBUG) -C pccts antlr dlg || exit $$?

pccts :
	$(MAKE) DEBUG=$(DEBUG) -C pccts $@ || exit $$?

cccc :	mini
	$(MAKE) DEBUG=$(DEBUG) -C cccc -f posixgcc.mak $@ || exit $$?

.NOTPARALLEL:	cccc test
test :
	cd test && $(MAKE) -f posix.mak || exit $$?

DOCS	= doxygen
METRICS	= ccccout
TESTOBJ = test/*.xml test/*.html test/*.db

$(METRICS)/.keep_dir :
	mkdir -p $(dir $@)
	touch $@

metrics : $(METRICS)/.keep_dir cccc
	rm -rf $(METRICS)/*.html
	@echo "Input files are: $(CCCCSRC)"
	$(CCCC) $(CCCOPTS) --outdir=$(METRICS)/ $(CCCCSRC)
	@echo "Metrics output now in $(METRICS)/cccc.html"

$(DOCS)/.keep_dir :
	mkdir -p $(dir $@)
	touch $@

docs :	Doxyfile.html_cfg $(CCCCSRC) $(DOCS)/.keep_dir
	rm -rf $(DOCS)/html
	$(DOX) Doxyfile.html_cfg
	@echo "API docs now in $(DOCS)/html"

clean	:
	rm -rf cccc/*.o cccc/cccc $(GENSRC) pccts/bin/*

reallyclean : clean
	rm -rf ccccout/* doxygen/html test/.cccc $(TESTOBJ)
	make -C pccts clean

clobber	: reallyclean
	make -C pccts scrub
