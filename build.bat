@echo off
set PATH0=%PATH%
set PATH=%PATH0%;%CD%\tools\apache-ant-1.8.4\bin\

echo *********************************************************************
echo * Build ...
echo *********************************************************************
set srcDir=%CD%
cd BuildSystem

SET TEMP=a:\
SET TMP=a:\
ant -logfile build_log.txt

cd ..
echo *********************************************************************
echo * Finished !
echo *********************************************************************
