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

# Validate $host_cpu and simplify it for use in later checks
winpthreads_host=$host_cpu

AS_CASE(
  [$winpthreads_host],
    [i?86],
      [winpthreads_host=x86],
    [x86_64],
      [winpthreads_host=x64],
    [arm | armv7],
      [winpthreads_host=arm32],
    [aarch64],
      [winpthreads_host=arm64],
    [arm64ec],
      [winpthreads_host=arm64ec],
dnl default
      [AC_MSG_ERROR([Unsupported host '$host'])]
)

dnl This invocation may set variable `ac_no_link` to "yes", which will make
dnl `AC_LINK_IFELSE` abort configuration. Each use of `AC_LINK_IFELSE` must
dnl be guarded with `test $ac_no_link = no` check.
AC_NO_EXECUTABLES
dnl Checks for programs.
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

AC_ARG_WITH(
  [winnt],
  [AS_HELP_STRING(
    [--with-winnt=VERSION],
    [Minimal Windows NT version to support],
  )],
dnl then
  [AS_CASE(
    [$withval],
      [win10 | win8 | win8.1 | win7 | winvista | winxp | win2000 | nt4.0 | nt3.51 | nt3.5 | nt3.1],
        [:],
dnl   default
        [AC_MSG_ERROR([Invalid value '$withval' passed to --with-winnt option])]
  )],
dnl else
  [AS_CASE(
    [$winpthreads_host],
      [x86],
        [AS_IF(
          [test $msvc = yes],
            [with_winnt=winxp],
dnl       else
            [with_winnt=nt3.1]
        )],
      [x64],
        [with_winnt=winxp],
      [arm32],
        [with_winnt=win8],
      [arm64 | arm64ec],
        [with_winnt=win10]
  )]
)

# Major and minor subsystem versions corresponding to --with-winnt option
subsystem_major=
subsystem_minor=

# `WINPTHREADS_WINNT_*` value corresponding to --with-winnt option;
# see misc.h for valid values
winpthreads_winnt=

AS_CASE(
  [$with_winnt],
    [win10],
      [AS_IF(
        # FIXME: mingw-w64 tools produce broken binaries when subsystem
        # version is set to 6.3 or higher.
        [test $msvc = yes],
          [subsystem_major=10]
          [subsystem_minor=0],
dnl     else
          [subsystem_major=6]
          [subsystem_minor=2]
      )]
      [winpthreads_winnt=WINPTHREADS_WINNT_WIN10],
    [win8.1],
      [AS_CASE(
        [$winpthreads_host],
          [x86 | x64 | arm32],
            # FIXME: mingw-w64 tools produce broken binaries when subsystem
            # version is set to 6.3 or higher.
            [AS_IF(
              [test $msvc = yes],
                [subsystem_major=6]
                [subsystem_minor=3],
dnl           else
                [subsystem_major=6]
                [subsystem_minor=2]
            )]
            [winpthreads_winnt=WINPTHREADS_WINNT_WIN8_1],
dnl     default
            [AC_MSG_ERROR([Windows 8.1 does not support running '$host_cpu' binaries])]
      )],
    [win8],
      [AS_CASE(
        [$winpthreads_host],
          [x86 | x64 | arm32],
            [subsystem_major=6]
            [subsystem_minor=2]
            [winpthreads_winnt=WINPTHREADS_WINNT_WIN8],
dnl     default
            [AC_MSG_ERROR([Windows 8 does not support running '$host_cpu' binaries])]
      )],
    [win7],
      [AS_CASE(
        [$winpthreads_host],
          [x86 | x64],
            [subsystem_major=6]
            [subsystem_minor=1]
            [winpthreads_winnt=WINPTHREADS_WINNT_WIN7],
dnl     default
            [AC_MSG_ERROR([Windows 7 does not support running '$host_cpu' binaries])]
      )],
    [winvista],
      [AS_CASE(
        [$winpthreads_host],
          [x86 | x64],
            [subsystem_major=6]
            [subsystem_minor=0]
            [winpthreads_winnt=WINPTHREADS_WINNT_VISTA],
dnl     default
            [AC_MSG_ERROR([Windows Vista does not support running '$host_cpu' binaries])]
      )],
    [winxp],
      [AS_CASE(
        [$winpthreads_host],
          [x86],
            [subsystem_major=5]
            [subsystem_minor=1]
            [winpthreads_winnt=WINPTHREADS_WINNT_XP],
          [x64],
            [subsystem_major=5]
            [subsystem_minor=2]
            [winpthreads_winnt=WINPTHREADS_WINNT_2003],
dnl       default
            [AC_MSG_ERROR([Windows XP does not support running '$host_cpu' binaries])]
      )],
    [win2000],
      [AS_IF(
        [test $winpthreads_host = x86],
          [subsystem_major=5]
          [subsystem_minor=0]
          [winpthreads_winnt=WINPTHREADS_WINNT_2000],
dnl     else
          [AC_MSG_ERROR([Windows 2000 does not support running '$host_cpu' binaries])]
      )],
    [nt4.0],
      [AS_IF(
        [test $winpthreads_host = x86],
          [subsystem_major=4]
          [subsystem_minor=0]
          [winpthreads_winnt=WINPTHREADS_WINNT_NT_4],
dnl     else
          [AC_MSG_ERROR([Windows NT 4.0 does not support running '$host_cpu' binaries])]
      )],
    [nt3.51],
      [AS_IF(
        [test $winpthreads_host = x86],
          [subsystem_major=3]
          [subsystem_minor=51]
          [winpthreads_winnt=WINPTHREADS_WINNT_NT_3_51],
dnl     else
          [AC_MSG_ERROR([Windows NT 3.51 does not support running '$host_cpu' binaries])]
      )],
    [nt3.5],
      [AS_IF(
        [test $winpthreads_host = x86],
          [subsystem_major=3]
          [subsystem_minor=50]
          [winpthreads_winnt=WINPTHREADS_WINNT_NT_3_5],
dnl     else
          [AC_MSG_ERROR([Windows NT 3.5 does not support running '$host_cpu' binaries])]
      )],
    [nt3.1],
      [AS_IF(
        [test $winpthreads_host = x86],
          [subsystem_major=3]
          [subsystem_minor=10]
          [winpthreads_winnt=WINPTHREADS_WINNT_NT_3_1],
dnl     else
          [AC_MSG_ERROR([Windows NT 3.1 does not support running '$host_cpu' binaries])]
      )]
)

