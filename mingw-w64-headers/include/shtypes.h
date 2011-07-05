/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef __shtypes_h__
#define __shtypes_h__

#include "wtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#include <pshpack1.h>
  typedef struct _SHITEMID {
    USHORT cb;
    BYTE abID[1 ];
  } SHITEMID;

#include <poppack.h>
#if (defined(_X86_) && !defined(__x86_64))
#undef __unaligned
#define __unaligned
#endif
  typedef SHITEMID __unaligned *LPSHITEMID;

  typedef const SHITEMID __unaligned *LPCSHITEMID;

#include <pshpack1.h>
  typedef struct _ITEMIDLIST {
    SHITEMID mkid;
  } ITEMIDLIST;

#include <poppack.h>
  typedef BYTE_BLOB *wirePIDL;

  typedef ITEMIDLIST __unaligned *LPITEMIDLIST;
  typedef const ITEMIDLIST __unaligned *LPCITEMIDLIST;

#ifdef WINBASE_DEFINED_MIDL
  typedef struct _WIN32_FIND_DATAA {
    DWORD bData[80 ];
  } WIN32_FIND_DATAA;

  typedef struct _WIN32_FIND_DATAW {
    DWORD bData[148 ];
  } WIN32_FIND_DATAW;
#endif

  typedef enum tagSTRRET_TYPE {
    STRRET_WSTR = 0,STRRET_OFFSET = 0x1,STRRET_CSTR = 0x2
  } STRRET_TYPE;

#include <pshpack8.h>
  typedef struct _STRRET {
    UINT uType;
    __C89_NAMELESS union {
      LPWSTR pOleStr;
      UINT uOffset;
      char cStr[260 ];
    } DUMMYUNIONNAME;
  } STRRET;

#include <poppack.h>
  typedef STRRET *LPSTRRET;

#include <pshpack1.h>
  typedef struct _SHELLDETAILS {
    int fmt;
    int cxChar;
    STRRET str;
  } SHELLDETAILS;

  typedef struct _SHELLDETAILS *LPSHELLDETAILS;

#include <poppack.h>

  typedef enum tagSHCOLSTATE {
    SHCOLSTATE_TYPE_STR = 0x1,
    SHCOLSTATE_TYPE_INT = 0x2,
    SHCOLSTATE_TYPE_DATE = 0x3,
    SHCOLSTATE_TYPEMASK = 0xf,
    SHCOLSTATE_ONBYDEFAULT = 0x10,
    SHCOLSTATE_SLOW = 0x20,
    SHCOLSTATE_EXTENDED = 0x40,
    SHCOLSTATE_SECONDARYUI = 0x80,
    SHCOLSTATE_HIDDEN = 0x100,
    SHCOLSTATE_PREFER_VARCMP = 0x200
  } SHCOLSTATE;

  typedef DWORD SHCOLSTATEF;

  typedef PROPERTYKEY SHCOLUMNID;
  typedef const SHCOLUMNID *LPCSHCOLUMNID;

  extern RPC_IF_HANDLE __MIDL_itf_shtypes_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shtypes_0000_v0_0_s_ifspec;

#ifdef __cplusplus
}
#endif
#endif
