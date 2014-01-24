@ECHO OFF

cd ..\..\

if not exist master hg clone -U http://hg.python.org/cpython master
if exist master cd master && hg pull && cd ..

for %%b in (2.6 2.7 3.1 3.2) do (
    if not exist %%b hg clone master %%b -u %%b
    if exist %%b cd %%b && hg pull -u && cd ..
)

if not exist 3.3 hg clone master 3.3 -u default
if exist 3.3 cd 3.3 && hg pull -u && cd ..

cd mpdecimal\python


