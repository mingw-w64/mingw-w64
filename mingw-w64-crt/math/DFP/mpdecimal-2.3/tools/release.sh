#!/bin/sh


VERSIONED_FILES=\
"LIBINSTALL.txt Makefile.vc PKG-INFO configure configure.in setup.py"

for file in $VERSIONED_FILES; do
    sed -i "s/@RELEASE_VERSION@/$@/g" $file
done


