/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __INC_TUNER__
#define __INC_TUNER__
#include <objbase.h>
#include <comcat.h>
#include <dshow.h>
#include <bdatypes.h>
#include <bdaiface.h>

#ifndef __IBDACreateTuneRequestEx_FWD_DEFINED__
#define __IBDACreateTuneRequestEx_FWD_DEFINED__
typedef struct IBDACreateTuneRequestEx IBDACreateTuneRequestEx;
#endif

#ifndef __ITuneRequest_FWD_DEFINED__
#define __ITuneRequest_FWD_DEFINED__
typedef struct ITuneRequest ITuneRequest;
#endif

#ifndef __IChannelIDTuneRequest_FWD_DEFINED__
#define __IChannelIDTuneRequest_FWD_DEFINED__
typedef struct IChannelIDTuneRequest IChannelIDTuneRequest;
#endif

#ifndef __ILocator_FWD_DEFINED__
#define __ILocator_FWD_DEFINED__
typedef struct ILocator ILocator;
#endif

#ifndef __IDigitalLocator_FWD_DEFINED__
#define __IDigitalLocator_FWD_DEFINED__
typedef struct IDigitalLocator IDigitalLocator;
#endif

#ifndef __IDVBSLocator_FWD_DEFINED__
#define __IDVBSLocator_FWD_DEFINED__
typedef struct IDVBSLocator IDVBSLocator;
#endif

#ifndef __IDVBSLocator2_FWD_DEFINED__
#define __IDVBSLocator2_FWD_DEFINED__
typedef struct IDVBSLocator2 IDVBSLocator2;
#endif

#ifndef __IDVBTLocator_FWD_DEFINED__
#define __IDVBTLocator_FWD_DEFINED__
typedef struct IDVBTLocator IDVBTLocator;
#endif

#ifndef __IDVBTLocator_FWD_DEFINED__
#define __IDVBTLocator_FWD_DEFINED__
typedef struct IDVBTLocator2 IDVBTLocator2;
#endif

#ifndef __IComponents_FWD_DEFINED__
#define __IComponents_FWD_DEFINED__
typedef struct IComponents IComponents;
#endif

#ifndef __IEnumComponents_FWD_DEFINED__
#define __IEnumComponents_FWD_DEFINED__
typedef struct IEnumComponents IEnumComponents;
#endif

#ifndef __IComponent_FWD_DEFINED__
#define __IComponent_FWD_DEFINED__
typedef struct IComponent IComponent;
#endif

#ifndef __IMPEG2Component_FWD_DEFINED__
#define __IMPEG2Component_FWD_DEFINED__
typedef struct IMPEG2Component IMPEG2Component;
#endif

#ifndef __ITuningSpace_FWD_DEFINED__
#define __ITuningSpace_FWD_DEFINED__
typedef struct ITuningSpace ITuningSpace;
#endif

#ifndef __IComponentTypes_FWD_DEFINED__
#define __IComponentTypes_FWD_DEFINED__
typedef struct IComponentTypes IComponentTypes;
#endif

#ifndef __IComponentType_FWD_DEFINED__
#define __IComponentType_FWD_DEFINED__
typedef struct IComponentType IComponentType;
#endif

#ifndef __IEnumComponentTypes_FWD_DEFINED__
#define __IEnumComponentTypes_FWD_DEFINED__
typedef struct IEnumComponentTypes IEnumComponentTypes;
#endif

#undef  INTERFACE
#define INTERFACE IBDACreateTuneRequestEx
DECLARE_INTERFACE_(IBDACreateTuneRequestEx,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBDACreateTuneRequestEx methods */
    STDMETHOD_(HRESULT,CreateTuneRequestEx)(THIS_ REFCLSID TuneRequestIID,ITuneRequest **ppTuneRequest) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IBDACreateTuneRequestEx_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBDACreateTuneRequestEx_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBDACreateTuneRequestEx_Release(This) (This)->lpVtbl->Release(This)
#define IBDACreateTuneRequestEx_CreateTuneRequestEx(This,TuneRequestIID,ppTuneRequest) (This)->lpVtbl->CreateTuneRequestEx(This,TuneRequestIID,ppTuneRequest)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE ITuneRequest
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(ITuneRequest,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* ITuneRequest methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ ITuneRequest **ppNewTuneRequest) PURE;
    STDMETHOD_(HRESULT,get_Components)(THIS_ IComponents **ppComponents) PURE;
    STDMETHOD_(HRESULT,get_Locator)(THIS_ ILocator **ppLocator) PURE;
    STDMETHOD_(HRESULT,get_TuningSpace)(THIS_ ITuningSpace **ppTuningSpace) PURE;
    STDMETHOD_(HRESULT,put_Locator)(THIS_ ILocator *pLocator) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define ITuneRequest_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITuneRequest_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITuneRequest_Release(This) (This)->lpVtbl->Release(This)
#define ITuneRequest_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ITuneRequest_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ITuneRequest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ITuneRequest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ITuneRequest_Clone(This,ppNewTuneRequest) (This)->lpVtbl->Clone(This,ppNewTuneRequest)
#define ITuneRequest_get_Components(This,ppComponents) (This)->lpVtbl->get_Components(This,ppComponents)
#define ITuneRequest_get_Locator(This,ppLocator) (This)->lpVtbl->get_Locator(This,ppLocator)
#define ITuneRequest_get_TuningSpace(This,ppTuningSpace) (This)->lpVtbl->get_TuningSpace(This,ppTuningSpace)
#define ITuneRequest_put_Locator(This,pLocator) (This)->lpVtbl->put_Locator(This,pLocator)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IChannelIDTuneRequest
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IChannelIDTuneRequest,ITuneRequest)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IChannelIDTuneRequest methods */
    STDMETHOD_(HRESULT,put_ChannelID)(THIS_ BSTR ChannelID) PURE;
    STDMETHOD_(HRESULT,get_ChannelID)(THIS_ BSTR *ChannelID) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IChannelIDTuneRequest_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IChannelIDTuneRequest_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IChannelIDTuneRequest_Release(This) (This)->lpVtbl->Release(This)
#define IChannelIDTuneRequest_put_ChannelID(This,ChannelID) (This)->lpVtbl->put_ChannelID(This,ChannelID)
#define IChannelIDTuneRequest_get_ChannelID(This,ChannelID) (This)->lpVtbl->get_ChannelID(This,ChannelID)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE ILocator
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(ILocator,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* ILocator methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ ILocator **ppNewLocator) PURE;
    STDMETHOD_(HRESULT,get_CarrierFrequency)(THIS_ __LONG32 *pFrequency) PURE;
    STDMETHOD_(HRESULT,get_InnerFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_InnerFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_Modulation)(THIS_ ModulationType *pModulation) PURE;
    STDMETHOD_(HRESULT,get_OuterFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_OuterFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_SymbolRate)(THIS_ __LONG32 *Rate) PURE;
    STDMETHOD_(HRESULT,put_CarrierFrequency)(THIS_ __LONG32 Frequency) PURE;
    STDMETHOD_(HRESULT,put_InnerFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_InnerFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_Modulation)(THIS_ ModulationType Modulation) PURE;
    STDMETHOD_(HRESULT,put_OuterFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_OuterFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_SymbolRate)(THIS_ __LONG32 Rate) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define ILocator_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ILocator_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ILocator_Release(This) (This)->lpVtbl->Release(This)
