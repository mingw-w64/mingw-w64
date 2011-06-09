/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __INC_LOCATIONAPI__
#define __INC_LOCATIONAPI__

#include <objbase.h>

#if (_WIN32_WINNT >= 0x0601)

typedef GUID SENSOR_ID;

#ifndef __ILocationReport_FWD_DEFINED__
#define __ILocationReport_FWD_DEFINED__
typedef struct ILocationReport ILocationReport;
#endif

#ifndef __ICivicAddressReport_FWD_DEFINED__
#define __ICivicAddressReport_FWD_DEFINED__
typedef struct ICivicAddressReport ICivicAddressReport;
#endif

#ifndef __IDefaultLocation_FWD_DEFINED__
#define __IDefaultLocation_FWD_DEFINED__
typedef struct IDefaultLocation IDefaultLocation;
#endif

#undef  INTERFACE
#define INTERFACE ILocationReport
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(ILocationReport,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ILocationReport methods */
    STDMETHOD_(HRESULT,GetSensorID)(THIS_ SENSOR_ID *pSensorID) PURE;
    STDMETHOD_(HRESULT,GetTimestamp)(THIS_ SYSTEMTIME *pCreationTime) PURE;
    STDMETHOD_(HRESULT,GetValue)(THIS_ REFPROPERTYKEY pKey,PROPVARIANT *pValue) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define ILocationReport_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define ILocationReport_AddRef(This) (This)->pVtbl->AddRef(This)
#define ILocationReport_Release(This) (This)->pVtbl->Release(This)
#define ILocationReport_GetSensorID(This,pSensorID) (This)->lpVtbl->GetSensorID(This,pSensorID)
#define ILocationReport_GetTimestamp(This,pCreationTime) (This)->lpVtbl->GetTimestamp(This,pCreationTime)
#define ILocationReport_GetValue(This,pKey,pValue) (This)->lpVtbl->GetValue(This,pKey,pValue)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE ICivicAddressReport
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(ICivicAddressReport,ILocationReport)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ILocationReport methods */
    STDMETHOD_(HRESULT,GetSensorID)(THIS_ SENSOR_ID *pSensorID) PURE;
    STDMETHOD_(HRESULT,GetTimestamp)(THIS_ SYSTEMTIME *pCreationTime) PURE;
    STDMETHOD_(HRESULT,GetValue)(THIS_ REFPROPERTYKEY pKey,PROPVARIANT *pValue) PURE;

    /* ICivicAddressReport methods */
    STDMETHOD_(HRESULT,GetAddressLine1)(THIS_ BSTR *pbstrAddress1) PURE;
    STDMETHOD_(HRESULT,GetAddressLine2)(THIS_ BSTR *pbstrAddress2) PURE;
    STDMETHOD_(HRESULT,GetCity)(THIS_ BSTR *pbstrCity) PURE;
    STDMETHOD_(HRESULT,GetCountryRegion)(THIS_ BSTR *pbstrCountryRegion) PURE;
    STDMETHOD_(HRESULT,GetDetailLevel)(THIS_ DWORD *pDetailLevel) PURE;
    STDMETHOD_(HRESULT,GetPostalCode)(THIS_ BSTR *pbstrPostalCode) PURE;
    STDMETHOD_(HRESULT,GetStateProvince)(THIS_ BSTR *pbstrStateProvince) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define ICivicAddressReport_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define ICivicAddressReport_AddRef(This) (This)->pVtbl->AddRef(This)
#define ICivicAddressReport_Release(This) (This)->pVtbl->Release(This)
#define ICivicAddressReport_GetSensorID(This,pSensorID) (This)->lpVtbl->GetSensorID(This,pSensorID)
#define ICivicAddressReport_GetTimestamp(This,pCreationTime) (This)->lpVtbl->GetTimestamp(This,pCreationTime)
#define ICivicAddressReport_GetValue(This,pKey,pValue) (This)->lpVtbl->GetValue(This,pKey,pValue)
#define ICivicAddressReport_GetAddressLine1(This,pbstrAddress1) (This)->lpVtbl->GetAddressLine1(This,pbstrAddress1)
#define ICivicAddressReport_GetAddressLine2(This,pbstrAddress2) (This)->lpVtbl->GetAddressLine2(This,pbstrAddress2)
#define ICivicAddressReport_GetCity(This,pbstrCity) (This)->lpVtbl->GetCity(This,pbstrCity)
#define ICivicAddressReport_GetCountryRegion(This,pbstrCountryRegion) (This)->lpVtbl->GetCountryRegion(This,pbstrCountryRegion)
#define ICivicAddressReport_GetDetailLevel(This,pDetailLevel) (This)->lpVtbl->GetDetailLevel(This,pDetailLevel)
#define ICivicAddressReport_GetPostalCode(This,pbstrPostalCode) (This)->lpVtbl->GetPostalCode(This,pbstrPostalCode)
#define ICivicAddressReport_GetStateProvince(This,pbstrStateProvince) (This)->lpVtbl->GetStateProvince(This,pbstrStateProvince)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDefaultLocation
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDefaultLocation,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDefaultLocation methods */
    STDMETHOD_(HRESULT,GetReport)(THIS_ REFIID reportType,ILocationReport **ppLocationReport) PURE;
    STDMETHOD_(HRESULT,SetReport)(THIS_ REFIID reportType,ILocationReport *pLocationReport) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDefaultLocation_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IDefaultLocation_AddRef(This) (This)->pVtbl->AddRef(This)
#define IDefaultLocation_Release(This) (This)->pVtbl->Release(This)
#define IDefaultLocation_GetReport(This,reportType,ppLocationReport) (This)->lpVtbl->GetReport(This,reportType,ppLocationReport)
#define IDefaultLocation_SetReport(This,reportType,pLocationReport) (This)->lpVtbl->SetReport(This,reportType,pLocationReport)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /*__INC_LOCATIONAPI__*/
