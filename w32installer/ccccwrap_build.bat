@rem ccccwrap.bat
@rem Wrapper script to provide a command line environment 
@rem for building CCCC using the Microsoft Visual C++ Toolkit 2003.
@echo off 

rem Give the command prompt a distinctive colour scheme so that 
rem the user can tell it from other command prompt windows.
color 2f

set CCCC_SRC_DIR=src
set MSVCT2003_DIR="c:\Program Files\Microsoft Visual C++ Toolkit 2003"

if not exist %CCCC_SRC_DIR% (
  echo "Source code directory not present"
  pause
  exit
) 

if not exist %MSVCT2003_DIR% (
   echo Microsoft Visual C++ Toolkit 2003 not present
   echo Please install or adapt build files to use a different compiler.
   pause
) else (
   echo Start the build using the script 'build_w32vct2003.bat'
)

cd %CCCC_SRC_DIR%

rem Start the shell

%COMSPEC% 
goto end

:end

