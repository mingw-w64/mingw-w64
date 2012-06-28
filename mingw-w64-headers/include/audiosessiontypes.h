/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __INC_AUDIOSESSIONTYPES__
#define __INC_AUDIOSESSIONTYPES__


typedef enum _AudioSessionState {
  AudioSessionStateInactive   = 0,
  AudioSessionStateActive     = 1,
  AudioSessionStateExpired    = 2 
} AudioSessionState;

typedef enum _AUDCLNT_SHAREMODE {
  AUDCLNT_SHAREMODE_SHARED,
  AUDCLNT_SHAREMODE_EXCLUSIVE 
} AUDCLNT_SHAREMODE;


#define AUDCLNT_STREAMFLAGS_CROSSPROCESS 0x00010000
#define AUDCLNT_STREAMFLAGS_LOOPBACK 0x00020000
#define AUDCLNT_STREAMFLAGS_EVENTCALLBACK 0x00040000
#define AUDCLNT_STREAMFLAGS_NOPERSIST 0x00080000

#define AUDCLNT_SESSIONFLAGS_EXPIREWHENUNOWNED 0x10000000
#define AUDCLNT_SESSIONFLAGS_DISPLAY_HIDE 0x20000000
#define AUDCLNT_SESSIONFLAGS_DISPLAY_HIDEWHENEXPIRED 0x40000000

#endif /*__INC_AUDIOSESSIONTYPES__*/
