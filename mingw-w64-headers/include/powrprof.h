/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifdef __cplusplus
extern "C" {
#endif

  typedef struct _GLOBAL_MACHINE_POWER_POLICY{
    ULONG Revision;
    SYSTEM_POWER_STATE LidOpenWakeAc;
    SYSTEM_POWER_STATE LidOpenWakeDc;
    ULONG BroadcastCapacityResolution;
  } GLOBAL_MACHINE_POWER_POLICY,*PGLOBAL_MACHINE_POWER_POLICY;

  typedef struct _GLOBAL_USER_POWER_POLICY{
    ULONG Revision;
    POWER_ACTION_POLICY PowerButtonAc;
    POWER_ACTION_POLICY PowerButtonDc;
    POWER_ACTION_POLICY SleepButtonAc;
    POWER_ACTION_POLICY SleepButtonDc;
    POWER_ACTION_POLICY LidCloseAc;
    POWER_ACTION_POLICY LidCloseDc;
    SYSTEM_POWER_LEVEL DischargePolicy[NUM_DISCHARGE_POLICIES];
    ULONG GlobalFlags;
  } GLOBAL_USER_POWER_POLICY,*PGLOBAL_USER_POWER_POLICY;

  typedef struct _GLOBAL_POWER_POLICY{
    GLOBAL_USER_POWER_POLICY user;
    GLOBAL_MACHINE_POWER_POLICY mach;
  } GLOBAL_POWER_POLICY,*PGLOBAL_POWER_POLICY;

  typedef struct _MACHINE_POWER_POLICY{
    ULONG Revision;
    SYSTEM_POWER_STATE MinSleepAc;
    SYSTEM_POWER_STATE MinSleepDc;
    SYSTEM_POWER_STATE ReducedLatencySleepAc;
    SYSTEM_POWER_STATE ReducedLatencySleepDc;
    ULONG DozeTimeoutAc;
    ULONG DozeTimeoutDc;
    ULONG DozeS4TimeoutAc;
    ULONG DozeS4TimeoutDc;
    UCHAR MinThrottleAc;
    UCHAR MinThrottleDc;
    UCHAR pad1[2];
    POWER_ACTION_POLICY OverThrottledAc;
    POWER_ACTION_POLICY OverThrottledDc;
  } MACHINE_POWER_POLICY,*PMACHINE_POWER_POLICY;

  typedef struct _MACHINE_PROCESSOR_POWER_POLICY {
    ULONG Revision;
    PROCESSOR_POWER_POLICY ProcessorPolicyAc;
    PROCESSOR_POWER_POLICY ProcessorPolicyDc;
  } MACHINE_PROCESSOR_POWER_POLICY,*PMACHINE_PROCESSOR_POWER_POLICY;

  typedef struct _USER_POWER_POLICY{
    ULONG Revision;
    POWER_ACTION_POLICY IdleAc;
    POWER_ACTION_POLICY IdleDc;
    ULONG IdleTimeoutAc;
    ULONG IdleTimeoutDc;
    UCHAR IdleSensitivityAc;
    UCHAR IdleSensitivityDc;
    UCHAR ThrottlePolicyAc;
    UCHAR ThrottlePolicyDc;
    SYSTEM_POWER_STATE MaxSleepAc;
    SYSTEM_POWER_STATE MaxSleepDc;
    ULONG Reserved[2];
    ULONG VideoTimeoutAc;
    ULONG VideoTimeoutDc;
    ULONG SpindownTimeoutAc;
    ULONG SpindownTimeoutDc;
    BOOLEAN OptimizeForPowerAc;
    BOOLEAN OptimizeForPowerDc;
    UCHAR FanThrottleToleranceAc;
    UCHAR FanThrottleToleranceDc;
    UCHAR ForcedThrottleAc;
    UCHAR ForcedThrottleDc;
  } USER_POWER_POLICY,*PUSER_POWER_POLICY;

  typedef struct _POWER_POLICY{
    USER_POWER_POLICY user;
    MACHINE_POWER_POLICY mach;
  } POWER_POLICY,*PPOWER_POLICY;

#define EnableSysTrayBatteryMeter 0x01
#define EnableMultiBatteryDisplay 0x02
#define EnablePasswordLogon 0x04
#define EnableWakeOnRing 0x08
#define EnableVideoDimDisplay 0x10

#define NEWSCHEME (UINT)-1

  typedef BOOLEAN (CALLBACK *PWRSCHEMESENUMPROC)(UINT,DWORD,LPTSTR,DWORD,LPTSTR,PPOWER_POLICY,LPARAM);
  typedef BOOLEAN (CALLBACK *PFNNTINITIATEPWRACTION)(POWER_ACTION,SYSTEM_POWER_STATE,ULONG,BOOLEAN);

  BOOLEAN WINAPI GetPwrDiskSpindownRange(PUINT,PUINT);
  BOOLEAN WINAPI EnumPwrSchemes(PWRSCHEMESENUMPROC,LPARAM);
  BOOLEAN WINAPI ReadGlobalPwrPolicy(PGLOBAL_POWER_POLICY);
  BOOLEAN WINAPI ReadPwrScheme(UINT,PPOWER_POLICY);
  BOOLEAN WINAPI WritePwrScheme(PUINT,LPTSTR,LPTSTR,PPOWER_POLICY);
  BOOLEAN WINAPI WriteGlobalPwrPolicy(PGLOBAL_POWER_POLICY);
  BOOLEAN WINAPI DeletePwrScheme(UINT);
  BOOLEAN WINAPI GetActivePwrScheme(PUINT);
  BOOLEAN WINAPI SetActivePwrScheme(UINT,PGLOBAL_POWER_POLICY,PPOWER_POLICY);
  BOOLEAN WINAPI GetPwrCapabilities(PSYSTEM_POWER_CAPABILITIES);
  BOOLEAN WINAPI IsPwrSuspendAllowed(VOID);
  BOOLEAN WINAPI IsPwrHibernateAllowed(VOID);
  BOOLEAN WINAPI IsPwrShutdownAllowed(VOID);
  BOOLEAN WINAPI IsAdminOverrideActive(PADMINISTRATOR_POWER_POLICY);
  BOOLEAN WINAPI SetSuspendState(BOOLEAN,BOOLEAN,BOOLEAN);
  BOOLEAN WINAPI GetCurrentPowerPolicies(PGLOBAL_POWER_POLICY,PPOWER_POLICY);
  BOOLEAN WINAPI CanUserWritePwrScheme(VOID);
  BOOLEAN WINAPI ReadProcessorPwrScheme(UINT,PMACHINE_PROCESSOR_POWER_POLICY);
  BOOLEAN WINAPI WriteProcessorPwrScheme(UINT,PMACHINE_PROCESSOR_POWER_POLICY);
  BOOLEAN WINAPI ValidatePowerPolicies(PGLOBAL_POWER_POLICY,PPOWER_POLICY);
#ifndef NT_SUCCESS
#define NTSTATUS LONG
#define _OVERRIDE_NTSTATUS_
#endif

  NTSTATUS WINAPI CallNtPowerInformation(POWER_INFORMATION_LEVEL,PVOID,ULONG,PVOID,ULONG);

#ifdef _OVERRIDE_NTSTATUS_
#undef NTSTATUS
#endif

#ifdef __cplusplus
}
#endif
