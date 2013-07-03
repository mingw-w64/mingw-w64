#define __INTRINSIC_ONLYSPECIAL
#define __INTRINSIC_SPECIAL__interlockedbittestandcomplement64 /* Causes code generation in intrin-impl.h */

#include <intrin.h>

unsigned char InterlockedBitTestAndComplement64(__int64 volatile *, __int64) __attribute__((alias("_interlockedbittestandcomplement64")));
