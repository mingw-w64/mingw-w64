/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <windows.h>
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

/* mingw-w64 always provides _vscwprintf() implementation, so use it */
static int __cdecl emu_scwprintf(const wchar_t * __restrict__ format, ...)
{
    va_list arglist;
    int ret;

    va_start(arglist, format);
    ret = _vscwprintf(format, arglist);
    va_end(arglist);
    return ret;
}

#ifndef __LIBMSVCRT_OS__

int __attribute__ ((alias ("emu_scwprintf"))) __cdecl _scwprintf(const wchar_t * __restrict__, ...);
int (__cdecl *__MINGW_IMP_SYMBOL(_scwprintf))(const wchar_t * __restrict__, ...) = _scwprintf;

#else

#include <msvcrt.h>

static int __cdecl init_scwprintf(const wchar_t * __restrict__ format, ...);

int (__cdecl *__MINGW_IMP_SYMBOL(_scwprintf))(const wchar_t * __restrict__, ...) = init_scwprintf;

__attribute__((used))
static void resolve_scwprintf(void)
{
    HMODULE msvcrt = __mingw_get_msvcrt_handle();
    int (__cdecl *func)(const wchar_t * __restrict__, ...) = NULL;

    if (msvcrt)
        func = (int (__cdecl *)(const wchar_t * __restrict__, ...))GetProcAddress(msvcrt, "_scwprintf");

    if (!func)
        func = emu_scwprintf;

    __MINGW_IMP_SYMBOL(_scwprintf) = func;
}

/* gcc does not provide an easy way to call another variadic function with reusing current arguments
 * this source file is used only on i386, so do this function redirect via inline i386 assembly */
#define ASM_SYM(sym) __MINGW64_STRINGIFY(__MINGW_USYMBOL(sym))
asm (
".def\t" ASM_SYM(init_scwprintf) ";\t.scl\t3;\t.type\t32;\t.endef\n"
ASM_SYM(init_scwprintf) ":\n\t"
    "pushal\n\t"
    "call\t" ASM_SYM(resolve_scwprintf) "\n\t"
    "popal\n\t"
    /* fallthrough */
".globl\t" ASM_SYM(_scwprintf) "\n\t"
".def\t" ASM_SYM(_scwprintf) ";\t.scl\t2;\t.type\t32;\t.endef\n"
ASM_SYM(_scwprintf) ":\n\t"
    "jmp\t*" ASM_SYM(__MINGW_IMP_SYMBOL(_scwprintf))
);

#endif
