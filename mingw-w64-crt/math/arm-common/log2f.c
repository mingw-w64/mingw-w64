/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>
#include <stdint.h>

typedef union ieee754_float_ {
  struct __attribute__((__packed__)) {
    uint32_t f23 : 23;
    uint32_t exp :  8;
    uint32_t sgn :  1;
  };
  float f;
} ieee754_float;

float log2f(float x)
{
    ieee754_float u = { .f = x };
    if (u.sgn == 0 && u.f23 == 0 && u.exp > 0 && u.exp < 0xff) {
        // Handle exact powers of two exactly
        return (int)u.exp - 127;
    }
    return logf(x) / 0.69314718246459960938f;
}
