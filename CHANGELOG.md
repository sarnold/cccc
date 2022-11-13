# Changelog


## 3.2.0 (2022-11-13)

### Changes

* Cleanup deb package workflow, make one artifact. [Stephen L Arnold]

  * add deb packaging to release workflow

* Fix debian rules file, update tox default CC var. [Stephen L Arnold]

  * debian package flags conflict with top-level makefile, cleanup
    clean override
  * cleanup typo and macos versions in workflows

* Use gitchangelog, replace old tool cfg, update tox file. [Stephen L Arnold]

  * fix typo in new workflow

* Workflow and makefile cleanup, add simple tox file. [Stephen L Arnold]

  * add local include path for https://bugs.gentoo.org/880613
    and rename top-level makefile for this_cli
  * update workflow actions and add simple release workflow,
    test deb package action in a new workflow
  * add basic tox.ini file !wip

### Fixes

* Update debian man page for xml out. [Stephen L Arnold]

* Use correct readme filename in rules.mk. [Stephen L Arnold]

* Update crufty version header, add release.sh and update readme. [Stephen L Arnold]

### Other

* Merge pull request #37 from sarnold/fix-rollup. [Steve Arnold]

  pull in fix for implicit integer cast

* Fix from Erwan Legrand on the implicit integer cast. [Sebastian Stiernborg]

* Bump last workflow (conda) to windows-2019 (2016 is now deprecated) [Stephen L Arnold]

* Merge pull request #36 from sarnold/fix-ci. [Steve Arnold]

  update workflows

* Update workflows, fix missing cmd, check windows env. [Stephen L Arnold]

* Update readme_install doc, tweak apt pkg installs (ci workaround) [Stephen L Arnold]

* Merge pull request #25 from sarnold/readme. [Steve Arnold]

  test upstream codeclimate badge

* Cleanup both markdown docs. [Stephen L Arnold]

* Fix some markdow format (need a local linter) [Stephen L Arnold]

* Test upstream codeclimate badge. [Stephen L Arnold]

* Merge pull request #24 from sarnold/test-ci. [Steve Arnold]

  remove static cfg file for backend cfg

* Remove static cfg file for backen cfg. [Stephen L Arnold]

* Fix .codeclimate.yml config. [Stephen L Arnold]

* Update quick install readme with conda-forge info. [Stephen L Arnold]

