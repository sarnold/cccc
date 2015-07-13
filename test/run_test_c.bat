@rem run_test_c.bat
@rem This script depends on environment variables set up in run_test.bat
%CCCC% --report_mask=cspPrRojh --db_outfile=%TEST%.db --html_outfile=%TEST%.html --xml_outfile=%TEST%.xml %TEST%.c
set CCCC_STATUS=%ERRORLEVEL%
%DIFF% %TEST%.db %TEST%.dbref
set DBDIFF_STATUS=%DIFF_STATUS%
%DIFF% %TEST%.html %TEST%.htmlref
set HTMLDIFF_STATUS=%DIFF_STATUS%
%DIFF% %TEST%.xml %TEST%.xmlref
set XMLDIFF_STATUS=%DIFF_STATUS%

