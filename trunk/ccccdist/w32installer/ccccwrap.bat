@echo off 
set PATH=%WINDIR%;%WINDIR%\command;%WINDIR%\system;%WINDIR%\system32 
set CCCC_PATH_DIR="C:\Program Files\CCCC"
set CCCC_WORK_DIR="C:\"
type %CCCC_PATH_DIR%\ccccwrap.msg 
doskey cccc=%CCCC_PATH_DIR%\CCCC.exe $* $T start .cccc\cccc.html 
cd %CCCC_WORK_DIR% 
%COMSPEC% 
