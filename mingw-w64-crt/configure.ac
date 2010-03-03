#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# Use AM_MAINTANER_MODE somewhere in this file once reconfigurations settle down.

AC_PREREQ([2.65])
AC_INIT([mingw-w64-runtime],[1.0b],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([ChangeLog])
AC_CONFIG_HEADER([config.h])

AM_MAINTAINER_MODE
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_CANONICAL_HOST

AC_MSG_CHECKING([for sysroot])
AC_ARG_WITH([sysroot],
  [AS_HELP_STRING([--with-sysroot=DIR],
    [Search for include within DIR/mingw.])],
  [AS_CASE([$with_sysroot],
    [no],[AC_MSG_RESULT([no])],
    [yes],[AC_MSG_RESULT([none specified])
      AC_MSG_ERROR([Please specify a directory to the --with-sysroot=DIR option])
    ],[
      AC_MSG_RESULT([$with_sysroot])
      TARGET_SYSTEM_ROOT=$with_sysroot
      AC_MSG_CHECKING([if sysroot contains an include directory])
      AS_IF([test -d $with_sysroot/$host/include],
        [AC_MSG_RESULT([yes])],
        [
          AC_MSG_RESULT([no])
          AC_MSG_ERROR([Sysroot directory does not contain $host/include])
          with_sysroot=no
        ])
    ])
  ],
  [
    AC_MSG_RESULT([no])
    TARGET_SYSTEM_ROOT=
    with_sysroot=no
  ])
AM_CONDITIONAL(WITHSYSROOT, test $with_sysroot != no)
AC_SUBST(TARGET_SYSTEM_ROOT)

# Checks for programs.
# Checks for headers, libs, etc need to utilize the sysroot... no idea how
AC_NO_EXECUTABLES
AC_PROG_SED
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_LIBTOOL_WIN32_DLL
AC_DISABLE_STATIC
AC_PROG_LIBTOOL
AM_PROG_AS
AM_PROG_CC_C_O

AC_ARG_ENABLE([lib32],
  [AS_HELP_STRING([--enable-lib32],
    [enable compiling the Win32 runtime])],
  [],
  [AC_MSG_CHECKING([whether to build the Win32 runtime])
   _save_CFLAGS="$CFLAGS"
   CFLAGS="$CFLAGS -m32"
   AC_COMPILE_IFELSE(
     [AC_LANG_PROGRAM(
       [[const char test[(sizeof(void*)==4)?0:-1];]],
       []
     )],
     [enable_lib32=yes],
     [enable_lib32=no])
   AC_MSG_RESULT([$enable_lib32])
   CFLAGS="$_save_CFLAGS"
  ])
AM_CONDITIONAL([LIB32], [test $enable_lib32 = yes])

AC_ARG_ENABLE([lib64],
  [AS_HELP_STRING([--enable-lib64],
    [enable compiling the Win64 runtime])],
  [],
  [AC_MSG_CHECKING([whether to build the Win64 runtime])
   _save_CFLAGS="$CFLAGS"
   CFLAGS="$CFLAGS -m64"
   AC_COMPILE_IFELSE(
     [AC_LANG_PROGRAM(
       [[const char test[(sizeof(void*)==8)?0:-1];]],
       []
     )],
     [enable_lib64=yes],
     [enable_lib64=no])
   AC_MSG_RESULT([$enable_lib64])
   CFLAGS="$_save_CFLAGS"
  ])
AM_CONDITIONAL([LIB64], [test $enable_lib64 = yes])

AC_ARG_ENABLE([libce],
  [AS_HELP_STRING([--enable-libce],
    [enable compiling the WinCE runtime])],
  [],
  [AS_CASE([$host_cpu],
    [arm*],
      [enable_libce=yes],
    [*],
      [enable_libce=no])
  ])
AM_CONDITIONAL([LIBCE], [test $enable_libce = yes])

AS_IF([test "$enable_lib32" = no && test "$enable_lib64" = no],
        [],
      [test "$enable_libce" = yes],
        [AC_MSG_WARN([Building the runtime to use libce with lib32 or lib64 is unsupported.])])

AS_CASE([$host_cpu],
  [x86_64],[
    AC_SUBST([LIB64SUFFIXDIR],[lib])
    AC_SUBST([LIB32SUFFIXDIR],[lib32])],
  [i*86],[
    AC_SUBST([LIB64SUFFIXDIR],[lib64])
    AC_SUBST([LIB32SUFFIXDIR],[lib])],
  [*],[
    AC_SUBST([LIB64SUFFIXDIR],[lib64])
    AC_SUBST([LIB32SUFFIXDIR],[lib32])]
  )

# Checks for features.

AC_ARG_ENABLE(
  wildcard,
  AS_HELP_STRING([--enable-wildcard],[Enable command line globbing [[default=no]]]),
  [],
  [enable_wildcard=no]
)
AS_IF(
  [test x$enable_wildcard = xyes],
  [AC_DEFINE(__ENABLE_GLOBBING,-1, [Define as -1 if want to enable command line globbing, 0 otherwise])],
  [AC_DEFINE(__ENABLE_GLOBBING, 0, [Define as -1 if want to enable command line globbing, 0 otherwise])]
)

# Checks for libraries.

# Checks for header files.
#AC_HEADER_DIRENT
#AC_HEADER_STDC
#AC_CHECK_HEADERS([fcntl.h fenv.h float.h inttypes.h limits.h locale.h malloc.h stddef.h stdint.h stdlib.h string.h sys/ioctl.h sys/time.h sys/timeb.h termios.h unistd.h wchar.h wctype.h])

# Checks for typedefs, structures, and compiler characteristics.
#AC_C_INLINE
#AC_HEADER_TIME
#AC_C_VOLATILE
#AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
#AC_FUNC_MALLOC
#AC_FUNC_MBRTOWC
#AC_FUNC_REALLOC
#AC_FUNC_STRTOD
#AC_FUNC_VPRINTF
#AC_CHECK_FUNCS([alarm atexit btowc fesetround floor ftruncate gettimeofday isascii localeconv mbrlen memmove memset pow rint setlocale sqrt strcasecmp strchr strncasecmp strtoull strtoumax])

AC_CHECK_HEADER([_mingw_mac.h], [], [AC_MSG_ERROR([Please check if the mingw-w64 header set and the build/host option are set properly.])])

#Warnings and errors, default level is 3
AC_MSG_CHECKING([for warning levels])
AC_ARG_ENABLE([warnings],
  [AS_HELP_STRING([[--enable-warnings[=0-5]]], 
    [Enable compile time warnings @<:@default=3@:>@])],
  [AS_CASE([$enableval],
    [yes], [warning_level=3],
    [no],  [warning_level=0],
    [[[0-5]]], [warning_level="$enableval"],
    [warning_level=3])],
  [warning_level=3])
AC_MSG_RESULT([Level $warning_level])

#Add warning flags as appropriate. Level 4 and above are only for testing purpose.
AS_CASE([$warning_level],
  [0],[ADD_C_CXX_WARNING_FLAGS="-Wall"],
  [1],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra"
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration"],
  [2],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra -Wformat -Wstrict-aliasing -Wshadow -Wpacked -Winline" 
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration"],
  [3],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra -Wformat -Wstrict-aliasing -Wshadow -Wpacked -Winline" 
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration -Wmissing-noreturn -Wmissing-prototypes"],
  [4],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra -Wformat -Wstrict-aliasing=2 -Wsystem-headers -Wshadow -Wmissing-declarations -Wpacked -Winline -Werror -pedantic" 
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration -Wmissing-noreturn -Wmissing-prototypes"]
  [5],[
    ADD_C_CXX_WARNING_FLAGS="-Wall -Wextra -Wformat -Wstrict-aliasing=2 -Wsystem-headers -Wshadow -Wmissing-declarations -Wpacked -Wredundant-decls -Winline -Werror -Wfatal-errors -pedantic -pedantic-errors" 
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration -Wmissing-noreturn -Wmissing-prototypes"]
   )

AC_SUBST(ADD_C_ONLY_WARNING_FLAGS)
AC_SUBST(ADD_C_CXX_WARNING_FLAGS)
AC_SUBST(ADD_CXX_ONLY_WARNING_FLAGS)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

AC_MSG_NOTICE([])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([------------------------------------------------------------------------])
AC_MSG_NOTICE([$PACKAGE $VERSION])
AC_MSG_NOTICE([------------------------------------------------------------------------])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([Configuration Options Summary:])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([  WinCE runtime........: $enable_libce])
AC_MSG_NOTICE([  Win32 runtime........: $enable_lib32])
AC_MSG_NOTICE([  Win64 runtime........: $enable_lib64])
AC_MSG_NOTICE([  C Warning Flags......: $ADD_C_ONLY_WARNING_FLAGS])
AC_MSG_NOTICE([  C++ Warning Flags....: $ADD_CXX_ONLY_WARNING_FLAGS])
AC_MSG_NOTICE([  Common Warning Flags.: $ADD_C_CXX_WARNING_FLAGS])
AC_MSG_NOTICE([])


