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
AC_PROG_RANLIB
AM_PROG_AS
AM_PROG_AR

# Libtool 2.4 should check them correctly
# AC_CHECK_TOOLS([AR],[ar],[:])

# Libtool
LT_INIT([win32-dll])
LT_LANG([Windows Resource])

AC_SUBST([LT_OBJDIR],$lt_cv_objdir)

AS_VAR_IF([enable_shared], [yes], [AS_VAR_SET([copy_shared])])
AS_VAR_IF([enable_static], [yes], [AS_VAR_SET([copy_static])])
AM_CONDITIONAL( [COPY_SHARED], [AS_VAR_TEST_SET([copy_shared])] )
AM_CONDITIONAL( [COPY_STATIC], [AS_VAR_TEST_SET([copy_static])] )

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lpthread':
#AC_CHECK_LIB([pthread], [main])

# Checks for header files.
AC_CHECK_HEADERS([limits.h sys/timeb.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
#AC_FUNC_MALLOC
#AC_FUNC_REALLOC
# mingw-w64 should already have them
#AC_CHECK_FUNCS([ftime gettimeofday memset])

AC_SUBST([RCFLAGS])

AC_CONFIG_FILES([Makefile tests/Makefile])
AC_OUTPUT
