#!/bin/sh


if ! [ -f runtest ]; then
    echo "error: you must build the tests first"
    exit 1
fi


./gettests.sh || exit 1

printf "\nRunning official tests ... \n\n"
$VALGRIND ./runtest --all official.decTest

printf "\nRunning additional tests ... \n\n"
$VALGRIND ./runtest --all additional.decTest

printf "\nRunning coverage tests ... \n\n"
$VALGRIND ./cov
$VALGRIND ./test_transpose
$VALGRIND ./fntcov

if [ -f deccheck ]; then
    printf "\nRunning decNumber tests ... \n\n"
    $VALGRIND ./deccheck
fi

printf "\nRunning long tests ... \n\n"
./ppro_mulmod
if [ -f mpd_mpz_add ]; then
    $VALGRIND ./mpd_mpz_add -q
fi
if [ -f mpd_mpz_sub ]; then
    $VALGRIND ./mpd_mpz_sub -q
fi
if [ -f mpd_mpz_mul ]; then
    $VALGRIND ./mpd_mpz_mul -q
fi
if [ -f mpd_mpz_divmod ]; then
    $VALGRIND ./mpd_mpz_divmod -q
fi
$VALGRIND ./karatsuba_fnt -q
$VALGRIND ./karatsuba_fnt2 -q


PYTHON=`which python3.2`
if [ X"$PYTHON" = X"" ]; then
    PYTHON=`which python2.7`
fi

if [ X"$PYTHON" != X"" ]; then
    printf "\nRunning locale and format tests ... \n\n"

    $PYTHON ../python/genrandlocale.py | $VALGRIND ./runtest -
    $PYTHON ../python/genrandformat.py | $VALGRIND ./runtest -
    $PYTHON ../python/genlocale.py | $VALGRIND ./runtest -
fi



