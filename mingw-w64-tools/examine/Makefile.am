AUTOMAKE_OPTIONS = subdir-objects

ACLOCAL_AMFLAGS = -I m4

DISTCHECK_CONFIGURE_FLAGS = --host=$(host_triplet)

MAINTAINERCLEANFILES = \
Makefile.in \
aclocal.m4 \
compile \
config.guess \
config.h.in \
config.h.in~ \
config.sub \
configure \
depcomp \
install-sh \
ltmain.sh \
missing \
$(distdir).tar.gz \
$(distdir).tar.bz2 \
m4/libtool.m4 \
m4/lt~obsolete.m4 \
m4/ltoptions.m4 \
m4/ltsugar.m4 \
m4/ltversion.m4

lib_LTLIBRARIES =
pkg_LTLIBRARIES =
bin_PROGRAMS =
EXTRA_DIST =

include src/lib/Makefile.mk
include src/bin/Makefile.mk

EXTRA_DIST += \
autogen.sh \
COPYING \
THANKS \
m4/exm_attribute.m4 \
win32/examine.sln \
win32/examine.vcproj \
win32/examine_dll.vcproj \
win32/examine_test.vcproj
