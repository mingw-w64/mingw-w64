/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __wbemcli_h__
#define __wbemcli_h__

#ifndef __IWbemClassObject_FWD_DEFINED__
#define __IWbemClassObject_FWD_DEFINED__
typedef struct IWbemClassObject IWbemClassObject;
#endif

#ifndef __IWbemObjectAccess_FWD_DEFINED__
#define __IWbemObjectAccess_FWD_DEFINED__
typedef struct IWbemObjectAccess IWbemObjectAccess;
#endif

#ifndef __IWbemQualifierSet_FWD_DEFINED__
#define __IWbemQualifierSet_FWD_DEFINED__
typedef struct IWbemQualifierSet IWbemQualifierSet;
#endif

#ifndef __IWbemServices_FWD_DEFINED__
#define __IWbemServices_FWD_DEFINED__
typedef struct IWbemServices IWbemServices;
#endif

#ifndef __IWbemLocator_FWD_DEFINED__
#define __IWbemLocator_FWD_DEFINED__
typedef struct IWbemLocator IWbemLocator;
#endif

#ifndef __IWbemObjectSink_FWD_DEFINED__
#define __IWbemObjectSink_FWD_DEFINED__
typedef struct IWbemObjectSink IWbemObjectSink;
#endif

#ifndef __IEnumWbemClassObject_FWD_DEFINED__
#define __IEnumWbemClassObject_FWD_DEFINED__
typedef struct IEnumWbemClassObject IEnumWbemClassObject;
#endif

#ifndef __IWbemCallResult_FWD_DEFINED__
#define __IWbemCallResult_FWD_DEFINED__
typedef struct IWbemCallResult IWbemCallResult;
#endif

#ifndef __IWbemContext_FWD_DEFINED__
#define __IWbemContext_FWD_DEFINED__
typedef struct IWbemContext IWbemContext;
#endif

#ifndef __IUnsecuredApartment_FWD_DEFINED__
#define __IUnsecuredApartment_FWD_DEFINED__
typedef struct IUnsecuredApartment IUnsecuredApartment;
#endif

#ifndef __IWbemUnsecuredApartment_FWD_DEFINED__
#define __IWbemUnsecuredApartment_FWD_DEFINED__
typedef struct IWbemUnsecuredApartment IWbemUnsecuredApartment;
#endif

#ifndef __IWbemStatusCodeText_FWD_DEFINED__
#define __IWbemStatusCodeText_FWD_DEFINED__
typedef struct IWbemStatusCodeText IWbemStatusCodeText;
#endif

#ifndef __IWbemBackupRestore_FWD_DEFINED__
#define __IWbemBackupRestore_FWD_DEFINED__
typedef struct IWbemBackupRestore IWbemBackupRestore;
#endif

#ifndef __IWbemBackupRestoreEx_FWD_DEFINED__
#define __IWbemBackupRestoreEx_FWD_DEFINED__
typedef struct IWbemBackupRestoreEx IWbemBackupRestoreEx;
#endif

#ifndef __IWbemRefresher_FWD_DEFINED__
#define __IWbemRefresher_FWD_DEFINED__
typedef struct IWbemRefresher IWbemRefresher;
#endif

#ifndef __IWbemHiPerfEnum_FWD_DEFINED__
#define __IWbemHiPerfEnum_FWD_DEFINED__
typedef struct IWbemHiPerfEnum IWbemHiPerfEnum;
#endif

#ifndef __IWbemConfigureRefresher_FWD_DEFINED__
#define __IWbemConfigureRefresher_FWD_DEFINED__
typedef struct IWbemConfigureRefresher IWbemConfigureRefresher;
#endif

#ifndef __WbemLocator_FWD_DEFINED__
#define __WbemLocator_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemLocator WbemLocator;
#else
typedef struct WbemLocator WbemLocator;
#endif
#endif

#ifndef __WbemContext_FWD_DEFINED__
#define __WbemContext_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemContext WbemContext;
#else
typedef struct WbemContext WbemContext;
#endif
#endif

#ifndef __UnsecuredApartment_FWD_DEFINED__
#define __UnsecuredApartment_FWD_DEFINED__
#ifdef __cplusplus
typedef class UnsecuredApartment UnsecuredApartment;
#else
typedef struct UnsecuredApartment UnsecuredApartment;
#endif
#endif

#ifndef __WbemClassObject_FWD_DEFINED__
#define __WbemClassObject_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemClassObject WbemClassObject;
#else
typedef struct WbemClassObject WbemClassObject;
#endif
#endif

#ifndef __MofCompiler_FWD_DEFINED__
#define __MofCompiler_FWD_DEFINED__
#ifdef __cplusplus
typedef class MofCompiler MofCompiler;
#else
typedef struct MofCompiler MofCompiler;
#endif
#endif

#ifndef __WbemStatusCodeText_FWD_DEFINED__
#define __WbemStatusCodeText_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemStatusCodeText WbemStatusCodeText;
#else
typedef struct WbemStatusCodeText WbemStatusCodeText;
#endif
#endif

#ifndef __WbemBackupRestore_FWD_DEFINED__
#define __WbemBackupRestore_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemBackupRestore WbemBackupRestore;
#else
typedef struct WbemBackupRestore WbemBackupRestore;
#endif
#endif

#ifndef __WbemRefresher_FWD_DEFINED__
#define __WbemRefresher_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemRefresher WbemRefresher;
#else
typedef struct WbemRefresher WbemRefresher;
#endif
#endif

#ifndef __WbemObjectTextSrc_FWD_DEFINED__
#define __WbemObjectTextSrc_FWD_DEFINED__
#ifdef __cplusplus
typedef class WbemObjectTextSrc WbemObjectTextSrc;
#else
typedef struct WbemObjectTextSrc WbemObjectTextSrc;
#endif
#endif

#ifndef __IWbemClassObject_FWD_DEFINED__
#define __IWbemClassObject_FWD_DEFINED__
typedef struct IWbemClassObject IWbemClassObject;
#endif

#ifndef __IWbemQualifierSet_FWD_DEFINED__
#define __IWbemQualifierSet_FWD_DEFINED__
typedef struct IWbemQualifierSet IWbemQualifierSet;
#endif

#ifndef __IWbemLocator_FWD_DEFINED__
#define __IWbemLocator_FWD_DEFINED__
typedef struct IWbemLocator IWbemLocator;
#endif

#ifndef __IWbemObjectSink_FWD_DEFINED__
#define __IWbemObjectSink_FWD_DEFINED__
typedef struct IWbemObjectSink IWbemObjectSink;
#endif

#ifndef __IEnumWbemClassObject_FWD_DEFINED__
#define __IEnumWbemClassObject_FWD_DEFINED__
typedef struct IEnumWbemClassObject IEnumWbemClassObject;
#endif

#ifndef __IWbemContext_FWD_DEFINED__
#define __IWbemContext_FWD_DEFINED__
typedef struct IWbemContext IWbemContext;
#endif

#ifndef __IWbemCallResult_FWD_DEFINED__
#define __IWbemCallResult_FWD_DEFINED__
typedef struct IWbemCallResult IWbemCallResult;
#endif

#ifndef __IWbemServices_FWD_DEFINED__
#define __IWbemServices_FWD_DEFINED__
typedef struct IWbemServices IWbemServices;
#endif

#ifndef __IWbemShutdown_FWD_DEFINED__
#define __IWbemShutdown_FWD_DEFINED__
typedef struct IWbemShutdown IWbemShutdown;
#endif

#ifndef __IWbemObjectTextSrc_FWD_DEFINED__
#define __IWbemObjectTextSrc_FWD_DEFINED__
typedef struct IWbemObjectTextSrc IWbemObjectTextSrc;
#endif

#ifndef __IWbemObjectAccess_FWD_DEFINED__
#define __IWbemObjectAccess_FWD_DEFINED__
typedef struct IWbemObjectAccess IWbemObjectAccess;
#endif

#ifndef __IMofCompiler_FWD_DEFINED__
#define __IMofCompiler_FWD_DEFINED__
typedef struct IMofCompiler IMofCompiler;
#endif

#ifndef __IUnsecuredApartment_FWD_DEFINED__
#define __IUnsecuredApartment_FWD_DEFINED__
typedef struct IUnsecuredApartment IUnsecuredApartment;
#endif

#ifndef __IWbemUnsecuredApartment_FWD_DEFINED__
#define __IWbemUnsecuredApartment_FWD_DEFINED__
typedef struct IWbemUnsecuredApartment IWbemUnsecuredApartment;
#endif

#ifndef __IWbemStatusCodeText_FWD_DEFINED__
#define __IWbemStatusCodeText_FWD_DEFINED__
typedef struct IWbemStatusCodeText IWbemStatusCodeText;
#endif

#ifndef __IWbemBackupRestore_FWD_DEFINED__
#define __IWbemBackupRestore_FWD_DEFINED__
typedef struct IWbemBackupRestore IWbemBackupRestore;
#endif

#ifndef __IWbemBackupRestoreEx_FWD_DEFINED__
#define __IWbemBackupRestoreEx_FWD_DEFINED__
typedef struct IWbemBackupRestoreEx IWbemBackupRestoreEx;
#endif

#ifndef __IWbemRefresher_FWD_DEFINED__
#define __IWbemRefresher_FWD_DEFINED__
typedef struct IWbemRefresher IWbemRefresher;
#endif

#ifndef __IWbemHiPerfEnum_FWD_DEFINED__
#define __IWbemHiPerfEnum_FWD_DEFINED__
typedef struct IWbemHiPerfEnum IWbemHiPerfEnum;
#endif

