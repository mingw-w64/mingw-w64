bin_PROGRAMS = genlib
AM_LDFLAGS = @GENLIB_LDFLAGS@
AM_CPPFLAGS = @GENLIB_CPPFLAGS@ -I$(top_srcdir)/src

genlib_SOURCES = src/genlib.h src/genlib.c src/deffun.c src/deflex.c src/defparse.c \
                 src/deflex.h src/defparse.h
genlib_CFLAGS = $(AM_CFLAGS) -O3 -g -Wall -Wextra

EXTRA_DIST = $(srcdir)/ChangeLog*
DISTCHECK_CONFIGURE_FLAGS = --host=$(host) --with-mangle=@with_mangle@
