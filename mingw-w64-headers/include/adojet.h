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

#ifndef __adojet_h__
#define __adojet_h__

#ifndef __IReplica_FWD_DEFINED__
#define __IReplica_FWD_DEFINED__
typedef struct IReplica IReplica;
#endif

#ifndef __Filter_FWD_DEFINED__
#define __Filter_FWD_DEFINED__
typedef struct Filter Filter;
#endif

#ifndef __Filters_FWD_DEFINED__
#define __Filters_FWD_DEFINED__
typedef struct Filters Filters;
#endif

#ifndef __IJetEngine_FWD_DEFINED__
#define __IJetEngine_FWD_DEFINED__
typedef struct IJetEngine IJetEngine;
#endif

#ifndef __Replica_FWD_DEFINED__
#define __Replica_FWD_DEFINED__

#ifdef __cplusplus
typedef class Replica Replica;
#else
typedef struct Replica Replica;
#endif
#endif

#ifndef __JetEngine_FWD_DEFINED__
#define __JetEngine_FWD_DEFINED__

#ifdef __cplusplus
typedef class JetEngine JetEngine;
#else
typedef struct JetEngine JetEngine;
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

  extern RPC_IF_HANDLE __MIDL_itf_adojet_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_adojet_0000_v0_0_s_ifspec;

#ifndef __JRO_LIBRARY_DEFINED__
#define __JRO_LIBRARY_DEFINED__

  typedef enum ReplicaTypeEnum {
    jrRepTypeNotReplicable = 0,jrRepTypeDesignMaster = 0x1,jrRepTypeFull = 0x2,jrRepTypePartial = 0x3
  } ReplicaTypeEnum;

  typedef enum VisibilityEnum {
    jrRepVisibilityGlobal = 0x1,jrRepVisibilityLocal = 0x2,jrRepVisibilityAnon = 0x4
  } VisibilityEnum;

  typedef enum UpdatabilityEnum {
    jrRepUpdFull = 0,jrRepUpdReadOnly = 0x2
  } UpdatabilityEnum;

  typedef enum SyncTypeEnum {
    jrSyncTypeExport = 0x1,jrSyncTypeImport = 0x2,jrSyncTypeImpExp = 0x3
  } SyncTypeEnum;

  typedef enum SyncModeEnum {
    jrSyncModeIndirect = 0x1,jrSyncModeDirect = 0x2,jrSyncModeInternet = 0x3
  } SyncModeEnum;

  typedef enum FilterTypeEnum {
    jrFilterTypeTable = 0x1,jrFilterTypeRelationship = 0x2
  } FilterTypeEnum;

  EXTERN_C const IID LIBID_JRO;

