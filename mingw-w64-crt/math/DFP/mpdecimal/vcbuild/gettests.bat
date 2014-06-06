@ECHO OFF

if not exist official.decTest copy /y ..\tests\official.decTest .
if not exist additional.decTest copy /y ..\tests\additional.decTest .

if not exist testdata mkdir testdata
rem copy additional tests
if not exist testdata\baseconv.decTest copy /y ..\tests\testdata_dist\* testdata

if exist testdata\add.decTest goto OUT

rem get official tests
wget -nv http://speleotrove.com/decimal/dectest.zip
cd testdata
unzip -qq ../dectest.zip
cd ..

:OUT


