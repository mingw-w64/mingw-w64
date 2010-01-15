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

#ifndef __adomd_h__
#define __adomd_h__

#ifndef __ICatalog_FWD_DEFINED__
#define __ICatalog_FWD_DEFINED__
typedef struct ICatalog ICatalog;
#endif

#ifndef __ICellset_FWD_DEFINED__
#define __ICellset_FWD_DEFINED__
typedef struct ICellset ICellset;
#endif

#ifndef __Cell_FWD_DEFINED__
#define __Cell_FWD_DEFINED__
typedef struct Cell Cell;
#endif

#ifndef __Axis_FWD_DEFINED__
#define __Axis_FWD_DEFINED__
typedef struct Axis Axis;
#endif

#ifndef __Position_FWD_DEFINED__
#define __Position_FWD_DEFINED__
typedef struct Position Position;
#endif

#ifndef __Member_FWD_DEFINED__
#define __Member_FWD_DEFINED__
typedef struct Member Member;
#endif

#ifndef __Level_FWD_DEFINED__
#define __Level_FWD_DEFINED__
typedef struct Level Level;
#endif

#ifndef __CubeDef25_FWD_DEFINED__
#define __CubeDef25_FWD_DEFINED__
typedef struct CubeDef25 CubeDef25;
#endif

#ifndef __CubeDef_FWD_DEFINED__
#define __CubeDef_FWD_DEFINED__
typedef struct CubeDef CubeDef;
#endif

#ifndef __Dimension_FWD_DEFINED__
#define __Dimension_FWD_DEFINED__
typedef struct Dimension Dimension;
#endif

#ifndef __Hierarchy_FWD_DEFINED__
#define __Hierarchy_FWD_DEFINED__
typedef struct Hierarchy Hierarchy;
#endif

#ifndef __MD_Collection_FWD_DEFINED__
#define __MD_Collection_FWD_DEFINED__
typedef struct MD_Collection MD_Collection;
#endif

#ifndef __Members_FWD_DEFINED__
#define __Members_FWD_DEFINED__
typedef struct Members Members;
#endif

#ifndef __Levels_FWD_DEFINED__
#define __Levels_FWD_DEFINED__
typedef struct Levels Levels;
#endif

#ifndef __Axes_FWD_DEFINED__
#define __Axes_FWD_DEFINED__
typedef struct Axes Axes;
#endif

#ifndef __Positions_FWD_DEFINED__
#define __Positions_FWD_DEFINED__
typedef struct Positions Positions;
#endif

#ifndef __Hierarchies_FWD_DEFINED__
#define __Hierarchies_FWD_DEFINED__
typedef struct Hierarchies Hierarchies;
#endif

#ifndef __Dimensions_FWD_DEFINED__
#define __Dimensions_FWD_DEFINED__
typedef struct Dimensions Dimensions;
#endif

#ifndef __CubeDefs_FWD_DEFINED__
#define __CubeDefs_FWD_DEFINED__
typedef struct CubeDefs CubeDefs;
#endif

#ifndef __Catalog_FWD_DEFINED__
#define __Catalog_FWD_DEFINED__

#ifdef __cplusplus
typedef class Catalog Catalog;
#else
typedef struct Catalog Catalog;
#endif
#endif

#ifndef __Cellset_FWD_DEFINED__
#define __Cellset_FWD_DEFINED__

#ifdef __cplusplus
typedef class Cellset Cellset;
#else
typedef struct Cellset Cellset;
#endif
#endif

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

  extern RPC_IF_HANDLE __MIDL_itf_adomd_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_adomd_0000_v0_0_s_ifspec;

#ifndef __ADOMD_LIBRARY_DEFINED__
#define __ADOMD_LIBRARY_DEFINED__

  typedef enum MemberTypeEnum {
    adMemberUnknown = 0,adMemberRegular = 0x1,adMemberAll = 0x2,adMemberMeasure = 0x3,adMemberFormula = 0x4
  } MemberTypeEnum;

  typedef enum SchemaObjectTypeEnum {
    adObjectTypeDimension = 1,adObjectTypeHierarchy = 2,adObjectTypeLevel = 3,adObjectTypeMember = 4
  } SchemaObjectTypeEnum;

  EXTERN_C const IID LIBID_ADOMD;

#ifndef __ICatalog_INTERFACE_DEFINED__
#define __ICatalog_INTERFACE_DEFINED__

  EXTERN_C const IID IID_ICatalog;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ICatalog : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI putref_ActiveConnection(IDispatch *pconn) = 0;
    virtual HRESULT WINAPI put_ActiveConnection(BSTR bstrConn) = 0;
    virtual HRESULT WINAPI get_ActiveConnection(IDispatch **ppConn) = 0;
    virtual HRESULT WINAPI get_CubeDefs(CubeDefs **ppvObject) = 0;
  };
