#!/bin/sh


# Build all Python releases.


cd ../../

for dir in r25 r251 r252 r253 r254 r255 r26 r261 r262 r263 r264 r265 r266 \
           r27 r271 r31 r311 r312 r313 r32; do
    cd $dir
    make distclean
    ./configure --prefix=/dev/null "$@"
    make
    cd ../
    case $dir in
        r32) continue;;
    esac
    cd $dir/Lib/test && rm -rf decimaltestdata
    cp -R ../../../r32/Lib/test/decimaltestdata .
    cd ../../../
done


