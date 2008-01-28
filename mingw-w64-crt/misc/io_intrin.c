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

  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     seperatly.  */
 
  #ifdef _WIN64
  void __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  unsigned __int64 __readcr2(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      return value;
  }

 void __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  unsigned __int64 __readcr3(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      return value;
  }

 void __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  unsigned __int64 __readcr4(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      return value;
  }

 void __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  unsigned __int64 __readcr8(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
      return value;
  }

 void __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  #elif defined(_WIN32)

  void __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  unsigned long __readcr2(void)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      return value;
  }

 void __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  unsigned long __readcr3(void)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      return value;
  }

 void __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  unsigned long __readcr4(void)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      return value;
  }

 void __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 unsigned long __readcr8(void)
 {
   unsigned long value;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
     return value;
 }

 void __writecr8(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  #endif

  unsigned __int64 __readmsr(int msr)
  {
      unsigned __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      return val1 | (val2 << 32);
  }

 void __writemsr (unsigned long msr, unsigned __int64 Value)
 {
    unsigned long val1 = Value, val2 = Value >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  unsigned __int64 __rdtsc(void)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      return val1 | (val2 << 32);
  }

  void __cpuid(int CPUInfo[4], int InfoType)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }
