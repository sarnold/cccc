# Microsoft Developer Studio Project File - Name="cccc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) External Target" 0x0106

CFG=cccc - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Cccc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Cccc.mak" CFG="cccc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cccc - Win32 Release" (based on "Win32 (x86) External Target")
!MESSAGE "cccc - Win32 Debug" (based on "Win32 (x86) External Target")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "cccc - Win32 Release"

# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Cmd_Line "NMAKE /f cccc.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "cccc.exe"
# PROP BASE Bsc_Name "cccc.bsc"
# PROP BASE Target_Dir ""
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Cmd_Line "nmake -f w32vc.mak DEBUG=false"
# PROP Rebuild_Opt ""
# PROP Target_File "\ccccprod\bin\cccc.exe"
# PROP Bsc_Name ""
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "cccc - Win32 Debug"

# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Cmd_Line "NMAKE /f cccc.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "cccc.exe"
# PROP BASE Bsc_Name "cccc.bsc"
# PROP BASE Target_Dir ""
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Cmd_Line "nmake -f w32vc.mak DEBUG=true"
# PROP Rebuild_Opt "clean all"
# PROP Target_File "cccc.exe"
# PROP Bsc_Name ""
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "cccc - Win32 Release"
# Name "cccc - Win32 Debug"

!IF  "$(CFG)" == "cccc - Win32 Release"

!ELSEIF  "$(CFG)" == "cccc - Win32 Debug"

!ENDIF 

# Begin Group "PCCTS grammars"

# PROP Default_Filter "g"
# Begin Source File

SOURCE=.\ada.g
# End Source File
# Begin Source File

SOURCE=.\cccc.g
# End Source File
# Begin Source File

SOURCE=.\java.g
# End Source File
# End Group
# Begin Group "C++ header files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\cccc.h
# End Source File
# Begin Source File

SOURCE=.\cccc_db.h
# End Source File
# Begin Source File

SOURCE=.\cccc_ext.h
# End Source File
# Begin Source File

SOURCE=.\cccc_htm.h
# End Source File
# Begin Source File

SOURCE=.\cccc_itm.h
# End Source File
# Begin Source File

SOURCE=.\cccc_mem.h
# End Source File
# Begin Source File

SOURCE=.\cccc_met.h
# End Source File
# Begin Source File

SOURCE=.\cccc_mod.h
# End Source File
# Begin Source File

SOURCE=.\cccc_opt.h
# End Source File
# Begin Source File

SOURCE=.\cccc_prj.h
# End Source File
# Begin Source File

SOURCE=.\cccc_rec.h
# End Source File
# Begin Source File

SOURCE=.\cccc_tbl.h
# End Source File
# Begin Source File

SOURCE=.\cccc_tok.h
# End Source File
# Begin Source File

SOURCE=.\cccc_use.h
# End Source File
# Begin Source File

SOURCE=.\cccc_utl.h
# End Source File
# End Group
# Begin Group "C++ implementation files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\cccc_db.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_ext.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_htm.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_itm.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_mem.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_met.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_mod.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_new.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_opt.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_prj.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_rec.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_tbl.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_tok.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_tpl.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_use.cc
# End Source File
# Begin Source File

SOURCE=.\cccc_utl.cc
# End Source File
# Begin Source File

SOURCE=.\ccccmain.cc
# End Source File
# End Group
# Begin Group "makefiles"

# PROP Default_Filter "*.mak"
# Begin Source File

SOURCE=.\posixgcc.mak
# End Source File
# Begin Source File

SOURCE=.\rules.mak
# End Source File
# Begin Source File

SOURCE=.\w32bcb.mak
# End Source File
# Begin Source File

SOURCE=.\w32cygnus.mak
# End Source File
# Begin Source File

SOURCE=.\w32cygnus_gmake.mak
# End Source File
# Begin Source File

SOURCE=.\w32cygnus_nmake.mak
# End Source File
# Begin Source File

SOURCE=.\w32vc.mak
# End Source File
# End Group
# End Target
# End Project
