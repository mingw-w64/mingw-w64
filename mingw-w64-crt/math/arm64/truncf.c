/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <math.h>
#include <internal.h>

__ASM_DEFINE_FUNC(float, truncf, (float x),
                  "frintz s0, s0\n\t"
                  "ret")
