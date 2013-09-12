/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* There are 3 separate ways this file is intended to be used:

   1) Included from intrin.h.  In this case, all intrinsics in this file get declarations and
      implementations.  No special #defines are needed for this case.

   2) Included from the library versions of these functions (ie mingw-w64-crt\intrincs\*.c).  All
      intrinsics in this file must also be included in the library.  In this case, only the 
      specific functions requested will get defined, and they will not be defined as inline.  If
      you have followed the instructions (below) for adding functions to this file, then all you 
      need to have in the .c file is the following:

      #define __INTRINSIC_ONLYSPECIAL
      #define __INTRINSIC_SPECIAL___stosb // Causes code generation in intrin-impl.h

      #include <intrin.h>

   3) Included from various platform sdk headers.  Some platform sdk headers (such as winnt.h)
      define a subset of intrinsics.  To avoid potential conflicts, this file is designed to
      allow for specific subsets of functions to be defined.  This is done by defining the 
      appropriate variable before including this file:

      #define __INTRINSIC_GROUP_WINNT
      #include <psdk_inc/intrin-impl.h>

   In all cases, it is acceptable to include this file multiple times in any order (ie include 
   winnt.h to get its subset, then include intrin.h to get everything, or vice versa).

   See also the comments at the top of intrin.h.
*/

/* To add an implementation for a new intrinsic to this file, you should comment out the current prototype in intrin.h.
   If the function you are adding is not in intrin.h, you should not be adding it to this file.  This file is only
   for MSVC intrinsics.

   Make sure you put your definition in the right section (x86 vs x64), and use this outline when adding definitions 
   to this file:

#if __INTRINSIC_PROLOG(__int2c)

<prototype goes here>

__INTRINSICS_USEINLINE 
<code goes here>

#define __INTRINSIC_DEFINED___int2c
#endif
*/

/* Note that there is no file-wide #if to prevent intrin-impl.h from being
   included multiple times.  This is because this file might be included multiple
   times to define various subsets of the functions it contains. */

/* However we do check for __MINGW_INTRIN_INLINE.  In theory this means we
   can work with other compilers.  */

#ifdef __MINGW_INTRIN_INLINE

/* These macros are used by the routines below.  While this file may be included 
   multiple times, these macros only need to be defined once. */
#ifndef _INTRIN_MAC_
#define _INTRIN_MAC_

/* This macro is used by __stosb, __stosw, __stosd, __stosq */

/* Parameters: (FunctionName, DataType, Operator)
   FunctionName: Any valid function name
   DataType: BYTE, WORD, DWORD or DWORD64
   InstructionSizeIntel: b, w, d, q (not b,w,l,q) */

/* While we don't need the output values for Dest or Count, we
   must still inform the compiler the asm changes them. */
#define __buildstos(x, y, z) void x(y *Dest, y Data, size_t Count) \
{ \
   __asm__ __volatile__ ("rep stos{%z[Data]|" z "}" \
      : "+D" (Dest), "+c" (Count) \
      : [Data] "a" (Data) \
      : "memory"); \
}

/* This macro is used by InterlockedAnd, InterlockedOr, InterlockedXor, InterlockedAnd64, InterlockedOr64, InterlockedXor64 */

/* Parameters: (FunctionName, DataType, Operator)
   FunctionName: Any valid function name
   DataType: __LONG32 or __int64
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
   DataType: __LONG32 or __int64
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

/* This macro is used by __readfsbyte, __readfsword, __readfsdword
                         __readgsbyte, __readgsword, __readgsdword, __readgsqword

Parameters: (FunctionName, DataType, Segment)
   FunctionName: Any valid function name
   DataType: char, short, __LONG32 or __int64
   Segment: fs or gs */

#define __buildreadseg(x, y, z) y x(unsigned __LONG32 Offset) { \
    y ret; \
    __asm__ ("mov{%z[ret] %%" z ":%[offset], %[ret] | %[ret], %%" z ":%[offset]}" \
        : [ret] "=r" (ret) \
        : [offset] "m" ((*(y *) (size_t) Offset))); \
    return ret; \
}

/* This macro is used by __writefsbyte, __writefsword, __writefsdword
                         __writegsbyte, __writegsword, __writegsdword, __writegsqword

Parameters: (FunctionName, DataType, Segment)
   FunctionName: Any valid function name
   DataType: char, short, __LONG32 or __int64
   Segment: fs or gs */

#define __buildwriteseg(x, y, z) void x(unsigned __LONG32 Offset, y Data) { \
    __asm__ ("mov{%z[offset] %[Data], %%" z ":%[offset] | %%" z ":%[offset], %[Data]}" \
        : [offset] "=m" ((*(y *) (size_t) Offset)) \
        : [Data] "ri" (Data)); \
}

/* This macro is used by _BitScanForward, _BitScanForward64, _BitScanReverse _BitScanReverse64

Parameters: (FunctionName, DataType, Segment)
   FunctionName: Any valid function name
   DataType: unsigned __LONG32 or unsigned __int64
   Statement: BSF or BSR */

#define __buildbitscan(x, y, z) unsigned char x(unsigned __LONG32 *Index, y Mask) \
{ \
   y n; \
   __asm__ (z "{%z[Mask] %[Mask],%[Index] | %[Index],%[Mask]}" \
      : [Index] "=r" (n) \
      : [Mask] "r" (Mask) \
      : "cc"); \
   *Index = n; \
   return Mask!=0; \
}

/* This macro is used by _bittest & _bittest64

Parameters: (FunctionName, DataType, OffsetConstraint)
   FunctionName: Any valid function name
   DataType: __LONG32 or __int64
   OffsetConstraint: either "I" for 32bit data types or "J" for 64.

   */
#define __buildbittest(x, y, a) unsigned char x(const y *Base, y Offset) \
{ \
   unsigned char old; \
   __asm__ ("bt{%z[Base] %[Offset],%[Base] | %[Base],%[Offset]} ; setc %[old]" \
      : [old] "=rm" (old) \
      : [Offset] a "r" (Offset), [Base] "rm" (*Base) \
      : "cc"); \
   return old; \
}

/* This macro is used by _bittestandset, _bittestandreset, _bittestandcomplement,
   _bittestandset64, _bittestandreset64, _bittestandcomplement64

Parameters: (FunctionName, DataType, Statement, OffsetConstraint)
   FunctionName: Any valid function name
   DataType: __LONG32 or __int64
   Statement: asm statement (bts, btr, btc)
   OffsetConstraint: either "I" for 32bit data types or "J" for 64.

   */
