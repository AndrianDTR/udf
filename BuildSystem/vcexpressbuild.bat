@echo off

mkdir build
cd build

call cmake ../.

call "%VS90COMNTOOLS%vsvars32.bat"

@echo Building WX configuration...
devenv.exe "3rd_party\wx_widgets-prefix\src\wxWidgets-2.9.4\build\msw\wx_vc9.sln" /build Release 
if %ERRORLEVEL% NEQ 0 (
@echo Build error, return code %ERRORLEVEL%!
cd ..
exit %ERRORLEVEL%
)
@echo OK.


@echo Building Release configuration...
devenv.exe "%1" /build Release 
if %ERRORLEVEL% NEQ 0 (
@echo Build error, return code %ERRORLEVEL%!
cd ..
exit %ERRORLEVEL%
)
@echo OK.

@echo Building Debug configuration...
devenv.exe "%1" /build Debug 
if %ERRORLEVEL% NEQ 0 (
@echo Build error, return code %ERRORLEVEL%!
cd ..
exit %ERRORLEVEL%
)
@echo OK.
