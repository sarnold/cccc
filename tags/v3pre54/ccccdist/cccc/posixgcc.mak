# posixgcc.mak
## GNUMakefile to build the CCCC project on the POSIX compliant 
## platforms using the GNU C Compiler.
## Tested with:
##   GCC 2.95.3 on Mandrake Linux v7.2  (reported by Tim Littlefair)
##   EGCS 2.91.66 (aka kgcc) on Mandrake Linux v7.2  (reported by Tim Littlefair)
## (More reports welcome)
## See rules.mak for discussion of the meaning of the make variables
## which this file defines

# support for debugging 
ifeq "$(DEBUG)" "true"
CFLAGS_DEBUG=-g
LDFLAGS_DEBUG=-g
endif

PATHSEP=/

CCC=g++
LD=g++
CFLAGS=-c -I../pccts/h $(CFLAGS_DEBUG) -x c++ 
C_OFLAG=-o
LDFLAGS=$(LDFLAGS_DEBUG) 
LD_OFLAG=-o
OBJEXT=o
CCCC_EXE=cccc

COPY=cp
RM=rm


include rules.mak

