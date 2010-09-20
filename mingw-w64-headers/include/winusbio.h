/*
 This Software is provided under the Zope Public License (ZPL) Version 2.1.

 Copyright (c) 2009, 2010 by the mingw-w64 project

 See the AUTHORS file for the list of contributors to the mingw-w64 project.

 This license has been certified as open source. It has also been designated
 as GPL compatible by the Free Software Foundation (FSF).

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

   1. Redistributions in source code must retain the accompanying copyright
      notice, this list of conditions, and the following disclaimer.
   2. Redistributions in binary form must reproduce the accompanying
      copyright notice, this list of conditions, and the following disclaimer
      in the documentation and/or other materials provided with the
      distribution.
   3. Names of the copyright holders must not be used to endorse or promote
      products derived from this software without prior written permission
      from the copyright holders.
   4. The right to distribute this software or to use it for any purpose does
      not give you the right to use Servicemarks (sm) or Trademarks (tm) of
      the copyright holders.  Use of them is covered by separate agreement
      with the copyright holders.
   5. If any files are modified, you must cause the modified files to carry
      prominent notices stating that you changed the files and the date of
      any change.

 Disclaimer

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESSED
 OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __WINUSBIO_H
#define __WINUSBIO_H


#include <windows.h>
#include <usb.h>	/* for USBD_PIPE_TYPE */


#ifdef __cplusplus
extern "C" {
#endif

typedef struct _WINUSB_PIPE_INFORMATION {
  USBD_PIPE_TYPE PipeType;
  UCHAR PipeId;
  USHORT MaximumPacketSize;
  UCHAR Interval;
} WINUSB_PIPE_INFORMATION, *PWINUSB_PIPE_INFORMATION;

/* constants for WinUsb_Get/SetPipePolicy.  */
#define SHORT_PACKET_TERMINATE 0x01
#define AUTO_CLEAR_STALL       0x02
#define PIPE_TRANSFER_TIMEOUT  0x03
#define IGNORE_SHORT_PACKETS   0x04
#define ALLOW_PARTIAL_READS    0x05
#define AUTO_FLUSH             0x06
#define RAW_IO                 0x07

/* constants for WinUsb_Get/SetPowerPolicy.  */
#define AUTO_SUSPEND  0x01
#define ENABLE_WAKE   0x02
#define SUSPEND_DELAY 0x03

/* constants for WinUsb_QueryDeviceInformation.  */
#define DEVICE_SPEED 0x01
#define LowSpeed     0x01
#define FullSpeed    0x02
#define HighSpeed    0x03


#ifdef __cplusplus
}
#endif

#endif /* __WINUSBIO_H */

