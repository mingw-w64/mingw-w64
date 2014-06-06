@ECHO off

call vcvarsall x64

cd ..\libmpdec
if exist Makefile nmake clean

cd ..\vcbuild
if exist dist64 rd /q /s dist64
if exist dist32 rd /q /s dist32


