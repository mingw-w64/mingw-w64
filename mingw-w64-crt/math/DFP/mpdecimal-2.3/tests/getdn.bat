@ECHO OFF

if exist decNumber goto END

wget -nv http://download.icu-project.org/files/decNumber/decNumber-icu-368.zip
unzip -qq decNumber-icu-368.zip
cd decNumber
patch < ..\dnloop-windows.patch
cd ..

:END


