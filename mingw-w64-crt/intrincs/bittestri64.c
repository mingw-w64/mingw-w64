#define __INTRINSIC_ONLYSPECIAL
#define __INTRINSIC_SPECIAL__interlockedbittestandreset64 /* Causes code generation in intrin-impl.h */

#include <intrin.h>

unsigned char InterlockedBitTestAndReset64(__int64 volatile *, __int64) __attribute__((alias("_interlockedbittestandreset64")));
