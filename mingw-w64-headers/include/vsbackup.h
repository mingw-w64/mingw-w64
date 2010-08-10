/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_VSBACKUP
#define _INC_VSBACKUP

#ifdef __cplusplus
extern "C" {
#endif

HRESULT ShouldBlockRevert(
  LPCWSTR wszVolumeName,
  WINBOOL *pbBlock
);

#ifdef __cplusplus
}
#endif

#endif /*_INC_VSBACKUP*/
