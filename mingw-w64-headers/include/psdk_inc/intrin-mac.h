/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* The macros in this file are included in multiple places */

#ifndef _INTRIN_MAC_
#define _INTRIN_MAC_

/* This macro is used by __stosb, __stosw, __stosd, __stosq */

/* Parameters: (FunctionName, DataType, Operator)
   FunctionName: Any valid function name
   DataType: BYTE, WORD, DWORD or DWORD64 */

/* While we don't need the output values for Dest or Count, we
   must still inform the compiler the asm changes them. */
#define __buildstos(x, y) void x(y *Dest, y Data, size_t Count) \
{ \
   __asm__ __volatile__ ("rep stos%z[Data]" \
      : "+D" (Dest), "+c" (Count) \
      : [Data] "a" (Data) \
      : "memory"); \
}

/* This macro is used by InterlockedAnd, InterlockedOr, InterlockedXor, InterlockedAnd64, InterlockedOr64, InterlockedXor64 */

/* Parameters: (FunctionName, DataType, Operator)
   FunctionName: Any valid function name
   DataType: __LONG32 or LONG64
   Operator: One of xor, or, and */
#define __buildlogicali(x, y, o) y x(volatile y *Destination, y Value) \
{ \
    return __sync_fetch_and_ ## o(Destination, Value); \
}

/* This macro is used by InterlockedBitTestAndSet, InterlockedBitTestAndReset, InterlockedBitTestAndComplement,
   InterlockedBitTestAndSet64, InterlockedBitTestAndReset64, InterlockedBitTestAndComplement64
   _interlockedbittestandset, _interlockedbittestandreset, _interlockedbittestandcomplement
   _interlockedbittestandset64, _interlockedbittestandreset64, _interlockedbittestandcomplement64 */

/* Parameters: (FunctionName, DataType, AsmCode, OffsetConstraint, Volatile)
   FunctionName: Any valid function name
   DataType: __LONG32 or LONG64
   OffsetConstraint: either "I" for 32bit data types or "J" for 64.
   Volatile: either volatile or blank. */
#define __buildbittesti(x, y, z, a, b) unsigned char x(b y *Base, y Offset) \
{ \
   unsigned char old; \
   __asm__ __volatile__ (z "%z[Base] {%[Offset],%[Base] | %[Base],%[Offset]} ; setc %[old]" \
      : [old] "=qm" (old), [Base] "+m" (*Base) \
      : [Offset] a "r" (Offset) \
      : "memory", "cc"); \
   return old; \
}

/* This macro is used by YieldProcessor when compiling x86 w/o SSE2.
It generates the same opcodes as _mm_pause.  */
#define __buildpause() __asm__ __volatile__("rep nop")

/* This macro is used by DbgRaiseAssertionFailure and __int2c

Parameters: (IntNum)
IntNum: Interrupt number in hex */
#define __buildint(a) __asm__ __volatile__("int {$}" #a :)

/* This macro is used by MemoryBarrier when compiling x86 w/o SSE2. 
Note that on i386, xchg performs an implicit lock. */
#define __buildmemorybarrier() \
{ \
unsigned char Barrier; \
__asm__ __volatile__("xchg{b %%| }al, %0" :"=m" (Barrier) : /* no inputs */ : "eax", "memory"); \
}

#endif /* _INTRIN_MAC_ */
