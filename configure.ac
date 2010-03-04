#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([mingw-w64],[1.0b],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([AUTHORS])
AC_CONFIG_HEADERS([config.h])

AM_MAINTAINER_MODE
AM_INIT_AUTOMAKE([foreign])

AC_CANONICAL_HOST

AC_DEFUN([MW64_OPTION_ERROR],[AC_MSG_ERROR([Invalid argument to --$1: $AS_TR_SH([$1])])])

# Checks for programs.

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_MSG_CHECKING([whether to build the headers])
AC_ARG_WITH([headers],
  [AS_HELP_STRING([--without-headers],
    [Skip building the mingw-w64 headers])],
  [],
  [with_headers=yes])
AS_CASE([$with_headers],
  [yes],[AC_CONFIG_SUBDIRS([mingw-w64-headers])],
  [no],[],
  [MW64_OPTION_ERROR([with-headers])])
AM_CONDITIONAL([HEADER],[test "x$with_headers" = xyes])
AC_MSG_RESULT([$with_headers])

AC_MSG_CHECKING([whether to build the crt])
AC_ARG_WITH([crt],
  [AS_HELP_STRING([--without-crt],
    [Skip building the mingw-w64 crt])],
  [],
  [with_crt=yes])
AS_CASE([$with_crt],
  [yes],[AC_CONFIG_SUBDIRS([mingw-w64-crt])],
  [no],[],
  [MW64_OPTION_ERROR([with-crt])])
AM_CONDITIONAL([CRT],[test "x$with_crt" = xyes])
AC_MSG_RESULT([$with_crt])

AC_MSG_CHECKING([whether to build the optional libraries])
AC_ARG_WITH([libraries],
  [AS_HELP_STRING([--with-libraries=ARG],
    [Build the extra mingw-w64 libs, where ARG is one of libmangle, pseh, or all])],
  [],
  [with_libraries=no])
AS_CASE([$with_libraries],
  [yes|all],[
    with_libraries="libmangle,pseh"
    with_libraries_mangle=yes
    with_libraries_pseh=yes],
  [libmangle],[
    with_libraries="libmangle"
    with_libraries_mangle=yes
    with_libraries_pseh=no],
  [pseh],[
    with_libraries="pseh"
    with_libraries_mangle=no
    with_libraries_pseh=yes],
  [no],[
    with_libraries_mangle=no
    with_libraries_pseh=no],
  [MW64_OPTION_ERROR([with-libraries])])
AM_CONDITIONAL([LIBRARIES_MANGLE],[test "x$with_libraries_mangle" = xyes])
AM_CONDITIONAL([LIBRARIES_PSEH],[test "x$with_libraries_pseh" = xyes])
AM_COND_IF([LIBRARIES_MANGLE],[AC_CONFIG_SUBDIRS([mingw-w64-libraries/libmangle])])
AM_COND_IF([LIBRARIES_PSEH],[AC_CONFIG_SUBDIRS([mingw-w64-libraries/pseh])])
AC_MSG_RESULT([$with_libraries])

AC_MSG_CHECKING([whether to build the optional tools])
AC_ARG_WITH([tools],
  [AS_HELP_STRING([--with-tools=ARG],
    [Build the extra mingw-w64 tools, where ARG is one of gendef, genidl, or all])],
  [],
  [with_tools=no])
AS_CASE([$with_tools],
  [yes|all],[
    with_tools="gendef,genidl"
    with_tools_gendef=yes
    with_tools_genidl=yes],
  [gendef],[
    with_tools="gendef"
    with_tools_gendef=yes
    with_tools_genidl=no],
  [genidl],[
    with_tools="genidl"
    with_tools_gendef=no
    with_tools_genidl=yes],
  [no],[
    with_tools_gendef=no
    with_tools_genidl=no],
  [MW64_OPTION_ERROR([with-tools])])
AM_CONDITIONAL([TOOLS_GENDEF],[test "x$with_tools_gendef" = xyes])
AM_CONDITIONAL([TOOLS_GENIDL],[test "x$with_tools_genidl" = xyes])
AM_COND_IF([TOOLS_GENDEF],[AC_CONFIG_SUBDIRS([mingw-w64-tools/gendef])])
AM_COND_IF([TOOLS_GENIDL],[AC_CONFIG_SUBDIRS([mingw-w64-tools/genidl])])
AC_MSG_RESULT([$with_tools])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

