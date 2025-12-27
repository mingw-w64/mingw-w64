/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw_mac.h>

/* Define _setjmp3 as wrapper around the _setjmp */
#define I386_SETJMP3_ONLY
#include "setjmp.S"
