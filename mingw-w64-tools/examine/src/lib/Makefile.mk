
lib_LTLIBRARIES += src/lib/libexamine.la

src_lib_libexamine_la_SOURCES = \
src/lib/examine_log.c \
src/lib/examine_log.h

src_lib_libexamine_la_CFLAGS = @EXM_CFLAGS@

src_lib_libexamine_la_LDFLAGS = -no-undefined -version-info @version_info@

src_lib_libexamine_la_LIBTOOLFLAGS = --tag=disable-static

pkgdir = $(bindir)
pkg_LTLIBRARIES += src/lib/examine_dll.la

src_lib_examine_dll_la_SOURCES = \
src/lib/examine_dll.c \
src/lib/examine_list.c \
src/lib/examine_overloads.c \
src/lib/examine_pe.c \
src/lib/examine_stacktrace.c \
src/lib/examine_list.h \
src/lib/examine_pe.h \
src/lib/examine_private.h \
src/lib/examine_stacktrace.h

src_lib_examine_dll_la_CPPFLAGS = \
-I$(top_srcdir)/src/lib \
-DPSAPI_VERSION=1 \
@EXM_CPPFLAGS@

src_lib_examine_dll_la_CFLAGS = @EXM_CFLAGS@

src_lib_examine_dll_la_LIBADD = \
src/lib/libexamine.la \
-lpsapi \
-limagehlp \
@EXM_LIBS@

src_lib_examine_dll_la_LDFLAGS = -no-undefined -module -avoid-version

src_lib_examine_dll_la_LIBTOOLFLAGS = --tag=disable-static

EXTRA_DIST += src/lib/examine_stacktrace_vc.c
