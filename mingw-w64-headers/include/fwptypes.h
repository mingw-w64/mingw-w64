/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_FWTYPES
#define _INC_FWTYPES

#ifdef __cplusplus
extern "C" {
#endif

#if (_WIN32_WINNT >= 0x0600)

#define SOCKET_SETTINGS_GUARANTEE_ENCRYPTION 0x00000001
#define SOCKET_SETTINGS_ALLOW_INSECURE 0x00000002

typedef UINT32 FWP_ACTION_TYPE;

typedef enum FWP_CLASSIFY_OPTION_TYPE_ {
  FWP_CLASSIFY_OPTION_MULTICAST_STATE = 0,
  FWP_CLASSIFY_OPTION_LOOSE_SOURCE_MAPPING,
  FWP_CLASSIFY_OPTION_UNICAST_LIFETIME,
  FWP_CLASSIFY_OPTION_MCAST_BCAST_LIFETIME,
  FWP_CLASSIFY_OPTION_SECURE_SOCKET_SECURITY_FLAGS,
  FWP_CLASSIFY_OPTION_SECURE_SOCKET_AUTHIP_MM_POLICY_KEY,
  FWP_CLASSIFY_OPTION_SECURE_SOCKET_AUTHIP_QM_POLICY_KEY,
  FWP_CLASSIFY_OPTION_MAX
} FWP_CLASSIFY_OPTION_TYPE;

typedef enum FWP_DATA_TYPE_ {
  FWP_EMPTY = 0,
  FWP_UINT8,
  FWP_UINT16,
  FWP_UINT32,
  FWP_UINT64,
  FWP_INT8,
  FWP_INT16,
  FWP_INT32,
  FWP_INT64,
  FWP_FLOAT,
  FWP_DOUBLE,
  FWP_BYTE_ARRAY16_TYPE,
  FWP_BYTE_BLOB_TYPE,
  FWP_SID,
  FWP_SECURITY_DESCRIPTOR_TYPE,
  FWP_TOKEN_INFORMATION_TYPE ,
  FWP_TOKEN_ACCESS_INFORMATION_TYPE ,
  FWP_UNICODE_STRING_TYPE,
  FWP_BYTE_ARRAY6_TYPE,
  FWP_SINGLE_DATA_TYPE_MAX             = 0xFF,
  FWP_V4_ADDR_MASK,
  FWP_V6_ADDR_MASK,
  FWP_RANGE_TYPE,
  FWP_DATA_TYPE_MAX
} FWP_DATA_TYPE;

typedef enum FWP_DIRECTION_ {
  FWP_DIRECTION_OUTBOUND = 0,
  FWP_DIRECTION_INBOUND,
  FWP_DIRECTION_MAX
} FWP_DIRECTION;

typedef enum FWP_FILTER_ENUM_TYPE_ {
  FWP_FILTER_ENUM_FULLY_CONTAINED = 0,
  FWP_FILTER_ENUM_OVERLAPPING,
  FWP_FILTER_ENUM_TYPE_MAX
} FWP_FILTER_ENUM_TYPE;

typedef enum FWP_IP_VERSION_ {
  FWP_IP_VERSION_V4 = 0,
  FWP_IP_VERSION_V6,
  FWP_IP_VERSION_NONE,
  FWP_IP_VERSION_MAX
} FWP_IP_VERSION;

typedef enum FWP_MATCH_TYPE_ {
  FWP_MATCH_EQUAL = 0,
  FWP_MATCH_GREATER,
  FWP_MATCH_LESS,
  FWP_MATCH_GREATER_OR_EQUAL,
  FWP_MATCH_LESS_OR_EQUAL,
  FWP_MATCH_RANGE,
  FWP_MATCH_FLAGS_ALL_SET,
  FWP_MATCH_FLAGS_ANY_SET,
  FWP_MATCH_FLAGS_NONE_SET,
  FWP_MATCH_EQUAL_CASE_INSENSITIVE,
  FWP_MATCH_NOT_EQUAL,
  FWP_MATCH_TYPE_MAX
} FWP_MATCH_TYPE;

typedef struct FWP_BYTE_ARRAY16_ {
  UINT8 byteArray16[16];
} FWP_BYTE_ARRAY16;

typedef struct FWP_BYTE_BLOB_ {
  UINT32 size;
  UINT8  *data;
} FWP_BYTE_BLOB;

typedef struct FWP_BYTE_ARRAY6_ {
  UINT8 byteArray6[6];
} FWP_BYTE_ARRAY6;

typedef struct FWP_V4_ADDR_AND_MASK_ {
  UINT32 addr;
  UINT32 mask;
} FWP_V4_ADDR_AND_MASK;

#define FWP_V6_ADDR_SIZE 16

typedef struct FWP_V6_ADDR_AND_MASK_ {
  UINT8 addr[FWP_V6_ADDR_SIZE];
  UINT8 prefixLength;
} FWP_V6_ADDR_AND_MASK;

typedef struct _FWP_TOKEN_INFORMATION {
  ULONG                sidCount;
  PSID_AND_ATTRIBUTES  sids;
  ULONG                restrictedSidCount;
  PSID_AND_ATTRIBUTES  restrictedSids;
} FWP_TOKEN_INFORMATION;

typedef struct FWP_VALUE0_ {
  FWP_DATA_TYPE type;
  __C89_NAMELESS union {
    LPVOID                EMPTY;      // case(FWP_EMPTY)
    UINT8                 uint8;
    UINT16                uint16;
    UINT32                uint32;
    UINT64                *uint64;
    INT8                  int8;
    INT16                 int16;
    INT32                 int32;
    INT64                 *int64;
    float                 float32;
    double                *double64;
    FWP_BYTE_ARRAY16      *byteArray16;
    FWP_BYTE_BLOB         *byteBlob;
    SID                   *sid;
    FWP_BYTE_BLOB         *sd;
    FWP_TOKEN_INFORMATION *tokenInformation;
    FWP_BYTE_BLOB         *tokenAccessInformation;
    LPWSTR                unicodeString;
    FWP_BYTE_ARRAY6       *byteArray6;
  };
} FWP_VALUE0;

typedef struct FWP_RANGE0_ {
  FWP_VALUE0 valueLow;
  FWP_VALUE0 valueHigh;
} FWP_RANGE0;

typedef struct FWP_CONDITION_VALUE0_ {
  FWP_DATA_TYPE type;
  __C89_NAMELESS union {
    UINT8                uint8;
    UINT16               uint16;
    UINT32               uint32;
    UINT64               *uint64;
    INT8                 int8;
    INT16                int16;
    INT32                int32;
    INT64                *int64;
    float                float32;
    double               *double64;
    FWP_BYTE_ARRAY16     *byteArray16;
    FWP_BYTE_BLOB        *byteBlob;
    SID                  *sid;
    FWP_BYTE_BLOB        *sd;
    FWP_BYTE_BLOB        *tokenInformation;
    FWP_BYTE_BLOB        *tokenAccessInformation;
    LPWSTR               unicodeString;
    FWP_BYTE_ARRAY6      *byteArray6;
    FWP_V4_ADDR_AND_MASK *v4AddrMask;
    FWP_V6_ADDR_AND_MASK *v6AddrMask;
    FWP_RANGE0           *rangeValue;
  };
} FWP_CONDITION_VALUE0;

#endif /*(_WIN32_WINNT >= 0x0600)*/

#if (_WIN32_WINNT >= 0x0601)

typedef enum FWP_NE_FAMILY_ {
  FWP_AF_INET    = FWP_IP_VERSION_V4,
  FWP_AF_INET6   = FWP_IP_VERSION_V6,
  FWP_AF_ETHER   = FWP_IP_VERSION_NONE,
  FWP_AF_NONE 
} FWP_AF;

typedef enum FWP_ETHER_ENCAP_METHOD_ {
  FWP_ETHER_ENCAP_METHOD_ETHER_V2          = 0,
  FWP_ETHER_ENCAP_METHOD_SNAP              = 1,
  FWP_ETHER_ENCAP_METHOD_SNAP_W_OUI_ZERO   = 3 
} FWP_ETHER_ENCAP_METHOD;

#endif /*(_WIN32_WINNT >= 0x0601)*/

#ifdef __cplusplus
}
#endif

#endif /*_INC_FWTYPES*/
