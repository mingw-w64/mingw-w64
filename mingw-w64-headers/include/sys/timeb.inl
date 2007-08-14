/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_TIMEB_INL
#define _INC_TIMEB_INL

#ifndef	NO_OLDNAMES
#ifdef _USE_32BIT_TIME_T
__CRT_INLINE void __cdecl ftime(struct timeb *_Tmb) {
  _ftime32((struct __timeb32 *)_Tmb);
}
#else
__CRT_INLINE void __cdecl ftime(struct timeb *_Tmb) {
  _ftime64((struct __timeb64 *)_Tmb);
}
#endif
#endif
#endif
