#!/bin/sh

#
# Purpose: test all configurations with all supported python versions.
#
# Synopsis: ./runall-memorydebugger.sh [--all-configs64 | --all-configs32]
#
# Requirements:
#
#   Programs:
#
#     hg, valgrind
#
#   Directory structure (path names are hardcoded):
#
#     hgdir/2.5
#     hgdir/2.6
#     hgdir/2.7
#     hgdir/3.1
#     hgdir/3.2
#     hgdir/default
#
#     hgdir/mpdecimal/python  ->  run script from this directory
#


# Specific configurations for setup.py
CONFIGS_64="x64 uint128 ansi64 universal"
CONFIGS_32="ppro ansi32 ansi-legacy universal"

PY2_VERSIONS="2.5 2.6 2.7"
PY3_VERSIONS="3.1 3.2 default"

VALGRIND="valgrind --tool=memcheck --leak-check=full --leak-resolution=high \
         --db-attach=yes --show-reachable=yes --suppressions="

# Get args
case $@ in
     *--all-configs64*)
         CONFIGS=$CONFIGS_64
         ;;
     *--all-configs32*)
         CONFIGS=$CONFIGS_32
         ;;
     *)
         CONFIGS="auto"
         ;;
esac

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

cp -R ../../default/Lib/test/decimaltestdata .

# Refleak tests
./build_all_branches.sh --with-pydebug

for py_version in $PY2_VERSIONS $PY3_VERSIONS; do
    for pyargs in "--without-threads" ""; do
        for config in $CONFIGS; do
            for failapi in "yes" "no"; do
                if [ X"$failapi" = X"yes" ]; then
                    cd .. || exit 1
                    patch < python/failapi2.diff
                    patch < python/failapi3.diff
                    cd python || exit 1
                fi

                ################### Arguments for setup.py ####################
                if [ "$config" = "auto" ]; then
                    args=$pyargs
                else
                    args=$pyargs" --with-machine="$config
                fi
                py_exec="$py_version/python"
                regrtest="../../$py_version/Lib/test/regrtest.py -uall -R 2:2:reflog.txt"
    
                #################### Print section header #####################
                print_config $py_version $args "failapi=$failapi"
    
                ########################## Unit tests #########################
                cd .. || exit 1
                $GMAKE clean
                ../$py_exec setup.py build $args || exit 1
                cd python || exit 1
                echo ""
                echo ""
                echo "======================== Unit tests =========================="
                echo ""
                case "$py_version" in
                    2.5) decimal_tests=test_cdecimal2.5.py;;
                    2.6|2.7) decimal_tests=test_cdecimal2.py;;
                    3*|default) decimal_tests=test_cdecimal3.py;;
                    *) exit 1;;
                esac
                cp cdecimal*.so ../../$py_version/Lib/ || exit 1
                cp $decimal_tests ../../$py_version/Lib/test/test_cdecimal.py || exit 1
                ../../$py_exec $regrtest test_cdecimal

                if [ X"$failapi" = X"yes" ]; then
                    cd .. || exit 1
                    patch -R < python/failapi2.diff
                    patch -R < python/failapi3.diff
                    cd python || exit 1
                fi
            done
        done
    done
done

# Valgrind tests
./build_all_branches.sh --without-pymalloc

for py_version in $PY2_VERSIONS $PY3_VERSIONS; do
    for pyargs in "--without-threads" ""; do
        for config in $CONFIGS; do

            ################### Arguments for setup.py ####################
            if [ "$config" = "auto" ]; then
                args=$pyargs
            else
                args=$pyargs" --with-machine="$config
            fi

            ################### Valgrind command line #####################
            py_exec="$py_version/python"
            valgrind="$VALGRIND../../$py_version/Misc/valgrind-python.supp"
            case "$config" in
                # Valgrind has no support for 80 bit long double arithmetic.
                ppro) valgrind= ;;
                auto) case `uname -m` in
                          i386|i486|i586|i686) valgrind= ;;
                      esac
            esac

            ################ Select version specific tests ################
            case "$py_version" in
                2.5)
                    decimal_tests=test_cdecimal2.5.py
                    deccheck=deccheck2.py
                    ctx_deccheck=ctx-deccheck2.py
                    ;;
                2.6|2.7)
                    decimal_tests=test_cdecimal2.py
                    deccheck=deccheck2.py
                    ctx_deccheck=ctx-deccheck2.py
                    ;;
                3*|default)
                    decimal_tests=test_cdecimal3.py
                    deccheck=deccheck3.py
                    ctx_deccheck='-c print("\ndeccheck3_includes_context_tests\n\n")'
                    ;;
                *) exit 1 ;;
            esac

            #################### Print section header #####################
            print_config $py_version $args

            ################### Unit tests with FailAPI ###################
            cd .. || exit 1
            patch < python/failapi2.diff
            patch < python/failapi3.diff
            cd python || exit 1

            cd .. || exit 1
            $GMAKE clean
            ../$py_exec setup.py build $args || exit 1
            cd python || exit 1
   
            echo ""
            echo ""
            echo "======================= FailAPI tests ========================"
            echo ""
            $valgrind ../../$py_exec $decimal_tests

            cd .. || exit 1
            patch -R < python/failapi2.diff
            patch -R < python/failapi3.diff
            cd python || exit 1

            ###################### Regular unit tests #####################
            cd .. || exit 1
            $GMAKE clean
            ../$py_exec setup.py build $args || exit 1
            cd python || exit 1

            echo ""
            echo ""
            echo "======================== Unit tests =========================="
            echo ""
            $valgrind ../../$py_exec $decimal_tests

            ########################### deccheck ##########################
            echo ""
            echo ""
            echo "========================= deccheck ==========================="
            echo ""
            $valgrind ../../$py_exec $deccheck || exit 1

            ######################## ctx-deccheck #########################
            echo ""
            echo ""
            echo "======================= ctx-deccheck ========================="
            echo ""
            $valgrind ../../$py_exec $ctx_deccheck || exit 1
        done
    done
done



