#!/bin/bash

set -e

WINE_DIR=$1

if test -z $WINE_DIR; then
	echo "Usage: wine-impot.sh wine_dir"
	exit 1
fi

for f in client.c expr.c expr.h hash.c hash.h header.c header.h parser.h parser.l parser.tab.c parser.tab.h parser.y \
	parser.yy.c proxy.c register.c server.c typegen.c typegen.h typelib.c typelib.h typelib_struct.h typetree.c typetree.h \
	utils.c utils.h widl.c widl.h widltypes.h write_msft.c
do
	cp $WINE_DIR/tools/widl/$f src
done

for f in ppl.l ppl.yy.c ppy.tab.c ppy.tab.h ppy.y preproc.c wpp.c wpp_private.h
do
	cp $WINE_DIR/libs/wpp/$f src/wpp
done

for f in basetsd.h guiddef.h poppack.h pshpack1.h pshpack2.h pshpack4.h pshpack8.h winbase.h windef.h winerror.h winnls.h winnt.h winnt.rh
do
	cp $WINE_DIR/include/$f include
done

for f in list.h rpcfc.h wpp.h
do
	cp $WINE_DIR/include/wine/$f include/wine
done

for f in getopt.c getopt1.c
do
	cp $WINE_DIR/libs/port/$f src/port/
done

sed s/Wine/WIDL/ < $WINE_DIR/VERSION >VERSION
