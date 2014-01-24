@ECHO OFF

if exist decimaltestdata goto END
if exist ..\..\default\Lib\test\decimaltestdata xcopy /E /Q /Y ..\..\default\Lib\test\decimaltestdata .
if exist decimaltestdata goto END

wget http://hg.python.org/cpython/archive/tip.zip
unzip -qq tip.zip cpython*/Lib/test/decimaltestdata/*
cd cpython*
cd Lib\test
move decimaltestdata ..\..\..\
cd ..\..\..\
rm tip.zip
rm -rf cpython*


:END


