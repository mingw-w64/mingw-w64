/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_FUNCTIONDISCOVERYCONSTRAINTS
#define _INC_FUNCTIONDISCOVERYCONSTRAINTS
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum tagPropertyConstraint {
  QC_EQUALS               = 0,
  QC_NOTEQUAL             = 1,
  QC_LESSTHAN             = 2,
  QC_LESSTHANOREQUAL      = 3,
  QC_GREATERTHAN          = 4,
  QC_GREATERTHANOREQUAL   = 5,
  QC_STARTSWITH           = 6,
  QC_EXISTS               = 7,
  QC_DOESNOTEXIST         = 8,
  QC_CONTAINS             = 8 
} PropertyConstraint;

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_FUNCTIONDISCOVERYCONSTRAINTS*/
