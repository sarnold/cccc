@rem run_test_test4.bat
@This script depends on environment variables set up in run_test.bat
%CCCC% --opt_infile=test4.opt --report_mask=cspPrRojh --db_outfile=test4.db --html_outfile=test4.html --xml_outfile=test4.xml %TEST%.cc
set CCCC_STATUS=%DIFF_STATUS%
%DIFF% %TEST%.db %TEST%.dbref
set DBDIFF_STATUS=%DIFF_STATUS%
%DIFF% %TEST%.html %TEST%.htmlref
set HTMLDIFF_STATUS=%DIFF_STATUS%
%DIFF% %TEST%.xml %TEST%.xmlref
set XMLDIFF_STATUS=%DIFF_STATUS%

