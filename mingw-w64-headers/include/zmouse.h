/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifdef UNICODE
#define MSH_MOUSEWHEEL L"MSWHEEL_ROLLMSG"
#else
#define MSH_MOUSEWHEEL "MSWHEEL_ROLLMSG"
#endif

#define WHEEL_DELTA 120

#ifndef WM_MOUSEWHEEL
#define WM_MOUSEWHEEL (WM_MOUSELAST+1)
#endif

#ifdef UNICODE
#define MOUSEZ_CLASSNAME L"MouseZ"
#define MOUSEZ_TITLE L"Magellan MSWHEEL"
#else
#define MOUSEZ_CLASSNAME "MouseZ"
#define MOUSEZ_TITLE "Magellan MSWHEEL"
#endif

#define MSH_WHEELMODULE_CLASS (MOUSEZ_CLASSNAME)
#define MSH_WHEELMODULE_TITLE (MOUSEZ_TITLE)

#ifdef UNICODE
#define MSH_WHEELSUPPORT L"MSH_WHEELSUPPORT_MSG"
#else
#define MSH_WHEELSUPPORT "MSH_WHEELSUPPORT_MSG"
#endif

#ifdef UNICODE
#define MSH_SCROLL_LINES L"MSH_SCROLL_LINES_MSG"
#else
#define MSH_SCROLL_LINES "MSH_SCROLL_LINES_MSG"
#endif

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
  if(*puiMsh_Msg3DSupport) *pf3DSupport = (WINBOOL)SendMessage(hdlMsWheel,*puiMsh_Msg3DSupport,0,0);
  else *pf3DSupport = FALSE;
  if(*puiMsh_MsgScrollLines) *piScrollLines = (int)SendMessage(hdlMsWheel,*puiMsh_MsgScrollLines,0,0);
  else *piScrollLines = 3;
  return(hdlMsWheel);
}
#endif /* !__CRT__NO_INLINE */

