/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_ICFTYPES
#define _INC_ICFTYPES
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _NET_FW_ACTION {
  NET_FW_ACTION_BLOCK,
  NET_FW_ACTION_ALLOW,
  NET_FW_ACTION_MAX 
} NET_FW_ACTION;

typedef enum _NET_FW_MODIFY_STATE {
  NET_FW_MODIFY_STATE_OK,
  NET_FW_MODIFY_STATE_GP_OVERRIDE,
  NET_FW_MODIFY_STATE_INBOUND_BLOCKED 
} NET_FW_MODIFY_STATE;

typedef enum NET_FW_PROFILE_TYPE2_ {
  NET_FW_PROFILE2_DOMAIN    = 0x0001,
  NET_FW_PROFILE2_PRIVATE   = 0x0002,
  NET_FW_PROFILE2_PUBLIC    = 0x0004,
  NET_FW_PROFILE2_ALL       = 0x7FFFFFFF 
} NET_FW_PROFILE_TYPE2;

typedef enum NET_FW_RULE_DIRECTION_ {
  NET_FW_RULE_DIR_IN,
  NET_FW_RULE_DIR_OUT,
  NET_FW_RULE_DIR_MAX 
} NET_FW_RULE_DIRECTION;

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_ICFTYPES*/
