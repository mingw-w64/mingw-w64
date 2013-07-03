#define __INTRINSIC_ONLYSPECIAL
#define __INTRINSIC_SPECIAL__InterlockedXor /* Causes code generation in intrin-impl.h */

#include <intrin.h>

__LONG32 InterlockedXor(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedXor")));

