#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([mingw-w64-headers], [1.0b], [mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_SRCDIR([include/_mingw.h])
AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_HOST
AM_INIT_AUTOMAKE([foreign])

# Checks for programs.

# Checks for libraries.

# Checks for header files.

SYSHEAD_LIST=$srcdir/include/sys/*.h
SECHEAD_LIST=$srcdir/include/sec_api/*.h
SECSYSHEAD_LIST=$srcdir/include/sec_api/sys/*.h
GLHEAD_LIST=$srcdir/include/GL/*.h
BASEHEAD_LIST=$srcdir/include/*.h
for i in c dlg h16 hxx rh ver; do
  BASEHEAD_LIST="$BASEHEAD_LIST "$srcdir/include/*.$i
done

AC_SUBST([BASEHEAD_LIST])
AC_SUBST([SYSHEAD_LIST])
AC_SUBST([SECHEAD_LIST])
AC_SUBST([SECSYSHEAD_LIST])
AC_SUBST([GLHEAD_LIST])

AC_MSG_CHECKING([for optional ddk headers])
AC_ARG_WITH([ddk],
  [AS_HELP_STRING([--with-ddk],
    [Add the ddk directory to the header installation])],
  [],
  [with_ddk=no])
AS_IF([test $with_ddk = yes],
  [DDKHEAD_LIST=$srcdir/ddk/include/*/*.h],
  [DDKHEAD_LIST=""])
AC_SUBST([DDKHEAD_LIST])
AC_MSG_RESULT([$with_ddk])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
