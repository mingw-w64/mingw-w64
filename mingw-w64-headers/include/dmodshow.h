/*** Autogenerated by WIDL 10.12 from include/dmodshow.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __dmodshow_h__
#define __dmodshow_h__

/* Forward declarations */

#ifndef __IDMOWrapperFilter_FWD_DEFINED__
#define __IDMOWrapperFilter_FWD_DEFINED__
typedef interface IDMOWrapperFilter IDMOWrapperFilter;
#ifdef __cplusplus
interface IDMOWrapperFilter;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <unknwn.h>

#ifdef __cplusplus
extern "C" {
#endif

DEFINE_GUID(CLSID_DMOWrapperFilter,  0x94297043, 0xbd82, 0x4dfd, 0xb0, 0xde, 0x81, 0x77, 0x73, 0x9c, 0x6d, 0x20);
/*****************************************************************************
 * IDMOWrapperFilter interface
 */
#ifndef __IDMOWrapperFilter_INTERFACE_DEFINED__
#define __IDMOWrapperFilter_INTERFACE_DEFINED__

DEFINE_GUID(IID_IDMOWrapperFilter, 0x52d6f586, 0x9f0f, 0x4824, 0x8f,0xc8, 0xe3,0x2c,0xa0,0x49,0x30,0xc2);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("52d6f586-9f0f-4824-8fc8-e32ca04930c2")
IDMOWrapperFilter : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Init(
        REFCLSID clsidDMO,
        REFCLSID catDMO) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDMOWrapperFilter, 0x52d6f586, 0x9f0f, 0x4824, 0x8f,0xc8, 0xe3,0x2c,0xa0,0x49,0x30,0xc2)
#endif
#else
typedef struct IDMOWrapperFilterVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IDMOWrapperFilter *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IDMOWrapperFilter *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IDMOWrapperFilter *This);

    /*** IDMOWrapperFilter methods ***/
    HRESULT (STDMETHODCALLTYPE *Init)(
        IDMOWrapperFilter *This,
        REFCLSID clsidDMO,
        REFCLSID catDMO);

    END_INTERFACE
} IDMOWrapperFilterVtbl;

interface IDMOWrapperFilter {
    CONST_VTBL IDMOWrapperFilterVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IDMOWrapperFilter_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDMOWrapperFilter_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDMOWrapperFilter_Release(This) (This)->lpVtbl->Release(This)
/*** IDMOWrapperFilter methods ***/
#define IDMOWrapperFilter_Init(This,clsidDMO,catDMO) (This)->lpVtbl->Init(This,clsidDMO,catDMO)
#else
/*** IUnknown methods ***/
static inline HRESULT IDMOWrapperFilter_QueryInterface(IDMOWrapperFilter* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IDMOWrapperFilter_AddRef(IDMOWrapperFilter* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IDMOWrapperFilter_Release(IDMOWrapperFilter* This) {
    return This->lpVtbl->Release(This);
}
/*** IDMOWrapperFilter methods ***/
static inline HRESULT IDMOWrapperFilter_Init(IDMOWrapperFilter* This,REFCLSID clsidDMO,REFCLSID catDMO) {
    return This->lpVtbl->Init(This,clsidDMO,catDMO);
}
#endif
#endif

#endif


#endif  /* __IDMOWrapperFilter_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __dmodshow_h__ */
