/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <rpc.h>
#include <rpcndr.h>

#ifndef _COMBASEAPI_H_
#define _COMBASEAPI_H_

#include <pshpack8.h>

#include <wtypes.h>
#include <unknwn.h>
#include <objidl.h>
#include <objbase.h>
#include <guiddef.h>

#ifndef INITGUID
#include <cguid.h>
#endif

#if (_WIN32_WINNT >= 0x0602)
WINOLEAPI CoCreateInstanceFromApp(REFCLSID Clsid,IUnknown *punkOuter,DWORD dwClsCtx,void *reserved,DWORD dwCount,MULTI_QI *pResults);
#endif /*(_WIN32_WINNT >= 0x0602)*/

#endif
