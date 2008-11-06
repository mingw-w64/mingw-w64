/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINTERNL_
#define _WINTERNL_

#include <windef.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct _UNICODE_STRING {
    USHORT Length;
    USHORT MaximumLength;
    PWSTR Buffer;
  } UNICODE_STRING;

  typedef struct _PEB_LDR_DATA {
    BYTE Reserved1[8];
    PVOID Reserved2[3];
    LIST_ENTRY InMemoryOrderModuleList;
  } PEB_LDR_DATA,*PPEB_LDR_DATA;
 
  typedef struct _LDR_DATA_TABLE_ENTRY {
    BYTE Reserved1[2];
    LIST_ENTRY InMemoryOrderLinks;
    PVOID Reserved2[2];
    PVOID DllBase;
    PVOID Reserved3[2];
    UNICODE_STRING FullDllName;
    BYTE Reserved4[8];
    PVOID Reserved5[3];
    union {
      ULONG CheckSum;
      PVOID Reserved6;
    };
    ULONG TimeDateStamp;
  } LDR_DATA_TABLE_ENTRY,*PLDR_DATA_TABLE_ENTRY;

typedef struct _RTL_USER_PROCESS_PARAMETERS {
    BYTE Reserved1[16];
    PVOID Reserved2[10];
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
  } RTL_USER_PROCESS_PARAMETERS,*PRTL_USER_PROCESS_PARAMETERS;
  
  /* This function pointer is undocumented and just valid for windows 2000.
     Therefore I guess.  */
  typedef VOID (WINAPI *PPS_POST_PROCESS_INIT_ROUTINE)(VOID);
  
  typedef struct _PEB {
    BYTE Reserved1[2];
    BYTE BeingDebugged;
    BYTE Reserved2[1];
    PVOID Reserved3[2];
    PPEB_LDR_DATA Ldr;
    PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
    BYTE Reserved4[104];
    PVOID Reserved5[52];
    PPS_POST_PROCESS_INIT_ROUTINE PostProcessInitRoutine;
    BYTE Reserved6[128];
    PVOID Reserved7[1];
    ULONG SessionId;
  } PEB,*PPEB;

  typedef struct _TEB {
    BYTE Reserved1[1952];
    PVOID Reserved2[412];
    PVOID TlsSlots[64];
    BYTE Reserved3[8];
    PVOID Reserved4[26];
    PVOID ReservedForOle;
    PVOID Reserved5[4];
    PVOID TlsExpansionSlots;
  } TEB;

  typedef TEB *PTEB;
  typedef LONG NTSTATUS;
  typedef CONST char *PCSZ;

  typedef struct _STRING {
    USHORT Length;
    USHORT MaximumLength;
    PCHAR Buffer;
  } STRING;

  typedef STRING *PSTRING;
  typedef STRING ANSI_STRING;
  typedef PSTRING PANSI_STRING;
  typedef PSTRING PCANSI_STRING;
  typedef STRING OEM_STRING;
  typedef PSTRING POEM_STRING;
  typedef CONST STRING *PCOEM_STRING;

  typedef UNICODE_STRING *PUNICODE_STRING;
  typedef const UNICODE_STRING *PCUNICODE_STRING;

  typedef struct _OBJECT_ATTRIBUTES {
    ULONG Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG Attributes;
    PVOID SecurityDescriptor;
    PVOID SecurityQualityOfService;
  } OBJECT_ATTRIBUTES;

  typedef OBJECT_ATTRIBUTES *POBJECT_ATTRIBUTES;

  typedef struct _IO_STATUS_BLOCK {
    union {
      NTSTATUS Status;
      PVOID Pointer;
    };
    ULONG_PTR Information;
  } IO_STATUS_BLOCK,*PIO_STATUS_BLOCK;

  typedef VOID (NTAPI *PIO_APC_ROUTINE)(PVOID ApcContext,PIO_STATUS_BLOCK IoStatusBlock,ULONG Reserved);

#ifdef __ia64__
  typedef struct _FRAME_POINTERS {
    ULONGLONG MemoryStackFp;
    ULONGLONG BackingStoreFp;
  } FRAME_POINTERS,*PFRAME_POINTERS;

