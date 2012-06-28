/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_WSDXML
#define _INC_WSDXML

#ifndef _INC_WSDAPI
#error Please include wsdapi.h instead of this header. This header cannot be used directly.
#endif

#if (_WIN32_WINNT >= 0x0600)

#undef  INTERFACE
#define INTERFACE IWSDXMLContext
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IWSDXMLContext,IUnknown)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IWSDXMLContext methods */
    STDMETHOD_(HRESULT,SetNamespaces)(THIS_ const PCWSDXML_NAMESPACE *pNamespaces,WORD wNamespacesCount,BYTE bLayerNumber) PURE;
    STDMETHOD_(HRESULT,SetTypes)(THIS_ const PCWSDXML_TYPE *pTypes,DWORD dwTypesCount,BYTE bLayerNumber) PURE;
    STDMETHOD_(HRESULT,AddNamespace)(THIS_ const LPCWSTR *pszUri,const LPCWSTR *pszSuggestedPrefix,WSDXML_NAMESPACE **ppNamespace) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IWSDXMLContext_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWSDXMLContext_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWSDXMLContext_Release(This) (This)->lpVtbl->Release(This)
#define IWSDXMLContext_SetNamespaces(This,pNamespaces,wNamespacesCount,bLayerNumber) (This)->lpVtbl->SetNamespaces(This,pNamespaces,wNamespacesCount,bLayerNumber)
#define IWSDXMLContext_SetTypes(This,pTypes,dwTypesCount,bLayerNumber) (This)->lpVtbl->SetTypes(This,pTypes,dwTypesCount,bLayerNumber)
#define IWSDXMLContext_AddNamespace(This,pszUri,pszSuggestedPrefix,ppNamespace) (This)->lpVtbl->AddNamespace(This,pszUri,pszSuggestedPrefix,ppNamespace)
#endif /*COBJMACROS*/

/* In WsdXml.idl
HRESULT WINAPI WSDXMLCreateContext(
  __out  IWSDXMLContext **ppContext
);

HRESULT WINAPI WSDXMLGetNameFromBuiltinNamespace(
    LPCWSTR pszNamespace,
    LPCWSTR pszName,
    WSDXML_NAME **ppName
);

*/

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_WSDXML*/
