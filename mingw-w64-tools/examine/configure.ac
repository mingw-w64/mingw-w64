
### Version

m4_define([v_maj], [0])
m4_define([v_min], [0])
m4_define([v_mic], [1])

m4_define([examine_version], [v_maj.v_min.v_mic])

m4_define([lt_cur], m4_eval(v_maj + v_min))
m4_define([lt_rev], v_mic)
m4_define([lt_age], v_min)

AC_INIT([examine], [examine_version], [enlightenment-devel@lists.sourceforge.net])
AC_PREREQ([2.52])
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_HEADERS([config.h])
AH_TOP([
#ifndef EXAMINE_CONFIG_H__
#define EXAMINE_CONFIG_H__
])
AH_BOTTOM([
#endif /* EXAMINE_CONFIG_H__ */
])


### If the host is not Windows, or is ceGCC, we exit

AC_CANONICAL_HOST

case "$host_os" in
  cegcc* | mingw32ce*)
    AC_MSG_ERROR([Windows CE is not supported. Exiting...])
    ;;
  mingw*)
    ;;
  *)
    AC_MSG_ERROR([OS must be Windows >= XP. Exiting...])
    ;;
esac

AM_INIT_AUTOMAKE([1.6 dist-bzip2])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

lt_cv_deplibs_check_method='pass_all'
LT_PREREQ([2.4])
LT_INIT([win32-dll])

VMAJ=v_maj
AC_SUBST([VMAJ])

version_info="lt_cur:lt_rev:lt_age"
AC_SUBST([version_info])


### configure options

AC_ARG_WITH([libbfd-prefix],
   [AC_HELP_STRING([--with-libbfd-prefix=DIR], [prefix of libbfd @<:@default=/usr/local@:>@])],
   [_exm_libbfd_prefix="${with_libbfd_prefix}"],
   [_exm_libbfd_prefix="/usr/local"])


### Needed information


### Checks for programs
AC_PROG_CC_C99
AM_PROG_CC_C_O

### Checks for libraries


### Checks for header files


### Checks for types


### Checks for structures


### Checks for compiler characteristics
EXM_ATTRIBUTE_UNUSED

EXM_CFLAGS="-std=c99 -pedantic -Wall -Wextra -Wshadow -Wdeclaration-after-statement -Wmissing-prototypes -Wstrict-prototypes -Wredundant-decls -Wno-pedantic-ms-format"

AC_SUBST([EXM_CFLAGS])


### Checks for linker characteristics


### Checks for library functions

# bfd_init
AC_MSG_CHECKING([for bfd_init in libbfd])
CPPFLAGS_save="${CPPFLAGS}"
CPPFLAGS="${CPPFLAGS} -I${_exm_libbfd_prefix}/include"
LIBS_save="${LIBS}"
LIBS="${LIBS} -L${_exm_libbfd_prefix}/lib/ -lbfd -liberty -lintl"
AC_LINK_IFELSE(
   [AC_LANG_PROGRAM(
       [[
#include <bfd.h>
       ]],
       [[
bfd_init();
       ]])],
   [
    EXM_CPPFLAGS="-I${_exm_libbfd_prefix}/include"
    EXM_LIBS="-L${_exm_libbfd_prefix}/lib/ -lbfd -liberty -lintl"
    _efl_have_bfd_init="yes"
   ],
   [_efl_have_bfd_init="no"])

AC_MSG_RESULT([${_efl_have_bfd_init}])

if test "x${_efl_have_bfd_init}" = "xno" ; then
   AC_MSG_ERROR([libbfd, libiberty and libintl are required from binutils. Use --with-libbfd-prefix to set their prefix.])
fi

AC_SUBST([EXM_CPPFLAGS])
AC_SUBST([EXM_LIBS])


AC_CONFIG_FILES([
Makefile
src/Makefile
src/bin/Makefile
src/lib/Makefile
])

AC_OUTPUT


#####################################################################
## Info

echo
echo
echo
echo "------------------------------------------------------------------------"
echo "$PACKAGE_NAME $PACKAGE_VERSION"
echo "------------------------------------------------------------------------"
echo
echo "Configuration Options Summary:"
echo
echo "  OS...................: ${host_os}"
echo
echo "Compilation............: make"
echo "  CPPFLAGS.............: $CPPFLAGS"
echo "  CFLAGS...............: $CFLAGS"
echo "  LDFLAGS..............: $LDFLAGS"
echo
echo "Installation...........: make install"
echo "  prefix...............: $prefix"
echo
