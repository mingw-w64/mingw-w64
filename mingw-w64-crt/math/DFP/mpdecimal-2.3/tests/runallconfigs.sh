#!/bin/sh


VALGRIND=
if [ X"$1" = X"--valgrind" ]; then
    shift
    VALGRIND="valgrind --tool=memcheck --leak-check=full --leak-resolution=high --db-attach=yes --show-reachable=yes"
fi
export VALGRIND

if [ -n "$1" ]; then
    CONFIGS="$@"
else
    CONFIGS="x64 uint128 ansi64 full_coverage ppro ansi32 ansi-legacy universal"
fi

GMAKE=`which gmake`
if [ X"$GMAKE" = X"" ]; then
    GMAKE=make
fi

DNTEST="true"
case `uname -a` in
    # suncc does not compile decNumber.
    *SunOS*) DNTEST="false" ;;
esac
case $CC in
    # CompCert does not compile decNumber.
    *ccomp*) DNTEST="false" ;;
esac


./gettests.sh || exit 1
if [ "$DNTEST" = "true" ]; then
    ./getdn.sh || exit 1
fi

for config in $CONFIGS; do
    printf "\n# ========================================================================\n"
    printf "#                                 %s\n" $config
    printf "# ========================================================================\n\n"
    cd ..
    $GMAKE clean
    ./configure MACHINE=$config
    if [ X"$config" = X"full_coverage" ]; then
        patch < tests/fullcov_header.patch
    fi
    $GMAKE extended
    cd tests
    if [ "$DNTEST" = "true" ]; then
        $GMAKE deccheck
    fi
    printf "\n"
    if [ X"$config" = X"ppro" ]; then
        # Valgrind has no support for 80 bit long double arithmetic.
        savevg=$VALGRIND
        VALGRIND=
        ./runalltests.sh
        VALGRIND=$savevg
    else
        ./runalltests.sh
    fi
done