#define UNWIND_HISTORY_TABLE_SIZE 12

  typedef struct _RUNTIME_FUNCTION {
    ULONG BeginAddress;
    ULONG EndAddress;
    ULONG UnwindInfoAddress;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  typedef struct _UNWIND_HISTORY_TABLE_ENTRY {
    ULONG64 ImageBase;
    ULONG64 Gp;
    PRUNTIME_FUNCTION FunctionEntry;
  } UNWIND_HISTORY_TABLE_ENTRY,*PUNWIND_HISTORY_TABLE_ENTRY;

  typedef struct _UNWIND_HISTORY_TABLE {
    ULONG Count;
    UCHAR Search;
    ULONG64 LowAddress;
    ULONG64 HighAddress;
    UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
  } UNWIND_HISTORY_TABLE,*PUNWIND_HISTORY_TABLE;
#endif

  typedef struct _PROCESS_BASIC_INFORMATION {
    PVOID Reserved1;
    PPEB PebBaseAddress;
    PVOID Reserved2[2];
    ULONG_PTR UniqueProcessId;
    PVOID Reserved3;
  } PROCESS_BASIC_INFORMATION;

  typedef PROCESS_BASIC_INFORMATION *PPROCESS_BASIC_INFORMATION;

  typedef struct _SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION {
    LARGE_INTEGER IdleTime;
    LARGE_INTEGER KernelTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER Reserved1[2];
    ULONG Reserved2;
  } SYSTEM_PROCESSOR_PERFORMANCE_INFORMATION,*PSYSTEM_PROCESSOR_PERFORMANCE_INFORMATION;

  typedef struct _SYSTEM_PROCESS_INFORMATION {
    ULONG NextEntryOffset;
    BYTE Reserved1[52];
    PVOID Reserved2[3];
    HANDLE UniqueProcessId;
    PVOID Reserved3;
    ULONG HandleCount;
    BYTE Reserved4[4];
    PVOID Reserved5[11];
    SIZE_T PeakPagefileUsage;
    SIZE_T PrivatePageCount;
    LARGE_INTEGER Reserved6[6];
  } SYSTEM_PROCESS_INFORMATION,*PSYSTEM_PROCESS_INFORMATION;

  typedef struct _SYSTEM_REGISTRY_QUOTA_INFORMATION {
    ULONG RegistryQuotaAllowed;
    ULONG RegistryQuotaUsed;
    PVOID Reserved1;
  } SYSTEM_REGISTRY_QUOTA_INFORMATION,*PSYSTEM_REGISTRY_QUOTA_INFORMATION;

  typedef struct _SYSTEM_BASIC_INFORMATION {
    BYTE Reserved1[24];
    PVOID Reserved2[4];
    CCHAR NumberOfProcessors;
  } SYSTEM_BASIC_INFORMATION,*PSYSTEM_BASIC_INFORMATION;

  typedef struct _SYSTEM_TIMEOFDAY_INFORMATION {
    BYTE Reserved1[48];
  } SYSTEM_TIMEOFDAY_INFORMATION,*PSYSTEM_TIMEOFDAY_INFORMATION;

  typedef struct _SYSTEM_PERFORMANCE_INFORMATION {
    BYTE Reserved1[312];
  } SYSTEM_PERFORMANCE_INFORMATION,*PSYSTEM_PERFORMANCE_INFORMATION;

  typedef struct _SYSTEM_EXCEPTION_INFORMATION {
    BYTE Reserved1[16];
  } SYSTEM_EXCEPTION_INFORMATION,*PSYSTEM_EXCEPTION_INFORMATION;

  typedef struct _SYSTEM_LOOKASIDE_INFORMATION {
    BYTE Reserved1[32];
  } SYSTEM_LOOKASIDE_INFORMATION,*PSYSTEM_LOOKASIDE_INFORMATION;

  typedef struct _SYSTEM_INTERRUPT_INFORMATION {
    BYTE Reserved1[24];
  } SYSTEM_INTERRUPT_INFORMATION,*PSYSTEM_INTERRUPT_INFORMATION;

  typedef enum _FILE_INFORMATION_CLASS {
    FileDirectoryInformation = 1
  } FILE_INFORMATION_CLASS;

  typedef enum _PROCESSINFOCLASS {
    ProcessBasicInformation = 0,ProcessWow64Information = 26
  } PROCESSINFOCLASS;

  typedef enum _THREADINFOCLASS {
    ThreadIsIoPending = 16
  } THREADINFOCLASS;

  typedef enum _SYSTEM_INFORMATION_CLASS {
    SystemBasicInformation = 0,SystemPerformanceInformation = 2,SystemTimeOfDayInformation = 3,SystemProcessInformation = 5,
    SystemProcessorPerformanceInformation = 8,SystemInterruptInformation = 23,SystemExceptionInformation = 33,SystemRegistryQuotaInformation = 37,
    SystemLookasideInformation = 45
  } SYSTEM_INFORMATION_CLASS;

#define INTERNAL_TS_ACTIVE_CONSOLE_ID (*((volatile ULONG*)(0x7ffe02d8)))

#define RtlMoveMemory(Destination,Source,Length) memmove((Destination),(Source),(Length))
#define RtlFillMemory(Destination,Length,Fill) memset((Destination),(Fill),(Length))
#define RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))

  NTSTATUS NtClose(HANDLE Handle);
  NTSTATUS NtCreateFile(PHANDLE FileHandle,ACCESS_MASK DesiredAccess,POBJECT_ATTRIBUTES ObjectAttributes,PIO_STATUS_BLOCK IoStatusBlock,PLARGE_INTEGER AllocationSize,ULONG FileAttributes,ULONG ShareAccess,ULONG CreateDisposition,ULONG CreateOptions,PVOID EaBuffer,ULONG EaLength);
  NTSTATUS NtOpenFile(PHANDLE FileHandle,ACCESS_MASK DesiredAccess,POBJECT_ATTRIBUTES ObjectAttributes,PIO_STATUS_BLOCK IoStatusBlock,ULONG ShareAccess,ULONG OpenOptions);
  NTSTATUS NtDeviceIoControlFile(HANDLE FileHandle,HANDLE Event,PIO_APC_ROUTINE ApcRoutine,PVOID ApcContext,PIO_STATUS_BLOCK IoStatusBlock,ULONG IoControlCode,PVOID InputBuffer,ULONG InputBufferLength,PVOID OutputBuffer,ULONG OutputBufferLength);
  NTSTATUS NtWaitForSingleObject(HANDLE Handle,BOOLEAN Alertable,PLARGE_INTEGER Timeout);
  BOOLEAN RtlIsNameLegalDOS8Dot3(PUNICODE_STRING Name,POEM_STRING OemName,PBOOLEAN NameContainsSpaces);
  ULONG RtlNtStatusToDosError (NTSTATUS Status);
  NTSTATUS NtQueryInformationProcess(HANDLE ProcessHandle,PROCESSINFOCLASS ProcessInformationClass,PVOID ProcessInformation,ULONG ProcessInformationLength,PULONG ReturnLength);
  NTSTATUS NtQueryInformationThread(HANDLE ThreadHandle,THREADINFOCLASS ThreadInformationClass,PVOID ThreadInformation,ULONG ThreadInformationLength,PULONG ReturnLength);
  NTSTATUS NtQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass,PVOID SystemInformation,ULONG SystemInformationLength,PULONG ReturnLength);
  NTSTATUS NtQuerySystemTime(PLARGE_INTEGER SystemTime);
  NTSTATUS RtlLocalTimeToSystemTime(PLARGE_INTEGER LocalTime,PLARGE_INTEGER SystemTime);
  BOOLEAN RtlTimeToSecondsSince1970(PLARGE_INTEGER Time,PULONG ElapsedSeconds);
  VOID RtlFreeAnsiString(PANSI_STRING AnsiString);
  VOID RtlFreeUnicodeString(PUNICODE_STRING UnicodeString);
  VOID RtlFreeOemString(POEM_STRING OemString);
  VOID RtlInitString (PSTRING DestinationString,PCSZ SourceString);
  VOID RtlInitAnsiString(PANSI_STRING DestinationString,PCSZ SourceString);
  VOID RtlInitUnicodeString(PUNICODE_STRING DestinationString,PCWSTR SourceString);
  NTSTATUS RtlAnsiStringToUnicodeString(PUNICODE_STRING DestinationString,PCANSI_STRING SourceString,BOOLEAN AllocateDestinationString);
  NTSTATUS RtlUnicodeStringToAnsiString(PANSI_STRING DestinationString,PCUNICODE_STRING SourceString,BOOLEAN AllocateDestinationString);
  NTSTATUS RtlUnicodeStringToOemString(POEM_STRING DestinationString,PCUNICODE_STRING SourceString,BOOLEAN AllocateDestinationString);
  NTSTATUS RtlUnicodeToMultiByteSize(PULONG BytesInMultiByteString,PWCH UnicodeString,ULONG BytesInUnicodeString);
  NTSTATUS RtlCharToInteger (PCSZ String,ULONG Base,PULONG Value);
  NTSTATUS RtlConvertSidToUnicodeString(PUNICODE_STRING UnicodeString,PSID Sid,BOOLEAN AllocateDestinationString);
  ULONG RtlUniform(PULONG Seed);
  VOID RtlUnwind (PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue);

#ifdef __ia64__
  VOID RtlUnwind2(FRAME_POINTERS TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue,PCONTEXT ContextRecord);
  VOID RtlUnwindEx(FRAME_POINTERS TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue,PCONTEXT ContextRecord,PUNWIND_HISTORY_TABLE HistoryTable);
#endif

#define LOGONID_CURRENT ((ULONG)-1)
#define SERVERNAME_CURRENT ((HANDLE)NULL)

  typedef enum _WINSTATIONINFOCLASS {
    WinStationInformation = 8
  } WINSTATIONINFOCLASS;

  typedef struct _WINSTATIONINFORMATIONW {
    BYTE Reserved2[70];
    ULONG LogonId;
    BYTE Reserved3[1140];
  } WINSTATIONINFORMATIONW,*PWINSTATIONINFORMATIONW;

  typedef BOOLEAN (WINAPI *PWINSTATIONQUERYINFORMATIONW)(HANDLE,ULONG,WINSTATIONINFOCLASS,PVOID,ULONG,PULONG);

#ifdef __cplusplus
}
#endif

#endif
