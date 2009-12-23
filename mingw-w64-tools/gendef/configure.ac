#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])
AC_INIT([mingw-w64-gendef], [1.0], [mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([src/gendef.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([inttypes.h memory.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_INT32_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
# Disabled due the fact that once the autoconf detects that gnu malloc
# is not available, it places in config.h the define of malloc as
# rpl_malloc. By this linkage could fail.
#AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset strdup strrchr])

# Check for libmangle
libmangle_h=no
libmangle_a=no
libmangle=yes
mangle_path=

AC_ARG_WITH([libmangle],
  [AS_HELP_STRING([--with-libmangle=PATH], [Specify prefix directory for the installed libmangle package])],
  [],
  [])

AS_CASE(["$with_libmangle"],
  [yes], [libmangle=yes],
  [no], [libmangle=no],
  [mangle_path="$with_libmangle"])

if test "x$libmangle" = "xyes"; then
  MCPPFLAGS=-I"$mangle_path/include"
  MLDFLAGS=-L"$mangle_path/lib"
  CPPFLAGS="$CPPFLAGS $MCPPFLAGS"
  LDFLAGS="$LDFLAGS $MLDFLAGS"

  AC_CHECK_HEADERS([libmangle.h], [libmangle_h=yes], [])
  AC_SEARCH_LIBS([decode_ms_name], [mangle], [libmangle_a=yes])

  AC_MSG_CHECKING([if we want to use libmangle])
  if test "x$libmangle_h" = "xyes" && test "x$libmangle_a" = "xyes"; then
    AC_MSG_RESULT([yes])
    AC_DEFINE([USE_LIBMANGLE], [1], [Define to use libmangle])
    LIBMANGLE_LIB=-lmangle
    AC_SUBST([LIBMANGLE_LIB], ["-lmangle"])
    AC_SUBST([LIBMANGLE_CPPFLAGS], ["$MCPPFLAGS"])
    AC_SUBST([LIBMANGLE_LDFLAGS], ["$MLDFLAGS"])
  else
    AC_MSG_RESULT([no])
    AC_SUBST([LIBMANGLE_LIB], [""])
  fi
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
