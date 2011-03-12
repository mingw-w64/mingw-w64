/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WLANTYPES
#define _INC_WLANTYPES

#ifdef __cplusplus
extern "C" {
#endif

#define DOT11_SSID_MAX_LENGTH 32

typedef enum _DOT11_AUTH_ALGORITHM {
  DOT11_AUTH_ALGO_80211_OPEN         = 1,
  DOT11_AUTH_ALGO_80211_SHARED_KEY   = 2,
  DOT11_AUTH_ALGO_WPA                = 3,
  DOT11_AUTH_ALGO_WPA_PSK            = 4,
  DOT11_AUTH_ALGO_WPA_NONE           = 5,
  DOT11_AUTH_ALGO_RSNA               = 6,
  DOT11_AUTH_ALGO_RSNA_PSK           = 7,
  DOT11_AUTH_ALGO_IHV_START          = 0x80000000,
  DOT11_AUTH_ALGO_IHV_END            = 0xffffffff 
} DOT11_AUTH_ALGORITHM, *PDOT11_AUTH_ALGORITHM;

typedef enum _DOT11_CIPHER_ALGORITHM {
  DOT11_CIPHER_ALGO_NONE            = 0x00,
  DOT11_CIPHER_ALGO_WEP40           = 0x01,
  DOT11_CIPHER_ALGO_TKIP            = 0x02,
  DOT11_CIPHER_ALGO_CCMP            = 0x04,
  DOT11_CIPHER_ALGO_WEP104          = 0x05,
  DOT11_CIPHER_ALGO_WPA_USE_GROUP   = 0x100,
  DOT11_CIPHER_ALGO_RSN_USE_GROUP   = 0x100,
  DOT11_CIPHER_ALGO_WEP             = 0x101,
  DOT11_CIPHER_ALGO_IHV_START       = 0x80000000,
  DOT11_CIPHER_ALGO_IHV_END         = 0xffffffff 
} DOT11_CIPHER_ALGORITHM, *PDOT11_CIPHER_ALGORITHM;

typedef enum _DOT11_BSS_TYPE {
  dot11_BSS_type_infrastructure   = 1,
  dot11_BSS_type_independent      = 2,
  dot11_BSS_type_any              = 3 
} DOT11_BSS_TYPE, *PDOT11_BSS_TYPE;

typedef struct _DOT11_AUTH_CIPHER_PAIR {
  DOT11_AUTH_ALGORITHM   AuthAlgoId;
  DOT11_CIPHER_ALGORITHM CipherAlgoId;
} DOT11_AUTH_CIPHER_PAIR, *PDOT11_AUTH_CIPHER_PAIR;

typedef struct _DOT11_SSID {
  ULONG uSSIDLength;
  UCHAR ucSSID[DOT11_SSID_MAX_LENGTH];
} DOT11_SSID, *PDOT11_SSID;

#ifdef __cplusplus
}
#endif

#endif /*_INC_WLANTYPES*/
