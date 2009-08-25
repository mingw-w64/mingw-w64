/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#define __CRT__NO_INLINE
#include <_mingw.h>

void __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long Count);

void __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; outsl " 
        : "=S" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}

