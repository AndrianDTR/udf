@echo off
call "%VS90COMNTOOLS%vsvars32.bat"

@echo Building Release configuration...
devenv.exe "%1" /build Release 
if %ERRORLEVEL% NEQ 0 (
@echo Build error, return code %ERRORLEVEL%!
exit %ERRORLEVEL%
)
@echo OK.

@echo Building Debug configuration...
devenv.exe "%1" /build Debug 
if %ERRORLEVEL% NEQ 0 (
@echo Build error, return code %ERRORLEVEL%!
exit %ERRORLEVEL%
)
@echo OK.
