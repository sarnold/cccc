@rem make_release.bat
@rem Script to make a Win32 version of the CCCC release.

if "%3"=="" (
   echo Usage: make_release.bat major minor patch
)

set cvs="c:\Program Files\GNU\WinCVS 1.3\CVSNT\cvs.exe"

set release_tag=V%1_%2_%3
set release_name=cccc-%1.%2.%3
set release_number=%1.%2.%3

%cvs% export -r %release_tag% -d %release_name% ccccdist
echo #define CCCC_VERSION %release_number% > %release_name%\cccc\cccc_ver.h
echo #define CCCC_VERSION_STRING "%release_number%" >> %release_name%\cccc\cccc_ver.h
setlocal
cd %release_name%
call build_w32vct2003.bat --clean
endlocal
copy %release_name%\w32installer\output\CCCC_SETUP.exe .\CCCC_%release_number%_setup.exe



