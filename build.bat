@echo off
set PATH0=%PATH%
set PATH=C:\Program Files\Common Files\Microsoft Shared\Windows Live;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\Program Files\ATI Technologies\ATI.ACE\Core-Static;C:\Program Files\Microchip\MPLAB C32 Suite\bin;C:\Program Files\doxygen\bin;C:\Program Files\TortoiseSVN\bin;C:\Program Files\VisualSVN\bin;C:\Program Files\CMake 2.8\bin;C:\Program Files\TortoiseGit\bin;C:\MinGW\bin;

echo *********************************************************************
echo * Build 3rd party libraries ...
echo *********************************************************************
set srcDir=%CD%

cd 3rd_party
rem start /B /wait build_wxWidgets.bat release 0 1 1

echo *********************************************************************
echo * Build UDF ...
echo *********************************************************************

cd %srcDir%

del /f /q build/*
mkdir build
cd build
cmake -G "MinGW Makefiles" -g0 -O4 ../
mingw32-make -j 4
rem -f makefile.gcc BUILD=release UNICODE=1 MONOLITHIC=1 SHARED=1 
rem cmd /c mingw32-make

cd ..

echo *********************************************************************
echo * Finished !
echo *********************************************************************
