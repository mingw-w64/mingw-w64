#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.65])
AC_INIT([mingw-w64-winstorecompat], [1.0], [mingw-w64-public@lists.sf.net])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([src/CreateEventW.c])

AM_INIT_AUTOMAKE([foreign subdir-objects])
AM_MAINTAINER_MODE

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB
AC_CHECK_TOOLS([AR], [ar], [:])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
