@ECHO off

call vcvarsall x86

if not exist dist32 mkdir dist32
if exist dist32\* del /q dist32\*

cd ..\libmpdec
copy /y Makefile.vc Makefile

nmake clean
nmake MACHINE=ppro

copy /y libmpdec-2.4.0.lib ..\vcbuild\dist32
copy /y ..\tests\runtest.exe ..\vcbuild\dist32\runtest.exe

nmake clean
rem comment out the next line for PGO build
nmake MACHINE=ppro DLL=1
rem uncomment the next line for PGO build
rem nmake MACHINE=ppro DLL=1 profile

copy /y libmpdec-2.4.0.dll ..\vcbuild\dist32
copy /y libmpdec-2.4.0.dll.lib ..\vcbuild\dist32
copy /y libmpdec-2.4.0.dll.exp ..\vcbuild\dist32
copy /y mpdecimal.h ..\vcbuild\dist32


cd ..\vcbuild



