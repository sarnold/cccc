# Microsoft Developer Studio Generated NMAKE File, Based on CcccDevStudioAddIn.dsp
!IF "$(CFG)" == ""
CFG=CcccDevStudioAddIn - Win32 Debug
!MESSAGE No configuration specified. Defaulting to CcccDevStudioAddIn - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CcccDevStudioAddIn - Win32 Release" && "$(CFG)" != "CcccDevStudioAddIn - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CcccDevStudioAddIn.mak" CFG="CcccDevStudioAddIn - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CcccDevStudioAddIn - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CcccDevStudioAddIn - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Release"

OUTDIR=.\release
INTDIR=.\release
# Begin Custom Macros
OutDir=.\release
# End Custom Macros

ALL : "$(OUTDIR)\CcccDevStudioAddIn.dll" "$(OUTDIR)\CcccDevStudioAddIn.tlb"


CLEAN :
	-@erase "$(INTDIR)\CcccDevStudioAddIn.obj"
	-@erase "$(INTDIR)\CcccDevStudioAddIn.pch"
	-@erase "$(INTDIR)\CcccDevStudioAddIn.res"
	-@erase "$(INTDIR)\CcccDevStudioAddIn.tlb"
	-@erase "$(INTDIR)\CommandForm.obj"
	-@erase "$(INTDIR)\Commands.obj"
	-@erase "$(INTDIR)\DevStudioFileStore.obj"
	-@erase "$(INTDIR)\DSAddIn.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CcccDevStudioAddIn.dll"
	-@erase "$(OUTDIR)\CcccDevStudioAddIn.exp"
	-@erase "$(OUTDIR)\CcccDevStudioAddIn.lib"
	-@erase ".\CcccDevStudioAddInTypes.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\CcccDevStudioAddIn.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0xc09 /fo"$(INTDIR)\CcccDevStudioAddIn.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CcccDevStudioAddIn.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=mapi32.lib mpr.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\CcccDevStudioAddIn.pdb" /machine:I386 /def:".\CcccDevStudioAddIn.def" /out:"$(OUTDIR)\CcccDevStudioAddIn.dll" /implib:"$(OUTDIR)\CcccDevStudioAddIn.lib" 
DEF_FILE= \
	".\CcccDevStudioAddIn.def"
LINK32_OBJS= \
	"$(INTDIR)\CcccDevStudioAddIn.obj" \
	"$(INTDIR)\CommandForm.obj" \
	"$(INTDIR)\Commands.obj" \
	"$(INTDIR)\DevStudioFileStore.obj" \
	"$(INTDIR)\DSAddIn.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CcccDevStudioAddIn.res"

"$(OUTDIR)\CcccDevStudioAddIn.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"

OUTDIR=.\debug
INTDIR=.\debug
# Begin Custom Macros
OutDir=.\debug
# End Custom Macros

ALL : "$(OUTDIR)\CcccDevStudioAddIn.dll" "$(OUTDIR)\CcccDevStudioAddIn.tlb" ".\CcccDevStudioAddInTypes.h" "$(OUTDIR)\CcccDevStudioAddIn.bsc"


CLEAN :
	-@erase "$(INTDIR)\CcccDevStudioAddIn.obj"
	-@erase "$(INTDIR)\CcccDevStudioAddIn.pch"
	-@erase "$(INTDIR)\CcccDevStudioAddIn.res"
	-@erase "$(INTDIR)\CcccDevStudioAddIn.sbr"
	-@erase "$(INTDIR)\CcccDevStudioAddIn.tlb"
	-@erase "$(INTDIR)\CommandForm.obj"
	-@erase "$(INTDIR)\CommandForm.sbr"
	-@erase "$(INTDIR)\Commands.obj"
	-@erase "$(INTDIR)\Commands.sbr"
	-@erase "$(INTDIR)\DevStudioFileStore.obj"
	-@erase "$(INTDIR)\DevStudioFileStore.sbr"
	-@erase "$(INTDIR)\DSAddIn.obj"
	-@erase "$(INTDIR)\DSAddIn.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CcccDevStudioAddIn.bsc"
	-@erase "$(OUTDIR)\CcccDevStudioAddIn.dll"
	-@erase "$(OUTDIR)\CcccDevStudioAddIn.exp"
	-@erase "$(OUTDIR)\CcccDevStudioAddIn.ilk"
	-@erase "$(OUTDIR)\CcccDevStudioAddIn.lib"
	-@erase "$(OUTDIR)\CcccDevStudioAddIn.pdb"
	-@erase ".\CcccDevStudioAddInTypes.h"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CcccDevStudioAddIn.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32 
