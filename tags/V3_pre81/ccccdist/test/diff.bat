@echo off
rem DIFF.BAT
rem This script should simulate the behaviour of Unix diff.
rem As it stands it simply uses the FC.EXE command which 
rem is part of DOS.  This does not give a useful return 
rem value, so the tester must visually check the output
rem to ensure that the test did pass, even though NMAKE thought
rem it did.

if not "%2" == "" goto AfterUsage
:usage
echo DIFF [file1] [file2]
goto :end
:afterUsage

fc %1 %2 
:end


