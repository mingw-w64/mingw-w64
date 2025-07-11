/*** Autogenerated by WIDL 10.12 from include/activation.idl - Do not edit ***/

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

#ifndef __activation_h__
#define __activation_h__

/* Forward declarations */

#ifndef __IActivationFactory_FWD_DEFINED__
#define __IActivationFactory_FWD_DEFINED__
typedef interface IActivationFactory IActivationFactory;
#ifdef __cplusplus
interface IActivationFactory;
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <inspectable.h>

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * IActivationFactory interface
 */
#ifndef __IActivationFactory_INTERFACE_DEFINED__
#define __IActivationFactory_INTERFACE_DEFINED__

DEFINE_GUID(IID_IActivationFactory, 0x00000035, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("00000035-0000-0000-c000-000000000046")
IActivationFactory : public IInspectable
{
    virtual HRESULT STDMETHODCALLTYPE ActivateInstance(
        IInspectable **instance) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IActivationFactory, 0x00000035, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46)
#endif
#else
typedef struct IActivationFactoryVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IActivationFactory *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IActivationFactory *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IActivationFactory *This);

    /*** IInspectable methods ***/
    HRESULT (STDMETHODCALLTYPE *GetIids)(
        IActivationFactory *This,
        ULONG *iidCount,
        IID **iids);

    HRESULT (STDMETHODCALLTYPE *GetRuntimeClassName)(
        IActivationFactory *This,
        HSTRING *className);

    HRESULT (STDMETHODCALLTYPE *GetTrustLevel)(
        IActivationFactory *This,
        TrustLevel *trustLevel);

    /*** IActivationFactory methods ***/
    HRESULT (STDMETHODCALLTYPE *ActivateInstance)(
        IActivationFactory *This,
        IInspectable **instance);

    END_INTERFACE
} IActivationFactoryVtbl;

interface IActivationFactory {
    CONST_VTBL IActivationFactoryVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IActivationFactory_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActivationFactory_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActivationFactory_Release(This) (This)->lpVtbl->Release(This)
/*** IInspectable methods ***/
#define IActivationFactory_GetIids(This,iidCount,iids) (This)->lpVtbl->GetIids(This,iidCount,iids)
#define IActivationFactory_GetRuntimeClassName(This,className) (This)->lpVtbl->GetRuntimeClassName(This,className)
#define IActivationFactory_GetTrustLevel(This,trustLevel) (This)->lpVtbl->GetTrustLevel(This,trustLevel)
/*** IActivationFactory methods ***/
#define IActivationFactory_ActivateInstance(This,instance) (This)->lpVtbl->ActivateInstance(This,instance)
#else
/*** IUnknown methods ***/
static inline HRESULT IActivationFactory_QueryInterface(IActivationFactory* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG IActivationFactory_AddRef(IActivationFactory* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG IActivationFactory_Release(IActivationFactory* This) {
    return This->lpVtbl->Release(This);
}
/*** IInspectable methods ***/
static inline HRESULT IActivationFactory_GetIids(IActivationFactory* This,ULONG *iidCount,IID **iids) {
    return This->lpVtbl->GetIids(This,iidCount,iids);
}
static inline HRESULT IActivationFactory_GetRuntimeClassName(IActivationFactory* This,HSTRING *className) {
    return This->lpVtbl->GetRuntimeClassName(This,className);
}
static inline HRESULT IActivationFactory_GetTrustLevel(IActivationFactory* This,TrustLevel *trustLevel) {
    return This->lpVtbl->GetTrustLevel(This,trustLevel);
}
/*** IActivationFactory methods ***/
static inline HRESULT IActivationFactory_ActivateInstance(IActivationFactory* This,IInspectable **instance) {
    return This->lpVtbl->ActivateInstance(This,instance);
}
#endif
#endif

#endif


#endif  /* __IActivationFactory_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __activation_h__ */