#ifndef __IWbemConfigureRefresher_FWD_DEFINED__
#define __IWbemConfigureRefresher_FWD_DEFINED__
typedef struct IWbemConfigureRefresher IWbemConfigureRefresher;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#ifndef __WbemClient_v1_LIBRARY_DEFINED__
#define __WbemClient_v1_LIBRARY_DEFINED__

  typedef enum tag_WBEM_GENUS_TYPE {
    WBEM_GENUS_CLASS = 1,WBEM_GENUS_INSTANCE = 2
  } WBEM_GENUS_TYPE;

  typedef enum tag_WBEM_CHANGE_FLAG_TYPE {
    WBEM_FLAG_CREATE_OR_UPDATE = 0,WBEM_FLAG_UPDATE_ONLY = 0x1,WBEM_FLAG_CREATE_ONLY = 0x2,WBEM_FLAG_UPDATE_COMPATIBLE = 0,
    WBEM_FLAG_UPDATE_SAFE_MODE = 0x20,WBEM_FLAG_UPDATE_FORCE_MODE = 0x40,WBEM_MASK_UPDATE_MODE = 0x60,WBEM_FLAG_ADVISORY = 0x10000
  } WBEM_CHANGE_FLAG_TYPE;

  typedef enum tag_WBEM_GENERIC_FLAG_TYPE {
    WBEM_FLAG_RETURN_IMMEDIATELY = 0x10,WBEM_FLAG_RETURN_WBEM_COMPLETE = 0,WBEM_FLAG_BIDIRECTIONAL = 0,WBEM_FLAG_FORWARD_ONLY = 0x20,
    WBEM_FLAG_NO_ERROR_OBJECT = 0x40,WBEM_FLAG_RETURN_ERROR_OBJECT = 0,WBEM_FLAG_SEND_STATUS = 0x80,WBEM_FLAG_DONT_SEND_STATUS = 0,
    WBEM_FLAG_ENSURE_LOCATABLE = 0x100,WBEM_FLAG_DIRECT_READ = 0x200,WBEM_FLAG_SEND_ONLY_SELECTED = 0,WBEM_RETURN_WHEN_COMPLETE = 0,
    WBEM_RETURN_IMMEDIATELY = 0x10,WBEM_MASK_RESERVED_FLAGS = 0x1f000,WBEM_FLAG_USE_AMENDED_QUALIFIERS = 0x20000,
    WBEM_FLAG_STRONG_VALIDATION = 0x100000
  } WBEM_GENERIC_FLAG_TYPE;

  typedef enum tag_WBEM_STATUS_TYPE {
    WBEM_STATUS_COMPLETE = 0,WBEM_STATUS_REQUIREMENTS = 1,WBEM_STATUS_PROGRESS = 2
  } WBEM_STATUS_TYPE;

  typedef enum tag_WBEM_TIMEOUT_TYPE {
    WBEM_NO_WAIT = 0,WBEM_INFINITE = 0xffffffff
  } WBEM_TIMEOUT_TYPE;

  typedef enum tag_WBEM_CONDITION_FLAG_TYPE {
    WBEM_FLAG_ALWAYS = 0,WBEM_FLAG_ONLY_IF_TRUE = 0x1,WBEM_FLAG_ONLY_IF_FALSE = 0x2,WBEM_FLAG_ONLY_IF_IDENTICAL = 0x3,WBEM_MASK_PRIMARY_CONDITION = 0x3,
    WBEM_FLAG_KEYS_ONLY = 0x4,WBEM_FLAG_REFS_ONLY = 0x8,WBEM_FLAG_LOCAL_ONLY = 0x10,WBEM_FLAG_PROPAGATED_ONLY = 0x20,WBEM_FLAG_SYSTEM_ONLY = 0x30,
    WBEM_FLAG_NONSYSTEM_ONLY = 0x40,WBEM_MASK_CONDITION_ORIGIN = 0x70,WBEM_FLAG_CLASS_OVERRIDES_ONLY = 0x100,WBEM_FLAG_CLASS_LOCAL_AND_OVERRIDES = 0x200,
    WBEM_MASK_CLASS_CONDITION = 0x300
  } WBEM_CONDITION_FLAG_TYPE;

  typedef enum tag_WBEM_FLAVOR_TYPE {
    WBEM_FLAVOR_DONT_PROPAGATE = 0,WBEM_FLAVOR_FLAG_PROPAGATE_TO_INSTANCE = 0x1,WBEM_FLAVOR_FLAG_PROPAGATE_TO_DERIVED_CLASS = 0x2,
    WBEM_FLAVOR_MASK_PROPAGATION = 0xf,WBEM_FLAVOR_OVERRIDABLE = 0,WBEM_FLAVOR_NOT_OVERRIDABLE = 0x10,WBEM_FLAVOR_MASK_PERMISSIONS = 0x10,
    WBEM_FLAVOR_ORIGIN_LOCAL = 0,WBEM_FLAVOR_ORIGIN_PROPAGATED = 0x20,WBEM_FLAVOR_ORIGIN_SYSTEM = 0x40,WBEM_FLAVOR_MASK_ORIGIN = 0x60,
    WBEM_FLAVOR_NOT_AMENDED = 0,WBEM_FLAVOR_AMENDED = 0x80,WBEM_FLAVOR_MASK_AMENDED = 0x80
  } WBEM_FLAVOR_TYPE;

  typedef enum tag_WBEM_QUERY_FLAG_TYPE {
    WBEM_FLAG_DEEP = 0,WBEM_FLAG_SHALLOW = 1,WBEM_FLAG_PROTOTYPE = 2
  } WBEM_QUERY_FLAG_TYPE;

  typedef enum tag_WBEM_SECURITY_FLAGS {
    WBEM_ENABLE = 1,WBEM_METHOD_EXECUTE = 2,WBEM_FULL_WRITE_REP = 4,WBEM_PARTIAL_WRITE_REP = 8,WBEM_WRITE_PROVIDER = 0x10,WBEM_REMOTE_ACCESS = 0x20,
    WBEM_RIGHT_SUBSCRIBE = 0x40,WBEM_RIGHT_PUBLISH = 0x80
  } WBEM_SECURITY_FLAGS;

  typedef enum tag_WBEM_LIMITATION_FLAG_TYPE {
    WBEM_FLAG_EXCLUDE_OBJECT_QUALIFIERS = 0x10,WBEM_FLAG_EXCLUDE_PROPERTY_QUALIFIERS = 0x20
  } WBEM_LIMITATION_FLAG_TYPE;

  typedef enum tag_WBEM_TEXT_FLAG_TYPE {
    WBEM_FLAG_NO_FLAVORS = 0x1
  } WBEM_TEXT_FLAG_TYPE;

  typedef enum tag_WBEM_COMPARISON_FLAG {
    WBEM_COMPARISON_INCLUDE_ALL = 0,WBEM_FLAG_IGNORE_QUALIFIERS = 0x1,WBEM_FLAG_IGNORE_OBJECT_SOURCE = 0x2,WBEM_FLAG_IGNORE_DEFAULT_VALUES = 0x4,
    WBEM_FLAG_IGNORE_CLASS = 0x8,WBEM_FLAG_IGNORE_CASE = 0x10,WBEM_FLAG_IGNORE_FLAVOR = 0x20
  } WBEM_COMPARISON_FLAG;

  typedef enum tag_WBEM_LOCKING {
    WBEM_FLAG_ALLOW_READ = 0x1
  } WBEM_LOCKING_FLAG_TYPE;

  typedef enum tag_CIMTYPE_ENUMERATION {
    CIM_ILLEGAL = 0xfff,CIM_EMPTY = 0,CIM_SINT8 = 16,CIM_UINT8 = 17,CIM_SINT16 = 2,CIM_UINT16 = 18,CIM_SINT32 = 3,CIM_UINT32 = 19,CIM_SINT64 = 20,
    CIM_UINT64 = 21,CIM_REAL32 = 4,CIM_REAL64 = 5,CIM_BOOLEAN = 11,CIM_STRING = 8,CIM_DATETIME = 101,CIM_REFERENCE = 102,CIM_CHAR16 = 103,
    CIM_OBJECT = 13,CIM_FLAG_ARRAY = 0x2000
  } CIMTYPE_ENUMERATION;

  typedef enum tag_WBEM_BACKUP_RESTORE_FLAGS {
    WBEM_FLAG_BACKUP_RESTORE_DEFAULT = 0,WBEM_FLAG_BACKUP_RESTORE_FORCE_SHUTDOWN = 1
  } WBEM_BACKUP_RESTORE_FLAGS;

  typedef enum tag_WBEM_REFRESHER_FLAGS {
    WBEM_FLAG_REFRESH_AUTO_RECONNECT = 0,WBEM_FLAG_REFRESH_NO_AUTO_RECONNECT = 1
  } WBEM_REFRESHER_FLAGS;

  typedef enum tag_WBEM_SHUTDOWN_FLAGS {
    WBEM_SHUTDOWN_UNLOAD_COMPONENT = 1,WBEM_SHUTDOWN_WMI = 2,WBEM_SHUTDOWN_OS = 3
  } WBEM_SHUTDOWN_FLAGS;

  typedef long CIMTYPE;

  typedef enum tag_WBEMSTATUS_FORMAT {
    WBEMSTATUS_FORMAT_NEWLINE = 0,WBEMSTATUS_FORMAT_NO_NEWLINE = 1
  } WBEMSTATUS_FORMAT;

  typedef enum tag_WBEM_LIMITS {
    WBEM_MAX_IDENTIFIER = 0x1000,WBEM_MAX_QUERY = 0x4000,WBEM_MAX_PATH = 0x2000,WBEM_MAX_OBJECT_NESTING = 64,WBEM_MAX_USER_PROPERTIES = 1024
  } WBEM_LIMITS;

  typedef enum tag_WBEMSTATUS {
    WBEM_NO_ERROR = 0,WBEM_S_NO_ERROR = 0,WBEM_S_SAME = 0,WBEM_S_FALSE = 1,WBEM_S_ALREADY_EXISTS = 0x40001,WBEM_S_RESET_TO_DEFAULT = 0x40002,
    WBEM_S_DIFFERENT = 0x40003,WBEM_S_TIMEDOUT = 0x40004,WBEM_S_NO_MORE_DATA = 0x40005,WBEM_S_OPERATION_CANCELLED = 0x40006,WBEM_S_PENDING = 0x40007,
    WBEM_S_DUPLICATE_OBJECTS = 0x40008,WBEM_S_ACCESS_DENIED = 0x40009,WBEM_S_PARTIAL_RESULTS = 0x40010,WBEM_S_SOURCE_NOT_AVAILABLE = 0x40017,
    WBEM_E_FAILED = 0x80041001,WBEM_E_NOT_FOUND = 0x80041002,WBEM_E_ACCESS_DENIED = 0x80041003,WBEM_E_PROVIDER_FAILURE = 0x80041004,
    WBEM_E_TYPE_MISMATCH = 0x80041005,WBEM_E_OUT_OF_MEMORY = 0x80041006,WBEM_E_INVALID_CONTEXT = 0x80041007,WBEM_E_INVALID_PARAMETER = 0x80041008,
    WBEM_E_NOT_AVAILABLE = 0x80041009,WBEM_E_CRITICAL_ERROR = 0x8004100a,WBEM_E_INVALID_STREAM = 0x8004100b,WBEM_E_NOT_SUPPORTED = 0x8004100c,
    WBEM_E_INVALID_SUPERCLASS = 0x8004100d,WBEM_E_INVALID_NAMESPACE = 0x8004100e,WBEM_E_INVALID_OBJECT = 0x8004100f,WBEM_E_INVALID_CLASS = 0x80041010,
    WBEM_E_PROVIDER_NOT_FOUND = 0x80041011,WBEM_E_INVALID_PROVIDER_REGISTRATION = 0x80041012,WBEM_E_PROVIDER_LOAD_FAILURE = 0x80041013,
    WBEM_E_INITIALIZATION_FAILURE = 0x80041014,WBEM_E_TRANSPORT_FAILURE = 0x80041015,WBEM_E_INVALID_OPERATION = 0x80041016,
    WBEM_E_INVALID_QUERY = 0x80041017,WBEM_E_INVALID_QUERY_TYPE = 0x80041018,WBEM_E_ALREADY_EXISTS = 0x80041019,WBEM_E_OVERRIDE_NOT_ALLOWED = 0x8004101a,
    WBEM_E_PROPAGATED_QUALIFIER = 0x8004101b,WBEM_E_PROPAGATED_PROPERTY = 0x8004101c,WBEM_E_UNEXPECTED = 0x8004101d,WBEM_E_ILLEGAL_OPERATION = 0x8004101e,
    WBEM_E_CANNOT_BE_KEY = 0x8004101f,WBEM_E_INCOMPLETE_CLASS = 0x80041020,WBEM_E_INVALID_SYNTAX = 0x80041021,WBEM_E_NONDECORATED_OBJECT = 0x80041022,
    WBEM_E_READ_ONLY = 0x80041023,WBEM_E_PROVIDER_NOT_CAPABLE = 0x80041024,WBEM_E_CLASS_HAS_CHILDREN = 0x80041025,
    WBEM_E_CLASS_HAS_INSTANCES = 0x80041026,WBEM_E_QUERY_NOT_IMPLEMENTED = 0x80041027,WBEM_E_ILLEGAL_NULL = 0x80041028,
    WBEM_E_INVALID_QUALIFIER_TYPE = 0x80041029,WBEM_E_INVALID_PROPERTY_TYPE = 0x8004102a,WBEM_E_VALUE_OUT_OF_RANGE = 0x8004102b,
    WBEM_E_CANNOT_BE_SINGLETON = 0x8004102c,WBEM_E_INVALID_CIM_TYPE = 0x8004102d,WBEM_E_INVALID_METHOD = 0x8004102e,
    WBEM_E_INVALID_METHOD_PARAMETERS = 0x8004102f,WBEM_E_SYSTEM_PROPERTY = 0x80041030,WBEM_E_INVALID_PROPERTY = 0x80041031,
    WBEM_E_CALL_CANCELLED = 0x80041032,WBEM_E_SHUTTING_DOWN = 0x80041033,WBEM_E_PROPAGATED_METHOD = 0x80041034,
    WBEM_E_UNSUPPORTED_PARAMETER = 0x80041035,WBEM_E_MISSING_PARAMETER_ID = 0x80041036,WBEM_E_INVALID_PARAMETER_ID = 0x80041037,
    WBEM_E_NONCONSECUTIVE_PARAMETER_IDS = 0x80041038,WBEM_E_PARAMETER_ID_ON_RETVAL = 0x80041039,WBEM_E_INVALID_OBJECT_PATH = 0x8004103a,
    WBEM_E_OUT_OF_DISK_SPACE = 0x8004103b,WBEM_E_BUFFER_TOO_SMALL = 0x8004103c,WBEM_E_UNSUPPORTED_PUT_EXTENSION = 0x8004103d,
    WBEM_E_UNKNOWN_OBJECT_TYPE = 0x8004103e,WBEM_E_UNKNOWN_PACKET_TYPE = 0x8004103f,WBEM_E_MARSHAL_VERSION_MISMATCH = 0x80041040,
    WBEM_E_MARSHAL_INVALID_SIGNATURE = 0x80041041,WBEM_E_INVALID_QUALIFIER = 0x80041042,WBEM_E_INVALID_DUPLICATE_PARAMETER = 0x80041043,
    WBEM_E_TOO_MUCH_DATA = 0x80041044,WBEM_E_SERVER_TOO_BUSY = 0x80041045,WBEM_E_INVALID_FLAVOR = 0x80041046,WBEM_E_CIRCULAR_REFERENCE = 0x80041047,
    WBEM_E_UNSUPPORTED_CLASS_UPDATE = 0x80041048,WBEM_E_CANNOT_CHANGE_KEY_INHERITANCE = 0x80041049,WBEM_E_CANNOT_CHANGE_INDEX_INHERITANCE = 0x80041050,
    WBEM_E_TOO_MANY_PROPERTIES = 0x80041051,WBEM_E_UPDATE_TYPE_MISMATCH = 0x80041052,WBEM_E_UPDATE_OVERRIDE_NOT_ALLOWED = 0x80041053,
    WBEM_E_UPDATE_PROPAGATED_METHOD = 0x80041054,WBEM_E_METHOD_NOT_IMPLEMENTED = 0x80041055,WBEM_E_METHOD_DISABLED = 0x80041056,
    WBEM_E_REFRESHER_BUSY = 0x80041057,WBEM_E_UNPARSABLE_QUERY = 0x80041058,WBEM_E_NOT_EVENT_CLASS = 0x80041059,WBEM_E_MISSING_GROUP_WITHIN = 0x8004105a,
    WBEM_E_MISSING_AGGREGATION_LIST = 0x8004105b,WBEM_E_PROPERTY_NOT_AN_OBJECT = 0x8004105c,WBEM_E_AGGREGATING_BY_OBJECT = 0x8004105d,
    WBEM_E_UNINTERPRETABLE_PROVIDER_QUERY = 0x8004105f,WBEM_E_BACKUP_RESTORE_WINMGMT_RUNNING = 0x80041060,WBEM_E_QUEUE_OVERFLOW = 0x80041061,
    WBEM_E_PRIVILEGE_NOT_HELD = 0x80041062,WBEM_E_INVALID_OPERATOR = 0x80041063,WBEM_E_LOCAL_CREDENTIALS = 0x80041064,
    WBEM_E_CANNOT_BE_ABSTRACT = 0x80041065,WBEM_E_AMENDED_OBJECT = 0x80041066,WBEM_E_CLIENT_TOO_SLOW = 0x80041067,
    WBEM_E_NULL_SECURITY_DESCRIPTOR = 0x80041068,WBEM_E_TIMED_OUT = 0x80041069,WBEM_E_INVALID_ASSOCIATION = 0x8004106a,
    WBEM_E_AMBIGUOUS_OPERATION = 0x8004106b,WBEM_E_QUOTA_VIOLATION = 0x8004106c,WBEM_E_RESERVED_001 = 0x8004106d,WBEM_E_RESERVED_002 = 0x8004106e,
    WBEM_E_UNSUPPORTED_LOCALE = 0x8004106f,WBEM_E_HANDLE_OUT_OF_DATE = 0x80041070,WBEM_E_CONNECTION_FAILED = 0x80041071,
    WBEM_E_INVALID_HANDLE_REQUEST = 0x80041072,WBEM_E_PROPERTY_NAME_TOO_WIDE = 0x80041073,WBEM_E_CLASS_NAME_TOO_WIDE = 0x80041074,
    WBEM_E_METHOD_NAME_TOO_WIDE = 0x80041075,WBEM_E_QUALIFIER_NAME_TOO_WIDE = 0x80041076,WBEM_E_RERUN_COMMAND = 0x80041077,
    WBEM_E_DATABASE_VER_MISMATCH = 0x80041078,WBEM_E_VETO_DELETE = 0x80041079,WBEM_E_VETO_PUT = 0x8004107a,WBEM_E_INVALID_LOCALE = 0x80041080,
    WBEM_E_PROVIDER_SUSPENDED = 0x80041081,WBEM_E_SYNCHRONIZATION_REQUIRED = 0x80041082,WBEM_E_NO_SCHEMA = 0x80041083,
    WBEM_E_PROVIDER_ALREADY_REGISTERED = 0x80041084,WBEM_E_PROVIDER_NOT_REGISTERED = 0x80041085,WBEM_E_FATAL_TRANSPORT_ERROR = 0x80041086,
    WBEM_E_ENCRYPTED_CONNECTION_REQUIRED = 0x80041087,WBEM_E_PROVIDER_TIMED_OUT = 0x80041088,WBEM_E_NO_KEY = 0x80041089,
    WBEM_E_PROVIDER_DISABLED = 0x8004108a,WBEMESS_E_REGISTRATION_TOO_BROAD = 0x80042001,WBEMESS_E_REGISTRATION_TOO_PRECISE = 0x80042002,
    WBEMESS_E_AUTHZ_NOT_PRIVILEGED = 0x80042003,WBEMMOF_E_EXPECTED_QUALIFIER_NAME = 0x80044001,WBEMMOF_E_EXPECTED_SEMI = 0x80044002,
    WBEMMOF_E_EXPECTED_OPEN_BRACE = 0x80044003,WBEMMOF_E_EXPECTED_CLOSE_BRACE = 0x80044004,WBEMMOF_E_EXPECTED_CLOSE_BRACKET = 0x80044005,
    WBEMMOF_E_EXPECTED_CLOSE_PAREN = 0x80044006,WBEMMOF_E_ILLEGAL_CONSTANT_VALUE = 0x80044007,WBEMMOF_E_EXPECTED_TYPE_IDENTIFIER = 0x80044008,
    WBEMMOF_E_EXPECTED_OPEN_PAREN = 0x80044009,WBEMMOF_E_UNRECOGNIZED_TOKEN = 0x8004400a,WBEMMOF_E_UNRECOGNIZED_TYPE = 0x8004400b,
    WBEMMOF_E_EXPECTED_PROPERTY_NAME = 0x8004400c,WBEMMOF_E_TYPEDEF_NOT_SUPPORTED = 0x8004400d,WBEMMOF_E_UNEXPECTED_ALIAS = 0x8004400e,
    WBEMMOF_E_UNEXPECTED_ARRAY_INIT = 0x8004400f,WBEMMOF_E_INVALID_AMENDMENT_SYNTAX = 0x80044010,WBEMMOF_E_INVALID_DUPLICATE_AMENDMENT = 0x80044011,
    WBEMMOF_E_INVALID_PRAGMA = 0x80044012,WBEMMOF_E_INVALID_NAMESPACE_SYNTAX = 0x80044013,WBEMMOF_E_EXPECTED_CLASS_NAME = 0x80044014,
    WBEMMOF_E_TYPE_MISMATCH = 0x80044015,WBEMMOF_E_EXPECTED_ALIAS_NAME = 0x80044016,WBEMMOF_E_INVALID_CLASS_DECLARATION = 0x80044017,
    WBEMMOF_E_INVALID_INSTANCE_DECLARATION = 0x80044018,WBEMMOF_E_EXPECTED_DOLLAR = 0x80044019,WBEMMOF_E_CIMTYPE_QUALIFIER = 0x8004401a,
    WBEMMOF_E_DUPLICATE_PROPERTY = 0x8004401b,WBEMMOF_E_INVALID_NAMESPACE_SPECIFICATION = 0x8004401c,WBEMMOF_E_OUT_OF_RANGE = 0x8004401d,
    WBEMMOF_E_INVALID_FILE = 0x8004401e,WBEMMOF_E_ALIASES_IN_EMBEDDED = 0x8004401f,WBEMMOF_E_NULL_ARRAY_ELEM = 0x80044020,
    WBEMMOF_E_DUPLICATE_QUALIFIER = 0x80044021,WBEMMOF_E_EXPECTED_FLAVOR_TYPE = 0x80044022,WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES = 0x80044023,
    WBEMMOF_E_MULTIPLE_ALIASES = 0x80044024,WBEMMOF_E_INCOMPATIBLE_FLAVOR_TYPES2 = 0x80044025,WBEMMOF_E_NO_ARRAYS_RETURNED = 0x80044026,
    WBEMMOF_E_MUST_BE_IN_OR_OUT = 0x80044027,WBEMMOF_E_INVALID_FLAGS_SYNTAX = 0x80044028,WBEMMOF_E_EXPECTED_BRACE_OR_BAD_TYPE = 0x80044029,
    WBEMMOF_E_UNSUPPORTED_CIMV22_QUAL_VALUE = 0x8004402a,WBEMMOF_E_UNSUPPORTED_CIMV22_DATA_TYPE = 0x8004402b,
    WBEMMOF_E_INVALID_DELETEINSTANCE_SYNTAX = 0x8004402c,WBEMMOF_E_INVALID_QUALIFIER_SYNTAX = 0x8004402d,
    WBEMMOF_E_QUALIFIER_USED_OUTSIDE_SCOPE = 0x8004402e,WBEMMOF_E_ERROR_CREATING_TEMP_FILE = 0x8004402f,
    WBEMMOF_E_ERROR_INVALID_INCLUDE_FILE = 0x80044030,WBEMMOF_E_INVALID_DELETECLASS_SYNTAX = 0x80044031
  } WBEMSTATUS;

  EXTERN_C const IID LIBID_WbemClient_v1;
