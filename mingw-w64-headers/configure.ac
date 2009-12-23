#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])
AC_INIT([mingw-w64-headers], [1.0b], [mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_SRCDIR([crt/_mingw.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])

AC_CANONICAL_HOST

# Checks for programs.

# Checks for libraries.

# Checks for header files.

GLHEAD_LIST=$srcdir/include/GL/*.h
BASEHEAD_LIST=$srcdir/include/*.h
for i in c dlg h16 hxx rh ver; do
  BASEHEAD_LIST="$BASEHEAD_LIST "$srcdir/include/*.$i
done
#FIXME: Add in base directx
AC_SUBST([BASEHEAD_LIST])
AC_SUBST([GLHEAD_LIST])
AC_SUBST([SDKSHEAD_LIST])

AC_MSG_CHECKING([for c-runtime headers])
AC_ARG_ENABLE([crt],
  [AS_HELP_STRING([--disable-crt],
    [Do not use the default crt headers])],
  [],
  [enable_crt=yes])
AM_CONDITIONAL([ENABLE_CRT],[test x$enable_crt=xyes])
AC_MSG_RESULT([$enable_crt])

AC_MSG_CHECKING([for optional sdk headers])
AC_ARG_ENABLE([sdk],
  [AS_HELP_STRING([--enable-sdk=ARG],
    [Add the desired SDK, where ARG can be one of ddk, directx, or all])],
  [],
  [enable_sdk=no])
AS_CASE([$enable_sdk],
  [all|yes],[
    enable_sdk="ddk,directx"
    enable_ddk=yes
    enable_directx=yes],
  [ddk],[
    enable_ddk=yes
    enable_directx=no],
  [directx],[
    enable_ddk=no
    enable_directx=yes],
  [no],[
    enable_ddk=no
    enable_directx=no],
  [AC_ERROR([Invalid option: $enable_sdk.  Please choose one of ddk, directx, or all.])])
AC_MSG_RESULT([$enable_sdk])

MINGW_HAS_DX=0

AS_IF([test $enable_directx = yes],[
  DXHEAD_LIST=$srcdir/direct-x/include/*.[[hi]]*
  MINGW_HAS_DX=1],
  [])
AC_SUBST([DXHEAD_LIST])
AC_SUBST([MINGW_HAS_DX])

AS_IF([test $enable_ddk = yes],[
  DDKHEAD_LIST=$srcdir/ddk/include/ddk/*.h
  SDKSHEAD_LIST="$SDKSHEAD_LIST "$srcdir/ddk/include/sdks/*.h],
  [])
AC_SUBST([DDKHEAD_LIST])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile crt/sdks/_mingw_directx.h])
AC_OUTPUT
