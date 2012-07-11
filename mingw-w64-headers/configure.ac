#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([mingw-w64-headers],[3.0b],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_SRCDIR([crt/_mingw.h.in])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_SED

AC_MSG_CHECKING([whether to rebuild headers with widl])
AC_ARG_WITH([widl],
  AS_HELP_STRING([--with-widl=PATH],
    [use widl to update idl-based headers]),
  [],
  [AS_VAR_SET([with_widl],[no])])
AS_CASE([$with_widl],
  [no],[],
  [yes],[AS_VAR_SET([with_widl],["mingw-w64-widl widl"])],
  [])
AC_MSG_RESULT([$with_widl])

AS_VAR_IF([with_widl],[no],[],[
  AC_PATH_PROGS([WIDL], [$with_widl], [])
  AS_VAR_IF([WIDL],[],[AC_MSG_ERROR([Could not find widl installation, which is required in maintainer mode])])])

AM_CONDITIONAL([HAVE_WIDL],[AS_VAR_TEST_SET([WIDL])])

# Checks for libraries.

# Checks for header files.

BASEHEAD_LIST="crt/_bsd_types.h crt/_cygwin.h crt/_mingw.h crt/_mingw_mac.h crt/_mingw_print_push.h crt/_mingw_print_pop.h crt/_mingw_secapi.h crt/_mingw_unicode.h crt/_timeval.h crt/crtdefs.h crt/excpt.h crt/vadefs.h "$srcdir/include/*.h
SECHEAD_LIST="$srcdir/crt/sec_api/stralign_s.h"
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

AC_MSG_CHECKING([for optional sdk headers])
AC_ARG_ENABLE([sdk],
  [AS_HELP_STRING([--enable-sdk=ARG],
    [Add the desired SDK, where ARG can be one of ddk, directx, no or all.  Default is all.])],
  [],
  [AS_VAR_SET([enable_sdk],[all])])

AS_CASE([$enable_sdk],
  [all|yes],[
    AS_VAR_SET([enable_sdk],[ddk,directx])
    AS_VAR_SET([enable_ddk],[yes])
    AS_VAR_SET([enable_directx],[yes])],
  [ddk],[
    AS_VAR_SET([enable_ddk],[yes])],
  [directx],[
    AS_VAR_SET([enable_directx],[yes])],
  [no],[],
  [AC_MSG_ERROR([Invalid option: $enable_sdk.  Please choose one of ddk, directx, no or all.])])
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

AC_MSG_CHECKING([if installing idl files is enabled])
AC_ARG_ENABLE([idl],
    [AS_HELP_STRING([--enable-idl],
        [Enable installing idl files (default disabled)])],
    [enable_idl=yes])
AC_MSG_RESULT([$enable_idl])
AS_VAR_IF([enable_idl],[yes],
    [IDLHEAD_LIST=$srcdir/include/*.idl],
    [IDLHEAD_LIST=""])
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

