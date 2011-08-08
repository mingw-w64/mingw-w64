/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __INC_DEVICETOPOLOGY__
#define __INC_DEVICETOPOLOGY__

#if (_WIN32_WINNT >= 0x0600)
#include <windef.h>

typedef enum _ConnectorType {
  Unknown_Connector = 0,
  Physical_Internal,
  Physical_External,
  Software_IO,
  Software_Fixed,
  Network 
} ConnectorType;

typedef enum _DataFlow {
  In,
  Out 
} DataFlow;

typedef enum _PartType {
  Connector,
  Subunit 
} PartType;

/* NOTE: EChannelMapping enumeration is obsoleted in Windows/7:
 * SPEAKER_FRONT_LEFT and friends from ksmedia.h are to
 * be used as KSJACK_DESCRIPTION->ChannelMapping member
 * values who also changed to a DWORD. See:
 * http://msdn.microsoft.com/en-us/library/dd316543(VS.85).aspx
 */
typedef enum _EChannelMapping {
  ePcxChanMap_FL_FR = 0,
  ePcxChanMap_FC_LFE,
  ePcxChanMap_BL_BR,
  ePcxChanMap_FLC_FRC,
  ePcxChanMap_SL_SR,
  ePcxChanMap_Unknown
} EChannelMapping;

typedef enum _EPcxConnectionType {
  eConnTypeUnknown = 0,
  eConnTypeEighth,
  eConnType3Point5mm = eConnTypeEighth,
  eConnTypeQuarter,
  eConnTypeAtapiInternal,
  eConnTypeRCA,
  eConnTypeOptical,
  eConnTypeOtherDigital,
  eConnTypeOtherAnalog,
  eConnTypeMultichannelAnalogDIN,
  eConnTypeXlrProfessional,
  eConnTypeRJ11Modem,
  eConnTypeCombination
} EPcxConnectionType;

typedef enum _EPcxGeoLocation {
  eGeoLocRear = 0,
  eGeoLocFront,
  eGeoLocLeft,
  eGeoLocRight,
  eGeoLocTop,
  eGeoLocBottom,
  eGeoLocRearOPanel,
  eGeoLocRearPanel = eGeoLocRearOPanel,
  eGeoLocRiser,
  eGeoLocInsideMobileLid,
  eGeoLocDrivebay,
  eGeoLocHDMI,
  eGeoLocOutsideMobileLid,
  eGeoLocATAPI
} EPcxGeoLocation;

typedef enum _EPcxGenLocation {
  eGenLocPrimaryBox = 0,
  eGenLocInternal,
  eGenLocSeperate,
  eGenLocSeparate = eGenLocSeperate,
  eGenLocOther
} EPcxGenLocation;

typedef enum _EPxcPortConnection {
  ePortConnJack = 0,
  ePortConnIntegratedDevice,
  ePortConnBothIntegratedAndJack,
  ePortConnUnknown
} EPxcPortConnection;

typedef struct _KSJACK_DESCRIPTION {
  EChannelMapping    ChannelMapping; /* see note up above for EChannelMapping */
  COLORREF           Color;
  EPcxConnectionType ConnectionType;
  EPcxGeoLocation    GeoLocation;
  EPcxGenLocation    GenLocation;
  EPxcPortConnection PortConnection;
  BOOL               IsConnected;
} KSJACK_DESCRIPTION, *PKSJACK_DESCRIPTION;

#define SPEAKER_FRONT_LEFT              0x1
#define SPEAKER_FRONT_RIGHT             0x2
#define SPEAKER_FRONT_CENTER            0x4
#define SPEAKER_LOW_FREQUENCY           0x8
#define SPEAKER_BACK_LEFT               0x10
#define SPEAKER_BACK_RIGHT              0x20
#define SPEAKER_FRONT_LEFT_OF_CENTER    0x40
#define SPEAKER_FRONT_RIGHT_OF_CENTER   0x80
#define SPEAKER_BACK_CENTER             0x100
#define SPEAKER_SIDE_LEFT               0x200
#define SPEAKER_SIDE_RIGHT              0x400
#define SPEAKER_TOP_CENTER              0x800
#define SPEAKER_TOP_FRONT_LEFT          0x1000
#define SPEAKER_TOP_FRONT_CENTER        0x2000
#define SPEAKER_TOP_FRONT_RIGHT         0x4000
#define SPEAKER_TOP_BACK_LEFT           0x8000
#define SPEAKER_TOP_BACK_CENTER         0x10000
#define SPEAKER_TOP_BACK_RIGHT          0x20000

#endif /*(_WIN32_WINNT >= 0x0600)*/

#if (_WIN32_WINNT >= 0x0601)

typedef enum _KSJACK_SINK_CONNECTIONTYPE {
  KSJACK_SINK_CONNECTIONTYPE_HDMI          = 0,
  KSJACK_SINK_CONNECTIONTYPE_DISPLAYPORT   = 1 
} KSJACK_SINK_CONNECTIONTYPE;

typedef struct _KSJACK_DESCRIPTION2 {
  DWORD DeviceStateInfo;
  DWORD JackCapabilities;
} KSJACK_DESCRIPTION2, *PKSJACK_DESCRIPTION2;

#define JACKDESC2_PRESENCE_DETECT_CAPABILITY (0x00000001)
#define JACKDESC2_DYNAMIC_FORMAT_CHANGE_CAPABILITY (0x00000002)

#define MAX_SINK_DESCRIPTION_NAME_LENGTH 32

typedef struct _KSJACK_SINK_INFORMATION {
  KSJACK_SINK_CONNECTIONTYPE               ConnType;
  WORD                                     ManufacturerId;
  WORD                                     ProductId;
  WORD                                     AudioLatency;
  WINBOOL                                  HDCPCapable;
  WINBOOL                                  AICapable;
  UCHAR                                    SinkDescriptionLength;
  WCHAR                                    SinkDescription [MAX_SINK_DESCRIPTION_NAME_LENGTH];
  LUID                                     PortId;
} KSJACK_SINK_INFORMATION, *PKSJACK_SINK_INFORMATION;

#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /*__INC_DEVICETOPOLOGY__*/
