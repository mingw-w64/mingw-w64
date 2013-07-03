#define __INTRINSIC_ONLYSPECIAL
#define __INTRINSIC_SPECIAL__interlockedbittestandset64 /* Causes code generation in intrin-impl.h */

#include <intrin.h>

unsigned char InterlockedBitTestAndSet64(__int64 volatile *, __int64) __attribute__((alias("_interlockedbittestandset64")));
