@ECHO OFF

if exist testdata goto NEXT

wget -nv http://speleotrove.com/decimal/dectest.zip
mkdir testdata
cd testdata
unzip -qq ../dectest.zip
cd ..

:NEXT

if not exist testdata\baseconv.decTest copy /y testdata_dist\* testdata