#else
  typedef struct ICatalogVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ICatalog *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ICatalog *This);
      ULONG (WINAPI *Release)(ICatalog *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ICatalog *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ICatalog *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ICatalog *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ICatalog *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(ICatalog *This,BSTR *pbstr);
      HRESULT (WINAPI *putref_ActiveConnection)(ICatalog *This,IDispatch *pconn);
      HRESULT (WINAPI *put_ActiveConnection)(ICatalog *This,BSTR bstrConn);
      HRESULT (WINAPI *get_ActiveConnection)(ICatalog *This,IDispatch **ppConn);
      HRESULT (WINAPI *get_CubeDefs)(ICatalog *This,CubeDefs **ppvObject);
    END_INTERFACE
  } ICatalogVtbl;
  struct ICatalog {
    CONST_VTBL struct ICatalogVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ICatalog_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICatalog_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICatalog_Release(This) (This)->lpVtbl->Release(This)
#define ICatalog_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ICatalog_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ICatalog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ICatalog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ICatalog_get_Name(This,pbstr) (This)->lpVtbl->get_Name(This,pbstr)
#define ICatalog_putref_ActiveConnection(This,pconn) (This)->lpVtbl->putref_ActiveConnection(This,pconn)
#define ICatalog_put_ActiveConnection(This,bstrConn) (This)->lpVtbl->put_ActiveConnection(This,bstrConn)
#define ICatalog_get_ActiveConnection(This,ppConn) (This)->lpVtbl->get_ActiveConnection(This,ppConn)
#define ICatalog_get_CubeDefs(This,ppvObject) (This)->lpVtbl->get_CubeDefs(This,ppvObject)
#endif
#endif
  HRESULT WINAPI ICatalog_get_Name_Proxy(ICatalog *This,BSTR *pbstr);
  void __RPC_STUB ICatalog_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatalog_putref_ActiveConnection_Proxy(ICatalog *This,IDispatch *pconn);
  void __RPC_STUB ICatalog_putref_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatalog_put_ActiveConnection_Proxy(ICatalog *This,BSTR bstrConn);
  void __RPC_STUB ICatalog_put_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatalog_get_ActiveConnection_Proxy(ICatalog *This,IDispatch **ppConn);
  void __RPC_STUB ICatalog_get_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatalog_get_CubeDefs_Proxy(ICatalog *This,CubeDefs **ppvObject);
  void __RPC_STUB ICatalog_get_CubeDefs_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ICellset_INTERFACE_DEFINED__
#define __ICellset_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ICellset;
#if defined(__cplusplus) && !defined(CINTERFACE)

  struct ICellset : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Item(SAFEARRAY **idx,Cell **ppvObject) = 0;
    virtual HRESULT WINAPI Open(VARIANT DataSource,VARIANT ActiveConnection) = 0;
    virtual HRESULT WINAPI Close(void) = 0;
    virtual HRESULT WINAPI putref_Source(IDispatch *pcmd) = 0;
    virtual HRESULT WINAPI put_Source(BSTR bstrCmd) = 0;
    virtual HRESULT WINAPI get_Source(VARIANT *pvSource) = 0;
    virtual HRESULT WINAPI putref_ActiveConnection(IDispatch *pconn) = 0;
    virtual HRESULT WINAPI put_ActiveConnection(BSTR bstrConn) = 0;
    virtual HRESULT WINAPI get_ActiveConnection(IDispatch **ppConn) = 0;
    virtual HRESULT WINAPI get_State(LONG *plState) = 0;
    virtual HRESULT WINAPI get_Axes(Axes **ppvObject) = 0;
    virtual HRESULT WINAPI get_FilterAxis(Axis **ppvObject) = 0;
    virtual HRESULT WINAPI get_Properties(Properties **ppvObject) = 0;
  };
