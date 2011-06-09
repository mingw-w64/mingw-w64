/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __INC_MMDEVICEAPI__
#define __INC_MMDEVICEAPI__

#include <windef.h>

#if (_WIN32_WINNT >= 0x0600)

typedef enum _EDataFlow {
  eRender,
  eCapture,
  eAll,
  EDataFlow_enum_count 
} EDataFlow;

typedef enum _EndpointFormFactor {
  RemoteNetworkDevice,
  Speakers,
  LineLevel,
  Headphones,
  Microphone,
  Headset,
  Handset,
  UnknownDigitalPassthrough,
  SPDIF,
  DigitalAudioDisplayDevice,
  UnknownFormFactor,
  EndpointFormFactor_enum_count 
} EndpointFormFactor;

typedef enum _ERole {
  eConsole,
  eMultimedia,
  eCommunications,
  ERole_enum_count 
} ERole;

typedef struct {
  DWORD cbDirectXAudioActivationParams;
  GUID  guidAudioSession;
  DWORD dwAudioStreamFlags;
} DIRECTX_AUDIO_ACTIVATION_PARAMS, *PDIRECTX_AUDIO_ACTIVATION_PARAMS;

#define DEVICE_STATE_ACTIVE 0x00000001
#define DEVICE_STATE_DISABLED 0x00000002
#define DEVICE_STATE_NOTPRESENT 0x00000004
#define DEVICE_STATE_UNPLUGGED 0x00000008
#define DEVICE_STATEMASK_ALL 0x0000000F

#define ENDPOINT_HARDWARE_SUPPORT_VOLUME 0x00000001
#define ENDPOINT_HARDWARE_SUPPORT_MUTE 0x00000002
#define ENDPOINT_HARDWARE_SUPPORT_METER 0x00000004

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*__INC_MMDEVICEAPI__*/
