# Microsoft Developer Studio Project File - Name="TUN_Convert" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TUN_Convert - Win32 Debug
!MESSAGE Dies ist kein gültiges Makefile. Zum Erstellen dieses Projekts mit NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und führen Sie den Befehl
!MESSAGE 
!MESSAGE NMAKE /f "TUN_Convert.mak".
!MESSAGE 
!MESSAGE Sie können beim Ausführen von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "TUN_Convert.mak" CFG="TUN_Convert - Win32 Debug"
!MESSAGE 
!MESSAGE Für die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "TUN_Convert - Win32 Release" (basierend auf  "Win32 (x86) Application")
!MESSAGE "TUN_Convert - Win32 Debug" (basierend auf  "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TUN_Convert - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 nafxcw.lib LIBCMT.lib libcpmt.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"nafxcw.lib LIBCMT.lib libcpmt.lib"

!ELSEIF  "$(CFG)" == "TUN_Convert - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 nafxcwd.lib LIBCMTD.lib libcpmtd.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"nafxcwd.lib LIBCMTD.lib libcpmtd.lib" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TUN_Convert - Win32 Release"
# Name "TUN_Convert - Win32 Debug"
# Begin Group "Quellcodedateien"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TUN_Convert.cpp
# End Source File
# Begin Source File

SOURCE=.\TUN_Convert.rc
# End Source File
# Begin Source File

SOURCE=.\TUN_ConvertDlg.cpp
# End Source File
# End Group
# Begin Group "Header-Dateien"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TUN_Convert.h
# End Source File
# Begin Source File

SOURCE=.\TUN_ConvertDlg.h
# End Source File
# End Group
# Begin Group "Ressourcendateien"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\TUN_Convert.ico
# End Source File
# Begin Source File

SOURCE=.\res\TUN_Convert.rc2
# End Source File
# End Group
# Begin Group "TUN"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\TUN_V2_Src\SCL_Import.cpp
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\SCL_Import.h
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_EmbedHTML.cpp
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_EmbedHTML.h
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_Error.h
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_Formula.h
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_MIDIChannelRange.h
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_MultiScaleFile.h
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_Scale.cpp
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_Scale.h
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_StringTools.cpp
# End Source File
# Begin Source File

SOURCE=..\TUN_V2_Src\TUN_StringTools.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
