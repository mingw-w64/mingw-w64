

Download official tests and add the tests to the testdata directory:
====================================================================

URL: http://speleotrove.com/decimal/dectest.zip

# Unix example:
wget http://speleotrove.com/decimal/dectest.zip &&
cd testdata &&
unzip ../dectest.zip &&
cd ../

The directory structure should look like:

<mpdecimal directory>/tests/testdata/<test files>


runshort,sh, runshort.bat:
==========================

cd .. && make MACHINE=<arch> && ./runshort.sh


runalltests,sh, runalltests.bat:
================================

# Without gmp tests:
cd .. && make MACHINE=<arch> extended && ./runalltests.sh


# With gmp tests:

cd .. && make MACHINE=<arch> extended_gmp && ./runalltests.sh


runallconfigs,sh, runconfigs.bat:
=================================

For each configuration in MACHINE={x64, uint128, ansi64, ppro, ansi32, ansi-legacy},
run all tests.


Tests against decNumber:
========================

wget http://download.icu-project.org/ex/files/decNumber/decNumber-icu-368.zip
unzip decNumber-icu-368.zip
cd decNumber && patch < ../dnloop.patch && cd ..
make deccheck
./deccheck




