/*
 * hidpi.h
 *
 * Public Interface for HID parsing library.
 *
 * This file is part of the w32api package.
 *
 * Contributors:
 *   Created by Casper S. Hornstrup <chorns@users.sourceforge.net>
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#ifndef __HIDPI_H
#define __HIDPI_H

#include "hidusage.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_HIDPI_)
# define HIDAPI
#else
# define HIDAPI DECLSPEC_IMPORT
#endif

#if !defined (_NTDEF_) && !defined (_NTSTATUS_PSDK)
#define _NTSTATUS_PSDK
  typedef LONG NTSTATUS,*PNTSTATUS;
#endif

typedef PUCHAR PHIDP_REPORT_DESCRIPTOR;
typedef struct _HIDP_PREPARSED_DATA * PHIDP_PREPARSED_DATA;

typedef struct _HIDP_UNKNOWN_TOKEN {
  UCHAR  Token;
  UCHAR  Reserved[3];
  ULONG  BitField;
} HIDP_UNKNOWN_TOKEN, *PHIDP_UNKNOWN_TOKEN;

typedef enum _HIDP_KEYBOARD_DIRECTION {
  HidP_Keyboard_Break,
  HidP_Keyboard_Make
} HIDP_KEYBOARD_DIRECTION;

typedef struct _HIDP_KEYBOARD_MODIFIER_STATE {
  _ANONYMOUS_UNION union {
    _ANONYMOUS_STRUCT struct {
      ULONG  LeftControl : 1;
      ULONG  LeftShift : 1;
      ULONG  LeftAlt : 1;
      ULONG  LeftGUI : 1;
      ULONG  RightControl : 1;
      ULONG  RightShift : 1;
      ULONG  RightAlt : 1;
      ULONG  RigthGUI : 1;
      ULONG  CapsLock : 1;
      ULONG  ScollLock : 1;
      ULONG  NumLock : 1;
      ULONG  Reserved : 21;
    } DUMMYSTRUCTNAME;
    ULONG ul;
  } DUMMYUNIONNAME;
} HIDP_KEYBOARD_MODIFIER_STATE, *PHIDP_KEYBOARD_MODIFIER_STATE;

typedef BOOLEAN (NTAPI *PHIDP_INSERT_SCANCODES)(
  PVOID  Context,
  PCHAR  NewScanCodes,
  ULONG  Length);

typedef struct _USAGE_AND_PAGE {
  USAGE  Usage;
  USAGE  UsagePage;
} USAGE_AND_PAGE, *PUSAGE_AND_PAGE;

typedef struct _HIDD_ATTRIBUTES {
  ULONG   Size;
  USHORT  VendorID;
  USHORT  ProductID;
  USHORT  VersionNumber;
} HIDD_ATTRIBUTES, *PHIDD_ATTRIBUTES;

typedef struct _HIDD_CONFIGURATION {
  PVOID  cookie;
  ULONG  size;
  ULONG  RingBufferSize;
} HIDD_CONFIGURATION, *PHIDD_CONFIGURATION;

HIDAPI
NTSTATUS
NTAPI
HidP_TranslateUsageAndPagesToI8042ScanCodes(
  PUSAGE_AND_PAGE  ChangedUsageList,
  ULONG  UsageListLength,
  HIDP_KEYBOARD_DIRECTION  KeyAction,
  PHIDP_KEYBOARD_MODIFIER_STATE  ModifierState,
  PHIDP_INSERT_SCANCODES  InsertCodesProcedure,
  PVOID  InsertCodesContext);

HIDAPI
NTSTATUS
NTAPI
HidP_TranslateUsagesToI8042ScanCodes(
  PUSAGE  ChangedUsageList,
  ULONG  UsageListLength,
  HIDP_KEYBOARD_DIRECTION  KeyAction,
  PHIDP_KEYBOARD_MODIFIER_STATE  ModifierState,
  PHIDP_INSERT_SCANCODES  InsertCodesProcedure,
  PVOID  InsertCodesContext);

typedef struct _HIDP_BUTTON_CAPS {
  USAGE  UsagePage;
  UCHAR  ReportID;
  BOOLEAN  IsAlias;
  USHORT  BitField;
  USHORT  LinkCollection;
  USAGE  LinkUsage;
  USAGE  LinkUsagePage;
  BOOLEAN  IsRange;
  BOOLEAN  IsStringRange;
  BOOLEAN  IsDesignatorRange;
  BOOLEAN  IsAbsolute;
  ULONG  Reserved[10];
  _ANONYMOUS_UNION union {
    struct {
      USAGE  UsageMin, UsageMax;
      USHORT  StringMin, StringMax;
      USHORT  DesignatorMin, DesignatorMax;
      USHORT  DataIndexMin, DataIndexMax;
    } Range;
    struct  {
       USAGE  Usage, Reserved1;
       USHORT  StringIndex, Reserved2;
       USHORT  DesignatorIndex, Reserved3;
       USHORT  DataIndex, Reserved4;
    } NotRange;
  } DUMMYUNIONNAME;
} HIDP_BUTTON_CAPS, *PHIDP_BUTTON_CAPS;

typedef struct _HIDP_CAPS {
  USAGE  Usage;
  USAGE  UsagePage;
  USHORT  InputReportByteLength;
  USHORT  OutputReportByteLength;
  USHORT  FeatureReportByteLength;
  USHORT  Reserved[17];
  USHORT  NumberLinkCollectionNodes;
  USHORT  NumberInputButtonCaps;
  USHORT  NumberInputValueCaps;
  USHORT  NumberInputDataIndices;
  USHORT  NumberOutputButtonCaps;
  USHORT  NumberOutputValueCaps;
  USHORT  NumberOutputDataIndices;
  USHORT  NumberFeatureButtonCaps;
  USHORT  NumberFeatureValueCaps;
  USHORT  NumberFeatureDataIndices;
} HIDP_CAPS, *PHIDP_CAPS;

typedef struct _HIDP_DATA {
  USHORT  DataIndex;
  USHORT  Reserved;
  _ANONYMOUS_UNION union {
    ULONG  RawValue;
    BOOLEAN  On;
  }  DUMMYUNIONNAME;
} HIDP_DATA, *PHIDP_DATA;

typedef struct _HIDP_EXTENDED_ATTRIBUTES {
  UCHAR  NumGlobalUnknowns;
  UCHAR  Reserved[3];
  PHIDP_UNKNOWN_TOKEN  GlobalUnknowns;
  ULONG  Data[1];
} HIDP_EXTENDED_ATTRIBUTES, *PHIDP_EXTENDED_ATTRIBUTES;

#define HIDP_LINK_COLLECTION_ROOT         ((USHORT) -1)
#define HIDP_LINK_COLLECTION_UNSPECIFIED  ((USHORT) 0)

typedef struct _HIDP_LINK_COLLECTION_NODE {
  USAGE  LinkUsage;
  USAGE  LinkUsagePage;
  USHORT  Parent;
  USHORT  NumberOfChildren;
  USHORT  NextSibling;
  USHORT  FirstChild;
  ULONG  CollectionType: 8;
  ULONG  IsAlias: 1;
  ULONG  Reserved: 23;
  PVOID  UserContext;
} HIDP_LINK_COLLECTION_NODE, *PHIDP_LINK_COLLECTION_NODE;

typedef struct _HIDP_VALUE_CAPS {
  USAGE  UsagePage;
  UCHAR  ReportID;
  BOOLEAN  IsAlias;
  USHORT  BitField;
  USHORT  LinkCollection;
  USAGE  LinkUsage;
  USAGE  LinkUsagePage;
  BOOLEAN  IsRange;
  BOOLEAN  IsStringRange;
  BOOLEAN  IsDesignatorRange;
  BOOLEAN  IsAbsolute;
  BOOLEAN  HasNull;
  UCHAR  Reserved;
  USHORT  BitSize;
  USHORT  ReportCount;
  USHORT  Reserved2[5];
  ULONG  UnitsExp;
  ULONG  Units;
  LONG  LogicalMin, LogicalMax;
  LONG  PhysicalMin, PhysicalMax;
    _ANONYMOUS_UNION union {
      struct {
        USAGE  UsageMin, UsageMax;
        USHORT  StringMin, StringMax;
        USHORT  DesignatorMin, DesignatorMax;
        USHORT  DataIndexMin, DataIndexMax;
      } Range;
      struct {
        USAGE  Usage, Reserved1;
        USHORT  StringIndex, Reserved2;
        USHORT  DesignatorIndex, Reserved3;
        USHORT  DataIndex, Reserved4;
      } NotRange;
    } DUMMYUNIONNAME;
} HIDP_VALUE_CAPS, *PHIDP_VALUE_CAPS;

typedef enum _HIDP_REPORT_TYPE {
  HidP_Input,
  HidP_Output,
  HidP_Feature
} HIDP_REPORT_TYPE;

#define FACILITY_HID_ERROR_CODE           0x11

#define HIDP_ERROR_CODES(SEV, CODE) \
  ((NTSTATUS) (((SEV) << 28) | (FACILITY_HID_ERROR_CODE << 16) | (CODE)))

#define HIDP_STATUS_SUCCESS                 (HIDP_ERROR_CODES(0x0, 0))
#define HIDP_STATUS_NULL                    (HIDP_ERROR_CODES(0x8, 1))
#define HIDP_STATUS_INVALID_PREPARSED_DATA  (HIDP_ERROR_CODES(0xC, 1))
#define HIDP_STATUS_INVALID_REPORT_TYPE     (HIDP_ERROR_CODES(0xC, 2))
#define HIDP_STATUS_INVALID_REPORT_LENGTH   (HIDP_ERROR_CODES(0xC, 3))
#define HIDP_STATUS_USAGE_NOT_FOUND         (HIDP_ERROR_CODES(0xC, 4))
#define HIDP_STATUS_VALUE_OUT_OF_RANGE      (HIDP_ERROR_CODES(0xC, 5))
#define HIDP_STATUS_BAD_LOG_PHY_VALUES      (HIDP_ERROR_CODES(0xC, 6))
#define HIDP_STATUS_BUFFER_TOO_SMALL        (HIDP_ERROR_CODES(0xC, 7))
#define HIDP_STATUS_INTERNAL_ERROR          (HIDP_ERROR_CODES(0xC, 8))
#define HIDP_STATUS_I8042_TRANS_UNKNOWN     (HIDP_ERROR_CODES(0xC, 9))
#define HIDP_STATUS_INCOMPATIBLE_REPORT_ID  (HIDP_ERROR_CODES(0xC, 0xA))
#define HIDP_STATUS_NOT_VALUE_ARRAY         (HIDP_ERROR_CODES(0xC, 0xB))
#define HIDP_STATUS_IS_VALUE_ARRAY          (HIDP_ERROR_CODES(0xC, 0xC))
#define HIDP_STATUS_DATA_INDEX_NOT_FOUND    (HIDP_ERROR_CODES(0xC, 0xD))
#define HIDP_STATUS_DATA_INDEX_OUT_OF_RANGE (HIDP_ERROR_CODES(0xC, 0xE))
#define HIDP_STATUS_BUTTON_NOT_PRESSED      (HIDP_ERROR_CODES(0xC, 0xF))
#define HIDP_STATUS_REPORT_DOES_NOT_EXIST   (HIDP_ERROR_CODES(0xC, 0x10))
#define HIDP_STATUS_NOT_IMPLEMENTED         (HIDP_ERROR_CODES(0xC, 0x20))
#define HIDP_STATUS_I8242_TRANS_UNKNOWN     HIDP_STATUS_I8042_TRANS_UNKNOWN


#if !defined(_HIDPI_NO_FUNCTION_MACROS_)
/*
 * NTSTATUS
 * HidP_GetButtonCaps(
 *   IN HIDP_REPORT_TYPE  ReportType,
 *   OUT PHIDP_BUTTON_CAPS  ButtonCaps,
 *   IN OUT PULONG  ButtonCapsLength,
 *   IN PHIDP_PREPARSED_DATA  PreparsedData);
 */
