# makefile to control installation of CCCC

ifeq "$(CONF)" "w32vc"
CD=cd
CP=../w32bin/cp
RM=../w32bin/rm -f
RMDIR=../w32bin/rm -rf
MV=../w32bin/mv
ECHO=../w32bin/echo
DIFF=../w32bin/diff
MKDIR=../w32bin/mkdir
INSTBIN1=cccc.exe
INSTBIN2=CcccDevStudioAddIn.dll
INSTDIR=C:/Program\ Files/CCCC
else
CD=cd
CP=cp
RM=rm -f
RMDIR=rm -rf
MV=mv
ECHO=echo
DIFF=diff
MKDIR=mkdir
INSTBIN1=cccc
INSTBIN2=
INSTDIR=/usr/local/bin
endif

# The installation is pretty crude
# we just go to the target directory for the machine
# we are on, delete old versions, copy new versions in
# There are lots of nicer things we could do on either 
# platform, but this is the lowest common denominator which
# works consistently on both.
ifeq "$(CONF)" "w32vc"
all : install_cccc install_addin report_success
else
all : install_cccc report_success
endif

install_cccc :
	-$(MKDIR) $(INSTDIR)
	-$(RM) $(INSTDIR)/$(INSTBIN1)
	$(CP) ../cccc/$(INSTBIN1) $(INSTDIR)

install_addin :
	-$(RM) $(INSTDIR)/$(INSTBIN2)
	$(CP) ../vcaddin/$(VARIANT)/$(INSTBIN2) $(INSTDIR)

# There are potential error messages relating to directories which
# already existed, which will be ignored, because we are being conservative
# and attempting creation unconditionally (so we don't have to ship Win32 
# bash and test).
# So we finish the process with a message reassuring the user that all went well
report_success :
	@$(ECHO) ===========================
	@$(ECHO) Installation succeeded!
	@$(ECHO) ===========================

