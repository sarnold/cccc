@echo off
rem DIFF.BAT
rem This script should simulate the behaviour of Unix diff.
rem As it stands it simply uses the FC.EXE command which 
rem is part of DOS.  This does not give a useful return 
rem value, so the tester must visually check the output
rem to ensure that the test did pass, even though NMAKE thought
rem it did.

if "%2" == "" goto usage

fc %1 %2 

goto end

:usage
DIFF [file1] [file2]

:end
