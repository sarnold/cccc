@Rem DEVENV.BAT
@echo off
rem This file sets up a minimal command line environment
rem for CCCC development.

rem Path to Microsoft Visual Studio standard edition release 6.0
set VCDIR1=c:\Program Files\Microsoft Visual Studio\vc98
set VCDIR2=c:\Program Files\Microsoft Visual Studio\common\msdev98

rem Path to Borland Free command line tools version 5.5
set BCDIR=c:\Program Files\Borland\bcc55

rem Path to CygWin toolchain version 1.3
set CYGDIR=c:\cygwin

path "%VCDIR1%\bin";"%VCDIR2%\bin";"%BCDIR%\bin";"%CYGDIR%\bin";"%CYGDIR%\usr\bin";%PATH%
call vcvars32.bat
