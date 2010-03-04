bin_PROGRAMS = gendef

gendef_SOURCES = src/gendef.h src/gendef.c src/gendef_def.c src/compat_string.c
gendef_CFLAGS = $(AM_CFLAGS) -O3 -g -Werror -Wall -Wextra

EXTRA_DIST = ChangeLog-2009
DISTCHECK_CONFIGURE_FLAGS = --host=$(host) --with-mangle=@with_mangle@

