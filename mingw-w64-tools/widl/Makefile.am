bin_PROGRAMS = widl

widl_SOURCES = src/widl.h \
  src/expr.h \
  src/hash.h \
  src/header.h \
  src/parser.h \
  src/parser.tab.h \
  src/typegen.h \
  src/typelib.h \
  src/typelib_struct.h \
  src/typetree.h \
  src/utils.h \
  src/widltypes.h \
  src/client.c \
  src/expr.c \
  src/hash.c \
  src/header.c \
  src/parser.tab.c \
  src/parser.yy.c \
  src/port/getopt.c \
  src/port/getopt1.c \
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
  src/wpp/wpp_private.h \
  src/wpp/ppy.tab.h \
  src/wpp/ppl.yy.c \
  src/wpp/ppy.tab.c \
  src/wpp/preproc.c \
  src/wpp/wpp.c \
  src/pathtools.c \
  include/pshpack1.h \
  include/pshpack2.h \
  include/winbase.h \
  include/pshpack8.h \
  include/basetsd.h \
  include/guiddef.h \
  include/winnt.h \
  include/windef.h \
  include/poppack.h \
  include/config.h.in \
  include/wine/wpp.h \
  include/wine/list.h \
  include/wine/port.h \
  include/wine/rpcfc.h \
  include/winerror.h \
  include/pshpack4.h \
  include/winnt.h \
  include/winnls.h \
  include/pathtools.h \
  include/winnt.rh

widl_CPPFLAGS = -I$(top_srcdir)/include -DDEFAULT_INCLUDE_DIR=\"@WIDL_INCLUDEDIR@\" -DDEFAULT_BINDIR=\"$(bindir)\"
widl_CFLAGS = -O3 -g -Wall -Wformat -Wpacked -Wmissing-declarations -Wimplicit-function-declaration -Wmissing-prototypes -Wstrict-aliasing=2

DISTCHECK_CONFIGURE_FLAGS = --host=$(host) --target=$(target)
