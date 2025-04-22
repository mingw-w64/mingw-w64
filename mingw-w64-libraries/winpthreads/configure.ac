#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([mingw-w64-winpthreads], [1.0], [mingw-w64-public@lists.sf.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([src/spinlock.c])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_MAINTAINER_MODE

AC_CANONICAL_HOST

# Checks for programs.
AC_NO_EXECUTABLES
AC_PROG_CC
AM_PROG_AS
AM_PROG_AR

AC_MSG_CHECKING([whether C compiler is MSVC-like compiler])
AC_COMPILE_IFELSE(
  [AC_LANG_SOURCE(
    [
#if !defined (_MSC_VER)
not msvc
#endif
    ])
  ],
dnl then
  [RC="$am_aux_dir/windres-rc rc.exe"]
  [msvc=yes],
dnl else
  [msvc=no]
)
AC_MSG_RESULT([$msvc])

AC_SUBST([RCFLAGS])
AM_CONDITIONAL([MSVC], [test x$msvc = xyes])

# Libtool 2.4 should check them correctly
# AC_CHECK_TOOLS([AR],[ar],[:])

# Libtool
LT_INIT([win32-dll])
LT_LANG([Windows Resource])

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile tests/Makefile])
AC_OUTPUT