#define __buildbittestand(x, y, z, a) unsigned char x(y *Base, y Offset) \
{ \
   unsigned char old; \
   __asm__ (z "%z[Base] {%[Offset],%[Base] | %[Base],%[Offset]} ; setc %[old]" \
      : [old] "=r" (old), [Base] "+rm" (*Base) \
      : [Offset] a "r" (Offset) \
      : "cc"); \
   return old; \
}

/* This macro is used by __inbyte, __inword, __indword

Parameters: (FunctionName, DataType)
   FunctionName: Any valid function name
   DataType: unsigned char, unsigned short, unsigned __LONG32

   */
#define __build_inport(x, y) y x(unsigned short Port) { \
   y value; \
      __asm__ __volatile__ ("in{%z0 %w1,%0| %0,%w1}" \
          : "=a" (value) \
          : "Nd" (Port)); \
      return value; \
   }

/* This macro is used by __outbyte, __outword, __outdword

Parameters: (FunctionName, DataType)
   FunctionName: Any valid function name
   DataType: unsigned char, unsigned short, unsigned __LONG32

   */
#define __build_outport(x, y) void x(unsigned short Port, y Data) { \
      __asm__ __volatile__ ("out{%z0 %0,%w1| %w1,%0}" \
          : \
          : "a" (Data), "Nd" (Port)); \
   }

/* This macro is used by __inbytestring, __inwordstring, __indwordstring

Parameters: (FunctionName, DataType, InstructionSizeAtt, InstructionSizeIntel)
   FunctionName: Any valid function name
   DataType: unsigned char, unsigned short, unsigned __LONG32
   InstructionSizeAtt: b, w, l
   InstructionSizeIntel: b, w, d (not b,w,l)

   */
#define __build_inportstring(x, y, z, a) void x(unsigned short Port, y *Buffer, unsigned __LONG32 Count) { \
   __asm__ __volatile__ ("cld ; rep ins{" z "|" a "}" \
      : "=D" (Buffer), "=c" (Count) \
      : "d"(Port), "0"(Buffer), "1" (Count)); \
   }

/* This macro is used by __outbytestring, __outwordstring, __outdwordstring

Parameters: (FunctionName, DataType, InstructionSizeAtt, InstructionSizeIntel)
   FunctionName: Any valid function name
   DataType: unsigned char, unsigned short, unsigned __LONG32
   InstructionSizeAtt: b, w, l
   InstructionSizeIntel: b, w, d (not b,w,l)

   */
#define __build_outportstring(x, y, z, a) void x(unsigned short Port, y *Buffer, unsigned __LONG32 Count) { \
   __asm__ __volatile__ ("cld ; rep outs{" z "|" a "}" \
      : "=S" (Buffer), "=c" (Count) \
      : "d"(Port), "0"(Buffer), "1" (Count)); \
  }

/* This macro is used by __readcr0, __readcr2, __readcr3, __readcr4, __readcr8

Parameters: (FunctionName, DataType, RegisterNumber)
   FunctionName: Any valid function name
   DataType: unsigned __LONG32, unsigned __int64
   RegisterNumber: 0, 2, 3, 4, 8

   */
#define __build_readcr(x, y, z) y x(void) { \
      y value; \
      __asm__ __volatile__ ("mov {%%cr" z ", %[value] | %[value], %%cr" z "}" \
          : [value] "=q" (value)); \
      return value; \
  }

/* This macro is used by __writecr0, __writecr2, __writecr3, __writecr4, __writecr8

Parameters: (FunctionName, DataType, RegisterNumber)
   FunctionName: Any valid function name
   DataType: unsigned __LONG32, unsigned __int64
   RegisterNumber: 0, 2, 3, 4, 8

   */
#define __build_writecr(x, y, z) void x(y Data) { \
   __asm__ __volatile__ ("mov {%[Data], %%cr" z "|%%cr" z ", %[Data]}" \
       : \
       : [Data] "q" (Data) \
       : "memory"); \
   }

/* This macro is used by __movsb, __movsd, __movsq, __movsw

Parameters: (FunctionName, DataType, RegisterNumber)
   FunctionName: Any valid function name
   DataType: unsigned char, unsigned short, unsigned __LONG32, unsigned __int64
   InstructionSize: b, w, d, q

   */
#define __buildmov(x, y, z) void x(y *Destination, y const *Source, size_t Count) \
{ \
  __asm__ __volatile__ ( \
    "rep movs" z \
       : "=D" (Destination), "=S" (Source), "=c" (Count) \
       : "0" (Destination), "1" (Source), "2" (Count) \
       : "memory"); \
}

#endif /* _INTRIN_MAC_ */

/* The Barrier functions can never be in the library.  Since gcc only
supports ReadWriteBarrier, map all 3 to do the same. */
#ifndef _ReadWriteBarrier

#define _ReadWriteBarrier() __asm__ __volatile__ ("" ::: "memory")
#define _ReadBarrier _ReadWriteBarrier
#define _WriteBarrier _ReadWriteBarrier

#endif

/* The logic for this macro is:
   if the function is not yet defined AND
   (
       (if we are not just defining special OR 
           (we are defining special AND this is one of the ones we are defining)
       )
   )
*/
#define __INTRINSIC_PROLOG(name) (!defined(__INTRINSIC_DEFINED_ ## name)) && ((!defined (__INTRINSIC_ONLYSPECIAL)) || (defined (__INTRINSIC_ONLYSPECIAL) && defined(__INTRINSIC_SPECIAL_ ## name)))

#ifdef __INTRINSIC_ONLYSPECIAL
#define __INTRINSICS_USEINLINE
#else
#define __INTRINSICS_USEINLINE __MINGW_INTRIN_INLINE
#endif

/* Normally __INTRINSIC_ONLYSPECIAL is used to indicate that we are
   being included in the library version of the intrinsic (case 2).  However,
   that really only affects the definition of __INTRINSICS_USEINLINE.
   So here we are letting it serve an additional purpose of only defining
   the intrinsics for a certain file (case 3).  For example, to create the
   intrinsics for the functions in winnt.h, define __INTRINSIC_GROUP_WINNT.

   Note that this file can be included multiple times, and as a result
   there can be overlap (definitions that appear in more than one
   file).  This is handled by __INTRINSIC_DEFINED_*

   If no groups are defined (such as what happens when including intrin.h),
   all intrinsics are defined.   */

/* If __INTRINSIC_ONLYSPECIAL is defined at this point, we are processing case 2.  In 
   that case, don't go looking for groups */
#ifndef __INTRINSIC_ONLYSPECIAL

#ifdef __INTRINSIC_GROUP_WINNT
#undef __INTRINSIC_GROUP_WINNT /* Remove this for efficiency if intrin-impl.h is included again */

/* Note that this gets undefined at the end of this file */
#define __INTRINSIC_ONLYSPECIAL

