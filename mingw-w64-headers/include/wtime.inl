/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_WTIME_INL
#define _INC_WTIME_INL
#ifndef RC_INVOKED

#ifdef _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { return _wctime32(_Time); }
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,const time_t *_Time) { return _wctime32_s(_Buffer,_SizeInWords,_Time); }
#else
__CRT_INLINE wchar_t *__cdecl _wctime(const time_t *_Time) { return _wctime64(_Time); }
__CRT_INLINE errno_t __cdecl _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,const time_t *_Time) { return _wctime64_s(_Buffer,_SizeInWords,_Time); }
#endif
#endif
#endif
