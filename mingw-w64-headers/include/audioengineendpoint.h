/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_AUDIOENGINEENDPOINT
#define _INC_AUDIOENGINEENDPOINT

#if (_WIN32_WINNT >= 0x0601)
#ifdef __cplusplus
extern "C" {
#endif

typedef enum AE_POSITION_FLAGS {
  POSITION_INVALID         = 0,
  POSITION_DISCONTINUOUS   = 1,
  POSITION_CONTINUOUS      = 2,
  POSITION_QPC_ERROR       = 4 
} AE_POSITION_FLAGS;

typedef struct AE_CURRENT_POSITION {
  UINT64            u64DevicePosition;
  UINT64            u64StreamPosition;
  UINT64            u64PaddingFrames;
  HNSTIME           hnsQPCPosition;
  FLOAT32           f32FramesPerSecond;
  AE_POSITION_FLAGS Flag;
} AE_CURRENT_POSITION, *PAE_CURRENT_POSITION;

typedef struct _AUDIO_ENDPOINT_EXCLUSIVE_CREATE_PARAMS {
  UINT32       u32Size;
  LONGLONG     hConnection;
  WINBOOL      bIsRtCapable;
  HNSTIME      hnsBufferDuration;
  HNSTIME      hnsPeriod;
  UINT32       u32LatencyCoefficient;
  WAVEFORMATEX wfxDeviceFormat;
} AUDIO_ENDPOINT_EXCLUSIVE_CREATE_PARAMS, *PAUDIO_ENDPOINT_EXCLUSIVE_CREATE_PARAMS;

typedef struct _AUDIO_ENDPOINT_SHARED_CREATE_PARAMS {
  UINT32 u32Size;
  UINT32 u32TSSessionId;
} AUDIO_ENDPOINT_SHARED_CREATE_PARAMS, *PAUDIO_ENDPOINT_SHARED_CREATE_PARAMS;

#ifdef __cplusplus
}
#endif
#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /*_INC_AUDIOENGINEENDPOINT*/
