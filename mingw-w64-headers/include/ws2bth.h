/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WS2BTH
#define _INC_WS2BTH
#include <bthdef.h>
#include <bthsdpdef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
  constants as found on
  http://www.koders.com/delphi/fid882B076395C727550B1DA378430A79672B587941.aspx
*/

#define BT_PORT_ANY       ((ULONG)-1)
#define BT_PORT_MIN       0x0001
#define BT_PORT_MAX       0xffff
#define BT_PORT_DYN_FIRST 0x1001

#define BTH_ADDR_STRING_SIZE 12

#define BTHPROTO_RFCOMM 0x0003
#define BTHPROTO_L2CAP  0x0100

#define SOL_RFCOMM BTHPROTO_RFCOMM
#define SOL_L2CAP  BTHPROTO_L2CAP
#define SOL_SDP    0x0101

#define SO_BTH_AUTHENTICATE 0x80000001
#define SO_BTH_ENCRYPT      0x00000002
#define SO_BTH_MTU          0x80000007
#define SO_BTH_MTU_MAX      0x80000008
#define SO_BTH_MTU_MIN      0x8000000a

#define RFCOMM_MAX_MTU 0x029a
#define RFCOMM_MIN_MTU 0x0017

#define BTH_SDP_VERSION 1

#define SDP_DEFAULT_INQUIRY_SECONDS       6
#define SDP_MAX_INQUIRY_SECONDS           60
#define SDP_DEFAULT_INQUIRY_MAX_RESPONSES 255

#define SDP_SERVICE_SEARCH_REQUEST           1
#define SDP_SERVICE_ATTRIBUTE_REQUEST        2
#define SDP_SERVICE_SEARCH_ATTRIBUTE_REQUEST 3

#define BTHNS_RESULT_DEVICE_CONNECTED     0x00010000
#define BTHNS_RESULT_DEVICE_REMEMBERED    0x00020000
#define BTHNS_RESULT_DEVICE_AUTHENTICATED 0x00040000

#define SIO_BTH_PING                _WSAIORW(IOC_VENDOR, 8)
#define SIO_BTH_INFO                _WSAIORW(IOC_VENDOR, 9)

#define SIO_RFCOMM_SEND_COMMAND     _WSAIORW(IOC_VENDOR, 101)
#define SIO_RFCOMM_WAIT_COMMAND     _WSAIORW(IOC_VENDOR, 102)
#define SIO_RFCOMM_SESSION_FLOW_OFF _WSAIORW(IOC_VENDOR, 103)
#define SIO_RFCOMM_TEST             _WSAIORW(IOC_VENDOR, 104)
#define SIO_RFCOMM_USECFC           _WSAIORW(IOC_VENDOR, 105)

#define BIT(b) (1 << (b))

//TODO #define MSC_EA_BIT
#define MSC_FC_BIT    BIT(1)
#define MSC_RTC_BIT   BIT(2)
#define MSC_RTR_BIT   BIT(3)
#define MSC_RESERVED  (BIT(4) | BIT(5))
#define MSC_IC_BIT    BIT(6)
#define MSC_DV_BIT    BIT(7)
#define MSC_BREAK_BIT BIT(1)

#define MSC_SET_BREAK_LENGTH(b, l) ((b) = ((b) & 0x03) | (((l) & 0x0f) << 4))

#define RLS_ERROR   0x01
#define RLS_OVERRUN 0x02
#define RLS_PARITY  0x04
#define RLS_FRAMING 0x08

#define RPN_BAUD_2400   0
#define RPN_BAUD_4800   1
#define RPN_BAUD_7200   2
#define RPN_BAUD_9600   3
#define RPN_BAUD_19200  4
#define RPN_BAUD_38400  5
#define RPN_BAUD_57600  6
#define RPN_BAUD_115200 7
#define RPN_BAUD_230400 8

#define RPN_DATA_5 0
#define RPN_DATA_6 1
#define RPN_DATA_7 2
#define RPN_DATA_8 3

#define RPN_STOP_1   0
#define RPN_STOP_1_5 4

#define RPN_PARITY_NONE  0x00
#define RPN_PARITY_ODD   0x08
#define RPN_PARITY_EVEN  0x18
#define RPN_PARITY_MARK  0x28
#define RPN_PARITY_SPACE 0x38

#define RPN_FLOW_X_IN    0x01
#define RPN_FLOW_X_OUT   0x02
#define RPN_FLOW_RTR_IN  0x04
#define RPN_FLOW_RTR_OUT 0x08
#define RPN_FLOW_RTC_IN  0x10
#define RPN_FLOW_RTC_OUT 0x20

#define RPN_PARAM_BAUD   0x01
#define RPN_PARAM_DATA   0x02
#define RPN_PARAM_STOP   0x04
#define RPN_PARAM_PARITY 0x08
#define RPN_PARAM_P_TYPE 0x10
#define RPN_PARAM_XON    0x20
#define RPN_PARAM_XOFF   0x40

#define RPN_PARAM_X_IN    0x01
#define RPN_PARAM_X_OUT   0x02
#define RPN_PARAM_RTR_IN  0x04
#define RPN_PARAM_RTR_OUT 0x08
#define RPN_PARAM_RTC_IN  0x10
#define RPN_PARAM_RTC_OUT 0x20

#define RFCOMM_CMD_NONE         0
#define RFCOMM_CMD_MSC          1
#define RFCOMM_CMD_RLS          2
#define RFCOMM_CMD_RPN          3
#define RFCOMM_CMD_RPN_REQUEST  4
#define RFCOMM_CMD_RPN_RESPONSE 5

typedef struct _BTH_QUERY_SERVICE {
  ULONG             type;
  ULONG             serviceHandle;
  SdpQueryUuid      uuids[MAX_UUIDS_IN_QUERY];
  ULONG             numRange;
  SdpAttributeRange pRange[1];
} BTH_QUERY_SERVICE, *PBTH_QUERY_SERVICE;

typedef struct _BTH_QUERY_DEVICE {
  ULONG LAP;
  UCHAR length;
} BTH_QUERY_DEVICE, *PBTH_QUERY_DEVICE;

typedef struct _BTH_SET_SERVICE {
  PULONG pSdpVersion;
  HANDLE *pRecordHandle;
  ULONG  fCodService;
  ULONG  Reserved[5];
  ULONG  ulRecordLength;
  UCHAR  pRecord[1];
} BTH_SET_SERVICE, *PBTH_SET_SERVICE;

typedef struct _SOCKADDR_BTH {
  USHORT   addressFamily;
  BTH_ADDR btAddr;
  GUID     serviceClassId;
  ULONG    port;
} SOCKADDR_BTH, *PSOCKADDR_BTH;

#ifdef __cplusplus
}
#endif
#endif /*_INC_WS2BTH*/
