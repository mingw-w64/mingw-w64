#!/bin/sh


# Prepare all supported Python branches for memory debugging:
# ./build_all_branches --without-threads --with-pydebug


branches="2.5  2.6  2.7  3.1  3.2  default"


cd ../../

for dir in $branches; do
    cd $dir
    if [ -f Makefile ]; then
        make distclean
    fi
    ./configure --prefix=/dev/null "$@"
    make
    cd ..
done

# 2.5 has a buggy version of decimaltestdata
cd 2.5/Lib/test && rm -rf decimaltestdata && cp -R ../../../default/Lib/test/decimaltestdata .


