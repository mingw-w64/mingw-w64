/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __dbgprop_h__
#define __dbgprop_h__

#ifndef __IDebugProperty_FWD_DEFINED__
#define __IDebugProperty_FWD_DEFINED__
typedef struct IDebugProperty IDebugProperty;
#endif

#ifndef __IEnumDebugPropertyInfo_FWD_DEFINED__
#define __IEnumDebugPropertyInfo_FWD_DEFINED__
typedef struct IEnumDebugPropertyInfo IEnumDebugPropertyInfo;
#endif

#ifndef __IDebugExtendedProperty_FWD_DEFINED__
#define __IDebugExtendedProperty_FWD_DEFINED__
typedef struct IDebugExtendedProperty IDebugExtendedProperty;
#endif

#ifndef __IEnumDebugExtendedPropertyInfo_FWD_DEFINED__
#define __IEnumDebugExtendedPropertyInfo_FWD_DEFINED__
typedef struct IEnumDebugExtendedPropertyInfo IEnumDebugExtendedPropertyInfo;
#endif

#ifndef __IPerPropertyBrowsing2_FWD_DEFINED__
#define __IPerPropertyBrowsing2_FWD_DEFINED__
typedef struct IPerPropertyBrowsing2 IPerPropertyBrowsing2;
#endif

#ifndef __IDebugPropertyEnumType_All_FWD_DEFINED__
#define __IDebugPropertyEnumType_All_FWD_DEFINED__
typedef struct IDebugPropertyEnumType_All IDebugPropertyEnumType_All;
#endif

#ifndef __IDebugPropertyEnumType_Locals_FWD_DEFINED__
#define __IDebugPropertyEnumType_Locals_FWD_DEFINED__
typedef struct IDebugPropertyEnumType_Locals IDebugPropertyEnumType_Locals;
#endif

#ifndef __IDebugPropertyEnumType_Arguments_FWD_DEFINED__
#define __IDebugPropertyEnumType_Arguments_FWD_DEFINED__
typedef struct IDebugPropertyEnumType_Arguments IDebugPropertyEnumType_Arguments;
#endif

#ifndef __IDebugPropertyEnumType_LocalsPlusArgs_FWD_DEFINED__
#define __IDebugPropertyEnumType_LocalsPlusArgs_FWD_DEFINED__
typedef struct IDebugPropertyEnumType_LocalsPlusArgs IDebugPropertyEnumType_LocalsPlusArgs;
#endif

#ifndef __IDebugPropertyEnumType_Registers_FWD_DEFINED__
#define __IDebugPropertyEnumType_Registers_FWD_DEFINED__
typedef struct IDebugPropertyEnumType_Registers IDebugPropertyEnumType_Registers;
#endif

#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

  typedef enum tagOBJECT_ATTRIB_FLAG {
    OBJECT_ATTRIB_NO_ATTRIB = 0,OBJECT_ATTRIB_NO_NAME = 0x1,OBJECT_ATTRIB_NO_TYPE = 0x2,OBJECT_ATTRIB_NO_VALUE = 0x4,
    OBJECT_ATTRIB_VALUE_IS_INVALID = 0x8,OBJECT_ATTRIB_VALUE_IS_OBJECT = 0x10,OBJECT_ATTRIB_VALUE_IS_ENUM = 0x20,
    OBJECT_ATTRIB_VALUE_IS_CUSTOM = 0x40,OBJECT_ATTRIB_OBJECT_IS_EXPANDABLE = 0x70,OBJECT_ATTRIB_VALUE_HAS_CODE = 0x80,
    OBJECT_ATTRIB_TYPE_IS_OBJECT = 0x100,OBJECT_ATTRIB_TYPE_HAS_CODE = 0x200,OBJECT_ATTRIB_TYPE_IS_EXPANDABLE = 0x100,
    OBJECT_ATTRIB_SLOT_IS_CATEGORY = 0x400,OBJECT_ATTRIB_VALUE_READONLY = 0x800,OBJECT_ATTRIB_ACCESS_PUBLIC = 0x1000,
    OBJECT_ATTRIB_ACCESS_PRIVATE = 0x2000,OBJECT_ATTRIB_ACCESS_PROTECTED = 0x4000,OBJECT_ATTRIB_ACCESS_FINAL = 0x8000,
    OBJECT_ATTRIB_STORAGE_GLOBAL = 0x10000,OBJECT_ATTRIB_STORAGE_STATIC = 0x20000,OBJECT_ATTRIB_STORAGE_FIELD = 0x40000,
    OBJECT_ATTRIB_STORAGE_VIRTUAL = 0x80000,OBJECT_ATTRIB_TYPE_IS_CONSTANT = 0x100000,OBJECT_ATTRIB_TYPE_IS_SYNCHRONIZED = 0x200000,
    OBJECT_ATTRIB_TYPE_IS_VOLATILE = 0x400000,OBJECT_ATTRIB_HAS_EXTENDED_ATTRIBS = 0x800000,OBJECT_ATTRIB_IS_CLASS = 0x1000000,
    OBJECT_ATTRIB_IS_FUNCTION = 0x2000000,OBJECT_ATTRIB_IS_VARIABLE = 0x4000000,OBJECT_ATTRIB_IS_PROPERTY = 0x8000000,
    OBJECT_ATTRIB_IS_MACRO = 0x10000000,OBJECT_ATTRIB_IS_TYPE = 0x20000000,OBJECT_ATTRIB_IS_INHERITED = 0x40000000,
    OBJECT_ATTRIB_IS_INTERFACE = 0x80000000
  } OBJECT_ATTRIB_FLAGS;

  typedef enum tagPROP_INFO_FLAGS {
    PROP_INFO_NAME = 0x1,PROP_INFO_TYPE = 0x2,PROP_INFO_VALUE = 0x4,PROP_INFO_FULLNAME = 0x20,PROP_INFO_ATTRIBUTES = 0x8,
    PROP_INFO_DEBUGPROP = 0x10,PROP_INFO_AUTOEXPAND = 0x8000000
  } PROP_INFO_FLAGS;

