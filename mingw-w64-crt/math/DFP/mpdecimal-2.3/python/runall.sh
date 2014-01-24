#!/bin/sh


# Run all tests for the supported Python versions (>= 2.5)

PY2_VERSIONS="2.5 2.6 2.7"
PY3_VERSIONS="3.1 3.2 3.3"

./gettests.sh


# gmake required
GMAKE=`which gmake`
if [ X"$GMAKE" = X"" ]; then
    GMAKE=make
fi


for py_version in $PY2_VERSIONS; do
    for args in "--without-threads" ""; do
        py_exec="python"$py_version
        echo ""
        echo "# ========================================================================"
        printf "#                               "
        echo $py_exec $args
        echo "# ========================================================================"
        echo ""

        cd ../ || exit 1
        $GMAKE clean
        $py_exec setup.py build $args || exit 1
        cd python || exit 1
        echo ""
        echo "======================== Unit tests =========================="
        echo ""
        if [ X"$py_version" = X"2.5" ]
        then
            $py_exec test_cdecimal2.5.py || exit 1
        else
            $py_exec test_cdecimal2.py || exit 1
        fi
        echo ""
        echo ""
        echo "========================= deccheck ==========================="
        echo ""
        $py_exec deccheck2.py
        echo ""
        echo ""
        echo "======================= ctx-deccheck ========================="
        echo ""
        $py_exec ctx-deccheck2.py
    done
done


for py_version in $PY3_VERSIONS; do
    for args in "--without-threads" ""; do
        py_exec="python"$py_version
        echo ""
        echo "# ========================================================================"
        printf "#                               "
        echo $py_exec $args
        echo "# ========================================================================"
        echo ""

        cd ../ || exit 1
        $GMAKE clean
        $py_exec setup.py build $args || exit 1
        cd python || exit 1
        echo ""
        echo "======================== Unit tests =========================="
        echo ""
        $py_exec test_cdecimal3.py || exit 1
        echo ""
        echo ""
        echo "========================= deccheck ==========================="
        echo ""
        $py_exec deccheck3.py
    done
done