#else
  typedef struct ICellsetVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ICellset *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ICellset *This);
      ULONG (WINAPI *Release)(ICellset *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ICellset *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ICellset *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ICellset *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ICellset *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Item)(ICellset *This,SAFEARRAY **idx,Cell **ppvObject);
      HRESULT (WINAPI *Open)(ICellset *This,VARIANT DataSource,VARIANT ActiveConnection);
      HRESULT (WINAPI *Close)(ICellset *This);
      HRESULT (WINAPI *putref_Source)(ICellset *This,IDispatch *pcmd);
      HRESULT (WINAPI *put_Source)(ICellset *This,BSTR bstrCmd);
      HRESULT (WINAPI *get_Source)(ICellset *This,VARIANT *pvSource);
      HRESULT (WINAPI *putref_ActiveConnection)(ICellset *This,IDispatch *pconn);
      HRESULT (WINAPI *put_ActiveConnection)(ICellset *This,BSTR bstrConn);
      HRESULT (WINAPI *get_ActiveConnection)(ICellset *This,IDispatch **ppConn);
      HRESULT (WINAPI *get_State)(ICellset *This,LONG *plState);
      HRESULT (WINAPI *get_Axes)(ICellset *This,Axes **ppvObject);
      HRESULT (WINAPI *get_FilterAxis)(ICellset *This,Axis **ppvObject);
      HRESULT (WINAPI *get_Properties)(ICellset *This,Properties **ppvObject);
    END_INTERFACE
  } ICellsetVtbl;
  struct ICellset {
    CONST_VTBL struct ICellsetVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ICellset_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICellset_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICellset_Release(This) (This)->lpVtbl->Release(This)
#define ICellset_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ICellset_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ICellset_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ICellset_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ICellset_get_Item(This,idx,ppvObject) (This)->lpVtbl->get_Item(This,idx,ppvObject)
#define ICellset_Open(This,DataSource,ActiveConnection) (This)->lpVtbl->Open(This,DataSource,ActiveConnection)
#define ICellset_Close(This) (This)->lpVtbl->Close(This)
#define ICellset_putref_Source(This,pcmd) (This)->lpVtbl->putref_Source(This,pcmd)
#define ICellset_put_Source(This,bstrCmd) (This)->lpVtbl->put_Source(This,bstrCmd)
#define ICellset_get_Source(This,pvSource) (This)->lpVtbl->get_Source(This,pvSource)
#define ICellset_putref_ActiveConnection(This,pconn) (This)->lpVtbl->putref_ActiveConnection(This,pconn)
#define ICellset_put_ActiveConnection(This,bstrConn) (This)->lpVtbl->put_ActiveConnection(This,bstrConn)
#define ICellset_get_ActiveConnection(This,ppConn) (This)->lpVtbl->get_ActiveConnection(This,ppConn)
#define ICellset_get_State(This,plState) (This)->lpVtbl->get_State(This,plState)
#define ICellset_get_Axes(This,ppvObject) (This)->lpVtbl->get_Axes(This,ppvObject)
#define ICellset_get_FilterAxis(This,ppvObject) (This)->lpVtbl->get_FilterAxis(This,ppvObject)
#define ICellset_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#endif
#endif
  HRESULT WINAPI ICellset_get_Item_Proxy(ICellset *This,SAFEARRAY **idx,Cell **ppvObject);
  void __RPC_STUB ICellset_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_Open_Proxy(ICellset *This,VARIANT DataSource,VARIANT ActiveConnection);
  void __RPC_STUB ICellset_Open_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_Close_Proxy(ICellset *This);
  void __RPC_STUB ICellset_Close_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_putref_Source_Proxy(ICellset *This,IDispatch *pcmd);
  void __RPC_STUB ICellset_putref_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_put_Source_Proxy(ICellset *This,BSTR bstrCmd);
  void __RPC_STUB ICellset_put_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_get_Source_Proxy(ICellset *This,VARIANT *pvSource);
  void __RPC_STUB ICellset_get_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_putref_ActiveConnection_Proxy(ICellset *This,IDispatch *pconn);
  void __RPC_STUB ICellset_putref_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_put_ActiveConnection_Proxy(ICellset *This,BSTR bstrConn);
  void __RPC_STUB ICellset_put_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_get_ActiveConnection_Proxy(ICellset *This,IDispatch **ppConn);
  void __RPC_STUB ICellset_get_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_get_State_Proxy(ICellset *This,LONG *plState);
  void __RPC_STUB ICellset_get_State_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_get_Axes_Proxy(ICellset *This,Axes **ppvObject);
  void __RPC_STUB ICellset_get_Axes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_get_FilterAxis_Proxy(ICellset *This,Axis **ppvObject);
  void __RPC_STUB ICellset_get_FilterAxis_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICellset_get_Properties_Proxy(ICellset *This,Properties **ppvObject);
  void __RPC_STUB ICellset_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Cell_INTERFACE_DEFINED__
#define __Cell_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Cell;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Cell : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Value(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI put_Value(VARIANT var) = 0;
    virtual HRESULT WINAPI get_Positions(Positions **ppvObject) = 0;
    virtual HRESULT WINAPI get_Properties(Properties **ppvObject) = 0;
    virtual HRESULT WINAPI get_FormattedValue(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI put_FormattedValue(BSTR bstr) = 0;
    virtual HRESULT WINAPI get_Ordinal(long *pl) = 0;
  };
#else
  typedef struct CellVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Cell *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Cell *This);
      ULONG (WINAPI *Release)(Cell *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Cell *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Cell *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Cell *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Cell *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Value)(Cell *This,VARIANT *pvar);
      HRESULT (WINAPI *put_Value)(Cell *This,VARIANT var);
      HRESULT (WINAPI *get_Positions)(Cell *This,Positions **ppvObject);
      HRESULT (WINAPI *get_Properties)(Cell *This,Properties **ppvObject);
      HRESULT (WINAPI *get_FormattedValue)(Cell *This,BSTR *pbstr);
      HRESULT (WINAPI *put_FormattedValue)(Cell *This,BSTR bstr);
      HRESULT (WINAPI *get_Ordinal)(Cell *This,long *pl);
    END_INTERFACE
  } CellVtbl;
  struct Cell {
    CONST_VTBL struct CellVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Cell_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Cell_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Cell_Release(This) (This)->lpVtbl->Release(This)
#define Cell_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Cell_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Cell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Cell_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Cell_get_Value(This,pvar) (This)->lpVtbl->get_Value(This,pvar)
#define Cell_put_Value(This,var) (This)->lpVtbl->put_Value(This,var)
#define Cell_get_Positions(This,ppvObject) (This)->lpVtbl->get_Positions(This,ppvObject)
#define Cell_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define Cell_get_FormattedValue(This,pbstr) (This)->lpVtbl->get_FormattedValue(This,pbstr)
#define Cell_put_FormattedValue(This,bstr) (This)->lpVtbl->put_FormattedValue(This,bstr)
#define Cell_get_Ordinal(This,pl) (This)->lpVtbl->get_Ordinal(This,pl)
#endif
#endif
  HRESULT WINAPI Cell_get_Value_Proxy(Cell *This,VARIANT *pvar);
  void __RPC_STUB Cell_get_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Cell_put_Value_Proxy(Cell *This,VARIANT var);
  void __RPC_STUB Cell_put_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Cell_get_Positions_Proxy(Cell *This,Positions **ppvObject);
  void __RPC_STUB Cell_get_Positions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Cell_get_Properties_Proxy(Cell *This,Properties **ppvObject);
  void __RPC_STUB Cell_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Cell_get_FormattedValue_Proxy(Cell *This,BSTR *pbstr);
  void __RPC_STUB Cell_get_FormattedValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Cell_put_FormattedValue_Proxy(Cell *This,BSTR bstr);
  void __RPC_STUB Cell_put_FormattedValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Cell_get_Ordinal_Proxy(Cell *This,long *pl);
  void __RPC_STUB Cell_get_Ordinal_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Axis_INTERFACE_DEFINED__
#define __Axis_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Axis;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Axis : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_DimensionCount(long *pl) = 0;
    virtual HRESULT WINAPI get_Positions(Positions **ppvObject) = 0;
    virtual HRESULT WINAPI get_Properties(Properties **ppvObject) = 0;
  };
#else
  typedef struct AxisVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Axis *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Axis *This);
      ULONG (WINAPI *Release)(Axis *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Axis *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Axis *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Axis *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Axis *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(Axis *This,BSTR *pbstr);
      HRESULT (WINAPI *get_DimensionCount)(Axis *This,long *pl);
      HRESULT (WINAPI *get_Positions)(Axis *This,Positions **ppvObject);
      HRESULT (WINAPI *get_Properties)(Axis *This,Properties **ppvObject);
    END_INTERFACE
  } AxisVtbl;
  struct Axis {
    CONST_VTBL struct AxisVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Axis_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Axis_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Axis_Release(This) (This)->lpVtbl->Release(This)
#define Axis_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Axis_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Axis_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Axis_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Axis_get_Name(This,pbstr) (This)->lpVtbl->get_Name(This,pbstr)
#define Axis_get_DimensionCount(This,pl) (This)->lpVtbl->get_DimensionCount(This,pl)
#define Axis_get_Positions(This,ppvObject) (This)->lpVtbl->get_Positions(This,ppvObject)
#define Axis_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#endif
#endif
  HRESULT WINAPI Axis_get_Name_Proxy(Axis *This,BSTR *pbstr);
  void __RPC_STUB Axis_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Axis_get_DimensionCount_Proxy(Axis *This,long *pl);
  void __RPC_STUB Axis_get_DimensionCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Axis_get_Positions_Proxy(Axis *This,Positions **ppvObject);
  void __RPC_STUB Axis_get_Positions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Axis_get_Properties_Proxy(Axis *This,Properties **ppvObject);
  void __RPC_STUB Axis_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Position_INTERFACE_DEFINED__
#define __Position_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Position;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Position : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Ordinal(long *pl) = 0;
    virtual HRESULT WINAPI get_Members(Members **ppvObject) = 0;
  };
