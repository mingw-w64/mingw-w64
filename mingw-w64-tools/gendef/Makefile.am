bin_PROGRAMS = gendef

gendef_SOURCES = src/gendef.h src/compat_string.h src/gendef.c src/gendef_def.c src/compat_string.c \
                 src/fsredir.c src/fsredir.h
gendef_CFLAGS = $(AM_CFLAGS) -O3 -g -Werror -Wall -Wextra

EXTRA_DIST = ChangeLog-2009
DISTCHECK_CONFIGURE_FLAGS = --host=$(host) --with-mangle=@with_mangle@

