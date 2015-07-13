@rem ccccwrap.bat
@rem Wrapper script to provide a command line environment with CCCC in the path.
@echo off 

rem Give the command prompt a distinctive colour scheme so that 
rem the user can tell it from other command prompt windows.
color 2e

set CCCC_ENV=cccc_env.bat
set CCCC_EXE=cccc.exe

if not exist %CCCC_ENV% goto noEnv
call %CCCC_ENV%

if not exist %CCCC_PATH_DIR%\%CCCC_EXE% goto noExe
if not exist %CCCC_WORK_DIR% goto noWorkDir

path %CCCC_PATH_DIR%;%path%
cd %CCCC_WORK_DIR% 

rem Request the usage message.
%CCCC_PATH_DIR%\cccc.exe --help


rem Start the shell
%COMSPEC% 
goto end

:noEnv
echo The file %CCCC_ENV% was not found.
echo This file is required to define the command line environment for CCCC.
echo Please uninstall and reinstall CCCC to get a working command line environment.
pause
goto end

:noExe
echo The executable %CCCC_EXE% was not found in %CCCC_PATH_DIR%.
echo Please uninstall and reinstall CCCC to get a working command line environment.
pause
goto end

:noWorkDir
echo The shell variable CCCC_WORK_DIR is defined as %CCCC_WORK_DIR% but this 
echo directory does not exist.
echo This variable is required to define the initial work directory
echo for a session using the CCCC command line environment.
echo Please uninstall and reinstall CCCC to get a working command line environment.
pause
goto end

:end

