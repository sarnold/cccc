@echo off
call cccc_env.bat
echo CCCC is a command line tool.  
echo This window has been set up with a PATH to allow the tool to
echo be run conveniently.
set path=%CCCC_PATH_DIR%
cd %CCCC_WORK_DIR%

%COMSPEC% 

