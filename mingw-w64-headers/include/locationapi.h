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
DEFINE_GUID(IID_ILocationReport,0xC8B7F7EE,0x75D0,0x4DB9,0xB6,0x2D,0x7A,0x0F,0x36,0x9C,0xA4,0x56);
DEFINE_GUID(IID_ICivicAddressReport,0xC0B19F70,0x4ADF,0x445D,0x87,0xF2,0xCA,0xD8,0xFD,0x71,0x17,0x92);
DEFINE_GUID(IID_IDefaultLocation,0xA65AF77E,0x969A,0x4A2E,0x8A,0xCA,0x33,0xBB,0x7C,0xBB,0x12,0x35);

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
#define ILocationReport_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ILocationReport_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ILocationReport_Release(This) (This)->lpVtbl->Release(This)
#define ILocationReport_GetSensorID(This,pSensorID) (This)->lpVtbl->GetSensorID(This,pSensorID)
#define ILocationReport_GetTimestamp(This,pCreationTime) (This)->lpVtbl->GetTimestamp(This,pCreationTime)
#define ILocationReport_GetValue(This,pKey,pValue) (This)->lpVtbl->GetValue(This,pKey,pValue)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE ICivicAddressReport
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
    STDMETHOD_(HRESULT,GetStateProvince)(THIS_ BSTR *pbstrStateProvince) PURE;
    STDMETHOD_(HRESULT,GetPostalCode)(THIS_ BSTR *pbstrPostalCode) PURE;
    STDMETHOD_(HRESULT,GetCountryRegion)(THIS_ BSTR *pbstrCountryRegion) PURE;
    STDMETHOD_(HRESULT,GetDetailLevel)(THIS_ DWORD *pDetailLevel) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define ICivicAddressReport_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICivicAddressReport_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICivicAddressReport_Release(This) (This)->lpVtbl->Release(This)
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
DECLARE_INTERFACE_(IDefaultLocation,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDefaultLocation methods */
    STDMETHOD_(HRESULT,SetReport)(THIS_ REFIID reportType,ILocationReport *pLocationReport) PURE;
    STDMETHOD_(HRESULT,GetReport)(THIS_ REFIID reportType,ILocationReport **ppLocationReport) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDefaultLocation_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDefaultLocation_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDefaultLocation_Release(This) (This)->lpVtbl->Release(This)
#define IDefaultLocation_GetReport(This,reportType,ppLocationReport) (This)->lpVtbl->GetReport(This,reportType,ppLocationReport)
#define IDefaultLocation_SetReport(This,reportType,pLocationReport) (This)->lpVtbl->SetReport(This,reportType,pLocationReport)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /*__INC_LOCATIONAPI__*/