* Add conda build, more CI, fix exit code for help, set c.ansi default for .h files (#20) [Steve Arnold]

  * set .h header files to type c.ansi as default
  * add conda recipe/build scripts
  * update readme and user guide, add quick install doc
  * update msvc build script (batch file)
  * add platform/compiler matrix workflow
  * set exit to zero when using the --help option

* Merge pull request #19 from sarnold/ci-version. [Steve Arnold]

  ci updates

* Fix yet-another-markdown-fail... [Stephen L Arnold]

* Really fix badges (silly markdown...) [Stephen L Arnold]

* Fix status/version badges in readme. [Stephen L Arnold]

* Merge pull request #18 from sarnold/new-ci. [Steve Arnold]

  Create ci.yml

* README.md: update CI build status. [Stephen L Arnold]

* Try adding windows build with mingw (with path update) [Stephen L Arnold]

* Test building on macos. [Stephen L Arnold]

* .github/workflows/ci.yml: remove configure step, disable rename travis cfg. [Stephen L Arnold]

* Create ci.yml. [Steve Arnold]


## 3.1.6 (2020-10-04)

### Other

* Doxyfile.html_cfg: disable clang parsing as default/travis. [Stephen Arnold]

* Update docs and changelog, make travis install clang for doxygen. [Stephen Arnold]

* .travis.yml: test for newer toolchain versions (may break) [Stephen Arnold]

* .travis.yml: test updated matrix cfg. [Stephen Arnold]

* Update expected test ref output for PR #17. [Stephen Arnold]

* README.md: test issue badge fix. [Stephen Arnold]

* Merge pull request #17 from git-afsantos/fix-16. [Steve Arnold]

  Swapped counting of Fan-in and Fan-out

* Swapped counting of fan-in and fan-out fixes #16. [André Santos]

* Merge pull request #14 from p2k-ko/per_function_metrics. [Steve Arnold]

  Patch for per function metrics in the detailed report; initialize with wmc1 instead of zero (contribution from p2k-ko).

* Initialized the number of functions per module with the wmc1 metric instead of zero. Added the test ouput files to the ignore list. [Stephan Schneider]

* Update Doxyfile HTML config. [Steve Arnold]

* Updated release version in readme header. [Steve Arnold]


## 3.1.5 (2016-02-11)

### Other

* Updated changelog/config, closed issues #2, #4, #6, and #7. [Steve Arnold]

* Updated (new) changelog from current version back to 3.1.3, closes issue #2. [Steve Arnold]

* Minor build clarification for the readme. [Steve Arnold]

* Add test config for code climate. [Steve Arnold]

* Added code climate status to readme file. [Steve Arnold]

* Formatting updates. [Steve Arnold]

* Added direct links to documentation. [Steve Arnold]

* Add irc notification. [Steve Arnold]

* Remove unsupported docs badge. [Steve Arnold]

* Swap out gcc package update for graphviz in travis-ci. [Steve Arnold]

* Let's see which gcc version is the latest... [Steve Arnold]

* Gcc-4.9 is also apparently not available in the default Docker image. [Steve Arnold]

* Sudo should apparently be false in a Docker image. [Steve Arnold]

* Add sudo to travis-ci config. [Steve Arnold]

* Update travis-ci build config to add doxygen and newer gcc. [Steve Arnold]

* Add docs badge and update travis-ci config. [Steve Arnold]

* Remove non-working badges, update formatting. [Steve Arnold]

* Update second issue badge source URL. [Steve Arnold]

* Update issue badge source URL. [Steve Arnold]

* Update issue pointer URL. [Steve Arnold]

* Add yet-another-issues-badge for testing. [Steve Arnold]

* Merge branch 'master' of github.com:sarnold/cccc. [Steve Arnold]

* Testing issue badges. [Steve Arnold]

* One more update. [Steve Arnold]

  reset tag to strict semantic version for testing

* Fix minor merge conflict in readme. [Steve Arnold]

* Back to previous version badge. [Steve Arnold]

* Update version badge. [Steve Arnold]

* More badge updates. [Steve Arnold]

  All should be working except maybe issues...

* Still more fiddling. [Steve Arnold]

* Still more fiddling. [Steve Arnold]

* More badge fiddling. [Steve Arnold]

* New badge test. [Steve Arnold]

* Add build status from travis-ci. [Steve Arnold]

* Remove newer make flag (default env is old) [Steve Arnold]

* Update script args to remove configure step. [Steve Arnold]

* Add travis-ci build config. [Steve Arnold]


## 3.1.5-rc.2 (2016-02-01)

### Other

* Minor makefile updates and one LFLAGS fix. [Steve Arnold]

* Shoehorn debug flags into multiple static makefiles. [Steve Arnold]

* Add required Ada defs. [Steve Arnold]

* Minor updates for RC1. [Steve Arnold]

* .github_changelog_generator: new config file. [Steve Arnold]

* Build_posixgcc.sh: minor update to make it compatible with new make targets. [Steve Arnold]

* Reverted simple format changelog. [Steve Arnold]

* Syncing up formatting changes. [Steve Arnold]

* Fix static formatting. [Steve Arnold]


## 3.1.5_rc1 (2015-09-19)

### Other

* Adding (auto)changelog and (static)history files. [Steve Arnold]

* Added license file pointer and updated readme. [Steve Arnold]

* Makefiles: remove hard-coded global flags and update clean targets. [Steve Arnold]

* Cccc_htm.cc: updated html footer and testref documents. [Steve Arnold]

* Merge branch 'gcc-warnings': source fixes and makefile cleanup. [Steve Arnold]

* Cleaned up pccts makefiles for portage builds. [Steve Arnold]

* Fixed pccts (antlr/dlg) compiler warnings. [Steve Arnold]

* Fixed cccc compiler warnings. [Steve Arnold]

* Update README.rst. [Steve Arnold]

* One last makefile cleanup (clean me up Scotty) [Steve Arnold]

* Updated .gitignore and cleaned up makefile handling of output directories. [Steve Arnold]

* Filter input to metrics target. [Steve Arnold]

* Added link to gh-pages docs to readme file. [Steve Arnold]

* Forgot last update for ebuild test phase. [Steve Arnold]

* Fixed typo in test target, all tests pass! [Steve Arnold]

* Don't build pccts for test, and remove sorcerer make target. [Steve Arnold]

* Final(?) makefile config and target updates. [Steve Arnold]

* Still testing makefile changes in portage. [Steve Arnold]

* Completed makefile updates for new build options. [Steve Arnold]

* Initial makefile updates for docs and metrics targets. [Steve Arnold]

* Pulled in updated readme from update branch. [Steve Arnold]

* First cleanup and unqualified-lookup fix. [Steve Arnold]

* Cleaned up source tree to match distribution. [Steve Arnold]

* Test commit to confirm sandbox is writeable. [tim_littlefair]


## V3_1_4 (2006-01-06)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_1_4'. [nobody]

* Fixing version numbering. [tim_littlefair]

* Fixed bad version numbering logic. [tim_littlefair]


## V3_1_3 (2006-01-06)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_1_3'. [nobody]

* Added win32 release script. [tim_littlefair]

* Added logic to terminate before test or installer if cccc.exe fails to build. Added -nologo to compiler flags. [tim_littlefair]


## V3_1_2 (2006-01-06)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_1_2'. [nobody]

* Work on Win32 installer. [tim_littlefair]


## V3_1_1 (2006-01-05)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_1_1'. [nobody]

* Changed to 3-part version numbers. [tim_littlefair]


## V3_1 (2006-01-05)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_1'. [nobody]

* Minor tweaks required to perfect win32 build. [tim_littlefair]

* Modified code + doco to reflect GPL licensing.  Reworked to build under GCC 4.0.2. [tim_littlefair]

* Added GPL license text to source and doco, reworked to ensure compilation and tests passed under GCC 4.0.2 (on Ubuntu 5.10 Breezy Badger) [tim_littlefair]

* Now includes a message that the project is dormant. [tim_littlefair]

* Patch from Diomidis Spinellis to avoid this error: cccc_utl.cc(358) : fatal error C1001: INTERNAL COMPILER ERROR                  (compiler file 'msc1.cpp', line 1188)      Please choose the Technical Support command on the Visual C++      Help menu, or open the Technical Support help file for more information. [tim_littlefair]

* Documentation changes, starting to work on making Win32 installer build a development environment. [tim_littlefair]

* Script to zip up source for transfer to virtual Linux machine. [tim_littlefair]

* Getting version numbering working. [tim_littlefair]

* Changes checked in in the course of updating the test and w32installer directory configurations to run under VCTK2003. [tim_littlefair]

* Modifications to support use of (free) MS Visual C++ Toolkit 2003 in place of MS Visual Studio 5/6. The free toolkit does not contain an implementation of make, this .bat file builds the sandbox explicitly. [tim_littlefair]

* Modifications to support use of (free) MS Visual C++ Toolkit 2003 in place of MS Visual Studio 5/6. For some reason, the use of friend functions IncrementNesting and DecrementNesting has stopped working (possibly because these functions are only seen as inline definitions within the CCCC_Token class body).  These have been converted to static member functions of CCCC_Token and all is now well. [tim_littlefair]

* Modifications to support use of (free) MS Visual C++ Toolkit 2003 in place of MS Visual Studio 5/6. Specifically, the FindFirstFile/FindNextFile APIs are not provided, _findfirst, _findnext are and work OK. [tim_littlefair]


## V3_pre84 (2004-02-28)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre84'. [nobody]

* Eliminated use of strstream class hierarchy, replaced with stringstream classes. Added prn16 test case to list for execution. [tim_littlefair]

  CVS ----------------------------------------------------------------------


## V3_pre83 (2003-08-31)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre83'. [nobody]


## V3_pre82 (2003-08-31)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre82'. [nobody]

* Added words on PRN16 fix. [tim_littlefair]

* Removed special logic to report module name as 'anonymous' if the actual module name is an empty string. This mapping is now done within the record_XXXXX_extent functions in cccc_utl.cc. [tim_littlefair]

* Adjusted reference output files to expect changed behaviour caused by the fix for PRN16. [tim_littlefair]

* Added filtering in the record_XXXXXX_extent functions to validate module and member name parameters (calls to these functions with empty module or member names may now be ignored). [tim_littlefair]

* Added a test case relating to prn16 (spurious lines with CCCC_Module@@@ in cccc.db). [tim_littlefair]

* Added typename keyword at various places in response to patch from Colin Watson, building for Debian packaging against GCC 3.3. [tim_littlefair]


## V3_pre81 (2003-08-12)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre81'. [nobody]

* Fixes required to make the makefile build under GCC 3.2 (Mandrake 9.0). [tim_littlefair]

* Last minute changes before 3.pre81. [tim_littlefair]

* Added VC addin to installer package. [tim_littlefair]

* Shortened usage message in the hope of getting it to fit in a single window. [tim_littlefair]


## V3_pre80 (2003-08-11)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre80'. [nobody]

* Fixed so that discovery of differences now cause make to stop. [tim_littlefair]

* Modified Edith Cowan URL. [tim_littlefair]

* Reworked command line interface. [tim_littlefair]

* Implemented XML reports analagous to existing HTML reports. [tim_littlefair]

* Implemented XML reports analagous to existing HTML reports. [tim_littlefair]

* Added logic to ensure division results are always rounded down to eliminate a difference in behaviour between Linux and Visual C++ builds on prn14. [tim_littlefair]

* Changes to wrappers for command line environment. [tim_littlefair]

* Adding test case for problem with large numbers of degenerate case labels (caused exponentially long processing times). [tim_littlefair]

* Fixed some parser generator warnings, also possibly handled 'virtual' keyword in inheritance lists either before, after or instead of the access control keyword. [tim_littlefair]

* Fixed problem with exponential growth of processing times for large number of degenerate case labels in Java code.  prn15.java tests for this problem. [tim_littlefair]


## V3_pre63 (2002-05-01)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre63'. [nobody]

* Modifying references to pre62 to mention pre63 instead. [tim_littlefair]

* Modified to make the installer work. [tim_littlefair]


## V3_pre62 (2002-05-01)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre62'. [nobody]

* Added some lines about the installer to readme.txt Modified rules.mak to make the output flags work on Win32. [tim_littlefair]


## V3_pre61 (2002-04-30)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre61'. [nobody]

* Added PRN14 (properly this time) [tim_littlefair]

* Change log for 3.pre61. [tim_littlefair]

* After fixing parse of prn14.java. [tim_littlefair]

* Added further tests related to literal float handling. [tim_littlefair]

* After fixing parse of prn13.java. [tim_littlefair]

* Adding example programs for the Sun Java Tutorial so that parse problems with these can be resolved. [tim_littlefair]

* Adding test case based on example program FadeAnim.java from the Sun Java tutorial. [tim_littlefair]

* Removed -z9 on export as it appears to cause a hang. [tim_littlefair]


## V3_pre59 (2002-04-23)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre59'. [nobody]

* Fixed several problems in java grammar including missing default keyword, incorrect handling of instanceof keyword, failure to parse floating point constants like 1f, and incorrect handling of escaped double quotes within strings.  The escaped double quote fix was also applied to the C++ grammar. [tim_littlefair]


## V3_pre58 (2002-04-22)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre58'. [nobody]

* These modifications create an initial working command line environment for CCCC. [tim_littlefair]

* Added space to makefiles. [cramus]

* Modified traling comments to reference mailto address for list rather than TL's hotmail address. [tim_littlefair]

* Fixes for Win32 installer environment. [tim_littlefair]

* Fixed reported compile error from GCC 2.96 and 3.X compilers. This should have been picked up as an error by GCC 2.95, but wasn't. [tim_littlefair]

* Corrected spelling mistake. [tim_littlefair]

* Make_ccccwrap.bat has become make_cccc_env.bat. [tim_littlefair]


## V3_pre57 (2002-04-02)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre57'. [nobody]


## V3_pre56 (2002-04-02)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre56'. [nobody]


## V3_pre55 (2002-04-02)

### Other

* This commit was manufactured by cvs2svn to create tag 'V3_pre55'. [nobody]

* Scripts to help in making releases. [tim_littlefair]

* Adding install script. [tim_littlefair]

* Adding logic to build installer with Inno setup. [tim_littlefair]

* Adding user documentation. [tim_littlefair]

* Attempting to fix problems parsing switch statements. [tim_littlefair]

* Fixes for PRNs 8-12. [tim_littlefair]

* Added bug reports directory. [tim_littlefair]

* Tests for PRNs 8-12. [tim_littlefair]

* Fixes for PRNs 8-12. [tim_littlefair]

* Fixing various code which does not compile under GCC 3.0.2. [tim_littlefair]

* Hacked PCCTS files to ensure that #endif directives do not have trailing text as this generates a warning under GCC 3.0.2. [tim_littlefair]


## v3pre54 (2001-11-04)

### Other

* This commit was manufactured by cvs2svn to create tag 'v3pre54'. [nobody]

* Updated for 3.pre54. [tim_littlefair]

* Added comments for 3.pre48 and 3.pre54. [tim_littlefair]

* Making the package build under Linux. [tim_littlefair]

* Verified everything runs OK in new sandbox. [tim_littlefair]

* Created build scripts for MSVC and BCC. [tim_littlefair]

* Modified makefiles for NMAKE. [tim_littlefair]

* Added makefile which enables build of Borland command line variant. [tim_littlefair]

* Adding a directory which was missing from the PCCTS distribution on SF. [tim_littlefair]

* *** empty log message *** [tim_littlefair]

* Removing sorcerer subdirectory. [tim_littlefair]

* Removed parts of the PCCTS distribution which are not useful when building CCCC. [tim_littlefair]

* Working on making test projects work under NMAKE. [tim_littlefair]

* Committing changes to makefile which I forgot to do in previous sandbox. [tim_littlefair]

* Added tests for prn7 (various compile problems reported by Larry Peters) and test4 for option file processing. [tim_littlefair]

* Implemented logic to handle dialect differences in the lexer. Test for this is test4 in the test suite. [tim_littlefair]

* No longer need the CygWin stuff as now use NMAKE.EXE for default build. [tim_littlefair]

* Removed files from Win32Bin directory. [tim_littlefair]

* Put in fixes for most of the parse problem examples submitted by Larry Peters at ATI. [tim_littlefair]

* Added logic to build under Borland C++ Builder and CygWin32 Fixed warnings and errors reported by C++ Builder. [tim_littlefair]


## v3pre48 (2001-04-12)

### Other

* This commit was manufactured by cvs2svn to create tag 'v3pre48'. [nobody]

* Initial revision. [tim_littlefair]

* Initial revision. [tim_littlefair]

* Initial revision. [tim_littlefair]

* Initial revision. [tim_littlefair]


## start (2001-04-12)

### Other

* This commit was manufactured by cvs2svn to create tag 'start'. [nobody]

* Initial revision. [tim_littlefair]

* Initial checkin. [root]


