# w32bcb.mak

## NMakefile to build the CCCC project on the Borland C++ Builder 
## (tested with a free copy which was shipped on a magazine CD, May 2000)
## See rules.mak for discussion of the meaning of the make variables
## which this file defines

# support for debugging (note that debug building is on by default)
!IF "$(DEBUG)"=="true"
CFLAGS_DEBUG=-g
LDFLAGS_DEBUG=-g
!ENDIF

PATHSEP=\\
PATH=\Program Files\Borland\CBuilder3\bin
CCC="$(PATH)\bcc32.exe"
LD="$(PATH)\bcc32.exe"
CFLAGS=-c -P -D_NO_VCL -I$(PCCTS_H) -w-aus -w-par -w-hid -w-inl $(CFLAGS_DEBUG) -DCCCC_CONF_W32VC
C_OFLAG=-o
LDFLAGS=$(LDFLAGS_DEBUG) 
LD_OFLAG=-o
OBJEXT=obj
CCCC_EXE=cccc.exe

COPY=copy
RM=del

!INCLUDE rules.mak

