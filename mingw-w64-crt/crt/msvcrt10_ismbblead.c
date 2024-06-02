/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>

/**
 * Implementation of _ismbblead() function called by crtexewin.c startup code
 * for msvcrt10.dll library which does not contain this function and is not MBCS aware.
 */
int __cdecl _ismbblead(unsigned int _C);
int __cdecl _ismbblead(unsigned int __UNUSED_PARAM(_C)) { return 0; }
