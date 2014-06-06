@ECHO off

call vcvarsall x64

cd ..\libmpdec
if exist Makefile nmake distclean

cd ..\vcbuild
if exist additional.decTest del /q additional.decTest
if exist official.decTest del /q official.decTest
if exist dectest.zip del /q dectest.zip
if exist dist64 rd /q /s dist64
if exist dist32 rd /q /s dist32
if exist testdata rd /q /s testdata