#define PROP_INFO_STANDARD (PROP_INFO_NAME | PROP_INFO_TYPE | PROP_INFO_VALUE | PROP_INFO_ATTRIBUTES)
#define PROP_INFO_ALL (PROP_INFO_NAME | PROP_INFO_TYPE | PROP_INFO_VALUE | PROP_INFO_FULLNAME | PROP_INFO_ATTRIBUTES | PROP_INFO_DEBUGPROP)

  typedef struct tagDebugPropertyInfo {
    DWORD m_dwValidFields;
    BSTR m_bstrName;
    BSTR m_bstrType;
    BSTR m_bstrValue;
    BSTR m_bstrFullName;
    DWORD m_dwAttrib;
    IDebugProperty *m_pDebugProp;
  } DebugPropertyInfo;

  typedef enum tagEX_PROP_INFO_FLAGS {
    EX_PROP_INFO_ID = 0x100,EX_PROP_INFO_NTYPE = 0x200,EX_PROP_INFO_NVALUE = 0x400,EX_PROP_INFO_LOCKBYTES = 0x800,
    EX_PROP_INFO_DEBUGEXTPROP = 0x1000
  } EX_PROP_INFO_FLAGS;

  typedef struct tagExtendedDebugPropertyInfo {
    DWORD dwValidFields;
    LPOLESTR pszName;
    LPOLESTR pszType;
    LPOLESTR pszValue;
    LPOLESTR pszFullName;
    DWORD dwAttrib;
    IDebugProperty *pDebugProp;
    DWORD nDISPID;
    DWORD nType;
    VARIANT varValue;
    ILockBytes *plbValue;
    IDebugExtendedProperty *pDebugExtProp;
  } ExtendedDebugPropertyInfo;

  extern RPC_IF_HANDLE __MIDL_itf_dbgprop_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_dbgprop_0000_v0_0_s_ifspec;

#ifndef __IDebugProperty_INTERFACE_DEFINED__
#define __IDebugProperty_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDebugProperty;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDebugProperty : public IUnknown {
  public:
    virtual HRESULT WINAPI GetPropertyInfo(DWORD dwFieldSpec,UINT nRadix,DebugPropertyInfo *pPropertyInfo) = 0;
    virtual HRESULT WINAPI GetExtendedInfo(ULONG cInfos,GUID *rgguidExtendedInfo,VARIANT *rgvar) = 0;
    virtual HRESULT WINAPI SetValueAsString(LPCOLESTR pszValue,UINT nRadix) = 0;
    virtual HRESULT WINAPI EnumMembers(DWORD dwFieldSpec,UINT nRadix,REFIID refiid,IEnumDebugPropertyInfo **ppepi) = 0;
    virtual HRESULT WINAPI GetParent(IDebugProperty **ppDebugProp) = 0;
  };
