#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# Use AM_MAINTANER_MODE somewhere in this file once reconfigurations settle down.

AC_PREREQ([2.69])
AC_INIT([mingw-w64-runtime],[4.0b],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([ChangeLog])
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE([1.14 foreign subdir-objects])
AM_MAINTAINER_MODE

AC_CANONICAL_HOST

AC_MSG_CHECKING([for sysroot])
AC_ARG_WITH([sysroot],
  [AS_HELP_STRING([--with-sysroot=DIR],
    [Search for headers within DIR/include (default: prefix)])],
  [],
  [AS_VAR_SET([with_sysroot],[yes])])
AS_CASE([$with_sysroot],
  [no],[],
  [yes],[AS_VAR_SET([with_sysroot],[$prefix])],
  [])
AC_MSG_RESULT([$with_sysroot])
AS_VAR_IF([with_sysroot],[no],[],[AS_VAR_SET([TARGET_SYSTEM_ROOT],[$with_sysroot])])
AC_SUBST([TARGET_SYSTEM_ROOT])
AM_CONDITIONAL([WITHSYSROOT],[AS_VAR_TEST_SET([TARGET_SYSTEM_ROOT])])


# Checks for programs.
# Checks for headers, libs, etc need to utilize the sysroot... no idea how
AC_NO_EXECUTABLES
AC_PROG_SED
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_RANLIB
AC_CHECK_TOOL([DLLTOOL], [dlltool], [:])
AM_PROG_AR
AM_PROG_AS
dnl Remove this once automake fixes the bug where AS is not defined according to $host
AC_CHECK_TOOL([AS], [as], [:])
dnl ---
AM_PROG_CC_C_O

AC_MSG_CHECKING([whether to build a w32api package for Cygwin])
AC_ARG_ENABLE([w32api],
  [AS_HELP_STRING([--enable-w32api],
    [Enable building a w32api package for Cygwin])],
  [],
  [AS_VAR_SET([enable_w32api],[no])])
AC_MSG_RESULT([$enable_w32api])
AS_CASE([$enable_w32api],
  [no],[],
  [yes],[AS_VAR_SET([W32API])
	 AS_VAR_SET([includedir],[${prefix}/include/w32api])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([W32API], [AS_VAR_TEST_SET([W32API])])

AC_MSG_CHECKING([whether to build the Win32 libraries])
AC_ARG_ENABLE([lib32],
  [AS_HELP_STRING([--enable-lib32],
    [Build the Win32 libraries])],
  [],
  [
    _save_CFLAGS="$CFLAGS"
    CFLAGS="$CFLAGS -m32"
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[const char test[(sizeof(void*)==4)?0:-1];]],[])],
      [enable_lib32=yes],
      [enable_lib32=no])
    CFLAGS="$_save_CFLAGS"])
AC_MSG_RESULT([$enable_lib32])
AS_CASE([$enable_lib32],
  [no],[],
  [yes],[AS_VAR_SET([LIB32])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([LIB32], [AS_VAR_TEST_SET([LIB32])])

AC_MSG_CHECKING([whether to build the Win64 libraries])
AC_ARG_ENABLE([lib64],
  [AS_HELP_STRING([--enable-lib64],
    [Build the Win64 libraries])],
  [],
  [
    _save_CFLAGS="$CFLAGS"
    CFLAGS="$CFLAGS -m64"
    AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[const char test[(sizeof(void*)==8)?0:-1];]],[])],
      [enable_lib64=yes],
      [enable_lib64=no])
    CFLAGS="$_save_CFLAGS"])
