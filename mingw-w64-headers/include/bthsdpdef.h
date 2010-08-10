/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_BTHSDPDEF
#define _INC_BTHSDPDEF

#ifdef __cplusplus
extern "C" {
#endif

typedef union SdpQueryUuidUnion {
  GUID   uuid128;
  ULONG  uuid32;
  USHORT uuid16;
} SdpQueryUuidUnion;

typedef struct _SdpAttributeRange {
  USHORT minAttribute;
  USHORT maxAttribute;
} SdpAttributeRange;

typedef struct _SdpQueryUuid {
  SdpQueryUuidUnion u;
  USHORT            uuidType;
} SdpQueryUuid;

typedef struct _BTH_L2CAP_EVENT_INFO {
  BTH_ADDR bthAddress;
  USHORT   psm;
  UCHAR    connected;
  UCHAR    initiated;
} BTH_L2CAP_EVENT_INFO, *PBTH_L2CAP_EVENT_INFO;

#ifdef __cplusplus
}
#endif
#endif /*_INC_BTHSDPDEF*/