#else
  typedef struct IDebugPropertyVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDebugProperty *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDebugProperty *This);
      ULONG (WINAPI *Release)(IDebugProperty *This);
      HRESULT (WINAPI *GetPropertyInfo)(IDebugProperty *This,DWORD dwFieldSpec,UINT nRadix,DebugPropertyInfo *pPropertyInfo);
      HRESULT (WINAPI *GetExtendedInfo)(IDebugProperty *This,ULONG cInfos,GUID *rgguidExtendedInfo,VARIANT *rgvar);
      HRESULT (WINAPI *SetValueAsString)(IDebugProperty *This,LPCOLESTR pszValue,UINT nRadix);
      HRESULT (WINAPI *EnumMembers)(IDebugProperty *This,DWORD dwFieldSpec,UINT nRadix,REFIID refiid,IEnumDebugPropertyInfo **ppepi);
      HRESULT (WINAPI *GetParent)(IDebugProperty *This,IDebugProperty **ppDebugProp);
    END_INTERFACE
  } IDebugPropertyVtbl;
  struct IDebugProperty {
    CONST_VTBL struct IDebugPropertyVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDebugProperty_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDebugProperty_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDebugProperty_Release(This) (This)->lpVtbl->Release(This)
#define IDebugProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo) (This)->lpVtbl->GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)
#define IDebugProperty_GetExtendedInfo(This,cInfos,rgguidExtendedInfo,rgvar) (This)->lpVtbl->GetExtendedInfo(This,cInfos,rgguidExtendedInfo,rgvar)
#define IDebugProperty_SetValueAsString(This,pszValue,nRadix) (This)->lpVtbl->SetValueAsString(This,pszValue,nRadix)
#define IDebugProperty_EnumMembers(This,dwFieldSpec,nRadix,refiid,ppepi) (This)->lpVtbl->EnumMembers(This,dwFieldSpec,nRadix,refiid,ppepi)
#define IDebugProperty_GetParent(This,ppDebugProp) (This)->lpVtbl->GetParent(This,ppDebugProp)
#endif
#endif
  HRESULT WINAPI IDebugProperty_RemoteGetPropertyInfo_Proxy(IDebugProperty *This,DWORD dwFieldSpec,UINT nRadix,DWORD *dwValidFields,BSTR *pbstrName,BSTR *pbstrType,BSTR *pbstrValue,BSTR *pbstrFullName,DWORD *pdwAttrib,IDebugProperty **ppDebugProperty);
  void __RPC_STUB IDebugProperty_RemoteGetPropertyInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDebugProperty_GetExtendedInfo_Proxy(IDebugProperty *This,ULONG cInfos,GUID *rgguidExtendedInfo,VARIANT *rgvar);
  void __RPC_STUB IDebugProperty_GetExtendedInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDebugProperty_SetValueAsString_Proxy(IDebugProperty *This,LPCOLESTR pszValue,UINT nRadix);
  void __RPC_STUB IDebugProperty_SetValueAsString_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDebugProperty_EnumMembers_Proxy(IDebugProperty *This,DWORD dwFieldSpec,UINT nRadix,REFIID refiid,IEnumDebugPropertyInfo **ppepi);
  void __RPC_STUB IDebugProperty_EnumMembers_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDebugProperty_GetParent_Proxy(IDebugProperty *This,IDebugProperty **ppDebugProp);
  void __RPC_STUB IDebugProperty_GetParent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IEnumDebugPropertyInfo_INTERFACE_DEFINED__
#define __IEnumDebugPropertyInfo_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IEnumDebugPropertyInfo;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumDebugPropertyInfo : public IUnknown {
  public:
    virtual HRESULT WINAPI Next(ULONG celt,DebugPropertyInfo *pi,ULONG *pcEltsfetched) = 0;
    virtual HRESULT WINAPI Skip(ULONG celt) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Clone(IEnumDebugPropertyInfo **ppepi) = 0;
    virtual HRESULT WINAPI GetCount(ULONG *pcelt) = 0;
  };
