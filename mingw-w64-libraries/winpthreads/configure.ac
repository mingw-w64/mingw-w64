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

dnl Global compiler and linker flags. We handle compiler-specific flags in
dnl configure.ac rather than in each Makefile.am. Note that it does not prevent
dnl each individual Makefile.am from extending these variables.
dnl
dnl Please note that `AC_COMPILE_IFELSE` and `AC_LINK_IFELSE` use user variables
dnl `CPPFLAGS`, `CFLAGS` and `LDFLAGS`. When running those checks, we can modify
dnl them in order to run a test, but then we must restore previous value and
dnl instead modify `AM_*` equivalents accordingly.
CRT_DEFINES=
DEFAULT_WARNINGS=
LINKER_SUBSYSTEM=

AC_SUBST([CRT_DEFINES])
AC_SUBST([DEFAULT_WARNINGS])
AC_SUBST([LINKER_SUBSYSTEM])

AS_IF(
  [test $msvc = yes],
    # Do not warn about using non-standard function names such as `strdup`
    [CRT_DEFINES="$CRT_DEFINES -D_CRT_NONSTDC_NO_WARNINGS"]
    # Make Windows SDK headers declare non-standard names;
    # required if -Zc:__STDC__ option is used
    [CRT_DEFINES="$CRT_DEFINES -D_CRT_DECLARE_NONSTDC_NAMES"]
    # Do not warn about using "unsafe" functions
    [CRT_DEFINES="$CRT_DEFINES -D_CRT_SECURE_NO_WARNINGS"]
    # MSVC's -Wall enables _all_ warnings, which is too much
    [DEFAULT_WARNINGS='-W3'],
dnl else
    # Do not use mingw-w64 stdio functions
    [CRT_DEFINES="$CRT_DEFINES -D__USE_MINGW_ANSI_STDIO=0"]
    [DEFAULT_WARNINGS='-Wall']
)

# config.h
AH_BOTTOM(
[#ifdef DLL_EXPORT
#define WINPTHREAD_API __declspec(dllexport)
#else
#define WINPTHREAD_API
#endif]dnl
)

AC_CONFIG_FILES([Makefile tests/Makefile])
AC_OUTPUT