#define HidP_GetButtonCaps(_Type_, _Caps_, _Len_, _Data_) \
  HidP_GetSpecificButtonCaps(_Type_, 0, 0, 0, _Caps_, _Len_, _Data_)

/*
 * NTSTATUS
 * HidP_GetButtons(
 *   IN HIDP_REPORT_TYPE  ReportType,
 *   IN USAGE  UsagePage,
 *   IN USHORT  LinkCollection,
 *   OUT USAGE  *UsageList,
 *   IN OUT ULONG  *UsageLength,
 *   IN PHIDP_PREPARSED_DATA  PreparsedData,
 *   IN PCHAR  Report,
 *   IN ULONG  ReportLength);
 */
#define HidP_GetButtons(Rty, UPa, LCo, ULi, ULe, Ppd, Rep, RLe) \
  HidP_GetUsages(Rty, UPa, LCo, ULi, ULe, Ppd, Rep, RLe)

#define HidP_GetButtonListLength(RTy, UPa, Ppd) \
  HidP_GetUsageListLength(Rty, UPa, Ppd)


/*
 * NTSTATUS
 * HidP_GetButtonsEx(
 *   IN HIDP_REPORT_TYPE  ReportType,
 *   IN USHORT  LinkCollection,
 *   OUT PUSAGE_AND_PAGE  ButtonList,
 *   IN OUT ULONG  *UsageLength,
 *   IN PHIDP_PREPARSED_DATA  PreparsedData,
 *   IN PCHAR  Report,
 *   IN ULONG  ReportLength);
 */
