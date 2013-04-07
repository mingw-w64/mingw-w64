
lib_LTLIBRARIES += src/bin/libexamine_test_dll.la
src_bin_libexamine_test_dll_la_SOURCES = \
src/bin/examine_test_dll.c \
src/bin/examine_test_dll.h

src_bin_libexamine_test_dll_la_CPPFLAGS = \
-I$(top_srcdir)/src/bin

src_bin_libexamine_test_dll_la_LDFLAGS = -no-undefined -version-info @version_info@

src_bin_libexamine_test_dll_la_LIBTOOLFLAGS = --tag=disable-static

bin_PROGRAMS += src/bin/examine src/bin/examine_test

src_bin_examine_SOURCES = src/bin/examine_main.c

src_bin_examine_CPPFLAGS = \
-I$(top_srcdir)/src/lib \
-DPACKAGE_BIN_DIR=\"$(bindir)\" \
@EXM_CPPFLAGS@

src_bin_examine_CFLAGS = @EXM_CFLAGS@

src_bin_examine_LDADD = \
src/lib/libexamine.la

src_bin_examine_test_SOURCES = src/bin/examine_test.c

src_bin_examine_test_LDADD = \
src/bin/libexamine_test_dll.la