#define ILocator_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ILocator_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ILocator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ILocator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ILocator_Clone(This,ppNewLocator) (This)->lpVtbl->Clone(This,ppNewLocator)
#define ILocator_get_CarrierFrequency(This,pFrequency) (This)->lpVtbl->get_CarrierFrequency(This,pFrequency)
#define ILocator_get_InnerFEC(This,FEC) (This)->lpVtbl->get_InnerFEC(This,FEC)
#define ILocator_get_InnerFECRate(This,FEC) (This)->lpVtbl->get_InnerFECRate(This,FEC)
#define ILocator_get_Modulation(This,pModulation) (This)->lpVtbl->get_Modulation(This,pModulation)
#define ILocator_get_OuterFEC(This,FEC) (This)->lpVtbl->get_OuterFEC(This,FEC)
#define ILocator_get_OuterFECRate(This,FEC) (This)->lpVtbl->get_OuterFECRate(This,FEC)
#define ILocator_get_SymbolRate(This,Rate) (This)->lpVtbl->get_SymbolRate(This,Rate)
#define ILocator_put_CarrierFrequency(This,Frequency) (This)->lpVtbl->put_CarrierFrequency(This,Frequency)
#define ILocator_put_InnerFEC(This,FEC) (This)->lpVtbl->put_InnerFEC(This,FEC)
#define ILocator_put_InnerFECRate(This,FEC) (This)->lpVtbl->put_InnerFECRate(This,FEC)
#define ILocator_put_Modulation(This,Modulation) (This)->lpVtbl->put_Modulation(This,Modulation)
#define ILocator_put_OuterFEC(This,FEC) (This)->lpVtbl->put_OuterFEC(This,FEC)
#define ILocator_put_OuterFECRate(This,FEC) (This)->lpVtbl->put_OuterFECRate(This,FEC)
#define ILocator_put_SymbolRate(This,Rate) (This)->lpVtbl->put_SymbolRate(This,Rate)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDigitalLocator
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDigitalLocator,ILocator)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* ILocator methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ ILocator **ppNewLocator) PURE;
    STDMETHOD_(HRESULT,get_CarrierFrequency)(THIS_ __LONG32 *pFrequency) PURE;
    STDMETHOD_(HRESULT,get_InnerFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_InnerFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_Modulation)(THIS_ ModulationType *pModulation) PURE;
    STDMETHOD_(HRESULT,get_OuterFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_OuterFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_SymbolRate)(THIS_ __LONG32 *Rate) PURE;
    STDMETHOD_(HRESULT,put_CarrierFrequency)(THIS_ __LONG32 Frequency) PURE;
    STDMETHOD_(HRESULT,put_InnerFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_InnerFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_Modulation)(THIS_ ModulationType Modulation) PURE;
    STDMETHOD_(HRESULT,put_OuterFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_OuterFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_SymbolRate)(THIS_ __LONG32 Rate) PURE;

    /* IDigitalLocator methods */

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDigitalLocator_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDigitalLocator_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDigitalLocator_Release(This) (This)->lpVtbl->Release(This)
#define IDigitalLocator_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IDigitalLocator_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDigitalLocator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDigitalLocator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDigitalLocator_Clone(This,ppNewLocator) (This)->lpVtbl->Clone(This,ppNewLocator)
#define IDigitalLocator_get_CarrierFrequency(This,pFrequency) (This)->lpVtbl->get_CarrierFrequency(This,pFrequency)
#define IDigitalLocator_get_InnerFEC(This,FEC) (This)->lpVtbl->get_InnerFEC(This,FEC)
#define IDigitalLocator_get_InnerFECRate(This,FEC) (This)->lpVtbl->get_InnerFECRate(This,FEC)
#define IDigitalLocator_get_Modulation(This,pModulation) (This)->lpVtbl->get_Modulation(This,pModulation)
#define IDigitalLocator_get_OuterFEC(This,FEC) (This)->lpVtbl->get_OuterFEC(This,FEC)
#define IDigitalLocator_get_OuterFECRate(This,FEC) (This)->lpVtbl->get_OuterFECRate(This,FEC)
#define IDigitalLocator_get_SymbolRate(This,Rate) (This)->lpVtbl->get_SymbolRate(This,Rate)
#define IDigitalLocator_put_CarrierFrequency(This,Frequency) (This)->lpVtbl->put_CarrierFrequency(This,Frequency)
#define IDigitalLocator_put_InnerFEC(This,FEC) (This)->lpVtbl->put_InnerFEC(This,FEC)
#define IDigitalLocator_put_InnerFECRate(This,FEC) (This)->lpVtbl->put_InnerFECRate(This,FEC)
#define IDigitalLocator_put_Modulation(This,Modulation) (This)->lpVtbl->put_Modulation(This,Modulation)
#define IDigitalLocator_put_OuterFEC(This,FEC) (This)->lpVtbl->put_OuterFEC(This,FEC)
#define IDigitalLocator_put_OuterFECRate(This,FEC) (This)->lpVtbl->put_OuterFECRate(This,FEC)
#define IDigitalLocator_put_SymbolRate(This,Rate) (This)->lpVtbl->put_SymbolRate(This,Rate)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDVBSLocator
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDVBSLocator,IDigitalLocator)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* ILocator methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ ILocator **ppNewLocator) PURE;
    STDMETHOD_(HRESULT,get_CarrierFrequency)(THIS_ __LONG32 *pFrequency) PURE;
    STDMETHOD_(HRESULT,get_InnerFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_InnerFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_Modulation)(THIS_ ModulationType *pModulation) PURE;
    STDMETHOD_(HRESULT,get_OuterFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_OuterFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_SymbolRate)(THIS_ __LONG32 *Rate) PURE;
    STDMETHOD_(HRESULT,put_CarrierFrequency)(THIS_ __LONG32 Frequency) PURE;
    STDMETHOD_(HRESULT,put_InnerFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_InnerFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_Modulation)(THIS_ ModulationType Modulation) PURE;
    STDMETHOD_(HRESULT,put_OuterFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_OuterFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_SymbolRate)(THIS_ __LONG32 Rate) PURE;

    /* IDigitalLocator methods */

    /* IDVBSLocator methods */
    STDMETHOD_(HRESULT,get_Azimuth)(THIS_ __LONG32 *pAzimuth) PURE;
    STDMETHOD_(HRESULT,get_Elevation)(THIS_ __LONG32 *pElevation) PURE;
    STDMETHOD_(HRESULT,get_OrbitalPosition)(THIS_ __LONG32 *plongitude) PURE;
    STDMETHOD_(HRESULT,get_SignalPolarisation)(THIS_ Polarisation *pPolarisationVal) PURE;
    STDMETHOD_(HRESULT,get_WestPosition)(THIS_ VARIANT_BOOL *pWestLongitude) PURE;
    STDMETHOD_(HRESULT,put_Azimuth)(THIS_ __LONG32 Azimuth) PURE;
    STDMETHOD_(HRESULT,put_Elevation)(THIS_ __LONG32 Elevation) PURE;
    STDMETHOD_(HRESULT,put_OrbitalPosition)(THIS_ __LONG32 longitude) PURE;
    STDMETHOD_(HRESULT,put_SignalPolarisation)(THIS_ Polarisation PolarisationVal) PURE;
    STDMETHOD_(HRESULT,put_WestPosition)(THIS_ VARIANT_BOOL WestLongitude) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDVBSLocator_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDVBSLocator_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDVBSLocator_Release(This) (This)->lpVtbl->Release(This)