#else
  typedef struct PositionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Position *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Position *This);
      ULONG (WINAPI *Release)(Position *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Position *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Position *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Position *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Position *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Ordinal)(Position *This,long *pl);
      HRESULT (WINAPI *get_Members)(Position *This,Members **ppvObject);
    END_INTERFACE
  } PositionVtbl;
  struct Position {
    CONST_VTBL struct PositionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Position_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Position_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Position_Release(This) (This)->lpVtbl->Release(This)
#define Position_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Position_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Position_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Position_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Position_get_Ordinal(This,pl) (This)->lpVtbl->get_Ordinal(This,pl)
#define Position_get_Members(This,ppvObject) (This)->lpVtbl->get_Members(This,ppvObject)
#endif
#endif
  HRESULT WINAPI Position_get_Ordinal_Proxy(Position *This,long *pl);
  void __RPC_STUB Position_get_Ordinal_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Position_get_Members_Proxy(Position *This,Members **ppvObject);
  void __RPC_STUB Position_get_Members_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Member_INTERFACE_DEFINED__
#define __Member_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Member;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Member : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_UniqueName(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Caption(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Description(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Parent(Member **ppvObject) = 0;
    virtual HRESULT WINAPI get_LevelDepth(long *pl) = 0;
    virtual HRESULT WINAPI get_LevelName(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Properties(Properties **ppvObject) = 0;
    virtual HRESULT WINAPI get_Type(MemberTypeEnum *ptype) = 0;
    virtual HRESULT WINAPI get_ChildCount(long *pl) = 0;
    virtual HRESULT WINAPI get_DrilledDown(VARIANT_BOOL *pf) = 0;
    virtual HRESULT WINAPI get_ParentSameAsPrev(VARIANT_BOOL *pf) = 0;
    virtual HRESULT WINAPI get_Children(Members **ppvObject) = 0;
  };
#else
  typedef struct MemberVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Member *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Member *This);
      ULONG (WINAPI *Release)(Member *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Member *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Member *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Member *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Member *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(Member *This,BSTR *pbstr);
      HRESULT (WINAPI *get_UniqueName)(Member *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Caption)(Member *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Description)(Member *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Parent)(Member *This,Member **ppvObject);
      HRESULT (WINAPI *get_LevelDepth)(Member *This,long *pl);
      HRESULT (WINAPI *get_LevelName)(Member *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Properties)(Member *This,Properties **ppvObject);
      HRESULT (WINAPI *get_Type)(Member *This,MemberTypeEnum *ptype);
      HRESULT (WINAPI *get_ChildCount)(Member *This,long *pl);
      HRESULT (WINAPI *get_DrilledDown)(Member *This,VARIANT_BOOL *pf);
      HRESULT (WINAPI *get_ParentSameAsPrev)(Member *This,VARIANT_BOOL *pf);
      HRESULT (WINAPI *get_Children)(Member *This,Members **ppvObject);
    END_INTERFACE
  } MemberVtbl;
  struct Member {
    CONST_VTBL struct MemberVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Member_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Member_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Member_Release(This) (This)->lpVtbl->Release(This)
#define Member_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Member_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Member_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Member_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Member_get_Name(This,pbstr) (This)->lpVtbl->get_Name(This,pbstr)
#define Member_get_UniqueName(This,pbstr) (This)->lpVtbl->get_UniqueName(This,pbstr)
#define Member_get_Caption(This,pbstr) (This)->lpVtbl->get_Caption(This,pbstr)
#define Member_get_Description(This,pbstr) (This)->lpVtbl->get_Description(This,pbstr)
#define Member_get_Parent(This,ppvObject) (This)->lpVtbl->get_Parent(This,ppvObject)
#define Member_get_LevelDepth(This,pl) (This)->lpVtbl->get_LevelDepth(This,pl)
#define Member_get_LevelName(This,pbstr) (This)->lpVtbl->get_LevelName(This,pbstr)
#define Member_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define Member_get_Type(This,ptype) (This)->lpVtbl->get_Type(This,ptype)
#define Member_get_ChildCount(This,pl) (This)->lpVtbl->get_ChildCount(This,pl)
#define Member_get_DrilledDown(This,pf) (This)->lpVtbl->get_DrilledDown(This,pf)
#define Member_get_ParentSameAsPrev(This,pf) (This)->lpVtbl->get_ParentSameAsPrev(This,pf)
#define Member_get_Children(This,ppvObject) (This)->lpVtbl->get_Children(This,ppvObject)
#endif
#endif
  HRESULT WINAPI Member_get_Name_Proxy(Member *This,BSTR *pbstr);
  void __RPC_STUB Member_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_UniqueName_Proxy(Member *This,BSTR *pbstr);
  void __RPC_STUB Member_get_UniqueName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_Caption_Proxy(Member *This,BSTR *pbstr);
  void __RPC_STUB Member_get_Caption_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_Description_Proxy(Member *This,BSTR *pbstr);
  void __RPC_STUB Member_get_Description_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_Parent_Proxy(Member *This,Member **ppvObject);
  void __RPC_STUB Member_get_Parent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_LevelDepth_Proxy(Member *This,long *pl);
  void __RPC_STUB Member_get_LevelDepth_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_LevelName_Proxy(Member *This,BSTR *pbstr);
  void __RPC_STUB Member_get_LevelName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_Properties_Proxy(Member *This,Properties **ppvObject);
  void __RPC_STUB Member_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_Type_Proxy(Member *This,MemberTypeEnum *ptype);
  void __RPC_STUB Member_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_ChildCount_Proxy(Member *This,long *pl);
  void __RPC_STUB Member_get_ChildCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_DrilledDown_Proxy(Member *This,VARIANT_BOOL *pf);
  void __RPC_STUB Member_get_DrilledDown_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_ParentSameAsPrev_Proxy(Member *This,VARIANT_BOOL *pf);
  void __RPC_STUB Member_get_ParentSameAsPrev_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Member_get_Children_Proxy(Member *This,Members **ppvObject);
  void __RPC_STUB Member_get_Children_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Level_INTERFACE_DEFINED__
#define __Level_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Level;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Level : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_UniqueName(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Caption(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Description(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Depth(short *pw) = 0;
    virtual HRESULT WINAPI get_Properties(Properties **ppvObject) = 0;
    virtual HRESULT WINAPI get_Members(Members **ppvObject) = 0;
  };
