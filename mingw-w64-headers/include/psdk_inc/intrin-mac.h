/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

// The macros in this file are included in multiple places

#ifndef _INTRIN-MAC_
#define _INTRIN-MAC_

// This macro is used by __stosb, __stosw, __stosd, __stosq
#define __buildstos(x, y) void x(y *Dest, y Data, size_t Count) \
{ \
   __asm__ __volatile__ ("rep stos%z[Data]" \
      :  /* no outputs */ \
      : "D" (Dest), "c" (Count), [Data] "a" (Data) \
      : "memory"); \
}

#endif /* _INTRIN-MAC_ */