#define IDVBSLocator_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IDVBSLocator_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDVBSLocator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDVBSLocator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDVBSLocator_Clone(This,ppNewLocator) (This)->lpVtbl->Clone(This,ppNewLocator)
#define IDVBSLocator_get_CarrierFrequency(This,pFrequency) (This)->lpVtbl->get_CarrierFrequency(This,pFrequency)
#define IDVBSLocator_get_InnerFEC(This,FEC) (This)->lpVtbl->get_InnerFEC(This,FEC)
#define IDVBSLocator_get_InnerFECRate(This,FEC) (This)->lpVtbl->get_InnerFECRate(This,FEC)
#define IDVBSLocator_get_Modulation(This,pModulation) (This)->lpVtbl->get_Modulation(This,pModulation)
#define IDVBSLocator_get_OuterFEC(This,FEC) (This)->lpVtbl->get_OuterFEC(This,FEC)
#define IDVBSLocator_get_OuterFECRate(This,FEC) (This)->lpVtbl->get_OuterFECRate(This,FEC)
#define IDVBSLocator_get_SymbolRate(This,Rate) (This)->lpVtbl->get_SymbolRate(This,Rate)
#define IDVBSLocator_put_CarrierFrequency(This,Frequency) (This)->lpVtbl->put_CarrierFrequency(This,Frequency)
#define IDVBSLocator_put_InnerFEC(This,FEC) (This)->lpVtbl->put_InnerFEC(This,FEC)
#define IDVBSLocator_put_InnerFECRate(This,FEC) (This)->lpVtbl->put_InnerFECRate(This,FEC)
#define IDVBSLocator_put_Modulation(This,Modulation) (This)->lpVtbl->put_Modulation(This,Modulation)
#define IDVBSLocator_put_OuterFEC(This,FEC) (This)->lpVtbl->put_OuterFEC(This,FEC)
#define IDVBSLocator_put_OuterFECRate(This,FEC) (This)->lpVtbl->put_OuterFECRate(This,FEC)
#define IDVBSLocator_put_SymbolRate(This,Rate) (This)->lpVtbl->put_SymbolRate(This,Rate)
#define IDVBSLocator_get_Azimuth(This,pAzimuth) (This)->lpVtbl->get_Azimuth(This,pAzimuth)
#define IDVBSLocator_get_Elevation(This,pElevation) (This)->lpVtbl->get_Elevation(This,pElevation)
#define IDVBSLocator_get_OrbitalPosition(This,plongitude) (This)->lpVtbl->get_OrbitalPosition(This,plongitude)
#define IDVBSLocator_get_SignalPolarisation(This,pPolarisationVal) (This)->lpVtbl->get_SignalPolarisation(This,pPolarisationVal)
#define IDVBSLocator_get_WestPosition(This,pWestLongitude) (This)->lpVtbl->get_WestPosition(This,pWestLongitude)
#define IDVBSLocator_put_Azimuth(This,Azimuth) (This)->lpVtbl->put_Azimuth(This,Azimuth)
#define IDVBSLocator_put_Elevation(This,Elevation) (This)->lpVtbl->put_Elevation(This,Elevation)
#define IDVBSLocator_put_OrbitalPosition(This,longitude) (This)->lpVtbl->put_OrbitalPosition(This,longitude)
#define IDVBSLocator_put_SignalPolarisation(This,PolarisationVal) (This)->lpVtbl->put_SignalPolarisation(This,PolarisationVal)
#define IDVBSLocator_put_WestPosition(This,WestLongitude) (This)->lpVtbl->put_WestPosition(This,WestLongitude)
#endif /*COBJMACROS*/

#if (_WIN32_WINNT >= 0x0601)

#undef  INTERFACE
#define INTERFACE IDVBSLocator2
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDVBSLocator2,IDVBSLocator)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* ILocator methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ ILocator **ppNewLocator) PURE;
    STDMETHOD_(HRESULT,get_CarrierFrequency)(THIS_ __LONG32 *pFrequency) PURE;
    STDMETHOD_(HRESULT,get_InnerFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_InnerFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_Modulation)(THIS_ ModulationType *pModulation) PURE;
    STDMETHOD_(HRESULT,get_OuterFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_OuterFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_SymbolRate)(THIS_ __LONG32 *Rate) PURE;
    STDMETHOD_(HRESULT,put_CarrierFrequency)(THIS_ __LONG32 Frequency) PURE;
    STDMETHOD_(HRESULT,put_InnerFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_InnerFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_Modulation)(THIS_ ModulationType Modulation) PURE;
    STDMETHOD_(HRESULT,put_OuterFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_OuterFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_SymbolRate)(THIS_ __LONG32 Rate) PURE;

    /* IDigitalLocator methods */

    /* IDVBSLocator methods */
    STDMETHOD_(HRESULT,get_Azimuth)(THIS_ __LONG32 *pAzimuth) PURE;
    STDMETHOD_(HRESULT,get_Elevation)(THIS_ __LONG32 *pElevation) PURE;
    STDMETHOD_(HRESULT,get_OrbitalPosition)(THIS_ __LONG32 *plongitude) PURE;
    STDMETHOD_(HRESULT,get_SignalPolarisation)(THIS_ Polarisation *pPolarisationVal) PURE;
    STDMETHOD_(HRESULT,get_WestPosition)(THIS_ VARIANT_BOOL *pWestLongitude) PURE;
    STDMETHOD_(HRESULT,put_Azimuth)(THIS_ __LONG32 Azimuth) PURE;
    STDMETHOD_(HRESULT,put_Elevation)(THIS_ __LONG32 Elevation) PURE;
    STDMETHOD_(HRESULT,put_OrbitalPosition)(THIS_ __LONG32 longitude) PURE;
    STDMETHOD_(HRESULT,put_SignalPolarisation)(THIS_ Polarisation PolarisationVal) PURE;
    STDMETHOD_(HRESULT,put_WestPosition)(THIS_ VARIANT_BOOL WestLongitude) PURE;

    /* IDVBSLocator2 methods */
    STDMETHOD_(HRESULT,put_DiseqLNBSource)(THIS_ LNB_Source DiseqLNBSourceVal) PURE;
    STDMETHOD_(HRESULT,get_DiseqLNBSource)(THIS_ LNB_Source *DiseqLNBSourceVal) PURE;
    STDMETHOD_(HRESULT,put_LocalLNBSwitchOverride)(THIS_ __LONG32 LocalLNBSwitchOverrideVal) PURE;
    STDMETHOD_(HRESULT,get_LocalLNBSwitchOverride)(THIS_ __LONG32 *LocalLNBSwitchOverrideVal) PURE;
    STDMETHOD_(HRESULT,put_LocalOscillatorOverrideHigh)(THIS_ __LONG32 LocalOscillatorOverrideHighVal) PURE;
    STDMETHOD_(HRESULT,get_LocalOscillatorOverrideHigh)(THIS_ __LONG32 *LocalOscillatorOverrideHighVal) PURE;
    STDMETHOD_(HRESULT,put_LocalOscillatorOverrideLow)(THIS_ __LONG32 LocalOscillatorOverrideLowVal) PURE;
    STDMETHOD_(HRESULT,get_LocalOscillatorOverrideLow)(THIS_ __LONG32 *LocalOscillatorOverrideLowVal) PURE;
    STDMETHOD_(HRESULT,put_LocalSpectralInversionOverride)(THIS_ SpectralInversion LocalSpectralInversionOverrideVal) PURE;
    STDMETHOD_(HRESULT,get_LocalSpectralInversionOverride)(THIS_ SpectralInversion *LocalSpectralInversionOverrideVal) PURE;
    STDMETHOD_(HRESULT,put_SignalPilot)(THIS_ Pilot PilotVal) PURE;
    STDMETHOD_(HRESULT,get_SignalPilot)(THIS_ Pilot *PilotVal) PURE;
    STDMETHOD_(HRESULT,put_SignalRollOff)(THIS_ RollOff RollOffVal) PURE;
    STDMETHOD_(HRESULT,get_SignalRollOff)(THIS_ RollOff *RollOffVal) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDVBSLocator2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDVBSLocator2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDVBSLocator2_Release(This) (This)->lpVtbl->Release(This)