#ifndef __IWbemClassObject_INTERFACE_DEFINED__
#define __IWbemClassObject_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemClassObject;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemClassObject : public IUnknown {
  public:
    virtual HRESULT WINAPI GetQualifierSet(IWbemQualifierSet **ppQualSet) = 0;
    virtual HRESULT WINAPI Get(LPCWSTR wszName,long lFlags,VARIANT *pVal,CIMTYPE *pType,long *plFlavor) = 0;
    virtual HRESULT WINAPI Put(LPCWSTR wszName,long lFlags,VARIANT *pVal,CIMTYPE Type) = 0;
    virtual HRESULT WINAPI Delete(LPCWSTR wszName) = 0;
    virtual HRESULT WINAPI GetNames(LPCWSTR wszQualifierName,long lFlags,VARIANT *pQualifierVal,SAFEARRAY **pNames) = 0;
    virtual HRESULT WINAPI BeginEnumeration(long lEnumFlags) = 0;
    virtual HRESULT WINAPI Next(long lFlags,BSTR *strName,VARIANT *pVal,CIMTYPE *pType,long *plFlavor) = 0;
    virtual HRESULT WINAPI EndEnumeration(void) = 0;
    virtual HRESULT WINAPI GetPropertyQualifierSet(LPCWSTR wszProperty,IWbemQualifierSet **ppQualSet) = 0;
    virtual HRESULT WINAPI Clone(IWbemClassObject **ppCopy) = 0;
    virtual HRESULT WINAPI GetObjectText(long lFlags,BSTR *pstrObjectText) = 0;
    virtual HRESULT WINAPI SpawnDerivedClass(long lFlags,IWbemClassObject **ppNewClass) = 0;
    virtual HRESULT WINAPI SpawnInstance(long lFlags,IWbemClassObject **ppNewInstance) = 0;
    virtual HRESULT WINAPI CompareTo(long lFlags,IWbemClassObject *pCompareTo) = 0;
    virtual HRESULT WINAPI GetPropertyOrigin(LPCWSTR wszName,BSTR *pstrClassName) = 0;
    virtual HRESULT WINAPI InheritsFrom(LPCWSTR strAncestor) = 0;
    virtual HRESULT WINAPI GetMethod(LPCWSTR wszName,long lFlags,IWbemClassObject **ppInSignature,IWbemClassObject **ppOutSignature) = 0;
    virtual HRESULT WINAPI PutMethod(LPCWSTR wszName,long lFlags,IWbemClassObject *pInSignature,IWbemClassObject *pOutSignature) = 0;
    virtual HRESULT WINAPI DeleteMethod(LPCWSTR wszName) = 0;
    virtual HRESULT WINAPI BeginMethodEnumeration(long lEnumFlags) = 0;
    virtual HRESULT WINAPI NextMethod(long lFlags,BSTR *pstrName,IWbemClassObject **ppInSignature,IWbemClassObject **ppOutSignature) = 0;
    virtual HRESULT WINAPI EndMethodEnumeration(void) = 0;
    virtual HRESULT WINAPI GetMethodQualifierSet(LPCWSTR wszMethod,IWbemQualifierSet **ppQualSet) = 0;
    virtual HRESULT WINAPI GetMethodOrigin(LPCWSTR wszMethodName,BSTR *pstrClassName) = 0;
  };
#else
  typedef struct IWbemClassObjectVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemClassObject *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemClassObject *This);
      ULONG (WINAPI *Release)(IWbemClassObject *This);
      HRESULT (WINAPI *GetQualifierSet)(IWbemClassObject *This,IWbemQualifierSet **ppQualSet);
      HRESULT (WINAPI *Get)(IWbemClassObject *This,LPCWSTR wszName,long lFlags,VARIANT *pVal,CIMTYPE *pType,long *plFlavor);
      HRESULT (WINAPI *Put)(IWbemClassObject *This,LPCWSTR wszName,long lFlags,VARIANT *pVal,CIMTYPE Type);
      HRESULT (WINAPI *Delete)(IWbemClassObject *This,LPCWSTR wszName);
      HRESULT (WINAPI *GetNames)(IWbemClassObject *This,LPCWSTR wszQualifierName,long lFlags,VARIANT *pQualifierVal,SAFEARRAY **pNames);
      HRESULT (WINAPI *BeginEnumeration)(IWbemClassObject *This,long lEnumFlags);
      HRESULT (WINAPI *Next)(IWbemClassObject *This,long lFlags,BSTR *strName,VARIANT *pVal,CIMTYPE *pType,long *plFlavor);
      HRESULT (WINAPI *EndEnumeration)(IWbemClassObject *This);
      HRESULT (WINAPI *GetPropertyQualifierSet)(IWbemClassObject *This,LPCWSTR wszProperty,IWbemQualifierSet **ppQualSet);
      HRESULT (WINAPI *Clone)(IWbemClassObject *This,IWbemClassObject **ppCopy);
      HRESULT (WINAPI *GetObjectText)(IWbemClassObject *This,long lFlags,BSTR *pstrObjectText);
      HRESULT (WINAPI *SpawnDerivedClass)(IWbemClassObject *This,long lFlags,IWbemClassObject **ppNewClass);
      HRESULT (WINAPI *SpawnInstance)(IWbemClassObject *This,long lFlags,IWbemClassObject **ppNewInstance);
      HRESULT (WINAPI *CompareTo)(IWbemClassObject *This,long lFlags,IWbemClassObject *pCompareTo);
      HRESULT (WINAPI *GetPropertyOrigin)(IWbemClassObject *This,LPCWSTR wszName,BSTR *pstrClassName);
      HRESULT (WINAPI *InheritsFrom)(IWbemClassObject *This,LPCWSTR strAncestor);
      HRESULT (WINAPI *GetMethod)(IWbemClassObject *This,LPCWSTR wszName,long lFlags,IWbemClassObject **ppInSignature,IWbemClassObject **ppOutSignature);
      HRESULT (WINAPI *PutMethod)(IWbemClassObject *This,LPCWSTR wszName,long lFlags,IWbemClassObject *pInSignature,IWbemClassObject *pOutSignature);
      HRESULT (WINAPI *DeleteMethod)(IWbemClassObject *This,LPCWSTR wszName);
      HRESULT (WINAPI *BeginMethodEnumeration)(IWbemClassObject *This,long lEnumFlags);
      HRESULT (WINAPI *NextMethod)(IWbemClassObject *This,long lFlags,BSTR *pstrName,IWbemClassObject **ppInSignature,IWbemClassObject **ppOutSignature);
      HRESULT (WINAPI *EndMethodEnumeration)(IWbemClassObject *This);
      HRESULT (WINAPI *GetMethodQualifierSet)(IWbemClassObject *This,LPCWSTR wszMethod,IWbemQualifierSet **ppQualSet);
      HRESULT (WINAPI *GetMethodOrigin)(IWbemClassObject *This,LPCWSTR wszMethodName,BSTR *pstrClassName);
    END_INTERFACE
  } IWbemClassObjectVtbl;
  struct IWbemClassObject {
    CONST_VTBL struct IWbemClassObjectVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemClassObject_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemClassObject_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemClassObject_Release(This) (This)->lpVtbl->Release(This)
#define IWbemClassObject_GetQualifierSet(This,ppQualSet) (This)->lpVtbl->GetQualifierSet(This,ppQualSet)
#define IWbemClassObject_Get(This,wszName,lFlags,pVal,pType,plFlavor) (This)->lpVtbl->Get(This,wszName,lFlags,pVal,pType,plFlavor)
#define IWbemClassObject_Put(This,wszName,lFlags,pVal,Type) (This)->lpVtbl->Put(This,wszName,lFlags,pVal,Type)
#define IWbemClassObject_Delete(This,wszName) (This)->lpVtbl->Delete(This,wszName)
#define IWbemClassObject_GetNames(This,wszQualifierName,lFlags,pQualifierVal,pNames) (This)->lpVtbl->GetNames(This,wszQualifierName,lFlags,pQualifierVal,pNames)
#define IWbemClassObject_BeginEnumeration(This,lEnumFlags) (This)->lpVtbl->BeginEnumeration(This,lEnumFlags)
#define IWbemClassObject_Next(This,lFlags,strName,pVal,pType,plFlavor) (This)->lpVtbl->Next(This,lFlags,strName,pVal,pType,plFlavor)
#define IWbemClassObject_EndEnumeration(This) (This)->lpVtbl->EndEnumeration(This)
#define IWbemClassObject_GetPropertyQualifierSet(This,wszProperty,ppQualSet) (This)->lpVtbl->GetPropertyQualifierSet(This,wszProperty,ppQualSet)
#define IWbemClassObject_Clone(This,ppCopy) (This)->lpVtbl->Clone(This,ppCopy)
#define IWbemClassObject_GetObjectText(This,lFlags,pstrObjectText) (This)->lpVtbl->GetObjectText(This,lFlags,pstrObjectText)
#define IWbemClassObject_SpawnDerivedClass(This,lFlags,ppNewClass) (This)->lpVtbl->SpawnDerivedClass(This,lFlags,ppNewClass)
#define IWbemClassObject_SpawnInstance(This,lFlags,ppNewInstance) (This)->lpVtbl->SpawnInstance(This,lFlags,ppNewInstance)
#define IWbemClassObject_CompareTo(This,lFlags,pCompareTo) (This)->lpVtbl->CompareTo(This,lFlags,pCompareTo)
#define IWbemClassObject_GetPropertyOrigin(This,wszName,pstrClassName) (This)->lpVtbl->GetPropertyOrigin(This,wszName,pstrClassName)
#define IWbemClassObject_InheritsFrom(This,strAncestor) (This)->lpVtbl->InheritsFrom(This,strAncestor)
#define IWbemClassObject_GetMethod(This,wszName,lFlags,ppInSignature,ppOutSignature) (This)->lpVtbl->GetMethod(This,wszName,lFlags,ppInSignature,ppOutSignature)
#define IWbemClassObject_PutMethod(This,wszName,lFlags,pInSignature,pOutSignature) (This)->lpVtbl->PutMethod(This,wszName,lFlags,pInSignature,pOutSignature)
#define IWbemClassObject_DeleteMethod(This,wszName) (This)->lpVtbl->DeleteMethod(This,wszName)
#define IWbemClassObject_BeginMethodEnumeration(This,lEnumFlags) (This)->lpVtbl->BeginMethodEnumeration(This,lEnumFlags)
#define IWbemClassObject_NextMethod(This,lFlags,pstrName,ppInSignature,ppOutSignature) (This)->lpVtbl->NextMethod(This,lFlags,pstrName,ppInSignature,ppOutSignature)
#define IWbemClassObject_EndMethodEnumeration(This) (This)->lpVtbl->EndMethodEnumeration(This)
#define IWbemClassObject_GetMethodQualifierSet(This,wszMethod,ppQualSet) (This)->lpVtbl->GetMethodQualifierSet(This,wszMethod,ppQualSet)
#define IWbemClassObject_GetMethodOrigin(This,wszMethodName,pstrClassName) (This)->lpVtbl->GetMethodOrigin(This,wszMethodName,pstrClassName)
#endif
#endif
  HRESULT WINAPI IWbemClassObject_GetQualifierSet_Proxy(IWbemClassObject *This,IWbemQualifierSet **ppQualSet);
  void __RPC_STUB IWbemClassObject_GetQualifierSet_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_Get_Proxy(IWbemClassObject *This,LPCWSTR wszName,long lFlags,VARIANT *pVal,CIMTYPE *pType,long *plFlavor);
  void __RPC_STUB IWbemClassObject_Get_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_Put_Proxy(IWbemClassObject *This,LPCWSTR wszName,long lFlags,VARIANT *pVal,CIMTYPE Type);
  void __RPC_STUB IWbemClassObject_Put_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_Delete_Proxy(IWbemClassObject *This,LPCWSTR wszName);
  void __RPC_STUB IWbemClassObject_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_GetNames_Proxy(IWbemClassObject *This,LPCWSTR wszQualifierName,long lFlags,VARIANT *pQualifierVal,SAFEARRAY **pNames);
  void __RPC_STUB IWbemClassObject_GetNames_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_BeginEnumeration_Proxy(IWbemClassObject *This,long lEnumFlags);
  void __RPC_STUB IWbemClassObject_BeginEnumeration_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_Next_Proxy(IWbemClassObject *This,long lFlags,BSTR *strName,VARIANT *pVal,CIMTYPE *pType,long *plFlavor);
  void __RPC_STUB IWbemClassObject_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_EndEnumeration_Proxy(IWbemClassObject *This);
  void __RPC_STUB IWbemClassObject_EndEnumeration_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_GetPropertyQualifierSet_Proxy(IWbemClassObject *This,LPCWSTR wszProperty,IWbemQualifierSet **ppQualSet);
  void __RPC_STUB IWbemClassObject_GetPropertyQualifierSet_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_Clone_Proxy(IWbemClassObject *This,IWbemClassObject **ppCopy);
  void __RPC_STUB IWbemClassObject_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_GetObjectText_Proxy(IWbemClassObject *This,long lFlags,BSTR *pstrObjectText);
  void __RPC_STUB IWbemClassObject_GetObjectText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_SpawnDerivedClass_Proxy(IWbemClassObject *This,long lFlags,IWbemClassObject **ppNewClass);
  void __RPC_STUB IWbemClassObject_SpawnDerivedClass_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_SpawnInstance_Proxy(IWbemClassObject *This,long lFlags,IWbemClassObject **ppNewInstance);
  void __RPC_STUB IWbemClassObject_SpawnInstance_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_CompareTo_Proxy(IWbemClassObject *This,long lFlags,IWbemClassObject *pCompareTo);
  void __RPC_STUB IWbemClassObject_CompareTo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_GetPropertyOrigin_Proxy(IWbemClassObject *This,LPCWSTR wszName,BSTR *pstrClassName);
  void __RPC_STUB IWbemClassObject_GetPropertyOrigin_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_InheritsFrom_Proxy(IWbemClassObject *This,LPCWSTR strAncestor);
  void __RPC_STUB IWbemClassObject_InheritsFrom_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_GetMethod_Proxy(IWbemClassObject *This,LPCWSTR wszName,long lFlags,IWbemClassObject **ppInSignature,IWbemClassObject **ppOutSignature);
  void __RPC_STUB IWbemClassObject_GetMethod_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_PutMethod_Proxy(IWbemClassObject *This,LPCWSTR wszName,long lFlags,IWbemClassObject *pInSignature,IWbemClassObject *pOutSignature);
  void __RPC_STUB IWbemClassObject_PutMethod_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_DeleteMethod_Proxy(IWbemClassObject *This,LPCWSTR wszName);
  void __RPC_STUB IWbemClassObject_DeleteMethod_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_BeginMethodEnumeration_Proxy(IWbemClassObject *This,long lEnumFlags);
  void __RPC_STUB IWbemClassObject_BeginMethodEnumeration_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_NextMethod_Proxy(IWbemClassObject *This,long lFlags,BSTR *pstrName,IWbemClassObject **ppInSignature,IWbemClassObject **ppOutSignature);
  void __RPC_STUB IWbemClassObject_NextMethod_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_EndMethodEnumeration_Proxy(IWbemClassObject *This);
  void __RPC_STUB IWbemClassObject_EndMethodEnumeration_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_GetMethodQualifierSet_Proxy(IWbemClassObject *This,LPCWSTR wszMethod,IWbemQualifierSet **ppQualSet);
  void __RPC_STUB IWbemClassObject_GetMethodQualifierSet_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemClassObject_GetMethodOrigin_Proxy(IWbemClassObject *This,LPCWSTR wszMethodName,BSTR *pstrClassName);
  void __RPC_STUB IWbemClassObject_GetMethodOrigin_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemObjectAccess_INTERFACE_DEFINED__
#define __IWbemObjectAccess_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemObjectAccess;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemObjectAccess : public IWbemClassObject {
  public:
    virtual HRESULT WINAPI GetPropertyHandle(LPCWSTR wszPropertyName,CIMTYPE *pType,long *plHandle) = 0;
    virtual HRESULT WINAPI WritePropertyValue(long lHandle,long lNumBytes,const byte *aData) = 0;
    virtual HRESULT WINAPI ReadPropertyValue(long lHandle,long lBufferSize,long *plNumBytes,byte *aData) = 0;
    virtual HRESULT WINAPI ReadDWORD(long lHandle,DWORD *pdw) = 0;
    virtual HRESULT WINAPI WriteDWORD(long lHandle,DWORD dw) = 0;
    __MINGW_EXTENSION virtual HRESULT WINAPI ReadQWORD(long lHandle,unsigned __int64 *pqw) = 0;
    __MINGW_EXTENSION virtual HRESULT WINAPI WriteQWORD(long lHandle,unsigned __int64 pw) = 0;
    virtual HRESULT WINAPI GetPropertyInfoByHandle(long lHandle,BSTR *pstrName,CIMTYPE *pType) = 0;
    virtual HRESULT WINAPI Lock(long lFlags) = 0;
    virtual HRESULT WINAPI Unlock(long lFlags) = 0;
  };
