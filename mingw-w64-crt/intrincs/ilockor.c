#define __INTRINSIC_ONLYSPECIAL
#define __INTRINSIC_SPECIAL__InterlockedOr /* Causes code generation in intrin-impl.h */

#include <intrin.h>

__LONG32 InterlockedOr(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedOr")));