#define __INTRINSIC_SPECIAL___faststorefence
#define __INTRINSIC_SPECIAL___int2c
#define __INTRINSIC_SPECIAL___stosb
#define __INTRINSIC_SPECIAL___stosd
#define __INTRINSIC_SPECIAL___stosq
#define __INTRINSIC_SPECIAL___stosw
#define __INTRINSIC_SPECIAL__InterlockedAnd
#define __INTRINSIC_SPECIAL__InterlockedAnd64
#define __INTRINSIC_SPECIAL__interlockedbittestandcomplement
#define __INTRINSIC_SPECIAL__interlockedbittestandcomplement64
#define __INTRINSIC_SPECIAL__interlockedbittestandreset
#define __INTRINSIC_SPECIAL__interlockedbittestandreset64
#define __INTRINSIC_SPECIAL__interlockedbittestandset
#define __INTRINSIC_SPECIAL__interlockedbittestandset64
#define __INTRINSIC_SPECIAL__InterlockedOr
#define __INTRINSIC_SPECIAL__InterlockedOr64
#define __INTRINSIC_SPECIAL__InterlockedXor
#define __INTRINSIC_SPECIAL__InterlockedXor64
#define __INTRINSIC_SPECIAL_InterlockedBitTestAndComplement
#define __INTRINSIC_SPECIAL_InterlockedBitTestAndComplement64
#define __INTRINSIC_SPECIAL_InterlockedBitTestAndReset
#define __INTRINSIC_SPECIAL_InterlockedBitTestAndReset64
#define __INTRINSIC_SPECIAL_InterlockedBitTestAndSet
#define __INTRINSIC_SPECIAL_InterlockedBitTestAndSet64
#define __INTRINSIC_SPECIAL__InterlockedIncrement16
#define __INTRINSIC_SPECIAL__InterlockedDecrement16
#define __INTRINSIC_SPECIAL__InterlockedCompareExchange16
#define __INTRINSIC_SPECIAL__InterlockedIncrement
#define __INTRINSIC_SPECIAL__InterlockedDecrement
#define __INTRINSIC_SPECIAL__InterlockedExchange
#define __INTRINSIC_SPECIAL__InterlockedExchangeAdd
#define __INTRINSIC_SPECIAL__InterlockedCompareExchange
#define __INTRINSIC_SPECIAL__InterlockedIncrement64
#define __INTRINSIC_SPECIAL__InterlockedDecrement64
#define __INTRINSIC_SPECIAL__InterlockedExchangeAdd64
#define __INTRINSIC_SPECIAL__InterlockedExchange64
#define __INTRINSIC_SPECIAL__InterlockedCompareExchange64
#define __INTRINSIC_SPECIAL__InterlockedExchangePointer
#define __INTRINSIC_SPECIAL__InterlockedCompareExchangePointer
#define __INTRINSIC_SPECIAL___readgsbyte
#define __INTRINSIC_SPECIAL___readgsword
#define __INTRINSIC_SPECIAL___readgsdword
#define __INTRINSIC_SPECIAL___readgsqword
#define __INTRINSIC_SPECIAL___writegsbyte
#define __INTRINSIC_SPECIAL___writegsword
#define __INTRINSIC_SPECIAL___writegsdword
#define __INTRINSIC_SPECIAL___writegsqword
#define __INTRINSIC_SPECIAL___readfsbyte
#define __INTRINSIC_SPECIAL___readfsword
#define __INTRINSIC_SPECIAL___readfsdword
#define __INTRINSIC_SPECIAL___writefsbyte
#define __INTRINSIC_SPECIAL___writefsword
#define __INTRINSIC_SPECIAL___writefsdword
#define __INTRINSIC_SPECIAL__BitScanForward
#define __INTRINSIC_SPECIAL__BitScanForward64
#define __INTRINSIC_SPECIAL__BitScanReverse
#define __INTRINSIC_SPECIAL__BitScanReverse64
#define __INTRINSIC_SPECIAL__bittest
#define __INTRINSIC_SPECIAL__bittestandset
#define __INTRINSIC_SPECIAL__bittestandreset
#define __INTRINSIC_SPECIAL__bittestandcomplement
#define __INTRINSIC_SPECIAL__bittest64
#define __INTRINSIC_SPECIAL__bittestandset64
#define __INTRINSIC_SPECIAL__bittestandreset64
#define __INTRINSIC_SPECIAL__bittestandcomplement64
#define __INTRINSIC_SPECIAL___movsb
#define __INTRINSIC_SPECIAL___movsw
#define __INTRINSIC_SPECIAL___movsd
#define __INTRINSIC_SPECIAL___movsq

#endif /* __INTRINSIC_GROUP_WINNT */

#ifdef __INTRINSIC_GROUP_WINBASE
#undef __INTRINSIC_GROUP_WINBASE /* Remove this for efficiency if intrin-impl.h is included again */

/* Note that this gets undefined at the end of this file */
#define __INTRINSIC_ONLYSPECIAL

#define __INTRINSIC_SPECIAL__InterlockedIncrement
#define __INTRINSIC_SPECIAL__InterlockedDecrement
#define __INTRINSIC_SPECIAL__InterlockedExchange
#define __INTRINSIC_SPECIAL__InterlockedExchangeAdd
#define __INTRINSIC_SPECIAL__InterlockedCompareExchange
#define __INTRINSIC_SPECIAL__InterlockedCompareExchangePointer
#define __INTRINSIC_SPECIAL__InterlockedExchangePointer
#define __INTRINSIC_SPECIAL__InterlockedAnd64
#define __INTRINSIC_SPECIAL__InterlockedOr64
#define __INTRINSIC_SPECIAL__InterlockedXor64
#define __INTRINSIC_SPECIAL__InterlockedIncrement64
#define __INTRINSIC_SPECIAL__InterlockedDecrement64
#define __INTRINSIC_SPECIAL__InterlockedExchange64
#define __INTRINSIC_SPECIAL__InterlockedExchangeAdd64
#define __INTRINSIC_SPECIAL__InterlockedCompareExchange64

#endif /* __INTRINSIC_GROUP_WINBASE */

/* To add an additional group, put the #ifdef and definitions here. */

#endif /* __INTRINSIC_ONLYSPECIAL */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __x86_64__