#ifndef __IReplica_INTERFACE_DEFINED__
#define __IReplica_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IReplica;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IReplica : public IDispatch {
  public:
    virtual HRESULT WINAPI putref_ActiveConnection(IDispatch *pconn) = 0;
    virtual HRESULT WINAPI put_ActiveConnection(VARIANT vConn) = 0;
    virtual HRESULT WINAPI get_ActiveConnection(IDispatch **ppconn) = 0;
    virtual HRESULT WINAPI get_ConflictFunction(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI put_ConflictFunction(BSTR bstr) = 0;
    virtual HRESULT WINAPI get_ConflictTables(_Recordset **pprset) = 0;
    virtual HRESULT WINAPI get_DesignMasterId(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI put_DesignMasterId(VARIANT var) = 0;
    virtual HRESULT WINAPI get_Priority(long *pl) = 0;
    virtual HRESULT WINAPI get_ReplicaId(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI get_ReplicaType(ReplicaTypeEnum *pl) = 0;
    virtual HRESULT WINAPI get_RetentionPeriod(long *pl) = 0;
    virtual HRESULT WINAPI put_RetentionPeriod(long l) = 0;
    virtual HRESULT WINAPI get_Visibility(VisibilityEnum *pl) = 0;
    virtual HRESULT WINAPI CreateReplica(BSTR replicaName,BSTR description,ReplicaTypeEnum replicaType = jrRepTypeFull,VisibilityEnum visibility = jrRepVisibilityGlobal,long priority = -1,UpdatabilityEnum updatability = jrRepUpdFull) = 0;
    virtual HRESULT WINAPI GetObjectReplicability(BSTR objectName,BSTR objectType,VARIANT_BOOL *replicability) = 0;
    virtual HRESULT WINAPI SetObjectReplicability(BSTR objectName,BSTR objectType,VARIANT_BOOL replicability) = 0;
    virtual HRESULT WINAPI MakeReplicable(BSTR connectionString = L"",VARIANT_BOOL columnTracking = -1) = 0;
    virtual HRESULT WINAPI PopulatePartial(BSTR FullReplica) = 0;
    virtual HRESULT WINAPI Synchronize(BSTR target,SyncTypeEnum syncType = jrSyncTypeImpExp,SyncModeEnum syncMode = jrSyncModeIndirect) = 0;
    virtual HRESULT WINAPI get_Filters(Filters **ppFilters) = 0;
  };
#else
  typedef struct IReplicaVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IReplica *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IReplica *This);
      ULONG (WINAPI *Release)(IReplica *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IReplica *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IReplica *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IReplica *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IReplica *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *putref_ActiveConnection)(IReplica *This,IDispatch *pconn);
      HRESULT (WINAPI *put_ActiveConnection)(IReplica *This,VARIANT vConn);
      HRESULT (WINAPI *get_ActiveConnection)(IReplica *This,IDispatch **ppconn);
      HRESULT (WINAPI *get_ConflictFunction)(IReplica *This,BSTR *pbstr);
      HRESULT (WINAPI *put_ConflictFunction)(IReplica *This,BSTR bstr);
      HRESULT (WINAPI *get_ConflictTables)(IReplica *This,_Recordset **pprset);
      HRESULT (WINAPI *get_DesignMasterId)(IReplica *This,VARIANT *pvar);
      HRESULT (WINAPI *put_DesignMasterId)(IReplica *This,VARIANT var);
      HRESULT (WINAPI *get_Priority)(IReplica *This,long *pl);
      HRESULT (WINAPI *get_ReplicaId)(IReplica *This,VARIANT *pvar);
      HRESULT (WINAPI *get_ReplicaType)(IReplica *This,ReplicaTypeEnum *pl);
      HRESULT (WINAPI *get_RetentionPeriod)(IReplica *This,long *pl);
      HRESULT (WINAPI *put_RetentionPeriod)(IReplica *This,long l);
      HRESULT (WINAPI *get_Visibility)(IReplica *This,VisibilityEnum *pl);
      HRESULT (WINAPI *CreateReplica)(IReplica *This,BSTR replicaName,BSTR description,ReplicaTypeEnum replicaType,VisibilityEnum visibility,long priority,UpdatabilityEnum updatability);
      HRESULT (WINAPI *GetObjectReplicability)(IReplica *This,BSTR objectName,BSTR objectType,VARIANT_BOOL *replicability);
      HRESULT (WINAPI *SetObjectReplicability)(IReplica *This,BSTR objectName,BSTR objectType,VARIANT_BOOL replicability);
      HRESULT (WINAPI *MakeReplicable)(IReplica *This,BSTR connectionString,VARIANT_BOOL columnTracking);
      HRESULT (WINAPI *PopulatePartial)(IReplica *This,BSTR FullReplica);
      HRESULT (WINAPI *Synchronize)(IReplica *This,BSTR target,SyncTypeEnum syncType,SyncModeEnum syncMode);
      HRESULT (WINAPI *get_Filters)(IReplica *This,Filters **ppFilters);
    END_INTERFACE
  } IReplicaVtbl;
  struct IReplica {
    CONST_VTBL struct IReplicaVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IReplica_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IReplica_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IReplica_Release(This) (This)->lpVtbl->Release(This)
#define IReplica_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IReplica_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IReplica_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IReplica_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IReplica_putref_ActiveConnection(This,pconn) (This)->lpVtbl->putref_ActiveConnection(This,pconn)
#define IReplica_put_ActiveConnection(This,vConn) (This)->lpVtbl->put_ActiveConnection(This,vConn)
#define IReplica_get_ActiveConnection(This,ppconn) (This)->lpVtbl->get_ActiveConnection(This,ppconn)
#define IReplica_get_ConflictFunction(This,pbstr) (This)->lpVtbl->get_ConflictFunction(This,pbstr)
#define IReplica_put_ConflictFunction(This,bstr) (This)->lpVtbl->put_ConflictFunction(This,bstr)
#define IReplica_get_ConflictTables(This,pprset) (This)->lpVtbl->get_ConflictTables(This,pprset)
#define IReplica_get_DesignMasterId(This,pvar) (This)->lpVtbl->get_DesignMasterId(This,pvar)
#define IReplica_put_DesignMasterId(This,var) (This)->lpVtbl->put_DesignMasterId(This,var)
#define IReplica_get_Priority(This,pl) (This)->lpVtbl->get_Priority(This,pl)
#define IReplica_get_ReplicaId(This,pvar) (This)->lpVtbl->get_ReplicaId(This,pvar)
#define IReplica_get_ReplicaType(This,pl) (This)->lpVtbl->get_ReplicaType(This,pl)
#define IReplica_get_RetentionPeriod(This,pl) (This)->lpVtbl->get_RetentionPeriod(This,pl)
#define IReplica_put_RetentionPeriod(This,l) (This)->lpVtbl->put_RetentionPeriod(This,l)
#define IReplica_get_Visibility(This,pl) (This)->lpVtbl->get_Visibility(This,pl)
#define IReplica_CreateReplica(This,replicaName,description,replicaType,visibility,priority,updatability) (This)->lpVtbl->CreateReplica(This,replicaName,description,replicaType,visibility,priority,updatability)
#define IReplica_GetObjectReplicability(This,objectName,objectType,replicability) (This)->lpVtbl->GetObjectReplicability(This,objectName,objectType,replicability)
#define IReplica_SetObjectReplicability(This,objectName,objectType,replicability) (This)->lpVtbl->SetObjectReplicability(This,objectName,objectType,replicability)
#define IReplica_MakeReplicable(This,connectionString,columnTracking) (This)->lpVtbl->MakeReplicable(This,connectionString,columnTracking)
#define IReplica_PopulatePartial(This,FullReplica) (This)->lpVtbl->PopulatePartial(This,FullReplica)
#define IReplica_Synchronize(This,target,syncType,syncMode) (This)->lpVtbl->Synchronize(This,target,syncType,syncMode)
#define IReplica_get_Filters(This,ppFilters) (This)->lpVtbl->get_Filters(This,ppFilters)
#endif
#endif
  HRESULT WINAPI IReplica_putref_ActiveConnection_Proxy(IReplica *This,IDispatch *pconn);
  void __RPC_STUB IReplica_putref_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_put_ActiveConnection_Proxy(IReplica *This,VARIANT vConn);
  void __RPC_STUB IReplica_put_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_ActiveConnection_Proxy(IReplica *This,IDispatch **ppconn);
  void __RPC_STUB IReplica_get_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_ConflictFunction_Proxy(IReplica *This,BSTR *pbstr);
  void __RPC_STUB IReplica_get_ConflictFunction_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_put_ConflictFunction_Proxy(IReplica *This,BSTR bstr);
  void __RPC_STUB IReplica_put_ConflictFunction_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_ConflictTables_Proxy(IReplica *This,_Recordset **pprset);
  void __RPC_STUB IReplica_get_ConflictTables_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_DesignMasterId_Proxy(IReplica *This,VARIANT *pvar);
  void __RPC_STUB IReplica_get_DesignMasterId_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_put_DesignMasterId_Proxy(IReplica *This,VARIANT var);
  void __RPC_STUB IReplica_put_DesignMasterId_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_Priority_Proxy(IReplica *This,long *pl);
  void __RPC_STUB IReplica_get_Priority_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_ReplicaId_Proxy(IReplica *This,VARIANT *pvar);
  void __RPC_STUB IReplica_get_ReplicaId_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_ReplicaType_Proxy(IReplica *This,ReplicaTypeEnum *pl);
  void __RPC_STUB IReplica_get_ReplicaType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_RetentionPeriod_Proxy(IReplica *This,long *pl);
  void __RPC_STUB IReplica_get_RetentionPeriod_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_put_RetentionPeriod_Proxy(IReplica *This,long l);
  void __RPC_STUB IReplica_put_RetentionPeriod_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_Visibility_Proxy(IReplica *This,VisibilityEnum *pl);
  void __RPC_STUB IReplica_get_Visibility_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_CreateReplica_Proxy(IReplica *This,BSTR replicaName,BSTR description,ReplicaTypeEnum replicaType,VisibilityEnum visibility,long priority,UpdatabilityEnum updatability);
  void __RPC_STUB IReplica_CreateReplica_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_GetObjectReplicability_Proxy(IReplica *This,BSTR objectName,BSTR objectType,VARIANT_BOOL *replicability);
  void __RPC_STUB IReplica_GetObjectReplicability_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_SetObjectReplicability_Proxy(IReplica *This,BSTR objectName,BSTR objectType,VARIANT_BOOL replicability);
  void __RPC_STUB IReplica_SetObjectReplicability_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_MakeReplicable_Proxy(IReplica *This,BSTR connectionString,VARIANT_BOOL columnTracking);
  void __RPC_STUB IReplica_MakeReplicable_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_PopulatePartial_Proxy(IReplica *This,BSTR FullReplica);
  void __RPC_STUB IReplica_PopulatePartial_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_Synchronize_Proxy(IReplica *This,BSTR target,SyncTypeEnum syncType,SyncModeEnum syncMode);
  void __RPC_STUB IReplica_Synchronize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IReplica_get_Filters_Proxy(IReplica *This,Filters **ppFilters);
  void __RPC_STUB IReplica_get_Filters_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Filter_INTERFACE_DEFINED__
#define __Filter_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Filter;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Filter : public IDispatch {
  public:
    virtual HRESULT WINAPI get_TableName(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_FilterType(FilterTypeEnum *ptype) = 0;
    virtual HRESULT WINAPI get_FilterCriteria(BSTR *pbstr) = 0;
  };
#else
  typedef struct FilterVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Filter *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Filter *This);
      ULONG (WINAPI *Release)(Filter *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Filter *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Filter *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Filter *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Filter *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_TableName)(Filter *This,BSTR *pbstr);
      HRESULT (WINAPI *get_FilterType)(Filter *This,FilterTypeEnum *ptype);
      HRESULT (WINAPI *get_FilterCriteria)(Filter *This,BSTR *pbstr);
    END_INTERFACE
  } FilterVtbl;
  struct Filter {
    CONST_VTBL struct FilterVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Filter_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Filter_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Filter_Release(This) (This)->lpVtbl->Release(This)
#define Filter_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Filter_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Filter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Filter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Filter_get_TableName(This,pbstr) (This)->lpVtbl->get_TableName(This,pbstr)
#define Filter_get_FilterType(This,ptype) (This)->lpVtbl->get_FilterType(This,ptype)
#define Filter_get_FilterCriteria(This,pbstr) (This)->lpVtbl->get_FilterCriteria(This,pbstr)
#endif
#endif
  HRESULT WINAPI Filter_get_TableName_Proxy(Filter *This,BSTR *pbstr);
  void __RPC_STUB Filter_get_TableName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Filter_get_FilterType_Proxy(Filter *This,FilterTypeEnum *ptype);
  void __RPC_STUB Filter_get_FilterType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Filter_get_FilterCriteria_Proxy(Filter *This,BSTR *pbstr);
  void __RPC_STUB Filter_get_FilterCriteria_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Filters_INTERFACE_DEFINED__
#define __Filters_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Filters;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Filters : public IDispatch {
  public:
    virtual HRESULT WINAPI Refresh(void) = 0;
    virtual HRESULT WINAPI _NewEnum(IUnknown **ppvObject) = 0;
    virtual HRESULT WINAPI get_Count(long *c) = 0;
    virtual HRESULT WINAPI get_Item(VARIANT Index,Filter **ppvObject) = 0;
    virtual HRESULT WINAPI Append(BSTR tableName,FilterTypeEnum filterType,BSTR filterCriteria) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Index) = 0;
  };
