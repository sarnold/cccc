@echo off
rem make_cccc_env.bat
rem This script will be run at install time to create 
rem the file cccc_env.bat which is included by ccccwrap.bat
rem to define the directory where the CCCC binary is and
rem the working directory in which the command prompt is 
rem to start.
echo set CCCC_PATH_DIR=%1 >> cccc_env.bat
echo set CCCC_WORK_DIR=%2 >> cccc_env.bat


