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
#FIXME: Add in base directx
AC_SUBST([BASEHEAD_LIST])
AC_SUBST([SYSHEAD_LIST])
AC_SUBST([SECHEAD_LIST])
AC_SUBST([SECSYSHEAD_LIST])
AC_SUBST([GLHEAD_LIST])
AC_SUBST([SDKSHEAD_LIST])

AC_MSG_CHECKING([for optional sdk headers])
AC_ARG_WITH([sdk],
  [AS_HELP_STRING([--with-sdk=ARG],
    [Add the desired SDK, where ARG can be one of ddk, directx, or all])],
  [AS_CASE([$with_sdk],
    [all|yes],[
      with_sdk="ddk,directx"
      with_ddk=yes
      with_directx=yes],
    [ddk],[
      with_ddk=yes
      with_directx=no],
    [directx],[
      with_ddk=no
      with_directx=yes],
    [no],[
      with_ddk=no
      with_directx=no],
    [AC_ERROR([Invalid option: $with_sdk.  Please choose one of ddk, directx, or all.])])],
  [])
AC_MSG_RESULT([$with_sdk])

AS_IF([test $with_ddk = yes],[
  DDKHEAD_LIST=$srcdir/ddk/include/ddk/*.h
  SDKSHEAD_LIST="$SDKSHEAD_LIST "$srcdir/ddk/include/sdks/*.h],
  [])
AC_SUBST([DDKHEAD_LIST])

AS_IF([test $with_directx = yes],[
  DXHEAD_LIST=$srcdir/direct-x/include/*.[[hi]]*
  SDKSHEAD_LIST="$SDKSHEAD_LIST "$srcdir/direct-x/include/sdks/*.h],
  [SDKSHEAD_LIST=$srcdir/include/sdks/*.h])
AC_SUBST([DXHEAD_LIST])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