#define HidP_GetButtonsEx(RT, LC, BL, UL, PD, R, RL)  \
  HidP_GetUsagesEx(RT, LC, BL, UL, PD, R, RL)

#endif /* _HIDPI_NO_FUNCTION_MACROS_ */

HIDAPI
NTSTATUS
NTAPI
HidP_GetCaps(
  PHIDP_PREPARSED_DATA  PreparsedData,
  PHIDP_CAPS  Capabilities);

HIDAPI
NTSTATUS
NTAPI
HidP_GetData(
  HIDP_REPORT_TYPE  ReportType,
  PHIDP_DATA  DataList,
  PULONG  DataLength,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_GetExtendedAttributes(
  HIDP_REPORT_TYPE  ReportType,
  USHORT  DataIndex,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PHIDP_EXTENDED_ATTRIBUTES  Attributes,
  PULONG  LengthAttributes);

HIDAPI
NTSTATUS
NTAPI
HidP_GetLinkCollectionNodes(
  PHIDP_LINK_COLLECTION_NODE  LinkCollectionNodes,
  PULONG  LinkCollectionNodesLength,
  PHIDP_PREPARSED_DATA  PreparsedData);

HIDAPI
NTSTATUS
NTAPI
HidP_GetScaledUsageValue(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  USAGE  Usage,
  PLONG  UsageValue,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_GetSpecificButtonCaps(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  USAGE  Usage,
  PHIDP_BUTTON_CAPS  ButtonCaps,
  PULONG  ButtonCapsLength,
  PHIDP_PREPARSED_DATA  PreparsedData);

HIDAPI
NTSTATUS
NTAPI
HidP_GetSpecificValueCaps(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  USAGE  Usage,
  PHIDP_VALUE_CAPS  ValueCaps,
  PULONG  ValueCapsLength,
  PHIDP_PREPARSED_DATA  PreparsedData);

HIDAPI
NTSTATUS
NTAPI
HidP_GetUsages(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  USAGE  *UsageList,
  ULONG  *UsageLength,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_GetUsagesEx(
  HIDP_REPORT_TYPE  ReportType,
  USHORT  LinkCollection,
  PUSAGE_AND_PAGE  ButtonList,
  ULONG  *UsageLength,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_GetUsageValue(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  USAGE  Usage,
  PULONG  UsageValue,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_GetUsageValueArray(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  USAGE  Usage,
  PCHAR  UsageValue,
  USHORT  UsageValueByteLength,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

#if !defined(_HIDPI_NO_FUNCTION_MACROS_)

/*
 * NTSTATUS
 * HidP_GetValueCaps(
 *   IN HIDP_REPORT_TYPE  ReportType,
 *   OUT PHIDP_VALUE_CAPS  ValueCaps,
 *   IN OUT PULONG  ValueCapsLength,
 *   IN PHIDP_PREPARSED_DATA  PreparsedData);
 */
#define HidP_GetValueCaps(_Type_, _Caps_, _Len_, _Data_) \
  HidP_GetSpecificValueCaps (_Type_, 0, 0, 0, _Caps_, _Len_, _Data_)

#endif /* _HIDPI_NO_FUNCTION_MACROS_ */

HIDAPI
NTSTATUS
NTAPI
HidP_InitializeReportForID(
  HIDP_REPORT_TYPE  ReportType,
  UCHAR  ReportID,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

#if !defined(_HIDPI_NO_FUNCTION_MACROS_)

/*
 * BOOLEAN
 * HidP_IsSameUsageAndPage(
 *   USAGE_AND_PAGE  u1,
 *   USAGE_AND_PAGE  u2);
 */
#define HidP_IsSameUsageAndPage(u1, u2) ((* (PULONG) &u1) == (* (PULONG) &u2))

#endif /* _HIDPI_NO_FUNCTION_MACROS_ */

HIDAPI
ULONG
NTAPI
HidP_MaxDataListLength(
  HIDP_REPORT_TYPE  ReportType,
  PHIDP_PREPARSED_DATA  PreparsedData);

HIDAPI
ULONG
NTAPI
HidP_MaxUsageListLength(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  PHIDP_PREPARSED_DATA  PreparsedData);

#if !defined(_HIDPI_NO_FUNCTION_MACROS_)

/*
 * NTSTATUS
 * HidP_SetButtons(
 *   IN HIDP_REPORT_TYPE  ReportType,
 *   IN USAGE  UsagePage,
 *   IN USHORT  LinkCollection,
 *   IN PUSAGE  UsageList,
 *   IN OUT PULONG  UsageLength,
 *   IN PHIDP_PREPARSED_DATA  PreparsedData,
 *   IN OUT PCHAR  Report,
 *   IN ULONG  ReportLength);
 */
#define HidP_SetButtons(RT, UP, LC, UL1, UL2, PD, R, RL) \
  HidP_SetUsages(RT, UP, LC, UL1, UL2, PD, R, RL)

#endif /* _HIDPI_NO_FUNCTION_MACROS_ */

HIDAPI
NTSTATUS
NTAPI
HidP_SetData(
  HIDP_REPORT_TYPE  ReportType,
  PHIDP_DATA  DataList,
  PULONG  DataLength,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_SetScaledUsageValue(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  USAGE  Usage,
  LONG  UsageValue,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_SetUsages(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection, /* Optional */
  PUSAGE  UsageList,
  PULONG  UsageLength,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_SetUsageValue(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  USAGE  Usage,
  ULONG  UsageValue,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_SetUsageValueArray(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  USAGE  Usage,
  PCHAR  UsageValue,
  USHORT  UsageValueByteLength,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

#if !defined(_HIDPI_NO_FUNCTION_MACROS_)

/*
 * NTSTATUS
 * HidP_UnsetButtons(
 *   IN HIDP_REPORT_TYPE  ReportType,
 *   IN USAGE  UsagePage,
 *   IN USHORT  LinkCollection,
 *   IN PUSAGE  UsageList,
 *   IN OUT PULONG  UsageLength,
 *   IN PHIDP_PREPARSED_DATA  PreparsedData,
 *   IN OUT PCHAR  Report,
 *   IN ULONG  ReportLength);
 */
#define HidP_UnsetButtons(RT, UP, LC, UL1, UL2, PD, R, RL) \
  HidP_UnsetUsages(RT, UP, LC, UL1, UL2, PD, R, RL)

#endif /* _HIDPI_NO_FUNCTION_MACROS_ */

HIDAPI
NTSTATUS
NTAPI
HidP_UnsetUsages(
  HIDP_REPORT_TYPE  ReportType,
  USAGE  UsagePage,
  USHORT  LinkCollection,
  PUSAGE  UsageList,
  PULONG  UsageLength,
  PHIDP_PREPARSED_DATA  PreparsedData,
  PCHAR  Report,
  ULONG  ReportLength);

HIDAPI
NTSTATUS
NTAPI
HidP_UsageAndPageListDifference(
  PUSAGE_AND_PAGE  PreviousUsageList,
  PUSAGE_AND_PAGE  CurrentUsageList,
  PUSAGE_AND_PAGE  BreakUsageList,
  PUSAGE_AND_PAGE  MakeUsageList,
  ULONG  UsageListLength);

HIDAPI
NTSTATUS
NTAPI
HidP_UsageListDifference(
  PUSAGE  PreviousUsageList,
  PUSAGE  CurrentUsageList,
  PUSAGE  BreakUsageList,
  PUSAGE  MakeUsageList,
  ULONG  UsageListLength);

#ifdef __cplusplus
}
#endif

#endif /* __HIDPI_H */
