#!/bin/sh

#
# Check out all supported Python releases.
#
# Directory structure:
#
#   svndir/r25
#   svndir/r251
#   ...
#
#   svndir/mpdecimal/python  ->  run script from this directory
#

cd ../../
for tag in r25 r251 r252 r253 r254 r255 r26 r261 r262 r263 r264 r265 r266 r27 r271 r31 r311 r312 r313 r32; do
   svn co http://svn.python.org/projects/python/tags/$tag
done



