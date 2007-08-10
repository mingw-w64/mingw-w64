/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_TIME_INL
#define _INC_TIME_INL
#ifndef RC_INVOKED

#ifdef _USE_32BIT_TIME_T
__CRT_INLINE double __cdecl difftime(time_t _Time1,time_t _Time2) { return _difftime32(_Time1,_Time2); }
__CRT_INLINE char *__cdecl ctime(const time_t *_Time) { return _ctime32(_Time); }
__CRT_INLINE struct tm *__cdecl gmtime(const time_t *_Time) { return _gmtime32(_Time); }
__CRT_INLINE struct tm *__cdecl localtime(const time_t *_Time) { return _localtime32(_Time); }
__CRT_INLINE errno_t __cdecl localtime_s(struct tm *_Tm,const time_t *_Time) { return _localtime32_s(_Tm,_Time); }
__CRT_INLINE time_t __cdecl mktime(struct tm *_Tm) { return _mktime32(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(struct tm *_Tm) { return _mkgmtime32(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { return _time32(_Time); }
#else
__CRT_INLINE double __cdecl difftime(time_t _Time1,time_t _Time2) { return _difftime64(_Time1,_Time2); }
__CRT_INLINE char *__cdecl ctime(const time_t *_Time) { return _ctime64(_Time); }
__CRT_INLINE struct tm *__cdecl gmtime(const time_t *_Time) { return _gmtime64(_Time); }
__CRT_INLINE struct tm *__cdecl localtime(const time_t *_Time) { return _localtime64(_Time); }
__CRT_INLINE errno_t __cdecl localtime_s(struct tm *_Tm,const time_t *_Time) { return _localtime64_s(_Tm,_Time); }
__CRT_INLINE time_t __cdecl mktime(struct tm *_Tm) { return _mktime64(_Tm); }
__CRT_INLINE time_t __cdecl _mkgmtime(struct tm *_Tm) { return _mkgmtime64(_Tm); }
__CRT_INLINE time_t __cdecl time(time_t *_Time) { return _time64(_Time); }
#endif
#endif
#endif