#else
  typedef struct IWbemObjectAccessVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemObjectAccess *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemObjectAccess *This);
      ULONG (WINAPI *Release)(IWbemObjectAccess *This);
      HRESULT (WINAPI *GetQualifierSet)(IWbemObjectAccess *This,IWbemQualifierSet **ppQualSet);
      HRESULT (WINAPI *Get)(IWbemObjectAccess *This,LPCWSTR wszName,long lFlags,VARIANT *pVal,CIMTYPE *pType,long *plFlavor);
      HRESULT (WINAPI *Put)(IWbemObjectAccess *This,LPCWSTR wszName,long lFlags,VARIANT *pVal,CIMTYPE Type);
      HRESULT (WINAPI *Delete)(IWbemObjectAccess *This,LPCWSTR wszName);
      HRESULT (WINAPI *GetNames)(IWbemObjectAccess *This,LPCWSTR wszQualifierName,long lFlags,VARIANT *pQualifierVal,SAFEARRAY **pNames);
      HRESULT (WINAPI *BeginEnumeration)(IWbemObjectAccess *This,long lEnumFlags);
      HRESULT (WINAPI *Next)(IWbemObjectAccess *This,long lFlags,BSTR *strName,VARIANT *pVal,CIMTYPE *pType,long *plFlavor);
      HRESULT (WINAPI *EndEnumeration)(IWbemObjectAccess *This);
      HRESULT (WINAPI *GetPropertyQualifierSet)(IWbemObjectAccess *This,LPCWSTR wszProperty,IWbemQualifierSet **ppQualSet);
      HRESULT (WINAPI *Clone)(IWbemObjectAccess *This,IWbemClassObject **ppCopy);
      HRESULT (WINAPI *GetObjectText)(IWbemObjectAccess *This,long lFlags,BSTR *pstrObjectText);
      HRESULT (WINAPI *SpawnDerivedClass)(IWbemObjectAccess *This,long lFlags,IWbemClassObject **ppNewClass);
      HRESULT (WINAPI *SpawnInstance)(IWbemObjectAccess *This,long lFlags,IWbemClassObject **ppNewInstance);
      HRESULT (WINAPI *CompareTo)(IWbemObjectAccess *This,long lFlags,IWbemClassObject *pCompareTo);
      HRESULT (WINAPI *GetPropertyOrigin)(IWbemObjectAccess *This,LPCWSTR wszName,BSTR *pstrClassName);
      HRESULT (WINAPI *InheritsFrom)(IWbemObjectAccess *This,LPCWSTR strAncestor);
      HRESULT (WINAPI *GetMethod)(IWbemObjectAccess *This,LPCWSTR wszName,long lFlags,IWbemClassObject **ppInSignature,IWbemClassObject **ppOutSignature);
      HRESULT (WINAPI *PutMethod)(IWbemObjectAccess *This,LPCWSTR wszName,long lFlags,IWbemClassObject *pInSignature,IWbemClassObject *pOutSignature);
      HRESULT (WINAPI *DeleteMethod)(IWbemObjectAccess *This,LPCWSTR wszName);
      HRESULT (WINAPI *BeginMethodEnumeration)(IWbemObjectAccess *This,long lEnumFlags);
      HRESULT (WINAPI *NextMethod)(IWbemObjectAccess *This,long lFlags,BSTR *pstrName,IWbemClassObject **ppInSignature,IWbemClassObject **ppOutSignature);
      HRESULT (WINAPI *EndMethodEnumeration)(IWbemObjectAccess *This);
      HRESULT (WINAPI *GetMethodQualifierSet)(IWbemObjectAccess *This,LPCWSTR wszMethod,IWbemQualifierSet **ppQualSet);
      HRESULT (WINAPI *GetMethodOrigin)(IWbemObjectAccess *This,LPCWSTR wszMethodName,BSTR *pstrClassName);
      HRESULT (WINAPI *GetPropertyHandle)(IWbemObjectAccess *This,LPCWSTR wszPropertyName,CIMTYPE *pType,long *plHandle);
      HRESULT (WINAPI *WritePropertyValue)(IWbemObjectAccess *This,long lHandle,long lNumBytes,const byte *aData);
      HRESULT (WINAPI *ReadPropertyValue)(IWbemObjectAccess *This,long lHandle,long lBufferSize,long *plNumBytes,byte *aData);
      HRESULT (WINAPI *ReadDWORD)(IWbemObjectAccess *This,long lHandle,DWORD *pdw);
      HRESULT (WINAPI *WriteDWORD)(IWbemObjectAccess *This,long lHandle,DWORD dw);
      __MINGW_EXTENSION HRESULT (WINAPI *ReadQWORD)(IWbemObjectAccess *This,long lHandle,unsigned __int64 *pqw);
      __MINGW_EXTENSION HRESULT (WINAPI *WriteQWORD)(IWbemObjectAccess *This,long lHandle,unsigned __int64 pw);
      HRESULT (WINAPI *GetPropertyInfoByHandle)(IWbemObjectAccess *This,long lHandle,BSTR *pstrName,CIMTYPE *pType);
      HRESULT (WINAPI *Lock)(IWbemObjectAccess *This,long lFlags);
      HRESULT (WINAPI *Unlock)(IWbemObjectAccess *This,long lFlags);
    END_INTERFACE
  } IWbemObjectAccessVtbl;
  struct IWbemObjectAccess {
    CONST_VTBL struct IWbemObjectAccessVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemObjectAccess_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemObjectAccess_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemObjectAccess_Release(This) (This)->lpVtbl->Release(This)
#define IWbemObjectAccess_GetQualifierSet(This,ppQualSet) (This)->lpVtbl->GetQualifierSet(This,ppQualSet)
#define IWbemObjectAccess_Get(This,wszName,lFlags,pVal,pType,plFlavor) (This)->lpVtbl->Get(This,wszName,lFlags,pVal,pType,plFlavor)
#define IWbemObjectAccess_Put(This,wszName,lFlags,pVal,Type) (This)->lpVtbl->Put(This,wszName,lFlags,pVal,Type)
#define IWbemObjectAccess_Delete(This,wszName) (This)->lpVtbl->Delete(This,wszName)
#define IWbemObjectAccess_GetNames(This,wszQualifierName,lFlags,pQualifierVal,pNames) (This)->lpVtbl->GetNames(This,wszQualifierName,lFlags,pQualifierVal,pNames)
#define IWbemObjectAccess_BeginEnumeration(This,lEnumFlags) (This)->lpVtbl->BeginEnumeration(This,lEnumFlags)
#define IWbemObjectAccess_Next(This,lFlags,strName,pVal,pType,plFlavor) (This)->lpVtbl->Next(This,lFlags,strName,pVal,pType,plFlavor)
#define IWbemObjectAccess_EndEnumeration(This) (This)->lpVtbl->EndEnumeration(This)
#define IWbemObjectAccess_GetPropertyQualifierSet(This,wszProperty,ppQualSet) (This)->lpVtbl->GetPropertyQualifierSet(This,wszProperty,ppQualSet)
#define IWbemObjectAccess_Clone(This,ppCopy) (This)->lpVtbl->Clone(This,ppCopy)
#define IWbemObjectAccess_GetObjectText(This,lFlags,pstrObjectText) (This)->lpVtbl->GetObjectText(This,lFlags,pstrObjectText)
#define IWbemObjectAccess_SpawnDerivedClass(This,lFlags,ppNewClass) (This)->lpVtbl->SpawnDerivedClass(This,lFlags,ppNewClass)
#define IWbemObjectAccess_SpawnInstance(This,lFlags,ppNewInstance) (This)->lpVtbl->SpawnInstance(This,lFlags,ppNewInstance)
#define IWbemObjectAccess_CompareTo(This,lFlags,pCompareTo) (This)->lpVtbl->CompareTo(This,lFlags,pCompareTo)
#define IWbemObjectAccess_GetPropertyOrigin(This,wszName,pstrClassName) (This)->lpVtbl->GetPropertyOrigin(This,wszName,pstrClassName)
#define IWbemObjectAccess_InheritsFrom(This,strAncestor) (This)->lpVtbl->InheritsFrom(This,strAncestor)
#define IWbemObjectAccess_GetMethod(This,wszName,lFlags,ppInSignature,ppOutSignature) (This)->lpVtbl->GetMethod(This,wszName,lFlags,ppInSignature,ppOutSignature)
#define IWbemObjectAccess_PutMethod(This,wszName,lFlags,pInSignature,pOutSignature) (This)->lpVtbl->PutMethod(This,wszName,lFlags,pInSignature,pOutSignature)
#define IWbemObjectAccess_DeleteMethod(This,wszName) (This)->lpVtbl->DeleteMethod(This,wszName)
#define IWbemObjectAccess_BeginMethodEnumeration(This,lEnumFlags) (This)->lpVtbl->BeginMethodEnumeration(This,lEnumFlags)
#define IWbemObjectAccess_NextMethod(This,lFlags,pstrName,ppInSignature,ppOutSignature) (This)->lpVtbl->NextMethod(This,lFlags,pstrName,ppInSignature,ppOutSignature)
#define IWbemObjectAccess_EndMethodEnumeration(This) (This)->lpVtbl->EndMethodEnumeration(This)
#define IWbemObjectAccess_GetMethodQualifierSet(This,wszMethod,ppQualSet) (This)->lpVtbl->GetMethodQualifierSet(This,wszMethod,ppQualSet)
#define IWbemObjectAccess_GetMethodOrigin(This,wszMethodName,pstrClassName) (This)->lpVtbl->GetMethodOrigin(This,wszMethodName,pstrClassName)
#define IWbemObjectAccess_GetPropertyHandle(This,wszPropertyName,pType,plHandle) (This)->lpVtbl->GetPropertyHandle(This,wszPropertyName,pType,plHandle)
#define IWbemObjectAccess_WritePropertyValue(This,lHandle,lNumBytes,aData) (This)->lpVtbl->WritePropertyValue(This,lHandle,lNumBytes,aData)
#define IWbemObjectAccess_ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData) (This)->lpVtbl->ReadPropertyValue(This,lHandle,lBufferSize,plNumBytes,aData)
#define IWbemObjectAccess_ReadDWORD(This,lHandle,pdw) (This)->lpVtbl->ReadDWORD(This,lHandle,pdw)
#define IWbemObjectAccess_WriteDWORD(This,lHandle,dw) (This)->lpVtbl->WriteDWORD(This,lHandle,dw)
#define IWbemObjectAccess_ReadQWORD(This,lHandle,pqw) (This)->lpVtbl->ReadQWORD(This,lHandle,pqw)
#define IWbemObjectAccess_WriteQWORD(This,lHandle,pw) (This)->lpVtbl->WriteQWORD(This,lHandle,pw)
#define IWbemObjectAccess_GetPropertyInfoByHandle(This,lHandle,pstrName,pType) (This)->lpVtbl->GetPropertyInfoByHandle(This,lHandle,pstrName,pType)
#define IWbemObjectAccess_Lock(This,lFlags) (This)->lpVtbl->Lock(This,lFlags)
#define IWbemObjectAccess_Unlock(This,lFlags) (This)->lpVtbl->Unlock(This,lFlags)
#endif
#endif
  HRESULT WINAPI IWbemObjectAccess_GetPropertyHandle_Proxy(IWbemObjectAccess *This,LPCWSTR wszPropertyName,CIMTYPE *pType,long *plHandle);
  void __RPC_STUB IWbemObjectAccess_GetPropertyHandle_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemObjectAccess_WritePropertyValue_Proxy(IWbemObjectAccess *This,long lHandle,long lNumBytes,const byte *aData);
  void __RPC_STUB IWbemObjectAccess_WritePropertyValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemObjectAccess_ReadPropertyValue_Proxy(IWbemObjectAccess *This,long lHandle,long lBufferSize,long *plNumBytes,byte *aData);
  void __RPC_STUB IWbemObjectAccess_ReadPropertyValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemObjectAccess_ReadDWORD_Proxy(IWbemObjectAccess *This,long lHandle,DWORD *pdw);
  void __RPC_STUB IWbemObjectAccess_ReadDWORD_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemObjectAccess_WriteDWORD_Proxy(IWbemObjectAccess *This,long lHandle,DWORD dw);
  void __RPC_STUB IWbemObjectAccess_WriteDWORD_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  __MINGW_EXTENSION HRESULT WINAPI IWbemObjectAccess_ReadQWORD_Proxy(IWbemObjectAccess *This,long lHandle,unsigned __int64 *pqw);
  void __RPC_STUB IWbemObjectAccess_ReadQWORD_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  __MINGW_EXTENSION HRESULT WINAPI IWbemObjectAccess_WriteQWORD_Proxy(IWbemObjectAccess *This,long lHandle,unsigned __int64 pw);
  void __RPC_STUB IWbemObjectAccess_WriteQWORD_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemObjectAccess_GetPropertyInfoByHandle_Proxy(IWbemObjectAccess *This,long lHandle,BSTR *pstrName,CIMTYPE *pType);
  void __RPC_STUB IWbemObjectAccess_GetPropertyInfoByHandle_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemObjectAccess_Lock_Proxy(IWbemObjectAccess *This,long lFlags);
  void __RPC_STUB IWbemObjectAccess_Lock_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemObjectAccess_Unlock_Proxy(IWbemObjectAccess *This,long lFlags);
  void __RPC_STUB IWbemObjectAccess_Unlock_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemQualifierSet_INTERFACE_DEFINED__
#define __IWbemQualifierSet_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemQualifierSet;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemQualifierSet : public IUnknown {
  public:
    virtual HRESULT WINAPI Get(LPCWSTR wszName,long lFlags,VARIANT *pVal,long *plFlavor) = 0;
    virtual HRESULT WINAPI Put(LPCWSTR wszName,VARIANT *pVal,long lFlavor) = 0;
    virtual HRESULT WINAPI Delete(LPCWSTR wszName) = 0;
    virtual HRESULT WINAPI GetNames(long lFlags,SAFEARRAY **pNames) = 0;
    virtual HRESULT WINAPI BeginEnumeration(long lFlags) = 0;
    virtual HRESULT WINAPI Next(long lFlags,BSTR *pstrName,VARIANT *pVal,long *plFlavor) = 0;
    virtual HRESULT WINAPI EndEnumeration(void) = 0;
  };