#define IDVBSLocator2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IDVBSLocator2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDVBSLocator2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDVBSLocator2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDVBSLocator2_Clone(This,ppNewLocator) (This)->lpVtbl->Clone(This,ppNewLocator)
#define IDVBSLocator2_get_CarrierFrequency(This,pFrequency) (This)->lpVtbl->get_CarrierFrequency(This,pFrequency)
#define IDVBSLocator2_get_InnerFEC(This,FEC) (This)->lpVtbl->get_InnerFEC(This,FEC)
#define IDVBSLocator2_get_InnerFECRate(This,FEC) (This)->lpVtbl->get_InnerFECRate(This,FEC)
#define IDVBSLocator2_get_Modulation(This,pModulation) (This)->lpVtbl->get_Modulation(This,pModulation)
#define IDVBSLocator2_get_OuterFEC(This,FEC) (This)->lpVtbl->get_OuterFEC(This,FEC)
#define IDVBSLocator2_get_OuterFECRate(This,FEC) (This)->lpVtbl->get_OuterFECRate(This,FEC)
#define IDVBSLocator2_get_SymbolRate(This,Rate) (This)->lpVtbl->get_SymbolRate(This,Rate)
#define IDVBSLocator2_put_CarrierFrequency(This,Frequency) (This)->lpVtbl->put_CarrierFrequency(This,Frequency)
#define IDVBSLocator2_put_InnerFEC(This,FEC) (This)->lpVtbl->put_InnerFEC(This,FEC)
#define IDVBSLocator2_put_InnerFECRate(This,FEC) (This)->lpVtbl->put_InnerFECRate(This,FEC)
#define IDVBSLocator2_put_Modulation(This,Modulation) (This)->lpVtbl->put_Modulation(This,Modulation)
#define IDVBSLocator2_put_OuterFEC(This,FEC) (This)->lpVtbl->put_OuterFEC(This,FEC)
#define IDVBSLocator2_put_OuterFECRate(This,FEC) (This)->lpVtbl->put_OuterFECRate(This,FEC)
#define IDVBSLocator2_put_SymbolRate(This,Rate) (This)->lpVtbl->put_SymbolRate(This,Rate)
#define IDVBSLocator2_get_Azimuth(This,pAzimuth) (This)->lpVtbl->get_Azimuth(This,pAzimuth)
#define IDVBSLocator2_get_Elevation(This,pElevation) (This)->lpVtbl->get_Elevation(This,pElevation)
#define IDVBSLocator2_get_OrbitalPosition(This,plongitude) (This)->lpVtbl->get_OrbitalPosition(This,plongitude)
#define IDVBSLocator2_get_SignalPolarisation(This,pPolarisationVal) (This)->lpVtbl->get_SignalPolarisation(This,pPolarisationVal)
#define IDVBSLocator2_get_WestPosition(This,pWestLongitude) (This)->lpVtbl->get_WestPosition(This,pWestLongitude)
#define IDVBSLocator2_put_Azimuth(This,Azimuth) (This)->lpVtbl->put_Azimuth(This,Azimuth)
#define IDVBSLocator2_put_Elevation(This,Elevation) (This)->lpVtbl->put_Elevation(This,Elevation)
#define IDVBSLocator2_put_OrbitalPosition(This,longitude) (This)->lpVtbl->put_OrbitalPosition(This,longitude)
#define IDVBSLocator2_put_SignalPolarisation(This,PolarisationVal) (This)->lpVtbl->put_SignalPolarisation(This,PolarisationVal)
#define IDVBSLocator2_put_WestPosition(This,WestLongitude) (This)->lpVtbl->put_WestPosition(This,WestLongitude)
#define IDVBSLocator2_put_DiseqLNBSource(This,DiseqLNBSourceVal) (This)->lpVtbl->put_DiseqLNBSource(This,DiseqLNBSourceVal)
#define IDVBSLocator2_get_DiseqLNBSource(This,DiseqLNBSourceVal) (This)->lpVtbl->get_DiseqLNBSource(This,DiseqLNBSourceVal)
#define IDVBSLocator2_put_LocalLNBSwitchOverride(This,LocalLNBSwitchOverrideVal) (This)->lpVtbl->put_LocalLNBSwitchOverride(This,LocalLNBSwitchOverrideVal)
#define IDVBSLocator2_get_LocalLNBSwitchOverride(This,LocalLNBSwitchOverrideVal) (This)->lpVtbl->get_LocalLNBSwitchOverride(This,LocalLNBSwitchOverrideVal)
#define IDVBSLocator2_put_LocalOscillatorOverrideHigh(This,LocalOscillatorOverrideHighVal) (This)->lpVtbl->put_LocalOscillatorOverrideHigh(This,LocalOscillatorOverrideHighVal)
#define IDVBSLocator2_get_LocalOscillatorOverrideHigh(This,LocalOscillatorOverrideHighVal) (This)->lpVtbl->get_LocalOscillatorOverrideHigh(This,LocalOscillatorOverrideHighVal)
#define IDVBSLocator2_put_LocalOscillatorOverrideLow(This,LocalOscillatorOverrideLowVal) (This)->lpVtbl->put_LocalOscillatorOverrideLow(This,LocalOscillatorOverrideLowVal)
#define IDVBSLocator2_get_LocalOscillatorOverrideLow(This,LocalOscillatorOverrideLowVal) (This)->lpVtbl->get_LocalOscillatorOverrideLow(This,LocalOscillatorOverrideLowVal)
#define IDVBSLocator2_put_LocalSpectralInversionOverride(This,LocalSpectralInversionOverrideVal) (This)->lpVtbl->put_LocalSpectralInversionOverride(This,LocalSpectralInversionOverrideVal)
#define IDVBSLocator2_get_LocalSpectralInversionOverride(This,LocalSpectralInversionOverrideVal) (This)->lpVtbl->get_LocalSpectralInversionOverride(This,LocalSpectralInversionOverrideVal)
#define IDVBSLocator2_put_SignalPilot(This,PilotVal) (This)->lpVtbl->put_SignalPilot(This,PilotVal)
#define IDVBSLocator2_get_SignalPilot(This,PilotVal) (This)->lpVtbl->get_SignalPilot(This,PilotVal)
#define IDVBSLocator2_put_SignalRollOff(This,RollOffVal) (This)->lpVtbl->put_SignalRollOff(This,RollOffVal)
#define IDVBSLocator2_get_SignalRollOff(This,RollOffVal) (This)->lpVtbl->get_SignalRollOff(This,RollOffVal)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0601)*/

#undef  INTERFACE
#define INTERFACE IDVBTLocator
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDVBTLocator,IDigitalLocator)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* ILocator methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ ILocator **ppNewLocator) PURE;
    STDMETHOD_(HRESULT,get_CarrierFrequency)(THIS_ __LONG32 *pFrequency) PURE;
    STDMETHOD_(HRESULT,get_InnerFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_InnerFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_Modulation)(THIS_ ModulationType *pModulation) PURE;
    STDMETHOD_(HRESULT,get_OuterFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_OuterFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_SymbolRate)(THIS_ __LONG32 *Rate) PURE;
    STDMETHOD_(HRESULT,put_CarrierFrequency)(THIS_ __LONG32 Frequency) PURE;
    STDMETHOD_(HRESULT,put_InnerFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_InnerFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_Modulation)(THIS_ ModulationType Modulation) PURE;
    STDMETHOD_(HRESULT,put_OuterFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_OuterFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_SymbolRate)(THIS_ __LONG32 Rate) PURE;

    /* IDigitalLocator methods */

    /* IDVBTLocator methods */
    STDMETHOD_(HRESULT,get_Bandwidth)(THIS_ __LONG32 *pBandWidthVal) PURE;
    STDMETHOD_(HRESULT,get_Guard)(THIS_ GuardInterval *pGI) PURE;
    STDMETHOD_(HRESULT,get_HAlpha)(THIS_ HierarchyAlpha *pAlpha) PURE;
    STDMETHOD_(HRESULT,get_LPInnerFEC)(THIS_ FECMethod *pFEC) PURE;
    STDMETHOD_(HRESULT,get_LPInnerFECRate)(THIS_ BinaryConvolutionCodeRate *pFEC) PURE;
    STDMETHOD_(HRESULT,get_Mode)(THIS_ TransmissionMode *pmode) PURE;
    STDMETHOD_(HRESULT,get_OtherFrequencyInUse)(THIS_ VARIANT_BOOL *pOtherFrequencyInUseVal) PURE;
    STDMETHOD_(HRESULT,put_Bandwidth)(THIS_ __LONG32 BandwidthVal) PURE;
    STDMETHOD_(HRESULT,put_Guard)(THIS_ GuardInterval GI) PURE;
    STDMETHOD_(HRESULT,put_HAlpha)(THIS_ HierarchyAlpha Alpha) PURE;
    STDMETHOD_(HRESULT,put_LPInnerFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_LPInnerFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_Mode)(THIS_ TransmissionMode mode) PURE;
    STDMETHOD_(HRESULT,put_OtherFrequencyInUse)(THIS_ VARIANT_BOOL OtherFrequencyInUseVal) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDVBTLocator_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDVBTLocator_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDVBTLocator_Release(This) (This)->lpVtbl->Release(This)
