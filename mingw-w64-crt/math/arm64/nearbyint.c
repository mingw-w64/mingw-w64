/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>
#include <internal.h>

__ASM_DEFINE_FUNC(double, nearbyint, (double x),
                  "mrs x1, fpcr\n\t"
                  "frintx d0, d0\n\t"
                  "msr fpcr, x1\n\t"
                  "ret")
