#!/bin/sh


#
# Convert all text files in the current directory and in all
# subdirectories to dos line endings.
#


todos_if_text () {
	file $1 | grep -q text
	if [ $? -eq 0 ]; then
	     todos $1
	fi
}


for name in `find . -type f -print 2>/dev/null`
do
	todos_if_text $name
done


