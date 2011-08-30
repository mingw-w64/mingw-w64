bin_PROGRAMS = @WIDL_BIN_NAME@
EXTRA_PROGRAMS = widl mingw-w64-widl

widl_SOURCES = \
  src/client.c \
  src/expr.c \
  src/hash.c \
  src/header.c \
  src/parser.tab.c \
  src/parser.yy.c \
  src/port/port.c \
  src/proxy.c \
  src/register.c \
  src/server.c \
  src/typegen.c \
  src/typelib.c \
  src/typetree.c \
  src/utils.c \
  src/widl.c \
  src/write_msft.c \
  src/wpp/ppl.yy.c \
  src/wpp/ppy.tab.c \
  src/wpp/preproc.c \
  src/wpp/wpp.c

widl_CFLAGS = -I$(top_srcdir)/include -O3 -g -Wall -Wformat -Wpacked -Wmissing-declarations -Wimplicit-function-declaration -Wmissing-prototypes -Wstrict-aliasing=2

mingw_w64_widl_SOURCES = $(widl_SOURCES)
mingw_w64_widl_CFLAGS = $(widl_CFLAGS)

DISTCHECK_CONFIGURE_FLAGS = --host=$(host_triplet)

