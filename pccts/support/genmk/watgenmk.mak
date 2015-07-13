SET=..\..\support\set
PCCTS_H=..\..\h

#
#   Watcom
#
CC=wcl386
ANTLR=..\..\bin\antlr
DLG=..\..\bin\dlg
CFLAGS= -I. -I$(SET) -I$(PCCTS_H) -DUSER_ZZSYN -DPC
OUT_OBJ = -o
OBJ_EXT = obj
LINK = wcl386

.c.obj :
	$(CC) -c $[* $(CFLAGS)

genmk.exe: genmk.obj
	$(LINK) -fe=genmk.exe *.obj -k14336
	copy *.exe ..\..\bin

#clean up all the intermediate files
clean:
	del *.obj

#remove everything in clean plus the PCCTS files generated
scrub:
	del *.$(OBJ_EXT)