#else
  typedef struct IEnumDebugPropertyInfoVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumDebugPropertyInfo *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumDebugPropertyInfo *This);
      ULONG (WINAPI *Release)(IEnumDebugPropertyInfo *This);
      HRESULT (WINAPI *Next)(IEnumDebugPropertyInfo *This,ULONG celt,DebugPropertyInfo *pi,ULONG *pcEltsfetched);
      HRESULT (WINAPI *Skip)(IEnumDebugPropertyInfo *This,ULONG celt);
      HRESULT (WINAPI *Reset)(IEnumDebugPropertyInfo *This);
      HRESULT (WINAPI *Clone)(IEnumDebugPropertyInfo *This,IEnumDebugPropertyInfo **ppepi);
      HRESULT (WINAPI *GetCount)(IEnumDebugPropertyInfo *This,ULONG *pcelt);
    END_INTERFACE
  } IEnumDebugPropertyInfoVtbl;
  struct IEnumDebugPropertyInfo {
    CONST_VTBL struct IEnumDebugPropertyInfoVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumDebugPropertyInfo_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumDebugPropertyInfo_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumDebugPropertyInfo_Release(This) (This)->lpVtbl->Release(This)
#define IEnumDebugPropertyInfo_Next(This,celt,pi,pcEltsfetched) (This)->lpVtbl->Next(This,celt,pi,pcEltsfetched)
#define IEnumDebugPropertyInfo_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#define IEnumDebugPropertyInfo_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumDebugPropertyInfo_Clone(This,ppepi) (This)->lpVtbl->Clone(This,ppepi)
#define IEnumDebugPropertyInfo_GetCount(This,pcelt) (This)->lpVtbl->GetCount(This,pcelt)
#endif
#endif
  HRESULT WINAPI IEnumDebugPropertyInfo_RemoteNext_Proxy(IEnumDebugPropertyInfo *This,ULONG celt,DebugPropertyInfo *pinfo,ULONG *pcEltsfetched);
  void __RPC_STUB IEnumDebugPropertyInfo_RemoteNext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumDebugPropertyInfo_Skip_Proxy(IEnumDebugPropertyInfo *This,ULONG celt);
  void __RPC_STUB IEnumDebugPropertyInfo_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumDebugPropertyInfo_Reset_Proxy(IEnumDebugPropertyInfo *This);
  void __RPC_STUB IEnumDebugPropertyInfo_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumDebugPropertyInfo_Clone_Proxy(IEnumDebugPropertyInfo *This,IEnumDebugPropertyInfo **ppepi);
  void __RPC_STUB IEnumDebugPropertyInfo_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumDebugPropertyInfo_GetCount_Proxy(IEnumDebugPropertyInfo *This,ULONG *pcelt);
  void __RPC_STUB IEnumDebugPropertyInfo_GetCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IDebugExtendedProperty_INTERFACE_DEFINED__
#define __IDebugExtendedProperty_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDebugExtendedProperty;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDebugExtendedProperty : public IDebugProperty {
  public:
    virtual HRESULT WINAPI GetExtendedPropertyInfo(DWORD dwFieldSpec,UINT nRadix,ExtendedDebugPropertyInfo *pExtendedPropertyInfo) = 0;
    virtual HRESULT WINAPI EnumExtendedMembers(DWORD dwFieldSpec,UINT nRadix,IEnumDebugExtendedPropertyInfo **ppeepi) = 0;
  };
