#!/bin/sh


if ! [ -d decimaltestdata ]; then
    if [ -d ../../default/Lib/test/decimaltestdata ]; then
        cp -R ../../default/Lib/test/decimaltestdata .
    else
        # There is no way yet to check out subdirectories in mercurial.
        wget http://hg.python.org/cpython/archive/tip.zip
        unzip -qq tip.zip cpython*/Lib/test/decimaltestdata/*
        cp -R cpython*/Lib/test/decimaltestdata .
        rm tip.zip
        rm -rf cpython*
    fi
fi



