/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _ADTGEN_H
#define _ADTGEN_H

#define AUDIT_TYPE_LEGACY 1
#define AUDIT_TYPE_WMI 2

typedef enum _AUDIT_PARAM_TYPE {
  APT_None = 1,
  APT_String,APT_Ulong,
  APT_Pointer,
  APT_Sid,
  APT_LogonId,
  APT_ObjectTypeList,
  APT_Luid,
  APT_Guid,
  APT_Time,
  APT_Int64
} AUDIT_PARAM_TYPE;

#define AP_ParamTypeBits 8
#define AP_ParamTypeMask __MSABI_LONG(0x000000ff)

#define AP_FormatHex (__MSABI_LONG(0x0001) << AP_ParamTypeBits)
#define AP_AccessMask (__MSABI_LONG(0x0002) << AP_ParamTypeBits)
#define AP_Filespec (__MSABI_LONG(0x0001) << AP_ParamTypeBits)
#define AP_PrimaryLogonId (__MSABI_LONG(0x0001) << AP_ParamTypeBits)
#define AP_ClientLogonId (__MSABI_LONG(0x0002) << AP_ParamTypeBits)

#define ApExtractType(TypeFlags) ((AUDIT_PARAM_TYPE)(TypeFlags & AP_ParamTypeMask))
#define ApExtractFlags(TypeFlags) ((TypeFlags & ~AP_ParamTypeMask))

typedef struct _AUDIT_OBJECT_TYPE {
  GUID ObjectType;
  USHORT Flags;
  USHORT Level;
  ACCESS_MASK AccessMask;
} AUDIT_OBJECT_TYPE,*PAUDIT_OBJECT_TYPE;

typedef struct _AUDIT_OBJECT_TYPES {
  USHORT Count;
  USHORT Flags;
  AUDIT_OBJECT_TYPE *pObjectTypes;
} AUDIT_OBJECT_TYPES,*PAUDIT_OBJECT_TYPES;

typedef struct _AUDIT_PARAM {
  AUDIT_PARAM_TYPE Type;
  ULONG Length;
  DWORD Flags;
  __C89_NAMELESS union {
    ULONG_PTR Data0;
    PWSTR String;
    ULONG_PTR u;
    SID *psid;
    GUID *pguid;
    ULONG LogonId_LowPart;
    AUDIT_OBJECT_TYPES *pObjectTypes;
  };
  __C89_NAMELESS union {
    ULONG_PTR Data1;
    LONG LogonId_HighPart;
  };
} AUDIT_PARAM,*PAUDIT_PARAM;

#define APF_AuditFailure 0x00000000
#define APF_AuditSuccess 0x00000001

#define APF_ValidFlags (APF_AuditSuccess)

typedef struct _AUDIT_PARAMS {
  ULONG Length;
  DWORD Flags;
  USHORT Count;
  AUDIT_PARAM *Parameters;
} AUDIT_PARAMS,*PAUDIT_PARAMS;

typedef struct _AUTHZ_AUDIT_EVENT_TYPE_LEGACY {
  USHORT CategoryId;
  USHORT AuditId;
  USHORT ParameterCount;
} AUTHZ_AUDIT_EVENT_TYPE_LEGACY,*PAUTHZ_AUDIT_EVENT_TYPE_LEGACY;

typedef union _AUTHZ_AUDIT_EVENT_TYPE_UNION {
  AUTHZ_AUDIT_EVENT_TYPE_LEGACY Legacy;
} AUTHZ_AUDIT_EVENT_TYPE_UNION,*PAUTHZ_AUDIT_EVENT_TYPE_UNION;

typedef struct _AUTHZ_AUDIT_EVENT_TYPE_OLD {
  ULONG Version;
  DWORD dwFlags;
  LONG RefCount;
  ULONG_PTR hAudit;
  LUID LinkId;
  AUTHZ_AUDIT_EVENT_TYPE_UNION u;
} AUTHZ_AUDIT_EVENT_TYPE_OLD;

typedef AUTHZ_AUDIT_EVENT_TYPE_OLD *PAUTHZ_AUDIT_EVENT_TYPE_OLD;
typedef PVOID AUDIT_HANDLE,*PAUDIT_HANDLE;

#define AUTHZ_ALLOW_MULTIPLE_SOURCE_INSTANCES 0x1
#define AUTHZ_AUDIT_INSTANCE_INFORMATION 0x2

#endif
