@echo off
echo *********************************************************************
echo * Build wxWidgets libraries, please wait
echo *********************************************************************

set wxNAME=wxWidgets
set wxVER_MAJ=2
set wxVER_MIN=9
set wxVER_BUILD=3
set wxARCH_EXT=tar.bz2
set wxBuildDir=build\msw
set minGW_Path=C:\MinGW\bin
set wxBuildType=%1%
set wxBuildShared=%2%
set wxBuildUnicode=%3%
set wxBuildMono=%4%

SET wxDir=%CD%\%wxNAME%-%wxVER_MAJ%.%wxVER_MIN%.%wxVER_BUILD%
set wxBuildPath=%wxDir%\%wxBuildDir%

if not EXIST %wxDir% ( 
	if not EXIST %wxDir%.%wxARCH_EXT% ( 
		@echo * WxWidgets archive found!
		exit /B 1
	)
	
	echo * UNTAR wxWidgets .....
	c:\7-Zip\7z -y x %wxNAME%-%wxVER_MAJ%.%wxVER_MIN%.%wxVER_BUILD%.%wxARCH_EXT%
	c:\7-Zip\7z x %wxNAME%-%wxVER_MAJ%.%wxVER_MIN%.%wxVER_BUILD%.tar	 
)

if not exist %wxBuildPath% (
	echo * UNTAR wxWidgets .....
	c:\7-Zip\7z -y x %wxNAME%-%wxVER_MAJ%.%wxVER_MIN%.%wxVER_BUILD%.%wxARCH_EXT%
	c:\7-Zip\7z x %wxNAME%-%wxVER_MAJ%.%wxVER_MIN%.%wxVER_BUILD%.tar	 
)

:build
if not exist %wxBuildPath% (
	echo "* WxWidgets build folder (%wxBuildPath%) couldn't be found!"
	exit /B 1
) else (
	cd %wxBuildPath%
	if not exist gcc_mswu mkdir gcc_mswu
	if not exist ..\..\lib\gcc_lib\mswu mkdir ..\..\lib\gcc_lib\mswu
	if not exist ..\..\lib\gcc_lib\mswu\wx mkdir ..\..\lib\gcc_lib\mswu\wx
	if not exist ..\..\lib\gcc_lib\mswu\wx\setup.h copy ..\..\include\wx\msw\setup.h ..\..\lib\gcc_lib\mswu\wx\setup.h
	if not exist gcc_mswud mkdir gcc_mswud
	if not exist ..\..\lib\gcc_lib\mswud mkdir ..\..\lib\gcc_lib\mswud
	if not exist ..\..\lib\gcc_lib\mswud\wx mkdir ..\..\lib\gcc_lib\mswud\wx
	if not exist ..\..\lib\gcc_lib\mswud\wx\setup.h copy ..\..\include\wx\msw\setup.h ..\..\lib\gcc_lib\mswud\wx\setup.h
	
	ping -n 5 127.0.0.1 > nul
	
	%minGW_Path%\MinGW32-make.exe -j 4 -f Makefile.gcc SHARED=%wxBuildShared% UNICODE=%wxBuildUnicode% BUILD=%wxBuildType% MONOLITHIC=%wxBuildMono%
)

:finish
echo *********************************************************************
echo * Build wxWidgets are finished
echo *********************************************************************

exit
