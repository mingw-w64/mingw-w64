/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __pi_type(x) \
__builtin_choose_expr ( \
  __builtin_types_compatible_p (__typeof__ (x), float), \
  3.14159265F, \
  __builtin_choose_expr ( \
    __builtin_types_compatible_p (__typeof__ (x), double), \
    3.14159265358979323846, \
    __builtin_choose_expr ( \
      __builtin_types_compatible_p (__typeof__ (x), long double), \
      3.1415926535897932384626433832795029L, \
      __builtin_trap())))
