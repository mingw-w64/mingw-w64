/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_FUNCTIONDISCOVERYAPI
#define _INC_FUNCTIONDISCOVERYAPI
#if (_WIN32_WINNT >= 0x0600)
#ifdef __cplusplus
extern "C" {
#endif

typedef enum tagQueryUpdateAction {
  QUA_ADD      = 0,
  QUA_REMOVE   = 1,
  QUA_CHANGE   = 2 
} QueryUpdateAction;

typedef enum tagSystemVisibilityFlags {
  SVF_SYSTEM   = 0,
  SVF_USER     = 1 
} SystemVisibilityFlags;

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_FUNCTIONDISCOVERYAPI*/
