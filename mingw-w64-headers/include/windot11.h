/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WINDOT11
#define _INC_WINDOT11
#include <ntddndis.h>
#include <wlantypes.h>

typedef UCHAR DOT11_MAC_ADDRESS[6];
typedef DOT11_MAC_ADDRESS* PDOT11_MAC_ADDRESS;

typedef enum _DOT11_PHY_TYPE {
  dot11_phy_type_unknown      = 0,
  dot11_phy_type_any          = 0,
  dot11_phy_type_fhss         = 1,
  dot11_phy_type_dsss         = 2,
  dot11_phy_type_irbaseband   = 3,
  dot11_phy_type_ofdm         = 4,
  dot11_phy_type_hrdsss       = 5,
  dot11_phy_type_erp          = 6,
  dot11_phy_type_ht           = 7,
  dot11_phy_type_IHV_start    = 0x80000000,
  dot11_phy_type_IHV_end      = 0xffffffff 
} DOT11_PHY_TYPE, *PDOT11_PHY_TYPE;

typedef struct _DOT11_BSSID_LIST {
  NDIS_OBJECT_HEADER Header;
  ULONG              uNumOfEntries;
  ULONG              uTotalNumOfEntries;
  DOT11_MAC_ADDRESS  BSSIDs[1];
} DOT11_BSSID_LIST, *PDOT11_BSSID_LIST;

#endif /*_INC_WINDOT11*/
