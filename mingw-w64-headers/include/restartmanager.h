/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_RESTARTMANAGER
#define _INC_RESTARTMANAGER

#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _RM_APP_STATUS {
  RmStatusUnknown          = 0x0,
  RmStatusRunning          = 0x1,
  RmStatusStopped          = 0x2,
  RmStatusStoppedOther     = 0x4,
  RmStatusRestarted        = 0x8,
  RmStatusErrorOnStop      = 0x10,
  RmStatusErrorOnRestart   = 0x20,
  RmStatusShutdownMasked   = 0x40,
  RmStatusRestartMasked    = 0x80
} RM_APP_STATUS;

typedef enum _RM_APP_TYPE {
  RmUnknownApp    = 0,
  RmMainWindow    = 1,
  RmOtherWindow   = 2,
  RmService       = 3,
  RmExplorer      = 4,
  RmConsole       = 5,
  RmCritical      = 1000
} RM_APP_TYPE;

typedef enum _RM_FILTER_ACTION {
  RmInvalidFilterAction   = 0,
  RmNoRestart             = 1,
  RmNoShutdown            = 2
} RM_FILTER_ACTION;

typedef enum _RM_FILTER_TRIGGER {
  RmFilterTriggerInvalid   = 0,
  RmFilterTriggerFile      = 1,
  RmFilterTriggerProcess   = 2,
  RmFilterTriggerService   = 3
} RM_FILTER_TRIGGER;

typedef enum _RM_REBOOT_REASON {
  RmRebootReasonNone               = 0x0,
  RmRebootReasonPermissionDenied   = 0x1,
  RmRebootReasonSessionMismatch    = 0x2,
  RmRebootReasonCriticalProcess    = 0x4,
  RmRebootReasonCriticalService    = 0x8,
  RmRebootReasonDetectedSelf       = 0x10
} RM_REBOOT_REASON;

typedef enum _RM_SHUTDOWN_TYPE {
  RmForceShutdown            = 0x1,
  RmShutdownOnlyRegistered   = 0x10
} RM_SHUTDOWN_TYPE;

typedef struct _RM_UNIQUE_PROCESS {
  DWORD    dwProcessId;
  FILETIME ProcessStartTime;
} RM_UNIQUE_PROCESS, *PRM_UNIQUE_PROCESS;

typedef struct _RM_FILTER_INFO {
  RM_FILTER_ACTION  FilterAction;
  RM_FILTER_TRIGGER FilterTrigger;
  DWORD             cbNextOffset;
  LPWSTR            strFilename;
  RM_UNIQUE_PROCESS Process;
  LPWSTR            strServiceShortName;
} RM_FILTER_INFO, *PRM_FILTER_INFO;

typedef struct _RM_PROCESS_INFO {
  RM_UNIQUE_PROCESS Process;
  WCHAR             strAppName[CCH_RM_MAX_APP_NAME+1];
  WCHAR             strServiceShortName[CCH_RM_MAX_SVC_NAME+1];
  RM_APP_TYPE       ApplicationType;
  ULONG             AppStatus;
  DWORD             TSSessionId;
  WINBOOL           bRestartable;
} RM_PROCESS_INFO;

typedef void ( *RM_WRITE_STATUS_CALLBACK )(
  UINT nPercentComplete
);

DWORD WINAPI RmAddFilter(
  DWORD dwSessionHandle,
  LPCWSTR strFilename,
  RM_UNIQUE_PROCESS *Application,
  LPCWSTR strShortServiceName,
  RM_FILTER_ACTION ActionType
);

DWORD WINAPI RmCancelCurrentTask(
  DWORD dwSessionHandle
);

DWORD WINAPI RmEndSession(
  DWORD dwSessionHandle
);

DWORD WINAPI RmGetFilterList(
  DWORD dwSessionHandle,
  PBYTE pbFilterBuf,
  DWORD cbFilterBuf,
  LPDWORD cbFilterBufNeeded
);

DWORD WINAPI RmGetList(
  DWORD dwSessionHandle,
  UINT *pnProcInfoNeeded,
  UINT *pnProcInfo,
  RM_PROCESS_INFO rgAffectedApps[ ],
  LPDWORD lpdwRebootReasons
);

DWORD WINAPI RmJoinSession(
  DWORD *pSessionHandle,
  const WCHAR strSessionKey[ ]
);

DWORD WINAPI RmRegisterResources(
  DWORD dwSessionHandle,
  UINT nFiles,
  LPCWSTR rgsFilenames[ ],
  UINT nApplications,
  RM_UNIQUE_PROCESS rgApplications[ ],
  UINT nServices,
  LPCWSTR rgsServiceNames[ ]
);

DWORD WINAPI RmRemoveFilter(
  DWORD dwSessionHandle,
  LPCWSTR strFilename,
  RM_UNIQUE_PROCESS *Application,
  LPCWSTR strShortServiceName
);

DWORD WINAPI RmRestart(
  DWORD dwSessionHandle,
  DWORD dwRestartFlags,
  RM_WRITE_STATUS_CALLBACK fnStatus
);

#define RmForceShutdown 0x1
#define RmShutdownOnlyRegistered 0x10

DWORD WINAPI RmShutdown(
  DWORD dwSessionHandle,
  ULONG lActionFlags,
  RM_WRITE_STATUS_CALLBACK fnStatus
);

DWORD WINAPI RmStartSession(
  DWORD *pSessionHandle,
  DWORD dwSessionFlags,
  WCHAR strSessionKey[]
);

#ifdef __cplusplus
}
#endif

#endif /* (_WIN32_WINNT >= 0x0600) */

#endif /*_INC_RESTARTMANAGER*/

