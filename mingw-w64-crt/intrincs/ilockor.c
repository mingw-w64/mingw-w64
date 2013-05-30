#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

__buildlogicali(_InterlockedOr, __LONG32, or)

__LONG32 InterlockedOr(__LONG32 volatile *, __LONG32) __attribute__((alias("_InterlockedOr")));

