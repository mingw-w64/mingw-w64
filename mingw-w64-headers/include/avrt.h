/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_AVRT
#define _INC_AVRT

#if (_WIN32_WINNT >= 0x0600)
typedef enum _AVRT_PRIORITY {
  AVRT_PRIORITY_LOW = -1,
  AVRT_PRIORITY_NORMAL,		/* 0 */
  AVRT_PRIORITY_HIGH,		/* 1 */
  AVRT_PRIORITY_CRITICAL	/* 2 */
} AVRT_PRIORITY, *PAVRT_PRIORITY;

#define AvSetMmThreadCharacteristics __MINGW_NAME_AW(AvSetMmThreadCharacteristics)
#define AvSetMmMaxThreadCharacteristics __MINGW_NAME_AW(AvSetMmMaxThreadCharacteristics)
#define AvRtCreateThreadOrderingGroupEx __MINGW_NAME_AW(AvRtCreateThreadOrderingGroupEx)

WINBOOL WINAPI AvQuerySystemResponsiveness(
  HANDLE AvrtHandle,
  PULONG SystemResponsivenessValue
);

HANDLE WINAPI AvSetMmThreadCharacteristicsA(
  LPCSTR TaskName,
  LPDWORD TaskIndex
);

HANDLE WINAPI AvSetMmThreadCharacteristicsW(
  LPCWSTR TaskName,
  LPDWORD TaskIndex
);

WINBOOL WINAPI AvRevertMmThreadCharacteristics(
  HANDLE AvrtHandle
);

HANDLE WINAPI AvSetMmMaxThreadCharacteristicsA(
  LPCSTR FirstTask,
  LPCSTR SecondTask,
  LPDWORD TaskIndex
);

HANDLE WINAPI AvSetMmMaxThreadCharacteristicsW(
  LPCWSTR FirstTask,
  LPCWSTR SecondTask,
  LPDWORD TaskIndex
);

WINBOOL WINAPI AvSetMmThreadPriority(
  HANDLE AvrtHandle,
  AVRT_PRIORITY Priority
);

WINBOOL WINAPI AvRtCreateThreadOrderingGroup(
  PHANDLE Context,
  PLARGE_INTEGER Period,
  GUID *ThreadOrderingGuid,
  PLARGE_INTEGER Timeout
);

WINBOOL WINAPI AvRtCreateThreadOrderingGroupExA(
  PHANDLE Context,
  PLARGE_INTEGER Period,
  GUID *ThreadOrderingGuid,
  PLARGE_INTEGER Timeout,
  LPCSTR TaskName
);

WINBOOL WINAPI AvRtCreateThreadOrderingGroupExW(
  PHANDLE Context,
  PLARGE_INTEGER Period,
  GUID *ThreadOrderingGuid,
  PLARGE_INTEGER Timeout,
  LPCWSTR TaskName
);

WINBOOL WINAPI AvRtDeleteThreadOrderingGroup(
  HANDLE Context
);

WINBOOL WINAPI AvRtJoinThreadOrderingGroup(
  PHANDLE Context,
  GUID *ThreadOrderingGuid,
  WINBOOL Before
);

WINBOOL WINAPI AvRtLeaveThreadOrderingGroup(
  HANDLE Context
);

WINBOOL WINAPI AvRtWaitOnThreadOrderingGroup(
  HANDLE Context
);

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_AVRT*/