#else
  typedef struct LevelVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Level *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Level *This);
      ULONG (WINAPI *Release)(Level *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Level *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Level *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Level *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Level *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(Level *This,BSTR *pbstr);
      HRESULT (WINAPI *get_UniqueName)(Level *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Caption)(Level *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Description)(Level *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Depth)(Level *This,short *pw);
      HRESULT (WINAPI *get_Properties)(Level *This,Properties **ppvObject);
      HRESULT (WINAPI *get_Members)(Level *This,Members **ppvObject);
    END_INTERFACE
  } LevelVtbl;
  struct Level {
    CONST_VTBL struct LevelVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Level_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Level_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Level_Release(This) (This)->lpVtbl->Release(This)
#define Level_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Level_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Level_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Level_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Level_get_Name(This,pbstr) (This)->lpVtbl->get_Name(This,pbstr)
#define Level_get_UniqueName(This,pbstr) (This)->lpVtbl->get_UniqueName(This,pbstr)
#define Level_get_Caption(This,pbstr) (This)->lpVtbl->get_Caption(This,pbstr)
#define Level_get_Description(This,pbstr) (This)->lpVtbl->get_Description(This,pbstr)
#define Level_get_Depth(This,pw) (This)->lpVtbl->get_Depth(This,pw)
#define Level_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define Level_get_Members(This,ppvObject) (This)->lpVtbl->get_Members(This,ppvObject)
#endif
#endif
  HRESULT WINAPI Level_get_Name_Proxy(Level *This,BSTR *pbstr);
  void __RPC_STUB Level_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Level_get_UniqueName_Proxy(Level *This,BSTR *pbstr);
  void __RPC_STUB Level_get_UniqueName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Level_get_Caption_Proxy(Level *This,BSTR *pbstr);
  void __RPC_STUB Level_get_Caption_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Level_get_Description_Proxy(Level *This,BSTR *pbstr);
  void __RPC_STUB Level_get_Description_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Level_get_Depth_Proxy(Level *This,short *pw);
  void __RPC_STUB Level_get_Depth_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Level_get_Properties_Proxy(Level *This,Properties **ppvObject);
  void __RPC_STUB Level_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Level_get_Members_Proxy(Level *This,Members **ppvObject);
  void __RPC_STUB Level_get_Members_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __CubeDef25_INTERFACE_DEFINED__
#define __CubeDef25_INTERFACE_DEFINED__
  EXTERN_C const IID IID_CubeDef25;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct CubeDef25 : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Description(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Properties(Properties **ppvObject) = 0;
    virtual HRESULT WINAPI get_Dimensions(Dimensions **ppvObject) = 0;
  };
#else
  typedef struct CubeDef25Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(CubeDef25 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(CubeDef25 *This);
      ULONG (WINAPI *Release)(CubeDef25 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(CubeDef25 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(CubeDef25 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(CubeDef25 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(CubeDef25 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(CubeDef25 *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Description)(CubeDef25 *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Properties)(CubeDef25 *This,Properties **ppvObject);
      HRESULT (WINAPI *get_Dimensions)(CubeDef25 *This,Dimensions **ppvObject);
    END_INTERFACE
  } CubeDef25Vtbl;
  struct CubeDef25 {
    CONST_VTBL struct CubeDef25Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define CubeDef25_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define CubeDef25_AddRef(This) (This)->lpVtbl->AddRef(This)
#define CubeDef25_Release(This) (This)->lpVtbl->Release(This)
#define CubeDef25_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define CubeDef25_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define CubeDef25_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define CubeDef25_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define CubeDef25_get_Name(This,pbstr) (This)->lpVtbl->get_Name(This,pbstr)
#define CubeDef25_get_Description(This,pbstr) (This)->lpVtbl->get_Description(This,pbstr)
#define CubeDef25_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define CubeDef25_get_Dimensions(This,ppvObject) (This)->lpVtbl->get_Dimensions(This,ppvObject)
#endif
#endif
  HRESULT WINAPI CubeDef25_get_Name_Proxy(CubeDef25 *This,BSTR *pbstr);
  void __RPC_STUB CubeDef25_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI CubeDef25_get_Description_Proxy(CubeDef25 *This,BSTR *pbstr);
  void __RPC_STUB CubeDef25_get_Description_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI CubeDef25_get_Properties_Proxy(CubeDef25 *This,Properties **ppvObject);
  void __RPC_STUB CubeDef25_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI CubeDef25_get_Dimensions_Proxy(CubeDef25 *This,Dimensions **ppvObject);
  void __RPC_STUB CubeDef25_get_Dimensions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __CubeDef_INTERFACE_DEFINED__
#define __CubeDef_INTERFACE_DEFINED__
  EXTERN_C const IID IID_CubeDef;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct CubeDef : public CubeDef25 {
  public:
    virtual HRESULT WINAPI GetSchemaObject(SchemaObjectTypeEnum eObjType,BSTR bsUniqueName,IDispatch **ppObj) = 0;

  };
#else
  typedef struct CubeDefVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(CubeDef *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(CubeDef *This);
      ULONG (WINAPI *Release)(CubeDef *This);
      HRESULT (WINAPI *GetTypeInfoCount)(CubeDef *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(CubeDef *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(CubeDef *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(CubeDef *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(CubeDef *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Description)(CubeDef *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Properties)(CubeDef *This,Properties **ppvObject);
      HRESULT (WINAPI *get_Dimensions)(CubeDef *This,Dimensions **ppvObject);
      HRESULT (WINAPI *GetSchemaObject)(CubeDef *This,SchemaObjectTypeEnum eObjType,BSTR bsUniqueName,IDispatch **ppObj);
    END_INTERFACE
  } CubeDefVtbl;
  struct CubeDef {
    CONST_VTBL struct CubeDefVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define CubeDef_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define CubeDef_AddRef(This) (This)->lpVtbl->AddRef(This)
#define CubeDef_Release(This) (This)->lpVtbl->Release(This)
#define CubeDef_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define CubeDef_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define CubeDef_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define CubeDef_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define CubeDef_get_Name(This,pbstr) (This)->lpVtbl->get_Name(This,pbstr)
#define CubeDef_get_Description(This,pbstr) (This)->lpVtbl->get_Description(This,pbstr)
#define CubeDef_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define CubeDef_get_Dimensions(This,ppvObject) (This)->lpVtbl->get_Dimensions(This,ppvObject)
#define CubeDef_GetSchemaObject(This,eObjType,bsUniqueName,ppObj) (This)->lpVtbl->GetSchemaObject(This,eObjType,bsUniqueName,ppObj)
#endif
#endif
  HRESULT WINAPI CubeDef_GetSchemaObject_Proxy(CubeDef *This,SchemaObjectTypeEnum eObjType,BSTR bsUniqueName,IDispatch **ppObj);
  void __RPC_STUB CubeDef_GetSchemaObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Dimension_INTERFACE_DEFINED__
#define __Dimension_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Dimension;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Dimension : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_UniqueName(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Description(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Properties(Properties **ppvObject) = 0;
    virtual HRESULT WINAPI get_Hierarchies(Hierarchies **ppvObject) = 0;
  };
#else
  typedef struct DimensionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Dimension *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Dimension *This);
      ULONG (WINAPI *Release)(Dimension *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Dimension *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Dimension *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Dimension *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Dimension *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(Dimension *This,BSTR *pbstr);
      HRESULT (WINAPI *get_UniqueName)(Dimension *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Description)(Dimension *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Properties)(Dimension *This,Properties **ppvObject);
      HRESULT (WINAPI *get_Hierarchies)(Dimension *This,Hierarchies **ppvObject);
    END_INTERFACE
  } DimensionVtbl;
  struct Dimension {
    CONST_VTBL struct DimensionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Dimension_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Dimension_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Dimension_Release(This) (This)->lpVtbl->Release(This)
#define Dimension_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Dimension_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Dimension_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Dimension_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Dimension_get_Name(This,pbstr) (This)->lpVtbl->get_Name(This,pbstr)
#define Dimension_get_UniqueName(This,pbstr) (This)->lpVtbl->get_UniqueName(This,pbstr)
#define Dimension_get_Description(This,pbstr) (This)->lpVtbl->get_Description(This,pbstr)
#define Dimension_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define Dimension_get_Hierarchies(This,ppvObject) (This)->lpVtbl->get_Hierarchies(This,ppvObject)
#endif
#endif
  HRESULT WINAPI Dimension_get_Name_Proxy(Dimension *This,BSTR *pbstr);
  void __RPC_STUB Dimension_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Dimension_get_UniqueName_Proxy(Dimension *This,BSTR *pbstr);
  void __RPC_STUB Dimension_get_UniqueName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Dimension_get_Description_Proxy(Dimension *This,BSTR *pbstr);
  void __RPC_STUB Dimension_get_Description_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Dimension_get_Properties_Proxy(Dimension *This,Properties **ppvObject);
  void __RPC_STUB Dimension_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Dimension_get_Hierarchies_Proxy(Dimension *This,Hierarchies **ppvObject);
  void __RPC_STUB Dimension_get_Hierarchies_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Hierarchy_INTERFACE_DEFINED__
#define __Hierarchy_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Hierarchy;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Hierarchy : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_UniqueName(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Description(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Properties(Properties **ppvObject) = 0;
    virtual HRESULT WINAPI get_Levels(Levels **ppvObject) = 0;
  };
#else
  typedef struct HierarchyVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Hierarchy *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Hierarchy *This);
      ULONG (WINAPI *Release)(Hierarchy *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Hierarchy *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Hierarchy *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Hierarchy *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Hierarchy *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(Hierarchy *This,BSTR *pbstr);
      HRESULT (WINAPI *get_UniqueName)(Hierarchy *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Description)(Hierarchy *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Properties)(Hierarchy *This,Properties **ppvObject);
      HRESULT (WINAPI *get_Levels)(Hierarchy *This,Levels **ppvObject);
    END_INTERFACE
  } HierarchyVtbl;
  struct Hierarchy {
    CONST_VTBL struct HierarchyVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Hierarchy_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Hierarchy_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Hierarchy_Release(This) (This)->lpVtbl->Release(This)
#define Hierarchy_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Hierarchy_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Hierarchy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Hierarchy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Hierarchy_get_Name(This,pbstr) (This)->lpVtbl->get_Name(This,pbstr)
#define Hierarchy_get_UniqueName(This,pbstr) (This)->lpVtbl->get_UniqueName(This,pbstr)
#define Hierarchy_get_Description(This,pbstr) (This)->lpVtbl->get_Description(This,pbstr)
#define Hierarchy_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define Hierarchy_get_Levels(This,ppvObject) (This)->lpVtbl->get_Levels(This,ppvObject)
#endif
#endif
  HRESULT WINAPI Hierarchy_get_Name_Proxy(Hierarchy *This,BSTR *pbstr);
  void __RPC_STUB Hierarchy_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Hierarchy_get_UniqueName_Proxy(Hierarchy *This,BSTR *pbstr);
  void __RPC_STUB Hierarchy_get_UniqueName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Hierarchy_get_Description_Proxy(Hierarchy *This,BSTR *pbstr);
  void __RPC_STUB Hierarchy_get_Description_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Hierarchy_get_Properties_Proxy(Hierarchy *This,Properties **ppvObject);
  void __RPC_STUB Hierarchy_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Hierarchy_get_Levels_Proxy(Hierarchy *This,Levels **ppvObject);
  void __RPC_STUB Hierarchy_get_Levels_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __MD_Collection_INTERFACE_DEFINED__
#define __MD_Collection_INTERFACE_DEFINED__
  EXTERN_C const IID IID_MD_Collection;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct MD_Collection : public IDispatch {
  public:
    virtual HRESULT WINAPI Refresh(void) = 0;
    virtual HRESULT WINAPI _NewEnum(IUnknown **ppvObject) = 0;
    virtual HRESULT WINAPI get_Count(long *c) = 0;
  };
#else
  typedef struct MD_CollectionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(MD_Collection *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(MD_Collection *This);
      ULONG (WINAPI *Release)(MD_Collection *This);
      HRESULT (WINAPI *GetTypeInfoCount)(MD_Collection *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(MD_Collection *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(MD_Collection *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(MD_Collection *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *Refresh)(MD_Collection *This);
      HRESULT (WINAPI *_NewEnum)(MD_Collection *This,IUnknown **ppvObject);
      HRESULT (WINAPI *get_Count)(MD_Collection *This,long *c);
    END_INTERFACE
  } MD_CollectionVtbl;
  struct MD_Collection {
    CONST_VTBL struct MD_CollectionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define MD_Collection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define MD_Collection_AddRef(This) (This)->lpVtbl->AddRef(This)
#define MD_Collection_Release(This) (This)->lpVtbl->Release(This)
#define MD_Collection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define MD_Collection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define MD_Collection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define MD_Collection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define MD_Collection_Refresh(This) (This)->lpVtbl->Refresh(This)
#define MD_Collection__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define MD_Collection_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#endif
#endif
  HRESULT WINAPI MD_Collection_Refresh_Proxy(MD_Collection *This);
  void __RPC_STUB MD_Collection_Refresh_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI MD_Collection__NewEnum_Proxy(MD_Collection *This,IUnknown **ppvObject);
  void __RPC_STUB MD_Collection__NewEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI MD_Collection_get_Count_Proxy(MD_Collection *This,long *c);
  void __RPC_STUB MD_Collection_get_Count_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Members_INTERFACE_DEFINED__
#define __Members_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Members;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Members : public MD_Collection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,Member **ppvObject) = 0;
  };
#else
  typedef struct MembersVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Members *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Members *This);
      ULONG (WINAPI *Release)(Members *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Members *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Members *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Members *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Members *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *Refresh)(Members *This);
      HRESULT (WINAPI *_NewEnum)(Members *This,IUnknown **ppvObject);
      HRESULT (WINAPI *get_Count)(Members *This,long *c);
      HRESULT (WINAPI *get_Item)(Members *This,VARIANT Index,Member **ppvObject);
    END_INTERFACE
  } MembersVtbl;
  struct Members {
    CONST_VTBL struct MembersVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Members_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Members_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Members_Release(This) (This)->lpVtbl->Release(This)
#define Members_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Members_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Members_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Members_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Members_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Members__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Members_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Members_get_Item(This,Index,ppvObject) (This)->lpVtbl->get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI Members_get_Item_Proxy(Members *This,VARIANT Index,Member **ppvObject);
  void __RPC_STUB Members_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Levels_INTERFACE_DEFINED__
#define __Levels_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Levels;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Levels : public MD_Collection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,Level **ppvObject) = 0;
  };
#else
  typedef struct LevelsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Levels *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Levels *This);
      ULONG (WINAPI *Release)(Levels *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Levels *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Levels *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Levels *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Levels *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *Refresh)(Levels *This);
      HRESULT (WINAPI *_NewEnum)(Levels *This,IUnknown **ppvObject);
      HRESULT (WINAPI *get_Count)(Levels *This,long *c);
      HRESULT (WINAPI *get_Item)(Levels *This,VARIANT Index,Level **ppvObject);
    END_INTERFACE
  } LevelsVtbl;
  struct Levels {
    CONST_VTBL struct LevelsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Levels_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Levels_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Levels_Release(This) (This)->lpVtbl->Release(This)
#define Levels_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Levels_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Levels_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Levels_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Levels_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Levels__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Levels_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Levels_get_Item(This,Index,ppvObject) (This)->lpVtbl->get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI Levels_get_Item_Proxy(Levels *This,VARIANT Index,Level **ppvObject);
  void __RPC_STUB Levels_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Axes_INTERFACE_DEFINED__
#define __Axes_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Axes;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Axes : public MD_Collection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,Axis **ppvObject) = 0;
  };
#else
  typedef struct AxesVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Axes *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Axes *This);
      ULONG (WINAPI *Release)(Axes *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Axes *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Axes *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Axes *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Axes *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *Refresh)(Axes *This);
      HRESULT (WINAPI *_NewEnum)(Axes *This,IUnknown **ppvObject);
      HRESULT (WINAPI *get_Count)(Axes *This,long *c);
      HRESULT (WINAPI *get_Item)(Axes *This,VARIANT Index,Axis **ppvObject);
    END_INTERFACE
  } AxesVtbl;
  struct Axes {
    CONST_VTBL struct AxesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Axes_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Axes_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Axes_Release(This) (This)->lpVtbl->Release(This)
#define Axes_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Axes_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Axes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Axes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Axes_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Axes__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Axes_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Axes_get_Item(This,Index,ppvObject) (This)->lpVtbl->get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI Axes_get_Item_Proxy(Axes *This,VARIANT Index,Axis **ppvObject);
  void __RPC_STUB Axes_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Positions_INTERFACE_DEFINED__
#define __Positions_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Positions;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Positions : public MD_Collection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,Position **ppvObject) = 0;
  };
#else
  typedef struct PositionsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Positions *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Positions *This);
      ULONG (WINAPI *Release)(Positions *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Positions *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Positions *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Positions *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Positions *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *Refresh)(Positions *This);
      HRESULT (WINAPI *_NewEnum)(Positions *This,IUnknown **ppvObject);
      HRESULT (WINAPI *get_Count)(Positions *This,long *c);
      HRESULT (WINAPI *get_Item)(Positions *This,VARIANT Index,Position **ppvObject);
    END_INTERFACE
  } PositionsVtbl;
  struct Positions {
    CONST_VTBL struct PositionsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Positions_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Positions_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Positions_Release(This) (This)->lpVtbl->Release(This)
#define Positions_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Positions_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Positions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Positions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Positions_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Positions__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Positions_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Positions_get_Item(This,Index,ppvObject) (This)->lpVtbl->get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI Positions_get_Item_Proxy(Positions *This,VARIANT Index,Position **ppvObject);
  void __RPC_STUB Positions_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Hierarchies_INTERFACE_DEFINED__
#define __Hierarchies_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Hierarchies;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Hierarchies : public MD_Collection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,Hierarchy **ppvObject) = 0;
  };
#else
  typedef struct HierarchiesVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Hierarchies *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Hierarchies *This);
      ULONG (WINAPI *Release)(Hierarchies *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Hierarchies *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Hierarchies *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Hierarchies *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Hierarchies *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *Refresh)(Hierarchies *This);
      HRESULT (WINAPI *_NewEnum)(Hierarchies *This,IUnknown **ppvObject);
      HRESULT (WINAPI *get_Count)(Hierarchies *This,long *c);
      HRESULT (WINAPI *get_Item)(Hierarchies *This,VARIANT Index,Hierarchy **ppvObject);
    END_INTERFACE
  } HierarchiesVtbl;
  struct Hierarchies {
    CONST_VTBL struct HierarchiesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Hierarchies_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Hierarchies_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Hierarchies_Release(This) (This)->lpVtbl->Release(This)
#define Hierarchies_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Hierarchies_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Hierarchies_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Hierarchies_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Hierarchies_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Hierarchies__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Hierarchies_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Hierarchies_get_Item(This,Index,ppvObject) (This)->lpVtbl->get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI Hierarchies_get_Item_Proxy(Hierarchies *This,VARIANT Index,Hierarchy **ppvObject);
  void __RPC_STUB Hierarchies_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Dimensions_INTERFACE_DEFINED__
#define __Dimensions_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Dimensions;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Dimensions : public MD_Collection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,Dimension **ppvObject) = 0;
  };
#else
  typedef struct DimensionsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Dimensions *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Dimensions *This);
      ULONG (WINAPI *Release)(Dimensions *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Dimensions *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Dimensions *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Dimensions *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Dimensions *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *Refresh)(Dimensions *This);
      HRESULT (WINAPI *_NewEnum)(Dimensions *This,IUnknown **ppvObject);
      HRESULT (WINAPI *get_Count)(Dimensions *This,long *c);
      HRESULT (WINAPI *get_Item)(Dimensions *This,VARIANT Index,Dimension **ppvObject);
    END_INTERFACE
  } DimensionsVtbl;
  struct Dimensions {
    CONST_VTBL struct DimensionsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Dimensions_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Dimensions_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Dimensions_Release(This) (This)->lpVtbl->Release(This)
#define Dimensions_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Dimensions_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Dimensions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Dimensions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Dimensions_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Dimensions__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Dimensions_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Dimensions_get_Item(This,Index,ppvObject) (This)->lpVtbl->get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI Dimensions_get_Item_Proxy(Dimensions *This,VARIANT Index,Dimension **ppvObject);
  void __RPC_STUB Dimensions_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __CubeDefs_INTERFACE_DEFINED__
#define __CubeDefs_INTERFACE_DEFINED__
  EXTERN_C const IID IID_CubeDefs;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct CubeDefs : public MD_Collection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,CubeDef **ppvObject) = 0;
  };
