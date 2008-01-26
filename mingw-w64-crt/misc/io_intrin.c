/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <_mingw.h>
/* Intrin I/O functions.  */

unsigned char __inbyte(unsigned short Port)
{
    unsigned char value;
    __asm__ __volatile__ ("inb %w1,%b0"
        : "=a" (value)
        : "Nd" (Port));
    return value;
}

unsigned short __inword(unsigned short Port)
{
    unsigned short value;
    __asm__ __volatile__ ("inw %w1,%w0"
        : "=a" (value)
        : "Nd" (Port));
    return value;
}

unsigned long __indword(unsigned short Port)
{
    unsigned long value;
    __asm__ __volatile__ ("inl %w1,%0"
        : "=a" (value)
        : "Nd" (Port));
    return value;
}

void __outbyte(unsigned short Port,unsigned char Data)
{
    __asm__ __volatile__ ("outb %b0,%w1"
        :
    : "a" (Data), "Nd" (Port));
}

void __outword(unsigned short Port,unsigned short Data)
{
    __asm__ __volatile__ ("outw %w0,%w1"
        :
    : "a" (Data), "Nd" (Port));
}

void __outdword(unsigned short Port,unsigned long Data)
{
    __asm__ __volatile__ ("outl %0,%w1"
        :
    : "a" (Data), "Nd" (Port));
}

void __inbytestring(unsigned short Port,unsigned char *Buffer,unsigned long Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; insb " 
        : "=D" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}

void __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; insw " 
        : "=D" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}

void __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; insl " 
        : "=D" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}

void __outbytestring(unsigned short Port,unsigned char *Buffer,unsigned long Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; outsb " 
        : "=S" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}

void __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; outsw " 
        : "=S" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}

void __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long Count)
{
    __asm__ __volatile__ (
        "cld ; rep ; outsl " 
        : "=S" (Buffer), "=c" (Count)
        : "d"(Port), "0"(Buffer), "1" (Count)
        );
}