#define IDVBTLocator_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IDVBTLocator_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDVBTLocator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDVBTLocator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDVBTLocator_Clone(This,ppNewLocator) (This)->lpVtbl->Clone(This,ppNewLocator)
#define IDVBTLocator_get_CarrierFrequency(This,pFrequency) (This)->lpVtbl->get_CarrierFrequency(This,pFrequency)
#define IDVBTLocator_get_InnerFEC(This,FEC) (This)->lpVtbl->get_InnerFEC(This,FEC)
#define IDVBTLocator_get_InnerFECRate(This,FEC) (This)->lpVtbl->get_InnerFECRate(This,FEC)
#define IDVBTLocator_get_Modulation(This,pModulation) (This)->lpVtbl->get_Modulation(This,pModulation)
#define IDVBTLocator_get_OuterFEC(This,FEC) (This)->lpVtbl->get_OuterFEC(This,FEC)
#define IDVBTLocator_get_OuterFECRate(This,FEC) (This)->lpVtbl->get_OuterFECRate(This,FEC)
#define IDVBTLocator_get_SymbolRate(This,Rate) (This)->lpVtbl->get_SymbolRate(This,Rate)
#define IDVBTLocator_put_CarrierFrequency(This,Frequency) (This)->lpVtbl->put_CarrierFrequency(This,Frequency)
#define IDVBTLocator_put_InnerFEC(This,FEC) (This)->lpVtbl->put_InnerFEC(This,FEC)
#define IDVBTLocator_put_InnerFECRate(This,FEC) (This)->lpVtbl->put_InnerFECRate(This,FEC)
#define IDVBTLocator_put_Modulation(This,Modulation) (This)->lpVtbl->put_Modulation(This,Modulation)
#define IDVBTLocator_put_OuterFEC(This,FEC) (This)->lpVtbl->put_OuterFEC(This,FEC)
#define IDVBTLocator_put_OuterFECRate(This,FEC) (This)->lpVtbl->put_OuterFECRate(This,FEC)
#define IDVBTLocator_put_SymbolRate(This,Rate) (This)->lpVtbl->put_SymbolRate(This,Rate)
#define IDVBTLocator_get_Bandwidth(This,pBandWidthVal) (This)->lpVtbl->get_Bandwidth(This,pBandWidthVal)
#define IDVBTLocator_get_Guard(This,pGI) (This)->lpVtbl->get_Guard(This,pGI)
#define IDVBTLocator_get_HAlpha(This,pAlpha) (This)->lpVtbl->get_HAlpha(This,pAlpha)
#define IDVBTLocator_get_LPInnerFEC(This,pFEC) (This)->lpVtbl->get_LPInnerFEC(This,pFEC)
#define IDVBTLocator_get_LPInnerFECRate(This,pFEC) (This)->lpVtbl->get_LPInnerFECRate(This,pFEC)
#define IDVBTLocator_get_Mode(This,pmode) (This)->lpVtbl->get_Mode(This,pmode)
#define IDVBTLocator_get_OtherFrequencyInUse(This,pOtherFrequencyInUseVal) (This)->lpVtbl->get_OtherFrequencyInUse(This,pOtherFrequencyInUseVal)
#define IDVBTLocator_put_Bandwidth(This,BandwidthVal) (This)->lpVtbl->put_Bandwidth(This,BandwidthVal)
#define IDVBTLocator_put_Guard(This,GI) (This)->lpVtbl->put_Guard(This,GI)
#define IDVBTLocator_put_HAlpha(This,Alpha) (This)->lpVtbl->put_HAlpha(This,Alpha)
#define IDVBTLocator_put_LPInnerFEC(This,FEC) (This)->lpVtbl->put_LPInnerFEC(This,FEC)
#define IDVBTLocator_put_LPInnerFECRate(This,FEC) (This)->lpVtbl->put_LPInnerFECRate(This,FEC)
#define IDVBTLocator_put_Mode(This,mode) (This)->lpVtbl->put_Mode(This,mode)
#define IDVBTLocator_put_OtherFrequencyInUse(This,OtherFrequencyInUseVal) (This)->lpVtbl->put_OtherFrequencyInUse(This,OtherFrequencyInUseVal)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IDVBTLocator2
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IDVBTLocator2,IDVBTLocator)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* ILocator methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ ILocator **ppNewLocator) PURE;
    STDMETHOD_(HRESULT,get_CarrierFrequency)(THIS_ __LONG32 *pFrequency) PURE;
    STDMETHOD_(HRESULT,get_InnerFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_InnerFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_Modulation)(THIS_ ModulationType *pModulation) PURE;
    STDMETHOD_(HRESULT,get_OuterFEC)(THIS_ FECMethod *FEC) PURE;
    STDMETHOD_(HRESULT,get_OuterFECRate)(THIS_ BinaryConvolutionCodeRate *FEC) PURE;
    STDMETHOD_(HRESULT,get_SymbolRate)(THIS_ __LONG32 *Rate) PURE;
    STDMETHOD_(HRESULT,put_CarrierFrequency)(THIS_ __LONG32 Frequency) PURE;
    STDMETHOD_(HRESULT,put_InnerFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_InnerFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_Modulation)(THIS_ ModulationType Modulation) PURE;
    STDMETHOD_(HRESULT,put_OuterFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_OuterFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_SymbolRate)(THIS_ __LONG32 Rate) PURE;

    /* IDigitalLocator methods */

    /* IDVBTLocator methods */
    STDMETHOD_(HRESULT,get_Bandwidth)(THIS_ __LONG32 *pBandWidthVal) PURE;
    STDMETHOD_(HRESULT,get_Guard)(THIS_ GuardInterval *pGI) PURE;
    STDMETHOD_(HRESULT,get_HAlpha)(THIS_ HierarchyAlpha *pAlpha) PURE;
    STDMETHOD_(HRESULT,get_LPInnerFEC)(THIS_ FECMethod *pFEC) PURE;
    STDMETHOD_(HRESULT,get_LPInnerFECRate)(THIS_ BinaryConvolutionCodeRate *pFEC) PURE;
    STDMETHOD_(HRESULT,get_Mode)(THIS_ TransmissionMode *pmode) PURE;
    STDMETHOD_(HRESULT,get_OtherFrequencyInUse)(THIS_ VARIANT_BOOL *pOtherFrequencyInUseVal) PURE;
    STDMETHOD_(HRESULT,put_Bandwidth)(THIS_ __LONG32 BandwidthVal) PURE;
    STDMETHOD_(HRESULT,put_Guard)(THIS_ GuardInterval GI) PURE;
    STDMETHOD_(HRESULT,put_HAlpha)(THIS_ HierarchyAlpha Alpha) PURE;
    STDMETHOD_(HRESULT,put_LPInnerFEC)(THIS_ FECMethod FEC) PURE;
    STDMETHOD_(HRESULT,put_LPInnerFECRate)(THIS_ BinaryConvolutionCodeRate FEC) PURE;
    STDMETHOD_(HRESULT,put_Mode)(THIS_ TransmissionMode mode) PURE;
    STDMETHOD_(HRESULT,put_OtherFrequencyInUse)(THIS_ VARIANT_BOOL OtherFrequencyInUseVal) PURE;

    /* IDVBTLocator2 methods */
    STDMETHOD_(HRESULT,put_PhysicalLayerPipeId)(THIS_ __LONG32 PhysicalLayerPipeIdVal) PURE;
    STDMETHOD_(HRESULT,get_PhysicalLayerPipeId)(THIS_ __LONG32 *PhysicalLayerPipeIdVal) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IDVBTLocator2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDVBTLocator2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDVBTLocator2_Release(This) (This)->lpVtbl->Release(This)
