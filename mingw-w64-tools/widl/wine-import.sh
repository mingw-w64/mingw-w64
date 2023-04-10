#!/bin/bash

set -e

WINE_DIR=$1
WINE_BUILD_DIR=$2

if test -z $WINE_DIR; then
	echo "Usage: wine-import.sh wine_dir [wine_build_dir]"
	exit 1
fi

for f in attribute.c client.c expr.c expr.h hash.c hash.h header.c header.h parser.h parser.l parser.tab.c parser.tab.h parser.y \
	parser.yy.c proxy.c register.c server.c typegen.c typegen.h typelib.c typelib.h typelib_struct.h typetree.c typetree.h \
	utils.c utils.h widl.c widl.h widltypes.h write_msft.c
do
	if [ ! -f $WINE_DIR/tools/widl/$f ] && [ -f $WINE_BUILD_DIR/tools/widl/$f ]; then
		cp $WINE_BUILD_DIR/tools/widl/$f src
	else
		cp $WINE_DIR/tools/widl/$f src
	fi
done

for f in ppl.l ppl.yy.c ppy.tab.c ppy.tab.h ppy.y wpp.c wpp_private.h
do
	if [ ! -f $WINE_DIR/tools/wrc/$f ] && [ -f $WINE_BUILD_DIR/tools/wrc/$f ]; then
		cp $WINE_BUILD_DIR/tools/wrc/$f src
	else
		cp $WINE_DIR/tools/wrc/$f src
	fi
done

for f in tools.h
do
	if [ ! -f $WINE_DIR/tools/$f ] && [ -f $WINE_BUILD_DIR/tools/$f ]; then
		cp $WINE_BUILD_DIR/tools/$f .
	else
		cp $WINE_DIR/tools/$f .
	fi
done

for f in basetsd.h concurrencysal.h driverspecs.h guiddef.h excpt.h memoryapi.h namespaceapi.h ndrtypes.h poppack.h pshpack1.h \
        processthreadsapi.h pshpack2.h pshpack4.h pshpack8.h realtimeapiset.h sal.h specstrings.h threadpoolapiset.h \
        timezoneapi.h winbase.h windef.h winerror.h winnls.h winnt.h winnt.rh synchapi.h winapifamily.h
do
	cp $WINE_DIR/include/$f include
done

for f in list.h
do
	cp $WINE_DIR/include/wine/$f include/wine
done

sed s/Wine/WIDL/ < $WINE_DIR/VERSION >VERSION
for f in patches/*
do
	patch -p3 < $f
done
autoconf
