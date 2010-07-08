/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _EVNTCONS_H_
#define _EVNTCONS_H_

#include <wmistr.h>
#include <evntrace.h>
#include <evntprov.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum EVENTSECURITYOPERATION {
  EventSecuritySetDACL,
  EventSecuritySetSACL,
  EventSecurityAddDACL,
  EventSecurityAddSACL,
  EventSecurityMax 
} EVENTSECURITYOPERATION;

typedef struct _EVENT_EXTENDED_ITEM_INSTANCE {
  ULONG InstanceId;
  ULONG ParentInstanceId;
  GUID  ParentGuid;
} EVENT_EXTENDED_ITEM_INSTANCE, *PEVENT_EXTENDED_ITEM_INSTANCE;

typedef struct _EVENT_EXTENDED_ITEM_TS_ID {
  ULONG SessionId;
} EVENT_EXTENDED_ITEM_TS_ID, *PEVENT_EXTENDED_ITEM_TS_ID;

typedef struct _EVENT_EXTENDED_ITEM_RELATED_ACTIVITYID {
  GUID RelatedActivityId;
} EVENT_EXTENDED_ITEM_RELATED_ACTIVITYID, *PEVENT_EXTENDED_ITEM_RELATED_ACTIVITYID;

typedef struct _EVENT_HEADER_EXTENDED_DATA_ITEM {
  USHORT    Reserved1;
  USHORT    ExtType;
  __MINGW_EXTENSION struct {
    USHORT Linkage   : 1;
    USHORT Reserved2 :15;
  } DUMMYSTRUCTNAME;
  USHORT    DataSize;
  ULONGLONG DataPtr;
} EVENT_HEADER_EXTENDED_DATA_ITEM, *PEVENT_HEADER_EXTENDED_DATA_ITEM;

typedef struct _EVENT_HEADER {
  USHORT           Size;
  USHORT           HeaderType;
  USHORT           Flags;
  USHORT           EventProperty;
  ULONG            ThreadId;
  ULONG            ProcessId;
  LARGE_INTEGER    TimeStamp;
  GUID             ProviderId;
  EVENT_DESCRIPTOR EventDescriptor;
  __MINGW_EXTENSION union {
    __MINGW_EXTENSION struct {
      ULONG KernelTime;
      ULONG UserTime;
    } DUMMYSTRUCTNAME;
    ULONG64 ProcessorTime;
  } DUMMYUNIONNAME;
  GUID             ActivityId;
} EVENT_HEADER, *PEVENT_HEADER;

/* FIXME:
 * Need EVENT_HEADER_PROPERTY_* and EVENT_HEADER_FLAG_* macros:
 * http://msdn.microsoft.com/en-us/library/aa363759(VS.85).aspx
 * Need the EVENT_HEADER_EXT_TYPE_* macros:
 * http://msdn.microsoft.com/en-us/library/aa363759(VS.85).aspx
 */

struct _EVENT_RECORD {
  EVENT_HEADER                     EventHeader;
  ETW_BUFFER_CONTEXT               BufferContext;
  USHORT                           ExtendedDataCount;
  USHORT                           UserDataLength;
  PEVENT_HEADER_EXTENDED_DATA_ITEM ExtendedData;
  PVOID                            UserData;
  PVOID                            UserContext;
};
#ifndef DEFINED_PEVENT_RECORD
typedef struct _EVENT_RECORD EVENT_RECORD, *PEVENT_RECORD;
#define DEFINED_PEVENT_RECORD		1
#endif	/* for  evntrace.h */

#if (_WIN32_WINNT >= 0x0601)
typedef struct _EVENT_EXTENDED_ITEM_STACK_TRACE32 {
  ULONG64 MatchId;
  ULONG   Address[ANYSIZE_ARRAY];
} EVENT_EXTENDED_ITEM_STACK_TRACE32, *PEVENT_EXTENDED_ITEM_STACK_TRACE32;

typedef struct _EVENT_EXTENDED_ITEM_STACK_TRACE64 {
  ULONG64 MatchId;
  ULONG64 Address[ANYSIZE_ARRAY];
} EVENT_EXTENDED_ITEM_STACK_TRACE64, *PEVENT_EXTENDED_ITEM_STACK_TRACE64;
#endif /*(_WIN32_WINNT >= 0x0601)*/

/* FIXME:
 * Need EVENT_ENABLE_PROPERTY_* macros:
 * http://msdn.microsoft.com/en-us/library/dd392306(VS.85).aspx
 * Need PROCESS_TRACE_MODE_* macros:
 * http://msdn.microsoft.com/en-us/library/aa363780(VS.85).aspx
 */

#if (_WIN32_WINNT >= 0x0600)
ULONG EVNTAPI EventAccessControl(
  LPGUID Guid,
  ULONG Operation,
  PSID Sid,
  ULONG Rights,
  BOOLEAN AllowOrDeny
);

ULONG EVNTAPI EventAccessQuery(
  LPGUID Guid,
  PSECURITY_DESCRIPTOR Buffer,
  PULONG BufferSize
);

ULONG EVNTAPI EventAccessRemove(
  LPGUID Guid
);
#endif /*(_WIN32_WINNT >= 0x0600)*/

#ifdef __cplusplus
}
#endif

#endif /* _EVNTCONS_H_ */

