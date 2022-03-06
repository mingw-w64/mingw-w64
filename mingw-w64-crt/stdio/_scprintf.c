/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <windows.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* mingw-w64 always provides _vscprintf() implementation, so use it */
static int __cdecl emu_scprintf(const char * __restrict__ format, ...)
{
    va_list arglist;
    int ret;

    va_start(arglist, format);
    ret = _vscprintf(format, arglist);
    va_end(arglist);
    return ret;
}

#ifndef __LIBMSVCRT_OS__

int (__cdecl *__MINGW_IMP_SYMBOL(_scprintf))(const char * __restrict__, ...) = emu_scprintf;

/* gcc does not provide an easy way to call another variadic function with reusing current arguments
 * this source file is used only on i386, so do this function redirect via inline i386 assembly */
#define ASM_SYM(sym) __MINGW64_STRINGIFY(__MINGW_USYMBOL(sym))
asm (
".globl\t" ASM_SYM(_scprintf) "\n\t"
".def\t" ASM_SYM(_scprintf) ";\t.scl\t2;\t.type\t32;\t.endef\n"
ASM_SYM(_scprintf) ":\n\t"
    "jmp\t*" ASM_SYM(__MINGW_IMP_SYMBOL(_scprintf))
);

#else

#include <msvcrt.h>

static int __cdecl init_scprintf(const char * __restrict__ format, ...);

int (__cdecl *__MINGW_IMP_SYMBOL(_scprintf))(const char * __restrict__, ...) = init_scprintf;

__attribute__((used))
static void resolve_scprintf(void)
{
    HMODULE msvcrt = __mingw_get_msvcrt_handle();
    int (__cdecl *func)(const char * __restrict__, ...) = NULL;

    if (msvcrt)
        func = (int (__cdecl *)(const char * __restrict__, ...))GetProcAddress(msvcrt, "_scprintf");

    if (!func)
        func = emu_scprintf;

    __MINGW_IMP_SYMBOL(_scprintf) = func;
}

/* gcc does not provide an easy way to call another variadic function with reusing current arguments
 * this source file is used only on i386, so do this function redirect via inline i386 assembly */
#define ASM_SYM(sym) __MINGW64_STRINGIFY(__MINGW_USYMBOL(sym))
asm (
".def\t" ASM_SYM(init_scprintf) ";\t.scl\t3;\t.type\t32;\t.endef\n"
ASM_SYM(init_scprintf) ":\n\t"
    "pushal\n\t"
    "call\t" ASM_SYM(resolve_scprintf) "\n\t"
    "popal\n\t"
    /* fallthrough */
".globl\t" ASM_SYM(_scprintf) "\n\t"
".def\t" ASM_SYM(_scprintf) ";\t.scl\t2;\t.type\t32;\t.endef\n"
ASM_SYM(_scprintf) ":\n\t"
    "jmp\t*" ASM_SYM(__MINGW_IMP_SYMBOL(_scprintf))
);

#endif
