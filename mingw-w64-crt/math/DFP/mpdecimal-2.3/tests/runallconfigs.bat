@ECHO OFF

cd ..\
copy /y Makefile.vc Makefile
cd tests
copy /y Makefile.vc Makefile
call gettests.bat
call getdn.bat


call vcvarsall x64

echo.
echo # ========================================================================
echo #                                   x64
echo # ========================================================================
echo.
cd ..\
nmake clean
nmake MACHINE=x64 extended_deccheck
cd tests
call runalltests.bat


echo.
echo # ========================================================================
echo #                                 ansi64
echo # ========================================================================
echo.
cd ..\
nmake clean
nmake MACHINE=ansi64 extended_deccheck
cd tests
call runalltests.bat


echo.
echo # ========================================================================
echo #                             full_coverage
echo # ========================================================================
echo.
cd ..\
nmake clean
nmake MACHINE=full_coverage extended_deccheck
cd tests
call runalltests.bat


call vcvarsall x86

echo.
echo # ========================================================================
echo #                                  ppro
echo # ========================================================================
echo.
cd ..\
nmake clean
nmake MACHINE=ppro extended_deccheck
cd tests
call runalltests.bat

echo.
echo # ========================================================================
echo #                                ansi32
echo # ========================================================================
echo.
cd ..\
nmake clean
nmake MACHINE=ansi32 extended_deccheck
cd tests
call runalltests.bat

echo.
echo # ========================================================================
echo #                              ansi-legacy
echo # ========================================================================
echo.
cd ..\
nmake clean
nmake MACHINE=ansi-legacy extended_deccheck
cd tests
call runalltests.bat



