#!/bin/sh


VERSIONED_FILES=\
"configure configure.ac libmpdec/Makefile.vc vcbuild/vcbuild32.bat vcbuild/vcbuild64.bat"

for file in $VERSIONED_FILES; do
    sed -i "s/@RELEASE_VERSION@/$@/g" $file
done


