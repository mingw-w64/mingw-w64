#define __INTRINSIC_ONLYSPECIAL
#define __INTRINSIC_SPECIAL__interlockedbittestandreset /* Causes code generation in intrin-impl.h */

#include <intrin.h>

unsigned char InterlockedBitTestAndReset(__LONG32 volatile *, __LONG32) __attribute__((alias("_interlockedbittestandreset")));
