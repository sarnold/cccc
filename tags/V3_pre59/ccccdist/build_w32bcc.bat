@rem build_w32bcc.bat
@echo off

rem This file builds and tests CCCC under the Borland Command line
rem C++ compiler.
rem Path to Microsoft Visual Studio standard edition release 6.0
set BCDIR=c:\Program Files\Borland\bcc55
if not exist "%BCDIR%\bin\bcc32.exe" goto no_bcc

PATH "%BCDIR%\bin";%PATH%

rem One day there I will do Borland Makefiles for ANTLR and DLG.
rem For the moment I will rely on versions precompiled under MSVC.
if not exist pccts\bin\antlr.exe goto no_pccts
if not exist pccts\bin\dlg.exe goto no_pccts

cd cccc
if exist *.obj del *.obj
if exist *.cpp del *.cpp
make -f w32bcc.mak
cd ..

cd test
make -f w32bcc.mak
cd ..

goto end

:no_bcc
echo This script expects Borland C++ command line compiler to be in 
echo %VCDIR%\bin\bcc32.exe.
echo Please modify the script if the location is different.
goto end

:no_pccts
echo This script expects precompiled versions of PCCTS binaries
echo DLG and ANTLR to be in pccts\bin.
echo The CCCC package contains makefiles to build these under
echo MSVC, otherwise you can write and contribute makefiles for 
echo BCC32.

:end

