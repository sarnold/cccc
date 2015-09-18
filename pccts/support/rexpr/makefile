BAG=../../bin/bag
SRC=test.c rexpr.c
OBJ=test.o rexpr.o
CFLAGS_DEBUG = -g
CC ?= gcc

test: $(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(CFLAGS_DEBUG) -o texpr $(OBJ)

shar:
	shar makefile test.c rexpr.c rexpr.h > rexpr.shar

archive:
	$(BAG) makefile test.c rexpr.c rexpr.h > rexpr.bag

clean:
	rm -rf *.o core texpr

scrub:
	rm -rf *.o core texpr
