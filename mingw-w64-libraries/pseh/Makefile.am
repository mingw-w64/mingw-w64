AUTOMAKE_OPTIONS = foreign subdir-objects

AM_CPPFLAGS = -I$(srcdir)/include
AM_CFLAGS = -Wall -Wstrict-aliasing=2 -pedantic

lib_LIBRARIES = libpseh.a

libpseh_a_SOURCES = \
  src/framebased.c \
  src/i386/framebased-gcchack-asm.S \
  src/i386/framebased-gcchack.c \
  src/i386/framebased.S

psehdir = $(includedir)/pseh
framebaseddir = $(psehdir)/framebased

pseh_HEADERS = \
  include/pseh/pseh2.h \
  include/pseh/framebased.h \
  include/pseh/excpt.h \
  include/pseh/pseh.h \
  include/pseh/pseh2-common.h

framebased_HEADERS = include/pseh/framebased/internal.h