#if __INTRINSIC_PROLOG(__faststorefence)
void __faststorefence(void);
__INTRINSICS_USEINLINE
void __faststorefence(void) {
    /* Turns out this is actually faster than MS's "trick" on newer cpus.  Note
    that this builtin performs an implicit ReadWriteBarrier. */
    __builtin_ia32_sfence();
}
#define __INTRINSIC_DEFINED___faststorefence
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__stosq)
__MINGW_EXTENSION void __stosq(unsigned __int64 *, unsigned __int64, size_t);
__INTRINSICS_USEINLINE 
__buildstos(__stosq, unsigned __int64, "q")
#define __INTRINSIC_DEFINED___stosq
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_interlockedbittestandset64)
__MINGW_EXTENSION unsigned char _interlockedbittestandset64(__int64 *a, __int64 b);
__INTRINSICS_USEINLINE 
__buildbittesti(_interlockedbittestandset64, __int64, "lock bts", "J", /* unused param */)
#define __INTRINSIC_DEFINED__interlockedbittestandset64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_interlockedbittestandreset64)
__MINGW_EXTENSION unsigned char _interlockedbittestandreset64(__int64 *a, __int64 b);
__INTRINSICS_USEINLINE 
__buildbittesti(_interlockedbittestandreset64, __int64, "lock btr", "J", /* unused param */)
#define __INTRINSIC_DEFINED__interlockedbittestandreset64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_interlockedbittestandcomplement64)
__MINGW_EXTENSION unsigned char _interlockedbittestandcomplement64(__int64 *a, __int64 b);
__INTRINSICS_USEINLINE 
__buildbittesti(_interlockedbittestandcomplement64, __int64, "lock btc", "J", /* unused param */)
#define __INTRINSIC_DEFINED__interlockedbittestandcomplement64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(InterlockedBitTestAndSet64)
__MINGW_EXTENSION unsigned char InterlockedBitTestAndSet64(volatile __int64 *a, __int64 b);
__INTRINSICS_USEINLINE 
__buildbittesti(InterlockedBitTestAndSet64, __int64, "lock bts", "J", volatile)
#define __INTRINSIC_DEFINED_InterlockedBitTestAndSet64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(InterlockedBitTestAndReset64)
__MINGW_EXTENSION unsigned char InterlockedBitTestAndReset64(volatile __int64 *a, __int64 b);
__INTRINSICS_USEINLINE 
__buildbittesti(InterlockedBitTestAndReset64, __int64, "lock btr", "J", volatile)
#define __INTRINSIC_DEFINED_InterlockedBitTestAndReset64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(InterlockedBitTestAndComplement64)
__MINGW_EXTENSION unsigned char InterlockedBitTestAndComplement64(volatile __int64 *a, __int64 b);
__INTRINSICS_USEINLINE 
__buildbittesti(InterlockedBitTestAndComplement64, __int64, "lock btc", "J", volatile)
#define __INTRINSIC_DEFINED_InterlockedBitTestAndComplement64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedAnd64)
__MINGW_EXTENSION __int64 _InterlockedAnd64(__int64 volatile *, __int64);
__INTRINSICS_USEINLINE 
__buildlogicali(_InterlockedAnd64, __int64, and)
#define __INTRINSIC_DEFINED__InterlockedAnd64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedOr64)
__MINGW_EXTENSION __int64 _InterlockedOr64(__int64 volatile *, __int64);
__INTRINSICS_USEINLINE 
__buildlogicali(_InterlockedOr64, __int64, or)
#define __INTRINSIC_DEFINED__InterlockedOr64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedXor64)
__MINGW_EXTENSION __int64 _InterlockedXor64(__int64 volatile *, __int64);
__INTRINSICS_USEINLINE 
__buildlogicali(_InterlockedXor64, __int64, xor)
#define __INTRINSIC_DEFINED__InterlockedXor64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedIncrement64)
__MINGW_EXTENSION __int64 _InterlockedIncrement64(__int64 volatile *Addend);
__MINGW_EXTENSION __INTRINSICS_USEINLINE 
__int64 _InterlockedIncrement64(__int64 volatile *Addend) {
    return __sync_add_and_fetch(Addend, 1);
}
#define __INTRINSIC_DEFINED__InterlockedIncrement64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedDecrement64)
__MINGW_EXTENSION __int64 _InterlockedDecrement64(__int64 volatile *Addend);
__MINGW_EXTENSION __INTRINSICS_USEINLINE 
__int64 _InterlockedDecrement64(__int64 volatile *Addend) {
    return __sync_sub_and_fetch(Addend, 1);
}
#define __INTRINSIC_DEFINED__InterlockedDecrement64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedExchange64)
__MINGW_EXTENSION __int64 _InterlockedExchange64(__int64 volatile *Target, __int64 Value);
__MINGW_EXTENSION __INTRINSICS_USEINLINE 
__int64 _InterlockedExchange64(__int64 volatile *Target, __int64 Value) {
    return __sync_lock_test_and_set(Target, Value);
}
#define __INTRINSIC_DEFINED__InterlockedExchange64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedExchangeAdd64)
__MINGW_EXTENSION __int64 _InterlockedExchangeAdd64(__int64 volatile *Addend, __int64 Value);
__MINGW_EXTENSION __INTRINSICS_USEINLINE 
__int64 _InterlockedExchangeAdd64(__int64 volatile *Addend, __int64 Value) {
    return __sync_fetch_and_add(Addend, Value);
}
#define __INTRINSIC_DEFINED__InterlockedExchangeAdd64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readgsbyte)
unsigned char __readgsbyte(unsigned __LONG32 Offset);
__INTRINSICS_USEINLINE
__buildreadseg(__readgsbyte, unsigned char, "gs")
#define __INTRINSIC_DEFINED___readgsbyte
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readgsword)
unsigned short __readgsword(unsigned __LONG32 Offset);
__INTRINSICS_USEINLINE
__buildreadseg(__readgsword, unsigned short, "gs")
#define __INTRINSIC_DEFINED___readgsword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readgsdword)
unsigned __LONG32 __readgsdword(unsigned __LONG32 Offset);
__INTRINSICS_USEINLINE
__buildreadseg(__readgsdword, unsigned __LONG32, "gs")
#define __INTRINSIC_DEFINED___readgsdword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readgsqword)
__MINGW_EXTENSION unsigned __int64 __readgsqword(unsigned __LONG32 Offset);
__MINGW_EXTENSION __INTRINSICS_USEINLINE
__buildreadseg(__readgsqword, unsigned __int64, "gs")
#define __INTRINSIC_DEFINED___readgsqword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writegsbyte)
void __writegsbyte(unsigned __LONG32 Offset,unsigned char Data);
__INTRINSICS_USEINLINE
__buildwriteseg(__writegsbyte, unsigned char, "gs")
#define __INTRINSIC_DEFINED___writegsbyte
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writegsword)
void __writegsword(unsigned __LONG32 Offset,unsigned short Data);
__INTRINSICS_USEINLINE
__buildwriteseg(__writegsword, unsigned short, "gs")
#define __INTRINSIC_DEFINED___writegsword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writegsdword)
void __writegsdword(unsigned __LONG32 Offset,unsigned __LONG32 Data);
__INTRINSICS_USEINLINE
__buildwriteseg(__writegsdword, unsigned __LONG32, "gs")
#define __INTRINSIC_DEFINED___writegsdword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writegsqword)
__MINGW_EXTENSION void __writegsqword(unsigned __LONG32 Offset,unsigned __int64 Data);
__MINGW_EXTENSION __INTRINSICS_USEINLINE
__buildwriteseg(__writegsqword, unsigned __int64, "gs")
#define __INTRINSIC_DEFINED___writegsqword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_BitScanForward64)
__MINGW_EXTENSION unsigned char _BitScanForward64(unsigned __LONG32 *Index, unsigned __int64 Mask);
__MINGW_EXTENSION __INTRINSICS_USEINLINE
__buildbitscan(_BitScanForward64, unsigned __int64, "bsf")
#define __INTRINSIC_DEFINED__BitScanForward64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_BitScanReverse64)
__MINGW_EXTENSION unsigned char _BitScanReverse64(unsigned __LONG32 *Index, unsigned __int64 Mask);
__MINGW_EXTENSION __INTRINSICS_USEINLINE
__buildbitscan(_BitScanReverse64, unsigned __int64, "bsr")
#define __INTRINSIC_DEFINED__BitScanReverse64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_bittest64)
__MINGW_EXTENSION unsigned char _bittest64(__int64 const *a, __int64 b);
__MINGW_EXTENSION __INTRINSICS_USEINLINE
__buildbittest(_bittest64, __int64, "J")
#define __INTRINSIC_DEFINED__bittest64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_bittestandset64)
__MINGW_EXTENSION unsigned char _bittestandset64(__int64 *a, __int64 b);
__MINGW_EXTENSION __INTRINSICS_USEINLINE
__buildbittestand(_bittestandset64, __int64, "bts", "J")
#define __INTRINSIC_DEFINED__bittestandset64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_bittestandreset64)
__MINGW_EXTENSION unsigned char _bittestandreset64(__int64 *a, __int64 b);
__MINGW_EXTENSION __INTRINSICS_USEINLINE
__buildbittestand(_bittestandreset64, __int64, "btr", "J")
#define __INTRINSIC_DEFINED__bittestandreset64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_bittestandcomplement64)
__MINGW_EXTENSION unsigned char _bittestandcomplement64(__int64 *a, __int64 b);
__MINGW_EXTENSION __INTRINSICS_USEINLINE
__buildbittestand(_bittestandcomplement64, __int64, "btc", "J")
#define __INTRINSIC_DEFINED__bittestandcomplement64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr0)
__MINGW_EXTENSION unsigned __int64 __readcr0(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr0, unsigned __int64, "0")
#define __INTRINSIC_DEFINED___readcr0
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr2)
__MINGW_EXTENSION unsigned __int64 __readcr2(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr2, unsigned __int64, "2")
#define __INTRINSIC_DEFINED___readcr2
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr3)
__MINGW_EXTENSION unsigned __int64 __readcr3(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr3, unsigned __int64, "3")
#define __INTRINSIC_DEFINED___readcr3
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr4)
__MINGW_EXTENSION unsigned __int64 __readcr4(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr4, unsigned __int64, "4")
#define __INTRINSIC_DEFINED___readcr4
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr8)
__MINGW_EXTENSION unsigned __int64 __readcr8(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr8, unsigned __int64, "8")
#define __INTRINSIC_DEFINED___readcr8
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writecr0)
__MINGW_EXTENSION void __writecr0(unsigned __int64);
__INTRINSICS_USEINLINE
__build_writecr(__writecr0, unsigned __int64, "0")
#define __INTRINSIC_DEFINED___writecr0
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writecr3)
__MINGW_EXTENSION void __writecr3(unsigned __int64);
__INTRINSICS_USEINLINE
__build_writecr(__writecr3, unsigned __int64, "3")
#define __INTRINSIC_DEFINED___writecr3
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writecr4)
__MINGW_EXTENSION void __writecr4(unsigned __int64);
__INTRINSICS_USEINLINE
__build_writecr(__writecr4, unsigned __int64, "4")
#define __INTRINSIC_DEFINED___writecr4
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writecr8)
__MINGW_EXTENSION void __writecr8(unsigned __int64);
__INTRINSICS_USEINLINE
__build_writecr(__writecr8, unsigned __int64, "8")
#define __INTRINSIC_DEFINED___writecr8
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__movsq)
__MINGW_EXTENSION void __movsq(unsigned __int64 *Dest, unsigned __int64 const *Source, size_t Count);
__MINGW_EXTENSION __INTRINSICS_USEINLINE
__buildmov(__movsq, unsigned __int64, "q")
#define __INTRINSIC_DEFINED___movsq
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_umul128)
unsigned __int64 _umul128(unsigned __int64, unsigned __int64, unsigned __int64 *);
__INTRINSICS_USEINLINE
unsigned __int64 _umul128(unsigned __int64 a, unsigned __int64 b, unsigned __int64 *hi)
{
   __MINGW_EXTENSION union { unsigned __int128 v; unsigned __int64 sv[2]; } var;
   var.v = a;
   var.v *= b;
   if (hi) *hi = var.sv[1];
   return var.sv[0];
}
#define __INTRINSIC_DEFINED__umul128
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_mul128)
__int64 _mul128(__int64, __int64, __int64 *);
__INTRINSICS_USEINLINE
__int64 _mul128(__int64 a, __int64 b, __int64 *hi)
{
   __MINGW_EXTENSION union { __int128 v; __int64 sv[2]; } var;
   var.v = a;
   var.v *= b;
   if (hi) *hi = var.sv[1];
   return var.sv[0];
}
#define __INTRINSIC_DEFINED__mul128
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__shiftleft128)
unsigned __int64 __shiftleft128(unsigned __int64  LowPart, unsigned __int64 HighPart, unsigned char Shift);
__INTRINSICS_USEINLINE
unsigned __int64 __shiftleft128 (unsigned __int64  LowPart, unsigned __int64 HighPart, unsigned char Shift)
{
   unsigned __int64 ret;

   __asm__ ("shld {%[Shift],%[LowPart],%[HighPart]|%[HighPart], %[LowPart], %[Shift]}" 
      : [ret] "=r" (ret)
      : [LowPart] "r" (LowPart), [HighPart] "0" (HighPart), [Shift] "Jc" (Shift)
      : "cc");

   return ret;
}
#define __INTRINSIC_DEFINED___shiftleft128
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__shiftright128)
unsigned __int64 __shiftright128 (unsigned __int64  LowPart, unsigned __int64 HighPart, unsigned char Shift);
__INTRINSICS_USEINLINE
unsigned __int64 __shiftright128 (unsigned __int64  LowPart, unsigned __int64 HighPart, unsigned char Shift)
{
   unsigned __int64 ret;

   __asm__ ("shrd {%[Shift],%[HighPart],%[LowPart]|%[LowPart], %[HighPart], %[Shift]}" 
      : [ret] "=r" (ret)
      : [LowPart] "0" (LowPart), [HighPart] "r" (HighPart), [Shift] "Jc" (Shift)
      : "cc");

   return ret;
}
#define __INTRINSIC_DEFINED___shiftright128
#endif /* __INTRINSIC_PROLOG */

