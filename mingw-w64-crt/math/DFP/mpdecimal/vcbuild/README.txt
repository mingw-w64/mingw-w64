

libmpdec build instructions for Visual Studio
=============================================


   Requirements
   ------------

      - Visual Studio 2008 or later.

      - For the scripted build vcvarsall.bat must be in the PATH.


   64-bit build
   ------------

      Run vcbuild64.bat. If successful, the static library, the dynamic
      library, the common header file and an executable for running the
      unit tests should be in the dist64 directory.


   32-bit build
   ------------

      Run vcbuild32.bat. If successful, the static library, the dynamic
      library, the common header file and an executable for running the
      unit tests should be in the dist32 directory.


   Get the unit tests
   ------------------

      Run gettests.bat. This creates a directory 'testdata' and copies
      additional tests into the directory. If wget is installed (Cygwin),
      the script tries to download IBM's official test cases and copy them
      to 'testdata'.

      Otherwise, download:

         http://speleotrove.com/decimal/dectest.zip

      Unzip the archive such that all .decTest files from the archive are in
      the testdata directory. The directory structure should look like this:

         vcbuild\official.decTest
         vcbuild\additional.decTest
         vcbuild\testdata\*.decTest


   Run the unit tests
   ------------------

      Depending on the build, run runtest64.bat or runtest32.bat.




