/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_MEMORY_S
#define _INC_MEMORY_S

#if defined(MINGW_HAS_SECURE_API)
#include <memory.h>

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

#ifndef _MEMORY_S_DEFINED
#define _MEMORY_S_DEFINED
 errno_t __cdecl memcpy_s (void *_dest,size_t _numberOfElements,const void *_src,size_t _count);
#endif /*_MEMORY_S_DEFINED*/

#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*MINGW_HAS_SECURE_API*/
#endif /*_INC_MEMORY_S*/
