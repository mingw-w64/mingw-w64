/*
 * hidsdi.h
 *
 * Public interface for USB HID user space functions.
 *
 * Contributors:
 *   Created by Simon Josefsson <simon@josefsson.org>
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

#ifndef __HIDSDI_H
#define __HIDSDI_H

#include "hidpi.h"

#ifdef __cplusplus
extern "C" {
#endif

  /* http://msdn.microsoft.com/en-us/library/ff538900%28v=VS.85%29.aspx */
HIDAPI BOOLEAN NTAPI
HidD_GetAttributes(HANDLE HidDeviceObject, PHIDD_ATTRIBUTES Attributes);

  /* http://msdn.microsoft.com/en-us/library/ff538910%28v=VS.85%29.aspx */
HIDAPI BOOLEAN NTAPI
HidD_GetFeature(HANDLE HidDeviceObject, PVOID ReportBuffer,
		ULONG ReportBufferLength);

  /* http://msdn.microsoft.com/en-us/library/ff539684%28v=VS.85%29.aspx */
HIDAPI BOOLEAN NTAPI
HidD_SetFeature(HANDLE HidDeviceObject, PVOID ReportBuffer,
		ULONG ReportBufferLength);

#ifdef __cplusplus
}
#endif

#endif /* __HIDSDI_H */

