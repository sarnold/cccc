@rem make_cccc_env.bat
@rem This script runs at CCCC install time to generate a
@rem batch file to set up environment variables for the 
@rem command line interface for CCCC.
@echo off

set SCRIPT=cccc_env.bat
echo @rem cccc_env.bat> %SCRIPT%
echo @rem CCCC_PATH_DIR defines the installation directory where the>> %SCRIPT%
echo @rem cccc executable is found.>> %SCRIPT%
echo set CCCC_PATH_DIR=%1>> %SCRIPT%
echo @rem >> %SCRIPT%
echo @rem CCCC_WORK_DIR defines the initial working directory for the>> %SCRIPT%
echo @rem command line session>> %SCRIPT%
echo set CCCC_WORK_DIR=%2>> %SCRIPT%





