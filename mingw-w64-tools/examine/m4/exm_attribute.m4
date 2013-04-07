dnl Copyright (C) 2012 Vincent Torri <vtorri at gmail dot com>
dnl That code is public domain and can be freely used or copied.

dnl Macros for checking if the compiler supports some __attribute__ uses

dnl Usage: EXM_ATTRIBUTE_UNUSED
dnl call AC_DEFINE for EXM_UNUSED if __attribute__((unused)) is available

AC_DEFUN([EXM_ATTRIBUTE_UNUSED],
[
AC_MSG_CHECKING([for __attribute__ ((unused))])
AC_COMPILE_IFELSE(
   [AC_LANG_PROGRAM(
       [[
void foo(int x __attribute__ ((unused))) {}
       ]],
       [[
       ]])],
   [have_attribute_unused="yes"],
   [have_attribute_unused="no"])
AC_MSG_RESULT([${have_attribute_unused}])

if test "x${have_attribute_unused}" = "xyes" ; then
   AC_DEFINE([EXM_UNUSED], [__attribute__ ((unused))], [Macro declaring a function argument to be unused.])
else
   AC_DEFINE([EXM_UNUSED], [], [__attribute__ ((unused)) is not supported.])
fi
])

dnl End of exm_attribute.m4