#else
  typedef struct FiltersVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Filters *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Filters *This);
      ULONG (WINAPI *Release)(Filters *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Filters *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Filters *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Filters *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Filters *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *Refresh)(Filters *This);
      HRESULT (WINAPI *_NewEnum)(Filters *This,IUnknown **ppvObject);
      HRESULT (WINAPI *get_Count)(Filters *This,long *c);
      HRESULT (WINAPI *get_Item)(Filters *This,VARIANT Index,Filter **ppvObject);
      HRESULT (WINAPI *Append)(Filters *This,BSTR tableName,FilterTypeEnum filterType,BSTR filterCriteria);
      HRESULT (WINAPI *Delete)(Filters *This,VARIANT Index);
    END_INTERFACE
  } FiltersVtbl;
  struct Filters {
    CONST_VTBL struct FiltersVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Filters_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Filters_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Filters_Release(This) (This)->lpVtbl->Release(This)
#define Filters_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Filters_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Filters_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Filters_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Filters_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Filters__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Filters_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Filters_get_Item(This,Index,ppvObject) (This)->lpVtbl->get_Item(This,Index,ppvObject)
#define Filters_Append(This,tableName,filterType,filterCriteria) (This)->lpVtbl->Append(This,tableName,filterType,filterCriteria)
#define Filters_Delete(This,Index) (This)->lpVtbl->Delete(This,Index)
#endif
#endif
  HRESULT WINAPI Filters_Refresh_Proxy(Filters *This);
  void __RPC_STUB Filters_Refresh_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Filters__NewEnum_Proxy(Filters *This,IUnknown **ppvObject);
  void __RPC_STUB Filters__NewEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Filters_get_Count_Proxy(Filters *This,long *c);
  void __RPC_STUB Filters_get_Count_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Filters_get_Item_Proxy(Filters *This,VARIANT Index,Filter **ppvObject);
  void __RPC_STUB Filters_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Filters_Append_Proxy(Filters *This,BSTR tableName,FilterTypeEnum filterType,BSTR filterCriteria);
  void __RPC_STUB Filters_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Filters_Delete_Proxy(Filters *This,VARIANT Index);
  void __RPC_STUB Filters_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IJetEngine_INTERFACE_DEFINED__
#define __IJetEngine_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IJetEngine;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IJetEngine : public IDispatch {
  public:
    virtual HRESULT WINAPI CompactDatabase(BSTR SourceConnection,BSTR Destconnection) = 0;
    virtual HRESULT WINAPI RefreshCache(_Connection *Connection) = 0;
  };