#else
  typedef struct IWbemQualifierSetVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemQualifierSet *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemQualifierSet *This);
      ULONG (WINAPI *Release)(IWbemQualifierSet *This);
      HRESULT (WINAPI *Get)(IWbemQualifierSet *This,LPCWSTR wszName,long lFlags,VARIANT *pVal,long *plFlavor);
      HRESULT (WINAPI *Put)(IWbemQualifierSet *This,LPCWSTR wszName,VARIANT *pVal,long lFlavor);
      HRESULT (WINAPI *Delete)(IWbemQualifierSet *This,LPCWSTR wszName);
      HRESULT (WINAPI *GetNames)(IWbemQualifierSet *This,long lFlags,SAFEARRAY **pNames);
      HRESULT (WINAPI *BeginEnumeration)(IWbemQualifierSet *This,long lFlags);
      HRESULT (WINAPI *Next)(IWbemQualifierSet *This,long lFlags,BSTR *pstrName,VARIANT *pVal,long *plFlavor);
      HRESULT (WINAPI *EndEnumeration)(IWbemQualifierSet *This);
    END_INTERFACE
  } IWbemQualifierSetVtbl;
  struct IWbemQualifierSet {
    CONST_VTBL struct IWbemQualifierSetVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemQualifierSet_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemQualifierSet_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemQualifierSet_Release(This) (This)->lpVtbl->Release(This)
#define IWbemQualifierSet_Get(This,wszName,lFlags,pVal,plFlavor) (This)->lpVtbl->Get(This,wszName,lFlags,pVal,plFlavor)
#define IWbemQualifierSet_Put(This,wszName,pVal,lFlavor) (This)->lpVtbl->Put(This,wszName,pVal,lFlavor)
#define IWbemQualifierSet_Delete(This,wszName) (This)->lpVtbl->Delete(This,wszName)
#define IWbemQualifierSet_GetNames(This,lFlags,pNames) (This)->lpVtbl->GetNames(This,lFlags,pNames)
#define IWbemQualifierSet_BeginEnumeration(This,lFlags) (This)->lpVtbl->BeginEnumeration(This,lFlags)
#define IWbemQualifierSet_Next(This,lFlags,pstrName,pVal,plFlavor) (This)->lpVtbl->Next(This,lFlags,pstrName,pVal,plFlavor)
#define IWbemQualifierSet_EndEnumeration(This) (This)->lpVtbl->EndEnumeration(This)
#endif
#endif
  HRESULT WINAPI IWbemQualifierSet_Get_Proxy(IWbemQualifierSet *This,LPCWSTR wszName,long lFlags,VARIANT *pVal,long *plFlavor);
  void __RPC_STUB IWbemQualifierSet_Get_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemQualifierSet_Put_Proxy(IWbemQualifierSet *This,LPCWSTR wszName,VARIANT *pVal,long lFlavor);
  void __RPC_STUB IWbemQualifierSet_Put_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemQualifierSet_Delete_Proxy(IWbemQualifierSet *This,LPCWSTR wszName);
  void __RPC_STUB IWbemQualifierSet_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemQualifierSet_GetNames_Proxy(IWbemQualifierSet *This,long lFlags,SAFEARRAY **pNames);
  void __RPC_STUB IWbemQualifierSet_GetNames_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemQualifierSet_BeginEnumeration_Proxy(IWbemQualifierSet *This,long lFlags);
  void __RPC_STUB IWbemQualifierSet_BeginEnumeration_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemQualifierSet_Next_Proxy(IWbemQualifierSet *This,long lFlags,BSTR *pstrName,VARIANT *pVal,long *plFlavor);
  void __RPC_STUB IWbemQualifierSet_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemQualifierSet_EndEnumeration_Proxy(IWbemQualifierSet *This);
  void __RPC_STUB IWbemQualifierSet_EndEnumeration_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemServices_INTERFACE_DEFINED__
#define __IWbemServices_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemServices;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemServices : public IUnknown {
  public:
    virtual HRESULT WINAPI OpenNamespace(const BSTR strNamespace,long lFlags,IWbemContext *pCtx,IWbemServices **ppWorkingNamespace,IWbemCallResult **ppResult) = 0;
    virtual HRESULT WINAPI CancelAsyncCall(IWbemObjectSink *pSink) = 0;
    virtual HRESULT WINAPI QueryObjectSink(long lFlags,IWbemObjectSink **ppResponseHandler) = 0;
    virtual HRESULT WINAPI GetObject(const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemClassObject **ppObject,IWbemCallResult **ppCallResult) = 0;
    virtual HRESULT WINAPI GetObjectAsync(const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI PutClass(IWbemClassObject *pObject,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult) = 0;
    virtual HRESULT WINAPI PutClassAsync(IWbemClassObject *pObject,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI DeleteClass(const BSTR strClass,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult) = 0;
    virtual HRESULT WINAPI DeleteClassAsync(const BSTR strClass,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI CreateClassEnum(const BSTR strSuperclass,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum) = 0;
    virtual HRESULT WINAPI CreateClassEnumAsync(const BSTR strSuperclass,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI PutInstance(IWbemClassObject *pInst,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult) = 0;
    virtual HRESULT WINAPI PutInstanceAsync(IWbemClassObject *pInst,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI DeleteInstance(const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult) = 0;
    virtual HRESULT WINAPI DeleteInstanceAsync(const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI CreateInstanceEnum(const BSTR strFilter,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum) = 0;
    virtual HRESULT WINAPI CreateInstanceEnumAsync(const BSTR strFilter,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI ExecQuery(const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum) = 0;
    virtual HRESULT WINAPI ExecQueryAsync(const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI ExecNotificationQuery(const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum) = 0;
    virtual HRESULT WINAPI ExecNotificationQueryAsync(const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler) = 0;
    virtual HRESULT WINAPI ExecMethod(const BSTR strObjectPath,const BSTR strMethodName,long lFlags,IWbemContext *pCtx,IWbemClassObject *pInParams,IWbemClassObject **ppOutParams,IWbemCallResult **ppCallResult) = 0;
    virtual HRESULT WINAPI ExecMethodAsync(const BSTR strObjectPath,const BSTR strMethodName,long lFlags,IWbemContext *pCtx,IWbemClassObject *pInParams,IWbemObjectSink *pResponseHandler) = 0;
  };
#else
  typedef struct IWbemServicesVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemServices *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemServices *This);
      ULONG (WINAPI *Release)(IWbemServices *This);
      HRESULT (WINAPI *OpenNamespace)(IWbemServices *This,const BSTR strNamespace,long lFlags,IWbemContext *pCtx,IWbemServices **ppWorkingNamespace,IWbemCallResult **ppResult);
      HRESULT (WINAPI *CancelAsyncCall)(IWbemServices *This,IWbemObjectSink *pSink);
      HRESULT (WINAPI *QueryObjectSink)(IWbemServices *This,long lFlags,IWbemObjectSink **ppResponseHandler);
      HRESULT (WINAPI *GetObject)(IWbemServices *This,const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemClassObject **ppObject,IWbemCallResult **ppCallResult);
      HRESULT (WINAPI *GetObjectAsync)(IWbemServices *This,const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *PutClass)(IWbemServices *This,IWbemClassObject *pObject,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult);
      HRESULT (WINAPI *PutClassAsync)(IWbemServices *This,IWbemClassObject *pObject,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *DeleteClass)(IWbemServices *This,const BSTR strClass,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult);
      HRESULT (WINAPI *DeleteClassAsync)(IWbemServices *This,const BSTR strClass,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *CreateClassEnum)(IWbemServices *This,const BSTR strSuperclass,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum);
      HRESULT (WINAPI *CreateClassEnumAsync)(IWbemServices *This,const BSTR strSuperclass,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *PutInstance)(IWbemServices *This,IWbemClassObject *pInst,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult);
      HRESULT (WINAPI *PutInstanceAsync)(IWbemServices *This,IWbemClassObject *pInst,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *DeleteInstance)(IWbemServices *This,const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult);
      HRESULT (WINAPI *DeleteInstanceAsync)(IWbemServices *This,const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *CreateInstanceEnum)(IWbemServices *This,const BSTR strFilter,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum);
      HRESULT (WINAPI *CreateInstanceEnumAsync)(IWbemServices *This,const BSTR strFilter,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *ExecQuery)(IWbemServices *This,const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum);
      HRESULT (WINAPI *ExecQueryAsync)(IWbemServices *This,const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *ExecNotificationQuery)(IWbemServices *This,const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum);
      HRESULT (WINAPI *ExecNotificationQueryAsync)(IWbemServices *This,const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
      HRESULT (WINAPI *ExecMethod)(IWbemServices *This,const BSTR strObjectPath,const BSTR strMethodName,long lFlags,IWbemContext *pCtx,IWbemClassObject *pInParams,IWbemClassObject **ppOutParams,IWbemCallResult **ppCallResult);
      HRESULT (WINAPI *ExecMethodAsync)(IWbemServices *This,const BSTR strObjectPath,const BSTR strMethodName,long lFlags,IWbemContext *pCtx,IWbemClassObject *pInParams,IWbemObjectSink *pResponseHandler);
    END_INTERFACE
  } IWbemServicesVtbl;
  struct IWbemServices {
    CONST_VTBL struct IWbemServicesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemServices_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemServices_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemServices_Release(This) (This)->lpVtbl->Release(This)
#define IWbemServices_OpenNamespace(This,strNamespace,lFlags,pCtx,ppWorkingNamespace,ppResult) (This)->lpVtbl->OpenNamespace(This,strNamespace,lFlags,pCtx,ppWorkingNamespace,ppResult)
#define IWbemServices_CancelAsyncCall(This,pSink) (This)->lpVtbl->CancelAsyncCall(This,pSink)
#define IWbemServices_QueryObjectSink(This,lFlags,ppResponseHandler) (This)->lpVtbl->QueryObjectSink(This,lFlags,ppResponseHandler)
#define IWbemServices_GetObject(This,strObjectPath,lFlags,pCtx,ppObject,ppCallResult) (This)->lpVtbl->GetObject(This,strObjectPath,lFlags,pCtx,ppObject,ppCallResult)
#define IWbemServices_GetObjectAsync(This,strObjectPath,lFlags,pCtx,pResponseHandler) (This)->lpVtbl->GetObjectAsync(This,strObjectPath,lFlags,pCtx,pResponseHandler)
#define IWbemServices_PutClass(This,pObject,lFlags,pCtx,ppCallResult) (This)->lpVtbl->PutClass(This,pObject,lFlags,pCtx,ppCallResult)
#define IWbemServices_PutClassAsync(This,pObject,lFlags,pCtx,pResponseHandler) (This)->lpVtbl->PutClassAsync(This,pObject,lFlags,pCtx,pResponseHandler)
#define IWbemServices_DeleteClass(This,strClass,lFlags,pCtx,ppCallResult) (This)->lpVtbl->DeleteClass(This,strClass,lFlags,pCtx,ppCallResult)
#define IWbemServices_DeleteClassAsync(This,strClass,lFlags,pCtx,pResponseHandler) (This)->lpVtbl->DeleteClassAsync(This,strClass,lFlags,pCtx,pResponseHandler)
#define IWbemServices_CreateClassEnum(This,strSuperclass,lFlags,pCtx,ppEnum) (This)->lpVtbl->CreateClassEnum(This,strSuperclass,lFlags,pCtx,ppEnum)
#define IWbemServices_CreateClassEnumAsync(This,strSuperclass,lFlags,pCtx,pResponseHandler) (This)->lpVtbl->CreateClassEnumAsync(This,strSuperclass,lFlags,pCtx,pResponseHandler)
#define IWbemServices_PutInstance(This,pInst,lFlags,pCtx,ppCallResult) (This)->lpVtbl->PutInstance(This,pInst,lFlags,pCtx,ppCallResult)
#define IWbemServices_PutInstanceAsync(This,pInst,lFlags,pCtx,pResponseHandler) (This)->lpVtbl->PutInstanceAsync(This,pInst,lFlags,pCtx,pResponseHandler)
#define IWbemServices_DeleteInstance(This,strObjectPath,lFlags,pCtx,ppCallResult) (This)->lpVtbl->DeleteInstance(This,strObjectPath,lFlags,pCtx,ppCallResult)
#define IWbemServices_DeleteInstanceAsync(This,strObjectPath,lFlags,pCtx,pResponseHandler) (This)->lpVtbl->DeleteInstanceAsync(This,strObjectPath,lFlags,pCtx,pResponseHandler)
#define IWbemServices_CreateInstanceEnum(This,strFilter,lFlags,pCtx,ppEnum) (This)->lpVtbl->CreateInstanceEnum(This,strFilter,lFlags,pCtx,ppEnum)
#define IWbemServices_CreateInstanceEnumAsync(This,strFilter,lFlags,pCtx,pResponseHandler) (This)->lpVtbl->CreateInstanceEnumAsync(This,strFilter,lFlags,pCtx,pResponseHandler)
#define IWbemServices_ExecQuery(This,strQueryLanguage,strQuery,lFlags,pCtx,ppEnum) (This)->lpVtbl->ExecQuery(This,strQueryLanguage,strQuery,lFlags,pCtx,ppEnum)
#define IWbemServices_ExecQueryAsync(This,strQueryLanguage,strQuery,lFlags,pCtx,pResponseHandler) (This)->lpVtbl->ExecQueryAsync(This,strQueryLanguage,strQuery,lFlags,pCtx,pResponseHandler)
#define IWbemServices_ExecNotificationQuery(This,strQueryLanguage,strQuery,lFlags,pCtx,ppEnum) (This)->lpVtbl->ExecNotificationQuery(This,strQueryLanguage,strQuery,lFlags,pCtx,ppEnum)
#define IWbemServices_ExecNotificationQueryAsync(This,strQueryLanguage,strQuery,lFlags,pCtx,pResponseHandler) (This)->lpVtbl->ExecNotificationQueryAsync(This,strQueryLanguage,strQuery,lFlags,pCtx,pResponseHandler)
#define IWbemServices_ExecMethod(This,strObjectPath,strMethodName,lFlags,pCtx,pInParams,ppOutParams,ppCallResult) (This)->lpVtbl->ExecMethod(This,strObjectPath,strMethodName,lFlags,pCtx,pInParams,ppOutParams,ppCallResult)
#define IWbemServices_ExecMethodAsync(This,strObjectPath,strMethodName,lFlags,pCtx,pInParams,pResponseHandler) (This)->lpVtbl->ExecMethodAsync(This,strObjectPath,strMethodName,lFlags,pCtx,pInParams,pResponseHandler)
#endif
#endif
  HRESULT WINAPI IWbemServices_OpenNamespace_Proxy(IWbemServices *This,const BSTR strNamespace,long lFlags,IWbemContext *pCtx,IWbemServices **ppWorkingNamespace,IWbemCallResult **ppResult);
  void __RPC_STUB IWbemServices_OpenNamespace_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_CancelAsyncCall_Proxy(IWbemServices *This,IWbemObjectSink *pSink);
  void __RPC_STUB IWbemServices_CancelAsyncCall_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_QueryObjectSink_Proxy(IWbemServices *This,long lFlags,IWbemObjectSink **ppResponseHandler);
  void __RPC_STUB IWbemServices_QueryObjectSink_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_GetObject_Proxy(IWbemServices *This,const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemClassObject **ppObject,IWbemCallResult **ppCallResult);
  void __RPC_STUB IWbemServices_GetObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_GetObjectAsync_Proxy(IWbemServices *This,const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_GetObjectAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_PutClass_Proxy(IWbemServices *This,IWbemClassObject *pObject,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult);
  void __RPC_STUB IWbemServices_PutClass_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_PutClassAsync_Proxy(IWbemServices *This,IWbemClassObject *pObject,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_PutClassAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_DeleteClass_Proxy(IWbemServices *This,const BSTR strClass,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult);
  void __RPC_STUB IWbemServices_DeleteClass_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_DeleteClassAsync_Proxy(IWbemServices *This,const BSTR strClass,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_DeleteClassAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_CreateClassEnum_Proxy(IWbemServices *This,const BSTR strSuperclass,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum);
  void __RPC_STUB IWbemServices_CreateClassEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_CreateClassEnumAsync_Proxy(IWbemServices *This,const BSTR strSuperclass,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_CreateClassEnumAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_PutInstance_Proxy(IWbemServices *This,IWbemClassObject *pInst,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult);
  void __RPC_STUB IWbemServices_PutInstance_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_PutInstanceAsync_Proxy(IWbemServices *This,IWbemClassObject *pInst,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_PutInstanceAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_DeleteInstance_Proxy(IWbemServices *This,const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemCallResult **ppCallResult);
  void __RPC_STUB IWbemServices_DeleteInstance_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_DeleteInstanceAsync_Proxy(IWbemServices *This,const BSTR strObjectPath,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_DeleteInstanceAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_CreateInstanceEnum_Proxy(IWbemServices *This,const BSTR strFilter,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum);
  void __RPC_STUB IWbemServices_CreateInstanceEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_CreateInstanceEnumAsync_Proxy(IWbemServices *This,const BSTR strFilter,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_CreateInstanceEnumAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_ExecQuery_Proxy(IWbemServices *This,const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum);
  void __RPC_STUB IWbemServices_ExecQuery_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_ExecQueryAsync_Proxy(IWbemServices *This,const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_ExecQueryAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_ExecNotificationQuery_Proxy(IWbemServices *This,const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IEnumWbemClassObject **ppEnum);
  void __RPC_STUB IWbemServices_ExecNotificationQuery_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_ExecNotificationQueryAsync_Proxy(IWbemServices *This,const BSTR strQueryLanguage,const BSTR strQuery,long lFlags,IWbemContext *pCtx,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_ExecNotificationQueryAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_ExecMethod_Proxy(IWbemServices *This,const BSTR strObjectPath,const BSTR strMethodName,long lFlags,IWbemContext *pCtx,IWbemClassObject *pInParams,IWbemClassObject **ppOutParams,IWbemCallResult **ppCallResult);
  void __RPC_STUB IWbemServices_ExecMethod_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemServices_ExecMethodAsync_Proxy(IWbemServices *This,const BSTR strObjectPath,const BSTR strMethodName,long lFlags,IWbemContext *pCtx,IWbemClassObject *pInParams,IWbemObjectSink *pResponseHandler);
  void __RPC_STUB IWbemServices_ExecMethodAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemLocator_INTERFACE_DEFINED__
#define __IWbemLocator_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemLocator;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemLocator : public IUnknown {
  public:
    virtual HRESULT WINAPI ConnectServer(const BSTR strNetworkResource,const BSTR strUser,const BSTR strPassword,const BSTR strLocale,long lSecurityFlags,const BSTR strAuthority,IWbemContext *pCtx,IWbemServices **ppNamespace) = 0;
  };
#else
  typedef struct IWbemLocatorVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemLocator *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemLocator *This);
      ULONG (WINAPI *Release)(IWbemLocator *This);
      HRESULT (WINAPI *ConnectServer)(IWbemLocator *This,const BSTR strNetworkResource,const BSTR strUser,const BSTR strPassword,const BSTR strLocale,long lSecurityFlags,const BSTR strAuthority,IWbemContext *pCtx,IWbemServices **ppNamespace);
    END_INTERFACE
  } IWbemLocatorVtbl;
  struct IWbemLocator {
    CONST_VTBL struct IWbemLocatorVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemLocator_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemLocator_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemLocator_Release(This) (This)->lpVtbl->Release(This)
#define IWbemLocator_ConnectServer(This,strNetworkResource,strUser,strPassword,strLocale,lSecurityFlags,strAuthority,pCtx,ppNamespace) (This)->lpVtbl->ConnectServer(This,strNetworkResource,strUser,strPassword,strLocale,lSecurityFlags,strAuthority,pCtx,ppNamespace)
#endif
#endif
  HRESULT WINAPI IWbemLocator_ConnectServer_Proxy(IWbemLocator *This,const BSTR strNetworkResource,const BSTR strUser,const BSTR strPassword,const BSTR strLocale,long lSecurityFlags,const BSTR strAuthority,IWbemContext *pCtx,IWbemServices **ppNamespace);
  void __RPC_STUB IWbemLocator_ConnectServer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemObjectSink_INTERFACE_DEFINED__
#define __IWbemObjectSink_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemObjectSink;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemObjectSink : public IUnknown {
  public:
    virtual HRESULT WINAPI Indicate(long lObjectCount,IWbemClassObject **apObjArray) = 0;
    virtual HRESULT WINAPI SetStatus(long lFlags,HRESULT hResult,BSTR strParam,IWbemClassObject *pObjParam) = 0;
  };
#else
  typedef struct IWbemObjectSinkVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemObjectSink *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemObjectSink *This);
      ULONG (WINAPI *Release)(IWbemObjectSink *This);
      HRESULT (WINAPI *Indicate)(IWbemObjectSink *This,long lObjectCount,IWbemClassObject **apObjArray);
      HRESULT (WINAPI *SetStatus)(IWbemObjectSink *This,long lFlags,HRESULT hResult,BSTR strParam,IWbemClassObject *pObjParam);
    END_INTERFACE
  } IWbemObjectSinkVtbl;
  struct IWbemObjectSink {
    CONST_VTBL struct IWbemObjectSinkVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemObjectSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemObjectSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemObjectSink_Release(This) (This)->lpVtbl->Release(This)
#define IWbemObjectSink_Indicate(This,lObjectCount,apObjArray) (This)->lpVtbl->Indicate(This,lObjectCount,apObjArray)
#define IWbemObjectSink_SetStatus(This,lFlags,hResult,strParam,pObjParam) (This)->lpVtbl->SetStatus(This,lFlags,hResult,strParam,pObjParam)
#endif
#endif
  HRESULT WINAPI IWbemObjectSink_Indicate_Proxy(IWbemObjectSink *This,long lObjectCount,IWbemClassObject **apObjArray);
  void __RPC_STUB IWbemObjectSink_Indicate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemObjectSink_SetStatus_Proxy(IWbemObjectSink *This,long lFlags,HRESULT hResult,BSTR strParam,IWbemClassObject *pObjParam);
  void __RPC_STUB IWbemObjectSink_SetStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IEnumWbemClassObject_INTERFACE_DEFINED__
#define __IEnumWbemClassObject_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IEnumWbemClassObject;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumWbemClassObject : public IUnknown {
  public:
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Next(long lTimeout,ULONG uCount,IWbemClassObject **apObjects,ULONG *puReturned) = 0;
    virtual HRESULT WINAPI NextAsync(ULONG uCount,IWbemObjectSink *pSink) = 0;
    virtual HRESULT WINAPI Clone(IEnumWbemClassObject **ppEnum) = 0;
    virtual HRESULT WINAPI Skip(long lTimeout,ULONG nCount) = 0;
  };
#else
  typedef struct IEnumWbemClassObjectVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumWbemClassObject *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumWbemClassObject *This);
      ULONG (WINAPI *Release)(IEnumWbemClassObject *This);
      HRESULT (WINAPI *Reset)(IEnumWbemClassObject *This);
      HRESULT (WINAPI *Next)(IEnumWbemClassObject *This,long lTimeout,ULONG uCount,IWbemClassObject **apObjects,ULONG *puReturned);
      HRESULT (WINAPI *NextAsync)(IEnumWbemClassObject *This,ULONG uCount,IWbemObjectSink *pSink);
      HRESULT (WINAPI *Clone)(IEnumWbemClassObject *This,IEnumWbemClassObject **ppEnum);
      HRESULT (WINAPI *Skip)(IEnumWbemClassObject *This,long lTimeout,ULONG nCount);
    END_INTERFACE
  } IEnumWbemClassObjectVtbl;
  struct IEnumWbemClassObject {
    CONST_VTBL struct IEnumWbemClassObjectVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumWbemClassObject_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumWbemClassObject_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumWbemClassObject_Release(This) (This)->lpVtbl->Release(This)
#define IEnumWbemClassObject_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumWbemClassObject_Next(This,lTimeout,uCount,apObjects,puReturned) (This)->lpVtbl->Next(This,lTimeout,uCount,apObjects,puReturned)
#define IEnumWbemClassObject_NextAsync(This,uCount,pSink) (This)->lpVtbl->NextAsync(This,uCount,pSink)
#define IEnumWbemClassObject_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#define IEnumWbemClassObject_Skip(This,lTimeout,nCount) (This)->lpVtbl->Skip(This,lTimeout,nCount)
#endif
#endif
  HRESULT WINAPI IEnumWbemClassObject_Reset_Proxy(IEnumWbemClassObject *This);
  void __RPC_STUB IEnumWbemClassObject_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumWbemClassObject_Next_Proxy(IEnumWbemClassObject *This,long lTimeout,ULONG uCount,IWbemClassObject **apObjects,ULONG *puReturned);
  void __RPC_STUB IEnumWbemClassObject_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumWbemClassObject_NextAsync_Proxy(IEnumWbemClassObject *This,ULONG uCount,IWbemObjectSink *pSink);
  void __RPC_STUB IEnumWbemClassObject_NextAsync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumWbemClassObject_Clone_Proxy(IEnumWbemClassObject *This,IEnumWbemClassObject **ppEnum);
  void __RPC_STUB IEnumWbemClassObject_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumWbemClassObject_Skip_Proxy(IEnumWbemClassObject *This,long lTimeout,ULONG nCount);
  void __RPC_STUB IEnumWbemClassObject_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemCallResult_INTERFACE_DEFINED__
#define __IWbemCallResult_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemCallResult;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemCallResult : public IUnknown {
  public:
    virtual HRESULT WINAPI GetResultObject(long lTimeout,IWbemClassObject **ppResultObject) = 0;
    virtual HRESULT WINAPI GetResultString(long lTimeout,BSTR *pstrResultString) = 0;
    virtual HRESULT WINAPI GetResultServices(long lTimeout,IWbemServices **ppServices) = 0;
    virtual HRESULT WINAPI GetCallStatus(long lTimeout,long *plStatus) = 0;
  };
#else
  typedef struct IWbemCallResultVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemCallResult *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemCallResult *This);
      ULONG (WINAPI *Release)(IWbemCallResult *This);
      HRESULT (WINAPI *GetResultObject)(IWbemCallResult *This,long lTimeout,IWbemClassObject **ppResultObject);
      HRESULT (WINAPI *GetResultString)(IWbemCallResult *This,long lTimeout,BSTR *pstrResultString);
      HRESULT (WINAPI *GetResultServices)(IWbemCallResult *This,long lTimeout,IWbemServices **ppServices);
      HRESULT (WINAPI *GetCallStatus)(IWbemCallResult *This,long lTimeout,long *plStatus);
    END_INTERFACE
  } IWbemCallResultVtbl;
  struct IWbemCallResult {
    CONST_VTBL struct IWbemCallResultVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemCallResult_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemCallResult_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemCallResult_Release(This) (This)->lpVtbl->Release(This)
#define IWbemCallResult_GetResultObject(This,lTimeout,ppResultObject) (This)->lpVtbl->GetResultObject(This,lTimeout,ppResultObject)
#define IWbemCallResult_GetResultString(This,lTimeout,pstrResultString) (This)->lpVtbl->GetResultString(This,lTimeout,pstrResultString)
#define IWbemCallResult_GetResultServices(This,lTimeout,ppServices) (This)->lpVtbl->GetResultServices(This,lTimeout,ppServices)
#define IWbemCallResult_GetCallStatus(This,lTimeout,plStatus) (This)->lpVtbl->GetCallStatus(This,lTimeout,plStatus)
#endif
#endif
  HRESULT WINAPI IWbemCallResult_GetResultObject_Proxy(IWbemCallResult *This,long lTimeout,IWbemClassObject **ppResultObject);
  void __RPC_STUB IWbemCallResult_GetResultObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemCallResult_GetResultString_Proxy(IWbemCallResult *This,long lTimeout,BSTR *pstrResultString);
  void __RPC_STUB IWbemCallResult_GetResultString_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemCallResult_GetResultServices_Proxy(IWbemCallResult *This,long lTimeout,IWbemServices **ppServices);
  void __RPC_STUB IWbemCallResult_GetResultServices_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemCallResult_GetCallStatus_Proxy(IWbemCallResult *This,long lTimeout,long *plStatus);
  void __RPC_STUB IWbemCallResult_GetCallStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemContext_INTERFACE_DEFINED__
#define __IWbemContext_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemContext;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemContext : public IUnknown {
  public:
    virtual HRESULT WINAPI Clone(IWbemContext **ppNewCopy) = 0;
    virtual HRESULT WINAPI GetNames(long lFlags,SAFEARRAY **pNames) = 0;
    virtual HRESULT WINAPI BeginEnumeration(long lFlags) = 0;
    virtual HRESULT WINAPI Next(long lFlags,BSTR *pstrName,VARIANT *pValue) = 0;
    virtual HRESULT WINAPI EndEnumeration(void) = 0;
    virtual HRESULT WINAPI SetValue(LPCWSTR wszName,long lFlags,VARIANT *pValue) = 0;
    virtual HRESULT WINAPI GetValue(LPCWSTR wszName,long lFlags,VARIANT *pValue) = 0;
    virtual HRESULT WINAPI DeleteValue(LPCWSTR wszName,long lFlags) = 0;
    virtual HRESULT WINAPI DeleteAll(void) = 0;
  };
#else
  typedef struct IWbemContextVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemContext *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemContext *This);
      ULONG (WINAPI *Release)(IWbemContext *This);
      HRESULT (WINAPI *Clone)(IWbemContext *This,IWbemContext **ppNewCopy);
      HRESULT (WINAPI *GetNames)(IWbemContext *This,long lFlags,SAFEARRAY **pNames);
      HRESULT (WINAPI *BeginEnumeration)(IWbemContext *This,long lFlags);
      HRESULT (WINAPI *Next)(IWbemContext *This,long lFlags,BSTR *pstrName,VARIANT *pValue);
      HRESULT (WINAPI *EndEnumeration)(IWbemContext *This);
      HRESULT (WINAPI *SetValue)(IWbemContext *This,LPCWSTR wszName,long lFlags,VARIANT *pValue);
      HRESULT (WINAPI *GetValue)(IWbemContext *This,LPCWSTR wszName,long lFlags,VARIANT *pValue);
      HRESULT (WINAPI *DeleteValue)(IWbemContext *This,LPCWSTR wszName,long lFlags);
      HRESULT (WINAPI *DeleteAll)(IWbemContext *This);
    END_INTERFACE
  } IWbemContextVtbl;
  struct IWbemContext {
    CONST_VTBL struct IWbemContextVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemContext_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemContext_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemContext_Release(This) (This)->lpVtbl->Release(This)
#define IWbemContext_Clone(This,ppNewCopy) (This)->lpVtbl->Clone(This,ppNewCopy)
#define IWbemContext_GetNames(This,lFlags,pNames) (This)->lpVtbl->GetNames(This,lFlags,pNames)
#define IWbemContext_BeginEnumeration(This,lFlags) (This)->lpVtbl->BeginEnumeration(This,lFlags)
#define IWbemContext_Next(This,lFlags,pstrName,pValue) (This)->lpVtbl->Next(This,lFlags,pstrName,pValue)
#define IWbemContext_EndEnumeration(This) (This)->lpVtbl->EndEnumeration(This)
#define IWbemContext_SetValue(This,wszName,lFlags,pValue) (This)->lpVtbl->SetValue(This,wszName,lFlags,pValue)
#define IWbemContext_GetValue(This,wszName,lFlags,pValue) (This)->lpVtbl->GetValue(This,wszName,lFlags,pValue)
#define IWbemContext_DeleteValue(This,wszName,lFlags) (This)->lpVtbl->DeleteValue(This,wszName,lFlags)
#define IWbemContext_DeleteAll(This) (This)->lpVtbl->DeleteAll(This)
#endif
#endif
  HRESULT WINAPI IWbemContext_Clone_Proxy(IWbemContext *This,IWbemContext **ppNewCopy);
  void __RPC_STUB IWbemContext_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemContext_GetNames_Proxy(IWbemContext *This,long lFlags,SAFEARRAY **pNames);
  void __RPC_STUB IWbemContext_GetNames_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemContext_BeginEnumeration_Proxy(IWbemContext *This,long lFlags);
  void __RPC_STUB IWbemContext_BeginEnumeration_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemContext_Next_Proxy(IWbemContext *This,long lFlags,BSTR *pstrName,VARIANT *pValue);
  void __RPC_STUB IWbemContext_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemContext_EndEnumeration_Proxy(IWbemContext *This);
  void __RPC_STUB IWbemContext_EndEnumeration_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemContext_SetValue_Proxy(IWbemContext *This,LPCWSTR wszName,long lFlags,VARIANT *pValue);
  void __RPC_STUB IWbemContext_SetValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemContext_GetValue_Proxy(IWbemContext *This,LPCWSTR wszName,long lFlags,VARIANT *pValue);
  void __RPC_STUB IWbemContext_GetValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemContext_DeleteValue_Proxy(IWbemContext *This,LPCWSTR wszName,long lFlags);
  void __RPC_STUB IWbemContext_DeleteValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemContext_DeleteAll_Proxy(IWbemContext *This);
  void __RPC_STUB IWbemContext_DeleteAll_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IUnsecuredApartment_INTERFACE_DEFINED__
#define __IUnsecuredApartment_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IUnsecuredApartment;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IUnsecuredApartment : public IUnknown {
  public:
    virtual HRESULT WINAPI CreateObjectStub(IUnknown *pObject,IUnknown **ppStub) = 0;
  };
#else
  typedef struct IUnsecuredApartmentVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IUnsecuredApartment *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IUnsecuredApartment *This);
      ULONG (WINAPI *Release)(IUnsecuredApartment *This);
      HRESULT (WINAPI *CreateObjectStub)(IUnsecuredApartment *This,IUnknown *pObject,IUnknown **ppStub);
    END_INTERFACE
  } IUnsecuredApartmentVtbl;
  struct IUnsecuredApartment {
    CONST_VTBL struct IUnsecuredApartmentVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IUnsecuredApartment_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IUnsecuredApartment_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUnsecuredApartment_Release(This) (This)->lpVtbl->Release(This)
#define IUnsecuredApartment_CreateObjectStub(This,pObject,ppStub) (This)->lpVtbl->CreateObjectStub(This,pObject,ppStub)
#endif
#endif
  HRESULT WINAPI IUnsecuredApartment_CreateObjectStub_Proxy(IUnsecuredApartment *This,IUnknown *pObject,IUnknown **ppStub);
  void __RPC_STUB IUnsecuredApartment_CreateObjectStub_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemUnsecuredApartment_INTERFACE_DEFINED__
#define __IWbemUnsecuredApartment_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemUnsecuredApartment;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemUnsecuredApartment : public IUnsecuredApartment {
  public:
    virtual HRESULT WINAPI CreateSinkStub(IWbemObjectSink *pSink,DWORD dwFlags,LPCWSTR wszReserved,IWbemObjectSink **ppStub) = 0;
  };
#else
  typedef struct IWbemUnsecuredApartmentVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemUnsecuredApartment *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemUnsecuredApartment *This);
      ULONG (WINAPI *Release)(IWbemUnsecuredApartment *This);
      HRESULT (WINAPI *CreateObjectStub)(IWbemUnsecuredApartment *This,IUnknown *pObject,IUnknown **ppStub);
      HRESULT (WINAPI *CreateSinkStub)(IWbemUnsecuredApartment *This,IWbemObjectSink *pSink,DWORD dwFlags,LPCWSTR wszReserved,IWbemObjectSink **ppStub);
    END_INTERFACE
  } IWbemUnsecuredApartmentVtbl;
  struct IWbemUnsecuredApartment {
    CONST_VTBL struct IWbemUnsecuredApartmentVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemUnsecuredApartment_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemUnsecuredApartment_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemUnsecuredApartment_Release(This) (This)->lpVtbl->Release(This)
#define IWbemUnsecuredApartment_CreateObjectStub(This,pObject,ppStub) (This)->lpVtbl->CreateObjectStub(This,pObject,ppStub)
#define IWbemUnsecuredApartment_CreateSinkStub(This,pSink,dwFlags,wszReserved,ppStub) (This)->lpVtbl->CreateSinkStub(This,pSink,dwFlags,wszReserved,ppStub)
#endif
#endif
  HRESULT WINAPI IWbemUnsecuredApartment_CreateSinkStub_Proxy(IWbemUnsecuredApartment *This,IWbemObjectSink *pSink,DWORD dwFlags,LPCWSTR wszReserved,IWbemObjectSink **ppStub);
  void __RPC_STUB IWbemUnsecuredApartment_CreateSinkStub_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemStatusCodeText_INTERFACE_DEFINED__
#define __IWbemStatusCodeText_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemStatusCodeText;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemStatusCodeText : public IUnknown {
  public:
    virtual HRESULT WINAPI GetErrorCodeText(HRESULT hRes,LCID LocaleId,long lFlags,BSTR *MessageText) = 0;
    virtual HRESULT WINAPI GetFacilityCodeText(HRESULT hRes,LCID LocaleId,long lFlags,BSTR *MessageText) = 0;
  };
#else
  typedef struct IWbemStatusCodeTextVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemStatusCodeText *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemStatusCodeText *This);
      ULONG (WINAPI *Release)(IWbemStatusCodeText *This);
      HRESULT (WINAPI *GetErrorCodeText)(IWbemStatusCodeText *This,HRESULT hRes,LCID LocaleId,long lFlags,BSTR *MessageText);
      HRESULT (WINAPI *GetFacilityCodeText)(IWbemStatusCodeText *This,HRESULT hRes,LCID LocaleId,long lFlags,BSTR *MessageText);
    END_INTERFACE
  } IWbemStatusCodeTextVtbl;
  struct IWbemStatusCodeText {
    CONST_VTBL struct IWbemStatusCodeTextVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemStatusCodeText_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemStatusCodeText_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemStatusCodeText_Release(This) (This)->lpVtbl->Release(This)
#define IWbemStatusCodeText_GetErrorCodeText(This,hRes,LocaleId,lFlags,MessageText) (This)->lpVtbl->GetErrorCodeText(This,hRes,LocaleId,lFlags,MessageText)
#define IWbemStatusCodeText_GetFacilityCodeText(This,hRes,LocaleId,lFlags,MessageText) (This)->lpVtbl->GetFacilityCodeText(This,hRes,LocaleId,lFlags,MessageText)
#endif
#endif
  HRESULT WINAPI IWbemStatusCodeText_GetErrorCodeText_Proxy(IWbemStatusCodeText *This,HRESULT hRes,LCID LocaleId,long lFlags,BSTR *MessageText);
  void __RPC_STUB IWbemStatusCodeText_GetErrorCodeText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemStatusCodeText_GetFacilityCodeText_Proxy(IWbemStatusCodeText *This,HRESULT hRes,LCID LocaleId,long lFlags,BSTR *MessageText);
  void __RPC_STUB IWbemStatusCodeText_GetFacilityCodeText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemBackupRestore_INTERFACE_DEFINED__
#define __IWbemBackupRestore_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemBackupRestore;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemBackupRestore : public IUnknown {
  public:
    virtual HRESULT WINAPI Backup(LPCWSTR strBackupToFile,long lFlags) = 0;
    virtual HRESULT WINAPI Restore(LPCWSTR strRestoreFromFile,long lFlags) = 0;
  };
