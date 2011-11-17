#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([mingw-w64-headers],[2.0],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_SRCDIR([crt/_mingw.h.in])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_SED

# Checks for libraries.

# Checks for header files.

BASEHEAD_LIST="crt/_mingw.h "$srcdir/include/*.h
for i in dlg h16 hxx rh ver; do
  BASEHEAD_LIST="$BASEHEAD_LIST "$srcdir/include/*.$i
done
#FIXME: Add in base directx

AC_MSG_CHECKING([for c-runtime headers])
AC_ARG_ENABLE([crt],
  [AS_HELP_STRING([--disable-crt],
    [Do not use the default crt headers])],
  [],
  [enable_crt=yes])
AM_CONDITIONAL([ENABLE_CRT],[test x$enable_crt=xyes])
AC_MSG_RESULT([$enable_crt])
AS_VAR_IF([enable_crt],[yes],[
  BASEHEAD_LIST="$BASEHEAD_LIST "$srcdir/crt/*.h
  SYSHEAD_LIST=$srcdir/crt/sys/*.h
  SECHEAD_LIST=$srcdir/crt/sec_api/*.h
  SECSYSHEAD_LIST=$srcdir/crt/sec_api/sys/*.h
])
GDIPLUSHEAD_LIST=$srcdir/include/gdiplus/*.h
GLHEAD_LIST=$srcdir/include/GL/*.h
MINGWHELPERHEAD_LIST=$srcdir/include/psdk_inc/*.h
AC_SUBST([BASEHEAD_LIST])
AC_SUBST([GDIPLUSHEAD_LIST])
AC_SUBST([GLHEAD_LIST])
AC_SUBST([MINGWHELPERHEAD_LIST])
AC_SUBST([SYSHEAD_LIST])
AC_SUBST([SECHEAD_LIST])
AC_SUBST([SECSYSHEAD_LIST])

enable_directx=no
enable_ddk=no
enable_idl=no

AC_MSG_CHECKING([for optional sdk headers])
AC_ARG_ENABLE([sdk],
  [AS_HELP_STRING([--enable-sdk=ARG],
    [Add the desired SDK, where ARG can be one of ddk, directx, idl or all])],
  [],
  [enable_sdk=no])
AS_CASE([$enable_sdk],
  [all|yes],[
    enable_sdk="ddk,directx,idl"
    enable_ddk=yes
    enable_directx=yes],
  [ddk],[
    enable_ddk=yes],
  [directx],[
    enable_directx=yes],
  [idl],[
    enable_idl=yes],
  [no],[],
  [AC_MSG_ERROR([Invalid option: $enable_sdk.  Please choose one of ddk, directx, idl or all.])])
AC_MSG_RESULT([$enable_sdk])

AS_VAR_IF([enable_directx],[yes],[
    DXHEAD_LIST=$srcdir/direct-x/include/*.[[hi]]*
    MINGW_HAS_DX=1
  ],[
    MINGW_HAS_DX=0
  ])
AC_SUBST([DXHEAD_LIST])
AC_SUBST([MINGW_HAS_DX])

AS_VAR_IF([enable_ddk],[yes],[
    DDKHEAD_LIST=$srcdir/ddk/include/ddk/*.h
    MINGW_HAS_DDK=1
  ],[
    MINGW_HAS_DDK=0
  ])
AC_SUBST([DDKHEAD_LIST])
AC_SUBST([MINGW_HAS_DDK])

AS_VAR_IF([enable_idl],[yes],[
    IDLHEAD_LIST=$srcdir/idl/*.idl],[])
AC_SUBST([IDLHEAD_LIST])

AC_MSG_CHECKING([whether to enable the secure API])
AC_ARG_ENABLE([secure-api],
  [AS_HELP_STRING([--enable-secure-api],
    [Enable secure API by default])],
  [enable_secure_api=yes])
AC_MSG_RESULT([$enable_secure_api])
AS_VAR_IF([enable_secure_api],[yes],
  [MINGW_HAS_SECURE_API="#define MINGW_HAS_SECURE_API 1"],
  [MINGW_HAS_SECURE_API=""])
AC_SUBST([MINGW_HAS_SECURE_API])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([
  Makefile
  crt/_mingw.h
])
AC_OUTPUT

