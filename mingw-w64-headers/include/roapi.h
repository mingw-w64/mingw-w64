/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __ROAPI_H__
#define __ROAPI_H__

#include <winapifamily.h>
#include <windows.h>
#include <sdkddkver.h>
#include <hstring.h>
#include <inspectable.h>
#include <activation.h>

#if _WIN32_WINNT >= _WIN32_WINNT_WIN8

typedef enum RO_INIT_TYPE {
#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
  RO_INIT_SINGLETHREADED = 0,
#endif
  RO_INIT_MULTITHREADED  = 1
} RO_INIT_TYPE;

typedef struct { } *RO_REGISTRATION_COOKIE;

typedef HRESULT (WINAPI *PFNGETACTIVATIONFACTORY)(HSTRING, IActivationFactory **);

/* */

HRESULT WINAPI RoActivateInstance(HSTRING activatableClassId, IInspectable **instance);

HRESULT WINAPI RoGetActivationFactory(HSTRING activatableClassId, REFIID iid, void **factory);

HRESULT WINAPI RoGetApartmentIdentifier(UINT64 *apartmentIdentifier);

HRESULT WINAPI RoInitialize(RO_INIT_TYPE initType);

HRESULT WINAPI RoRegisterActivationFactories(HSTRING *activatableClassIds, PFNGETACTIVATIONFACTORY *activationFactoryCallbacks, UINT32 count, RO_REGISTRATION_COOKIE *cookie);

void WINAPI RoRevokeActivationFactories(RO_REGISTRATION_COOKIE cookie);

void WINAPI RoUninitialize(void);

typedef interface IApartmentShutdown IApartmentShutdown;
DECLARE_HANDLE (APARTMENT_SHUTDOWN_REGISTRATION_COOKIE);

HRESULT WINAPI RoRegisterForApartmentShutdown (IApartmentShutdown *callbackObj, UINT64 *apartmentId, APARTMENT_SHUTDOWN_REGISTRATION_COOKIE *regCookie);

HRESULT WINAPI RoUnregisterForApartmentShutdown (APARTMENT_SHUTDOWN_REGISTRATION_COOKIE regCookie);

HRESULT WINAPI RoGetApartmentIdentifier (UINT64 *apartmentId);

#endif

#ifdef __cplusplus

namespace Windows {
  namespace Foundation {
    __inline HRESULT Initalize (RO_INIT_TYPE it
#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
	 = 0
#endif
    ) { return RoInitialize (it); }
    __inline void Uninitialize ()
    { RoUninitialize (); }

  }
}

namespace ABI {
  namespace Windows {
    namespace Foundation {
      __inline HRESULT Initialze (RO_INIT_TYPE it
#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
	= 0
#endif
      ) { return RoInitialize (it); }
      __inline void Uninitialize ()
      { RoUninitialize (); }
    }
  }
}

#endif

#endif