RSC=rc.exe
RSC_PROJ=/l 0xc09 /fo"$(INTDIR)\CcccDevStudioAddIn.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CcccDevStudioAddIn.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CcccDevStudioAddIn.sbr" \
	"$(INTDIR)\CommandForm.sbr" \
	"$(INTDIR)\Commands.sbr" \
	"$(INTDIR)\DevStudioFileStore.sbr" \
	"$(INTDIR)\DSAddIn.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\CcccDevStudioAddIn.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=mapi32.lib mpr.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\CcccDevStudioAddIn.pdb" /debug /machine:I386 /def:".\CcccDevStudioAddIn.def" /out:"$(OUTDIR)\CcccDevStudioAddIn.dll" /implib:"$(OUTDIR)\CcccDevStudioAddIn.lib" /pdbtype:sept 
DEF_FILE= \
	".\CcccDevStudioAddIn.def"
LINK32_OBJS= \
	"$(INTDIR)\CcccDevStudioAddIn.obj" \
	"$(INTDIR)\CommandForm.obj" \
	"$(INTDIR)\Commands.obj" \
	"$(INTDIR)\DevStudioFileStore.obj" \
	"$(INTDIR)\DSAddIn.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CcccDevStudioAddIn.res"

"$(OUTDIR)\CcccDevStudioAddIn.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("CcccDevStudioAddIn.dep")
!INCLUDE "CcccDevStudioAddIn.dep"
!ELSE 
!MESSAGE Warning: cannot find "CcccDevStudioAddIn.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CcccDevStudioAddIn - Win32 Release" || "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"
SOURCE=.\CcccDevStudioAddIn.cpp

!IF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Release"


"$(INTDIR)\CcccDevStudioAddIn.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch" ".\CcccDevStudioAddInTypes.h"


!ELSEIF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"


"$(INTDIR)\CcccDevStudioAddIn.obj"	"$(INTDIR)\CcccDevStudioAddIn.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch"


!ENDIF 

SOURCE=.\CcccDevStudioAddIn.odl

!IF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Release"

MTL_SWITCHES=/nologo /D "NDEBUG" /tlb "$(OUTDIR)\CcccDevStudioAddIn.tlb" /h "CcccDevStudioAddInTypes.h" /mktyplib203 /o "NUL" /win32 

"$(OUTDIR)\CcccDevStudioAddIn.tlb"	".\CcccDevStudioAddInTypes.h" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"

MTL_SWITCHES=/nologo /D "_DEBUG" /tlb "$(OUTDIR)\CcccDevStudioAddIn.tlb" /h "CcccDevStudioAddInTypes.h" /mktyplib203 /o "NUL" /win32 

"$(OUTDIR)\CcccDevStudioAddIn.tlb"	".\CcccDevStudioAddInTypes.h" : $(SOURCE) "$(OUTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\CcccDevStudioAddIn.rc

!IF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Release"


"$(INTDIR)\CcccDevStudioAddIn.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0xc09 /fo"$(INTDIR)\CcccDevStudioAddIn.res" /i "release" /d "NDEBUG" /d "_AFXDLL" $(SOURCE)


!ELSEIF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"


"$(INTDIR)\CcccDevStudioAddIn.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0xc09 /fo"$(INTDIR)\CcccDevStudioAddIn.res" /i "debug" /d "_DEBUG" /d "_AFXDLL" $(SOURCE)


!ENDIF 

SOURCE=.\CommandForm.cpp

!IF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Release"


"$(INTDIR)\CommandForm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch"


!ELSEIF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"


"$(INTDIR)\CommandForm.obj"	"$(INTDIR)\CommandForm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch"


!ENDIF 

SOURCE=.\Commands.cpp

!IF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Release"


"$(INTDIR)\Commands.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch" ".\CcccDevStudioAddInTypes.h"


!ELSEIF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"


"$(INTDIR)\Commands.obj"	"$(INTDIR)\Commands.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch"


!ENDIF 

SOURCE=.\DevStudioFileStore.cpp

!IF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Release"


"$(INTDIR)\DevStudioFileStore.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch"


!ELSEIF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"


"$(INTDIR)\DevStudioFileStore.obj"	"$(INTDIR)\DevStudioFileStore.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch"


!ENDIF 

SOURCE=.\DSAddIn.cpp

!IF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Release"


"$(INTDIR)\DSAddIn.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch" ".\CcccDevStudioAddInTypes.h"


!ELSEIF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"


"$(INTDIR)\DSAddIn.obj"	"$(INTDIR)\DSAddIn.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CcccDevStudioAddIn.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /Fp"$(INTDIR)\CcccDevStudioAddIn.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CcccDevStudioAddIn.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CcccDevStudioAddIn - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CcccDevStudioAddIn.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\CcccDevStudioAddIn.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

