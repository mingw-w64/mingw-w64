/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define _UCRT

#include <setjmp.h>
#include <windef.h>
#include <winbase.h>

void __cdecl longjmp( jmp_buf b, int retval )
{
    _JUMP_BUFFER *buf = (_JUMP_BUFFER *)b;
    EXCEPTION_RECORD rec;

    if (!retval) retval = 1;

    rec.ExceptionCode = STATUS_LONGJUMP;
    rec.ExceptionFlags = 0;
    rec.ExceptionRecord = NULL;
    rec.ExceptionAddress = NULL;
    rec.NumberParameters = 1;
    rec.ExceptionInformation[0] = (DWORD_PTR)buf;
    RtlUnwind( (void *)buf->Frame, (void *)buf->Rip, &rec, IntToPtr(retval) );
    __builtin_unreachable();
}

void (__cdecl *__MINGW_IMP_SYMBOL(longjmp))( jmp_buf b, int retval ) = longjmp;
