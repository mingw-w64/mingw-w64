/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>
#include <stdint.h>

typedef union ieee754_double_ {
  struct __attribute__((__packed__)) {
    uint64_t f52 : 52;
    uint64_t exp : 11;
    uint64_t sgn :  1;
  };
  double f;
} ieee754_double;

double log2(double x)
{
    ieee754_double u = { .f = x };
    if (u.sgn == 0 && u.f52 == 0 && u.exp > 0 && u.exp < 0x7ff) {
        // Handle exact powers of two exactly
        return (int)u.exp - 1023;
    }
    return log(x) / 0.69314718246459960938;
}
