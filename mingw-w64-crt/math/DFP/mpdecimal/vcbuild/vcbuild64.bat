@ECHO off

call vcvarsall x64

if not exist dist64 mkdir dist64
if exist dist64\* del /q dist64\*

cd ..\libmpdec
copy /y Makefile.vc Makefile

nmake clean
nmake MACHINE=x64

copy /y libmpdec-2.4.0.lib ..\vcbuild\dist64
copy /y ..\tests\runtest.exe ..\vcbuild\dist64\runtest.exe

nmake clean
rem comment out the next line for PGO build
nmake MACHINE=x64 DLL=1
rem uncomment the next line for PGO build
rem nmake MACHINE=x64 DLL=1 profile

copy /y libmpdec-2.4.0.dll ..\vcbuild\dist64
copy /y libmpdec-2.4.0.dll.lib ..\vcbuild\dist64
copy /y libmpdec-2.4.0.dll.exp ..\vcbuild\dist64
copy /y mpdecimal.h ..\vcbuild\dist64


cd ..\vcbuild



