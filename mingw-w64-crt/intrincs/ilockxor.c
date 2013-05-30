#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

__buildlogicali(_InterlockedXor, __LONG32, xor)

__LONG32 InterlockedXor(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedXor")));

