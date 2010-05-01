bin_PROGRAMS = genidl

genidl_SOURCES = \
  src/genidl_cfg.h     src/genidl_typinfo.h  src/genidl_typeinfo.h  src/genidl_readpe.h \
  src/genidl_config.c  src/genidl_typinfo.c  src/genidl_typeinfo.c  src/genidl_readpe.c \
  src/genidl_dumpidl.c src/fsredir.c         src/fsredir.h \
  src/genidl.c
genidl_CFLAGS = -O3 -g -std=gnu99 -Wall -Wextra -Wshadow -Wformat -Wpacked -Wredundant-decls -Winline -pedantic -Wno-pedantic-ms-format -Wmissing-declarations -Wredundant-decls -Wimplicit-function-declaration -Wmissing-noreturn -Wmissing-prototypes -Wstrict-aliasing=2

#" -Wstrict-aliasing=2 -Wsystem-headers "

DISTCHECK_CONFIGURE_FLAGS = --host=$(host_triplet)

