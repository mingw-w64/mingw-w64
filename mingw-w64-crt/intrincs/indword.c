/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <intrin.h>

unsigned __LONG32 __indword(unsigned short Port)
{
    unsigned __LONG32 value;
    __asm__ __volatile__ ("inl %w1,%0"
        : "=a" (value)
        : "Nd" (Port));
    return value;
}

