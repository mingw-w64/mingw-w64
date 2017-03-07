#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([mingw-w64-gendef],[1.0],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([src/gendef.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_MAINTAINER_MODE

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_CC

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
# Disabled due the fact that once the autoconf detects that malloc
# is not available, it places in config.h the define of malloc as
# rpl_malloc. By this linkage could fail on cross-compiles.
#AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset strdup strrchr strlwr])

# Checks for libraries.
AC_MSG_CHECKING([whether to build gendef with libmangle])
AC_ARG_WITH([mangle],
  [AS_HELP_STRING([--with-mangle[=ARG]],
    [Use the libmangle package to build gendef.  If ARG is given, set to the libmangle installation prefix.])],
  [AS_CASE([$with_mangle],
    [yes],[with_mangle_result=yes],
    [no],[with_mangle_result=no],
    [with_mangle_path="$with_mangle"; with_mangle_result=yes])],
  [with_mangle=no; with_mangle_result=no])
AC_MSG_RESULT([$with_mangle_result])
AC_SUBST([with_mangle])
AS_VAR_IF([with_mangle_result],[yes],[
  AS_VAR_SET_IF([with_mangle_path],[
    extra_cppflags="-I$with_mangle_path/include"
    extra_ldflags="-L$with_mangle_path/lib"])
    temp_cppflags="$CPPFLAGS"
    temp_ldflags="$LDFLAGS"
    CPPFLAGS="$CPPFLAGS -I$with_mangle_path/include"
    LDFLAGS="$LDFLAGS -L$with_mangle_path/lib"
  AC_CHECK_HEADER([libmangle.h],[],[AC_MSG_ERROR([libmangle enabled, but the header is not usable.])])
  AC_CHECK_LIB([mangle],[libmangle_print_decl],[],[AC_MSG_ERROR([libmangle enabled, but the library is not usable.])])])
    CPPFLAGS="$temp_cppflags"
    LDFLAGS="$temp_ldflags"

AC_SUBST([GENDEF_CPPFLAGS],[$extra_cppflags])
AC_SUBST([GENDEF_LDFLAGS],[$extra_ldflags])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