#else
  typedef struct IJetEngineVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IJetEngine *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IJetEngine *This);
      ULONG (WINAPI *Release)(IJetEngine *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IJetEngine *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IJetEngine *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IJetEngine *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IJetEngine *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *CompactDatabase)(IJetEngine *This,BSTR SourceConnection,BSTR Destconnection);
      HRESULT (WINAPI *RefreshCache)(IJetEngine *This,_Connection *Connection);
    END_INTERFACE
  } IJetEngineVtbl;
  struct IJetEngine {
    CONST_VTBL struct IJetEngineVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IJetEngine_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IJetEngine_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IJetEngine_Release(This) (This)->lpVtbl->Release(This)
#define IJetEngine_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IJetEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IJetEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IJetEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IJetEngine_CompactDatabase(This,SourceConnection,Destconnection) (This)->lpVtbl->CompactDatabase(This,SourceConnection,Destconnection)
#define IJetEngine_RefreshCache(This,Connection) (This)->lpVtbl->RefreshCache(This,Connection)
#endif
#endif
  HRESULT WINAPI IJetEngine_CompactDatabase_Proxy(IJetEngine *This,BSTR SourceConnection,BSTR Destconnection);
  void __RPC_STUB IJetEngine_CompactDatabase_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IJetEngine_RefreshCache_Proxy(IJetEngine *This,_Connection *Connection);
  void __RPC_STUB IJetEngine_RefreshCache_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_Replica;

#ifdef __cplusplus
  class Replica;
#endif
  EXTERN_C const CLSID CLSID_JetEngine;
#ifdef __cplusplus
  class JetEngine;
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