#else
  typedef struct IDebugExtendedPropertyVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDebugExtendedProperty *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDebugExtendedProperty *This);
      ULONG (WINAPI *Release)(IDebugExtendedProperty *This);
      HRESULT (WINAPI *GetPropertyInfo)(IDebugExtendedProperty *This,DWORD dwFieldSpec,UINT nRadix,DebugPropertyInfo *pPropertyInfo);
      HRESULT (WINAPI *GetExtendedInfo)(IDebugExtendedProperty *This,ULONG cInfos,GUID *rgguidExtendedInfo,VARIANT *rgvar);
      HRESULT (WINAPI *SetValueAsString)(IDebugExtendedProperty *This,LPCOLESTR pszValue,UINT nRadix);
      HRESULT (WINAPI *EnumMembers)(IDebugExtendedProperty *This,DWORD dwFieldSpec,UINT nRadix,REFIID refiid,IEnumDebugPropertyInfo **ppepi);
      HRESULT (WINAPI *GetParent)(IDebugExtendedProperty *This,IDebugProperty **ppDebugProp);
      HRESULT (WINAPI *GetExtendedPropertyInfo)(IDebugExtendedProperty *This,DWORD dwFieldSpec,UINT nRadix,ExtendedDebugPropertyInfo *pExtendedPropertyInfo);
      HRESULT (WINAPI *EnumExtendedMembers)(IDebugExtendedProperty *This,DWORD dwFieldSpec,UINT nRadix,IEnumDebugExtendedPropertyInfo **ppeepi);
    END_INTERFACE
  } IDebugExtendedPropertyVtbl;
  struct IDebugExtendedProperty {
    CONST_VTBL struct IDebugExtendedPropertyVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDebugExtendedProperty_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDebugExtendedProperty_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDebugExtendedProperty_Release(This) (This)->lpVtbl->Release(This)
#define IDebugExtendedProperty_GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo) (This)->lpVtbl->GetPropertyInfo(This,dwFieldSpec,nRadix,pPropertyInfo)
#define IDebugExtendedProperty_GetExtendedInfo(This,cInfos,rgguidExtendedInfo,rgvar) (This)->lpVtbl->GetExtendedInfo(This,cInfos,rgguidExtendedInfo,rgvar)
#define IDebugExtendedProperty_SetValueAsString(This,pszValue,nRadix) (This)->lpVtbl->SetValueAsString(This,pszValue,nRadix)
#define IDebugExtendedProperty_EnumMembers(This,dwFieldSpec,nRadix,refiid,ppepi) (This)->lpVtbl->EnumMembers(This,dwFieldSpec,nRadix,refiid,ppepi)
#define IDebugExtendedProperty_GetParent(This,ppDebugProp) (This)->lpVtbl->GetParent(This,ppDebugProp)
#define IDebugExtendedProperty_GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo) (This)->lpVtbl->GetExtendedPropertyInfo(This,dwFieldSpec,nRadix,pExtendedPropertyInfo)
#define IDebugExtendedProperty_EnumExtendedMembers(This,dwFieldSpec,nRadix,ppeepi) (This)->lpVtbl->EnumExtendedMembers(This,dwFieldSpec,nRadix,ppeepi)
#endif
#endif
  HRESULT WINAPI IDebugExtendedProperty_GetExtendedPropertyInfo_Proxy(IDebugExtendedProperty *This,DWORD dwFieldSpec,UINT nRadix,ExtendedDebugPropertyInfo *pExtendedPropertyInfo);
  void __RPC_STUB IDebugExtendedProperty_GetExtendedPropertyInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDebugExtendedProperty_EnumExtendedMembers_Proxy(IDebugExtendedProperty *This,DWORD dwFieldSpec,UINT nRadix,IEnumDebugExtendedPropertyInfo **ppeepi);
  void __RPC_STUB IDebugExtendedProperty_EnumExtendedMembers_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED__
#define __IEnumDebugExtendedPropertyInfo_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IEnumDebugExtendedPropertyInfo;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumDebugExtendedPropertyInfo : public IUnknown {
  public:
    virtual HRESULT WINAPI Next(ULONG celt,ExtendedDebugPropertyInfo *rgExtendedPropertyInfo,ULONG *pceltFetched) = 0;
    virtual HRESULT WINAPI Skip(ULONG celt) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Clone(IEnumDebugExtendedPropertyInfo **pedpe) = 0;
    virtual HRESULT WINAPI GetCount(ULONG *pcelt) = 0;
  };
