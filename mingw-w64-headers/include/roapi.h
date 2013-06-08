/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __ROAPI_H__
#define __ROAPI_H__

#include <windows.h>
#include <sdkddkver.h>
#include <hstring.h>
#include <inspectable.h>
#include <activation.h>

#if _WIN32_WINNT >= _WIN32_WINNT_WIN8

typedef enum RO_INIT_TYPE {
  RO_INIT_MULTITHREADED  = 1
} RO_INIT_TYPE;

typedef struct {}* RO_REGISTRATION_COOKIE;

typedef HRESULT (WINAPI * PFNGETACTIVATIONFACTORY)(HSTRING, IActivationFactory **);

/* */

HRESULT WINAPI RoActivateInstance(HSTRING activatableClassId, IInspectable **instance);

HRESULT WINAPI RoGetActivationFactory(HSTRING activatableClassId, REFIID iid, void **factory);

HRESULT WINAPI RoGetApartmentIdentifier(UINT64 *apartmentIdentifier);

HRESULT WINAPI RoInitialize(RO_INIT_TYPE initType);

HRESULT WINAPI RoRegisterActivationFactories(HSTRING *activatableClassIds, PFNGETACTIVATIONFACTORY *activationFactoryCallbacks, UINT32 count, RO_REGISTRATION_COOKIE *cookie);

void WINAPI RoRevokeActivationFactories(RO_REGISTRATION_COOKIE cookie);

void WINAPI RoUninitialize(void);

#endif
#endif
