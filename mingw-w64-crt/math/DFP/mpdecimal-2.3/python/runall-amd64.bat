@ECHO OFF

call gettests.bat
call vcvarsall x64
cd ..
if not exist Makefile copy Makefile.vc Makefile
cd python

for %%v in ("Python26" "Python27") do (
  for %%m in ("" "--with-machine=x64" "--with-machine=ansi64") do (
    for %%a in ("" "--without-threads") do (
      echo.
      echo # ========================================================================
      echo #               %%v %%m %%a
      echo # ========================================================================
      echo.
      cd ..
      nmake clean
      "C:\Program Files\%%v\python.exe" setup.py build %%m %%a
      cd python
      echo.
      echo.
      echo ======================== Unit tests ==========================
      echo.
      "C:\Program Files\%%v\python.exe" test_cdecimal2.py
      echo.
      echo.
      echo ========================= deccheck ===========================
      echo.
      "C:\Program Files\%%v\python.exe" deccheck2.py
      echo.
      echo.
      echo ======================= ctx-deccheck =========================
      echo.
      "C:\Program Files\%%v\python.exe" ctx-deccheck2.py
    )
  )
)

for %%v in ("Python31" "Python32") do (
  for %%m in ("" "--with-machine=x64" "--with-machine=ansi64") do (
    for %%a in ("" "--without-threads") do (
      echo.
      echo # ========================================================================
      echo #               %%v %%m %%a
      echo # ========================================================================
      echo.
      cd ..
      nmake clean
      "C:\Program Files\%%v\python.exe" setup.py build %%m %%a
      cd python
      echo.
      echo.
      echo ======================== Unit tests ==========================
      echo.
      "C:\Program Files\%%v\python.exe" test_cdecimal3.py
      echo.
      echo.
      echo ========================= deccheck ===========================
      echo.
      "C:\Program Files\%%v\python.exe" deccheck3.py
      echo.
      echo.
    )
  )
)

for %%m in ("" "--with-machine=x64" "--with-machine=ansi64") do (
  for %%a in ("" "--without-threads") do (
    echo.
    echo # ========================================================================
    echo #               default %%m %%a
    echo # ========================================================================
    echo.
    cd ..
    nmake clean
    if exist ..\3.3\PCbuild\amd64\cdecimal.pyd del ..\3.3\PCbuild\amd64\cdecimal.pyd
    if exist ..\3.3\PCbuild\amd64\cdecimal_d.pyd del ..\3.3\PCbuild\amd64\cdecimal_d.pyd
    ..\3.3\PCbuild\amd64\python_d.exe setup.py build -g %%m %%a
    cd python
    echo.
    echo.
    echo ======================== Unit tests ==========================
    echo.
    ..\..\3.3\PCbuild\amd64\python_d.exe test_cdecimal3.py
    echo.
    echo.
    echo ========================= deccheck ===========================
    echo.
    ..\..\3.3\PCbuild\amd64\python_d.exe deccheck3.py
    echo.
    echo.
  )
)


