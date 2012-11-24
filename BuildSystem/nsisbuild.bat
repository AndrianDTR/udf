@echo off
@echo Compiling setup package...
"%NSISBIN%\makensis.exe" /O"%1" /DPRODUCT_VERSION=%2 "%3"
if %ERRORLEVEL% NEQ 0 (
@echo Compilation error, return code %ERRORLEVEL%!
@echo See NSISLOG.TXT for details.
exit %ERRORLEVEL%
)
@echo OK.
