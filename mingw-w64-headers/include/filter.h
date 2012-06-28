/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __filter_h__
#define __filter_h__

#ifndef __IFilter_FWD_DEFINED__
#define __IFilter_FWD_DEFINED__
typedef struct IFilter IFilter;
#endif

#include "unknwn.h"
#include "objidl.h"
#include "propidl.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#ifndef _TAGFULLPROPSPEC_DEFINED_
#define _TAGFULLPROPSPEC_DEFINED_
  typedef struct tagFULLPROPSPEC {
    GUID guidPropSet;
    PROPSPEC psProperty;
  } FULLPROPSPEC;
#endif

  extern RPC_IF_HANDLE __MIDL_itf_filter_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_filter_0000_v0_0_s_ifspec;

#ifndef __IFilter_INTERFACE_DEFINED__
#define __IFilter_INTERFACE_DEFINED__

#ifndef _tagIFILTER_INIT_DEFINED
  typedef enum tagIFILTER_INIT {
    IFILTER_INIT_CANON_PARAGRAPHS = 1,IFILTER_INIT_HARD_LINE_BREAKS = 2,IFILTER_INIT_CANON_HYPHENS = 4,IFILTER_INIT_CANON_SPACES = 8,
    IFILTER_INIT_APPLY_INDEX_ATTRIBUTES = 16,IFILTER_INIT_APPLY_OTHER_ATTRIBUTES = 32,IFILTER_INIT_INDEXING_ONLY = 64,IFILTER_INIT_SEARCH_LINKS = 128
  } IFILTER_INIT;

#define _tagIFILTER_INIT_DEFINED
#define _IFILTER_INIT_DEFINED
#endif
#ifndef _tagIFILTER_FLAGS_DEFINED
  typedef enum tagIFILTER_FLAGS {
    IFILTER_FLAGS_OLE_PROPERTIES = 1
  } IFILTER_FLAGS;

#define _tagIFILTER_FLAGS_DEFINED
#define _IFILTER_FLAGS_DEFINED
#endif
#ifndef _tagCHUNKSTATE_DEFINED
  typedef enum tagCHUNKSTATE {
    CHUNK_TEXT = 0x1,CHUNK_VALUE = 0x2
  } CHUNKSTATE;

#define _tagCHUNKSTATE_DEFINED
#define _CHUNKSTATE_DEFINED
#endif
#ifndef _tagCHUNK_BREAKTYPE_DEFINED
  typedef enum tagCHUNK_BREAKTYPE {
    CHUNK_NO_BREAK = 0,CHUNK_EOW = 1,CHUNK_EOS = 2,CHUNK_EOP = 3,CHUNK_EOC = 4
  } CHUNK_BREAKTYPE;

#define _tagCHUNK_BREAKTYPE_DEFINED
#define _CHUNK_BREAKTYPE_DEFINED
#endif
#ifndef _tagFILTERREGION_DEFINED
  typedef struct tagFILTERREGION {
    ULONG idChunk;
    ULONG cwcStart;
    ULONG cwcExtent;
  } FILTERREGION;

#define _tagFILTERREGION_DEFINED
#define _FILTERREGION_DEFINED
#endif

#ifndef _tagSTAT_CHUNK_DEFINED
#define _tagSTAT_CHUNK_DEFINED
  typedef struct tagSTAT_CHUNK {
    ULONG idChunk;
    CHUNK_BREAKTYPE breakType;
    CHUNKSTATE flags;
    LCID locale;
    FULLPROPSPEC attribute;
    ULONG idChunkSource;
    ULONG cwcStartSource;
    ULONG cwcLenSource;
  } STAT_CHUNK;
#define _STAT_CHUNK_DEFINED
#endif

  EXTERN_C const IID IID_IFilter;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IFilter : public IUnknown {
  public:
    virtual SCODE WINAPI Init(ULONG grfFlags,ULONG cAttributes,const FULLPROPSPEC *aAttributes,ULONG *pFlags) = 0;
    virtual SCODE WINAPI GetChunk(STAT_CHUNK *pStat) = 0;
    virtual SCODE WINAPI GetText(ULONG *pcwcBuffer,WCHAR *awcBuffer) = 0;
    virtual SCODE WINAPI GetValue(PROPVARIANT **ppPropValue) = 0;
    virtual SCODE WINAPI BindRegion(FILTERREGION origPos,REFIID riid,void **ppunk) = 0;
  };
#else
  typedef struct IFilterVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IFilter *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IFilter *This);
      ULONG (WINAPI *Release)(IFilter *This);
      SCODE (WINAPI *Init)(IFilter *This,ULONG grfFlags,ULONG cAttributes,const FULLPROPSPEC *aAttributes,ULONG *pFlags);
      SCODE (WINAPI *GetChunk)(IFilter *This,STAT_CHUNK *pStat);
      SCODE (WINAPI *GetText)(IFilter *This,ULONG *pcwcBuffer,WCHAR *awcBuffer);
      SCODE (WINAPI *GetValue)(IFilter *This,PROPVARIANT **ppPropValue);
      SCODE (WINAPI *BindRegion)(IFilter *This,FILTERREGION origPos,REFIID riid,void **ppunk);
    END_INTERFACE
  } IFilterVtbl;
  struct IFilter {
    CONST_VTBL struct IFilterVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IFilter_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFilter_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFilter_Release(This) (This)->lpVtbl->Release(This)
#define IFilter_Init(This,grfFlags,cAttributes,aAttributes,pFlags) (This)->lpVtbl->Init(This,grfFlags,cAttributes,aAttributes,pFlags)
#define IFilter_GetChunk(This,pStat) (This)->lpVtbl->GetChunk(This,pStat)
#define IFilter_GetText(This,pcwcBuffer,awcBuffer) (This)->lpVtbl->GetText(This,pcwcBuffer,awcBuffer)
#define IFilter_GetValue(This,ppPropValue) (This)->lpVtbl->GetValue(This,ppPropValue)
#define IFilter_BindRegion(This,origPos,riid,ppunk) (This)->lpVtbl->BindRegion(This,origPos,riid,ppunk)
#endif
#endif
  SCODE WINAPI IFilter_Init_Proxy(IFilter *This,ULONG grfFlags,ULONG cAttributes,const FULLPROPSPEC *aAttributes,ULONG *pFlags);
  void __RPC_STUB IFilter_Init_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  SCODE WINAPI IFilter_GetChunk_Proxy(IFilter *This,STAT_CHUNK *pStat);
  void __RPC_STUB IFilter_GetChunk_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  SCODE WINAPI IFilter_GetText_Proxy(IFilter *This,ULONG *pcwcBuffer,WCHAR *awcBuffer);
  void __RPC_STUB IFilter_GetText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  SCODE WINAPI IFilter_GetValue_Proxy(IFilter *This,PROPVARIANT **ppPropValue);
  void __RPC_STUB IFilter_GetValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  SCODE WINAPI IFilter_BindRegion_Proxy(IFilter *This,FILTERREGION origPos,REFIID riid,void **ppunk);
  void __RPC_STUB IFilter_BindRegion_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifdef __cplusplus
}
#endif
#endif
