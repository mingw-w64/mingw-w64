bin_PROGRAMS = genpeimg
genpeimg_SOURCES = src/img.h src/img.c src/img_pe.c src/genpeimg.c
genpeimg_CPPFLAGS = -Isrc
genpeimg_CFLAGS = $(AM_CFLAGS) -O3 -g -Werror -Wall -Wextra

DISTCHECK_CONFIGURE_FLAGS = --host=$(host)
