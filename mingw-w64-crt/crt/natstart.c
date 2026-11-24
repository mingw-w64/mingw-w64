/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <crtdefs.h>
#include <internal.h>

volatile unsigned int __native_dllmain_reason = UINT_MAX; /* Deprecated, may be removed future. */
volatile __enative_startup_state __native_startup_state = __uninitialized;
void *volatile __native_startup_lock = NULL;
