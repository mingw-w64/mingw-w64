/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <intrin.h>

void __outbytestring(unsigned short Port,unsigned char *Buffer,unsigned long Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; outsb " 
        : "=S" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}

