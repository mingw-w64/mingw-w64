/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <intrin.h>

unsigned long __indword(unsigned short Port)
{
    unsigned long value;
    __asm__ __volatile__ ("inl %w1,%0"
        : "=a" (value)
        : "Nd" (Port));
    return value;
}