#else
  typedef struct IEnumDebugExtendedPropertyInfoVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumDebugExtendedPropertyInfo *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumDebugExtendedPropertyInfo *This);
      ULONG (WINAPI *Release)(IEnumDebugExtendedPropertyInfo *This);
      HRESULT (WINAPI *Next)(IEnumDebugExtendedPropertyInfo *This,ULONG celt,ExtendedDebugPropertyInfo *rgExtendedPropertyInfo,ULONG *pceltFetched);
      HRESULT (WINAPI *Skip)(IEnumDebugExtendedPropertyInfo *This,ULONG celt);
      HRESULT (WINAPI *Reset)(IEnumDebugExtendedPropertyInfo *This);
      HRESULT (WINAPI *Clone)(IEnumDebugExtendedPropertyInfo *This,IEnumDebugExtendedPropertyInfo **pedpe);
      HRESULT (WINAPI *GetCount)(IEnumDebugExtendedPropertyInfo *This,ULONG *pcelt);
    END_INTERFACE
  } IEnumDebugExtendedPropertyInfoVtbl;
  struct IEnumDebugExtendedPropertyInfo {
    CONST_VTBL struct IEnumDebugExtendedPropertyInfoVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumDebugExtendedPropertyInfo_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumDebugExtendedPropertyInfo_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumDebugExtendedPropertyInfo_Release(This) (This)->lpVtbl->Release(This)
#define IEnumDebugExtendedPropertyInfo_Next(This,celt,rgExtendedPropertyInfo,pceltFetched) (This)->lpVtbl->Next(This,celt,rgExtendedPropertyInfo,pceltFetched)
#define IEnumDebugExtendedPropertyInfo_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#define IEnumDebugExtendedPropertyInfo_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumDebugExtendedPropertyInfo_Clone(This,pedpe) (This)->lpVtbl->Clone(This,pedpe)
#define IEnumDebugExtendedPropertyInfo_GetCount(This,pcelt) (This)->lpVtbl->GetCount(This,pcelt)
#endif
#endif
  HRESULT WINAPI IEnumDebugExtendedPropertyInfo_Next_Proxy(IEnumDebugExtendedPropertyInfo *This,ULONG celt,ExtendedDebugPropertyInfo *rgExtendedPropertyInfo,ULONG *pceltFetched);
  void __RPC_STUB IEnumDebugExtendedPropertyInfo_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumDebugExtendedPropertyInfo_Skip_Proxy(IEnumDebugExtendedPropertyInfo *This,ULONG celt);
  void __RPC_STUB IEnumDebugExtendedPropertyInfo_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumDebugExtendedPropertyInfo_Reset_Proxy(IEnumDebugExtendedPropertyInfo *This);
  void __RPC_STUB IEnumDebugExtendedPropertyInfo_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumDebugExtendedPropertyInfo_Clone_Proxy(IEnumDebugExtendedPropertyInfo *This,IEnumDebugExtendedPropertyInfo **pedpe);
  void __RPC_STUB IEnumDebugExtendedPropertyInfo_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumDebugExtendedPropertyInfo_GetCount_Proxy(IEnumDebugExtendedPropertyInfo *This,ULONG *pcelt);
  void __RPC_STUB IEnumDebugExtendedPropertyInfo_GetCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IPerPropertyBrowsing2_INTERFACE_DEFINED__
#define __IPerPropertyBrowsing2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IPerPropertyBrowsing2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IPerPropertyBrowsing2 : public IUnknown {
  public:
    virtual HRESULT WINAPI GetDisplayString(DISPID dispid,BSTR *pBstr) = 0;
    virtual HRESULT WINAPI MapPropertyToPage(DISPID dispid,CLSID *pClsidPropPage) = 0;
    virtual HRESULT WINAPI GetPredefinedStrings(DISPID dispid,CALPOLESTR *pCaStrings,CADWORD *pCaCookies) = 0;
    virtual HRESULT WINAPI SetPredefinedValue(DISPID dispid,DWORD dwCookie) = 0;
  };