#else
  typedef struct CubeDefsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(CubeDefs *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(CubeDefs *This);
      ULONG (WINAPI *Release)(CubeDefs *This);
      HRESULT (WINAPI *GetTypeInfoCount)(CubeDefs *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(CubeDefs *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(CubeDefs *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(CubeDefs *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *Refresh)(CubeDefs *This);
      HRESULT (WINAPI *_NewEnum)(CubeDefs *This,IUnknown **ppvObject);
      HRESULT (WINAPI *get_Count)(CubeDefs *This,long *c);
      HRESULT (WINAPI *get_Item)(CubeDefs *This,VARIANT Index,CubeDef **ppvObject);
    END_INTERFACE
  } CubeDefsVtbl;
  struct CubeDefs {
    CONST_VTBL struct CubeDefsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define CubeDefs_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define CubeDefs_AddRef(This) (This)->lpVtbl->AddRef(This)
#define CubeDefs_Release(This) (This)->lpVtbl->Release(This)
#define CubeDefs_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define CubeDefs_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define CubeDefs_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define CubeDefs_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define CubeDefs_Refresh(This) (This)->lpVtbl->Refresh(This)
#define CubeDefs__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define CubeDefs_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define CubeDefs_get_Item(This,Index,ppvObject) (This)->lpVtbl->get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI CubeDefs_get_Item_Proxy(CubeDefs *This,VARIANT Index,CubeDef **ppvObject);
  void __RPC_STUB CubeDefs_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_Catalog;
#ifdef __cplusplus
  class Catalog;
#endif
  EXTERN_C const CLSID CLSID_Cellset;
#ifdef __cplusplus
  class Cellset;
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
