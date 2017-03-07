bin_PROGRAMS = gendef
AM_LDFLAGS = @GENDEF_LDFLAGS@
AM_CPPFLAGS = @GENDEF_CPPFLAGS@

gendef_SOURCES = src/gendef.h src/compat_string.h src/gendef.c src/gendef_def.c src/compat_string.c \
                 src/fsredir.c src/fsredir.h
gendef_CFLAGS = $(AM_CFLAGS) -Werror -Wall -W

EXTRA_DIST = $(srcdir)/ChangeLog*
DISTCHECK_CONFIGURE_FLAGS = --host=$(host) --with-mangle=@with_mangle@

