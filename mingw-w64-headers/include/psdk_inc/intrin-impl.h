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

#include <psdk_inc/intrin-mac.h>

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

   If no groups are defined (such as what happens when including intrin.h,
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

#endif /* __INTRINSIC_GROUP_WINNT */

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
__buildstos(__stosq, unsigned __int64)
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

#endif // __x86_64__

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
__buildstos(__stosb, unsigned char)
#define __INTRINSIC_DEFINED___stosb
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__stosw)
void __stosw(unsigned short *, unsigned short, size_t);
__INTRINSICS_USEINLINE 
__buildstos(__stosw, unsigned short)
#define __INTRINSIC_DEFINED___stosw
#endif /* __INTRINSIC_PROLOG */

#if __INTRINSIC_PROLOG(__stosd)
void __stosd(unsigned __LONG32 *, unsigned __LONG32, size_t);
__INTRINSICS_USEINLINE 
__buildstos(__stosd, unsigned __LONG32)
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

#endif // defined(__x86_64__) || (defined(_X86_)

#ifdef __cplusplus
}
#endif

#undef __INTRINSIC_ONLYSPECIAL
#undef __INTRINSIC_PROLOG
#undef __INTRINSIC_EPILOG
#undef __INTRINSICS_USEINLINE
