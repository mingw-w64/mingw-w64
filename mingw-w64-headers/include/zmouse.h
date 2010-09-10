/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw_unicode.h>
#include <psdk_inc/_push_BOOL.h>

#define MSH_MOUSEWHEEL __MINGW_STRING_AW("MSWHEEL_ROLLMSG")

#define WHEEL_DELTA 120

#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL (WM_MOUSELAST+1)
#endif

#define MOUSEZ_CLASSNAME __MINGW_STRING_AW("MouseZ")
#define MOUSEZ_TITLE __MINGW_STRING_AW("Magellan MSWHEEL")

#define MSH_WHEELMODULE_CLASS (MOUSEZ_CLASSNAME)
#define MSH_WHEELMODULE_TITLE (MOUSEZ_TITLE)

#define MSH_WHEELSUPPORT __MINGW_STRING_AW("MSH_WHEELSUPPORT_MSG")
#define MSH_SCROLL_LINES __MINGW_STRING_AW("MSH_SCROLL_LINES_MSG")

#ifndef WHEEL_PAGESCROLL
#define WHEEL_PAGESCROLL (UINT_MAX)
#endif

#ifndef SPI_SETWHEELSCROLLLINES
#define SPI_SETWHEELSCROLLLINES 105
#endif

#ifndef __CRT__NO_INLINE
__CRT_INLINE HWND HwndMSWheel(PUINT puiMsh_MsgMouseWheel,PUINT puiMsh_Msg3DSupport,PUINT puiMsh_MsgScrollLines,PBOOL pf3DSupport,PINT piScrollLines) {
  HWND hdlMsWheel;
  hdlMsWheel = FindWindow(MSH_WHEELMODULE_CLASS,MSH_WHEELMODULE_TITLE);
  *puiMsh_MsgMouseWheel = RegisterWindowMessage(MSH_MOUSEWHEEL);
  *puiMsh_Msg3DSupport = RegisterWindowMessage(MSH_WHEELSUPPORT);
  *puiMsh_MsgScrollLines = RegisterWindowMessage(MSH_SCROLL_LINES);
  if(*puiMsh_Msg3DSupport) *pf3DSupport = (BOOL)SendMessage(hdlMsWheel,*puiMsh_Msg3DSupport,0,0);
  else *pf3DSupport = FALSE;
  if(*puiMsh_MsgScrollLines) *piScrollLines = (int)SendMessage(hdlMsWheel,*puiMsh_MsgScrollLines,0,0);
  else *piScrollLines = 3;
  return(hdlMsWheel);
}
#endif /* !__CRT__NO_INLINE */
#include <psdk_inc/_pop_BOOL.h>

