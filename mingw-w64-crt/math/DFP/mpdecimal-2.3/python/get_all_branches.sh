#!/bin/sh

#
# Check out all supported Python branches.
#
# Directory structure:
#
#   hgdir/release25-maint
#   hgdir/release26-maint
#   ...
#
#   hgdir/mpdecimal/python  ->  run script from this directory
#

branches="2.5 2.6 2.7 3.1 3.2 default"

cd ../../

if ! [ -d master ]; then
    hg clone -U http://hg.python.org/cpython master
else
    cd master && hg pull && cd ..
fi

for b in $branches; do
    if ! [ -d "$b" ]; then
        hg clone master "$b" -u "$b"
    else
        cd "$b" && hg pull -u && cd ..
    fi
done