#define IDVBTLocator2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IDVBTLocator2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IDVBTLocator2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IDVBTLocator2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IDVBTLocator2_Clone(This,ppNewLocator) (This)->lpVtbl->Clone(This,ppNewLocator)
#define IDVBTLocator2_get_CarrierFrequency(This,pFrequency) (This)->lpVtbl->get_CarrierFrequency(This,pFrequency)
#define IDVBTLocator2_get_InnerFEC(This,FEC) (This)->lpVtbl->get_InnerFEC(This,FEC)
#define IDVBTLocator2_get_InnerFECRate(This,FEC) (This)->lpVtbl->get_InnerFECRate(This,FEC)
#define IDVBTLocator2_get_Modulation(This,pModulation) (This)->lpVtbl->get_Modulation(This,pModulation)
#define IDVBTLocator2_get_OuterFEC(This,FEC) (This)->lpVtbl->get_OuterFEC(This,FEC)
#define IDVBTLocator2_get_OuterFECRate(This,FEC) (This)->lpVtbl->get_OuterFECRate(This,FEC)
#define IDVBTLocator2_get_SymbolRate(This,Rate) (This)->lpVtbl->get_SymbolRate(This,Rate)
#define IDVBTLocator2_put_CarrierFrequency(This,Frequency) (This)->lpVtbl->put_CarrierFrequency(This,Frequency)
#define IDVBTLocator2_put_InnerFEC(This,FEC) (This)->lpVtbl->put_InnerFEC(This,FEC)
#define IDVBTLocator2_put_InnerFECRate(This,FEC) (This)->lpVtbl->put_InnerFECRate(This,FEC)
#define IDVBTLocator2_put_Modulation(This,Modulation) (This)->lpVtbl->put_Modulation(This,Modulation)
#define IDVBTLocator2_put_OuterFEC(This,FEC) (This)->lpVtbl->put_OuterFEC(This,FEC)
#define IDVBTLocator2_put_OuterFECRate(This,FEC) (This)->lpVtbl->put_OuterFECRate(This,FEC)
#define IDVBTLocator2_put_SymbolRate(This,Rate) (This)->lpVtbl->put_SymbolRate(This,Rate)
#define IDVBTLocator2_get_Bandwidth(This,pBandWidthVal) (This)->lpVtbl->get_Bandwidth(This,pBandWidthVal)
#define IDVBTLocator2_get_Guard(This,pGI) (This)->lpVtbl->get_Guard(This,pGI)
#define IDVBTLocator2_get_HAlpha(This,pAlpha) (This)->lpVtbl->get_HAlpha(This,pAlpha)
#define IDVBTLocator2_get_LPInnerFEC(This,pFEC) (This)->lpVtbl->get_LPInnerFEC(This,pFEC)
#define IDVBTLocator2_get_LPInnerFECRate(This,pFEC) (This)->lpVtbl->get_LPInnerFECRate(This,pFEC)
#define IDVBTLocator2_get_Mode(This,pmode) (This)->lpVtbl->get_Mode(This,pmode)
#define IDVBTLocator2_get_OtherFrequencyInUse(This,pOtherFrequencyInUseVal) (This)->lpVtbl->get_OtherFrequencyInUse(This,pOtherFrequencyInUseVal)
#define IDVBTLocator2_put_Bandwidth(This,BandwidthVal) (This)->lpVtbl->put_Bandwidth(This,BandwidthVal)
#define IDVBTLocator2_put_Guard(This,GI) (This)->lpVtbl->put_Guard(This,GI)
#define IDVBTLocator2_put_HAlpha(This,Alpha) (This)->lpVtbl->put_HAlpha(This,Alpha)
#define IDVBTLocator2_put_LPInnerFEC(This,FEC) (This)->lpVtbl->put_LPInnerFEC(This,FEC)
#define IDVBTLocator2_put_LPInnerFECRate(This,FEC) (This)->lpVtbl->put_LPInnerFECRate(This,FEC)
#define IDVBTLocator2_put_Mode(This,mode) (This)->lpVtbl->put_Mode(This,mode)
#define IDVBTLocator2_put_OtherFrequencyInUse(This,OtherFrequencyInUseVal) (This)->lpVtbl->put_OtherFrequencyInUse(This,OtherFrequencyInUseVal)
#define IDVBTLocator2_put_PhysicalLayerPipeId(This,PhysicalLayerPipeIdVal) (This)->lpVtbl->put_PhysicalLayerPipeId(This,PhysicalLayerPipeIdVal)
#define IDVBTLocator2_get_PhysicalLayerPipeId(This,PhysicalLayerPipeIdVal) (This)->lpVtbl->get_PhysicalLayerPipeId(This,PhysicalLayerPipeIdVal)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IComponents
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IComponents,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* IComponents methods */
    STDMETHOD_(HRESULT,Add)(THIS_ IComponent *pComponent,VARIANT *pNewIndex) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IComponents **ppNewList) PURE;
    STDMETHOD_(HRESULT,EnumComponents)(THIS_ IEnumComponents **ppNewEnum) PURE;
    STDMETHOD_(HRESULT,get__NewEnum)(THIS_ IEnumVARIANT **ppNewEnum) PURE;
    STDMETHOD_(HRESULT,get_Count)(THIS_ __LONG32 *pCount) PURE;
    STDMETHOD_(HRESULT,get_Item)(THIS_ VARIANT Index,IComponent **ppComponent) PURE;
    STDMETHOD_(HRESULT,put_Item)(THIS_ VARIANT Index,IComponentType *pComponentType) PURE;
    STDMETHOD_(HRESULT,Remove)(THIS_ VARIANT Index) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IComponents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IComponents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IComponents_Release(This) (This)->lpVtbl->Release(This)
#define IComponents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IComponents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IComponents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IComponents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IComponents_Clone(This,ppNewList) (This)->lpVtbl->Clone(This,ppNewList)
#define IComponents_EnumComponents(This,ppNewEnum) (This)->lpVtbl->EnumComponents(This,ppNewEnum)
#define IComponents_get__NewEnum(This,ppNewEnum) (This)->lpVtbl->get__NewEnum(This,ppNewEnum)
#define IComponents_get_Count(This,pCount) (This)->lpVtbl->get_Count(This,pCount)
#define IComponents_get_Item(This,Index,ppComponent) (This)->lpVtbl->get_Item(This,Index,ppComponent)
#define IComponents_put_Item(This,Index,pComponentType) (This)->lpVtbl->put_Item(This,Index,pComponentType)
#define IComponents_Remove(This,Index) (This)->lpVtbl->Remove(This,Index)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IEnumComponents
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IEnumComponents,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IEnumComponents methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ IEnumComponents **ppEnum) PURE;
    STDMETHOD_(HRESULT,Next)(THIS_ ULONG celt,IComponent **pprgelt,ULONG *pceltFetched) PURE;
    STDMETHOD_(HRESULT,Reset)(THIS) PURE;
    STDMETHOD_(HRESULT,Skip)(THIS_ ULONG celt) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IEnumComponents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumComponents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumComponents_Release(This) (This)->lpVtbl->Release(This)
#define IEnumComponents_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#define IEnumComponents_Next(This,celt,pprgelt,pceltFetched) (This)->lpVtbl->Next(This,celt,pprgelt,pceltFetched)
#define IEnumComponents_Reset() (This)->lpVtbl->Reset(This)
#define IEnumComponents_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IComponent
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IComponent,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* IComponent methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ IComponent **ppNewComponent) PURE;
    STDMETHOD_(HRESULT,get_DescLangID)(THIS_ __LONG32 *pLangID) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *pDescription) PURE;
    STDMETHOD_(HRESULT,get_Status)(THIS_ ComponentStatus *pStatus) PURE;
    STDMETHOD_(HRESULT,get_Type)(THIS_ IComponentType **ppCT) PURE;
    STDMETHOD_(HRESULT,put_DescLangID)(THIS_ __LONG32 LangID) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR Description) PURE;
    STDMETHOD_(HRESULT,put_Status)(THIS_ ComponentStatus Status) PURE;
    STDMETHOD_(HRESULT,put_Type)(THIS_ IComponentType *pCT) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IComponent_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IComponent_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IComponent_Release(This) (This)->lpVtbl->Release(This)
