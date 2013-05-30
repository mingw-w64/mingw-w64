#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

__buildlogicali(_InterlockedAnd, __LONG32, and)

__LONG32 InterlockedAnd(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedAnd")));

