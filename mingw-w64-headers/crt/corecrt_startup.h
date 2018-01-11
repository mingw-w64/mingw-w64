/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _INC_CORECRT_STARTUP
#define _INC_CORECRT_STARTUP

#ifdef __cplusplus
extern "C" {
#endif

_CRTIMP char **__cdecl __p__acmdln(void);
#define _acmdln (*__p__acmdln())

_CRTIMP wchar_t **__cdecl __p__wcmdln(void);
#define _wcmdln (*__p__wcmdln())

typedef void (__cdecl *_PVFV)(void);
typedef int (__cdecl *_PIFV)(void);
typedef void (__cdecl *_PVFI)(int);

#ifdef __cplusplus
}
#endif
#endif
