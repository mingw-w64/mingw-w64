/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <intrin.h>

void __writemsr (unsigned long msr, unsigned __int64 Value)
{
    unsigned long val1 = Value, val2 = Value >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
}

