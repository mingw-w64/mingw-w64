/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_MINGW_PROCESS
#define _INC_MINGW_PROCESS

#include <corecrt.h>

/**
 * This header file contains declarations which belong to both process.h and
 * stdlib.h; it allows to avoid duplicating declarations in multiple headers.
 *
 * This header file is similar to corecrt_*.h header files used by MSVC,
 * but since there is no corecrt_process.h, we name it _mingw_process.h instead.
 */

_CRT_BEGIN_C_HEADER

int __cdecl system(const char* _Command);

void __cdecl __MINGW_NOTHROW exit(int _Code) __MINGW_ATTRIB_NORETURN;
void __cdecl __MINGW_NOTHROW _exit(int _Code) __MINGW_ATTRIB_NORETURN;
#ifdef _UCRT
void __cdecl __MINGW_NOTHROW quick_exit(int _Code) __MINGW_ATTRIB_NORETURN;
#endif

/* C99 function name */
void __cdecl _Exit(int) __MINGW_ATTRIB_NORETURN;

#pragma push_macro("abort")
#undef abort
void __cdecl __MINGW_ATTRIB_NORETURN abort(void);
#pragma pop_macro("abort")

_CRT_END_C_HEADER

#endif /* _INC_MINGW_PROCESS */
