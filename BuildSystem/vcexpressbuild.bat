@echo off

call "%VS90COMNTOOLS%vsvars32.bat"

@echo Building Release configuration...
devenv.exe "%1" /build Release 
if %ERRORLEVEL% NEQ 0 (
@echo Build error, return code %ERRORLEVEL%!
cd ..
exit %ERRORLEVEL%
)
@echo OK.
