#!/bin/sh

#
# Purpose: test with released Python versions.
#
# Synopsis: ./runall-releases.sh
#
#   Directory structure (path names are hardcoded):
#
#     svndir/r25*
#     svndir/r26*
#     svndir/r27*
#     svndir/r31*
#
#     svndir/mpdecimal/python  ->  run script from this directory
#

# Specific configurations for setup.py
PY2_VERSIONS="r25 r251 r252 r253 r254 r255 r26 r261 r262 r263 r264 r265 r266 r27 r271"
PY3_VERSIONS="r31 r311 r312 r313 r32"

# gmake required
GMAKE=`which gmake`
if [ X"$GMAKE" = X"" ]; then
    GMAKE=make
fi

# Pretty print configurations
print_config ()
{
    len=`echo $@ | wc -c`
    margin="#%"`expr \( 74 - $len \) / 2`"s"

    echo ""
    echo "# ========================================================================"
    printf $margin ""
    echo $@
    echo "# ========================================================================"
    echo ""
}

./gettests.sh
./build_all_releases.sh

for py_version in $PY2_VERSIONS $PY3_VERSIONS; do
    for pyargs in "--without-threads" ""; do
        py_exec="$py_version/python"
        regrtest="../../$py_version/Lib/test/regrtest.py -uall"

        print_config $py_version $pyargs

        cd ../ || exit 1
        $GMAKE clean
        ../$py_exec setup.py build $pyargs || exit 1
        cd python || exit 1
        echo ""
        echo ""
        echo "======================== Unit tests =========================="
        echo ""
        case "$py_version" in
            *25*)
                decimal_tests=test_cdecimal2.5.py
                deccheck=deccheck2.py
                ctx_deccheck=ctx-deccheck2.py
                ;;
            *26*|*27*)
                decimal_tests=test_cdecimal2.py
                deccheck=deccheck2.py
                ctx_deccheck=ctx-deccheck2.py
                ;;
            *31*|*32*)
                decimal_tests=test_cdecimal3.py
                deccheck=deccheck3.py
                ctx_deccheck='-c print("\ndeccheck3_includes_context_tests\n\n")'
                ;;
            *) exit 1 ;;
        esac
        cp cdecimal*.so ../../$py_version/Lib/ || exit 1
        cp $decimal_tests ../../$py_version/Lib/test/test_cdecimal.py || exit 1
        ../../$py_exec $regrtest test_cdecimal || exit 1
        echo ""
        echo ""
        echo "======================== deccheck =========================="
        echo ""
        ../../$py_exec $deccheck
        echo ""
        echo ""
        echo "======================= ctx-deccheck ======================="
        echo ""
        ../../$py_exec $ctx_deccheck
    done
done