#else
  typedef struct IPerPropertyBrowsing2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IPerPropertyBrowsing2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IPerPropertyBrowsing2 *This);
      ULONG (WINAPI *Release)(IPerPropertyBrowsing2 *This);
      HRESULT (WINAPI *GetDisplayString)(IPerPropertyBrowsing2 *This,DISPID dispid,BSTR *pBstr);
      HRESULT (WINAPI *MapPropertyToPage)(IPerPropertyBrowsing2 *This,DISPID dispid,CLSID *pClsidPropPage);
      HRESULT (WINAPI *GetPredefinedStrings)(IPerPropertyBrowsing2 *This,DISPID dispid,CALPOLESTR *pCaStrings,CADWORD *pCaCookies);
      HRESULT (WINAPI *SetPredefinedValue)(IPerPropertyBrowsing2 *This,DISPID dispid,DWORD dwCookie);
    END_INTERFACE
  } IPerPropertyBrowsing2Vtbl;
  struct IPerPropertyBrowsing2 {
    CONST_VTBL struct IPerPropertyBrowsing2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IPerPropertyBrowsing2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPerPropertyBrowsing2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPerPropertyBrowsing2_Release(This) (This)->lpVtbl->Release(This)
#define IPerPropertyBrowsing2_GetDisplayString(This,dispid,pBstr) (This)->lpVtbl->GetDisplayString(This,dispid,pBstr)
#define IPerPropertyBrowsing2_MapPropertyToPage(This,dispid,pClsidPropPage) (This)->lpVtbl->MapPropertyToPage(This,dispid,pClsidPropPage)
#define IPerPropertyBrowsing2_GetPredefinedStrings(This,dispid,pCaStrings,pCaCookies) (This)->lpVtbl->GetPredefinedStrings(This,dispid,pCaStrings,pCaCookies)
#define IPerPropertyBrowsing2_SetPredefinedValue(This,dispid,dwCookie) (This)->lpVtbl->SetPredefinedValue(This,dispid,dwCookie)
#endif
#endif
  HRESULT WINAPI IPerPropertyBrowsing2_GetDisplayString_Proxy(IPerPropertyBrowsing2 *This,DISPID dispid,BSTR *pBstr);
  void __RPC_STUB IPerPropertyBrowsing2_GetDisplayString_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPerPropertyBrowsing2_MapPropertyToPage_Proxy(IPerPropertyBrowsing2 *This,DISPID dispid,CLSID *pClsidPropPage);
  void __RPC_STUB IPerPropertyBrowsing2_MapPropertyToPage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPerPropertyBrowsing2_GetPredefinedStrings_Proxy(IPerPropertyBrowsing2 *This,DISPID dispid,CALPOLESTR *pCaStrings,CADWORD *pCaCookies);
  void __RPC_STUB IPerPropertyBrowsing2_GetPredefinedStrings_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPerPropertyBrowsing2_SetPredefinedValue_Proxy(IPerPropertyBrowsing2 *This,DISPID dispid,DWORD dwCookie);
  void __RPC_STUB IPerPropertyBrowsing2_SetPredefinedValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IDebugPropertyEnumType_All_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_All_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDebugPropertyEnumType_All;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDebugPropertyEnumType_All : public IUnknown {
  public:
    virtual HRESULT WINAPI GetName(BSTR *__MIDL_0011) = 0;
  };
#else
  typedef struct IDebugPropertyEnumType_AllVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDebugPropertyEnumType_All *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDebugPropertyEnumType_All *This);
      ULONG (WINAPI *Release)(IDebugPropertyEnumType_All *This);
      HRESULT (WINAPI *GetName)(IDebugPropertyEnumType_All *This,BSTR *__MIDL_0011);
    END_INTERFACE
  } IDebugPropertyEnumType_AllVtbl;
  struct IDebugPropertyEnumType_All {
    CONST_VTBL struct IDebugPropertyEnumType_AllVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDebugPropertyEnumType_All_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDebugPropertyEnumType_All_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDebugPropertyEnumType_All_Release(This) (This)->lpVtbl->Release(This)
#define IDebugPropertyEnumType_All_GetName(This,__MIDL_0011) (This)->lpVtbl->GetName(This,__MIDL_0011)
#endif
#endif
  HRESULT WINAPI IDebugPropertyEnumType_All_GetName_Proxy(IDebugPropertyEnumType_All *This,BSTR *__MIDL_0011);
  void __RPC_STUB IDebugPropertyEnumType_All_GetName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IDebugPropertyEnumType_Locals_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_Locals_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDebugPropertyEnumType_Locals;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDebugPropertyEnumType_Locals : public IDebugPropertyEnumType_All {
  public:
  };
#else
  typedef struct IDebugPropertyEnumType_LocalsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDebugPropertyEnumType_Locals *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDebugPropertyEnumType_Locals *This);
      ULONG (WINAPI *Release)(IDebugPropertyEnumType_Locals *This);
      HRESULT (WINAPI *GetName)(IDebugPropertyEnumType_Locals *This,BSTR *__MIDL_0011);
    END_INTERFACE
  } IDebugPropertyEnumType_LocalsVtbl;
  struct IDebugPropertyEnumType_Locals {
    CONST_VTBL struct IDebugPropertyEnumType_LocalsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDebugPropertyEnumType_Locals_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDebugPropertyEnumType_Locals_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDebugPropertyEnumType_Locals_Release(This) (This)->lpVtbl->Release(This)
#define IDebugPropertyEnumType_Locals_GetName(This,__MIDL_0011) (This)->lpVtbl->GetName(This,__MIDL_0011)
#endif
#endif
#endif

#ifndef __IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_Arguments_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDebugPropertyEnumType_Arguments;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDebugPropertyEnumType_Arguments : public IDebugPropertyEnumType_All {
  public:
  };
#else
  typedef struct IDebugPropertyEnumType_ArgumentsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDebugPropertyEnumType_Arguments *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDebugPropertyEnumType_Arguments *This);
      ULONG (WINAPI *Release)(IDebugPropertyEnumType_Arguments *This);
      HRESULT (WINAPI *GetName)(IDebugPropertyEnumType_Arguments *This,BSTR *__MIDL_0011);
    END_INTERFACE
  } IDebugPropertyEnumType_ArgumentsVtbl;
  struct IDebugPropertyEnumType_Arguments {
    CONST_VTBL struct IDebugPropertyEnumType_ArgumentsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDebugPropertyEnumType_Arguments_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDebugPropertyEnumType_Arguments_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDebugPropertyEnumType_Arguments_Release(This) (This)->lpVtbl->Release(This)
#define IDebugPropertyEnumType_Arguments_GetName(This,__MIDL_0011) (This)->lpVtbl->GetName(This,__MIDL_0011)
#endif
#endif
#endif

#ifndef __IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_LocalsPlusArgs_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDebugPropertyEnumType_LocalsPlusArgs;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDebugPropertyEnumType_LocalsPlusArgs : public IDebugPropertyEnumType_All {
  public:
  };
