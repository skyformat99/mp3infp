# Microsoft Developer Studio Project File - Name="libmp4v2_st" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=libmp4v2_st - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "libmp4v2_st60.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "libmp4v2_st60.mak" CFG="libmp4v2_st - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "libmp4v2_st - Win32 Release" ("Win32 (x86) Static Library" 用)
!MESSAGE "libmp4v2_st - Win32 Debug" ("Win32 (x86) Static Library" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "libmp4v2_st - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ST_Release"
# PROP Intermediate_Dir "ST_Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "libmp4v2_st - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "ST_Debug"
# PROP Intermediate_Dir "ST_Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /GX /Z7 /Od /I "..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "libmp4v2_st - Win32 Release"
# Name "libmp4v2_st - Win32 Debug"
# Begin Group "source"

# PROP Default_Filter ".c, .cpp"
# Begin Source File

SOURCE=.\3gp.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_amr.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_avc1.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_avcC.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_d263.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_damr.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_dref.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_elst.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_enca.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_encv.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_free.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_ftyp.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_hdlr.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_hinf.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_hnti.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_href.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_mdat.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_mdhd.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_meta.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_mp4s.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_mp4v.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_mvhd.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_root.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_rtp.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_s263.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_sdp.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_smi.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_sound.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_standard.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_stbl.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_stdp.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_stsc.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_stsd.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_stsz.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_tfhd.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_tkhd.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_treftype.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_trun.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_udta.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_url.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_urn.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_video.cpp
# End Source File
# Begin Source File

SOURCE=.\atom_vmhd.cpp
# End Source File
# Begin Source File

SOURCE=.\descriptors.cpp
# End Source File
# Begin Source File

SOURCE=.\isma.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4atom.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4container.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4descriptor.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4file.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4file_io.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4info.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4meta.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4property.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4track.cpp
# End Source File
# Begin Source File

SOURCE=.\mp4util.cpp
# End Source File
# Begin Source File

SOURCE=.\ocidescriptors.cpp
# End Source File
# Begin Source File

SOURCE=.\odcommands.cpp
# End Source File
# Begin Source File

SOURCE=.\qosqualifiers.cpp
# End Source File
# Begin Source File

SOURCE=.\rtphint.cpp
# End Source File
# End Group
# Begin Group "include"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=.\atoms.h
# End Source File
# Begin Source File

SOURCE=.\descriptors.h
# End Source File
# Begin Source File

SOURCE=.\mp4.h
# End Source File
# Begin Source File

SOURCE=.\mp4array.h
# End Source File
# Begin Source File

SOURCE=.\mp4atom.h
# End Source File
# Begin Source File

SOURCE=.\mp4common.h
# End Source File
# Begin Source File

SOURCE=.\mp4container.h
# End Source File
# Begin Source File

SOURCE=.\mp4descriptor.h
# End Source File
# Begin Source File

SOURCE=.\mp4file.h
# End Source File
# Begin Source File

SOURCE=.\mp4property.h
# End Source File
# Begin Source File

SOURCE=.\mp4track.h
# End Source File
# Begin Source File

SOURCE=.\mp4util.h
# End Source File
# Begin Source File

SOURCE=.\ocidescriptors.h
# End Source File
# Begin Source File

SOURCE=.\odcommands.h
# End Source File
# Begin Source File

SOURCE=.\qosqualifiers.h
# End Source File
# Begin Source File

SOURCE=.\rtphint.h
# End Source File
# End Group
# End Target
# End Project
