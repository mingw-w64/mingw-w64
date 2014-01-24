@ECHO OFF
call gettests.bat
echo.
<nul (set /p x="Running official tests ... ")
runtest.exe official.decTest
IF NOT ERRORLEVEL 1 echo PASS
<nul (set /p x="Running additional tests ... ")
runtest.exe additional.decTest
IF NOT ERRORLEVEL 1 echo PASS
echo.


