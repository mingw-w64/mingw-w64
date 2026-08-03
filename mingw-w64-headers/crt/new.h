/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_NEW
#define _INC_NEW

#include <corecrt.h>

#ifdef __cplusplus
#include <new>
#include <crtdefs.h>
#pragma push_macro("new")
#undef new
#endif

_CRT_BEGIN_C_HEADER

#ifndef __PLACEMENT_NEW_INLINE
#define __PLACEMENT_NEW_INLINE
#endif

_CRTIMP int __cdecl _query_new_mode(void);
_CRTIMP int __cdecl _set_new_mode(int _NewMode);

typedef int (__cdecl *_PNH)(size_t);

_CRTIMP _PNH __cdecl _query_new_handler(void);
_CRTIMP _PNH __cdecl _set_new_handler(_PNH _NewHandler);

#define _NO_ANSI_NEW_HANDLER ((new_handler)-1)
#define _NO_ANSI_NEW_HANDLER_M ((_new_handler_m)-1)

_CRT_END_C_HEADER

#ifdef __cplusplus
#pragma pop_macro("new")
#endif

#endif
