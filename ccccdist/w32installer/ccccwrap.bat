@echo off
set PATH=%WINDIR%;%WINDIR%\command;%WINDIR%\system;%WINDIR%\system32
type ccccwrap.msg
call cccc_env.bat
doskey /echo:off cccc=%CCCC_PATH_DIR%\CCCC.exe $* $T start .cccc\cccc.html
cd c:\
%COMSPEC% 


