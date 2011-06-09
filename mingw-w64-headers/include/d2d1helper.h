/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_D2D1HELPER
#define _INC_D2D1HELPER

#if (_WIN32_WINNT >= 0x0600)
#ifdef __cplusplus

/* TODO: import-library needs to alias VC++ to g++ name-mangline

   GCC cannot understand MSVC C++ mangling, so
   function is not usable with GCC.
D2D1_ARC_SEGMENT ArcSegment(
  const D2D1_POINT_2F &point,
  const D2D1_SIZE_F &size,
  FLOAT rotationAngle,
  D2D1_SWEEP_DIRECTION sweepDirection,
  D2D1_ARC_SIZE arcSize
);
*/
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/

#if (_WIN32_WINNT >= 0x0601)
#ifdef __cplusplus
/*
D2D1HELPERAPI HWND WINAPI HwndRenderTargetProperties(
  HWND hwnd,
  D2D1_SIZE_U pixelSize =  D2D1::Size(static_cast<UINT>(0), static_cast<UINT>(0)) ,
  D2D1_PRESENT_OPTIONS presentOptions =  D2D1_PRESENT_OPTIONS_NONE 
);
*/
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/

#endif /*_INC_D2D1HELPER*/
