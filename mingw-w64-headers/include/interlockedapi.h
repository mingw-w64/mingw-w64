/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INTERLOCKAPI_H_
#define _INTERLOCKAPI_H_

#include <apiset.h>
#include <apisetcconv.h>
#include <minwindef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined (NOWINBASEINTERLOCK) && !defined (_NTOS_)
#if !defined (__x86_64__) && !defined (__ia64__) && !defined (__arm__)
  WINBASEAPI LONG WINAPI InterlockedIncrement (LONG volatile *lpAddend);
  WINBASEAPI LONG WINAPI InterlockedDecrement (LONG volatile *lpAddend);
  WINBASEAPI LONG WINAPI InterlockedExchange (LONG volatile *Target, LONG Value);
  WINBASEAPI LONG WINAPI InterlockedExchangeAdd (LONG volatile *Addend, LONG Value);
  WINBASEAPI LONG WINAPI InterlockedCompareExchange (LONG volatile *Destination, LONG Exchange, LONG Comperand);
  WINBASEAPI LONGLONG WINAPI InterlockedCompareExchange64 (LONGLONG volatile *Destination, LONGLONG Exchange, LONGLONG Comperand);

#define InterlockedExchangePointer(Target, Value) (PVOID)InterlockedExchange ((PLONG) (Target),((LONG) (LONG_PTR) (Value)))
#define InterlockedExchangePointerNoFence InterlockedExchangePointer

#if defined(__MINGW_INTRIN_INLINE) && (defined(__GNUC__) && (__MINGW_GNUC_PREREQ(4, 9) || (__MINGW_GNUC_PREREQ(4, 8) && __GNUC_PATCHLEVEL__ >= 2)))
  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedIncrement(LONG volatile *lpAddend) {
    return _InterlockedIncrement(lpAddend);
  }
  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedDecrement(LONG volatile *lpAddend) {
    return _InterlockedDecrement(lpAddend);
  }
  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedExchange(LONG volatile *Target, LONG Value) {
    return _InterlockedExchange(Target, Value);
  }
  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedExchangeAdd(LONG volatile *Addend, LONG Value) {
    return _InterlockedExchangeAdd(Addend, Value);
  }
  __MINGW_INTRIN_INLINE LONG WINAPI InterlockedCompareExchange(LONG volatile *Destination, LONG Exchange, LONG Comperand) {
    return _InterlockedCompareExchange(Destination, Exchange, Comperand);
  }
  __MINGW_INTRIN_INLINE LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG volatile *Destination, LONGLONG Exchange, LONGLONG Comperand) {
    return _InterlockedCompareExchange64(Destination, Exchange, Comperand);
  }
#endif
#endif

#if defined (_SLIST_HEADER_) && !defined (_NTOSP_)
  WINBASEAPI VOID WINAPI InitializeSListHead (PSLIST_HEADER ListHead);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPopEntrySList (PSLIST_HEADER ListHead);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPushEntrySList (PSLIST_HEADER ListHead, PSLIST_ENTRY ListEntry);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedFlushSList (PSLIST_HEADER ListHead);
  WINBASEAPI USHORT WINAPI QueryDepthSList (PSLIST_HEADER ListHead);

#if NTDDI_VERSION >= 0x06020000
#define InterlockedPushListSList InterlockedPushListSListEx

  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedPushListSListEx (PSLIST_HEADER ListHead, PSLIST_ENTRY List, PSLIST_ENTRY ListEnd, ULONG Count);
#endif
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
