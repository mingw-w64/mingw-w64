/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef __hliface_h__
#define __hliface_h__

#ifdef __cplusplus
extern "C"{
#endif

  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);

#ifndef __hlink_h__
#include "hlink.h"
#endif

  extern RPC_IF_HANDLE __MIDL_itf_hliface_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_hliface_0000_v0_0_s_ifspec;

#ifdef __cplusplus
}
#endif

#endif
