#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

m4_define(WIDL_VERSION,regexp(m4_include(VERSION),[version \([-.0-9A-Za-z]+\)],[\1]))

AC_PREREQ([2.69])
AC_INIT([widl],[WIDL_VERSION],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/widl.c])
AC_CONFIG_HEADERS([include/config.h])

AC_CANONICAL_TARGET

AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_MAINTAINER_MODE

AC_ARG_PROGRAM

install_prefix=$(echo $prefix | sed "s,NONE,$ac_default_prefix,")
install_bindir=$(echo $bindir | sed "s,\${exec_prefix},$(echo $install_prefix | sed s/,/\\\\,/),")

AC_MSG_CHECKING([for widl includedir])
AC_ARG_WITH([widl-includedir],
  [AS_HELP_STRING([--with-widl-includedir=DIR],
    [Make widl look for includes in this directory, relative to the bin directory (default: <prefix>/<target>/include)])],
  [],
  [with_widl_includedir="$install_prefix/$target/include"])
AC_MSG_RESULT([$with_widl_includedir])
AS_VAR_SET([WIDL_INCLUDEDIR],[$with_widl_includedir])
AC_SUBST([WIDL_INCLUDEDIR])

AX_COMPUTE_RELATIVE_PATH([install_bindir], [with_widl_includedir], [BIN_TO_INCLUDEDIR])
AC_SUBST([BIN_TO_INCLUDEDIR])

# Checks for programs.
AC_PROG_CC

AS_CASE([$target],
  [*-mingw*],[],
  [AC_MSG_ERROR([Unsupported target: $target. Only *-mingw32 targets are supported])])

AS_CASE([$host],
  [*-mingw*],[CFLAGS="$CFLAGS -Wno-pedantic-ms-format"])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([getopt.h io.h fcntl.h inttypes.h libintl.h limits.h malloc.h stddef.h stdlib.h string.h sys/sysctl.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

AC_CHECK_TYPES([long long])

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_CHECK_FUNCS([atexit gettimeofday getopt_long_only memmove memset mkstemps strcasecmp strchr strdup strerror strncasecmp strrchr strtol strtoul strtoull])

AH_TOP([#define __WINE_CONFIG_H])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
