/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <intrin.h>

unsigned char __inbyte(unsigned short Port)
{
    unsigned char value;
    __asm__ __volatile__ ("inb %w1,%b0"
        : "=a" (value)
        : "Nd" (Port));
    return value;
}

