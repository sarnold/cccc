@echo off
rem DIFF.BAT
rem This script should simulate the behaviour of Unix diff.
rem As it stands it simply uses the FC.EXE command which 
rem is part of DOS.  This does not give a useful return 
rem value, so the script must check the output using the 
rem for /f "usebackq" structure. 

if not "%2" == "" goto AfterUsage
:usage
echo DIFF [file1] [file2]
goto :end

:afterUsage
set DIFFLEN=
set CMD=fc %1 %2
set DIFF_STATUS=0
for /f "usebackq" %%l in ( `%CMD%` ) do ( 
  if "%%l"=="Comparing" (
     rem This is expected
  ) else if "%%l"=="FC:" (
     rem This is also expected
  ) else (
     rem If anything else comes out, the comparison found a difference
     set DIFF_STATUS=1
  )
) 
exit /b %DIFF_STATUS%