#else
  typedef struct IDebugPropertyEnumType_LocalsPlusArgsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDebugPropertyEnumType_LocalsPlusArgs *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDebugPropertyEnumType_LocalsPlusArgs *This);
      ULONG (WINAPI *Release)(IDebugPropertyEnumType_LocalsPlusArgs *This);
      HRESULT (WINAPI *GetName)(IDebugPropertyEnumType_LocalsPlusArgs *This,BSTR *__MIDL_0011);
    END_INTERFACE
  } IDebugPropertyEnumType_LocalsPlusArgsVtbl;
  struct IDebugPropertyEnumType_LocalsPlusArgs {
    CONST_VTBL struct IDebugPropertyEnumType_LocalsPlusArgsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDebugPropertyEnumType_LocalsPlusArgs_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDebugPropertyEnumType_LocalsPlusArgs_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDebugPropertyEnumType_LocalsPlusArgs_Release(This) (This)->lpVtbl->Release(This)
#define IDebugPropertyEnumType_LocalsPlusArgs_GetName(This,__MIDL_0011) (This)->lpVtbl->GetName(This,__MIDL_0011)
#endif
#endif
#endif

#ifndef __IDebugPropertyEnumType_Registers_INTERFACE_DEFINED__
#define __IDebugPropertyEnumType_Registers_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDebugPropertyEnumType_Registers;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDebugPropertyEnumType_Registers : public IDebugPropertyEnumType_All {
  };
#else
  typedef struct IDebugPropertyEnumType_RegistersVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDebugPropertyEnumType_Registers *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDebugPropertyEnumType_Registers *This);
      ULONG (WINAPI *Release)(IDebugPropertyEnumType_Registers *This);
      HRESULT (WINAPI *GetName)(IDebugPropertyEnumType_Registers *This,BSTR *__MIDL_0011);
    END_INTERFACE
  } IDebugPropertyEnumType_RegistersVtbl;
  struct IDebugPropertyEnumType_Registers {
    CONST_VTBL struct IDebugPropertyEnumType_RegistersVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDebugPropertyEnumType_Registers_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDebugPropertyEnumType_Registers_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDebugPropertyEnumType_Registers_Release(This) (This)->lpVtbl->Release(This)
#define IDebugPropertyEnumType_Registers_GetName(This,__MIDL_0011) (This)->lpVtbl->GetName(This,__MIDL_0011)
#endif
#endif
#endif

  unsigned long __RPC_API BSTR_UserSize(unsigned long *,unsigned long,BSTR *);
  unsigned char *__RPC_API BSTR_UserMarshal(unsigned long *,unsigned char *,BSTR *);
  unsigned char *__RPC_API BSTR_UserUnmarshal(unsigned long *,unsigned char *,BSTR *);
  void __RPC_API BSTR_UserFree(unsigned long *,BSTR *);
  unsigned long __RPC_API VARIANT_UserSize(unsigned long *,unsigned long,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserMarshal(unsigned long *,unsigned char *,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserUnmarshal(unsigned long *,unsigned char *,VARIANT *);
  void __RPC_API VARIANT_UserFree(unsigned long *,VARIANT *);

  HRESULT WINAPI IDebugProperty_GetPropertyInfo_Proxy(IDebugProperty *This,DWORD dwFieldSpec,UINT nRadix,DebugPropertyInfo *pPropertyInfo);
  HRESULT WINAPI IDebugProperty_GetPropertyInfo_Stub(IDebugProperty *This,DWORD dwFieldSpec,UINT nRadix,DWORD *dwValidFields,BSTR *pbstrName,BSTR *pbstrType,BSTR *pbstrValue,BSTR *pbstrFullName,DWORD *pdwAttrib,IDebugProperty **ppDebugProperty);
  HRESULT WINAPI IEnumDebugPropertyInfo_Next_Proxy(IEnumDebugPropertyInfo *This,ULONG celt,DebugPropertyInfo *pi,ULONG *pcEltsfetched);
  HRESULT WINAPI IEnumDebugPropertyInfo_Next_Stub(IEnumDebugPropertyInfo *This,ULONG celt,DebugPropertyInfo *pinfo,ULONG *pcEltsfetched);

#ifdef __cplusplus
}
#endif
#endif