#else
  typedef struct IWbemBackupRestoreVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemBackupRestore *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemBackupRestore *This);
      ULONG (WINAPI *Release)(IWbemBackupRestore *This);
      HRESULT (WINAPI *Backup)(IWbemBackupRestore *This,LPCWSTR strBackupToFile,long lFlags);
      HRESULT (WINAPI *Restore)(IWbemBackupRestore *This,LPCWSTR strRestoreFromFile,long lFlags);
    END_INTERFACE
  } IWbemBackupRestoreVtbl;
  struct IWbemBackupRestore {
    CONST_VTBL struct IWbemBackupRestoreVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemBackupRestore_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemBackupRestore_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemBackupRestore_Release(This) (This)->lpVtbl->Release(This)
#define IWbemBackupRestore_Backup(This,strBackupToFile,lFlags) (This)->lpVtbl->Backup(This,strBackupToFile,lFlags)
#define IWbemBackupRestore_Restore(This,strRestoreFromFile,lFlags) (This)->lpVtbl->Restore(This,strRestoreFromFile,lFlags)
#endif
#endif
  HRESULT WINAPI IWbemBackupRestore_Backup_Proxy(IWbemBackupRestore *This,LPCWSTR strBackupToFile,long lFlags);
  void __RPC_STUB IWbemBackupRestore_Backup_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemBackupRestore_Restore_Proxy(IWbemBackupRestore *This,LPCWSTR strRestoreFromFile,long lFlags);
  void __RPC_STUB IWbemBackupRestore_Restore_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemBackupRestoreEx_INTERFACE_DEFINED__
#define __IWbemBackupRestoreEx_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemBackupRestoreEx;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemBackupRestoreEx : public IWbemBackupRestore {
  public:
    virtual HRESULT WINAPI Pause(void) = 0;
    virtual HRESULT WINAPI Resume(void) = 0;
  };