#define IComponent_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IComponent_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IComponent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IComponent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IComponent_Clone(This,ppNewComponent) (This)->lpVtbl->Clone(This,ppNewComponent)
#define IComponent_get_DescLangID(This,pLangID) (This)->lpVtbl->get_DescLangID(This,pLangID)
#define IComponent_get_Description(This,pDescription) (This)->lpVtbl->get_Description(This,pDescription)
#define IComponent_get_Status(This,pStatus) (This)->lpVtbl->get_Status(This,pStatus)
#define IComponent_get_Type(This,ppCT) (This)->lpVtbl->get_Type(This,ppCT)
#define IComponent_put_DescLangID(This,LangID) (This)->lpVtbl->put_DescLangID(This,LangID)
#define IComponent_put_Description(This,Description) (This)->lpVtbl->put_Description(This,Description)
#define IComponent_put_Status(This,Status) (This)->lpVtbl->put_Status(This,Status)
#define IComponent_put_Type(This,pCT) (This)->lpVtbl->put_Type(This,pCT)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IMPEG2Component
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IMPEG2Component,IComponent)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* IComponent methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ IComponent **ppNewComponent) PURE;
    STDMETHOD_(HRESULT,get_DescLangID)(THIS_ __LONG32 *pLangID) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *pDescription) PURE;
    STDMETHOD_(HRESULT,get_Status)(THIS_ ComponentStatus *pStatus) PURE;
    STDMETHOD_(HRESULT,get_Type)(THIS_ IComponentType **ppCT) PURE;
    STDMETHOD_(HRESULT,put_DescLangID)(THIS_ __LONG32 LangID) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR Description) PURE;
    STDMETHOD_(HRESULT,put_Status)(THIS_ ComponentStatus Status) PURE;
    STDMETHOD_(HRESULT,put_Type)(THIS_ IComponentType *pCT) PURE;

    /* IMPEG2Component methods */
    STDMETHOD_(HRESULT,get_PID)(THIS_ __LONG32 *pPID) PURE;
    STDMETHOD_(HRESULT,get_ProgramNumber)(THIS_ __LONG32 *pProgramNumber) PURE;
    STDMETHOD_(HRESULT,put_PCRPID)(THIS_ __LONG32 PCRPID) PURE;
    STDMETHOD_(HRESULT,put_PID)(THIS_ __LONG32 PID) PURE;
    STDMETHOD_(HRESULT,put_ProgramNumber)(THIS_ __LONG32 ProgramNumber) PURE;
    STDMETHOD_(HRESULT,get_PCRPID)(THIS_ __LONG32 *pPCRPID) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IMPEG2Component_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMPEG2Component_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMPEG2Component_Release(This) (This)->lpVtbl->Release(This)
#define IMPEG2Component_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IMPEG2Component_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IMPEG2Component_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IMPEG2Component_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IMPEG2Component_Clone(This,ppNewComponent) (This)->lpVtbl->Clone(This,ppNewComponent)
#define IMPEG2Component_get_DescLangID(This,pLangID) (This)->lpVtbl->get_DescLangID(This,pLangID)
#define IMPEG2Component_get_Description(This,pDescription) (This)->lpVtbl->get_Description(This,pDescription)
#define IMPEG2Component_get_Status(This,pStatus) (This)->lpVtbl->get_Status(This,pStatus)
#define IMPEG2Component_get_Type(This,ppCT) (This)->lpVtbl->get_Type(This,ppCT)
#define IMPEG2Component_put_DescLangID(This,LangID) (This)->lpVtbl->put_DescLangID(This,LangID)
#define IMPEG2Component_put_Description(This,Description) (This)->lpVtbl->put_Description(This,Description)
#define IMPEG2Component_put_Status(This,Status) (This)->lpVtbl->put_Status(This,Status)
#define IMPEG2Component_put_Type(This,pCT) (This)->lpVtbl->put_Type(This,pCT)
#define IMPEG2Component_get_PID(This,pPID) (This)->lpVtbl->get_PID(This,pPID)
#define IMPEG2Component_get_ProgramNumber(This,pProgramNumber) (This)->lpVtbl->get_ProgramNumber(This,pProgramNumber)
#define IMPEG2Component_put_PCRPID(This,PCRPID) (This)->lpVtbl->put_PCRPID(This,PCRPID)
#define IMPEG2Component_put_PID(This,PID) (This)->lpVtbl->put_PID(This,PID)
#define IMPEG2Component_put_ProgramNumber(This,ProgramNumber) (This)->lpVtbl->put_ProgramNumber(This,ProgramNumber)
#define IMPEG2Component_get_PCRPID(This,pPCRPID) (This)->lpVtbl->get_PCRPID(This,pPCRPID)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE ITuningSpace
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(ITuningSpace,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* ITuningSpace methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ ITuningSpace **ppNewTS) PURE;
    STDMETHOD_(HRESULT,CreateTuneRequest)(THIS_ ITuneRequest **ppTuneRequest) PURE;
    STDMETHOD_(HRESULT,EnumCategoryGUIDs)(THIS_ IEnumGUID **ppEnum) PURE;
    STDMETHOD_(HRESULT,EnumDeviceMonikers)(THIS_ IEnumMoniker **ppEnum) PURE;
    STDMETHOD_(HRESULT,get__NetworkType)(THIS_ GUID *pNetworkTypeGuid) PURE;
    STDMETHOD_(HRESULT,get_CLSID)(THIS_ BSTR *pSpaceCLSID) PURE;
    STDMETHOD_(HRESULT,get_DefaultLocator)(THIS_ ILocator **ppLocatorVal) PURE;
    STDMETHOD_(HRESULT,get_DefaultPreferredComponentTypes)(THIS_ IComponentTypes **ppComponentTypes) PURE;
    STDMETHOD_(HRESULT,get_FrequencyMapping)(THIS_ BSTR *pMapping) PURE;
    STDMETHOD_(HRESULT,get_FriendlyName)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,get_NetworkType)(THIS_ BSTR *pNetworkTypeGuid) PURE;
    STDMETHOD_(HRESULT,get_UniqueName)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,put__NetworkType)(THIS_ REFCLSID NetworkTypeGuid) PURE;
    STDMETHOD_(HRESULT,put_DefaultLocator)(THIS_ ILocator *pLocatorVal) PURE;
    STDMETHOD_(HRESULT,put_DefaultPreferredComponentTypes)(THIS_ IComponentTypes *pNewComponentTypes) PURE;
    STDMETHOD_(HRESULT,put_FrequencyMapping)(THIS_ BSTR Mapping) PURE;
    STDMETHOD_(HRESULT,put_FriendlyName)(THIS_ BSTR Name) PURE;
    STDMETHOD_(HRESULT,put_NetworkType)(THIS_ BSTR NetworkTypeGuid) PURE;
    STDMETHOD_(HRESULT,put_UniqueName)(THIS_ BSTR Name) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define ITuningSpace_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITuningSpace_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITuningSpace_Release(This) (This)->lpVtbl->Release(This)
#define ITuningSpace_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ITuningSpace_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ITuningSpace_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ITuningSpace_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ITuningSpace_Clone(This,ppNewTS) (This)->lpVtbl->Clone(This,ppNewTS)
#define ITuningSpace_CreateTuneRequest(This,ppTuneRequest) (This)->lpVtbl->CreateTuneRequest(This,ppTuneRequest)
#define ITuningSpace_EnumCategoryGUIDs(This,ppEnum) (This)->lpVtbl->EnumCategoryGUIDs(This,ppEnum)
#define ITuningSpace_EnumDeviceMonikers(This,ppEnum) (This)->lpVtbl->EnumDeviceMonikers(This,ppEnum)
#define ITuningSpace_get__NetworkType(This,pNetworkTypeGuid) (This)->lpVtbl->get__NetworkType(This,pNetworkTypeGuid)
#define ITuningSpace_get_CLSID(This,pSpaceCLSID) (This)->lpVtbl->get_CLSID(This,pSpaceCLSID)
#define ITuningSpace_get_DefaultLocator(This,ppLocatorVal) (This)->lpVtbl->get_DefaultLocator(This,ppLocatorVal)
#define ITuningSpace_get_DefaultPreferredComponentTypes(This,ppComponentTypes) (This)->lpVtbl->get_DefaultPreferredComponentTypes(This,ppComponentTypes)
#define ITuningSpace_get_FrequencyMapping(This,pMapping) (This)->lpVtbl->get_FrequencyMapping(This,pMapping)
#define ITuningSpace_get_FriendlyName(This,pName) (This)->lpVtbl->get_FriendlyName(This,pName)
#define ITuningSpace_get_NetworkType(This,pNetworkTypeGuid) (This)->lpVtbl->get_NetworkType(This,pNetworkTypeGuid)
#define ITuningSpace_get_UniqueName(This,pName) (This)->lpVtbl->get_UniqueName(This,pName)
#define ITuningSpace_put__NetworkType(This,NetworkTypeGuid) (This)->lpVtbl->put__NetworkType(This,NetworkTypeGuid)
#define ITuningSpace_put_DefaultLocator(This,pLocatorVal) (This)->lpVtbl->put_DefaultLocator(This,pLocatorVal)
#define ITuningSpace_put_DefaultPreferredComponentTypes(This,pNewComponentTypes) (This)->lpVtbl->put_DefaultPreferredComponentTypes(This,pNewComponentTypes)
#define ITuningSpace_put_FrequencyMapping(This,Mapping) (This)->lpVtbl->put_FrequencyMapping(This,Mapping)
#define ITuningSpace_put_FriendlyName(This,Name) (This)->lpVtbl->put_FriendlyName(This,Name)
#define ITuningSpace_put_NetworkType(This,NetworkTypeGuid) (This)->lpVtbl->put_NetworkType(This,NetworkTypeGuid)
#define ITuningSpace_put_UniqueName(This,Name) (This)->lpVtbl->put_UniqueName(This,Name)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IComponentTypes
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IComponentTypes,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* IComponentTypes methods */
    STDMETHOD_(HRESULT,Add)(THIS_ IComponentType *pComponentType,VARIANT *pNewIndex) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IComponentTypes **ppNewList) PURE;
    STDMETHOD_(HRESULT,EnumComponentTypes)(THIS_ IEnumComponentTypes **ppNewEnum) PURE;
    STDMETHOD_(HRESULT,get__NewEnum)(THIS_ IEnumVARIANT **ppNewEnum) PURE;
    STDMETHOD_(HRESULT,get_Count)(THIS_ __LONG32 *pCount) PURE;
    STDMETHOD_(HRESULT,get_Item)(THIS_ VARIANT Index,IComponentType **ppComponentType) PURE;
    STDMETHOD_(HRESULT,Remove)(THIS_ VARIANT Index) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IComponentTypes_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IComponentTypes_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IComponentTypes_Release(This) (This)->lpVtbl->Release(This)
