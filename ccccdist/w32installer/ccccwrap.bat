@echo off
doskey > NUL
type ccccwrap.msg
call cccc_env.bat
path %CCCC_PATH_DIR%
cd %CCCC_WORK_DIR%


