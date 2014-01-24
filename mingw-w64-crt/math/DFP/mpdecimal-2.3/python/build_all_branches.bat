@ECHO OFF


cd ..\..\


for %%b in (2.6 2.7 3.1 3.2 3.3) do (
  cd %%b
  cd PCbuild
  call vcvarsall x64
  call vcbuild /clean pcbuild.sln
  call vcbuild pcbuild.sln "Debug|x64"
  call vcvarsall x86
  call vcbuild pcbuild.sln "Debug|win32"
  cd ..\..\
)


cd mpdecimal\python


