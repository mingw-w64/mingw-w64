/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define _UCRT
#include <_mingw.h>

/* `quick_exit()`, C99  */
void quick_exit(int status) __attribute__((__noreturn__));
extern void (*__MINGW_IMP_SYMBOL(quick_exit))(int) __attribute__((__noreturn__));

void quick_exit(int status)
{
  (*__MINGW_IMP_SYMBOL(quick_exit))(status);
}

/* `_Exit()`, C99  */
void _Exit(int status) __attribute__((__noreturn__));
extern void (*__MINGW_IMP_SYMBOL(_Exit))(int) __attribute__((__noreturn__));

void _Exit(int status)
{
  (*__MINGW_IMP_SYMBOL(_Exit))(status);
}
