#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# Use AM_MAINTANER_MODE somewhere in this file once reconfigurations settle down.

AC_PREREQ([2.71])
AC_INIT([mingw-w64-runtime],[4.0b],[mingw-w64-public@lists.sourceforge.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([ChangeLog])
AC_CONFIG_HEADERS([config.h])

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

AC_MSG_CHECKING([whether dlltool supports --temp-prefix])
cat > test.def <<EOF
LIBRARY test.dll
EXPORTS
myfunc
EOF

AS_VAR_SET([test_dlltool_flags],[])
AC_DEFUN([TEST_DLLTOOL], [
  test_dlltool_flags_save="$test_dlltool_flags"
  test_dlltool_flags="$test_dlltool_flags $1"
  AS_ECHO([["$DLLTOOL $test_dlltool_flags -d test.def -l libtest.a"]]) >&AS_MESSAGE_LOG_FD
  AS_IF($DLLTOOL $test_dlltool_flags -d test.def -l libtest.a >&AS_MESSAGE_LOG_FD 2>&AS_MESSAGE_LOG_FD, [
    $2
  ], [
    test_dlltool_flags="$test_dlltool_flags_save"
  ])
])

# First check if $DLLTOOL supports the -m option. LLVM dlltool might not
# have a default arch (in older versions), so make sure we specify one.
TEST_DLLTOOL([--as-flags=--64 -m i386:x86-64])
# Now check if --temp-prefix is supported. GNU dlltool supports it,
# LLVM dlltool doesn't, yet at least (but doesn't need it either).
AS_VAR_SET([dlltool_has_temp_prefix],[no])
TEST_DLLTOOL([--temp-prefix myprefix], [dlltool_has_temp_prefix=yes])

rm -f test.def libtest.a
AC_MSG_RESULT([$dlltool_has_temp_prefix])
AM_CONDITIONAL([DLLTOOL_HAS_TEMP_PREFIX],[test $dlltool_has_temp_prefix = yes])

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

AC_MSG_CHECKING([whether to build the WinARM32 libraries])
AC_ARG_ENABLE([libarm32],
  [AS_HELP_STRING([--enable-libarm32],
    [Build the WinARM32 libraries])],
  [],
  [AS_CASE([$host_cpu],
    [armv7*],[enable_libarm32=yes],
    [*],[enable_libarm32=no])
  ])
AC_MSG_RESULT([$enable_libarm32])
AS_CASE([$enable_libarm32],
  [no],[],
  [yes],[AS_VAR_SET([LIBARM32])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([LIBARM32], [AS_VAR_TEST_SET([LIBARM32])])

AS_VAR_IF([enable_libarm32],[yes],[
  AS_IF([AS_VAR_TEST_SET([LIB32]) || AS_VAR_TEST_SET([LIB64])],
    [AC_MSG_WARN([Building the runtime to use libarm32 with lib32 or lib64 is unsupported.])])])

AC_MSG_CHECKING([whether to build the WinARM64 libraries])
AC_ARG_ENABLE([libarm64],
  [AS_HELP_STRING([--enable-libarm64],
    [Build the WinARM64 libraries])],
  [],
  [AS_CASE([$host_cpu],
    [aarch64*],[enable_libarm64=yes],
    [*],[enable_libarm64=no])
  ])
AC_MSG_RESULT([$enable_libarm64])
AS_CASE([$enable_libarm64],
  [no],[],
  [yes],[AS_VAR_SET([LIBARM64])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([LIBARM64], [AS_VAR_TEST_SET([LIBARM64])])

AS_VAR_IF([enable_libarm64],[yes],[
  AS_IF([AS_VAR_TEST_SET([LIB32]) || AS_VAR_TEST_SET([LIB64]) || AS_VAR_TEST_SET([LIBARM32])],
    [AC_MSG_WARN([Building the runtime to use libarm64 with lib32, lib64 or libarm32 is unsupported.])])])

AS_CASE([$host_cpu],
  [x86_64],[
    libx8664suffx=lib
    libx8632suffx=lib32
    libarm64suffx=libarm64
    libarm32suffx=libarm32],
  [i*86],[
    libx8664suffx=lib64
    libx8632suffx=lib
    libarm64suffx=libarm64
    libarm32suffx=libarm32],
  [aarch64*],[
    libx8664suffx=libx8664
    libx8632suffx=libx8632
    libarm64suffx=lib
    libarm32suffx=lib32],
  [armv7*],[
    libx8664suffx=libx8664
    libx8632suffx=libx8632
    libarm64suffx=lib64
    libarm32suffx=lib],
  [
    libx8664suffx=libx8664
    libx8632suffx=libx8632
    libarm64suffx=libarm64
    libarm32suffx=libarm32]
)

AS_VAR_IF([enable_w32api],[yes],[
  libx8664suffx=$libx8664suffx/w32api
  libx8632suffx=$libx8632suffx/w32api
  libarm64suffx=$libarm64suffx/w32api
  libarm32suffx=$libarm32suffx/w32api
])

AC_SUBST([LIBX8664SUFFIXDIR],[$libx8664suffx])
AC_SUBST([LIBX8632SUFFIXDIR],[$libx8632suffx])
AC_SUBST([LIBARM64SUFFIXDIR],[$libarm64suffx])
AC_SUBST([LIBARM32SUFFIXDIR],[$libarm32suffx])

# Checks for features.

AC_MSG_CHECKING([whether to use genlib])
AC_ARG_WITH([genlib],
  [AS_HELP_STRING([--with-genlib=PATH],
    [Whether to build import libraries via the genlib tool (default: no)])],
  [],
  [with_genlib=no])
AS_CASE([$with_genlib],
  [yes],[AC_CHECK_TOOL([GENLIB], [genlib], [:])],
  [no],[],
  [AS_VAR_SET([GENLIB], [$with_genlib])])
AM_CONDITIONAL([WITH_GENLIB], [AS_VAR_TEST_SET([GENLIB])])
AC_MSG_RESULT([$with_genlib])

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

AC_MSG_CHECKING([what to provide as libmsvcrt.a])
AC_ARG_WITH([default-msvcrt],
  [AS_HELP_STRING([--with-default-msvcrt=LIB],
    [Lib to provide as libmsvcrt.a (default: msvcrt-os)])],
  [],
  [with_default_msvcrt=msvcrt-os])
if test "$with_default_msvcrt" = "msvcrt"; then
  with_default_msvcrt=msvcrt-os
fi
AC_MSG_RESULT([$with_default_msvcrt])
AS_VAR_SET([MSVCRT_LIB],[lib${with_default_msvcrt}.a])
AC_SUBST([MSVCRT_LIB])

AC_MSG_CHECKING([whether to include support for Control Flow Guard])
AC_ARG_ENABLE([cfguard],
  [AS_HELP_STRING([--enable-cfguard],
    [Enable building with Control Flow Guard support (Clang)])],
  [],
  [AS_VAR_SET([enable_cfguard],[no])])
AC_MSG_RESULT([$enable_cfguard])
AS_CASE([$enable_cfguard],
  [no],[],
  [yes],[AS_VAR_SET([CFGUARD])
	 AS_VAR_SET([CFGUARD_CFLAGS],[-mguard=cf])],
  [AC_MSG_ERROR([invalid argument.  Must be either yes or no.])])
AM_CONDITIONAL([CFGUARD], [AS_VAR_TEST_SET([CFGUARD])])
AC_SUBST([CFGUARD_CFLAGS])

AC_MSG_CHECKING([whether to enable experimental features])
AC_ARG_ENABLE([experimental],
  [AS_HELP_STRING([--enable-experimental],
    [Enable experimental features, valid options are comma separated combination of all, dfp, printf128, registeredprintf, softmath.])],
    [experimental_features=$enable_experimental],
    [experimental_features="no"])

enable_dfp=no
enable_printf128=no
enable_registeredprintf=no
enable_softmath=no
experiment_list=$($AWK 'BEGIN{OFS=" "; len = split(ARGV@<:@1@:>@,str,","); for(; len != 0; len--) print str@<:@len@:>@ }' "$experimental_features")

for arg in $experiment_list
do
AS_CASE([$arg],
  [dfp],[enable_dfp=yes],
  [printf128],[enable_printf128=yes],
  [registeredprintf],[enable_registeredprintf=yes],
  [softmath],[enable_softmath=yes],
  [all], [enable_dfp=yes; enable_printf128=yes; enable_registeredprintf=yes; enable_softmath=yes; ],
  [yes], [enable_dfp=yes; enable_printf128=yes; enable_registeredprintf=yes; enable_softmath=yes; ],
  [no],  [enable_dfp=no; enable_printf128=no; enable_registeredprintf=no; enable_softmath=no; ],
  [AC_MSG_ERROR([Unknown option "$arg"])]
)
done

AC_MSG_RESULT([$experimental_features])
AM_CONDITIONAL([ENABLE_DFP],[ test "$enable_dfp" = "yes" ])
AM_CONDITIONAL([ENABLE_PRINTF128],[ test "$enable_printf128" = "yes" ])
AM_CONDITIONAL([ENABLE_REGISTEREDPRINTF],[ test "$enable_registeredprintf" = "yes" ])
AM_CONDITIONAL([ENABLE_SOFTMATH],[ test "$enable_softmath" = "yes" ])
AM_COND_IF([ENABLE_DFP],[AC_DEFINE([__ENABLE_DFP],[1],[Build DFP support])])
AM_COND_IF([ENABLE_PRINTF128],[AC_DEFINE([__ENABLE_PRINTF128],[1],[Build DFP support])])
AM_COND_IF([ENABLE_REGISTEREDPRINTF],[AC_DEFINE([__ENABLE_REGISTEREDPRINTF],[1],[Build DFP support])])
AM_COND_IF([ENABLE_SOFTMATH],[AC_DEFINE([__ENABLE_SOFTMATH],[1],[Build softmath routines])])

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
    ADD_C_ONLY_WARNING_FLAGS="-Wimplicit-function-declaration -Wmissing-noreturn -Wmissing-prototypes"],
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
AC_MSG_NOTICE([  WinARM32 runtime.....: $enable_libarm32])
AC_MSG_NOTICE([  WinARM64 runtime.....: $enable_libarm64])
AC_MSG_NOTICE([  Win32 runtime........: $enable_lib32])
AC_MSG_NOTICE([  Win64 runtime........: $enable_lib64])
AC_MSG_NOTICE([  C Warning Flags......: $ADD_C_ONLY_WARNING_FLAGS])
AC_MSG_NOTICE([  C++ Warning Flags....: $ADD_CXX_ONLY_WARNING_FLAGS])
AC_MSG_NOTICE([  Common Warning Flags.: $ADD_C_CXX_WARNING_FLAGS])
AC_MSG_NOTICE([  Default msvcrt.......: $with_default_msvcrt])
AC_MSG_NOTICE([  Control Flow Guard...: $enable_cfguard])
AC_MSG_NOTICE([])
AC_MSG_NOTICE([  DFP printf...........: $enable_dfp])
AC_MSG_NOTICE([  128-bit printf.......: $enable_printf128])
AC_MSG_NOTICE([  Custom printf........: $enable_registeredprintf])
AC_MSG_NOTICE([  Softhmath............: $enable_softmath])
AC_MSG_NOTICE([])