#endif /* __x86_64__ */

/* ***************************************************** */

#if defined(__x86_64__) || defined(_X86_)

#if __INTRINSIC_PROLOG(__int2c)
void __int2c(void);
__INTRINSICS_USEINLINE 
void __int2c(void) {
    __buildint(0x2c);
}
#define __INTRINSIC_DEFINED___int2c
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__stosb)
void __stosb(unsigned char *, unsigned char, size_t);
__INTRINSICS_USEINLINE 
__buildstos(__stosb, unsigned char, "b")
#define __INTRINSIC_DEFINED___stosb
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__stosw)
void __stosw(unsigned short *, unsigned short, size_t);
__INTRINSICS_USEINLINE 
__buildstos(__stosw, unsigned short, "w")
#define __INTRINSIC_DEFINED___stosw
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__stosd)
void __stosd(unsigned __LONG32 *, unsigned __LONG32, size_t);
__INTRINSICS_USEINLINE 
__buildstos(__stosd, unsigned __LONG32, "d")
#define __INTRINSIC_DEFINED___stosd
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_interlockedbittestandset)
unsigned char _interlockedbittestandset(__LONG32 *a, __LONG32 b);
__INTRINSICS_USEINLINE 
__buildbittesti(_interlockedbittestandset, __LONG32, "lock bts", "I", /* unused param */)
#define __INTRINSIC_DEFINED__interlockedbittestandset
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_interlockedbittestandreset)
unsigned char _interlockedbittestandreset(__LONG32 *a, __LONG32 b);
__INTRINSICS_USEINLINE 
__buildbittesti(_interlockedbittestandreset, __LONG32, "lock btr", "I", /* unused param */)
#define __INTRINSIC_DEFINED__interlockedbittestandreset
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_interlockedbittestandcomplement)
unsigned char _interlockedbittestandcomplement(__LONG32 *a, __LONG32 b);
__INTRINSICS_USEINLINE 
__buildbittesti(_interlockedbittestandcomplement, __LONG32, "lock btc", "I", /* unused param */)
#define __INTRINSIC_DEFINED__interlockedbittestandcomplement
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(InterlockedBitTestAndSet)
unsigned char InterlockedBitTestAndSet(volatile __LONG32 *a, __LONG32 b);
__INTRINSICS_USEINLINE 
__buildbittesti(InterlockedBitTestAndSet, __LONG32, "lock bts", "I", volatile)
#define __INTRINSIC_DEFINED_InterlockedBitTestAndSet
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(InterlockedBitTestAndReset)
unsigned char InterlockedBitTestAndReset(volatile __LONG32 *a, __LONG32 b);
__INTRINSICS_USEINLINE 
__buildbittesti(InterlockedBitTestAndReset, __LONG32, "lock btr", "I", volatile)
#define __INTRINSIC_DEFINED_InterlockedBitTestAndReset
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(InterlockedBitTestAndComplement)
unsigned char InterlockedBitTestAndComplement(volatile __LONG32 *a, __LONG32 b);
__INTRINSICS_USEINLINE 
__buildbittesti(InterlockedBitTestAndComplement, __LONG32, "lock btc", "I", volatile)
#define __INTRINSIC_DEFINED_InterlockedBitTestAndComplement
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedAnd)
__LONG32 _InterlockedAnd(__LONG32 volatile *, __LONG32);
__INTRINSICS_USEINLINE 
__buildlogicali(_InterlockedAnd, __LONG32, and)
#define __INTRINSIC_DEFINED__InterlockedAnd
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedOr)
__LONG32 _InterlockedOr(__LONG32 volatile *, __LONG32);
__INTRINSICS_USEINLINE 
__buildlogicali(_InterlockedOr, __LONG32, or)
#define __INTRINSIC_DEFINED__InterlockedOr
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedXor)
__LONG32 _InterlockedXor(__LONG32 volatile *, __LONG32);
__INTRINSICS_USEINLINE 
__buildlogicali(_InterlockedXor, __LONG32, xor)
#define __INTRINSIC_DEFINED__InterlockedXor
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedIncrement16)
short _InterlockedIncrement16(short volatile *Addend);
__INTRINSICS_USEINLINE 
short _InterlockedIncrement16(short volatile *Addend) {
    return __sync_add_and_fetch(Addend, 1);
}
#define __INTRINSIC_DEFINED__InterlockedIncrement16
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedDecrement16)
short _InterlockedDecrement16(short volatile *Addend);
__INTRINSICS_USEINLINE 
short _InterlockedDecrement16(short volatile *Addend) {
    return __sync_sub_and_fetch(Addend, 1);
}
#define __INTRINSIC_DEFINED__InterlockedDecrement16
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedCompareExchange16)
short _InterlockedCompareExchange16(short volatile *Destination, short ExChange, short Comperand);
__INTRINSICS_USEINLINE 
short _InterlockedCompareExchange16(short volatile *Destination, short ExChange, short Comperand) {
    return __sync_val_compare_and_swap(Destination, Comperand, ExChange);
}
#define __INTRINSIC_DEFINED__InterlockedCompareExchange16
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedExchangeAdd)
__LONG32 _InterlockedExchangeAdd(__LONG32 volatile *Addend, __LONG32 Value);
__INTRINSICS_USEINLINE 
__LONG32 _InterlockedExchangeAdd(__LONG32 volatile *Addend, __LONG32 Value) {
    return __sync_fetch_and_add(Addend, Value);
}
#define __INTRINSIC_DEFINED__InterlockedExchangeAdd
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedCompareExchange)
__LONG32 _InterlockedCompareExchange(__LONG32 volatile *Destination, __LONG32 ExChange, __LONG32 Comperand);
__INTRINSICS_USEINLINE 
__LONG32 _InterlockedCompareExchange(__LONG32 volatile *Destination, __LONG32 ExChange, __LONG32 Comperand) {
    return __sync_val_compare_and_swap(Destination, Comperand, ExChange);
}
#define __INTRINSIC_DEFINED__InterlockedCompareExchange
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedIncrement)
__LONG32 _InterlockedIncrement(__LONG32 volatile *Addend);
__INTRINSICS_USEINLINE 
__LONG32 _InterlockedIncrement(__LONG32 volatile *Addend) {
   return __sync_add_and_fetch(Addend, 1);
}
#define __INTRINSIC_DEFINED__InterlockedIncrement
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedDecrement)
__LONG32 _InterlockedDecrement(__LONG32 volatile *Addend);
__INTRINSICS_USEINLINE 
__LONG32 _InterlockedDecrement(__LONG32 volatile *Addend) {
   return __sync_sub_and_fetch(Addend, 1);
}
#define __INTRINSIC_DEFINED__InterlockedDecrement
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedExchange)
__LONG32 _InterlockedExchange(__LONG32 volatile *Target, __LONG32 Value);
__INTRINSICS_USEINLINE 
__LONG32 _InterlockedExchange(__LONG32 volatile *Target, __LONG32 Value) {
    return __sync_lock_test_and_set(Target, Value);
}
#define __INTRINSIC_DEFINED__InterlockedExchange
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedCompareExchange64)
__MINGW_EXTENSION __int64 _InterlockedCompareExchange64(__int64 volatile *Destination, __int64 ExChange, __int64 Comperand);
__MINGW_EXTENSION __INTRINSICS_USEINLINE 
__int64 _InterlockedCompareExchange64(__int64 volatile *Destination, __int64 ExChange, __int64 Comperand) {
    return __sync_val_compare_and_swap(Destination, Comperand, ExChange);
}
#define __INTRINSIC_DEFINED__InterlockedCompareExchange64
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedCompareExchangePointer)
void *_InterlockedCompareExchangePointer(void * volatile *Destination, void *ExChange, void *Comperand);
__INTRINSICS_USEINLINE 
void *_InterlockedCompareExchangePointer(void *volatile *Destination, void *ExChange, void *Comperand) {
    return __sync_val_compare_and_swap(Destination, Comperand, ExChange);
}
#define __INTRINSIC_DEFINED__InterlockedCompareExchangePointer
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_InterlockedExchangePointer)
void *_InterlockedExchangePointer(void *volatile *Target,void *Value);
__INTRINSICS_USEINLINE 
void *_InterlockedExchangePointer(void *volatile *Target,void *Value) {
    return __sync_lock_test_and_set(Target, Value);
}
#define __INTRINSIC_DEFINED__InterlockedExchangePointer
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_BitScanForward)
unsigned char _BitScanForward(unsigned __LONG32 *Index, unsigned __LONG32 Mask);
__INTRINSICS_USEINLINE 
__buildbitscan(_BitScanForward, unsigned __LONG32, "bsf")
#define __INTRINSIC_DEFINED__BitScanForward
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_BitScanReverse)
unsigned char _BitScanReverse(unsigned __LONG32 *Index, unsigned __LONG32 Mask);
__INTRINSICS_USEINLINE 
__buildbitscan(_BitScanReverse, unsigned __LONG32, "bsr")
#define __INTRINSIC_DEFINED__BitScanReverse
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_bittest)
unsigned char _bittest(__LONG32 const *a, __LONG32 b);
__INTRINSICS_USEINLINE
__buildbittest(_bittest, __LONG32, "I")
#define __INTRINSIC_DEFINED__bittest
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_bittestandset)
unsigned char _bittestandset(__LONG32 *a, __LONG32 b);
__INTRINSICS_USEINLINE
__buildbittestand(_bittestandset, __LONG32, "bts", "I")
#define __INTRINSIC_DEFINED__bittestandset
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_bittestandreset)
unsigned char _bittestandreset(__LONG32 *a, __LONG32 b);
__INTRINSICS_USEINLINE
__buildbittestand(_bittestandreset, __LONG32, "btr", "I")
#define __INTRINSIC_DEFINED__bittestandreset
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(_bittestandcomplement)
unsigned char _bittestandcomplement(__LONG32 *a, __LONG32 b);
__INTRINSICS_USEINLINE
__buildbittestand(_bittestandcomplement, __LONG32, "btc", "I")
#define __INTRINSIC_DEFINED__bittestandcomplement
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__inbyte)
unsigned char __inbyte(unsigned short Port);
__INTRINSICS_USEINLINE
__build_inport(__inbyte, unsigned char)
#define __INTRINSIC_DEFINED___inbyte
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__inword)
unsigned short __inword(unsigned short Port);
__INTRINSICS_USEINLINE
__build_inport(__inword, unsigned short)
#define __INTRINSIC_DEFINED___inword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__indword)
unsigned __LONG32 __indword(unsigned short Port);
__INTRINSICS_USEINLINE
__build_inport(__indword, unsigned __LONG32)
#define __INTRINSIC_DEFINED___indword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__outbyte)
void __outbyte(unsigned short Port, unsigned char Data);
__INTRINSICS_USEINLINE
__build_outport(__outbyte, unsigned char)
#define __INTRINSIC_DEFINED___outbyte
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__outword)
void __outword(unsigned short Port, unsigned short Data);
__INTRINSICS_USEINLINE
__build_outport(__outword, unsigned short)
#define __INTRINSIC_DEFINED___outword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__outdword)
void __outdword(unsigned short Port, unsigned __LONG32 Data);
__INTRINSICS_USEINLINE
__build_outport(__outdword, unsigned __LONG32)
#define __INTRINSIC_DEFINED___outdword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__inbytestring)
void __inbytestring(unsigned short Port, unsigned char *Buffer, unsigned __LONG32 Count);
__INTRINSICS_USEINLINE
__build_inportstring(__inbytestring, unsigned char, "b", "b")
#define __INTRINSIC_DEFINED___inbytestring
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__inwordstring)
void __inwordstring(unsigned short Port, unsigned short *Buffer, unsigned __LONG32 Count);
__INTRINSICS_USEINLINE
__build_inportstring(__inwordstring, unsigned short, "w", "w")
#define __INTRINSIC_DEFINED___inwordstring
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__indwordstring)
void __indwordstring(unsigned short Port, unsigned __LONG32 *Buffer, unsigned __LONG32 Count);
__INTRINSICS_USEINLINE
__build_inportstring(__indwordstring, unsigned __LONG32, "l", "d")
#define __INTRINSIC_DEFINED___indwordstring
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__outbytestring)
void __outbytestring(unsigned short Port, unsigned char *Buffer, unsigned __LONG32 Count);
__INTRINSICS_USEINLINE
__build_outportstring(__outbytestring, unsigned char, "b", "b")
#define __INTRINSIC_DEFINED___outbytestring
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__outwordstring)
void __outwordstring(unsigned short Port, unsigned short *Buffer, unsigned __LONG32 Count);
__INTRINSICS_USEINLINE
__build_outportstring(__outwordstring, unsigned short, "w", "w")
#define __INTRINSIC_DEFINED___outwordstring
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__outdwordstring)
void __outdwordstring(unsigned short Port, unsigned __LONG32 *Buffer, unsigned __LONG32 Count);
__INTRINSICS_USEINLINE
__build_outportstring(__outdwordstring, unsigned __LONG32, "l", "d")
#define __INTRINSIC_DEFINED___outdwordstring
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__cpuid)
void __cpuid(int CPUInfo[4], int InfoType);
__INTRINSICS_USEINLINE
void __cpuid(int CPUInfo[4], int InfoType) {
   __asm__ __volatile__ (
      "cpuid"
      : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
      : "a" (InfoType));
}
#define __INTRINSIC_DEFINED___cpuid
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readmsr)
__MINGW_EXTENSION unsigned __int64 __readmsr(unsigned __LONG32);
__INTRINSICS_USEINLINE
unsigned __int64 __readmsr(unsigned __LONG32 msr)
{
#ifdef __x86_64__
   unsigned __int64 val1, val2;
#else
   unsigned __LONG32 val1, val2;
#endif

   __asm__ __volatile__(
      "rdmsr"
      : "=a" (val1), "=d" (val2)
      : "c" (msr));

   return ((unsigned __int64) val1) | (((unsigned __int64)val2) << 32);
}
#define __INTRINSIC_DEFINED___readmsr
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writemsr)
__MINGW_EXTENSION void __writemsr(unsigned __LONG32, unsigned __int64);
__INTRINSICS_USEINLINE
void __writemsr(unsigned __LONG32 msr, unsigned __int64 Value)
{
   unsigned __LONG32 val1 = Value, val2 = Value >> 32;
   __asm__ __volatile__ (
      "wrmsr"
      :
      : "c" (msr), "a" (val1), "d" (val2));
}
#define __INTRINSIC_DEFINED___writemsr
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__movsb)
void __movsb(unsigned char *Destination, unsigned char const *Source, size_t Count);
__INTRINSICS_USEINLINE
__buildmov(__movsb, unsigned char, "b")
#define __INTRINSIC_DEFINED___movsb
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__movsw)
void __movsw(unsigned short *Dest, unsigned short const *Source, size_t Count);
__INTRINSICS_USEINLINE
__buildmov(__movsw, unsigned short, "w")
#define __INTRINSIC_DEFINED___movsw
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__movsd)
void __movsd(unsigned __LONG32 *Dest, unsigned __LONG32 const *Source, size_t Count);
__INTRINSICS_USEINLINE
__buildmov(__movsd, unsigned __LONG32, "d")
#define __INTRINSIC_DEFINED___movsd
#endif /* __INTRINSIC_PROLOG */

