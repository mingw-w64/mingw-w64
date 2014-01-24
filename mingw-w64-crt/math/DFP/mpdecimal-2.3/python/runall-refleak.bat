@ECHO OFF

cd ..

for %%b in (2.7 3.2 3.3) do (
  for %%a in ("--without-threads" "") do (
    for %%f in (yes no) do (

      if %%f==yes patch < python\failapi2.diff
      if %%f==yes patch < python\failapi3.diff

      if %%b==2.6 copy /y python\test_cdecimal2.py ..\2.6\Lib\test\test_cdecimal.py
      if %%b==2.7 copy /y python\test_cdecimal2.py ..\2.7\Lib\test\test_cdecimal.py
      if %%b==3.1 copy /y python\test_cdecimal3.py ..\3.1\Lib\test\test_cdecimal.py
      if %%b==3.2 copy /y python\test_cdecimal3.py ..\3.2\Lib\test\test_cdecimal.py
      if %%b==3.3 copy /y python\test_cdecimal3.py ..\3.3\Lib\test\test_cdecimal.py

      echo.
      echo # ========================================================================
      echo #        platform=x64 branch=%%b args=%%a failapi=%%f
      echo # ========================================================================
      echo.

      rd /q /s build
      ..\%%b\PCbuild\amd64\python_d.exe setup.py build -g %%a

      copy /y build\lib.win-amd64-%%b-pydebug\cdecimal_d.pyd ..\%%b\PCbuild\amd64

      cd ..\%%b
      echo.
      PCbuild\amd64\python_d.exe Lib\test\regrtest.py -uall -R 2:2:reflog.txt test_cdecimal
      echo.

      cd ..\mpdecimal

      echo.
      echo # ========================================================================
      echo #        platform=x86 branch=%%b args=%%a failapi=%%f
      echo # ========================================================================
      echo.

      rd /q /s build
      ..\%%b\PCbuild\python_d.exe setup.py build -g %%a

      copy /y build\lib.win32-%%b-pydebug\cdecimal_d.pyd ..\%%b\PCbuild

      cd ..\%%b
      echo.
      PCbuild\python_d.exe Lib\test\regrtest.py -uall -R 2:2:reflog.txt test_cdecimal
      echo.

      cd ..\mpdecimal

      if %%f==yes patch -R < python\failapi2.diff
      if %%f==yes patch -R < python\failapi3.diff
      echo.
      echo.
    )
  )
)


