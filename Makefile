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
CCCCSRC = ./cccc/*.cc ./cccc/*.cpp ./cccc/*.h
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

.PHONY : all mini pccts cccc test dist clean

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

# dist target requires VERSION set in build environment
dist :	clean
	mkdir -p dist/cccc-$(VERSION)
	cp *.rst *.md build* LICENSE tox.ini Makefile dist/cccc-$(VERSION)/
	cp -r cccc conda test dist/cccc-$(VERSION)/
	tar -czf dist/cccc-$(VERSION).tar.gz -C dist cccc-$(VERSION)

clean	:
	rm -f cccc/*.o cccc/cccc

reallyclean : clean
	rm -f pccts/bin/* $(TESTOBJ) $(GENSRC)
	rm -rf ccccout/ doxygen/ test/.cccc dist/
	make -C pccts clean

clobber	: reallyclean
	rm -f cccc/cccc_ver.h
	make -C pccts scrub
