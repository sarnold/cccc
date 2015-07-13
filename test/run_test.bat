@rem run_test.bat
@rem This script replaces the action of the make program in running
@rem the tests described in rules.mak as there is no make provided
@rem with Microsoft Visual C++ Toolkit 2003.

@rem the first test case is exercises the logic for procedural metrics
@rem the second test case is exercises the logic for structural metrics
@rem the third test case is exercises the logic for metrics arising out of the
@rem work of Chidamber and Kemerer
@rem the fourth test case applies to the ability to specify an option
@rem file to control CCCC's policies for parsing and presentation

@rem regression tests
@rem PRN1 and PRN2 sent in by Kenneth H. Cox
@rem PRN3 sent in by Dr D. Ruppert, against CCCC 3.pre39
@rem PRN4 prepared by TL to check for problems with classes being mapped
@rem to modules via their qualified name (CCCC policy is that the simple name
@rem is used)
@rem PRN5 prepared by TL to check for problem due to relationships being
@rem created involving built-in types
@rem PRN6 based on a test case reported by ??? 
@rem PRN7 based on a test case reported by Larry Peters of ATI
@rem PRN8 based on a test case reported by Eric Pischel
@rem PRN9-PRN12 based on test cases reported by Victor B Putz
@rem PRN13-PRN14 based on example programs from Sun's Java Tutorial.
@rem PRN15 based on a test case reported by Jordan Zimmerman
@rem PRN16 based on a test case reported by Colin Watson

@echo off

set MODE=%1
set TEST=%2

set CCCC=..\cccc\cccc.exe
set DIFF=call diff.bat
set RM=del
set RMDIR=rmdir
set MV=rename
set ECHO=echo

if "%TEST%"=="" then goto :usage

if "%MODE%"=="c" (
	call run_test_c.bat
	goto :checkStatus
) else if "%MODE%"=="cc" (
	call run_test_cc.bat
	goto :checkStatus
) else if "%MODE%"=="java" (
	call run_test_java.bat
	goto :checkStatus
) else if "%MODE%"=="test4" (
	call run_test_test4.bat
	goto :checkStatus
) else goto :usage

:checkStatus
set OVERALL_STATUS=%CCCC_STATUS%%DBDIFF_STATUS%%HTMLDIFF_STATUS%%XMLDIFF_STATUS%
if not "%OVERALL_STATUS%"=="0000" (
	echo Problem found:
	echo CCCC returned %CCCC_STATUS%
	echo DB diff returned %DBDIFF_STATUS%
	echo HTML diff returned %HTMLDIFF_STATUS%
	echo XML diff returned %XMLDIFF_STATUS%
	pause
) else (
	echo test %TEST% passed
)
goto :end

:usage
echo run_test [mode] [test]
echo [mode] is one of c, cc, java, test4
echo [test] is one of test1..test4, prn1..prn16
goto :end


:end



