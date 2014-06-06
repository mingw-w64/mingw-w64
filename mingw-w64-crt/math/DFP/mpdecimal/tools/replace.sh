#!/bin/sh

#
# usage: ./replace name1 name2
#
# In each .c or .h file in the current directory or subdirectory,
# replace all occurrences of name1 with name2.
#


find . -name '*.[ch]' -exec ex -c "%s#$1#$2#g" -c 'wq' {} \;