#define IComponentTypes_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IComponentTypes_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IComponentTypes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IComponentTypes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IComponentTypes_Add(This,pComponentType,pNewIndex) (This)->lpVtbl->Add(This,pComponentType,pNewIndex)
#define IComponentTypes_Clone(This,ppNewList) (This)->lpVtbl->Clone(This,ppNewList)
#define IComponentTypes_EnumComponentTypes(This,ppNewEnum) (This)->lpVtbl->EnumComponentTypes(This,ppNewEnum)
#define IComponentTypes_get__NewEnum(This,ppNewEnum) (This)->lpVtbl->get__NewEnum(This,ppNewEnum)
#define IComponentTypes_get_Count(This,pCount) (This)->lpVtbl->get_Count(This,pCount)
#define IComponentTypes_get_Item(This,Index,ppComponentType) (This)->lpVtbl->get_Item(This,Index,ppComponentType)
#define IComponentTypes_Remove(This,Index) (This)->lpVtbl->Remove(This,Index)
#endif /*COBJMACROS*/

/* Fixme: Double underscored ,methods are C++ only */
#undef  INTERFACE
#define INTERFACE IComponentType
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IComponentType,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ UINT *pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr) PURE;

    /* IComponentType methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ IComponentType **ppNewCT) PURE;
    STDMETHOD_(HRESULT,get__MediaFormatType)(THIS_ GUID *pMediaFormatType) PURE;
    STDMETHOD_(HRESULT,get__MediaMajorType)(THIS_ GUID *MediaMajorType) PURE;
    STDMETHOD_(HRESULT,get__MediaSubType)(THIS_ GUID *pMediaSubType) PURE;
    STDMETHOD_(HRESULT,get_Category)(THIS_ ComponentCategory *pCategory) PURE;
    STDMETHOD_(HRESULT,get_MediaFormatType)(THIS_ BSTR *pMediaFormatType) PURE;
    STDMETHOD_(HRESULT,get_MediaMajorType)(THIS_ BSTR *pMediaMajorType) PURE;
    STDMETHOD_(HRESULT,get_MediaSubType)(THIS_ BSTR *pMediaSubType) PURE;
    STDMETHOD_(HRESULT,get_MediaType)(THIS_ AM_MEDIA_TYPE *pMediaType) PURE;
    STDMETHOD_(HRESULT,put__MediaFormatType)(THIS_ REFCLSID MediaFormatType) PURE;
    STDMETHOD_(HRESULT,put__MediaMajorType)(THIS_ REFCLSID MediaMajorType) PURE;
    STDMETHOD_(HRESULT,put__MediaSubType)(THIS_ REFCLSID MediaSubType) PURE;
    STDMETHOD_(HRESULT,put_Category)(THIS_ ComponentCategory Category) PURE;
    STDMETHOD_(HRESULT,put_MediaFormatType)(THIS_ BSTR MediaFormatType) PURE;
    STDMETHOD_(HRESULT,put_MediaMajorType)(THIS_ BSTR MediaMajorType) PURE;
    STDMETHOD_(HRESULT,put_MediaSubType)(THIS_ BSTR MediaSubType) PURE;
    STDMETHOD_(HRESULT,put_MediaType)(THIS_ AM_MEDIA_TYPE MediaType) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IComponentType_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IComponentType_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IComponentType_Release(This) (This)->lpVtbl->Release(This)
#define IComponentType_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IComponentType_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IComponentType_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IComponentType_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IComponentType_Clone(This,ppNewCT) (This)->lpVtbl->Clone(This,ppNewCT)
#define IComponentType_get__MediaFormatType(This,pMediaFormatType) (This)->lpVtbl->get__MediaFormatType(This,pMediaFormatType)
#define IComponentType_get__MediaMajorType(This,MediaMajorType) (This)->lpVtbl->get__MediaMajorType(This,MediaMajorType)
#define IComponentType_get__MediaSubType(This,pMediaSubType) (This)->lpVtbl->get__MediaSubType(This,pMediaSubType)
#define IComponentType_get_Category(This,pCategory) (This)->lpVtbl->get_Category(This,pCategory)
#define IComponentType_get_MediaFormatType(This,pMediaFormatType) (This)->lpVtbl->get_MediaFormatType(This,pMediaFormatType)
#define IComponentType_get_MediaMajorType(This,pMediaMajorType) (This)->lpVtbl->get_MediaMajorType(This,pMediaMajorType)
#define IComponentType_get_MediaSubType(This,pMediaSubType) (This)->lpVtbl->get_MediaSubType(This,pMediaSubType)
#define IComponentType_get_MediaType(This,pMediaType) (This)->lpVtbl->get_MediaType(This,pMediaType)
#define IComponentType_put__MediaFormatType(This,MediaFormatType) (This)->lpVtbl->put__MediaFormatType(This,MediaFormatType)
#define IComponentType_put__MediaMajorType(This,MediaMajorType) (This)->lpVtbl->put__MediaMajorType(This,MediaMajorType)
#define IComponentType_put__MediaSubType(This,MediaSubType) (This)->lpVtbl->put__MediaSubType(This,MediaSubType)
#define IComponentType_put_Category(This,Category) (This)->lpVtbl->put_Category(This,Category)
#define IComponentType_put_MediaFormatType(This,MediaFormatType) (This)->lpVtbl->put_MediaFormatType(This,MediaFormatType)
#define IComponentType_put_MediaMajorType(This,MediaMajorType) (This)->lpVtbl->put_MediaMajorType(This,MediaMajorType)
#define IComponentType_put_MediaSubType(This,MediaSubType) (This)->lpVtbl->put_MediaSubType(This,MediaSubType)
#define IComponentType_put_MediaType(This,MediaType) (This)->lpVtbl->put_MediaType(This,MediaType)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IEnumComponentTypes
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IEnumComponentTypes,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IEnumComponentTypes methods */
    STDMETHOD_(HRESULT,Clone)(THIS_ IEnumComponentTypes **ppEnum) PURE;
    STDMETHOD_(HRESULT,Next)(THIS_ ULONG celt,IComponentType **pprgelt,ULONG *pceltFetched) PURE;
    STDMETHOD_(HRESULT,Reset)(THIS) PURE;
    STDMETHOD_(HRESULT,Skip)(THIS_ ULONG celt) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IEnumComponentTypes_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumComponentTypes_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumComponentTypes_Release(This) (This)->lpVtbl->Release(This)
#define IEnumComponentTypes_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#define IEnumComponentTypes_Next(This,celt,pprgelt,pceltFetched) (This)->lpVtbl->Next(This,celt,pprgelt,pceltFetched)
#define IEnumComponentTypes_Reset() (This)->lpVtbl->Reset(This)
#define IEnumComponentTypes_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#endif /*COBJMACROS*/

#endif /*__INC_TUNER__*/
