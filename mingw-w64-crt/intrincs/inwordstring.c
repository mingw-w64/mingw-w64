/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <_mingw.h>

void __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; insw " 
        : "=D" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}

