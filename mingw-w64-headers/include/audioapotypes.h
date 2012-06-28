/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __INC_AUDIOAPOTYPES__
#define __INC_AUDIOAPOTYPES__

#if (_WIN32_WINNT >= 0x0601)
#ifdef __cplusplus
extern "C" {
#endif

typedef enum APO_BUFFER_FLAGS {
  BUFFER_INVALID   = 0,
  BUFFER_VALID     = 1,
  BUFFER_SILENT    = 2 
} APO_BUFFER_FLAGS;

typedef struct APO_CONNECTION_PROPERTY {
  UINT_PTR         pBuffer;
  UINT32           u32ValidFrameCount;
  APO_BUFFER_FLAGS u32BufferFlags;
  UINT32           u32Signature;
} APO_CONNECTION_PROPERTY;

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /*__INC_AUDIOAPOTYPES__*/