#else
  typedef struct IWbemBackupRestoreExVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemBackupRestoreEx *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemBackupRestoreEx *This);
      ULONG (WINAPI *Release)(IWbemBackupRestoreEx *This);
      HRESULT (WINAPI *Backup)(IWbemBackupRestoreEx *This,LPCWSTR strBackupToFile,long lFlags);
      HRESULT (WINAPI *Restore)(IWbemBackupRestoreEx *This,LPCWSTR strRestoreFromFile,long lFlags);
      HRESULT (WINAPI *Pause)(IWbemBackupRestoreEx *This);
      HRESULT (WINAPI *Resume)(IWbemBackupRestoreEx *This);
    END_INTERFACE
  } IWbemBackupRestoreExVtbl;
  struct IWbemBackupRestoreEx {
    CONST_VTBL struct IWbemBackupRestoreExVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemBackupRestoreEx_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemBackupRestoreEx_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemBackupRestoreEx_Release(This) (This)->lpVtbl->Release(This)
#define IWbemBackupRestoreEx_Backup(This,strBackupToFile,lFlags) (This)->lpVtbl->Backup(This,strBackupToFile,lFlags)
#define IWbemBackupRestoreEx_Restore(This,strRestoreFromFile,lFlags) (This)->lpVtbl->Restore(This,strRestoreFromFile,lFlags)
#define IWbemBackupRestoreEx_Pause(This) (This)->lpVtbl->Pause(This)
#define IWbemBackupRestoreEx_Resume(This) (This)->lpVtbl->Resume(This)
#endif
#endif
  HRESULT WINAPI IWbemBackupRestoreEx_Pause_Proxy(IWbemBackupRestoreEx *This);
  void __RPC_STUB IWbemBackupRestoreEx_Pause_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemBackupRestoreEx_Resume_Proxy(IWbemBackupRestoreEx *This);
  void __RPC_STUB IWbemBackupRestoreEx_Resume_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemRefresher_INTERFACE_DEFINED__
#define __IWbemRefresher_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemRefresher;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemRefresher : public IUnknown {
  public:
    virtual HRESULT WINAPI Refresh(long lFlags) = 0;
  };
#else
  typedef struct IWbemRefresherVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemRefresher *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemRefresher *This);
      ULONG (WINAPI *Release)(IWbemRefresher *This);
      HRESULT (WINAPI *Refresh)(IWbemRefresher *This,long lFlags);
    END_INTERFACE
  } IWbemRefresherVtbl;
  struct IWbemRefresher {
    CONST_VTBL struct IWbemRefresherVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemRefresher_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemRefresher_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemRefresher_Release(This) (This)->lpVtbl->Release(This)
#define IWbemRefresher_Refresh(This,lFlags) (This)->lpVtbl->Refresh(This,lFlags)
#endif
#endif
  HRESULT WINAPI IWbemRefresher_Refresh_Proxy(IWbemRefresher *This,long lFlags);
  void __RPC_STUB IWbemRefresher_Refresh_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemHiPerfEnum_INTERFACE_DEFINED__
#define __IWbemHiPerfEnum_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemHiPerfEnum;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemHiPerfEnum : public IUnknown {
  public:
    virtual HRESULT WINAPI AddObjects(long lFlags,ULONG uNumObjects,long *apIds,IWbemObjectAccess **apObj) = 0;
    virtual HRESULT WINAPI RemoveObjects(long lFlags,ULONG uNumObjects,long *apIds) = 0;
    virtual HRESULT WINAPI GetObjects(long lFlags,ULONG uNumObjects,IWbemObjectAccess **apObj,ULONG *puReturned) = 0;
    virtual HRESULT WINAPI RemoveAll(long lFlags) = 0;
  };
#else
  typedef struct IWbemHiPerfEnumVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemHiPerfEnum *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemHiPerfEnum *This);
      ULONG (WINAPI *Release)(IWbemHiPerfEnum *This);
      HRESULT (WINAPI *AddObjects)(IWbemHiPerfEnum *This,long lFlags,ULONG uNumObjects,long *apIds,IWbemObjectAccess **apObj);
      HRESULT (WINAPI *RemoveObjects)(IWbemHiPerfEnum *This,long lFlags,ULONG uNumObjects,long *apIds);
      HRESULT (WINAPI *GetObjects)(IWbemHiPerfEnum *This,long lFlags,ULONG uNumObjects,IWbemObjectAccess **apObj,ULONG *puReturned);
      HRESULT (WINAPI *RemoveAll)(IWbemHiPerfEnum *This,long lFlags);
    END_INTERFACE
  } IWbemHiPerfEnumVtbl;
  struct IWbemHiPerfEnum {
    CONST_VTBL struct IWbemHiPerfEnumVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemHiPerfEnum_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemHiPerfEnum_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemHiPerfEnum_Release(This) (This)->lpVtbl->Release(This)
#define IWbemHiPerfEnum_AddObjects(This,lFlags,uNumObjects,apIds,apObj) (This)->lpVtbl->AddObjects(This,lFlags,uNumObjects,apIds,apObj)
#define IWbemHiPerfEnum_RemoveObjects(This,lFlags,uNumObjects,apIds) (This)->lpVtbl->RemoveObjects(This,lFlags,uNumObjects,apIds)
#define IWbemHiPerfEnum_GetObjects(This,lFlags,uNumObjects,apObj,puReturned) (This)->lpVtbl->GetObjects(This,lFlags,uNumObjects,apObj,puReturned)
#define IWbemHiPerfEnum_RemoveAll(This,lFlags) (This)->lpVtbl->RemoveAll(This,lFlags)
#endif
#endif
  HRESULT WINAPI IWbemHiPerfEnum_AddObjects_Proxy(IWbemHiPerfEnum *This,long lFlags,ULONG uNumObjects,long *apIds,IWbemObjectAccess **apObj);
  void __RPC_STUB IWbemHiPerfEnum_AddObjects_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemHiPerfEnum_RemoveObjects_Proxy(IWbemHiPerfEnum *This,long lFlags,ULONG uNumObjects,long *apIds);
  void __RPC_STUB IWbemHiPerfEnum_RemoveObjects_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemHiPerfEnum_GetObjects_Proxy(IWbemHiPerfEnum *This,long lFlags,ULONG uNumObjects,IWbemObjectAccess **apObj,ULONG *puReturned);
  void __RPC_STUB IWbemHiPerfEnum_GetObjects_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemHiPerfEnum_RemoveAll_Proxy(IWbemHiPerfEnum *This,long lFlags);
  void __RPC_STUB IWbemHiPerfEnum_RemoveAll_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWbemConfigureRefresher_INTERFACE_DEFINED__
#define __IWbemConfigureRefresher_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemConfigureRefresher;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemConfigureRefresher : public IUnknown {
  public:
    virtual HRESULT WINAPI AddObjectByPath(IWbemServices *pNamespace,LPCWSTR wszPath,long lFlags,IWbemContext *pContext,IWbemClassObject **ppRefreshable,long *plId) = 0;
    virtual HRESULT WINAPI AddObjectByTemplate(IWbemServices *pNamespace,IWbemClassObject *pTemplate,long lFlags,IWbemContext *pContext,IWbemClassObject **ppRefreshable,long *plId) = 0;
    virtual HRESULT WINAPI AddRefresher(IWbemRefresher *pRefresher,long lFlags,long *plId) = 0;
    virtual HRESULT WINAPI Remove(long lId,long lFlags) = 0;
    virtual HRESULT WINAPI AddEnum(IWbemServices *pNamespace,LPCWSTR wszClassName,long lFlags,IWbemContext *pContext,IWbemHiPerfEnum **ppEnum,long *plId) = 0;
  };