AC_MSG_RESULT([$enable_lib64])
AS_CASE([$enable_lib64],
  [no],[],
  [yes],[AS_VAR_SET([LIB64])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([LIB64], [AS_VAR_TEST_SET([LIB64])])

AC_MSG_CHECKING([whether to build the WinCE libraries])
AC_ARG_ENABLE([libce],
  [AS_HELP_STRING([--enable-libce],
    [Build the WinCE libraries])],
  [],
  [AS_CASE([$host_cpu],
    [arm*],[enable_libce=yes],
    [*],[enable_libce=no])
  ])
AC_MSG_RESULT([$enable_libce])
AS_CASE([$enable_libce],
  [no],[],
  [yes],[AS_VAR_SET([LIBCE])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([LIBCE], [AS_VAR_TEST_SET([LIBCE])])

AS_VAR_IF([enable_libce],[yes],[
  AS_IF([AS_VAR_TEST_SET([LIB32]) || AS_VAR_TEST_SET([LIB64])],
    [AC_MSG_WARN([Building the runtime to use libce with lib32 or lib64 is unsupported.])])])

AS_CASE([$host_cpu],
  [x86_64],[
    lib64suffx=lib
    lib32suffx=lib32],
  [i*86],[
    lib64suffx=lib64
    lib32suffx=lib],
  [
    lib64suffx=lib64
    lib32suffx=lib32]
)

AS_VAR_IF([enable_w32api],[yes],[
  lib64suffx=$lib64suffx/w32api
  lib32suffx=$lib32suffx/w32api
])

AC_SUBST([LIB64SUFFIXDIR],[$lib64suffx])
AC_SUBST([LIB32SUFFIXDIR],[$lib32suffx])

# Checks for features.

AC_MSG_CHECKING([whether to enable globbing])
AC_ARG_ENABLE([wildcard],
  [AS_HELP_STRING([--enable-wildcard],
    [Enable command line globbing])],
  [],
  [enable_wildcard=no])
AS_CASE([$enable_wildcard],
  [yes],[enable_wildcard_value=-1],
  [no],[enable_wildcard_value=0],
  [AC_MSG_ERROR([Please only use --enable-wildcard or --disable-wildcard, without any additional arguments.])])
AC_DEFINE_UNQUOTED([__ENABLE_GLOBBING],[$enable_wildcard_value],[Define as -1 to enable command line globbing or 0 to disable it.])
AC_MSG_RESULT([$enable_wildcard])

AC_MSG_CHECKING([whether to enable private exports])
AC_ARG_ENABLE([private-exports],
  [AS_HELP_STRING([--enable-private-exports],
    [Enable exporting private internal functions])],
  [],
  [enable_private_exports=no])
AS_CASE([$enable_private_exports],
  [yes],[],
  [no],[],
  [AC_MSG_ERROR([Please only use --enable-private-exports  or --disable-private-exports, without any additional arguments.])])
AM_CONDITIONAL([PRIVATE_EXPORTS],[test $enable_private_exports = yes])
AC_MSG_RESULT([$enable_private_exports])

AC_MSG_CHECKING([whether to enable delay import libs])
AC_ARG_ENABLE([delay-import-libs],
  [AS_HELP_STRING([--enable-delay-import-libs],
    [Enable creation of delay-import libraries])],
  [],
  [enable_delay_import_libs=no])
AS_CASE([$enable_delay_import_libs],
  [yes],[],
  [no],[],
  [AC_MSG_ERROR([Please only use --enable-delay-import-libs  or --disable-delay-import-libs, without any additional arguments.])])
AM_CONDITIONAL([DELAY_IMPORT_LIBS],[test $enable_delay_import_libs = yes])
AC_MSG_RESULT([$enable_delay_import_libs])

AC_MSG_CHECKING([whether to enable experimental features])
AC_ARG_ENABLE([experimental],
  [AS_HELP_STRING([--enable-experimental],
    [Enable experimental features, valid options are comma separated combination of all, dfp, printf128, registeredprintf. Refer to experimental.txt for descriptions.])],
    [experimental_features=$enable_experimental],
    [experimental_features="no"])

enable_dfp=no
enable_printf128=no
enable_registeredprintf=no
experiment_list=$($AWK 'BEGIN{OFS=" "; len = split(ARGV@<:@1@:>@,str,","); for(; len != 0; len--) print str@<:@len@:>@ }' "$experimental_features")

for arg in $experiment_list
do
AS_CASE([$arg],
  [dfp],[enable_dfp=yes],
  [printf128],[enable_printf128=yes],
  [registeredprintf],[enable_registeredprintf=yes],
  [all], [enable_dfp=yes; enable_printf128=yes; enable_registeredprintf=yes; ],
  [yes], [enable_dfp=yes; enable_printf128=yes; enable_registeredprintf=yes; ],
  [no],  [enable_dfp=no; enable_printf128=no; enable_registeredprintf=no; ],
  [AC_MSG_ERROR([Unknown option \"$experiment\"])]
)
done

AC_MSG_RESULT([$experimental_features])
AM_CONDITIONAL([ENABLE_DFP],[ test "$enable_dfp" = "yes" ])
AM_CONDITIONAL([ENABLE_PRINTF128],[ test "$enable_printf128" = "yes" ])
AM_CONDITIONAL([ENABLE_REGISTEREDPRINTF],[ test "$enable_registeredprintf" = "yes" ])
AM_COND_IF([ENABLE_DFP],[AC_DEFINE([__ENABLE_DFP],[1],[Build DFP support])])
AM_COND_IF([ENABLE_PRINTF128],[AC_DEFINE([__ENABLE_PRINTF128],[1],[Build DFP support])])
AM_COND_IF([ENABLE_REGISTEREDPRINTF],[AC_DEFINE([__ENABLE_REGISTEREDPRINTF],[1],[Build DFP support])])

AC_MSG_CHECKING([whether the compiler supports -municode])
AC_ARG_ENABLE([tests-unicode],
  [AS_HELP_STRING([--enable-tests-unicode],
    [Enable the unicode testsuite without testing the compiler for support.])],
  [],[
    saved_CFLAGS="$CFLAGS"
    CFLAGS="$CFLAGS -municode"
    AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#ifndef UNICODE
# error UNICODE not defined with -municode
#endif
    ]])],
    [enable_tests_unicode=yes],
    [enable_tests_unicode=no])
    CFLAGS="$saved_CFLAGS"])
AM_CONDITIONAL([ENABLE_TESTS_UNICODE],[test x$enable_tests_unicode = xyes])
AC_MSG_RESULT([$enable_tests_unicode])

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
AC_MSG_NOTICE([  DFP printf...........: $enable_dfp])
AC_MSG_NOTICE([  128-bit printf.......: $enable_printf128])
AC_MSG_NOTICE([  Custom printf........: $enable_registeredprintf])
AC_MSG_NOTICE([])


