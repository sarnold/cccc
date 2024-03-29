# posixgcc.mak
## GNUMakefile to build the CCCC project on the POSIX compliant 
## platforms using the GNU C Compiler.
## Tested with:

##   GCC 2.95.3 on Mandrake Linux v7.2  (reported by Tim Littlefair)
##   EGCS 2.91.66 (aka kgcc) on Mandrake Linux v7.2  (reported by Tim Littlefair)
##   GCC 2.96 on Red Hat 7.2 (reported by Tim Littlefair)
##   GCC 3.2 on Mandrake Linux 9.0 (reported by Tim Littlefair)

## The '-static' link argument was removed as a result of problems
## encountered on GCC 3.2 - as we don't prebuild binaries at present
## dynamic linking shouldn't be a killer problem.

## (More reports welcome)
## See rules.mak for discussion of the meaning of the make variables
## which this file defines

# support for debugging 
ifeq "$(DEBUG)" "true"
DEBUG_FLAGS = -g
DEBUG_LFLAGS = -Wl,$(DEBUG_FLAGS)
else
DEBUG_LFLAGS =
endif

PATHSEP=/

CCC ?= g++
INCLUDES = -I../pccts/h -I.
CCC_OPTS = -c $(CFLAGS) $(DEBUG_FLAGS) $(INCLUDES) -std=c++98 -x c++
C_OFLAG = -o 
LD_OPTS = $(LDFLAGS) $(DEBUG_LFLAGS)
LD_OFLAG = -o 
OBJEXT = o
CCCC_EXE = cccc

COPY = cp
RM = rm


include rules.mak

