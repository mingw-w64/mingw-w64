#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([PSEH],[2.0],[hackbunny@reactos.org])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([include/pseh/pseh2.h])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

AC_CANONICAL_HOST

AS_CASE([$host],
        [i*86-*-mingw*],[],
        [*],[AC_MSG_ERROR([Only x86 32-bit Win32 host variants are supported])])

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AS

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stddef.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
