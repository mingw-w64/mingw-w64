/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_NAPTYPES
#define _INC_NAPTYPES

#if (_WIN32_WINNT >= 0x0600)

typedef enum tagSoHAttributeType {
  sohAttributeTypeSystemHealthId           = 2,
  sohAttributeTypeIpv4FixupServers         = 3,
  sohAttributeTypeComplianceResultCodes    = 4,
  sohAttributeTypeTimeOfLastUpdate         = 5,
  sohAttributeTypeClientId                 = 6,
  sohAttributeTypeVendorSpecific           = 7,
  sohAttributeTypeHealthClass              = 8,
  sohAttributeTypeSoftwareVersion          = 9,
  sohAttributeTypeProductName              = 10,
  sohAttributeTypeHealthClassStatus        = 11,
  sohAttributeTypeSoHGenerationTime        = 12,
  sohAttributeTypeErrorCodes               = 13,
  sohAttributeTypeFailureCategory          = 14,
  sohAttributeTypeIpv6FixupServers         = 15,
  sohAttributeTypeExtendedIsolationState   = 16
} SoHAttributeType;

typedef union tagSoHAttributeValue {
  SystemHealthEntityId     idVal;
  struct tagIpv4Addresses {
    UINT16 count;
    Ipv4Address *addresses;
  } v4AddressesVal;
  struct tagIpv6Addresses {
    UINT16 count;
    Ipv6Address *addresses;
  } v6AddressesVal;
  ResultCodes              codesVal;
  FILETIME                 dateTimeVal;
  struct tagVendorSpecific {
    UINT32 vendorId;
    UINT16 size;
    BYTE *vendorSpecificData;
  } vendorSpecificVal;
  UINT8                    uint8Val;
  struct tagOctetString {
    UINT16 size;
    BYTE *data;
  } octetStringVal;
}SoHAttributeValue;

typedef enum tagHealthClassValue {
  healthClassFirewall         = 0,
  healthClassPatchLevel       = 1,
  healthClassAntiVirus        = 2,
  healthClassCriticalUpdate   = 3,
  healthClassReserved         = 128
} HealthClassValue;

#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /* _INC_NAPTYPES */

