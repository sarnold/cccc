# Makefile to control testing of CCCC on POSIX platforms

# Define the variables used by the platform-independent rules.
CP=cp
RMDIR=rm -rf
MV=mv
ECHO=echo
DIFF=diff
PATHSEP=/
CCCC=../cccc/cccc

# include the file containing the platform independent rules.
include rules.mak


