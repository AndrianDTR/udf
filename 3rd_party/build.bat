@echo on

SET TEMP=a:\
SET TMP=a:\
set BUILDTYPE=Debug

set BOOST=boost_1_50_0
set MYSQL=mysql-connector-c++-1.1.0
set WXWIDGETS=wxWidgets-2.9.4

if not exist "C:\Program Files\Microsoft Visual Studio 9.0\" (
echo Install Visual Studio 9 Express build first.
goto end
)

if not exist "C:\Program Files\MySQL\" (
echo Download and install MySQL.
goto end
)

if not exist "C:\Program Files\CMake 2.8\" (
echo Download and install CMake 2.8.
goto end
)

if not exist "%BOOST%\" (
echo Extract BOOST sources.
tar -xf %BOOST%.tar.gz
)

if not exist "%MYSQL%\" (
echo Extract MySQL Connector sources.
tar -xf %MYSQL%.tar.gz
)

if not exist "%WXWIDGETS%\" (
echo Extract wxWidgets sources.
tar -xf %WXWIDGETS%.tar.bz2
)

if not exist "%MYSQL%\driver\%BUILDTYPE%\" (
cd %MYSQL%
cmake -G "Visual Studio 9 2008" -DBOOST_ROOT=../%BOOST% -DCMAKE_BUILD_TYPE=%BUILDTYPE% -DMYSQLCPPCONN_BUILD_EXAMPLES=0 
cd ..
)

echo Set build environment.
call "%VS90COMNTOOLS%vsvars32.bat"

@echo Building MySQL Connector %BUILDTYPE% configuration...
devenv.exe "%MYSQL%\MYSQLCPPCONN.sln" /build %BUILDTYPE%
if %ERRORLEVEL% NEQ 0 (
@echo Build error, return code %ERRORLEVEL%!
goto end
)
@echo OK.

@echo Building wxWidgets %BUILDTYPE% configuration...
devenv.exe "%WXWIDGETS%\build\msw\wx_vc9.sln" /build %BUILDTYPE%
if %ERRORLEVEL% NEQ 0 (
@echo Build error, return code %ERRORLEVEL%!
goto end
)
@echo OK.

end:
