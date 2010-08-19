/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_PROPSYS
#define _INC_PROPSYS
#if (_WIN32_WINNT >= 0x0600)
#include <wtypes.h>
#include <propidl.h>
typedef PROPVARIANT *REFPROPVARIANT;
typedef PROPERTYKEY *REFPROPERTYKEY;

#undef  INTERFACE
#define INTERFACE IPropertyStore
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IPropertyStore,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IPropertyStore methods */
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;
    STDMETHOD_(HRESULT,GetAt)(THIS_ DWORD iProp,PROPERTYKEY *pkey) PURE;
    STDMETHOD_(HRESULT,GetCount)(THIS_ DWORD *cProps) PURE;
    STDMETHOD_(HRESULT,GetValue)(THIS_ REFPROPERTYKEY key,PROPVARIANT *pv) PURE;
    STDMETHOD_(HRESULT,SetValue)(THIS_ REFPROPERTYKEY key,REFPROPVARIANT propvar) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IPropertyStore_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define IPropertyStore_AddRef(This) (This)->pVtbl->AddRef(This)
#define IPropertyStore_Release(This) (This)->pVtbl->Release(This)
#define IPropertyStore_Commit() (This)->lpVtbl->Commit(This)
#define IPropertyStore_GetAt(This,iProp,pkey) (This)->lpVtbl->GetAt(This,iProp,pkey)
#define IPropertyStore_GetCount(This,cProps) (This)->lpVtbl->GetCount(This,cProps)
#define IPropertyStore_GetValue(This,key,pv) (This)->lpVtbl->GetValue(This,key,pv)
#define IPropertyStore_SetValue(This,key,propvar) (This)->lpVtbl->SetValue(This,key,propvar)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE INamedPropertyStore
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(INamedPropertyStore,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* INamedPropertyStore methods */
    STDMETHOD_(HRESULT,GetNameAt)(THIS_ DWORD iProp,BSTR *pbstrName) PURE;
    STDMETHOD_(HRESULT,GetNameCount)(THIS_ DWORD *pdwCount) PURE;
    STDMETHOD_(HRESULT,GetNamedValue)(THIS_ LPCWSTR pszName,PROPVARIANT *pv) PURE;
    STDMETHOD_(HRESULT,SetNamedValue)(THIS_ LPCWSTR pszName,const PROPVARIANT *pv) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define INamedPropertyStore_QueryInterface(This,riid,ppvObject) (This)->pVtbl->QueryInterface(This,riid,ppvObject)
#define INamedPropertyStore_AddRef(This) (This)->pVtbl->AddRef(This)
#define INamedPropertyStore_Release(This) (This)->pVtbl->Release(This)
#define INamedPropertyStore_GetNameAt(This,iProp,pbstrName) (This)->lpVtbl->GetNameAt(This,iProp,pbstrName)
#define INamedPropertyStore_GetNameCount(This,pdwCount) (This)->lpVtbl->GetNameCount(This,pdwCount)
#define INamedPropertyStore_GetNamedValue(This,pszName,pv) (This)->lpVtbl->GetNamedValue(This,pszName,pv)
#define INamedPropertyStore_SetNamedValue(This,pszName,pv) (This)->lpVtbl->SetNamedValue(This,pszName,pv)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_PROPSYS*/