#endif /* defined(__x86_64__) || (defined(_X86_) */

/* ***************************************************** */

#if defined(_X86_)

#if __INTRINSIC_PROLOG(__readfsbyte)
unsigned char __readfsbyte(unsigned __LONG32 Offset);
__INTRINSICS_USEINLINE
__buildreadseg(__readfsbyte, unsigned char, "fs")
#define __INTRINSIC_DEFINED___readfsbyte
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readfsword)
unsigned short __readfsword(unsigned __LONG32 Offset);
__INTRINSICS_USEINLINE
__buildreadseg(__readfsword, unsigned short, "fs")
#define __INTRINSIC_DEFINED___readfsword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readfsdword)
unsigned __LONG32 __readfsdword(unsigned __LONG32 Offset);
__INTRINSICS_USEINLINE
__buildreadseg(__readfsdword, unsigned __LONG32, "fs")
#define __INTRINSIC_DEFINED___readfsdword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writefsbyte)
void __writefsbyte(unsigned __LONG32 Offset,unsigned char Data);
__INTRINSICS_USEINLINE
__buildwriteseg(__writefsbyte, unsigned char, "fs")
#define __INTRINSIC_DEFINED___writefsbyte
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writefsword)
void __writefsword(unsigned __LONG32 Offset,unsigned short Data);
__INTRINSICS_USEINLINE
__buildwriteseg(__writefsword, unsigned short, "fs")
#define __INTRINSIC_DEFINED___writefsword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writefsdword)
void __writefsdword(unsigned __LONG32 Offset,unsigned __LONG32 Data);
__INTRINSICS_USEINLINE
__buildwriteseg(__writefsdword, unsigned __LONG32, "fs")
#define __INTRINSIC_DEFINED___writefsdword
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr0)
unsigned __LONG32 __readcr0(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr0, unsigned __LONG32, "0")
#define __INTRINSIC_DEFINED___readcr0
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr2)
unsigned __LONG32 __readcr2(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr2, unsigned __LONG32, "2")
#define __INTRINSIC_DEFINED___readcr2
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr3)
unsigned __LONG32 __readcr3(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr3, unsigned __LONG32, "3")
#define __INTRINSIC_DEFINED___readcr3
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr4)
unsigned __LONG32 __readcr4(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr4, unsigned __LONG32, "4")
#define __INTRINSIC_DEFINED___readcr4
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__readcr8)
unsigned __LONG32 __readcr8(void);
__INTRINSICS_USEINLINE
__build_readcr(__readcr8, unsigned __LONG32, "8")
#define __INTRINSIC_DEFINED___readcr8
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writecr0)
void __writecr0(unsigned __LONG32);
__INTRINSICS_USEINLINE
__build_writecr(__writecr0, unsigned __LONG32, "0")
#define __INTRINSIC_DEFINED___writecr0
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writecr3)
void __writecr3(unsigned __LONG32);
__INTRINSICS_USEINLINE
__build_writecr(__writecr3, unsigned __LONG32, "3")
#define __INTRINSIC_DEFINED___writecr3
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writecr4)
void __writecr4(unsigned __LONG32);
__INTRINSICS_USEINLINE
__build_writecr(__writecr4, unsigned __LONG32, "4")
#define __INTRINSIC_DEFINED___writecr4
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__writecr8)
void __writecr8(unsigned __LONG32);
__INTRINSICS_USEINLINE
__build_writecr(__writecr8, unsigned __LONG32, "8")
#define __INTRINSIC_DEFINED___writecr8
#endif /* __INTRINSIC_PROLOG */

#endif /* defined(_X86_) */

#ifdef __cplusplus
}
#endif

#undef __INTRINSIC_ONLYSPECIAL
#undef __INTRINSIC_PROLOG
#undef __INTRINSIC_EPILOG
#undef __INTRINSICS_USEINLINE

#endif /* __MINGW_INTRIN_INLINE */