AC_DEFINE_UNQUOTED(
  [WINPTHREADS_WINNT], [$winpthreads_winnt],
  [Minimal Windows NT version to be supported by the library]
)

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

# Figure out how to tell linker to set subsystem version
winpthreads_subsystem=

AS_IF(
  [test $msvc = yes],
    # The MSVC option has syntax
    #
    #   "/SUBSYSTEM:CONSOLE,major.minor"
    #
    # and must be passed as a single argument. We cannot pass it as
    #
    #   "-Wl,-SUBSYSTEM:CONSOLE,major.minor"
    #
    # because it will separate "major,minor" part, resulting in an error.
    # A solution is to use -Xlinker option for the check.
    #
    # The /WX switch makes the linker treat warnings as errors; passing invalid
    # subsystem version to /SUBSYSTEM switch results in a warning and linker
    # simply uses the default subsystem version, which is not what we want.
    [winpthreads_subsystem="-Xlinker -WX -Xlinker -SUBSYSTEM:CONSOLE,$subsystem_major.$subsystem_minor"],
dnl else
    [winpthreads_subsystem="-Wl,--subsystem,console:$subsystem_major.$subsystem_minor"]
)

AS_IF(
  [test $ac_no_link = no],
    [save_LDFLAGS=$LDFLAGS]
    [LDFLAGS="$LDFLAGS $winpthreads_subsystem"]
    [AC_LINK_IFELSE(
      [AC_LANG_SOURCE(
        [int main (void) {return 0;}]
      )],
dnl then
      [LDFLAGS=$save_LDFLAGS],
dnl else
      [AC_MSG_ERROR([Linker cannot create binaries for '$with_winnt'])]
    )]
)

# We cannot use "-Xlinker -SUBSYSTEM:CONSOLE,major.minor" when libtool is
# involved because it converts it to -Wl switch. Use a hack to make it pass
# "-Xlinker" and "-SUBSYSTEM:CONSOLE,major.minor" as two separate options to
# the `compile` wrapper, which will then pass the option to the linker.
AS_IF(
  [test $msvc = yes],
    [winpthreads_subsystem="-Xcompiler -Xlinker -Xcompiler -SUBSYSTEM:CONSOLE,$subsystem_major.$subsystem_minor"]
)

LINKER_SUBSYSTEM="$LINKER_SUBSYSTEM $winpthreads_subsystem"

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
