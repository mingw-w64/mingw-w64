/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw_mac.h>

/*
 * Example usage of this include file:
 *
 * #define RETT int
 * #define FUNC func1
 * #define ARGS int arg1, int arg2
 * #define CALL arg1, arg2
 * #include "msvcrt_or_emu_glue.h"
 *
 * This example defines function named "func1" with signature:
 * int __cdecl func1(int arg1, int arg2) { ... }
 *
 * This function "func1" would either call emulation function named "emu_func1"
 * which always has to be declarated (it should be defined as static in the
 * same source file) or would call function named "func1" from "msvcrt.dll"
 * library if exists.
*/

#if !defined(RETT) || !defined(FUNC) || !defined(ARGS) || !defined(CALL)
#error "Missing definitions for msvcrt_or_emu_glue.h"
#endif

#if defined(FORCEEMU) || !defined(__LIBMSVCRT_OS__)

/*
 * If not compiling for os-system version of msvcrt.dll or FORCEEMU was
 * specified then always use emulated version.
 */

#ifdef NORETURN
__MINGW_ATTRIB_NORETURN
#endif
RETT __attribute__((alias(__MINGW64_STRINGIFY(__MINGW64_PASTE(emu_,FUNC))))) __cdecl FUNC(ARGS);
#ifdef NORETURN
__MINGW_ATTRIB_NORETURN
#endif
RETT (__cdecl *__MINGW_IMP_SYMBOL(FUNC))(ARGS) = FUNC;

#else

/*
 * If compiling for os-system version of msvcrt.dll and FORCEEMU was not
 * specified then try to use function from msvcrt.dll and fallback to
 * emulated version only if function does not exist in msvcrt.dll.
 */

#include <windows.h>
#include <msvcrt.h>

#ifdef NORETURN
__MINGW_ATTRIB_NORETURN
#endif
static RETT __cdecl __MINGW64_PASTE(init_,FUNC)(ARGS);

#ifdef NORETURN
__MINGW_ATTRIB_NORETURN
#endif
RETT (__cdecl *volatile __MINGW_IMP_SYMBOL(FUNC))(ARGS) = __MINGW64_PASTE(init_,FUNC);

#ifdef NORETURN
__MINGW_ATTRIB_NORETURN
#endif
static RETT __cdecl __MINGW64_PASTE(init_,FUNC)(ARGS)
{
    HMODULE msvcrt = __mingw_get_msvcrt_handle();
#ifdef NORETURN
    __MINGW_ATTRIB_NORETURN
#endif
    RETT (__cdecl *func)(ARGS) = NULL;

    if (msvcrt)
        func = (typeof(func))(void (__cdecl *)(void))GetProcAddress(msvcrt, __MINGW64_STRINGIFY(FUNC));

    if (!func)
        func = __MINGW64_PASTE(emu_,FUNC);

    (void)InterlockedExchangePointer((PVOID volatile *)&__MINGW_IMP_SYMBOL(FUNC), func);

#ifndef NORETURN
    return
#endif
    func(CALL);
}

#ifdef NORETURN
__MINGW_ATTRIB_NORETURN
#endif
RETT __cdecl FUNC(ARGS)
{
#ifndef NORETURN
    return
#endif
    __MINGW_IMP_SYMBOL(FUNC)(CALL);
}

#endif

/* Now undefine the definitions, so the file can be included more times. */
#undef FORCEEMU
#undef NORETURN
#undef RETT
#undef FUNC
#undef ARGS
#undef CALL