#else
  typedef struct IWbemConfigureRefresherVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemConfigureRefresher *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemConfigureRefresher *This);
      ULONG (WINAPI *Release)(IWbemConfigureRefresher *This);
      HRESULT (WINAPI *AddObjectByPath)(IWbemConfigureRefresher *This,IWbemServices *pNamespace,LPCWSTR wszPath,long lFlags,IWbemContext *pContext,IWbemClassObject **ppRefreshable,long *plId);
      HRESULT (WINAPI *AddObjectByTemplate)(IWbemConfigureRefresher *This,IWbemServices *pNamespace,IWbemClassObject *pTemplate,long lFlags,IWbemContext *pContext,IWbemClassObject **ppRefreshable,long *plId);
      HRESULT (WINAPI *AddRefresher)(IWbemConfigureRefresher *This,IWbemRefresher *pRefresher,long lFlags,long *plId);
      HRESULT (WINAPI *Remove)(IWbemConfigureRefresher *This,long lId,long lFlags);
      HRESULT (WINAPI *AddEnum)(IWbemConfigureRefresher *This,IWbemServices *pNamespace,LPCWSTR wszClassName,long lFlags,IWbemContext *pContext,IWbemHiPerfEnum **ppEnum,long *plId);
    END_INTERFACE
  } IWbemConfigureRefresherVtbl;
  struct IWbemConfigureRefresher {
    CONST_VTBL struct IWbemConfigureRefresherVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemConfigureRefresher_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemConfigureRefresher_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemConfigureRefresher_Release(This) (This)->lpVtbl->Release(This)
#define IWbemConfigureRefresher_AddObjectByPath(This,pNamespace,wszPath,lFlags,pContext,ppRefreshable,plId) (This)->lpVtbl->AddObjectByPath(This,pNamespace,wszPath,lFlags,pContext,ppRefreshable,plId)
#define IWbemConfigureRefresher_AddObjectByTemplate(This,pNamespace,pTemplate,lFlags,pContext,ppRefreshable,plId) (This)->lpVtbl->AddObjectByTemplate(This,pNamespace,pTemplate,lFlags,pContext,ppRefreshable,plId)
#define IWbemConfigureRefresher_AddRefresher(This,pRefresher,lFlags,plId) (This)->lpVtbl->AddRefresher(This,pRefresher,lFlags,plId)
#define IWbemConfigureRefresher_Remove(This,lId,lFlags) (This)->lpVtbl->Remove(This,lId,lFlags)
#define IWbemConfigureRefresher_AddEnum(This,pNamespace,wszClassName,lFlags,pContext,ppEnum,plId) (This)->lpVtbl->AddEnum(This,pNamespace,wszClassName,lFlags,pContext,ppEnum,plId)
#endif
#endif
  HRESULT WINAPI IWbemConfigureRefresher_AddObjectByPath_Proxy(IWbemConfigureRefresher *This,IWbemServices *pNamespace,LPCWSTR wszPath,long lFlags,IWbemContext *pContext,IWbemClassObject **ppRefreshable,long *plId);
  void __RPC_STUB IWbemConfigureRefresher_AddObjectByPath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemConfigureRefresher_AddObjectByTemplate_Proxy(IWbemConfigureRefresher *This,IWbemServices *pNamespace,IWbemClassObject *pTemplate,long lFlags,IWbemContext *pContext,IWbemClassObject **ppRefreshable,long *plId);
  void __RPC_STUB IWbemConfigureRefresher_AddObjectByTemplate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemConfigureRefresher_AddRefresher_Proxy(IWbemConfigureRefresher *This,IWbemRefresher *pRefresher,long lFlags,long *plId);
  void __RPC_STUB IWbemConfigureRefresher_AddRefresher_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemConfigureRefresher_Remove_Proxy(IWbemConfigureRefresher *This,long lId,long lFlags);
  void __RPC_STUB IWbemConfigureRefresher_Remove_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemConfigureRefresher_AddEnum_Proxy(IWbemConfigureRefresher *This,IWbemServices *pNamespace,LPCWSTR wszClassName,long lFlags,IWbemContext *pContext,IWbemHiPerfEnum **ppEnum,long *plId);
  void __RPC_STUB IWbemConfigureRefresher_AddEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_WbemLocator;
#ifdef __cplusplus
  class WbemLocator;
#endif
  EXTERN_C const CLSID CLSID_WbemContext;
#ifdef __cplusplus
  class WbemContext;
#endif
  EXTERN_C const CLSID CLSID_UnsecuredApartment;
#ifdef __cplusplus
  class UnsecuredApartment;
#endif
  EXTERN_C const CLSID CLSID_WbemClassObject;
#ifdef __cplusplus
  class WbemClassObject;
#endif
  EXTERN_C const CLSID CLSID_MofCompiler;
#ifdef __cplusplus
  class MofCompiler;
#endif
  EXTERN_C const CLSID CLSID_WbemStatusCodeText;
#ifdef __cplusplus
  class WbemStatusCodeText;
#endif
  EXTERN_C const CLSID CLSID_WbemBackupRestore;
#ifdef __cplusplus
  class WbemBackupRestore;
#endif
  EXTERN_C const CLSID CLSID_WbemRefresher;
#ifdef __cplusplus
  class WbemRefresher;
#endif
  EXTERN_C const CLSID CLSID_WbemObjectTextSrc;
#ifdef __cplusplus
  class WbemObjectTextSrc;
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0000_v0_0_s_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0116_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0116_v0_0_s_ifspec;

#ifndef __IWbemShutdown_INTERFACE_DEFINED__
#define __IWbemShutdown_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemShutdown;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemShutdown : public IUnknown {
  public:
    virtual HRESULT WINAPI Shutdown(LONG uReason,ULONG uMaxMilliseconds,IWbemContext *pCtx) = 0;
  };
#else
  typedef struct IWbemShutdownVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemShutdown *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemShutdown *This);
      ULONG (WINAPI *Release)(IWbemShutdown *This);
      HRESULT (WINAPI *Shutdown)(IWbemShutdown *This,LONG uReason,ULONG uMaxMilliseconds,IWbemContext *pCtx);
    END_INTERFACE
  } IWbemShutdownVtbl;
  struct IWbemShutdown {
    CONST_VTBL struct IWbemShutdownVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemShutdown_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemShutdown_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemShutdown_Release(This) (This)->lpVtbl->Release(This)
#define IWbemShutdown_Shutdown(This,uReason,uMaxMilliseconds,pCtx) (This)->lpVtbl->Shutdown(This,uReason,uMaxMilliseconds,pCtx)
#endif
#endif
  HRESULT WINAPI IWbemShutdown_Shutdown_Proxy(IWbemShutdown *This,LONG uReason,ULONG uMaxMilliseconds,IWbemContext *pCtx);
  void __RPC_STUB IWbemShutdown_Shutdown_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef enum tag_WMI_OBJ_TEXT {
    WMI_OBJ_TEXT_CIM_DTD_2_0 = 1,WMI_OBJ_TEXT_WMI_DTD_2_0 = 2,WMI_OBJ_TEXT_WMI_EXT1 = 3,WMI_OBJ_TEXT_WMI_EXT2 = 4,WMI_OBJ_TEXT_WMI_EXT3 = 5,
    WMI_OBJ_TEXT_WMI_EXT4 = 6,WMI_OBJ_TEXT_WMI_EXT5 = 7,WMI_OBJ_TEXT_WMI_EXT6 = 8,WMI_OBJ_TEXT_WMI_EXT7 = 9,WMI_OBJ_TEXT_WMI_EXT8 = 10,
    WMI_OBJ_TEXT_WMI_EXT9 = 11,WMI_OBJ_TEXT_WMI_EXT10 = 12,WMI_OBJ_TEXT_LAST = 13
  } WMI_OBJ_TEXT;

  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0123_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0123_v0_0_s_ifspec;
#ifndef __IWbemObjectTextSrc_INTERFACE_DEFINED__
#define __IWbemObjectTextSrc_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWbemObjectTextSrc;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWbemObjectTextSrc : public IUnknown {
  public:
    virtual HRESULT WINAPI GetText(long lFlags,IWbemClassObject *pObj,ULONG uObjTextFormat,IWbemContext *pCtx,BSTR *strText) = 0;
    virtual HRESULT WINAPI CreateFromText(long lFlags,BSTR strText,ULONG uObjTextFormat,IWbemContext *pCtx,IWbemClassObject **pNewObj) = 0;
  };
#else
  typedef struct IWbemObjectTextSrcVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWbemObjectTextSrc *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWbemObjectTextSrc *This);
      ULONG (WINAPI *Release)(IWbemObjectTextSrc *This);
      HRESULT (WINAPI *GetText)(IWbemObjectTextSrc *This,long lFlags,IWbemClassObject *pObj,ULONG uObjTextFormat,IWbemContext *pCtx,BSTR *strText);
      HRESULT (WINAPI *CreateFromText)(IWbemObjectTextSrc *This,long lFlags,BSTR strText,ULONG uObjTextFormat,IWbemContext *pCtx,IWbemClassObject **pNewObj);
    END_INTERFACE
  } IWbemObjectTextSrcVtbl;
  struct IWbemObjectTextSrc {
    CONST_VTBL struct IWbemObjectTextSrcVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWbemObjectTextSrc_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWbemObjectTextSrc_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWbemObjectTextSrc_Release(This) (This)->lpVtbl->Release(This)
#define IWbemObjectTextSrc_GetText(This,lFlags,pObj,uObjTextFormat,pCtx,strText) (This)->lpVtbl->GetText(This,lFlags,pObj,uObjTextFormat,pCtx,strText)
#define IWbemObjectTextSrc_CreateFromText(This,lFlags,strText,uObjTextFormat,pCtx,pNewObj) (This)->lpVtbl->CreateFromText(This,lFlags,strText,uObjTextFormat,pCtx,pNewObj)
#endif
#endif
  HRESULT WINAPI IWbemObjectTextSrc_GetText_Proxy(IWbemObjectTextSrc *This,long lFlags,IWbemClassObject *pObj,ULONG uObjTextFormat,IWbemContext *pCtx,BSTR *strText);
  void __RPC_STUB IWbemObjectTextSrc_GetText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWbemObjectTextSrc_CreateFromText_Proxy(IWbemObjectTextSrc *This,long lFlags,BSTR strText,ULONG uObjTextFormat,IWbemContext *pCtx,IWbemClassObject **pNewObj);
  void __RPC_STUB IWbemObjectTextSrc_CreateFromText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef struct tag_CompileStatusInfo {
    long lPhaseError;
    HRESULT hRes;
    long ObjectNum;
    long FirstLine;
    long LastLine;
    DWORD dwOutFlags;
  } WBEM_COMPILE_STATUS_INFO;

  typedef enum tag_WBEM_COMPILER_OPTIONS {
    WBEM_FLAG_CHECK_ONLY = 0x1,WBEM_FLAG_AUTORECOVER = 0x2,WBEM_FLAG_WMI_CHECK = 0x4,WBEM_FLAG_CONSOLE_PRINT = 0x8,WBEM_FLAG_DONT_ADD_TO_LIST = 0x10,
    WBEM_FLAG_SPLIT_FILES = 0x20,WBEM_FLAG_STORE_FILE = 0x100
  } WBEM_COMPILER_OPTIONS;

  typedef enum tag_WBEM_CONNECT_OPTIONS {
    WBEM_FLAG_CONNECT_REPOSITORY_ONLY = 0x40,WBEM_FLAG_CONNECT_USE_MAX_WAIT = 0x80,WBEM_FLAG_CONNECT_PROVIDERS = 0x100
  } WBEM_CONNECT_OPTIONS;

  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0125_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0125_v0_0_s_ifspec;
#ifndef __IMofCompiler_INTERFACE_DEFINED__
#define __IMofCompiler_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IMofCompiler;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IMofCompiler : public IUnknown {
  public:
    virtual HRESULT WINAPI CompileFile(LPWSTR FileName,LPWSTR ServerAndNamespace,LPWSTR User,LPWSTR Authority,LPWSTR Password,LONG lOptionFlags,LONG lClassFlags,LONG lInstanceFlags,WBEM_COMPILE_STATUS_INFO *pInfo) = 0;
    virtual HRESULT WINAPI CompileBuffer(long BuffSize,BYTE *pBuffer,LPWSTR ServerAndNamespace,LPWSTR User,LPWSTR Authority,LPWSTR Password,LONG lOptionFlags,LONG lClassFlags,LONG lInstanceFlags,WBEM_COMPILE_STATUS_INFO *pInfo) = 0;
    virtual HRESULT WINAPI CreateBMOF(LPWSTR TextFileName,LPWSTR BMOFFileName,LPWSTR ServerAndNamespace,LONG lOptionFlags,LONG lClassFlags,LONG lInstanceFlags,WBEM_COMPILE_STATUS_INFO *pInfo) = 0;
  };
#else
  typedef struct IMofCompilerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IMofCompiler *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IMofCompiler *This);
      ULONG (WINAPI *Release)(IMofCompiler *This);
      HRESULT (WINAPI *CompileFile)(IMofCompiler *This,LPWSTR FileName,LPWSTR ServerAndNamespace,LPWSTR User,LPWSTR Authority,LPWSTR Password,LONG lOptionFlags,LONG lClassFlags,LONG lInstanceFlags,WBEM_COMPILE_STATUS_INFO *pInfo);
      HRESULT (WINAPI *CompileBuffer)(IMofCompiler *This,long BuffSize,BYTE *pBuffer,LPWSTR ServerAndNamespace,LPWSTR User,LPWSTR Authority,LPWSTR Password,LONG lOptionFlags,LONG lClassFlags,LONG lInstanceFlags,WBEM_COMPILE_STATUS_INFO *pInfo);
      HRESULT (WINAPI *CreateBMOF)(IMofCompiler *This,LPWSTR TextFileName,LPWSTR BMOFFileName,LPWSTR ServerAndNamespace,LONG lOptionFlags,LONG lClassFlags,LONG lInstanceFlags,WBEM_COMPILE_STATUS_INFO *pInfo);
    END_INTERFACE
  } IMofCompilerVtbl;
  struct IMofCompiler {
    CONST_VTBL struct IMofCompilerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IMofCompiler_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMofCompiler_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMofCompiler_Release(This) (This)->lpVtbl->Release(This)
#define IMofCompiler_CompileFile(This,FileName,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo) (This)->lpVtbl->CompileFile(This,FileName,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)
#define IMofCompiler_CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo) (This)->lpVtbl->CompileBuffer(This,BuffSize,pBuffer,ServerAndNamespace,User,Authority,Password,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)
#define IMofCompiler_CreateBMOF(This,TextFileName,BMOFFileName,ServerAndNamespace,lOptionFlags,lClassFlags,lInstanceFlags,pInfo) (This)->lpVtbl->CreateBMOF(This,TextFileName,BMOFFileName,ServerAndNamespace,lOptionFlags,lClassFlags,lInstanceFlags,pInfo)
#endif
#endif
  HRESULT WINAPI IMofCompiler_CompileFile_Proxy(IMofCompiler *This,LPWSTR FileName,LPWSTR ServerAndNamespace,LPWSTR User,LPWSTR Authority,LPWSTR Password,LONG lOptionFlags,LONG lClassFlags,LONG lInstanceFlags,WBEM_COMPILE_STATUS_INFO *pInfo);
  void __RPC_STUB IMofCompiler_CompileFile_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IMofCompiler_CompileBuffer_Proxy(IMofCompiler *This,long BuffSize,BYTE *pBuffer,LPWSTR ServerAndNamespace,LPWSTR User,LPWSTR Authority,LPWSTR Password,LONG lOptionFlags,LONG lClassFlags,LONG lInstanceFlags,WBEM_COMPILE_STATUS_INFO *pInfo);
  void __RPC_STUB IMofCompiler_CompileBuffer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IMofCompiler_CreateBMOF_Proxy(IMofCompiler *This,LPWSTR TextFileName,LPWSTR BMOFFileName,LPWSTR ServerAndNamespace,LONG lOptionFlags,LONG lClassFlags,LONG lInstanceFlags,WBEM_COMPILE_STATUS_INFO *pInfo);
  void __RPC_STUB IMofCompiler_CreateBMOF_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef enum tag_WBEM_UNSECAPP_FLAG_TYPE {
    WBEM_FLAG_UNSECAPP_DEFAULT_CHECK_ACCESS = 0,WBEM_FLAG_UNSECAPP_CHECK_ACCESS = 1,WBEM_FLAG_UNSECAPP_DONT_CHECK_ACCESS = 2
  } WBEM_UNSECAPP_FLAG_TYPE;

  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0127_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0127_v0_0_s_ifspec;

  typedef enum tag_WBEM_INFORMATION_FLAG_TYPE {
    WBEM_FLAG_SHORT_NAME = 0x1,WBEM_FLAG_LONG_NAME = 0x2
  } WBEM_INFORMATION_FLAG_TYPE;

  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0128_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_wbemcli_0128_v0_0_s_ifspec;

  unsigned long __RPC_API BSTR_UserSize(unsigned long *,unsigned long,BSTR *);
  unsigned char *__RPC_API BSTR_UserMarshal(unsigned long *,unsigned char *,BSTR *);
  unsigned char *__RPC_API BSTR_UserUnmarshal(unsigned long *,unsigned char *,BSTR *);
  void __RPC_API BSTR_UserFree(unsigned long *,BSTR *);

#ifdef __cplusplus
}
#endif
#endif
