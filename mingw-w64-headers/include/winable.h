/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _WINABLE_
#define _WINABLE_

#ifndef _WINABLE_
#define WINABLEAPI DECLSPEC_IMPORT
#else
#define WINABLEAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

  WINBOOL WINAPI BlockInput(WINBOOL fBlockIt);

#define CCHILDREN_FRAME 7

#ifdef __cplusplus
}
#endif
#endif
