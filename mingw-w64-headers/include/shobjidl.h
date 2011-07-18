/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <_mingw_unicode.h>
#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __shobjidl_h__
#define __shobjidl_h__

#ifndef __IPersistFolder_FWD_DEFINED__
#define __IPersistFolder_FWD_DEFINED__
typedef struct IPersistFolder IPersistFolder;
#endif

#ifndef __IPersistFolder2_FWD_DEFINED__
#define __IPersistFolder2_FWD_DEFINED__
typedef struct IPersistFolder2 IPersistFolder2;
#endif

#ifndef __IPersistIDList_FWD_DEFINED__
#define __IPersistIDList_FWD_DEFINED__
typedef struct IPersistIDList IPersistIDList;
#endif

#ifndef __IEnumIDList_FWD_DEFINED__
#define __IEnumIDList_FWD_DEFINED__
typedef struct IEnumIDList IEnumIDList;
#endif

#ifndef __IShellFolder_FWD_DEFINED__
#define __IShellFolder_FWD_DEFINED__
typedef struct IShellFolder IShellFolder;
#endif

#ifndef __IEnumExtraSearch_FWD_DEFINED__
#define __IEnumExtraSearch_FWD_DEFINED__
typedef struct IEnumExtraSearch IEnumExtraSearch;
#endif

#ifndef __IShellFolder2_FWD_DEFINED__
#define __IShellFolder2_FWD_DEFINED__
typedef struct IShellFolder2 IShellFolder2;
#endif

#ifndef __IShellView_FWD_DEFINED__
#define __IShellView_FWD_DEFINED__
typedef struct IShellView IShellView;
#endif

#ifndef __IShellView2_FWD_DEFINED__
#define __IShellView2_FWD_DEFINED__
typedef struct IShellView2 IShellView2;
#endif

#ifndef __IFolderView_FWD_DEFINED__
#define __IFolderView_FWD_DEFINED__
typedef struct IFolderView IFolderView;
#endif

#ifndef __IFolderFilterSite_FWD_DEFINED__
#define __IFolderFilterSite_FWD_DEFINED__
typedef struct IFolderFilterSite IFolderFilterSite;
#endif

#ifndef __IFolderFilter_FWD_DEFINED__
#define __IFolderFilter_FWD_DEFINED__
typedef struct IFolderFilter IFolderFilter;
#endif

#ifndef __IShellBrowser_FWD_DEFINED__
#define __IShellBrowser_FWD_DEFINED__
typedef struct IShellBrowser IShellBrowser;
#endif

#ifndef __IProfferService_FWD_DEFINED__
#define __IProfferService_FWD_DEFINED__
typedef struct IProfferService IProfferService;
#endif

#ifndef __IPropertyUI_FWD_DEFINED__
#define __IPropertyUI_FWD_DEFINED__
typedef struct IPropertyUI IPropertyUI;
#endif

#ifndef __ICategoryProvider_FWD_DEFINED__
#define __ICategoryProvider_FWD_DEFINED__
typedef struct ICategoryProvider ICategoryProvider;
#endif

#ifndef __ICategorizer_FWD_DEFINED__
#define __ICategorizer_FWD_DEFINED__
typedef struct ICategorizer ICategorizer;
#endif

#ifndef __IShellLinkA_FWD_DEFINED__
#define __IShellLinkA_FWD_DEFINED__
typedef struct IShellLinkA IShellLinkA;
#endif

#ifndef __IShellLinkW_FWD_DEFINED__
#define __IShellLinkW_FWD_DEFINED__
typedef struct IShellLinkW IShellLinkW;
#endif

#ifndef __IActionProgressDialog_FWD_DEFINED__
#define __IActionProgressDialog_FWD_DEFINED__
typedef struct IActionProgressDialog IActionProgressDialog;
#endif

#ifndef __IHWEventHandler_FWD_DEFINED__
#define __IHWEventHandler_FWD_DEFINED__
typedef struct IHWEventHandler IHWEventHandler;
#endif

#ifndef __IQueryCancelAutoPlay_FWD_DEFINED__
#define __IQueryCancelAutoPlay_FWD_DEFINED__
typedef struct IQueryCancelAutoPlay IQueryCancelAutoPlay;
#endif

#ifndef __IActionProgress_FWD_DEFINED__
#define __IActionProgress_FWD_DEFINED__
typedef struct IActionProgress IActionProgress;
#endif

#ifndef __IShellExtInit_FWD_DEFINED__
#define __IShellExtInit_FWD_DEFINED__
typedef struct IShellExtInit IShellExtInit;
#endif

#ifndef __IShellPropSheetExt_FWD_DEFINED__
#define __IShellPropSheetExt_FWD_DEFINED__
typedef struct IShellPropSheetExt IShellPropSheetExt;
#endif

#ifndef __IRemoteComputer_FWD_DEFINED__
#define __IRemoteComputer_FWD_DEFINED__
typedef struct IRemoteComputer IRemoteComputer;
#endif

#ifndef __IQueryContinue_FWD_DEFINED__
#define __IQueryContinue_FWD_DEFINED__
typedef struct IQueryContinue IQueryContinue;
#endif

#ifndef __IUserNotification_FWD_DEFINED__
#define __IUserNotification_FWD_DEFINED__
typedef struct IUserNotification IUserNotification;
#endif

#ifndef __IItemNameLimits_FWD_DEFINED__
#define __IItemNameLimits_FWD_DEFINED__
typedef struct IItemNameLimits IItemNameLimits;
#endif

#ifndef __INetCrawler_FWD_DEFINED__
#define __INetCrawler_FWD_DEFINED__
typedef struct INetCrawler INetCrawler;
#endif

#ifndef __IExtractImage_FWD_DEFINED__
#define __IExtractImage_FWD_DEFINED__
typedef struct IExtractImage IExtractImage;
#endif

#ifndef __IExtractImage2_FWD_DEFINED__
#define __IExtractImage2_FWD_DEFINED__
typedef struct IExtractImage2 IExtractImage2;
#endif

#ifndef __IUserEventTimerCallback_FWD_DEFINED__
#define __IUserEventTimerCallback_FWD_DEFINED__
typedef struct IUserEventTimerCallback IUserEventTimerCallback;
#endif

#ifndef __IUserEventTimer_FWD_DEFINED__
#define __IUserEventTimer_FWD_DEFINED__
typedef struct IUserEventTimer IUserEventTimer;
#endif

#ifndef __IDockingWindow_FWD_DEFINED__
#define __IDockingWindow_FWD_DEFINED__
typedef struct IDockingWindow IDockingWindow;
#endif

#ifndef __IDeskBand_FWD_DEFINED__
#define __IDeskBand_FWD_DEFINED__
typedef struct IDeskBand IDeskBand;
#endif

#ifndef __ITaskbarList_FWD_DEFINED__
#define __ITaskbarList_FWD_DEFINED__
typedef struct ITaskbarList ITaskbarList;
#endif

#ifndef __ITaskbarList2_FWD_DEFINED__
#define __ITaskbarList2_FWD_DEFINED__
typedef struct ITaskbarList2 ITaskbarList2;
#endif

#ifndef __ITaskbarList3_FWD_DEFINED__
#define __ITaskbarList3_FWD_DEFINED__
typedef interface ITaskbarList3 ITaskbarList3;
#endif

#ifndef __ITaskbarList4_FWD_DEFINED__
#define __ITaskbarList4_FWD_DEFINED__
typedef interface ITaskbarList4 ITaskbarList4;
#endif

#ifndef __ICDBurn_FWD_DEFINED__
#define __ICDBurn_FWD_DEFINED__
typedef struct ICDBurn ICDBurn;
#endif

#ifndef __IWizardSite_FWD_DEFINED__
#define __IWizardSite_FWD_DEFINED__
typedef struct IWizardSite IWizardSite;
#endif

#ifndef __IWizardExtension_FWD_DEFINED__
#define __IWizardExtension_FWD_DEFINED__
typedef struct IWizardExtension IWizardExtension;
#endif

#ifndef __IWebWizardExtension_FWD_DEFINED__
#define __IWebWizardExtension_FWD_DEFINED__
typedef struct IWebWizardExtension IWebWizardExtension;
#endif

#ifndef __IPublishingWizard_FWD_DEFINED__
#define __IPublishingWizard_FWD_DEFINED__
typedef struct IPublishingWizard IPublishingWizard;
#endif

#ifndef __IFolderViewHost_FWD_DEFINED__
#define __IFolderViewHost_FWD_DEFINED__
typedef struct IFolderViewHost IFolderViewHost;
#endif

#ifndef __IAutoCompleteDropDown_FWD_DEFINED__
#define __IAutoCompleteDropDown_FWD_DEFINED__
typedef struct IAutoCompleteDropDown IAutoCompleteDropDown;
#endif

#ifndef __IModalWindow_FWD_DEFINED__
#define __IModalWindow_FWD_DEFINED__
typedef struct IModalWindow IModalWindow;
#endif

#ifndef __IPassportWizard_FWD_DEFINED__
#define __IPassportWizard_FWD_DEFINED__
typedef struct IPassportWizard IPassportWizard;
#endif

#ifndef __ICDBurnExt_FWD_DEFINED__
#define __ICDBurnExt_FWD_DEFINED__
typedef struct ICDBurnExt ICDBurnExt;
#endif

#ifndef __IDVGetEnum_FWD_DEFINED__
#define __IDVGetEnum_FWD_DEFINED__
typedef struct IDVGetEnum IDVGetEnum;
#endif

#ifndef __IInsertItem_FWD_DEFINED__
#define __IInsertItem_FWD_DEFINED__
typedef struct IInsertItem IInsertItem;
#endif

#ifndef __IDeskBar_FWD_DEFINED__
#define __IDeskBar_FWD_DEFINED__
typedef struct IDeskBar IDeskBar;
#endif

#ifndef __IMenuBand_FWD_DEFINED__
#define __IMenuBand_FWD_DEFINED__
typedef struct IMenuBand IMenuBand;
#endif

#ifndef __IFolderBandPriv_FWD_DEFINED__
#define __IFolderBandPriv_FWD_DEFINED__
typedef struct IFolderBandPriv IFolderBandPriv;
#endif

#ifndef __IBandSite_FWD_DEFINED__
#define __IBandSite_FWD_DEFINED__
typedef struct IBandSite IBandSite;
#endif

#ifndef __INamespaceWalkCB_FWD_DEFINED__
#define __INamespaceWalkCB_FWD_DEFINED__
typedef struct INamespaceWalkCB INamespaceWalkCB;
#endif

#ifndef __INamespaceWalk_FWD_DEFINED__
#define __INamespaceWalk_FWD_DEFINED__
typedef struct INamespaceWalk INamespaceWalk;
#endif

#ifndef __IRegTreeItem_FWD_DEFINED__
#define __IRegTreeItem_FWD_DEFINED__
typedef struct IRegTreeItem IRegTreeItem;
#endif

#ifndef __IMenuPopup_FWD_DEFINED__
#define __IMenuPopup_FWD_DEFINED__
typedef struct IMenuPopup IMenuPopup;
#endif

#ifndef __IShellItem_FWD_DEFINED__
#define __IShellItem_FWD_DEFINED__
typedef struct IShellItem IShellItem;
#endif

#ifndef __IShellItem2_FWD_DEFINED__
#define __IShellItem2_FWD_DEFINED__
typedef interface IShellItem2 IShellItem2;
#endif

#ifndef __IImageRecompress_FWD_DEFINED__
#define __IImageRecompress_FWD_DEFINED__
typedef struct IImageRecompress IImageRecompress;
#endif

#ifndef __IDefViewSafety_FWD_DEFINED__
#define __IDefViewSafety_FWD_DEFINED__
typedef struct IDefViewSafety IDefViewSafety;
#endif

#ifndef __IContextMenuSite_FWD_DEFINED__
#define __IContextMenuSite_FWD_DEFINED__
typedef struct IContextMenuSite IContextMenuSite;
#endif

#ifndef __IDelegateFolder_FWD_DEFINED__
#define __IDelegateFolder_FWD_DEFINED__
typedef struct IDelegateFolder IDelegateFolder;
#endif

#ifndef __IBrowserFrameOptions_FWD_DEFINED__
#define __IBrowserFrameOptions_FWD_DEFINED__
typedef struct IBrowserFrameOptions IBrowserFrameOptions;
#endif

#ifndef __INewWindowManager_FWD_DEFINED__
#define __INewWindowManager_FWD_DEFINED__
typedef struct INewWindowManager INewWindowManager;
#endif

#ifndef __IShellMenuCallback_FWD_DEFINED__
#define __IShellMenuCallback_FWD_DEFINED__
typedef struct IShellMenuCallback IShellMenuCallback;
#endif

#ifndef __IAttachmentExecute_FWD_DEFINED__
#define __IAttachmentExecute_FWD_DEFINED__
typedef struct IAttachmentExecute IAttachmentExecute;
#endif

#ifndef __IShellMenu_FWD_DEFINED__
#define __IShellMenu_FWD_DEFINED__
typedef struct IShellMenu IShellMenu;
#endif

#ifndef __IApplicationAssociationRegistration_FWD_DEFINED__
#define __IApplicationAssociationRegistration_FWD_DEFINED__
typedef interface IApplicationAssociationRegistration IApplicationAssociationRegistration;
#endif

#ifndef __ICustomDestinationList_FWD_DEFINED__
#define __ICustomDestinationList_FWD_DEFINED__
typedef interface ICustomDestinationList ICustomDestinationList;
#endif

#ifndef __QueryCancelAutoPlay_FWD_DEFINED__
#define __QueryCancelAutoPlay_FWD_DEFINED__
#ifdef __cplusplus
typedef class QueryCancelAutoPlay QueryCancelAutoPlay;
#else
typedef struct QueryCancelAutoPlay QueryCancelAutoPlay;
#endif
#endif

#ifndef __DriveSizeCategorizer_FWD_DEFINED__
#define __DriveSizeCategorizer_FWD_DEFINED__
#ifdef __cplusplus
typedef class DriveSizeCategorizer DriveSizeCategorizer;
#else
typedef struct DriveSizeCategorizer DriveSizeCategorizer;
#endif
#endif

#ifndef __DriveTypeCategorizer_FWD_DEFINED__
#define __DriveTypeCategorizer_FWD_DEFINED__
#ifdef __cplusplus
typedef class DriveTypeCategorizer DriveTypeCategorizer;
#else
typedef struct DriveTypeCategorizer DriveTypeCategorizer;
#endif
#endif

#ifndef __FreeSpaceCategorizer_FWD_DEFINED__
#define __FreeSpaceCategorizer_FWD_DEFINED__
#ifdef __cplusplus
typedef class FreeSpaceCategorizer FreeSpaceCategorizer;
#else
typedef struct FreeSpaceCategorizer FreeSpaceCategorizer;
#endif
#endif

#ifndef __TimeCategorizer_FWD_DEFINED__
#define __TimeCategorizer_FWD_DEFINED__
#ifdef __cplusplus
typedef class TimeCategorizer TimeCategorizer;
#else
typedef struct TimeCategorizer TimeCategorizer;
#endif
#endif

#ifndef __SizeCategorizer_FWD_DEFINED__
#define __SizeCategorizer_FWD_DEFINED__
#ifdef __cplusplus
typedef class SizeCategorizer SizeCategorizer;
#else
typedef struct SizeCategorizer SizeCategorizer;
#endif
#endif

#ifndef __AlphabeticalCategorizer_FWD_DEFINED__
#define __AlphabeticalCategorizer_FWD_DEFINED__
#ifdef __cplusplus
typedef class AlphabeticalCategorizer AlphabeticalCategorizer;
#else
typedef struct AlphabeticalCategorizer AlphabeticalCategorizer;
#endif
#endif

#ifndef __MergedCategorizer_FWD_DEFINED__
#define __MergedCategorizer_FWD_DEFINED__
#ifdef __cplusplus
typedef class MergedCategorizer MergedCategorizer;
#else
typedef struct MergedCategorizer MergedCategorizer;
#endif
#endif

#ifndef __ImageProperties_FWD_DEFINED__
#define __ImageProperties_FWD_DEFINED__
#ifdef __cplusplus
typedef class ImageProperties ImageProperties;
#else
typedef struct ImageProperties ImageProperties;
#endif
#endif

#ifndef __PropertiesUI_FWD_DEFINED__
#define __PropertiesUI_FWD_DEFINED__
#ifdef __cplusplus
typedef class PropertiesUI PropertiesUI;
#else
typedef struct PropertiesUI PropertiesUI;
#endif
#endif

#ifndef __UserNotification_FWD_DEFINED__
#define __UserNotification_FWD_DEFINED__
#ifdef __cplusplus
typedef class UserNotification UserNotification;
#else
typedef struct UserNotification UserNotification;
#endif
#endif

#ifndef __UserEventTimerCallback_FWD_DEFINED__
#define __UserEventTimerCallback_FWD_DEFINED__
#ifdef __cplusplus
typedef class UserEventTimerCallback UserEventTimerCallback;
#else
typedef struct UserEventTimerCallback UserEventTimerCallback;
#endif
#endif

#ifndef __UserEventTimer_FWD_DEFINED__
#define __UserEventTimer_FWD_DEFINED__
#ifdef __cplusplus
typedef class UserEventTimer UserEventTimer;
#else
typedef struct UserEventTimer UserEventTimer;
#endif
#endif

#ifndef __NetCrawler_FWD_DEFINED__
#define __NetCrawler_FWD_DEFINED__
#ifdef __cplusplus
typedef class NetCrawler NetCrawler;
#else
typedef struct NetCrawler NetCrawler;
#endif
#endif

#ifndef __CDBurn_FWD_DEFINED__
#define __CDBurn_FWD_DEFINED__
#ifdef __cplusplus
typedef class CDBurn CDBurn;
#else
typedef struct CDBurn CDBurn;
#endif
#endif

#ifndef __TaskbarList_FWD_DEFINED__
#define __TaskbarList_FWD_DEFINED__
#ifdef __cplusplus
typedef class TaskbarList TaskbarList;
#else
typedef struct TaskbarList TaskbarList;
#endif
#endif

#ifndef __WebWizardHost_FWD_DEFINED__
#define __WebWizardHost_FWD_DEFINED__
#ifdef __cplusplus
typedef class WebWizardHost WebWizardHost;
#else
typedef struct WebWizardHost WebWizardHost;
#endif
#endif

#ifndef __PublishDropTarget_FWD_DEFINED__
#define __PublishDropTarget_FWD_DEFINED__
#ifdef __cplusplus
typedef class PublishDropTarget PublishDropTarget;
#else
typedef struct PublishDropTarget PublishDropTarget;
#endif
#endif

#ifndef __PublishingWizard_FWD_DEFINED__
#define __PublishingWizard_FWD_DEFINED__
#ifdef __cplusplus
typedef class PublishingWizard PublishingWizard;
#else
typedef struct PublishingWizard PublishingWizard;
#endif
#endif

#ifndef __InternetPrintOrdering_FWD_DEFINED__
#define __InternetPrintOrdering_FWD_DEFINED__
#ifdef __cplusplus
typedef class InternetPrintOrdering InternetPrintOrdering;
#else
typedef struct InternetPrintOrdering InternetPrintOrdering;
#endif
#endif

#ifndef __FolderViewHost_FWD_DEFINED__
#define __FolderViewHost_FWD_DEFINED__
#ifdef __cplusplus
typedef class FolderViewHost FolderViewHost;
#else
typedef struct FolderViewHost FolderViewHost;
#endif
#endif

#ifndef __NamespaceWalker_FWD_DEFINED__
#define __NamespaceWalker_FWD_DEFINED__
#ifdef __cplusplus
typedef class NamespaceWalker NamespaceWalker;
#else
typedef struct NamespaceWalker NamespaceWalker;
#endif
#endif

#ifndef __ImageRecompress_FWD_DEFINED__
#define __ImageRecompress_FWD_DEFINED__
#ifdef __cplusplus
typedef class ImageRecompress ImageRecompress;
#else
typedef struct ImageRecompress ImageRecompress;
#endif
#endif

#ifndef __TrayBandSiteService_FWD_DEFINED__
#define __TrayBandSiteService_FWD_DEFINED__
#ifdef __cplusplus
typedef class TrayBandSiteService TrayBandSiteService;
#else
typedef struct TrayBandSiteService TrayBandSiteService;
#endif
#endif

#ifndef __PassportWizard_FWD_DEFINED__
#define __PassportWizard_FWD_DEFINED__
#ifdef __cplusplus
typedef class PassportWizard PassportWizard;
#else
typedef struct PassportWizard PassportWizard;
#endif
#endif

#ifndef __AttachmentServices_FWD_DEFINED__
#define __AttachmentServices_FWD_DEFINED__
#ifdef __cplusplus
typedef class AttachmentServices AttachmentServices;
#else
typedef struct AttachmentServices AttachmentServices;
#endif
#endif

#include "objidl.h"
#include "oleidl.h"
#include "oaidl.h"
#include "shtypes.h"
#include "servprov.h"
#include "comcat.h"
#include "propidl.h"
#include "prsht.h"
#include "msxml.h"
#include "propsys.h"
#include "objectarray.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#ifndef _WINRESRC_
#ifndef _WIN32_IE
#define _WIN32_IE 0x0501
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0000_v0_0_s_ifspec;

#ifndef __IPersistFolder_INTERFACE_DEFINED__
#define __IPersistFolder_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IPersistFolder;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IPersistFolder : public IPersist {
  public:
    virtual HRESULT WINAPI Initialize(LPCITEMIDLIST pidl) = 0;
  };
#else
  typedef struct IPersistFolderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IPersistFolder *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IPersistFolder *This);
      ULONG (WINAPI *Release)(IPersistFolder *This);
      HRESULT (WINAPI *GetClassID)(IPersistFolder *This,CLSID *pClassID);
      HRESULT (WINAPI *Initialize)(IPersistFolder *This,LPCITEMIDLIST pidl);
    END_INTERFACE
  } IPersistFolderVtbl;
  struct IPersistFolder {
    CONST_VTBL struct IPersistFolderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IPersistFolder_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPersistFolder_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPersistFolder_Release(This) (This)->lpVtbl->Release(This)
#define IPersistFolder_GetClassID(This,pClassID) (This)->lpVtbl->GetClassID(This,pClassID)
#define IPersistFolder_Initialize(This,pidl) (This)->lpVtbl->Initialize(This,pidl)
#endif
#endif
  HRESULT WINAPI IPersistFolder_Initialize_Proxy(IPersistFolder *This,LPCITEMIDLIST pidl);
  void __RPC_STUB IPersistFolder_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
  typedef IPersistFolder *LPPERSISTFOLDER;

#if (_WIN32_IE >= 0x0400)
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0196_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0196_v0_0_s_ifspec;
#ifndef __IPersistFolder2_INTERFACE_DEFINED__
#define __IPersistFolder2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IPersistFolder2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IPersistFolder2 : public IPersistFolder {
  public:
    virtual HRESULT WINAPI GetCurFolder(LPITEMIDLIST *ppidl) = 0;
  };
#else
  typedef struct IPersistFolder2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IPersistFolder2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IPersistFolder2 *This);
      ULONG (WINAPI *Release)(IPersistFolder2 *This);
      HRESULT (WINAPI *GetClassID)(IPersistFolder2 *This,CLSID *pClassID);
      HRESULT (WINAPI *Initialize)(IPersistFolder2 *This,LPCITEMIDLIST pidl);
      HRESULT (WINAPI *GetCurFolder)(IPersistFolder2 *This,LPITEMIDLIST *ppidl);
    END_INTERFACE
  } IPersistFolder2Vtbl;
  struct IPersistFolder2 {
    CONST_VTBL struct IPersistFolder2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IPersistFolder2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPersistFolder2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPersistFolder2_Release(This) (This)->lpVtbl->Release(This)
#define IPersistFolder2_GetClassID(This,pClassID) (This)->lpVtbl->GetClassID(This,pClassID)
#define IPersistFolder2_Initialize(This,pidl) (This)->lpVtbl->Initialize(This,pidl)
#define IPersistFolder2_GetCurFolder(This,ppidl) (This)->lpVtbl->GetCurFolder(This,ppidl)
#endif
#endif
  HRESULT WINAPI IPersistFolder2_GetCurFolder_Proxy(IPersistFolder2 *This,LPITEMIDLIST *ppidl);
  void __RPC_STUB IPersistFolder2_GetCurFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
  typedef IPersistFolder2 *LPPERSISTFOLDER2;
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0197_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0197_v0_0_s_ifspec;

#ifndef __IPersistIDList_INTERFACE_DEFINED__
#define __IPersistIDList_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IPersistIDList;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IPersistIDList : public IPersist {
  public:
    virtual HRESULT WINAPI SetIDList(LPCITEMIDLIST pidl) = 0;
    virtual HRESULT WINAPI GetIDList(LPITEMIDLIST *ppidl) = 0;
  };
#else
  typedef struct IPersistIDListVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IPersistIDList *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IPersistIDList *This);
      ULONG (WINAPI *Release)(IPersistIDList *This);
      HRESULT (WINAPI *GetClassID)(IPersistIDList *This,CLSID *pClassID);
      HRESULT (WINAPI *SetIDList)(IPersistIDList *This,LPCITEMIDLIST pidl);
      HRESULT (WINAPI *GetIDList)(IPersistIDList *This,LPITEMIDLIST *ppidl);
    END_INTERFACE
  } IPersistIDListVtbl;
  struct IPersistIDList {
    CONST_VTBL struct IPersistIDListVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IPersistIDList_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPersistIDList_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPersistIDList_Release(This) (This)->lpVtbl->Release(This)
#define IPersistIDList_GetClassID(This,pClassID) (This)->lpVtbl->GetClassID(This,pClassID)
#define IPersistIDList_SetIDList(This,pidl) (This)->lpVtbl->SetIDList(This,pidl)
#define IPersistIDList_GetIDList(This,ppidl) (This)->lpVtbl->GetIDList(This,ppidl)
#endif
#endif
  HRESULT WINAPI IPersistIDList_SetIDList_Proxy(IPersistIDList *This,LPCITEMIDLIST pidl);
  void __RPC_STUB IPersistIDList_SetIDList_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPersistIDList_GetIDList_Proxy(IPersistIDList *This,LPITEMIDLIST *ppidl);
  void __RPC_STUB IPersistIDList_GetIDList_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IEnumIDList_INTERFACE_DEFINED__
#define __IEnumIDList_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IEnumIDList;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumIDList : public IUnknown {
  public:
    virtual HRESULT WINAPI Next(ULONG celt,LPITEMIDLIST *rgelt,ULONG *pceltFetched) = 0;
    virtual HRESULT WINAPI Skip(ULONG celt) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Clone(IEnumIDList **ppenum) = 0;
  };
#else
  typedef struct IEnumIDListVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumIDList *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumIDList *This);
      ULONG (WINAPI *Release)(IEnumIDList *This);
      HRESULT (WINAPI *Next)(IEnumIDList *This,ULONG celt,LPITEMIDLIST *rgelt,ULONG *pceltFetched);
      HRESULT (WINAPI *Skip)(IEnumIDList *This,ULONG celt);
      HRESULT (WINAPI *Reset)(IEnumIDList *This);
      HRESULT (WINAPI *Clone)(IEnumIDList *This,IEnumIDList **ppenum);
    END_INTERFACE
  } IEnumIDListVtbl;
  struct IEnumIDList {
    CONST_VTBL struct IEnumIDListVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumIDList_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumIDList_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumIDList_Release(This) (This)->lpVtbl->Release(This)
#define IEnumIDList_Next(This,celt,rgelt,pceltFetched) (This)->lpVtbl->Next(This,celt,rgelt,pceltFetched)
#define IEnumIDList_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#define IEnumIDList_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumIDList_Clone(This,ppenum) (This)->lpVtbl->Clone(This,ppenum)
#endif
#endif
  HRESULT WINAPI IEnumIDList_Next_Proxy(IEnumIDList *This,ULONG celt,LPITEMIDLIST *rgelt,ULONG *pceltFetched);
  void __RPC_STUB IEnumIDList_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumIDList_Skip_Proxy(IEnumIDList *This,ULONG celt);
  void __RPC_STUB IEnumIDList_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumIDList_Reset_Proxy(IEnumIDList *This);
  void __RPC_STUB IEnumIDList_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumIDList_Clone_Proxy(IEnumIDList *This,IEnumIDList **ppenum);
  void __RPC_STUB IEnumIDList_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef IEnumIDList *LPENUMIDLIST;

  enum _SHGDNF {
    SHGDN_NORMAL = 0x0000,SHGDN_INFOLDER = 0x0001,SHGDN_FOREDITING = 0x1000,SHGDN_FORADDRESSBAR = 0x4000,SHGDN_FORPARSING = 0x8000
  };
  typedef DWORD SHGDNF;

  enum _SHCONTF {
    SHCONTF_FOLDERS = 0x0020,SHCONTF_NONFOLDERS = 0x0040,SHCONTF_INCLUDEHIDDEN = 0x0080,SHCONTF_INIT_ON_FIRST_NEXT = 0x0100,
    SHCONTF_NETPRINTERSRCH = 0x0200,SHCONTF_SHAREABLE = 0x0400,SHCONTF_STORAGE = 0x0800
  };
  typedef DWORD SHCONTF;

#define SHCIDS_ALLFIELDS 0x80000000L
#define SHCIDS_CANONICALONLY 0x10000000L
#define SHCIDS_BITMASK 0xFFFF0000L
#define SHCIDS_COLUMNMASK 0x0000FFFFL
#define SFGAO_CANCOPY DROPEFFECT_COPY
#define SFGAO_CANMOVE DROPEFFECT_MOVE
#define SFGAO_CANLINK DROPEFFECT_LINK
#define SFGAO_STORAGE 0x00000008L
#define SFGAO_CANRENAME 0x00000010L
#define SFGAO_CANDELETE 0x00000020L
#define SFGAO_HASPROPSHEET 0x00000040L
#define SFGAO_DROPTARGET 0x00000100L
#define SFGAO_CAPABILITYMASK 0x00000177L
#define SFGAO_ENCRYPTED 0x00002000L
#define SFGAO_ISSLOW 0x00004000L
#define SFGAO_GHOSTED 0x00008000L
#define SFGAO_LINK 0x00010000L
#define SFGAO_SHARE 0x00020000L
#define SFGAO_READONLY 0x00040000L
#define SFGAO_HIDDEN 0x00080000L
#define SFGAO_DISPLAYATTRMASK 0x000FC000L
#define SFGAO_FILESYSANCESTOR 0x10000000L
#define SFGAO_FOLDER 0x20000000L
#define SFGAO_FILESYSTEM 0x40000000L
#define SFGAO_HASSUBFOLDER 0x80000000L
#define SFGAO_CONTENTSMASK 0x80000000L
#define SFGAO_VALIDATE 0x01000000L
#define SFGAO_REMOVABLE 0x02000000L
#define SFGAO_COMPRESSED 0x04000000L
#define SFGAO_BROWSABLE 0x08000000L
#define SFGAO_NONENUMERATED 0x00100000L
#define SFGAO_NEWCONTENT 0x00200000L
#define SFGAO_CANMONIKER 0x00400000L
#define SFGAO_HASSTORAGE 0x00400000L
#define SFGAO_STREAM 0x00400000L
#define SFGAO_STORAGEANCESTOR 0x00800000L
#define SFGAO_STORAGECAPMASK 0x70C50008L
  typedef ULONG SFGAOF;

#define STR_SKIP_BINDING_CLSID L"Skip Binding CLSID"
#define STR_PARSE_PREFER_FOLDER_BROWSING L"Parse Prefer Folder Browsing"
#define STR_DONT_PARSE_RELATIVE L"Don't Parse Relative"
#define STR_PARSE_TRANSLATE_ALIASES L"Parse Translate Aliases"
#define STR_PARSE_SHELL_PROTOCOL_TO_FILE_OBJECTS L"Parse Shell Protocol To File Objects"

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0199_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0199_v0_0_s_ifspec;
#ifndef __IShellFolder_INTERFACE_DEFINED__
#define __IShellFolder_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellFolder;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellFolder : public IUnknown {
  public:
    virtual HRESULT WINAPI ParseDisplayName(HWND hwnd,LPBC pbc,LPOLESTR pszDisplayName,ULONG *pchEaten,LPITEMIDLIST *ppidl,ULONG *pdwAttributes) = 0;
    virtual HRESULT WINAPI EnumObjects(HWND hwnd,SHCONTF grfFlags,IEnumIDList **ppenumIDList) = 0;
    virtual HRESULT WINAPI BindToObject(LPCITEMIDLIST pidl,LPBC pbc,REFIID riid,void **ppv) = 0;
    virtual HRESULT WINAPI BindToStorage(LPCITEMIDLIST pidl,LPBC pbc,REFIID riid,void **ppv) = 0;
    virtual HRESULT WINAPI CompareIDs(LPARAM lParam,LPCITEMIDLIST pidl1,LPCITEMIDLIST pidl2) = 0;
    virtual HRESULT WINAPI CreateViewObject(HWND hwndOwner,REFIID riid,void **ppv) = 0;
    virtual HRESULT WINAPI GetAttributesOf(UINT cidl,LPCITEMIDLIST *apidl,SFGAOF *rgfInOut) = 0;
    virtual HRESULT WINAPI GetUIObjectOf(HWND hwndOwner,UINT cidl,LPCITEMIDLIST *apidl,REFIID riid,UINT *rgfReserved,void **ppv) = 0;
    virtual HRESULT WINAPI GetDisplayNameOf(LPCITEMIDLIST pidl,SHGDNF uFlags,STRRET *pName) = 0;
    virtual HRESULT WINAPI SetNameOf(HWND hwnd,LPCITEMIDLIST pidl,LPCOLESTR pszName,SHGDNF uFlags,LPITEMIDLIST *ppidlOut) = 0;
  };
#else
  typedef struct IShellFolderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellFolder *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellFolder *This);
      ULONG (WINAPI *Release)(IShellFolder *This);
      HRESULT (WINAPI *ParseDisplayName)(IShellFolder *This,HWND hwnd,LPBC pbc,LPOLESTR pszDisplayName,ULONG *pchEaten,LPITEMIDLIST *ppidl,ULONG *pdwAttributes);
      HRESULT (WINAPI *EnumObjects)(IShellFolder *This,HWND hwnd,SHCONTF grfFlags,IEnumIDList **ppenumIDList);
      HRESULT (WINAPI *BindToObject)(IShellFolder *This,LPCITEMIDLIST pidl,LPBC pbc,REFIID riid,void **ppv);
      HRESULT (WINAPI *BindToStorage)(IShellFolder *This,LPCITEMIDLIST pidl,LPBC pbc,REFIID riid,void **ppv);
      HRESULT (WINAPI *CompareIDs)(IShellFolder *This,LPARAM lParam,LPCITEMIDLIST pidl1,LPCITEMIDLIST pidl2);
      HRESULT (WINAPI *CreateViewObject)(IShellFolder *This,HWND hwndOwner,REFIID riid,void **ppv);
      HRESULT (WINAPI *GetAttributesOf)(IShellFolder *This,UINT cidl,LPCITEMIDLIST *apidl,SFGAOF *rgfInOut);
      HRESULT (WINAPI *GetUIObjectOf)(IShellFolder *This,HWND hwndOwner,UINT cidl,LPCITEMIDLIST *apidl,REFIID riid,UINT *rgfReserved,void **ppv);
      HRESULT (WINAPI *GetDisplayNameOf)(IShellFolder *This,LPCITEMIDLIST pidl,SHGDNF uFlags,STRRET *pName);
      HRESULT (WINAPI *SetNameOf)(IShellFolder *This,HWND hwnd,LPCITEMIDLIST pidl,LPCOLESTR pszName,SHGDNF uFlags,LPITEMIDLIST *ppidlOut);
    END_INTERFACE
  } IShellFolderVtbl;
  struct IShellFolder {
    CONST_VTBL struct IShellFolderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellFolder_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellFolder_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellFolder_Release(This) (This)->lpVtbl->Release(This)
#define IShellFolder_ParseDisplayName(This,hwnd,pbc,pszDisplayName,pchEaten,ppidl,pdwAttributes) (This)->lpVtbl->ParseDisplayName(This,hwnd,pbc,pszDisplayName,pchEaten,ppidl,pdwAttributes)
#define IShellFolder_EnumObjects(This,hwnd,grfFlags,ppenumIDList) (This)->lpVtbl->EnumObjects(This,hwnd,grfFlags,ppenumIDList)
#define IShellFolder_BindToObject(This,pidl,pbc,riid,ppv) (This)->lpVtbl->BindToObject(This,pidl,pbc,riid,ppv)
#define IShellFolder_BindToStorage(This,pidl,pbc,riid,ppv) (This)->lpVtbl->BindToStorage(This,pidl,pbc,riid,ppv)
#define IShellFolder_CompareIDs(This,lParam,pidl1,pidl2) (This)->lpVtbl->CompareIDs(This,lParam,pidl1,pidl2)
#define IShellFolder_CreateViewObject(This,hwndOwner,riid,ppv) (This)->lpVtbl->CreateViewObject(This,hwndOwner,riid,ppv)
#define IShellFolder_GetAttributesOf(This,cidl,apidl,rgfInOut) (This)->lpVtbl->GetAttributesOf(This,cidl,apidl,rgfInOut)
#define IShellFolder_GetUIObjectOf(This,hwndOwner,cidl,apidl,riid,rgfReserved,ppv) (This)->lpVtbl->GetUIObjectOf(This,hwndOwner,cidl,apidl,riid,rgfReserved,ppv)
#define IShellFolder_GetDisplayNameOf(This,pidl,uFlags,pName) (This)->lpVtbl->GetDisplayNameOf(This,pidl,uFlags,pName)
#define IShellFolder_SetNameOf(This,hwnd,pidl,pszName,uFlags,ppidlOut) (This)->lpVtbl->SetNameOf(This,hwnd,pidl,pszName,uFlags,ppidlOut)
#endif
#endif
  HRESULT WINAPI IShellFolder_ParseDisplayName_Proxy(IShellFolder *This,HWND hwnd,LPBC pbc,LPOLESTR pszDisplayName,ULONG *pchEaten,LPITEMIDLIST *ppidl,ULONG *pdwAttributes);
  void __RPC_STUB IShellFolder_ParseDisplayName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder_EnumObjects_Proxy(IShellFolder *This,HWND hwnd,SHCONTF grfFlags,IEnumIDList **ppenumIDList);
  void __RPC_STUB IShellFolder_EnumObjects_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder_BindToObject_Proxy(IShellFolder *This,LPCITEMIDLIST pidl,LPBC pbc,REFIID riid,void **ppv);
  void __RPC_STUB IShellFolder_BindToObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder_BindToStorage_Proxy(IShellFolder *This,LPCITEMIDLIST pidl,LPBC pbc,REFIID riid,void **ppv);
  void __RPC_STUB IShellFolder_BindToStorage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder_CompareIDs_Proxy(IShellFolder *This,LPARAM lParam,LPCITEMIDLIST pidl1,LPCITEMIDLIST pidl2);
  void __RPC_STUB IShellFolder_CompareIDs_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder_CreateViewObject_Proxy(IShellFolder *This,HWND hwndOwner,REFIID riid,void **ppv);
  void __RPC_STUB IShellFolder_CreateViewObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder_GetAttributesOf_Proxy(IShellFolder *This,UINT cidl,LPCITEMIDLIST *apidl,SFGAOF *rgfInOut);
  void __RPC_STUB IShellFolder_GetAttributesOf_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder_GetUIObjectOf_Proxy(IShellFolder *This,HWND hwndOwner,UINT cidl,LPCITEMIDLIST *apidl,REFIID riid,UINT *rgfReserved,void **ppv);
  void __RPC_STUB IShellFolder_GetUIObjectOf_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder_GetDisplayNameOf_Proxy(IShellFolder *This,LPCITEMIDLIST pidl,SHGDNF uFlags,STRRET *pName);
  void __RPC_STUB IShellFolder_GetDisplayNameOf_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder_SetNameOf_Proxy(IShellFolder *This,HWND hwnd,LPCITEMIDLIST pidl,LPCOLESTR pszName,SHGDNF uFlags,LPITEMIDLIST *ppidlOut);
  void __RPC_STUB IShellFolder_SetNameOf_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef IShellFolder *LPSHELLFOLDER;

#if (_WIN32_IE >= 0x0500)
  typedef struct tagEXTRASEARCH {
    GUID guidSearch;
    WCHAR wszFriendlyName[80];
    WCHAR wszUrl[2084];
  } EXTRASEARCH;
  typedef struct tagEXTRASEARCH *LPEXTRASEARCH;
  typedef struct IEnumExtraSearch *LPENUMEXTRASEARCH;

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0200_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0200_v0_0_s_ifspec;

#ifndef __IEnumExtraSearch_INTERFACE_DEFINED__
#define __IEnumExtraSearch_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IEnumExtraSearch;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumExtraSearch : public IUnknown {
  public:
    virtual HRESULT WINAPI Next(ULONG celt,EXTRASEARCH *rgelt,ULONG *pceltFetched) = 0;
    virtual HRESULT WINAPI Skip(ULONG celt) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Clone(IEnumExtraSearch **ppenum) = 0;
  };
#else
  typedef struct IEnumExtraSearchVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumExtraSearch *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumExtraSearch *This);
      ULONG (WINAPI *Release)(IEnumExtraSearch *This);
      HRESULT (WINAPI *Next)(IEnumExtraSearch *This,ULONG celt,EXTRASEARCH *rgelt,ULONG *pceltFetched);
      HRESULT (WINAPI *Skip)(IEnumExtraSearch *This,ULONG celt);
      HRESULT (WINAPI *Reset)(IEnumExtraSearch *This);
      HRESULT (WINAPI *Clone)(IEnumExtraSearch *This,IEnumExtraSearch **ppenum);
    END_INTERFACE
  } IEnumExtraSearchVtbl;
  struct IEnumExtraSearch {
    CONST_VTBL struct IEnumExtraSearchVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumExtraSearch_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumExtraSearch_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumExtraSearch_Release(This) (This)->lpVtbl->Release(This)
#define IEnumExtraSearch_Next(This,celt,rgelt,pceltFetched) (This)->lpVtbl->Next(This,celt,rgelt,pceltFetched)
#define IEnumExtraSearch_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#define IEnumExtraSearch_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumExtraSearch_Clone(This,ppenum) (This)->lpVtbl->Clone(This,ppenum)
#endif
#endif
  HRESULT WINAPI IEnumExtraSearch_Next_Proxy(IEnumExtraSearch *This,ULONG celt,EXTRASEARCH *rgelt,ULONG *pceltFetched);
  void __RPC_STUB IEnumExtraSearch_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumExtraSearch_Skip_Proxy(IEnumExtraSearch *This,ULONG celt);
  void __RPC_STUB IEnumExtraSearch_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumExtraSearch_Reset_Proxy(IEnumExtraSearch *This);
  void __RPC_STUB IEnumExtraSearch_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumExtraSearch_Clone_Proxy(IEnumExtraSearch *This,IEnumExtraSearch **ppenum);
  void __RPC_STUB IEnumExtraSearch_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0201_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0201_v0_0_s_ifspec;
#ifndef __IShellFolder2_INTERFACE_DEFINED__
#define __IShellFolder2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellFolder2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellFolder2 : public IShellFolder {
  public:
    virtual HRESULT WINAPI GetDefaultSearchGUID(GUID *pguid) = 0;
    virtual HRESULT WINAPI EnumSearches(IEnumExtraSearch **ppenum) = 0;
    virtual HRESULT WINAPI GetDefaultColumn(DWORD dwRes,ULONG *pSort,ULONG *pDisplay) = 0;
    virtual HRESULT WINAPI GetDefaultColumnState(UINT iColumn,SHCOLSTATEF *pcsFlags) = 0;
    virtual HRESULT WINAPI GetDetailsEx(LPCITEMIDLIST pidl,const SHCOLUMNID *pscid,VARIANT *pv) = 0;
    virtual HRESULT WINAPI GetDetailsOf(LPCITEMIDLIST pidl,UINT iColumn,SHELLDETAILS *psd) = 0;
    virtual HRESULT WINAPI MapColumnToSCID(UINT iColumn,SHCOLUMNID *pscid) = 0;
  };
#else
  typedef struct IShellFolder2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellFolder2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellFolder2 *This);
      ULONG (WINAPI *Release)(IShellFolder2 *This);
      HRESULT (WINAPI *ParseDisplayName)(IShellFolder2 *This,HWND hwnd,LPBC pbc,LPOLESTR pszDisplayName,ULONG *pchEaten,LPITEMIDLIST *ppidl,ULONG *pdwAttributes);
      HRESULT (WINAPI *EnumObjects)(IShellFolder2 *This,HWND hwnd,SHCONTF grfFlags,IEnumIDList **ppenumIDList);
      HRESULT (WINAPI *BindToObject)(IShellFolder2 *This,LPCITEMIDLIST pidl,LPBC pbc,REFIID riid,void **ppv);
      HRESULT (WINAPI *BindToStorage)(IShellFolder2 *This,LPCITEMIDLIST pidl,LPBC pbc,REFIID riid,void **ppv);
      HRESULT (WINAPI *CompareIDs)(IShellFolder2 *This,LPARAM lParam,LPCITEMIDLIST pidl1,LPCITEMIDLIST pidl2);
      HRESULT (WINAPI *CreateViewObject)(IShellFolder2 *This,HWND hwndOwner,REFIID riid,void **ppv);
      HRESULT (WINAPI *GetAttributesOf)(IShellFolder2 *This,UINT cidl,LPCITEMIDLIST *apidl,SFGAOF *rgfInOut);
      HRESULT (WINAPI *GetUIObjectOf)(IShellFolder2 *This,HWND hwndOwner,UINT cidl,LPCITEMIDLIST *apidl,REFIID riid,UINT *rgfReserved,void **ppv);
      HRESULT (WINAPI *GetDisplayNameOf)(IShellFolder2 *This,LPCITEMIDLIST pidl,SHGDNF uFlags,STRRET *pName);
      HRESULT (WINAPI *SetNameOf)(IShellFolder2 *This,HWND hwnd,LPCITEMIDLIST pidl,LPCOLESTR pszName,SHGDNF uFlags,LPITEMIDLIST *ppidlOut);
      HRESULT (WINAPI *GetDefaultSearchGUID)(IShellFolder2 *This,GUID *pguid);
      HRESULT (WINAPI *EnumSearches)(IShellFolder2 *This,IEnumExtraSearch **ppenum);
      HRESULT (WINAPI *GetDefaultColumn)(IShellFolder2 *This,DWORD dwRes,ULONG *pSort,ULONG *pDisplay);
      HRESULT (WINAPI *GetDefaultColumnState)(IShellFolder2 *This,UINT iColumn,SHCOLSTATEF *pcsFlags);
      HRESULT (WINAPI *GetDetailsEx)(IShellFolder2 *This,LPCITEMIDLIST pidl,const SHCOLUMNID *pscid,VARIANT *pv);
      HRESULT (WINAPI *GetDetailsOf)(IShellFolder2 *This,LPCITEMIDLIST pidl,UINT iColumn,SHELLDETAILS *psd);
      HRESULT (WINAPI *MapColumnToSCID)(IShellFolder2 *This,UINT iColumn,SHCOLUMNID *pscid);
    END_INTERFACE
  } IShellFolder2Vtbl;
  struct IShellFolder2 {
    CONST_VTBL struct IShellFolder2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellFolder2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellFolder2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellFolder2_Release(This) (This)->lpVtbl->Release(This)
#define IShellFolder2_ParseDisplayName(This,hwnd,pbc,pszDisplayName,pchEaten,ppidl,pdwAttributes) (This)->lpVtbl->ParseDisplayName(This,hwnd,pbc,pszDisplayName,pchEaten,ppidl,pdwAttributes)
#define IShellFolder2_EnumObjects(This,hwnd,grfFlags,ppenumIDList) (This)->lpVtbl->EnumObjects(This,hwnd,grfFlags,ppenumIDList)
#define IShellFolder2_BindToObject(This,pidl,pbc,riid,ppv) (This)->lpVtbl->BindToObject(This,pidl,pbc,riid,ppv)
#define IShellFolder2_BindToStorage(This,pidl,pbc,riid,ppv) (This)->lpVtbl->BindToStorage(This,pidl,pbc,riid,ppv)
#define IShellFolder2_CompareIDs(This,lParam,pidl1,pidl2) (This)->lpVtbl->CompareIDs(This,lParam,pidl1,pidl2)
#define IShellFolder2_CreateViewObject(This,hwndOwner,riid,ppv) (This)->lpVtbl->CreateViewObject(This,hwndOwner,riid,ppv)
#define IShellFolder2_GetAttributesOf(This,cidl,apidl,rgfInOut) (This)->lpVtbl->GetAttributesOf(This,cidl,apidl,rgfInOut)
#define IShellFolder2_GetUIObjectOf(This,hwndOwner,cidl,apidl,riid,rgfReserved,ppv) (This)->lpVtbl->GetUIObjectOf(This,hwndOwner,cidl,apidl,riid,rgfReserved,ppv)
#define IShellFolder2_GetDisplayNameOf(This,pidl,uFlags,pName) (This)->lpVtbl->GetDisplayNameOf(This,pidl,uFlags,pName)
#define IShellFolder2_SetNameOf(This,hwnd,pidl,pszName,uFlags,ppidlOut) (This)->lpVtbl->SetNameOf(This,hwnd,pidl,pszName,uFlags,ppidlOut)
#define IShellFolder2_GetDefaultSearchGUID(This,pguid) (This)->lpVtbl->GetDefaultSearchGUID(This,pguid)
#define IShellFolder2_EnumSearches(This,ppenum) (This)->lpVtbl->EnumSearches(This,ppenum)
#define IShellFolder2_GetDefaultColumn(This,dwRes,pSort,pDisplay) (This)->lpVtbl->GetDefaultColumn(This,dwRes,pSort,pDisplay)
#define IShellFolder2_GetDefaultColumnState(This,iColumn,pcsFlags) (This)->lpVtbl->GetDefaultColumnState(This,iColumn,pcsFlags)
#define IShellFolder2_GetDetailsEx(This,pidl,pscid,pv) (This)->lpVtbl->GetDetailsEx(This,pidl,pscid,pv)
#define IShellFolder2_GetDetailsOf(This,pidl,iColumn,psd) (This)->lpVtbl->GetDetailsOf(This,pidl,iColumn,psd)
#define IShellFolder2_MapColumnToSCID(This,iColumn,pscid) (This)->lpVtbl->MapColumnToSCID(This,iColumn,pscid)
#endif
#endif
  HRESULT WINAPI IShellFolder2_GetDefaultSearchGUID_Proxy(IShellFolder2 *This,GUID *pguid);
  void __RPC_STUB IShellFolder2_GetDefaultSearchGUID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder2_EnumSearches_Proxy(IShellFolder2 *This,IEnumExtraSearch **ppenum);
  void __RPC_STUB IShellFolder2_EnumSearches_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder2_GetDefaultColumn_Proxy(IShellFolder2 *This,DWORD dwRes,ULONG *pSort,ULONG *pDisplay);
  void __RPC_STUB IShellFolder2_GetDefaultColumn_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder2_GetDefaultColumnState_Proxy(IShellFolder2 *This,UINT iColumn,SHCOLSTATEF *pcsFlags);
  void __RPC_STUB IShellFolder2_GetDefaultColumnState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder2_GetDetailsEx_Proxy(IShellFolder2 *This,LPCITEMIDLIST pidl,const SHCOLUMNID *pscid,VARIANT *pv);
  void __RPC_STUB IShellFolder2_GetDetailsEx_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder2_GetDetailsOf_Proxy(IShellFolder2 *This,LPCITEMIDLIST pidl,UINT iColumn,SHELLDETAILS *psd);
  void __RPC_STUB IShellFolder2_GetDetailsOf_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolder2_MapColumnToSCID_Proxy(IShellFolder2 *This,UINT iColumn,SHCOLUMNID *pscid);
  void __RPC_STUB IShellFolder2_MapColumnToSCID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif
  typedef char *LPVIEWSETTINGS;

  typedef enum __MIDL___MIDL_itf_shobjidl_0202_0001 {
    FWF_AUTOARRANGE = 0x1,FWF_ABBREVIATEDNAMES = 0x2,FWF_SNAPTOGRID = 0x4,FWF_OWNERDATA = 0x8,FWF_BESTFITWINDOW = 0x10,FWF_DESKTOP = 0x20,
    FWF_SINGLESEL = 0x40,FWF_NOSUBFOLDERS = 0x80,FWF_TRANSPARENT = 0x100,FWF_NOCLIENTEDGE = 0x200,FWF_NOSCROLL = 0x400,FWF_ALIGNLEFT = 0x800,
    FWF_NOICONS = 0x1000,FWF_SHOWSELALWAYS = 0x2000,FWF_NOVISIBLE = 0x4000,FWF_SINGLECLICKACTIVATE = 0x8000,FWF_NOWEBVIEW = 0x10000,
    FWF_HIDEFILENAMES = 0x20000,FWF_CHECKSELECT = 0x40000
  } FOLDERFLAGS;

  typedef enum __MIDL___MIDL_itf_shobjidl_0202_0002 {
    FVM_FIRST = 1,FVM_ICON = 1,FVM_SMALLICON = 2,FVM_LIST = 3,FVM_DETAILS = 4,FVM_THUMBNAIL = 5,FVM_TILE = 6,FVM_THUMBSTRIP = 7,FVM_LAST = 7
  } FOLDERVIEWMODE;

  typedef struct __MIDL___MIDL_itf_shobjidl_0202_0003 {
    UINT ViewMode;
    UINT fFlags;
  } FOLDERSETTINGS;

  typedef FOLDERSETTINGS *LPFOLDERSETTINGS;
  typedef const FOLDERSETTINGS *LPCFOLDERSETTINGS;
  typedef FOLDERSETTINGS *PFOLDERSETTINGS;

#define SVSI_DESELECT 0x00000000
#define SVSI_SELECT 0x00000001
#define SVSI_EDIT 0x00000003
#define SVSI_DESELECTOTHERS 0x00000004
#define SVSI_ENSUREVISIBLE 0x00000008
#define SVSI_FOCUSED 0x00000010
#define SVSI_TRANSLATEPT 0x00000020
#define SVSI_SELECTIONMARK 0x00000040
#define SVSI_POSITIONITEM 0x00000080
#define SVSI_CHECK 0x00000100
#define SVSI_NOSTATECHANGE 0x80000000
  typedef UINT SVSIF;

  typedef enum __MIDL___MIDL_itf_shobjidl_0202_0004 {
    SVGIO_BACKGROUND = 0,SVGIO_SELECTION = 0x1,SVGIO_ALLVIEW = 0x2,SVGIO_CHECKED = 0x3,SVGIO_TYPE_MASK = 0xf,SVGIO_FLAG_VIEWORDER = 0x80000000
  } SVGIO;

  typedef enum __MIDL___MIDL_itf_shobjidl_0202_0005 {
    SVUIA_DEACTIVATE = 0,SVUIA_ACTIVATE_NOFOCUS = 1,SVUIA_ACTIVATE_FOCUS = 2,SVUIA_INPLACEACTIVATE = 3
  } SVUIA_STATUS;

#ifdef _FIX_ENABLEMODELESS_CONFLICT
#define EnableModeless EnableModelessSV
#endif
#ifdef _NEVER_
  typedef LPARAM LPFNSVADDPROPSHEETPAGE;
#else
#include <prsht.h>
  typedef LPFNADDPROPSHEETPAGE LPFNSVADDPROPSHEETPAGE;
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0202_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0202_v0_0_s_ifspec;
#ifndef __IShellView_INTERFACE_DEFINED__
#define __IShellView_INTERFACE_DEFINED__
  typedef IShellView *LPSHELLVIEW;

  EXTERN_C const IID IID_IShellView;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellView : public IOleWindow {
  public:
    virtual HRESULT WINAPI TranslateAccelerator(MSG *pmsg) = 0;
    virtual HRESULT WINAPI EnableModeless(WINBOOL fEnable) = 0;
    virtual HRESULT WINAPI UIActivate(UINT uState) = 0;
    virtual HRESULT WINAPI Refresh(void) = 0;
    virtual HRESULT WINAPI CreateViewWindow(IShellView *psvPrevious,LPCFOLDERSETTINGS pfs,IShellBrowser *psb,RECT *prcView,HWND *phWnd) = 0;
    virtual HRESULT WINAPI DestroyViewWindow(void) = 0;
    virtual HRESULT WINAPI GetCurrentInfo(LPFOLDERSETTINGS pfs) = 0;
    virtual HRESULT WINAPI AddPropertySheetPages(DWORD dwReserved,LPFNSVADDPROPSHEETPAGE pfn,LPARAM lparam) = 0;
    virtual HRESULT WINAPI SaveViewState(void) = 0;
    virtual HRESULT WINAPI SelectItem(LPCITEMIDLIST pidlItem,SVSIF uFlags) = 0;
    virtual HRESULT WINAPI GetItemObject(UINT uItem,REFIID riid,void **ppv) = 0;
  };
#else
  typedef struct IShellViewVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellView *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellView *This);
      ULONG (WINAPI *Release)(IShellView *This);
      HRESULT (WINAPI *GetWindow)(IShellView *This,HWND *phwnd);
      HRESULT (WINAPI *ContextSensitiveHelp)(IShellView *This,WINBOOL fEnterMode);
      HRESULT (WINAPI *TranslateAccelerator)(IShellView *This,MSG *pmsg);
      HRESULT (WINAPI *EnableModeless)(IShellView *This,WINBOOL fEnable);
      HRESULT (WINAPI *UIActivate)(IShellView *This,UINT uState);
      HRESULT (WINAPI *Refresh)(IShellView *This);
      HRESULT (WINAPI *CreateViewWindow)(IShellView *This,IShellView *psvPrevious,LPCFOLDERSETTINGS pfs,IShellBrowser *psb,RECT *prcView,HWND *phWnd);
      HRESULT (WINAPI *DestroyViewWindow)(IShellView *This);
      HRESULT (WINAPI *GetCurrentInfo)(IShellView *This,LPFOLDERSETTINGS pfs);
      HRESULT (WINAPI *AddPropertySheetPages)(IShellView *This,DWORD dwReserved,LPFNSVADDPROPSHEETPAGE pfn,LPARAM lparam);
      HRESULT (WINAPI *SaveViewState)(IShellView *This);
      HRESULT (WINAPI *SelectItem)(IShellView *This,LPCITEMIDLIST pidlItem,SVSIF uFlags);
      HRESULT (WINAPI *GetItemObject)(IShellView *This,UINT uItem,REFIID riid,void **ppv);
    END_INTERFACE
  } IShellViewVtbl;
  struct IShellView {
    CONST_VTBL struct IShellViewVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellView_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellView_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellView_Release(This) (This)->lpVtbl->Release(This)
#define IShellView_GetWindow(This,phwnd) (This)->lpVtbl->GetWindow(This,phwnd)
#define IShellView_ContextSensitiveHelp(This,fEnterMode) (This)->lpVtbl->ContextSensitiveHelp(This,fEnterMode)
#define IShellView_TranslateAccelerator(This,pmsg) (This)->lpVtbl->TranslateAccelerator(This,pmsg)
#define IShellView_EnableModeless(This,fEnable) (This)->lpVtbl->EnableModeless(This,fEnable)
#define IShellView_UIActivate(This,uState) (This)->lpVtbl->UIActivate(This,uState)
#define IShellView_Refresh(This) (This)->lpVtbl->Refresh(This)
#define IShellView_CreateViewWindow(This,psvPrevious,pfs,psb,prcView,phWnd) (This)->lpVtbl->CreateViewWindow(This,psvPrevious,pfs,psb,prcView,phWnd)
#define IShellView_DestroyViewWindow(This) (This)->lpVtbl->DestroyViewWindow(This)
#define IShellView_GetCurrentInfo(This,pfs) (This)->lpVtbl->GetCurrentInfo(This,pfs)
#define IShellView_AddPropertySheetPages(This,dwReserved,pfn,lparam) (This)->lpVtbl->AddPropertySheetPages(This,dwReserved,pfn,lparam)
#define IShellView_SaveViewState(This) (This)->lpVtbl->SaveViewState(This)
#define IShellView_SelectItem(This,pidlItem,uFlags) (This)->lpVtbl->SelectItem(This,pidlItem,uFlags)
#define IShellView_GetItemObject(This,uItem,riid,ppv) (This)->lpVtbl->GetItemObject(This,uItem,riid,ppv)
#endif
#endif
  HRESULT WINAPI IShellView_TranslateAccelerator_Proxy(IShellView *This,MSG *pmsg);
  void __RPC_STUB IShellView_TranslateAccelerator_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_EnableModeless_Proxy(IShellView *This,WINBOOL fEnable);
  void __RPC_STUB IShellView_EnableModeless_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_UIActivate_Proxy(IShellView *This,UINT uState);
  void __RPC_STUB IShellView_UIActivate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_Refresh_Proxy(IShellView *This);
  void __RPC_STUB IShellView_Refresh_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_CreateViewWindow_Proxy(IShellView *This,IShellView *psvPrevious,LPCFOLDERSETTINGS pfs,IShellBrowser *psb,RECT *prcView,HWND *phWnd);
  void __RPC_STUB IShellView_CreateViewWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_DestroyViewWindow_Proxy(IShellView *This);
  void __RPC_STUB IShellView_DestroyViewWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_GetCurrentInfo_Proxy(IShellView *This,LPFOLDERSETTINGS pfs);
  void __RPC_STUB IShellView_GetCurrentInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_AddPropertySheetPages_Proxy(IShellView *This,DWORD dwReserved,LPFNSVADDPROPSHEETPAGE pfn,LPARAM lparam);
  void __RPC_STUB IShellView_AddPropertySheetPages_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_SaveViewState_Proxy(IShellView *This);
  void __RPC_STUB IShellView_SaveViewState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_SelectItem_Proxy(IShellView *This,LPCITEMIDLIST pidlItem,SVSIF uFlags);
  void __RPC_STUB IShellView_SelectItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView_GetItemObject_Proxy(IShellView *This,UINT uItem,REFIID riid,void **ppv);
  void __RPC_STUB IShellView_GetItemObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellView2_INTERFACE_DEFINED__
#define __IShellView2_INTERFACE_DEFINED__
  typedef GUID SHELLVIEWID;

#define SV2GV_CURRENTVIEW ((UINT)-1)
#define SV2GV_DEFAULTVIEW ((UINT)-2)
#include <pshpack8.h>
  typedef struct _SV2CVW2_PARAMS {
    DWORD cbSize;
    IShellView *psvPrev;
    LPCFOLDERSETTINGS pfs;
    IShellBrowser *psbOwner;
    RECT *prcView;
    const SHELLVIEWID *pvid;
    HWND hwndView;
  } SV2CVW2_PARAMS;

  typedef struct _SV2CVW2_PARAMS *LPSV2CVW2_PARAMS;

#include <poppack.h>

  EXTERN_C const IID IID_IShellView2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellView2 : public IShellView {
  public:
    virtual HRESULT WINAPI GetView(SHELLVIEWID *pvid,ULONG uView) = 0;
    virtual HRESULT WINAPI CreateViewWindow2(LPSV2CVW2_PARAMS lpParams) = 0;
    virtual HRESULT WINAPI HandleRename(LPCITEMIDLIST pidlNew) = 0;
    virtual HRESULT WINAPI SelectAndPositionItem(LPCITEMIDLIST pidlItem,UINT uFlags,POINT *ppt) = 0;
  };
#else
  typedef struct IShellView2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellView2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellView2 *This);
      ULONG (WINAPI *Release)(IShellView2 *This);
      HRESULT (WINAPI *GetWindow)(IShellView2 *This,HWND *phwnd);
      HRESULT (WINAPI *ContextSensitiveHelp)(IShellView2 *This,WINBOOL fEnterMode);
      HRESULT (WINAPI *TranslateAccelerator)(IShellView2 *This,MSG *pmsg);
      HRESULT (WINAPI *EnableModeless)(IShellView2 *This,WINBOOL fEnable);
      HRESULT (WINAPI *UIActivate)(IShellView2 *This,UINT uState);
      HRESULT (WINAPI *Refresh)(IShellView2 *This);
      HRESULT (WINAPI *CreateViewWindow)(IShellView2 *This,IShellView *psvPrevious,LPCFOLDERSETTINGS pfs,IShellBrowser *psb,RECT *prcView,HWND *phWnd);
      HRESULT (WINAPI *DestroyViewWindow)(IShellView2 *This);
      HRESULT (WINAPI *GetCurrentInfo)(IShellView2 *This,LPFOLDERSETTINGS pfs);
      HRESULT (WINAPI *AddPropertySheetPages)(IShellView2 *This,DWORD dwReserved,LPFNSVADDPROPSHEETPAGE pfn,LPARAM lparam);
      HRESULT (WINAPI *SaveViewState)(IShellView2 *This);
      HRESULT (WINAPI *SelectItem)(IShellView2 *This,LPCITEMIDLIST pidlItem,SVSIF uFlags);
      HRESULT (WINAPI *GetItemObject)(IShellView2 *This,UINT uItem,REFIID riid,void **ppv);
      HRESULT (WINAPI *GetView)(IShellView2 *This,SHELLVIEWID *pvid,ULONG uView);
      HRESULT (WINAPI *CreateViewWindow2)(IShellView2 *This,LPSV2CVW2_PARAMS lpParams);
      HRESULT (WINAPI *HandleRename)(IShellView2 *This,LPCITEMIDLIST pidlNew);
      HRESULT (WINAPI *SelectAndPositionItem)(IShellView2 *This,LPCITEMIDLIST pidlItem,UINT uFlags,POINT *ppt);
    END_INTERFACE
  } IShellView2Vtbl;
  struct IShellView2 {
    CONST_VTBL struct IShellView2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellView2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellView2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellView2_Release(This) (This)->lpVtbl->Release(This)
#define IShellView2_GetWindow(This,phwnd) (This)->lpVtbl->GetWindow(This,phwnd)
#define IShellView2_ContextSensitiveHelp(This,fEnterMode) (This)->lpVtbl->ContextSensitiveHelp(This,fEnterMode)
#define IShellView2_TranslateAccelerator(This,pmsg) (This)->lpVtbl->TranslateAccelerator(This,pmsg)
#define IShellView2_EnableModeless(This,fEnable) (This)->lpVtbl->EnableModeless(This,fEnable)
#define IShellView2_UIActivate(This,uState) (This)->lpVtbl->UIActivate(This,uState)
#define IShellView2_Refresh(This) (This)->lpVtbl->Refresh(This)
#define IShellView2_CreateViewWindow(This,psvPrevious,pfs,psb,prcView,phWnd) (This)->lpVtbl->CreateViewWindow(This,psvPrevious,pfs,psb,prcView,phWnd)
#define IShellView2_DestroyViewWindow(This) (This)->lpVtbl->DestroyViewWindow(This)
#define IShellView2_GetCurrentInfo(This,pfs) (This)->lpVtbl->GetCurrentInfo(This,pfs)
#define IShellView2_AddPropertySheetPages(This,dwReserved,pfn,lparam) (This)->lpVtbl->AddPropertySheetPages(This,dwReserved,pfn,lparam)
#define IShellView2_SaveViewState(This) (This)->lpVtbl->SaveViewState(This)
#define IShellView2_SelectItem(This,pidlItem,uFlags) (This)->lpVtbl->SelectItem(This,pidlItem,uFlags)
#define IShellView2_GetItemObject(This,uItem,riid,ppv) (This)->lpVtbl->GetItemObject(This,uItem,riid,ppv)
#define IShellView2_GetView(This,pvid,uView) (This)->lpVtbl->GetView(This,pvid,uView)
#define IShellView2_CreateViewWindow2(This,lpParams) (This)->lpVtbl->CreateViewWindow2(This,lpParams)
#define IShellView2_HandleRename(This,pidlNew) (This)->lpVtbl->HandleRename(This,pidlNew)
#define IShellView2_SelectAndPositionItem(This,pidlItem,uFlags,ppt) (This)->lpVtbl->SelectAndPositionItem(This,pidlItem,uFlags,ppt)
#endif
#endif
  HRESULT WINAPI IShellView2_GetView_Proxy(IShellView2 *This,SHELLVIEWID *pvid,ULONG uView);
  void __RPC_STUB IShellView2_GetView_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView2_CreateViewWindow2_Proxy(IShellView2 *This,LPSV2CVW2_PARAMS lpParams);
  void __RPC_STUB IShellView2_CreateViewWindow2_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView2_HandleRename_Proxy(IShellView2 *This,LPCITEMIDLIST pidlNew);
  void __RPC_STUB IShellView2_HandleRename_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellView2_SelectAndPositionItem_Proxy(IShellView2 *This,LPCITEMIDLIST pidlItem,UINT uFlags,POINT *ppt);
  void __RPC_STUB IShellView2_SelectAndPositionItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IFolderView_INTERFACE_DEFINED__
#define __IFolderView_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IFolderView;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IFolderView : public IUnknown {
  public:
    virtual HRESULT WINAPI GetCurrentViewMode(UINT *pViewMode) = 0;
    virtual HRESULT WINAPI SetCurrentViewMode(UINT ViewMode) = 0;
    virtual HRESULT WINAPI GetFolder(REFIID riid,void **ppv) = 0;
    virtual HRESULT WINAPI Item(int iItemIndex,LPITEMIDLIST *ppidl) = 0;
    virtual HRESULT WINAPI ItemCount(UINT uFlags,int *pcItems) = 0;
    virtual HRESULT WINAPI Items(UINT uFlags,REFIID riid,void **ppv) = 0;
    virtual HRESULT WINAPI GetSelectionMarkedItem(int *piItem) = 0;
    virtual HRESULT WINAPI GetFocusedItem(int *piItem) = 0;
    virtual HRESULT WINAPI GetItemPosition(LPCITEMIDLIST pidl,POINT *ppt) = 0;
    virtual HRESULT WINAPI GetSpacing(POINT *ppt) = 0;
    virtual HRESULT WINAPI GetDefaultSpacing(POINT *ppt) = 0;
    virtual HRESULT WINAPI GetAutoArrange(void) = 0;
    virtual HRESULT WINAPI SelectItem(int iItem,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI SelectAndPositionItems(UINT cidl,LPCITEMIDLIST *apidl,POINT *apt,DWORD dwFlags) = 0;
  };
#else
  typedef struct IFolderViewVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IFolderView *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IFolderView *This);
      ULONG (WINAPI *Release)(IFolderView *This);
      HRESULT (WINAPI *GetCurrentViewMode)(IFolderView *This,UINT *pViewMode);
      HRESULT (WINAPI *SetCurrentViewMode)(IFolderView *This,UINT ViewMode);
      HRESULT (WINAPI *GetFolder)(IFolderView *This,REFIID riid,void **ppv);
      HRESULT (WINAPI *Item)(IFolderView *This,int iItemIndex,LPITEMIDLIST *ppidl);
      HRESULT (WINAPI *ItemCount)(IFolderView *This,UINT uFlags,int *pcItems);
      HRESULT (WINAPI *Items)(IFolderView *This,UINT uFlags,REFIID riid,void **ppv);
      HRESULT (WINAPI *GetSelectionMarkedItem)(IFolderView *This,int *piItem);
      HRESULT (WINAPI *GetFocusedItem)(IFolderView *This,int *piItem);
      HRESULT (WINAPI *GetItemPosition)(IFolderView *This,LPCITEMIDLIST pidl,POINT *ppt);
      HRESULT (WINAPI *GetSpacing)(IFolderView *This,POINT *ppt);
      HRESULT (WINAPI *GetDefaultSpacing)(IFolderView *This,POINT *ppt);
      HRESULT (WINAPI *GetAutoArrange)(IFolderView *This);
      HRESULT (WINAPI *SelectItem)(IFolderView *This,int iItem,DWORD dwFlags);
      HRESULT (WINAPI *SelectAndPositionItems)(IFolderView *This,UINT cidl,LPCITEMIDLIST *apidl,POINT *apt,DWORD dwFlags);
    END_INTERFACE
  } IFolderViewVtbl;
  struct IFolderView {
    CONST_VTBL struct IFolderViewVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IFolderView_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFolderView_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFolderView_Release(This) (This)->lpVtbl->Release(This)
#define IFolderView_GetCurrentViewMode(This,pViewMode) (This)->lpVtbl->GetCurrentViewMode(This,pViewMode)
#define IFolderView_SetCurrentViewMode(This,ViewMode) (This)->lpVtbl->SetCurrentViewMode(This,ViewMode)
#define IFolderView_GetFolder(This,riid,ppv) (This)->lpVtbl->GetFolder(This,riid,ppv)
#define IFolderView_Item(This,iItemIndex,ppidl) (This)->lpVtbl->Item(This,iItemIndex,ppidl)
#define IFolderView_ItemCount(This,uFlags,pcItems) (This)->lpVtbl->ItemCount(This,uFlags,pcItems)
#define IFolderView_Items(This,uFlags,riid,ppv) (This)->lpVtbl->Items(This,uFlags,riid,ppv)
#define IFolderView_GetSelectionMarkedItem(This,piItem) (This)->lpVtbl->GetSelectionMarkedItem(This,piItem)
#define IFolderView_GetFocusedItem(This,piItem) (This)->lpVtbl->GetFocusedItem(This,piItem)
#define IFolderView_GetItemPosition(This,pidl,ppt) (This)->lpVtbl->GetItemPosition(This,pidl,ppt)
#define IFolderView_GetSpacing(This,ppt) (This)->lpVtbl->GetSpacing(This,ppt)
#define IFolderView_GetDefaultSpacing(This,ppt) (This)->lpVtbl->GetDefaultSpacing(This,ppt)
#define IFolderView_GetAutoArrange(This) (This)->lpVtbl->GetAutoArrange(This)
#define IFolderView_SelectItem(This,iItem,dwFlags) (This)->lpVtbl->SelectItem(This,iItem,dwFlags)
#define IFolderView_SelectAndPositionItems(This,cidl,apidl,apt,dwFlags) (This)->lpVtbl->SelectAndPositionItems(This,cidl,apidl,apt,dwFlags)
#endif
#endif
  HRESULT WINAPI IFolderView_GetCurrentViewMode_Proxy(IFolderView *This,UINT *pViewMode);
  void __RPC_STUB IFolderView_GetCurrentViewMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_SetCurrentViewMode_Proxy(IFolderView *This,UINT ViewMode);
  void __RPC_STUB IFolderView_SetCurrentViewMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_GetFolder_Proxy(IFolderView *This,REFIID riid,void **ppv);
  void __RPC_STUB IFolderView_GetFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_Item_Proxy(IFolderView *This,int iItemIndex,LPITEMIDLIST *ppidl);
  void __RPC_STUB IFolderView_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_ItemCount_Proxy(IFolderView *This,UINT uFlags,int *pcItems);
  void __RPC_STUB IFolderView_ItemCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_Items_Proxy(IFolderView *This,UINT uFlags,REFIID riid,void **ppv);
  void __RPC_STUB IFolderView_Items_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_GetSelectionMarkedItem_Proxy(IFolderView *This,int *piItem);
  void __RPC_STUB IFolderView_GetSelectionMarkedItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_GetFocusedItem_Proxy(IFolderView *This,int *piItem);
  void __RPC_STUB IFolderView_GetFocusedItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_GetItemPosition_Proxy(IFolderView *This,LPCITEMIDLIST pidl,POINT *ppt);
  void __RPC_STUB IFolderView_GetItemPosition_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_GetSpacing_Proxy(IFolderView *This,POINT *ppt);
  void __RPC_STUB IFolderView_GetSpacing_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_GetDefaultSpacing_Proxy(IFolderView *This,POINT *ppt);
  void __RPC_STUB IFolderView_GetDefaultSpacing_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_GetAutoArrange_Proxy(IFolderView *This);
  void __RPC_STUB IFolderView_GetAutoArrange_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_SelectItem_Proxy(IFolderView *This,int iItem,DWORD dwFlags);
  void __RPC_STUB IFolderView_SelectItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderView_SelectAndPositionItems_Proxy(IFolderView *This,UINT cidl,LPCITEMIDLIST *apidl,POINT *apt,DWORD dwFlags);
  void __RPC_STUB IFolderView_SelectAndPositionItems_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define SID_SFolderView IID_IFolderView
#ifdef _FIX_ENABLEMODELESS_CONFLICT
#undef EnableModeless
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0205_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0205_v0_0_s_ifspec;
#ifndef __IFolderFilterSite_INTERFACE_DEFINED__
#define __IFolderFilterSite_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IFolderFilterSite;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IFolderFilterSite : public IUnknown {
  public:
    virtual HRESULT WINAPI SetFilter(IUnknown *punk) = 0;
  };
#else
  typedef struct IFolderFilterSiteVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IFolderFilterSite *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IFolderFilterSite *This);
      ULONG (WINAPI *Release)(IFolderFilterSite *This);
      HRESULT (WINAPI *SetFilter)(IFolderFilterSite *This,IUnknown *punk);
    END_INTERFACE
  } IFolderFilterSiteVtbl;
  struct IFolderFilterSite {
    CONST_VTBL struct IFolderFilterSiteVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IFolderFilterSite_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFolderFilterSite_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFolderFilterSite_Release(This) (This)->lpVtbl->Release(This)
#define IFolderFilterSite_SetFilter(This,punk) (This)->lpVtbl->SetFilter(This,punk)
#endif
#endif
  HRESULT WINAPI IFolderFilterSite_SetFilter_Proxy(IFolderFilterSite *This,IUnknown *punk);
  void __RPC_STUB IFolderFilterSite_SetFilter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IFolderFilter_INTERFACE_DEFINED__
#define __IFolderFilter_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IFolderFilter;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IFolderFilter : public IUnknown {
  public:
    virtual HRESULT WINAPI ShouldShow(IShellFolder *psf,LPCITEMIDLIST pidlFolder,LPCITEMIDLIST pidlItem) = 0;
    virtual HRESULT WINAPI GetEnumFlags(IShellFolder *psf,LPCITEMIDLIST pidlFolder,HWND *phwnd,DWORD *pgrfFlags) = 0;
  };
#else
  typedef struct IFolderFilterVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IFolderFilter *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IFolderFilter *This);
      ULONG (WINAPI *Release)(IFolderFilter *This);
      HRESULT (WINAPI *ShouldShow)(IFolderFilter *This,IShellFolder *psf,LPCITEMIDLIST pidlFolder,LPCITEMIDLIST pidlItem);
      HRESULT (WINAPI *GetEnumFlags)(IFolderFilter *This,IShellFolder *psf,LPCITEMIDLIST pidlFolder,HWND *phwnd,DWORD *pgrfFlags);
    END_INTERFACE
  } IFolderFilterVtbl;
  struct IFolderFilter {
    CONST_VTBL struct IFolderFilterVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IFolderFilter_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFolderFilter_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFolderFilter_Release(This) (This)->lpVtbl->Release(This)
#define IFolderFilter_ShouldShow(This,psf,pidlFolder,pidlItem) (This)->lpVtbl->ShouldShow(This,psf,pidlFolder,pidlItem)
#define IFolderFilter_GetEnumFlags(This,psf,pidlFolder,phwnd,pgrfFlags) (This)->lpVtbl->GetEnumFlags(This,psf,pidlFolder,phwnd,pgrfFlags)
#endif
#endif
  HRESULT WINAPI IFolderFilter_ShouldShow_Proxy(IFolderFilter *This,IShellFolder *psf,LPCITEMIDLIST pidlFolder,LPCITEMIDLIST pidlItem);
  void __RPC_STUB IFolderFilter_ShouldShow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderFilter_GetEnumFlags_Proxy(IFolderFilter *This,IShellFolder *psf,LPCITEMIDLIST pidlFolder,HWND *phwnd,DWORD *pgrfFlags);
  void __RPC_STUB IFolderFilter_GetEnumFlags_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define SBSP_DEFBROWSER 0x0000
#define SBSP_SAMEBROWSER 0x0001
#define SBSP_NEWBROWSER 0x0002
#define SBSP_DEFMODE 0x0000
#define SBSP_OPENMODE 0x0010
#define SBSP_EXPLOREMODE 0x0020
#define SBSP_HELPMODE 0x0040
#define SBSP_NOTRANSFERHIST 0x0080
#define SBSP_ABSOLUTE 0x0000
#define SBSP_RELATIVE 0x1000
#define SBSP_PARENT 0x2000
#define SBSP_NAVIGATEBACK 0x4000
#define SBSP_NAVIGATEFORWARD 0x8000
#define SBSP_ALLOW_AUTONAVIGATE 0x10000
#define SBSP_CALLERUNTRUSTED 0x00800000
#define SBSP_TRUSTFIRSTDOWNLOAD 0x01000000
#define SBSP_UNTRUSTEDFORDOWNLOAD 0x02000000
#define SBSP_NOAUTOSELECT 0x04000000
#define SBSP_WRITENOHISTORY 0x08000000
#define SBSP_TRUSTEDFORACTIVEX 0x10000000
#define SBSP_REDIRECT 0x40000000
#define SBSP_INITIATEDBYHLINKFRAME 0x80000000
#define FCW_STATUS 0x0001
#define FCW_TOOLBAR 0x0002
#define FCW_TREE 0x0003
#define FCW_INTERNETBAR 0x0006
#define FCW_PROGRESS 0x0008
#define FCT_MERGE 0x0001
#define FCT_CONFIGABLE 0x0002
#define FCT_ADDTOEND 0x0004
#ifdef _NEVER_
  typedef LPARAM LPTBBUTTONSB;
#else
#include <commctrl.h>
  typedef LPTBBUTTON LPTBBUTTONSB;
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0207_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0207_v0_0_s_ifspec;
#ifndef __IShellBrowser_INTERFACE_DEFINED__
#define __IShellBrowser_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellBrowser;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellBrowser : public IOleWindow {
  public:
    virtual HRESULT WINAPI InsertMenusSB(HMENU hmenuShared,LPOLEMENUGROUPWIDTHS lpMenuWidths) = 0;
    virtual HRESULT WINAPI SetMenuSB(HMENU hmenuShared,HOLEMENU holemenuRes,HWND hwndActiveObject) = 0;
    virtual HRESULT WINAPI RemoveMenusSB(HMENU hmenuShared) = 0;
    virtual HRESULT WINAPI SetStatusTextSB(LPCOLESTR pszStatusText) = 0;
    virtual HRESULT WINAPI EnableModelessSB(WINBOOL fEnable) = 0;
    virtual HRESULT WINAPI TranslateAcceleratorSB(MSG *pmsg,WORD wID) = 0;
    virtual HRESULT WINAPI BrowseObject(LPCITEMIDLIST pidl,UINT wFlags) = 0;
    virtual HRESULT WINAPI GetViewStateStream(DWORD grfMode,IStream **ppStrm) = 0;
    virtual HRESULT WINAPI GetControlWindow(UINT id,HWND *phwnd) = 0;
    virtual HRESULT WINAPI SendControlMsg(UINT id,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *pret) = 0;
    virtual HRESULT WINAPI QueryActiveShellView(IShellView **ppshv) = 0;
    virtual HRESULT WINAPI OnViewWindowActive(IShellView *pshv) = 0;
    virtual HRESULT WINAPI SetToolbarItems(LPTBBUTTONSB lpButtons,UINT nButtons,UINT uFlags) = 0;
  };
#else
  typedef struct IShellBrowserVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellBrowser *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellBrowser *This);
      ULONG (WINAPI *Release)(IShellBrowser *This);
      HRESULT (WINAPI *GetWindow)(IShellBrowser *This,HWND *phwnd);
      HRESULT (WINAPI *ContextSensitiveHelp)(IShellBrowser *This,WINBOOL fEnterMode);
      HRESULT (WINAPI *InsertMenusSB)(IShellBrowser *This,HMENU hmenuShared,LPOLEMENUGROUPWIDTHS lpMenuWidths);
      HRESULT (WINAPI *SetMenuSB)(IShellBrowser *This,HMENU hmenuShared,HOLEMENU holemenuRes,HWND hwndActiveObject);
      HRESULT (WINAPI *RemoveMenusSB)(IShellBrowser *This,HMENU hmenuShared);
      HRESULT (WINAPI *SetStatusTextSB)(IShellBrowser *This,LPCOLESTR pszStatusText);
      HRESULT (WINAPI *EnableModelessSB)(IShellBrowser *This,WINBOOL fEnable);
      HRESULT (WINAPI *TranslateAcceleratorSB)(IShellBrowser *This,MSG *pmsg,WORD wID);
      HRESULT (WINAPI *BrowseObject)(IShellBrowser *This,LPCITEMIDLIST pidl,UINT wFlags);
      HRESULT (WINAPI *GetViewStateStream)(IShellBrowser *This,DWORD grfMode,IStream **ppStrm);
      HRESULT (WINAPI *GetControlWindow)(IShellBrowser *This,UINT id,HWND *phwnd);
      HRESULT (WINAPI *SendControlMsg)(IShellBrowser *This,UINT id,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *pret);
      HRESULT (WINAPI *QueryActiveShellView)(IShellBrowser *This,IShellView **ppshv);
      HRESULT (WINAPI *OnViewWindowActive)(IShellBrowser *This,IShellView *pshv);
      HRESULT (WINAPI *SetToolbarItems)(IShellBrowser *This,LPTBBUTTONSB lpButtons,UINT nButtons,UINT uFlags);
    END_INTERFACE
  } IShellBrowserVtbl;
  struct IShellBrowser {
    CONST_VTBL struct IShellBrowserVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellBrowser_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellBrowser_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellBrowser_Release(This) (This)->lpVtbl->Release(This)
#define IShellBrowser_GetWindow(This,phwnd) (This)->lpVtbl->GetWindow(This,phwnd)
#define IShellBrowser_ContextSensitiveHelp(This,fEnterMode) (This)->lpVtbl->ContextSensitiveHelp(This,fEnterMode)
#define IShellBrowser_InsertMenusSB(This,hmenuShared,lpMenuWidths) (This)->lpVtbl->InsertMenusSB(This,hmenuShared,lpMenuWidths)
#define IShellBrowser_SetMenuSB(This,hmenuShared,holemenuRes,hwndActiveObject) (This)->lpVtbl->SetMenuSB(This,hmenuShared,holemenuRes,hwndActiveObject)
#define IShellBrowser_RemoveMenusSB(This,hmenuShared) (This)->lpVtbl->RemoveMenusSB(This,hmenuShared)
#define IShellBrowser_SetStatusTextSB(This,pszStatusText) (This)->lpVtbl->SetStatusTextSB(This,pszStatusText)
#define IShellBrowser_EnableModelessSB(This,fEnable) (This)->lpVtbl->EnableModelessSB(This,fEnable)
#define IShellBrowser_TranslateAcceleratorSB(This,pmsg,wID) (This)->lpVtbl->TranslateAcceleratorSB(This,pmsg,wID)
#define IShellBrowser_BrowseObject(This,pidl,wFlags) (This)->lpVtbl->BrowseObject(This,pidl,wFlags)
#define IShellBrowser_GetViewStateStream(This,grfMode,ppStrm) (This)->lpVtbl->GetViewStateStream(This,grfMode,ppStrm)
#define IShellBrowser_GetControlWindow(This,id,phwnd) (This)->lpVtbl->GetControlWindow(This,id,phwnd)
#define IShellBrowser_SendControlMsg(This,id,uMsg,wParam,lParam,pret) (This)->lpVtbl->SendControlMsg(This,id,uMsg,wParam,lParam,pret)
#define IShellBrowser_QueryActiveShellView(This,ppshv) (This)->lpVtbl->QueryActiveShellView(This,ppshv)
#define IShellBrowser_OnViewWindowActive(This,pshv) (This)->lpVtbl->OnViewWindowActive(This,pshv)
#define IShellBrowser_SetToolbarItems(This,lpButtons,nButtons,uFlags) (This)->lpVtbl->SetToolbarItems(This,lpButtons,nButtons,uFlags)
#endif
#endif
  HRESULT WINAPI IShellBrowser_InsertMenusSB_Proxy(IShellBrowser *This,HMENU hmenuShared,LPOLEMENUGROUPWIDTHS lpMenuWidths);
  void __RPC_STUB IShellBrowser_InsertMenusSB_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_SetMenuSB_Proxy(IShellBrowser *This,HMENU hmenuShared,HOLEMENU holemenuRes,HWND hwndActiveObject);
  void __RPC_STUB IShellBrowser_SetMenuSB_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_RemoveMenusSB_Proxy(IShellBrowser *This,HMENU hmenuShared);
  void __RPC_STUB IShellBrowser_RemoveMenusSB_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_SetStatusTextSB_Proxy(IShellBrowser *This,LPCOLESTR pszStatusText);
  void __RPC_STUB IShellBrowser_SetStatusTextSB_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_EnableModelessSB_Proxy(IShellBrowser *This,WINBOOL fEnable);
  void __RPC_STUB IShellBrowser_EnableModelessSB_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_TranslateAcceleratorSB_Proxy(IShellBrowser *This,MSG *pmsg,WORD wID);
  void __RPC_STUB IShellBrowser_TranslateAcceleratorSB_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_BrowseObject_Proxy(IShellBrowser *This,LPCITEMIDLIST pidl,UINT wFlags);
  void __RPC_STUB IShellBrowser_BrowseObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_GetViewStateStream_Proxy(IShellBrowser *This,DWORD grfMode,IStream **ppStrm);
  void __RPC_STUB IShellBrowser_GetViewStateStream_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_GetControlWindow_Proxy(IShellBrowser *This,UINT id,HWND *phwnd);
  void __RPC_STUB IShellBrowser_GetControlWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_SendControlMsg_Proxy(IShellBrowser *This,UINT id,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *pret);
  void __RPC_STUB IShellBrowser_SendControlMsg_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_QueryActiveShellView_Proxy(IShellBrowser *This,IShellView **ppshv);
  void __RPC_STUB IShellBrowser_QueryActiveShellView_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_OnViewWindowActive_Proxy(IShellBrowser *This,IShellView *pshv);
  void __RPC_STUB IShellBrowser_OnViewWindowActive_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellBrowser_SetToolbarItems_Proxy(IShellBrowser *This,LPTBBUTTONSB lpButtons,UINT nButtons,UINT uFlags);
  void __RPC_STUB IShellBrowser_SetToolbarItems_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef IShellBrowser *LPSHELLBROWSER;

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0208_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0208_v0_0_s_ifspec;
#ifndef __IProfferService_INTERFACE_DEFINED__
#define __IProfferService_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IProfferService;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IProfferService : public IUnknown {
  public:
    virtual HRESULT WINAPI ProfferService(REFGUID rguidService,IServiceProvider *psp,DWORD *pdwCookie) = 0;
    virtual HRESULT WINAPI RevokeService(DWORD dwCookie) = 0;
  };
#else
  typedef struct IProfferServiceVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IProfferService *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IProfferService *This);
      ULONG (WINAPI *Release)(IProfferService *This);
      HRESULT (WINAPI *ProfferService)(IProfferService *This,REFGUID rguidService,IServiceProvider *psp,DWORD *pdwCookie);
      HRESULT (WINAPI *RevokeService)(IProfferService *This,DWORD dwCookie);
    END_INTERFACE
  } IProfferServiceVtbl;
  struct IProfferService {
    CONST_VTBL struct IProfferServiceVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IProfferService_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IProfferService_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IProfferService_Release(This) (This)->lpVtbl->Release(This)
#define IProfferService_ProfferService(This,rguidService,psp,pdwCookie) (This)->lpVtbl->ProfferService(This,rguidService,psp,pdwCookie)
#define IProfferService_RevokeService(This,dwCookie) (This)->lpVtbl->RevokeService(This,dwCookie)
#endif
#endif
  HRESULT WINAPI IProfferService_ProfferService_Proxy(IProfferService *This,REFGUID rguidService,IServiceProvider *psp,DWORD *pdwCookie);
  void __RPC_STUB IProfferService_ProfferService_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IProfferService_RevokeService_Proxy(IProfferService *This,DWORD dwCookie);
  void __RPC_STUB IProfferService_RevokeService_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define SID_SProfferService IID_IProfferService
  typedef enum __MIDL___MIDL_itf_shobjidl_0209_0001 {
    PUIFNF_DEFAULT = 0,PUIFNF_MNEMONIC = 0x1
  } PROPERTYUI_NAME_FLAGS;

  typedef enum __MIDL___MIDL_itf_shobjidl_0209_0002 {
    PUIF_DEFAULT = 0,PUIF_RIGHTALIGN = 0x1,PUIF_NOLABELININFOTIP = 0x2
  } PROPERTYUI_FLAGS;

  typedef enum __MIDL___MIDL_itf_shobjidl_0209_0003 {
    PUIFFDF_DEFAULT = 0,PUIFFDF_RIGHTTOLEFT = 0x1,PUIFFDF_SHORTFORMAT = 0x2,PUIFFDF_NOTIME = 0x4,PUIFFDF_FRIENDLYDATE = 0x8,PUIFFDF_NOUNITS = 0x10
  } PROPERTYUI_FORMAT_FLAGS;

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0209_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0209_v0_0_s_ifspec;
#ifndef __IPropertyUI_INTERFACE_DEFINED__
#define __IPropertyUI_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IPropertyUI;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IPropertyUI : public IUnknown {
  public:
    virtual HRESULT WINAPI ParsePropertyName(LPCWSTR pszName,FMTID *pfmtid,PROPID *ppid,ULONG *pchEaten) = 0;
    virtual HRESULT WINAPI GetCannonicalName(REFFMTID fmtid,PROPID pid,LPWSTR pwszText,DWORD cchText) = 0;
    virtual HRESULT WINAPI GetDisplayName(REFFMTID fmtid,PROPID pid,PROPERTYUI_NAME_FLAGS flags,LPWSTR pwszText,DWORD cchText) = 0;
    virtual HRESULT WINAPI GetPropertyDescription(REFFMTID fmtid,PROPID pid,LPWSTR pwszText,DWORD cchText) = 0;
    virtual HRESULT WINAPI GetDefaultWidth(REFFMTID fmtid,PROPID pid,ULONG *pcxChars) = 0;
    virtual HRESULT WINAPI GetFlags(REFFMTID fmtid,PROPID pid,PROPERTYUI_FLAGS *pFlags) = 0;
    virtual HRESULT WINAPI FormatForDisplay(REFFMTID fmtid,PROPID pid,const PROPVARIANT *pvar,PROPERTYUI_FORMAT_FLAGS flags,LPWSTR pwszText,DWORD cchText) = 0;
    virtual HRESULT WINAPI GetHelpInfo(REFFMTID fmtid,PROPID pid,LPWSTR pwszHelpFile,DWORD cch,UINT *puHelpID) = 0;
  };
#else
  typedef struct IPropertyUIVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IPropertyUI *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IPropertyUI *This);
      ULONG (WINAPI *Release)(IPropertyUI *This);
      HRESULT (WINAPI *ParsePropertyName)(IPropertyUI *This,LPCWSTR pszName,FMTID *pfmtid,PROPID *ppid,ULONG *pchEaten);
      HRESULT (WINAPI *GetCannonicalName)(IPropertyUI *This,REFFMTID fmtid,PROPID pid,LPWSTR pwszText,DWORD cchText);
      HRESULT (WINAPI *GetDisplayName)(IPropertyUI *This,REFFMTID fmtid,PROPID pid,PROPERTYUI_NAME_FLAGS flags,LPWSTR pwszText,DWORD cchText);
      HRESULT (WINAPI *GetPropertyDescription)(IPropertyUI *This,REFFMTID fmtid,PROPID pid,LPWSTR pwszText,DWORD cchText);
      HRESULT (WINAPI *GetDefaultWidth)(IPropertyUI *This,REFFMTID fmtid,PROPID pid,ULONG *pcxChars);
      HRESULT (WINAPI *GetFlags)(IPropertyUI *This,REFFMTID fmtid,PROPID pid,PROPERTYUI_FLAGS *pFlags);
      HRESULT (WINAPI *FormatForDisplay)(IPropertyUI *This,REFFMTID fmtid,PROPID pid,const PROPVARIANT *pvar,PROPERTYUI_FORMAT_FLAGS flags,LPWSTR pwszText,DWORD cchText);
      HRESULT (WINAPI *GetHelpInfo)(IPropertyUI *This,REFFMTID fmtid,PROPID pid,LPWSTR pwszHelpFile,DWORD cch,UINT *puHelpID);
    END_INTERFACE
  } IPropertyUIVtbl;
  struct IPropertyUI {
    CONST_VTBL struct IPropertyUIVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IPropertyUI_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPropertyUI_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPropertyUI_Release(This) (This)->lpVtbl->Release(This)
#define IPropertyUI_ParsePropertyName(This,pszName,pfmtid,ppid,pchEaten) (This)->lpVtbl->ParsePropertyName(This,pszName,pfmtid,ppid,pchEaten)
#define IPropertyUI_GetCannonicalName(This,fmtid,pid,pwszText,cchText) (This)->lpVtbl->GetCannonicalName(This,fmtid,pid,pwszText,cchText)
#define IPropertyUI_GetDisplayName(This,fmtid,pid,flags,pwszText,cchText) (This)->lpVtbl->GetDisplayName(This,fmtid,pid,flags,pwszText,cchText)
#define IPropertyUI_GetPropertyDescription(This,fmtid,pid,pwszText,cchText) (This)->lpVtbl->GetPropertyDescription(This,fmtid,pid,pwszText,cchText)
#define IPropertyUI_GetDefaultWidth(This,fmtid,pid,pcxChars) (This)->lpVtbl->GetDefaultWidth(This,fmtid,pid,pcxChars)
#define IPropertyUI_GetFlags(This,fmtid,pid,pFlags) (This)->lpVtbl->GetFlags(This,fmtid,pid,pFlags)
#define IPropertyUI_FormatForDisplay(This,fmtid,pid,pvar,flags,pwszText,cchText) (This)->lpVtbl->FormatForDisplay(This,fmtid,pid,pvar,flags,pwszText,cchText)
#define IPropertyUI_GetHelpInfo(This,fmtid,pid,pwszHelpFile,cch,puHelpID) (This)->lpVtbl->GetHelpInfo(This,fmtid,pid,pwszHelpFile,cch,puHelpID)
#endif
#endif
  HRESULT WINAPI IPropertyUI_ParsePropertyName_Proxy(IPropertyUI *This,LPCWSTR pszName,FMTID *pfmtid,PROPID *ppid,ULONG *pchEaten);
  void __RPC_STUB IPropertyUI_ParsePropertyName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPropertyUI_GetCannonicalName_Proxy(IPropertyUI *This,REFFMTID fmtid,PROPID pid,LPWSTR pwszText,DWORD cchText);
  void __RPC_STUB IPropertyUI_GetCannonicalName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPropertyUI_GetDisplayName_Proxy(IPropertyUI *This,REFFMTID fmtid,PROPID pid,PROPERTYUI_NAME_FLAGS flags,LPWSTR pwszText,DWORD cchText);
  void __RPC_STUB IPropertyUI_GetDisplayName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPropertyUI_GetPropertyDescription_Proxy(IPropertyUI *This,REFFMTID fmtid,PROPID pid,LPWSTR pwszText,DWORD cchText);
  void __RPC_STUB IPropertyUI_GetPropertyDescription_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPropertyUI_GetDefaultWidth_Proxy(IPropertyUI *This,REFFMTID fmtid,PROPID pid,ULONG *pcxChars);
  void __RPC_STUB IPropertyUI_GetDefaultWidth_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPropertyUI_GetFlags_Proxy(IPropertyUI *This,REFFMTID fmtid,PROPID pid,PROPERTYUI_FLAGS *pFlags);
  void __RPC_STUB IPropertyUI_GetFlags_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPropertyUI_FormatForDisplay_Proxy(IPropertyUI *This,REFFMTID fmtid,PROPID pid,const PROPVARIANT *pvar,PROPERTYUI_FORMAT_FLAGS flags,LPWSTR pwszText,DWORD cchText);
  void __RPC_STUB IPropertyUI_FormatForDisplay_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPropertyUI_GetHelpInfo_Proxy(IPropertyUI *This,REFFMTID fmtid,PROPID pid,LPWSTR pwszHelpFile,DWORD cch,UINT *puHelpID);
  void __RPC_STUB IPropertyUI_GetHelpInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#if (0x501 >= 0x0500)
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0210_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0210_v0_0_s_ifspec;
#ifndef __ICategoryProvider_INTERFACE_DEFINED__
#define __ICategoryProvider_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ICategoryProvider;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ICategoryProvider : public IUnknown {
  public:
    virtual HRESULT WINAPI CanCategorizeOnSCID(SHCOLUMNID *pscid) = 0;
    virtual HRESULT WINAPI GetDefaultCategory(GUID *pguid,SHCOLUMNID *pscid) = 0;
    virtual HRESULT WINAPI GetCategoryForSCID(SHCOLUMNID *pscid,GUID *pguid) = 0;
    virtual HRESULT WINAPI EnumCategories(IEnumGUID **penum) = 0;
    virtual HRESULT WINAPI GetCategoryName(GUID *pguid,LPWSTR pszName,UINT cch) = 0;
    virtual HRESULT WINAPI CreateCategory(GUID *pguid,REFIID riid,void **ppv) = 0;
  };
#else
  typedef struct ICategoryProviderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ICategoryProvider *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ICategoryProvider *This);
      ULONG (WINAPI *Release)(ICategoryProvider *This);
      HRESULT (WINAPI *CanCategorizeOnSCID)(ICategoryProvider *This,SHCOLUMNID *pscid);
      HRESULT (WINAPI *GetDefaultCategory)(ICategoryProvider *This,GUID *pguid,SHCOLUMNID *pscid);
      HRESULT (WINAPI *GetCategoryForSCID)(ICategoryProvider *This,SHCOLUMNID *pscid,GUID *pguid);
      HRESULT (WINAPI *EnumCategories)(ICategoryProvider *This,IEnumGUID **penum);
      HRESULT (WINAPI *GetCategoryName)(ICategoryProvider *This,GUID *pguid,LPWSTR pszName,UINT cch);
      HRESULT (WINAPI *CreateCategory)(ICategoryProvider *This,GUID *pguid,REFIID riid,void **ppv);
    END_INTERFACE
  } ICategoryProviderVtbl;
  struct ICategoryProvider {
    CONST_VTBL struct ICategoryProviderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ICategoryProvider_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICategoryProvider_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICategoryProvider_Release(This) (This)->lpVtbl->Release(This)
#define ICategoryProvider_CanCategorizeOnSCID(This,pscid) (This)->lpVtbl->CanCategorizeOnSCID(This,pscid)
#define ICategoryProvider_GetDefaultCategory(This,pguid,pscid) (This)->lpVtbl->GetDefaultCategory(This,pguid,pscid)
#define ICategoryProvider_GetCategoryForSCID(This,pscid,pguid) (This)->lpVtbl->GetCategoryForSCID(This,pscid,pguid)
#define ICategoryProvider_EnumCategories(This,penum) (This)->lpVtbl->EnumCategories(This,penum)
#define ICategoryProvider_GetCategoryName(This,pguid,pszName,cch) (This)->lpVtbl->GetCategoryName(This,pguid,pszName,cch)
#define ICategoryProvider_CreateCategory(This,pguid,riid,ppv) (This)->lpVtbl->CreateCategory(This,pguid,riid,ppv)
#endif
#endif
  HRESULT WINAPI ICategoryProvider_CanCategorizeOnSCID_Proxy(ICategoryProvider *This,SHCOLUMNID *pscid);
  void __RPC_STUB ICategoryProvider_CanCategorizeOnSCID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICategoryProvider_GetDefaultCategory_Proxy(ICategoryProvider *This,GUID *pguid,SHCOLUMNID *pscid);
  void __RPC_STUB ICategoryProvider_GetDefaultCategory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICategoryProvider_GetCategoryForSCID_Proxy(ICategoryProvider *This,SHCOLUMNID *pscid,GUID *pguid);
  void __RPC_STUB ICategoryProvider_GetCategoryForSCID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICategoryProvider_EnumCategories_Proxy(ICategoryProvider *This,IEnumGUID **penum);
  void __RPC_STUB ICategoryProvider_EnumCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICategoryProvider_GetCategoryName_Proxy(ICategoryProvider *This,GUID *pguid,LPWSTR pszName,UINT cch);
  void __RPC_STUB ICategoryProvider_GetCategoryName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICategoryProvider_CreateCategory_Proxy(ICategoryProvider *This,GUID *pguid,REFIID riid,void **ppv);
  void __RPC_STUB ICategoryProvider_CreateCategory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef enum __MIDL___MIDL_itf_shobjidl_0211_0001 {
    CATINFO_NORMAL = 0,CATINFO_COLLAPSED = 0x1,CATINFO_HIDDEN = 0x2
  } CATEGORYINFO_FLAGS;

  typedef enum __MIDL___MIDL_itf_shobjidl_0211_0002 {
    CATSORT_DEFAULT = 0,CATSORT_NAME = 0x1
  } CATSORT_FLAGS;

  typedef struct __MIDL___MIDL_itf_shobjidl_0211_0003 {
    CATEGORYINFO_FLAGS cif;
    WCHAR wszName[260];
  } CATEGORY_INFO;

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0211_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0211_v0_0_s_ifspec;
#ifndef __ICategorizer_INTERFACE_DEFINED__
#define __ICategorizer_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ICategorizer;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ICategorizer : public IUnknown {
  public:
    virtual HRESULT WINAPI GetDescription(LPWSTR pszDesc,UINT cch) = 0;
    virtual HRESULT WINAPI GetCategory(UINT cidl,LPCITEMIDLIST *apidl,DWORD *rgCategoryIds) = 0;
    virtual HRESULT WINAPI GetCategoryInfo(DWORD dwCategoryId,CATEGORY_INFO *pci) = 0;
    virtual HRESULT WINAPI CompareCategory(CATSORT_FLAGS csfFlags,DWORD dwCategoryId1,DWORD dwCategoryId2) = 0;
  };
#else
  typedef struct ICategorizerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ICategorizer *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ICategorizer *This);
      ULONG (WINAPI *Release)(ICategorizer *This);
      HRESULT (WINAPI *GetDescription)(ICategorizer *This,LPWSTR pszDesc,UINT cch);
      HRESULT (WINAPI *GetCategory)(ICategorizer *This,UINT cidl,LPCITEMIDLIST *apidl,DWORD *rgCategoryIds);
      HRESULT (WINAPI *GetCategoryInfo)(ICategorizer *This,DWORD dwCategoryId,CATEGORY_INFO *pci);
      HRESULT (WINAPI *CompareCategory)(ICategorizer *This,CATSORT_FLAGS csfFlags,DWORD dwCategoryId1,DWORD dwCategoryId2);
    END_INTERFACE
  } ICategorizerVtbl;
  struct ICategorizer {
    CONST_VTBL struct ICategorizerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ICategorizer_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICategorizer_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICategorizer_Release(This) (This)->lpVtbl->Release(This)
#define ICategorizer_GetDescription(This,pszDesc,cch) (This)->lpVtbl->GetDescription(This,pszDesc,cch)
#define ICategorizer_GetCategory(This,cidl,apidl,rgCategoryIds) (This)->lpVtbl->GetCategory(This,cidl,apidl,rgCategoryIds)
#define ICategorizer_GetCategoryInfo(This,dwCategoryId,pci) (This)->lpVtbl->GetCategoryInfo(This,dwCategoryId,pci)
#define ICategorizer_CompareCategory(This,csfFlags,dwCategoryId1,dwCategoryId2) (This)->lpVtbl->CompareCategory(This,csfFlags,dwCategoryId1,dwCategoryId2)
#endif
#endif
  HRESULT WINAPI ICategorizer_GetDescription_Proxy(ICategorizer *This,LPWSTR pszDesc,UINT cch);
  void __RPC_STUB ICategorizer_GetDescription_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICategorizer_GetCategory_Proxy(ICategorizer *This,UINT cidl,LPCITEMIDLIST *apidl,DWORD *rgCategoryIds);
  void __RPC_STUB ICategorizer_GetCategory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICategorizer_GetCategoryInfo_Proxy(ICategorizer *This,DWORD dwCategoryId,CATEGORY_INFO *pci);
  void __RPC_STUB ICategorizer_GetCategoryInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICategorizer_CompareCategory_Proxy(ICategorizer *This,CATSORT_FLAGS csfFlags,DWORD dwCategoryId1,DWORD dwCategoryId2);
  void __RPC_STUB ICategorizer_CompareCategory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#define IShellLink __MINGW_NAME_AW(IShellLink)

  typedef enum __MIDL___MIDL_itf_shobjidl_0212_0001 {
    SLR_NO_UI = 0x1,SLR_ANY_MATCH = 0x2,SLR_UPDATE = 0x4,SLR_NOUPDATE = 0x8,SLR_NOSEARCH = 0x10,SLR_NOTRACK = 0x20,SLR_NOLINKINFO = 0x40,
    SLR_INVOKE_MSI = 0x80,SLR_NO_UI_WITH_MSG_PUMP = 0x101
  } SLR_FLAGS;

  typedef enum __MIDL___MIDL_itf_shobjidl_0212_0002 {
    SLGP_SHORTPATH = 0x1,SLGP_UNCPRIORITY = 0x2,SLGP_RAWPATH = 0x4
  } SLGP_FLAGS;

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0212_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0212_v0_0_s_ifspec;
#ifndef __IShellLinkA_INTERFACE_DEFINED__
#define __IShellLinkA_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellLinkA;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellLinkA : public IUnknown {
  public:
    virtual HRESULT WINAPI GetPath(LPSTR pszFile,int cch,WIN32_FIND_DATAA *pfd,DWORD fFlags) = 0;
    virtual HRESULT WINAPI GetIDList(LPITEMIDLIST *ppidl) = 0;
    virtual HRESULT WINAPI SetIDList(LPCITEMIDLIST pidl) = 0;
    virtual HRESULT WINAPI GetDescription(LPSTR pszName,int cch) = 0;
    virtual HRESULT WINAPI SetDescription(LPCSTR pszName) = 0;
    virtual HRESULT WINAPI GetWorkingDirectory(LPSTR pszDir,int cch) = 0;
    virtual HRESULT WINAPI SetWorkingDirectory(LPCSTR pszDir) = 0;
    virtual HRESULT WINAPI GetArguments(LPSTR pszArgs,int cch) = 0;
    virtual HRESULT WINAPI SetArguments(LPCSTR pszArgs) = 0;
    virtual HRESULT WINAPI GetHotkey(WORD *pwHotkey) = 0;
    virtual HRESULT WINAPI SetHotkey(WORD wHotkey) = 0;
    virtual HRESULT WINAPI GetShowCmd(int *piShowCmd) = 0;
    virtual HRESULT WINAPI SetShowCmd(int iShowCmd) = 0;
    virtual HRESULT WINAPI GetIconLocation(LPSTR pszIconPath,int cch,int *piIcon) = 0;
    virtual HRESULT WINAPI SetIconLocation(LPCSTR pszIconPath,int iIcon) = 0;
    virtual HRESULT WINAPI SetRelativePath(LPCSTR pszPathRel,DWORD dwReserved) = 0;
    virtual HRESULT WINAPI Resolve(HWND hwnd,DWORD fFlags) = 0;
    virtual HRESULT WINAPI SetPath(LPCSTR pszFile) = 0;
  };
#else
  typedef struct IShellLinkAVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellLinkA *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellLinkA *This);
      ULONG (WINAPI *Release)(IShellLinkA *This);
      HRESULT (WINAPI *GetPath)(IShellLinkA *This,LPSTR pszFile,int cch,WIN32_FIND_DATAA *pfd,DWORD fFlags);
      HRESULT (WINAPI *GetIDList)(IShellLinkA *This,LPITEMIDLIST *ppidl);
      HRESULT (WINAPI *SetIDList)(IShellLinkA *This,LPCITEMIDLIST pidl);
      HRESULT (WINAPI *GetDescription)(IShellLinkA *This,LPSTR pszName,int cch);
      HRESULT (WINAPI *SetDescription)(IShellLinkA *This,LPCSTR pszName);
      HRESULT (WINAPI *GetWorkingDirectory)(IShellLinkA *This,LPSTR pszDir,int cch);
      HRESULT (WINAPI *SetWorkingDirectory)(IShellLinkA *This,LPCSTR pszDir);
      HRESULT (WINAPI *GetArguments)(IShellLinkA *This,LPSTR pszArgs,int cch);
      HRESULT (WINAPI *SetArguments)(IShellLinkA *This,LPCSTR pszArgs);
      HRESULT (WINAPI *GetHotkey)(IShellLinkA *This,WORD *pwHotkey);
      HRESULT (WINAPI *SetHotkey)(IShellLinkA *This,WORD wHotkey);
      HRESULT (WINAPI *GetShowCmd)(IShellLinkA *This,int *piShowCmd);
      HRESULT (WINAPI *SetShowCmd)(IShellLinkA *This,int iShowCmd);
      HRESULT (WINAPI *GetIconLocation)(IShellLinkA *This,LPSTR pszIconPath,int cch,int *piIcon);
      HRESULT (WINAPI *SetIconLocation)(IShellLinkA *This,LPCSTR pszIconPath,int iIcon);
      HRESULT (WINAPI *SetRelativePath)(IShellLinkA *This,LPCSTR pszPathRel,DWORD dwReserved);
      HRESULT (WINAPI *Resolve)(IShellLinkA *This,HWND hwnd,DWORD fFlags);
      HRESULT (WINAPI *SetPath)(IShellLinkA *This,LPCSTR pszFile);
    END_INTERFACE
  } IShellLinkAVtbl;
  struct IShellLinkA {
    CONST_VTBL struct IShellLinkAVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellLinkA_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellLinkA_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellLinkA_Release(This) (This)->lpVtbl->Release(This)
#define IShellLinkA_GetPath(This,pszFile,cch,pfd,fFlags) (This)->lpVtbl->GetPath(This,pszFile,cch,pfd,fFlags)
#define IShellLinkA_GetIDList(This,ppidl) (This)->lpVtbl->GetIDList(This,ppidl)
#define IShellLinkA_SetIDList(This,pidl) (This)->lpVtbl->SetIDList(This,pidl)
#define IShellLinkA_GetDescription(This,pszName,cch) (This)->lpVtbl->GetDescription(This,pszName,cch)
#define IShellLinkA_SetDescription(This,pszName) (This)->lpVtbl->SetDescription(This,pszName)
#define IShellLinkA_GetWorkingDirectory(This,pszDir,cch) (This)->lpVtbl->GetWorkingDirectory(This,pszDir,cch)
#define IShellLinkA_SetWorkingDirectory(This,pszDir) (This)->lpVtbl->SetWorkingDirectory(This,pszDir)
#define IShellLinkA_GetArguments(This,pszArgs,cch) (This)->lpVtbl->GetArguments(This,pszArgs,cch)
#define IShellLinkA_SetArguments(This,pszArgs) (This)->lpVtbl->SetArguments(This,pszArgs)
#define IShellLinkA_GetHotkey(This,pwHotkey) (This)->lpVtbl->GetHotkey(This,pwHotkey)
#define IShellLinkA_SetHotkey(This,wHotkey) (This)->lpVtbl->SetHotkey(This,wHotkey)
#define IShellLinkA_GetShowCmd(This,piShowCmd) (This)->lpVtbl->GetShowCmd(This,piShowCmd)
#define IShellLinkA_SetShowCmd(This,iShowCmd) (This)->lpVtbl->SetShowCmd(This,iShowCmd)
#define IShellLinkA_GetIconLocation(This,pszIconPath,cch,piIcon) (This)->lpVtbl->GetIconLocation(This,pszIconPath,cch,piIcon)
#define IShellLinkA_SetIconLocation(This,pszIconPath,iIcon) (This)->lpVtbl->SetIconLocation(This,pszIconPath,iIcon)
#define IShellLinkA_SetRelativePath(This,pszPathRel,dwReserved) (This)->lpVtbl->SetRelativePath(This,pszPathRel,dwReserved)
#define IShellLinkA_Resolve(This,hwnd,fFlags) (This)->lpVtbl->Resolve(This,hwnd,fFlags)
#define IShellLinkA_SetPath(This,pszFile) (This)->lpVtbl->SetPath(This,pszFile)
#endif
#endif
  HRESULT WINAPI IShellLinkA_GetPath_Proxy(IShellLinkA *This,LPSTR pszFile,int cch,WIN32_FIND_DATAA *pfd,DWORD fFlags);
  void __RPC_STUB IShellLinkA_GetPath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_GetIDList_Proxy(IShellLinkA *This,LPITEMIDLIST *ppidl);
  void __RPC_STUB IShellLinkA_GetIDList_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_SetIDList_Proxy(IShellLinkA *This,LPCITEMIDLIST pidl);
  void __RPC_STUB IShellLinkA_SetIDList_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_GetDescription_Proxy(IShellLinkA *This,LPSTR pszName,int cch);
  void __RPC_STUB IShellLinkA_GetDescription_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_SetDescription_Proxy(IShellLinkA *This,LPCSTR pszName);
  void __RPC_STUB IShellLinkA_SetDescription_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_GetWorkingDirectory_Proxy(IShellLinkA *This,LPSTR pszDir,int cch);
  void __RPC_STUB IShellLinkA_GetWorkingDirectory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_SetWorkingDirectory_Proxy(IShellLinkA *This,LPCSTR pszDir);
  void __RPC_STUB IShellLinkA_SetWorkingDirectory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_GetArguments_Proxy(IShellLinkA *This,LPSTR pszArgs,int cch);
  void __RPC_STUB IShellLinkA_GetArguments_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_SetArguments_Proxy(IShellLinkA *This,LPCSTR pszArgs);
  void __RPC_STUB IShellLinkA_SetArguments_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_GetHotkey_Proxy(IShellLinkA *This,WORD *pwHotkey);
  void __RPC_STUB IShellLinkA_GetHotkey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_SetHotkey_Proxy(IShellLinkA *This,WORD wHotkey);
  void __RPC_STUB IShellLinkA_SetHotkey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_GetShowCmd_Proxy(IShellLinkA *This,int *piShowCmd);
  void __RPC_STUB IShellLinkA_GetShowCmd_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_SetShowCmd_Proxy(IShellLinkA *This,int iShowCmd);
  void __RPC_STUB IShellLinkA_SetShowCmd_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_GetIconLocation_Proxy(IShellLinkA *This,LPSTR pszIconPath,int cch,int *piIcon);
  void __RPC_STUB IShellLinkA_GetIconLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_SetIconLocation_Proxy(IShellLinkA *This,LPCSTR pszIconPath,int iIcon);
  void __RPC_STUB IShellLinkA_SetIconLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_SetRelativePath_Proxy(IShellLinkA *This,LPCSTR pszPathRel,DWORD dwReserved);
  void __RPC_STUB IShellLinkA_SetRelativePath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_Resolve_Proxy(IShellLinkA *This,HWND hwnd,DWORD fFlags);
  void __RPC_STUB IShellLinkA_Resolve_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkA_SetPath_Proxy(IShellLinkA *This,LPCSTR pszFile);
  void __RPC_STUB IShellLinkA_SetPath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellLinkW_INTERFACE_DEFINED__
#define __IShellLinkW_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellLinkW;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellLinkW : public IUnknown {
  public:
    virtual HRESULT WINAPI GetPath(LPWSTR pszFile,int cch,WIN32_FIND_DATAW *pfd,DWORD fFlags) = 0;
    virtual HRESULT WINAPI GetIDList(LPITEMIDLIST *ppidl) = 0;
    virtual HRESULT WINAPI SetIDList(LPCITEMIDLIST pidl) = 0;
    virtual HRESULT WINAPI GetDescription(LPWSTR pszName,int cch) = 0;
    virtual HRESULT WINAPI SetDescription(LPCWSTR pszName) = 0;
    virtual HRESULT WINAPI GetWorkingDirectory(LPWSTR pszDir,int cch) = 0;
    virtual HRESULT WINAPI SetWorkingDirectory(LPCWSTR pszDir) = 0;
    virtual HRESULT WINAPI GetArguments(LPWSTR pszArgs,int cch) = 0;
    virtual HRESULT WINAPI SetArguments(LPCWSTR pszArgs) = 0;
    virtual HRESULT WINAPI GetHotkey(WORD *pwHotkey) = 0;
    virtual HRESULT WINAPI SetHotkey(WORD wHotkey) = 0;
    virtual HRESULT WINAPI GetShowCmd(int *piShowCmd) = 0;
    virtual HRESULT WINAPI SetShowCmd(int iShowCmd) = 0;
    virtual HRESULT WINAPI GetIconLocation(LPWSTR pszIconPath,int cch,int *piIcon) = 0;
    virtual HRESULT WINAPI SetIconLocation(LPCWSTR pszIconPath,int iIcon) = 0;
    virtual HRESULT WINAPI SetRelativePath(LPCWSTR pszPathRel,DWORD dwReserved) = 0;
    virtual HRESULT WINAPI Resolve(HWND hwnd,DWORD fFlags) = 0;
    virtual HRESULT WINAPI SetPath(LPCWSTR pszFile) = 0;
  };
#else
  typedef struct IShellLinkWVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellLinkW *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellLinkW *This);
      ULONG (WINAPI *Release)(IShellLinkW *This);
      HRESULT (WINAPI *GetPath)(IShellLinkW *This,LPWSTR pszFile,int cch,WIN32_FIND_DATAW *pfd,DWORD fFlags);
      HRESULT (WINAPI *GetIDList)(IShellLinkW *This,LPITEMIDLIST *ppidl);
      HRESULT (WINAPI *SetIDList)(IShellLinkW *This,LPCITEMIDLIST pidl);
      HRESULT (WINAPI *GetDescription)(IShellLinkW *This,LPWSTR pszName,int cch);
      HRESULT (WINAPI *SetDescription)(IShellLinkW *This,LPCWSTR pszName);
      HRESULT (WINAPI *GetWorkingDirectory)(IShellLinkW *This,LPWSTR pszDir,int cch);
      HRESULT (WINAPI *SetWorkingDirectory)(IShellLinkW *This,LPCWSTR pszDir);
      HRESULT (WINAPI *GetArguments)(IShellLinkW *This,LPWSTR pszArgs,int cch);
      HRESULT (WINAPI *SetArguments)(IShellLinkW *This,LPCWSTR pszArgs);
      HRESULT (WINAPI *GetHotkey)(IShellLinkW *This,WORD *pwHotkey);
      HRESULT (WINAPI *SetHotkey)(IShellLinkW *This,WORD wHotkey);
      HRESULT (WINAPI *GetShowCmd)(IShellLinkW *This,int *piShowCmd);
      HRESULT (WINAPI *SetShowCmd)(IShellLinkW *This,int iShowCmd);
      HRESULT (WINAPI *GetIconLocation)(IShellLinkW *This,LPWSTR pszIconPath,int cch,int *piIcon);
      HRESULT (WINAPI *SetIconLocation)(IShellLinkW *This,LPCWSTR pszIconPath,int iIcon);
      HRESULT (WINAPI *SetRelativePath)(IShellLinkW *This,LPCWSTR pszPathRel,DWORD dwReserved);
      HRESULT (WINAPI *Resolve)(IShellLinkW *This,HWND hwnd,DWORD fFlags);
      HRESULT (WINAPI *SetPath)(IShellLinkW *This,LPCWSTR pszFile);
    END_INTERFACE
  } IShellLinkWVtbl;
  struct IShellLinkW {
    CONST_VTBL struct IShellLinkWVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellLinkW_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellLinkW_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellLinkW_Release(This) (This)->lpVtbl->Release(This)
#define IShellLinkW_GetPath(This,pszFile,cch,pfd,fFlags) (This)->lpVtbl->GetPath(This,pszFile,cch,pfd,fFlags)
#define IShellLinkW_GetIDList(This,ppidl) (This)->lpVtbl->GetIDList(This,ppidl)
#define IShellLinkW_SetIDList(This,pidl) (This)->lpVtbl->SetIDList(This,pidl)
#define IShellLinkW_GetDescription(This,pszName,cch) (This)->lpVtbl->GetDescription(This,pszName,cch)
#define IShellLinkW_SetDescription(This,pszName) (This)->lpVtbl->SetDescription(This,pszName)
#define IShellLinkW_GetWorkingDirectory(This,pszDir,cch) (This)->lpVtbl->GetWorkingDirectory(This,pszDir,cch)
#define IShellLinkW_SetWorkingDirectory(This,pszDir) (This)->lpVtbl->SetWorkingDirectory(This,pszDir)
#define IShellLinkW_GetArguments(This,pszArgs,cch) (This)->lpVtbl->GetArguments(This,pszArgs,cch)
#define IShellLinkW_SetArguments(This,pszArgs) (This)->lpVtbl->SetArguments(This,pszArgs)
#define IShellLinkW_GetHotkey(This,pwHotkey) (This)->lpVtbl->GetHotkey(This,pwHotkey)
#define IShellLinkW_SetHotkey(This,wHotkey) (This)->lpVtbl->SetHotkey(This,wHotkey)
#define IShellLinkW_GetShowCmd(This,piShowCmd) (This)->lpVtbl->GetShowCmd(This,piShowCmd)
#define IShellLinkW_SetShowCmd(This,iShowCmd) (This)->lpVtbl->SetShowCmd(This,iShowCmd)
#define IShellLinkW_GetIconLocation(This,pszIconPath,cch,piIcon) (This)->lpVtbl->GetIconLocation(This,pszIconPath,cch,piIcon)
#define IShellLinkW_SetIconLocation(This,pszIconPath,iIcon) (This)->lpVtbl->SetIconLocation(This,pszIconPath,iIcon)
#define IShellLinkW_SetRelativePath(This,pszPathRel,dwReserved) (This)->lpVtbl->SetRelativePath(This,pszPathRel,dwReserved)
#define IShellLinkW_Resolve(This,hwnd,fFlags) (This)->lpVtbl->Resolve(This,hwnd,fFlags)
#define IShellLinkW_SetPath(This,pszFile) (This)->lpVtbl->SetPath(This,pszFile)
#endif
#endif
  HRESULT WINAPI IShellLinkW_GetPath_Proxy(IShellLinkW *This,LPWSTR pszFile,int cch,WIN32_FIND_DATAW *pfd,DWORD fFlags);
  void __RPC_STUB IShellLinkW_GetPath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_GetIDList_Proxy(IShellLinkW *This,LPITEMIDLIST *ppidl);
  void __RPC_STUB IShellLinkW_GetIDList_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_SetIDList_Proxy(IShellLinkW *This,LPCITEMIDLIST pidl);
  void __RPC_STUB IShellLinkW_SetIDList_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_GetDescription_Proxy(IShellLinkW *This,LPWSTR pszName,int cch);
  void __RPC_STUB IShellLinkW_GetDescription_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_SetDescription_Proxy(IShellLinkW *This,LPCWSTR pszName);
  void __RPC_STUB IShellLinkW_SetDescription_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_GetWorkingDirectory_Proxy(IShellLinkW *This,LPWSTR pszDir,int cch);
  void __RPC_STUB IShellLinkW_GetWorkingDirectory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_SetWorkingDirectory_Proxy(IShellLinkW *This,LPCWSTR pszDir);
  void __RPC_STUB IShellLinkW_SetWorkingDirectory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_GetArguments_Proxy(IShellLinkW *This,LPWSTR pszArgs,int cch);
  void __RPC_STUB IShellLinkW_GetArguments_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_SetArguments_Proxy(IShellLinkW *This,LPCWSTR pszArgs);
  void __RPC_STUB IShellLinkW_SetArguments_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_GetHotkey_Proxy(IShellLinkW *This,WORD *pwHotkey);
  void __RPC_STUB IShellLinkW_GetHotkey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_SetHotkey_Proxy(IShellLinkW *This,WORD wHotkey);
  void __RPC_STUB IShellLinkW_SetHotkey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_GetShowCmd_Proxy(IShellLinkW *This,int *piShowCmd);
  void __RPC_STUB IShellLinkW_GetShowCmd_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_SetShowCmd_Proxy(IShellLinkW *This,int iShowCmd);
  void __RPC_STUB IShellLinkW_SetShowCmd_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_GetIconLocation_Proxy(IShellLinkW *This,LPWSTR pszIconPath,int cch,int *piIcon);
  void __RPC_STUB IShellLinkW_GetIconLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_SetIconLocation_Proxy(IShellLinkW *This,LPCWSTR pszIconPath,int iIcon);
  void __RPC_STUB IShellLinkW_SetIconLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_SetRelativePath_Proxy(IShellLinkW *This,LPCWSTR pszPathRel,DWORD dwReserved);
  void __RPC_STUB IShellLinkW_SetRelativePath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_Resolve_Proxy(IShellLinkW *This,HWND hwnd,DWORD fFlags);
  void __RPC_STUB IShellLinkW_Resolve_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkW_SetPath_Proxy(IShellLinkW *This,LPCWSTR pszFile);
  void __RPC_STUB IShellLinkW_SetPath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActionProgressDialog_INTERFACE_DEFINED__
#define __IActionProgressDialog_INTERFACE_DEFINED__
  enum __MIDL_IActionProgressDialog_0001 {
    SPINITF_NORMAL = 0,SPINITF_MODAL = 0x1,SPINITF_NOMINIMIZE = 0x8
  };
  typedef DWORD SPINITF;

  EXTERN_C const IID IID_IActionProgressDialog;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActionProgressDialog : public IUnknown {
  public:
    virtual HRESULT WINAPI Initialize(SPINITF flags,LPCWSTR pszTitle,LPCWSTR pszCancel) = 0;
    virtual HRESULT WINAPI Stop(void) = 0;
  };
#else
  typedef struct IActionProgressDialogVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActionProgressDialog *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActionProgressDialog *This);
      ULONG (WINAPI *Release)(IActionProgressDialog *This);
      HRESULT (WINAPI *Initialize)(IActionProgressDialog *This,SPINITF flags,LPCWSTR pszTitle,LPCWSTR pszCancel);
      HRESULT (WINAPI *Stop)(IActionProgressDialog *This);
    END_INTERFACE
  } IActionProgressDialogVtbl;
  struct IActionProgressDialog {
    CONST_VTBL struct IActionProgressDialogVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActionProgressDialog_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActionProgressDialog_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActionProgressDialog_Release(This) (This)->lpVtbl->Release(This)
#define IActionProgressDialog_Initialize(This,flags,pszTitle,pszCancel) (This)->lpVtbl->Initialize(This,flags,pszTitle,pszCancel)
#define IActionProgressDialog_Stop(This) (This)->lpVtbl->Stop(This)
#endif
#endif
  HRESULT WINAPI IActionProgressDialog_Initialize_Proxy(IActionProgressDialog *This,SPINITF flags,LPCWSTR pszTitle,LPCWSTR pszCancel);
  void __RPC_STUB IActionProgressDialog_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActionProgressDialog_Stop_Proxy(IActionProgressDialog *This);
  void __RPC_STUB IActionProgressDialog_Stop_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IHWEventHandler_INTERFACE_DEFINED__
#define __IHWEventHandler_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IHWEventHandler;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IHWEventHandler : public IUnknown {
  public:
    virtual HRESULT WINAPI Initialize(LPCWSTR pszParams) = 0;
    virtual HRESULT WINAPI HandleEvent(LPCWSTR pszDeviceID,LPCWSTR pszAltDeviceID,LPCWSTR pszEventType) = 0;
    virtual HRESULT WINAPI HandleEventWithContent(LPCWSTR pszDeviceID,LPCWSTR pszAltDeviceID,LPCWSTR pszEventType,LPCWSTR pszContentTypeHandler,IDataObject *pdataobject) = 0;
  };
#else
  typedef struct IHWEventHandlerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IHWEventHandler *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IHWEventHandler *This);
      ULONG (WINAPI *Release)(IHWEventHandler *This);
      HRESULT (WINAPI *Initialize)(IHWEventHandler *This,LPCWSTR pszParams);
      HRESULT (WINAPI *HandleEvent)(IHWEventHandler *This,LPCWSTR pszDeviceID,LPCWSTR pszAltDeviceID,LPCWSTR pszEventType);
      HRESULT (WINAPI *HandleEventWithContent)(IHWEventHandler *This,LPCWSTR pszDeviceID,LPCWSTR pszAltDeviceID,LPCWSTR pszEventType,LPCWSTR pszContentTypeHandler,IDataObject *pdataobject);
    END_INTERFACE
  } IHWEventHandlerVtbl;
  struct IHWEventHandler {
    CONST_VTBL struct IHWEventHandlerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IHWEventHandler_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IHWEventHandler_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IHWEventHandler_Release(This) (This)->lpVtbl->Release(This)
#define IHWEventHandler_Initialize(This,pszParams) (This)->lpVtbl->Initialize(This,pszParams)
#define IHWEventHandler_HandleEvent(This,pszDeviceID,pszAltDeviceID,pszEventType) (This)->lpVtbl->HandleEvent(This,pszDeviceID,pszAltDeviceID,pszEventType)
#define IHWEventHandler_HandleEventWithContent(This,pszDeviceID,pszAltDeviceID,pszEventType,pszContentTypeHandler,pdataobject) (This)->lpVtbl->HandleEventWithContent(This,pszDeviceID,pszAltDeviceID,pszEventType,pszContentTypeHandler,pdataobject)
#endif
#endif
  HRESULT WINAPI IHWEventHandler_Initialize_Proxy(IHWEventHandler *This,LPCWSTR pszParams);
  void __RPC_STUB IHWEventHandler_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IHWEventHandler_HandleEvent_Proxy(IHWEventHandler *This,LPCWSTR pszDeviceID,LPCWSTR pszAltDeviceID,LPCWSTR pszEventType);
  void __RPC_STUB IHWEventHandler_HandleEvent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IHWEventHandler_HandleEventWithContent_Proxy(IHWEventHandler *This,LPCWSTR pszDeviceID,LPCWSTR pszAltDeviceID,LPCWSTR pszEventType,LPCWSTR pszContentTypeHandler,IDataObject *pdataobject);
  void __RPC_STUB IHWEventHandler_HandleEventWithContent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define ARCONTENT_AUTORUNINF 0x00000002
#define ARCONTENT_AUDIOCD 0x00000004
#define ARCONTENT_DVDMOVIE 0x00000008
#define ARCONTENT_BLANKCD 0x00000010
#define ARCONTENT_BLANKDVD 0x00000020
#define ARCONTENT_UNKNOWNCONTENT 0x00000040
#define ARCONTENT_AUTOPLAYPIX 0x00000080
#define ARCONTENT_AUTOPLAYMUSIC 0x00000100
#define ARCONTENT_AUTOPLAYVIDEO 0x00000200

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0216_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0216_v0_0_s_ifspec;
#ifndef __IQueryCancelAutoPlay_INTERFACE_DEFINED__
#define __IQueryCancelAutoPlay_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IQueryCancelAutoPlay;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IQueryCancelAutoPlay : public IUnknown {
  public:
    virtual HRESULT WINAPI AllowAutoPlay(LPCWSTR pszPath,DWORD dwContentType,LPCWSTR pszLabel,DWORD dwSerialNumber) = 0;
  };
#else
  typedef struct IQueryCancelAutoPlayVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IQueryCancelAutoPlay *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IQueryCancelAutoPlay *This);
      ULONG (WINAPI *Release)(IQueryCancelAutoPlay *This);
      HRESULT (WINAPI *AllowAutoPlay)(IQueryCancelAutoPlay *This,LPCWSTR pszPath,DWORD dwContentType,LPCWSTR pszLabel,DWORD dwSerialNumber);
    END_INTERFACE
  } IQueryCancelAutoPlayVtbl;
  struct IQueryCancelAutoPlay {
    CONST_VTBL struct IQueryCancelAutoPlayVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IQueryCancelAutoPlay_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IQueryCancelAutoPlay_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IQueryCancelAutoPlay_Release(This) (This)->lpVtbl->Release(This)
#define IQueryCancelAutoPlay_AllowAutoPlay(This,pszPath,dwContentType,pszLabel,dwSerialNumber) (This)->lpVtbl->AllowAutoPlay(This,pszPath,dwContentType,pszLabel,dwSerialNumber)
#endif
#endif
  HRESULT WINAPI IQueryCancelAutoPlay_AllowAutoPlay_Proxy(IQueryCancelAutoPlay *This,LPCWSTR pszPath,DWORD dwContentType,LPCWSTR pszLabel,DWORD dwSerialNumber);
  void __RPC_STUB IQueryCancelAutoPlay_AllowAutoPlay_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActionProgress_INTERFACE_DEFINED__
#define __IActionProgress_INTERFACE_DEFINED__
  enum __MIDL_IActionProgress_0001 {
    SPBEGINF_NORMAL = 0,SPBEGINF_AUTOTIME = 0x2,SPBEGINF_NOPROGRESSBAR = 0x10,SPBEGINF_MARQUEEPROGRESS = 0x20
  };
  typedef DWORD SPBEGINF;

  typedef enum _SPACTION {
    SPACTION_NONE = 0,
    SPACTION_MOVING,SPACTION_COPYING,SPACTION_RECYCLING,SPACTION_APPLYINGATTRIBS,
    SPACTION_DOWNLOADING,SPACTION_SEARCHING_INTERNET,SPACTION_CALCULATING,
    SPACTION_UPLOADING,SPACTION_SEARCHING_FILES
  } SPACTION;
  typedef enum _SPTEXT {
    SPTEXT_ACTIONDESCRIPTION = 1,SPTEXT_ACTIONDETAIL = SPTEXT_ACTIONDESCRIPTION + 1
  } SPTEXT;

  EXTERN_C const IID IID_IActionProgress;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActionProgress : public IUnknown {
  public:
    virtual HRESULT WINAPI Begin(SPACTION action,SPBEGINF flags) = 0;
    virtual HRESULT WINAPI UpdateProgress(ULONGLONG ulCompleted,ULONGLONG ulTotal) = 0;
    virtual HRESULT WINAPI UpdateText(SPTEXT sptext,LPCWSTR pszText,WINBOOL fMayCompact) = 0;
    virtual HRESULT WINAPI QueryCancel(WINBOOL *pfCancelled) = 0;
    virtual HRESULT WINAPI ResetCancel(void) = 0;
    virtual HRESULT WINAPI End(void) = 0;
  };
#else
  typedef struct IActionProgressVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActionProgress *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActionProgress *This);
      ULONG (WINAPI *Release)(IActionProgress *This);
      HRESULT (WINAPI *Begin)(IActionProgress *This,SPACTION action,SPBEGINF flags);
      HRESULT (WINAPI *UpdateProgress)(IActionProgress *This,ULONGLONG ulCompleted,ULONGLONG ulTotal);
      HRESULT (WINAPI *UpdateText)(IActionProgress *This,SPTEXT sptext,LPCWSTR pszText,WINBOOL fMayCompact);
      HRESULT (WINAPI *QueryCancel)(IActionProgress *This,WINBOOL *pfCancelled);
      HRESULT (WINAPI *ResetCancel)(IActionProgress *This);
      HRESULT (WINAPI *End)(IActionProgress *This);
    END_INTERFACE
  } IActionProgressVtbl;
  struct IActionProgress {
    CONST_VTBL struct IActionProgressVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActionProgress_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActionProgress_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActionProgress_Release(This) (This)->lpVtbl->Release(This)
#define IActionProgress_Begin(This,action,flags) (This)->lpVtbl->Begin(This,action,flags)
#define IActionProgress_UpdateProgress(This,ulCompleted,ulTotal) (This)->lpVtbl->UpdateProgress(This,ulCompleted,ulTotal)
#define IActionProgress_UpdateText(This,sptext,pszText,fMayCompact) (This)->lpVtbl->UpdateText(This,sptext,pszText,fMayCompact)
#define IActionProgress_QueryCancel(This,pfCancelled) (This)->lpVtbl->QueryCancel(This,pfCancelled)
#define IActionProgress_ResetCancel(This) (This)->lpVtbl->ResetCancel(This)
#define IActionProgress_End(This) (This)->lpVtbl->End(This)
#endif
#endif
  HRESULT WINAPI IActionProgress_Begin_Proxy(IActionProgress *This,SPACTION action,SPBEGINF flags);
  void __RPC_STUB IActionProgress_Begin_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActionProgress_UpdateProgress_Proxy(IActionProgress *This,ULONGLONG ulCompleted,ULONGLONG ulTotal);
  void __RPC_STUB IActionProgress_UpdateProgress_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActionProgress_UpdateText_Proxy(IActionProgress *This,SPTEXT sptext,LPCWSTR pszText,WINBOOL fMayCompact);
  void __RPC_STUB IActionProgress_UpdateText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActionProgress_QueryCancel_Proxy(IActionProgress *This,WINBOOL *pfCancelled);
  void __RPC_STUB IActionProgress_QueryCancel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActionProgress_ResetCancel_Proxy(IActionProgress *This);
  void __RPC_STUB IActionProgress_ResetCancel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActionProgress_End_Proxy(IActionProgress *This);
  void __RPC_STUB IActionProgress_End_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellExtInit_INTERFACE_DEFINED__
#define __IShellExtInit_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellExtInit;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellExtInit : public IUnknown {
  public:
    virtual HRESULT WINAPI Initialize(LPCITEMIDLIST pidlFolder,IDataObject *pdtobj,HKEY hkeyProgID) = 0;
  };
#else
  typedef struct IShellExtInitVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellExtInit *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellExtInit *This);
      ULONG (WINAPI *Release)(IShellExtInit *This);
      HRESULT (WINAPI *Initialize)(IShellExtInit *This,LPCITEMIDLIST pidlFolder,IDataObject *pdtobj,HKEY hkeyProgID);
    END_INTERFACE
  } IShellExtInitVtbl;
  struct IShellExtInit {
    CONST_VTBL struct IShellExtInitVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellExtInit_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellExtInit_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellExtInit_Release(This) (This)->lpVtbl->Release(This)
#define IShellExtInit_Initialize(This,pidlFolder,pdtobj,hkeyProgID) (This)->lpVtbl->Initialize(This,pidlFolder,pdtobj,hkeyProgID)
#endif
#endif
  HRESULT WINAPI IShellExtInit_Initialize_Proxy(IShellExtInit *This,LPCITEMIDLIST pidlFolder,IDataObject *pdtobj,HKEY hkeyProgID);
  void __RPC_STUB IShellExtInit_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef IShellExtInit *LPSHELLEXTINIT;

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0219_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0219_v0_0_s_ifspec;
#ifndef __IShellPropSheetExt_INTERFACE_DEFINED__
#define __IShellPropSheetExt_INTERFACE_DEFINED__
  enum __MIDL_IShellPropSheetExt_0001 {
    EXPPS_FILETYPES = 0x1
  };
  typedef UINT EXPPS;

  EXTERN_C const IID IID_IShellPropSheetExt;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellPropSheetExt : public IUnknown {
  public:
    virtual HRESULT WINAPI AddPages(LPFNSVADDPROPSHEETPAGE pfnAddPage,LPARAM lParam) = 0;
    virtual HRESULT WINAPI ReplacePage(EXPPS uPageID,LPFNSVADDPROPSHEETPAGE pfnReplaceWith,LPARAM lParam) = 0;
  };
#else
  typedef struct IShellPropSheetExtVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellPropSheetExt *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellPropSheetExt *This);
      ULONG (WINAPI *Release)(IShellPropSheetExt *This);
      HRESULT (WINAPI *AddPages)(IShellPropSheetExt *This,LPFNSVADDPROPSHEETPAGE pfnAddPage,LPARAM lParam);
      HRESULT (WINAPI *ReplacePage)(IShellPropSheetExt *This,EXPPS uPageID,LPFNSVADDPROPSHEETPAGE pfnReplaceWith,LPARAM lParam);
    END_INTERFACE
  } IShellPropSheetExtVtbl;
  struct IShellPropSheetExt {
    CONST_VTBL struct IShellPropSheetExtVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellPropSheetExt_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellPropSheetExt_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellPropSheetExt_Release(This) (This)->lpVtbl->Release(This)
#define IShellPropSheetExt_AddPages(This,pfnAddPage,lParam) (This)->lpVtbl->AddPages(This,pfnAddPage,lParam)
#define IShellPropSheetExt_ReplacePage(This,uPageID,pfnReplaceWith,lParam) (This)->lpVtbl->ReplacePage(This,uPageID,pfnReplaceWith,lParam)
#endif
#endif
  HRESULT WINAPI IShellPropSheetExt_AddPages_Proxy(IShellPropSheetExt *This,LPFNSVADDPROPSHEETPAGE pfnAddPage,LPARAM lParam);
  void __RPC_STUB IShellPropSheetExt_AddPages_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellPropSheetExt_ReplacePage_Proxy(IShellPropSheetExt *This,EXPPS uPageID,LPFNSVADDPROPSHEETPAGE pfnReplaceWith,LPARAM lParam);
  void __RPC_STUB IShellPropSheetExt_ReplacePage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef IShellPropSheetExt *LPSHELLPROPSHEETEXT;

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0220_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0220_v0_0_s_ifspec;
#ifndef __IRemoteComputer_INTERFACE_DEFINED__
#define __IRemoteComputer_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IRemoteComputer;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IRemoteComputer : public IUnknown {
  public:
    virtual HRESULT WINAPI Initialize(LPCWSTR pszMachine,WINBOOL bEnumerating) = 0;
  };
#else
  typedef struct IRemoteComputerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IRemoteComputer *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IRemoteComputer *This);
      ULONG (WINAPI *Release)(IRemoteComputer *This);
      HRESULT (WINAPI *Initialize)(IRemoteComputer *This,LPCWSTR pszMachine,WINBOOL bEnumerating);
    END_INTERFACE
  } IRemoteComputerVtbl;
  struct IRemoteComputer {
    CONST_VTBL struct IRemoteComputerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IRemoteComputer_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IRemoteComputer_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IRemoteComputer_Release(This) (This)->lpVtbl->Release(This)
#define IRemoteComputer_Initialize(This,pszMachine,bEnumerating) (This)->lpVtbl->Initialize(This,pszMachine,bEnumerating)
#endif
#endif
  HRESULT WINAPI IRemoteComputer_Initialize_Proxy(IRemoteComputer *This,LPCWSTR pszMachine,WINBOOL bEnumerating);
  void __RPC_STUB IRemoteComputer_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IQueryContinue_INTERFACE_DEFINED__
#define __IQueryContinue_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IQueryContinue;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IQueryContinue : public IUnknown {
  public:
    virtual HRESULT WINAPI QueryContinue(void) = 0;
  };
#else
  typedef struct IQueryContinueVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IQueryContinue *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IQueryContinue *This);
      ULONG (WINAPI *Release)(IQueryContinue *This);
      HRESULT (WINAPI *QueryContinue)(IQueryContinue *This);
    END_INTERFACE
  } IQueryContinueVtbl;
  struct IQueryContinue {
    CONST_VTBL struct IQueryContinueVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IQueryContinue_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IQueryContinue_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IQueryContinue_Release(This) (This)->lpVtbl->Release(This)
#define IQueryContinue_QueryContinue(This) (This)->lpVtbl->QueryContinue(This)
#endif
#endif
  HRESULT WINAPI IQueryContinue_QueryContinue_Proxy(IQueryContinue *This);
  void __RPC_STUB IQueryContinue_QueryContinue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IUserNotification_INTERFACE_DEFINED__
#define __IUserNotification_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IUserNotification;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IUserNotification : public IUnknown {
  public:
    virtual HRESULT WINAPI SetBalloonInfo(LPCWSTR pszTitle,LPCWSTR pszText,DWORD dwInfoFlags) = 0;
    virtual HRESULT WINAPI SetBalloonRetry(DWORD dwShowTime,DWORD dwInterval,UINT cRetryCount) = 0;
    virtual HRESULT WINAPI SetIconInfo(HICON hIcon,LPCWSTR pszToolTip) = 0;
    virtual HRESULT WINAPI Show(IQueryContinue *pqc,DWORD dwContinuePollInterval) = 0;
    virtual HRESULT WINAPI PlaySound(LPCWSTR pszSoundName) = 0;
  };
#else
  typedef struct IUserNotificationVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IUserNotification *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IUserNotification *This);
      ULONG (WINAPI *Release)(IUserNotification *This);
      HRESULT (WINAPI *SetBalloonInfo)(IUserNotification *This,LPCWSTR pszTitle,LPCWSTR pszText,DWORD dwInfoFlags);
      HRESULT (WINAPI *SetBalloonRetry)(IUserNotification *This,DWORD dwShowTime,DWORD dwInterval,UINT cRetryCount);
      HRESULT (WINAPI *SetIconInfo)(IUserNotification *This,HICON hIcon,LPCWSTR pszToolTip);
      HRESULT (WINAPI *Show)(IUserNotification *This,IQueryContinue *pqc,DWORD dwContinuePollInterval);
      HRESULT (WINAPI *PlaySound)(IUserNotification *This,LPCWSTR pszSoundName);
    END_INTERFACE
  } IUserNotificationVtbl;
  struct IUserNotification {
    CONST_VTBL struct IUserNotificationVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IUserNotification_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IUserNotification_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUserNotification_Release(This) (This)->lpVtbl->Release(This)
#define IUserNotification_SetBalloonInfo(This,pszTitle,pszText,dwInfoFlags) (This)->lpVtbl->SetBalloonInfo(This,pszTitle,pszText,dwInfoFlags)
#define IUserNotification_SetBalloonRetry(This,dwShowTime,dwInterval,cRetryCount) (This)->lpVtbl->SetBalloonRetry(This,dwShowTime,dwInterval,cRetryCount)
#define IUserNotification_SetIconInfo(This,hIcon,pszToolTip) (This)->lpVtbl->SetIconInfo(This,hIcon,pszToolTip)
#define IUserNotification_Show(This,pqc,dwContinuePollInterval) (This)->lpVtbl->Show(This,pqc,dwContinuePollInterval)
#define IUserNotification_PlaySound(This,pszSoundName) (This)->lpVtbl->PlaySound(This,pszSoundName)
#endif
#endif
  HRESULT WINAPI IUserNotification_SetBalloonInfo_Proxy(IUserNotification *This,LPCWSTR pszTitle,LPCWSTR pszText,DWORD dwInfoFlags);
  void __RPC_STUB IUserNotification_SetBalloonInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUserNotification_SetBalloonRetry_Proxy(IUserNotification *This,DWORD dwShowTime,DWORD dwInterval,UINT cRetryCount);
  void __RPC_STUB IUserNotification_SetBalloonRetry_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUserNotification_SetIconInfo_Proxy(IUserNotification *This,HICON hIcon,LPCWSTR pszToolTip);
  void __RPC_STUB IUserNotification_SetIconInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUserNotification_Show_Proxy(IUserNotification *This,IQueryContinue *pqc,DWORD dwContinuePollInterval);
  void __RPC_STUB IUserNotification_Show_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUserNotification_PlaySound_Proxy(IUserNotification *This,LPCWSTR pszSoundName);
  void __RPC_STUB IUserNotification_PlaySound_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IItemNameLimits_INTERFACE_DEFINED__
#define __IItemNameLimits_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IItemNameLimits;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IItemNameLimits : public IUnknown {
  public:
    virtual HRESULT WINAPI GetValidCharacters(LPWSTR *ppwszValidChars,LPWSTR *ppwszInvalidChars) = 0;
    virtual HRESULT WINAPI GetMaxLength(LPCWSTR pszName,int *piMaxNameLen) = 0;
  };
#else
  typedef struct IItemNameLimitsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IItemNameLimits *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IItemNameLimits *This);
      ULONG (WINAPI *Release)(IItemNameLimits *This);
      HRESULT (WINAPI *GetValidCharacters)(IItemNameLimits *This,LPWSTR *ppwszValidChars,LPWSTR *ppwszInvalidChars);
      HRESULT (WINAPI *GetMaxLength)(IItemNameLimits *This,LPCWSTR pszName,int *piMaxNameLen);
    END_INTERFACE
  } IItemNameLimitsVtbl;
  struct IItemNameLimits {
    CONST_VTBL struct IItemNameLimitsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IItemNameLimits_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IItemNameLimits_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IItemNameLimits_Release(This) (This)->lpVtbl->Release(This)
#define IItemNameLimits_GetValidCharacters(This,ppwszValidChars,ppwszInvalidChars) (This)->lpVtbl->GetValidCharacters(This,ppwszValidChars,ppwszInvalidChars)
#define IItemNameLimits_GetMaxLength(This,pszName,piMaxNameLen) (This)->lpVtbl->GetMaxLength(This,pszName,piMaxNameLen)
#endif
#endif
  HRESULT WINAPI IItemNameLimits_GetValidCharacters_Proxy(IItemNameLimits *This,LPWSTR *ppwszValidChars,LPWSTR *ppwszInvalidChars);
  void __RPC_STUB IItemNameLimits_GetValidCharacters_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IItemNameLimits_GetMaxLength_Proxy(IItemNameLimits *This,LPCWSTR pszName,int *piMaxNameLen);
  void __RPC_STUB IItemNameLimits_GetMaxLength_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define SNCF_REFRESHLIST 0x00000001

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0224_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0224_v0_0_s_ifspec;
#ifndef __INetCrawler_INTERFACE_DEFINED__
#define __INetCrawler_INTERFACE_DEFINED__
  EXTERN_C const IID IID_INetCrawler;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct INetCrawler : public IUnknown {
  public:
    virtual HRESULT WINAPI Update(DWORD dwFlags) = 0;
  };
#else
  typedef struct INetCrawlerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(INetCrawler *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(INetCrawler *This);
      ULONG (WINAPI *Release)(INetCrawler *This);
      HRESULT (WINAPI *Update)(INetCrawler *This,DWORD dwFlags);
    END_INTERFACE
  } INetCrawlerVtbl;
  struct INetCrawler {
    CONST_VTBL struct INetCrawlerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define INetCrawler_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define INetCrawler_AddRef(This) (This)->lpVtbl->AddRef(This)
#define INetCrawler_Release(This) (This)->lpVtbl->Release(This)
#define INetCrawler_Update(This,dwFlags) (This)->lpVtbl->Update(This,dwFlags)
#endif
#endif
  HRESULT WINAPI INetCrawler_Update_Proxy(INetCrawler *This,DWORD dwFlags);
  void __RPC_STUB INetCrawler_Update_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#if (0x501 >= 0x0400)
#define IEI_PRIORITY_MAX ITSAT_MAX_PRIORITY
#define IEI_PRIORITY_MIN ITSAT_MIN_PRIORITY
#define IEIT_PRIORITY_NORMAL ITSAT_DEFAULT_PRIORITY
#define IEIFLAG_ASYNC 0x0001
#define IEIFLAG_CACHE 0x0002
#define IEIFLAG_ASPECT 0x0004
#define IEIFLAG_OFFLINE 0x0008
#define IEIFLAG_GLEAM 0x0010
#define IEIFLAG_SCREEN 0x0020
#define IEIFLAG_ORIGSIZE 0x0040
#define IEIFLAG_NOSTAMP 0x0080
#define IEIFLAG_NOBORDER 0x0100
#define IEIFLAG_QUALITY 0x0200
#define IEIFLAG_REFRESH 0x0400

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0225_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0225_v0_0_s_ifspec;
#ifndef __IExtractImage_INTERFACE_DEFINED__
#define __IExtractImage_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IExtractImage;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IExtractImage : public IUnknown {
  public:
    virtual HRESULT WINAPI GetLocation(LPWSTR pszPathBuffer,DWORD cch,DWORD *pdwPriority,const SIZE *prgSize,DWORD dwRecClrDepth,DWORD *pdwFlags) = 0;
    virtual HRESULT WINAPI Extract(HBITMAP *phBmpThumbnail) = 0;
  };
#else
  typedef struct IExtractImageVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IExtractImage *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IExtractImage *This);
      ULONG (WINAPI *Release)(IExtractImage *This);
      HRESULT (WINAPI *GetLocation)(IExtractImage *This,LPWSTR pszPathBuffer,DWORD cch,DWORD *pdwPriority,const SIZE *prgSize,DWORD dwRecClrDepth,DWORD *pdwFlags);
      HRESULT (WINAPI *Extract)(IExtractImage *This,HBITMAP *phBmpThumbnail);
    END_INTERFACE
  } IExtractImageVtbl;
  struct IExtractImage {
    CONST_VTBL struct IExtractImageVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IExtractImage_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IExtractImage_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IExtractImage_Release(This) (This)->lpVtbl->Release(This)
#define IExtractImage_GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags) (This)->lpVtbl->GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)
#define IExtractImage_Extract(This,phBmpThumbnail) (This)->lpVtbl->Extract(This,phBmpThumbnail)
#endif
#endif
  HRESULT WINAPI IExtractImage_GetLocation_Proxy(IExtractImage *This,LPWSTR pszPathBuffer,DWORD cch,DWORD *pdwPriority,const SIZE *prgSize,DWORD dwRecClrDepth,DWORD *pdwFlags);
  void __RPC_STUB IExtractImage_GetLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IExtractImage_Extract_Proxy(IExtractImage *This,HBITMAP *phBmpThumbnail);
  void __RPC_STUB IExtractImage_Extract_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef IExtractImage *LPEXTRACTIMAGE;
#endif
#if (0x501 >= 0x0500)
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0226_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0226_v0_0_s_ifspec;
#ifndef __IExtractImage2_INTERFACE_DEFINED__
#define __IExtractImage2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IExtractImage2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IExtractImage2 : public IExtractImage {
  public:
    virtual HRESULT WINAPI GetDateStamp(FILETIME *pDateStamp) = 0;
  };
#else
  typedef struct IExtractImage2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IExtractImage2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IExtractImage2 *This);
      ULONG (WINAPI *Release)(IExtractImage2 *This);
      HRESULT (WINAPI *GetLocation)(IExtractImage2 *This,LPWSTR pszPathBuffer,DWORD cch,DWORD *pdwPriority,const SIZE *prgSize,DWORD dwRecClrDepth,DWORD *pdwFlags);
      HRESULT (WINAPI *Extract)(IExtractImage2 *This,HBITMAP *phBmpThumbnail);
      HRESULT (WINAPI *GetDateStamp)(IExtractImage2 *This,FILETIME *pDateStamp);
    END_INTERFACE
  } IExtractImage2Vtbl;
  struct IExtractImage2 {
    CONST_VTBL struct IExtractImage2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IExtractImage2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IExtractImage2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IExtractImage2_Release(This) (This)->lpVtbl->Release(This)
#define IExtractImage2_GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags) (This)->lpVtbl->GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)
#define IExtractImage2_Extract(This,phBmpThumbnail) (This)->lpVtbl->Extract(This,phBmpThumbnail)
#define IExtractImage2_GetDateStamp(This,pDateStamp) (This)->lpVtbl->GetDateStamp(This,pDateStamp)
#endif
#endif
  HRESULT WINAPI IExtractImage2_GetDateStamp_Proxy(IExtractImage2 *This,FILETIME *pDateStamp);
  void __RPC_STUB IExtractImage2_GetDateStamp_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef IExtractImage2 *LPEXTRACTIMAGE2;
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0227_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0227_v0_0_s_ifspec;
#ifndef __IUserEventTimerCallback_INTERFACE_DEFINED__
#define __IUserEventTimerCallback_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IUserEventTimerCallback;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IUserEventTimerCallback : public IUnknown {
  public:
    virtual HRESULT WINAPI UserEventTimerProc(ULONG uUserEventTimerID,UINT uTimerElapse) = 0;
  };
#else
  typedef struct IUserEventTimerCallbackVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IUserEventTimerCallback *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IUserEventTimerCallback *This);
      ULONG (WINAPI *Release)(IUserEventTimerCallback *This);
      HRESULT (WINAPI *UserEventTimerProc)(IUserEventTimerCallback *This,ULONG uUserEventTimerID,UINT uTimerElapse);
    END_INTERFACE
  } IUserEventTimerCallbackVtbl;
  struct IUserEventTimerCallback {
    CONST_VTBL struct IUserEventTimerCallbackVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IUserEventTimerCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IUserEventTimerCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUserEventTimerCallback_Release(This) (This)->lpVtbl->Release(This)
#define IUserEventTimerCallback_UserEventTimerProc(This,uUserEventTimerID,uTimerElapse) (This)->lpVtbl->UserEventTimerProc(This,uUserEventTimerID,uTimerElapse)
#endif
#endif
  HRESULT WINAPI IUserEventTimerCallback_UserEventTimerProc_Proxy(IUserEventTimerCallback *This,ULONG uUserEventTimerID,UINT uTimerElapse);
  void __RPC_STUB IUserEventTimerCallback_UserEventTimerProc_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0228_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0228_v0_0_s_ifspec;
#ifndef __IUserEventTimer_INTERFACE_DEFINED__
#define __IUserEventTimer_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IUserEventTimer;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IUserEventTimer : public IUnknown {
  public:
    virtual HRESULT WINAPI SetUserEventTimer(HWND hWnd,UINT uCallbackMessage,UINT uTimerElapse,IUserEventTimerCallback *pUserEventTimerCallback,ULONG *puUserEventTimerID) = 0;
    virtual HRESULT WINAPI KillUserEventTimer(HWND hWnd,ULONG uUserEventTimerID) = 0;
    virtual HRESULT WINAPI GetUserEventTimerElapsed(HWND hWnd,ULONG uUserEventTimerID,UINT *puTimerElapsed) = 0;
    virtual HRESULT WINAPI InitTimerTickInterval(UINT uTimerTickIntervalMs) = 0;
  };
#else
  typedef struct IUserEventTimerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IUserEventTimer *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IUserEventTimer *This);
      ULONG (WINAPI *Release)(IUserEventTimer *This);
      HRESULT (WINAPI *SetUserEventTimer)(IUserEventTimer *This,HWND hWnd,UINT uCallbackMessage,UINT uTimerElapse,IUserEventTimerCallback *pUserEventTimerCallback,ULONG *puUserEventTimerID);
      HRESULT (WINAPI *KillUserEventTimer)(IUserEventTimer *This,HWND hWnd,ULONG uUserEventTimerID);
      HRESULT (WINAPI *GetUserEventTimerElapsed)(IUserEventTimer *This,HWND hWnd,ULONG uUserEventTimerID,UINT *puTimerElapsed);
      HRESULT (WINAPI *InitTimerTickInterval)(IUserEventTimer *This,UINT uTimerTickIntervalMs);
    END_INTERFACE
  } IUserEventTimerVtbl;
  struct IUserEventTimer {
    CONST_VTBL struct IUserEventTimerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IUserEventTimer_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IUserEventTimer_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IUserEventTimer_Release(This) (This)->lpVtbl->Release(This)
#define IUserEventTimer_SetUserEventTimer(This,hWnd,uCallbackMessage,uTimerElapse,pUserEventTimerCallback,puUserEventTimerID) (This)->lpVtbl->SetUserEventTimer(This,hWnd,uCallbackMessage,uTimerElapse,pUserEventTimerCallback,puUserEventTimerID)
#define IUserEventTimer_KillUserEventTimer(This,hWnd,uUserEventTimerID) (This)->lpVtbl->KillUserEventTimer(This,hWnd,uUserEventTimerID)
#define IUserEventTimer_GetUserEventTimerElapsed(This,hWnd,uUserEventTimerID,puTimerElapsed) (This)->lpVtbl->GetUserEventTimerElapsed(This,hWnd,uUserEventTimerID,puTimerElapsed)
#define IUserEventTimer_InitTimerTickInterval(This,uTimerTickIntervalMs) (This)->lpVtbl->InitTimerTickInterval(This,uTimerTickIntervalMs)
#endif
#endif
  HRESULT WINAPI IUserEventTimer_SetUserEventTimer_Proxy(IUserEventTimer *This,HWND hWnd,UINT uCallbackMessage,UINT uTimerElapse,IUserEventTimerCallback *pUserEventTimerCallback,ULONG *puUserEventTimerID);
  void __RPC_STUB IUserEventTimer_SetUserEventTimer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUserEventTimer_KillUserEventTimer_Proxy(IUserEventTimer *This,HWND hWnd,ULONG uUserEventTimerID);
  void __RPC_STUB IUserEventTimer_KillUserEventTimer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUserEventTimer_GetUserEventTimerElapsed_Proxy(IUserEventTimer *This,HWND hWnd,ULONG uUserEventTimerID,UINT *puTimerElapsed);
  void __RPC_STUB IUserEventTimer_GetUserEventTimerElapsed_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IUserEventTimer_InitTimerTickInterval_Proxy(IUserEventTimer *This,UINT uTimerTickIntervalMs);
  void __RPC_STUB IUserEventTimer_InitTimerTickInterval_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IDockingWindow_INTERFACE_DEFINED__
#define __IDockingWindow_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDockingWindow;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDockingWindow : public IOleWindow {
  public:
    virtual HRESULT WINAPI ShowDW(WINBOOL fShow) = 0;
    virtual HRESULT WINAPI CloseDW(DWORD dwReserved) = 0;
    virtual HRESULT WINAPI ResizeBorderDW(LPCRECT prcBorder,IUnknown *punkToolbarSite,WINBOOL fReserved) = 0;
  };
#else
  typedef struct IDockingWindowVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDockingWindow *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDockingWindow *This);
      ULONG (WINAPI *Release)(IDockingWindow *This);
      HRESULT (WINAPI *GetWindow)(IDockingWindow *This,HWND *phwnd);
      HRESULT (WINAPI *ContextSensitiveHelp)(IDockingWindow *This,WINBOOL fEnterMode);
      HRESULT (WINAPI *ShowDW)(IDockingWindow *This,WINBOOL fShow);
      HRESULT (WINAPI *CloseDW)(IDockingWindow *This,DWORD dwReserved);
      HRESULT (WINAPI *ResizeBorderDW)(IDockingWindow *This,LPCRECT prcBorder,IUnknown *punkToolbarSite,WINBOOL fReserved);
    END_INTERFACE
  } IDockingWindowVtbl;
  struct IDockingWindow {
    CONST_VTBL struct IDockingWindowVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDockingWindow_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDockingWindow_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDockingWindow_Release(This) (This)->lpVtbl->Release(This)
#define IDockingWindow_GetWindow(This,phwnd) (This)->lpVtbl->GetWindow(This,phwnd)
#define IDockingWindow_ContextSensitiveHelp(This,fEnterMode) (This)->lpVtbl->ContextSensitiveHelp(This,fEnterMode)
#define IDockingWindow_ShowDW(This,fShow) (This)->lpVtbl->ShowDW(This,fShow)
#define IDockingWindow_CloseDW(This,dwReserved) (This)->lpVtbl->CloseDW(This,dwReserved)
#define IDockingWindow_ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved) (This)->lpVtbl->ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)
#endif
#endif
  HRESULT WINAPI IDockingWindow_ShowDW_Proxy(IDockingWindow *This,WINBOOL fShow);
  void __RPC_STUB IDockingWindow_ShowDW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDockingWindow_CloseDW_Proxy(IDockingWindow *This,DWORD dwReserved);
  void __RPC_STUB IDockingWindow_CloseDW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDockingWindow_ResizeBorderDW_Proxy(IDockingWindow *This,LPCRECT prcBorder,IUnknown *punkToolbarSite,WINBOOL fReserved);
  void __RPC_STUB IDockingWindow_ResizeBorderDW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define DBIM_MINSIZE 0x0001
#define DBIM_MAXSIZE 0x0002
#define DBIM_INTEGRAL 0x0004
#define DBIM_ACTUAL 0x0008
#define DBIM_TITLE 0x0010
#define DBIM_MODEFLAGS 0x0020
#define DBIM_BKCOLOR 0x0040

#include <pshpack8.h>

  typedef struct __MIDL___MIDL_itf_shobjidl_0230_0001 {
    DWORD dwMask;
    POINTL ptMinSize;
    POINTL ptMaxSize;
    POINTL ptIntegral;
    POINTL ptActual;
    WCHAR wszTitle[256];
    DWORD dwModeFlags;
    COLORREF crBkgnd;
  } DESKBANDINFO;

#include <poppack.h>
#define DBIMF_NORMAL 0x0000
#define DBIMF_FIXED 0x0001
#define DBIMF_FIXEDBMP 0x0004
#define DBIMF_VARIABLEHEIGHT 0x0008
#define DBIMF_UNDELETEABLE 0x0010
#define DBIMF_DEBOSSED 0x0020
#define DBIMF_BKCOLOR 0x0040
#define DBIMF_USECHEVRON 0x0080
#define DBIMF_BREAK 0x0100
#define DBIMF_ADDTOFRONT 0x0200
#define DBIMF_TOPALIGN 0x0400
#define DBIF_VIEWMODE_NORMAL 0x0000
#define DBIF_VIEWMODE_VERTICAL 0x0001
#define DBIF_VIEWMODE_FLOATING 0x0002
#define DBIF_VIEWMODE_TRANSPARENT 0x0004

  enum __MIDL___MIDL_itf_shobjidl_0230_0002 {
    DBID_BANDINFOCHANGED = 0,DBID_SHOWONLY = 1,DBID_MAXIMIZEBAND = 2,DBID_PUSHCHEVRON = 3,DBID_DELAYINIT = 4,DBID_FINISHINIT = 5,
    DBID_SETWINDOWTHEME = 6,DBID_PERMITAUTOHIDE = 7
  };
#define DBPC_SELECTFIRST (DWORD)-1
#define DBPC_SELECTLAST (DWORD)-2
#define CGID_DeskBand IID_IDeskBand

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0230_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0230_v0_0_s_ifspec;
#ifndef __IDeskBand_INTERFACE_DEFINED__
#define __IDeskBand_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDeskBand;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDeskBand : public IDockingWindow {
  public:
    virtual HRESULT WINAPI GetBandInfo(DWORD dwBandID,DWORD dwViewMode,DESKBANDINFO *pdbi) = 0;
  };
#else
  typedef struct IDeskBandVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDeskBand *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDeskBand *This);
      ULONG (WINAPI *Release)(IDeskBand *This);
      HRESULT (WINAPI *GetWindow)(IDeskBand *This,HWND *phwnd);
      HRESULT (WINAPI *ContextSensitiveHelp)(IDeskBand *This,WINBOOL fEnterMode);
      HRESULT (WINAPI *ShowDW)(IDeskBand *This,WINBOOL fShow);
      HRESULT (WINAPI *CloseDW)(IDeskBand *This,DWORD dwReserved);
      HRESULT (WINAPI *ResizeBorderDW)(IDeskBand *This,LPCRECT prcBorder,IUnknown *punkToolbarSite,WINBOOL fReserved);
      HRESULT (WINAPI *GetBandInfo)(IDeskBand *This,DWORD dwBandID,DWORD dwViewMode,DESKBANDINFO *pdbi);
    END_INTERFACE
  } IDeskBandVtbl;
  struct IDeskBand {
    CONST_VTBL struct IDeskBandVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDeskBand_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDeskBand_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDeskBand_Release(This) (This)->lpVtbl->Release(This)
#define IDeskBand_GetWindow(This,phwnd) (This)->lpVtbl->GetWindow(This,phwnd)
#define IDeskBand_ContextSensitiveHelp(This,fEnterMode) (This)->lpVtbl->ContextSensitiveHelp(This,fEnterMode)
#define IDeskBand_ShowDW(This,fShow) (This)->lpVtbl->ShowDW(This,fShow)
#define IDeskBand_CloseDW(This,dwReserved) (This)->lpVtbl->CloseDW(This,dwReserved)
#define IDeskBand_ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved) (This)->lpVtbl->ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)
#define IDeskBand_GetBandInfo(This,dwBandID,dwViewMode,pdbi) (This)->lpVtbl->GetBandInfo(This,dwBandID,dwViewMode,pdbi)
#endif
#endif
  HRESULT WINAPI IDeskBand_GetBandInfo_Proxy(IDeskBand *This,DWORD dwBandID,DWORD dwViewMode,DESKBANDINFO *pdbi);
  void __RPC_STUB IDeskBand_GetBandInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ITaskbarList_INTERFACE_DEFINED__
#define __ITaskbarList_INTERFACE_DEFINED__
  DEFINE_GUID(IID_ITaskbarList,0x56FDF342L,0xFD6D,0x11D0,0x95,0x8A,0x00,0x60,0x97,0xC9,0xA0,0x90);
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ITaskbarList : public IUnknown {
  public:
    virtual HRESULT WINAPI HrInit(void) = 0;
    virtual HRESULT WINAPI AddTab(HWND hwnd) = 0;
    virtual HRESULT WINAPI DeleteTab(HWND hwnd) = 0;
    virtual HRESULT WINAPI ActivateTab(HWND hwnd) = 0;
    virtual HRESULT WINAPI SetActiveAlt(HWND hwnd) = 0;
  };
#else
  typedef struct ITaskbarListVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ITaskbarList *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ITaskbarList *This);
      ULONG (WINAPI *Release)(ITaskbarList *This);
      HRESULT (WINAPI *HrInit)(ITaskbarList *This);
      HRESULT (WINAPI *AddTab)(ITaskbarList *This,HWND hwnd);
      HRESULT (WINAPI *DeleteTab)(ITaskbarList *This,HWND hwnd);
      HRESULT (WINAPI *ActivateTab)(ITaskbarList *This,HWND hwnd);
      HRESULT (WINAPI *SetActiveAlt)(ITaskbarList *This,HWND hwnd);
    END_INTERFACE
  } ITaskbarListVtbl;
  struct ITaskbarList {
    CONST_VTBL struct ITaskbarListVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ITaskbarList_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITaskbarList_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITaskbarList_Release(This) (This)->lpVtbl->Release(This)
#define ITaskbarList_HrInit(This) (This)->lpVtbl->HrInit(This)
#define ITaskbarList_AddTab(This,hwnd) (This)->lpVtbl->AddTab(This,hwnd)
#define ITaskbarList_DeleteTab(This,hwnd) (This)->lpVtbl->DeleteTab(This,hwnd)
#define ITaskbarList_ActivateTab(This,hwnd) (This)->lpVtbl->ActivateTab(This,hwnd)
#define ITaskbarList_SetActiveAlt(This,hwnd) (This)->lpVtbl->SetActiveAlt(This,hwnd)
#endif
#endif
  HRESULT WINAPI ITaskbarList_HrInit_Proxy(ITaskbarList *This);
  void __RPC_STUB ITaskbarList_HrInit_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITaskbarList_AddTab_Proxy(ITaskbarList *This,HWND hwnd);
  void __RPC_STUB ITaskbarList_AddTab_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITaskbarList_DeleteTab_Proxy(ITaskbarList *This,HWND hwnd);
  void __RPC_STUB ITaskbarList_DeleteTab_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITaskbarList_ActivateTab_Proxy(ITaskbarList *This,HWND hwnd);
  void __RPC_STUB ITaskbarList_ActivateTab_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITaskbarList_SetActiveAlt_Proxy(ITaskbarList *This,HWND hwnd);
  void __RPC_STUB ITaskbarList_SetActiveAlt_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ITaskbarList2_INTERFACE_DEFINED__
#define __ITaskbarList2_INTERFACE_DEFINED__
  DEFINE_GUID(IID_ITaskbarList2,0x602D4995L,0xB13A,0x429b,0xA6,0x6E,0x19,0x35,0xE4,0x4F,0x43,0x17);
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ITaskbarList2 : public ITaskbarList {
  public:
    virtual HRESULT WINAPI MarkFullscreenWindow(HWND hwnd,WINBOOL fFullscreen) = 0;
  };
#else
  typedef struct ITaskbarList2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ITaskbarList2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ITaskbarList2 *This);
      ULONG (WINAPI *Release)(ITaskbarList2 *This);
      HRESULT (WINAPI *HrInit)(ITaskbarList2 *This);
      HRESULT (WINAPI *AddTab)(ITaskbarList2 *This,HWND hwnd);
      HRESULT (WINAPI *DeleteTab)(ITaskbarList2 *This,HWND hwnd);
      HRESULT (WINAPI *ActivateTab)(ITaskbarList2 *This,HWND hwnd);
      HRESULT (WINAPI *SetActiveAlt)(ITaskbarList2 *This,HWND hwnd);
      HRESULT (WINAPI *MarkFullscreenWindow)(ITaskbarList2 *This,HWND hwnd,WINBOOL fFullscreen);
    END_INTERFACE
  } ITaskbarList2Vtbl;
  struct ITaskbarList2 {
    CONST_VTBL struct ITaskbarList2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ITaskbarList2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITaskbarList2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITaskbarList2_Release(This) (This)->lpVtbl->Release(This)
#define ITaskbarList2_HrInit(This) (This)->lpVtbl->HrInit(This)
#define ITaskbarList2_AddTab(This,hwnd) (This)->lpVtbl->AddTab(This,hwnd)
#define ITaskbarList2_DeleteTab(This,hwnd) (This)->lpVtbl->DeleteTab(This,hwnd)
#define ITaskbarList2_ActivateTab(This,hwnd) (This)->lpVtbl->ActivateTab(This,hwnd)
#define ITaskbarList2_SetActiveAlt(This,hwnd) (This)->lpVtbl->SetActiveAlt(This,hwnd)
#define ITaskbarList2_MarkFullscreenWindow(This,hwnd,fFullscreen) (This)->lpVtbl->MarkFullscreenWindow(This,hwnd,fFullscreen)
#endif
#endif
  HRESULT WINAPI ITaskbarList2_MarkFullscreenWindow_Proxy(ITaskbarList2 *This,HWND hwnd,WINBOOL fFullscreen);
  void __RPC_STUB ITaskbarList2_MarkFullscreenWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifdef MIDL_PASS
typedef IUnknown *HIMAGELIST;
#endif

typedef enum THUMBBUTTONFLAGS {
    THBF_ENABLED = 0x0,
    THBF_DISABLED = 0x1,
    THBF_DISMISSONCLICK = 0x2,
    THBF_NOBACKGROUND = 0x4,
    THBF_HIDDEN = 0x8,
    THBF_NONINTERACTIVE = 0x10
} THUMBBUTTONFLAGS;
DEFINE_ENUM_FLAG_OPERATORS(THUMBBUTTONFLAGS)

typedef enum THUMBBUTTONMASK {
    THB_BITMAP = 0x1,
    THB_ICON = 0x2,
    THB_TOOLTIP = 0x4,
    THB_FLAGS = 0x8
} THUMBBUTTONMASK;
DEFINE_ENUM_FLAG_OPERATORS(THUMBBUTTONMASK)

#include <pshpack8.h>
typedef struct THUMBBUTTON {
    THUMBBUTTONMASK dwMask;
    UINT iId;
    UINT iBitmap;
    HICON hIcon;
    WCHAR szTip[260];
    THUMBBUTTONFLAGS dwFlags;
} THUMBBUTTON;
typedef struct THUMBBUTTON *LPTHUMBBUTTON;
#include <poppack.h>

/*****************************************************************************
 * ITaskbarList3 interface
 */
#ifndef __ITaskbarList3_INTERFACE_DEFINED__
#define __ITaskbarList3_INTERFACE_DEFINED__

typedef enum TBPFLAG {
    TBPF_NOPROGRESS = 0x0,
    TBPF_INDETERMINATE = 0x1,
    TBPF_NORMAL = 0x2,
    TBPF_ERROR = 0x4,
    TBPF_PAUSED = 0x8
} TBPFLAG;
DEFINE_ENUM_FLAG_OPERATORS(TBPFLAG)

DEFINE_GUID(IID_ITaskbarList3, 0xea1afb91, 0x9e28, 0x4b86, 0x90,0xe9, 0x9e,0x9f,0x8a,0x5e,0xef,0xaf);
#if defined(__cplusplus) && !defined(CINTERFACE)
interface ITaskbarList3 : public ITaskbarList2
{
    virtual HRESULT STDMETHODCALLTYPE SetProgressValue(
        HWND hwnd,
        ULONGLONG ullCompleted,
        ULONGLONG ullTotal) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetProgressState(
        HWND hwnd,
        TBPFLAG tbpFlags) = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterTab(
        HWND hwndTab,
        HWND hwndMDI) = 0;

    virtual HRESULT STDMETHODCALLTYPE UnregisterTab(
        HWND hwndTab) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetTabOrder(
        HWND hwndTab,
        HWND hwndInsertBefore) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetTabActive(
        HWND hwndTab,
        HWND hwndMDI,
        DWORD dwReserved) = 0;

    virtual HRESULT STDMETHODCALLTYPE ThumbBarAddButtons(
        HWND hwnd,
        UINT cButtons,
        LPTHUMBBUTTON pButton) = 0;

    virtual HRESULT STDMETHODCALLTYPE ThumbBarUpdateButtons(
        HWND hwnd,
        UINT cButtons,
        LPTHUMBBUTTON pButton) = 0;

    virtual HRESULT STDMETHODCALLTYPE ThumbBarSetImageList(
        HWND hwnd,
        HIMAGELIST himl) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetOverlayIcon(
        HWND hwnd,
        HICON hIcon,
        LPCWSTR pszDescription) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetThumbnailTooltip(
        HWND hwnd,
        LPCWSTR pszTip) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetThumbnailClip(
        HWND hwnd,
        RECT *prcClip) = 0;

};
#else
typedef struct ITaskbarList3Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITaskbarList3* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITaskbarList3* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITaskbarList3* This);

    /*** ITaskbarList methods ***/
    HRESULT (STDMETHODCALLTYPE *HrInit)(
        ITaskbarList3* This);

    HRESULT (STDMETHODCALLTYPE *AddTab)(
        ITaskbarList3* This,
        HWND hwnd);

    HRESULT (STDMETHODCALLTYPE *DeleteTab)(
        ITaskbarList3* This,
        HWND hwnd);

    HRESULT (STDMETHODCALLTYPE *ActivateTab)(
        ITaskbarList3* This,
        HWND hwnd);

    HRESULT (STDMETHODCALLTYPE *SetActiveAlt)(
        ITaskbarList3* This,
        HWND hwnd);

    /*** ITaskbarList2 methods ***/
    HRESULT (STDMETHODCALLTYPE *MarkFullscreenWindow)(
        ITaskbarList3* This,
        HWND hwnd,
        BOOL fullscreen);

    /*** ITaskbarList3 methods ***/
    HRESULT (STDMETHODCALLTYPE *SetProgressValue)(
        ITaskbarList3* This,
        HWND hwnd,
        ULONGLONG ullCompleted,
        ULONGLONG ullTotal);

    HRESULT (STDMETHODCALLTYPE *SetProgressState)(
        ITaskbarList3* This,
        HWND hwnd,
        TBPFLAG tbpFlags);

    HRESULT (STDMETHODCALLTYPE *RegisterTab)(
        ITaskbarList3* This,
        HWND hwndTab,
        HWND hwndMDI);

    HRESULT (STDMETHODCALLTYPE *UnregisterTab)(
        ITaskbarList3* This,
        HWND hwndTab);

    HRESULT (STDMETHODCALLTYPE *SetTabOrder)(
        ITaskbarList3* This,
        HWND hwndTab,
        HWND hwndInsertBefore);

    HRESULT (STDMETHODCALLTYPE *SetTabActive)(
        ITaskbarList3* This,
        HWND hwndTab,
        HWND hwndMDI,
        DWORD dwReserved);

    HRESULT (STDMETHODCALLTYPE *ThumbBarAddButtons)(
        ITaskbarList3* This,
        HWND hwnd,
        UINT cButtons,
        LPTHUMBBUTTON pButton);

    HRESULT (STDMETHODCALLTYPE *ThumbBarUpdateButtons)(
        ITaskbarList3* This,
        HWND hwnd,
        UINT cButtons,
        LPTHUMBBUTTON pButton);

    HRESULT (STDMETHODCALLTYPE *ThumbBarSetImageList)(
        ITaskbarList3* This,
        HWND hwnd,
        HIMAGELIST himl);

    HRESULT (STDMETHODCALLTYPE *SetOverlayIcon)(
        ITaskbarList3* This,
        HWND hwnd,
        HICON hIcon,
        LPCWSTR pszDescription);

    HRESULT (STDMETHODCALLTYPE *SetThumbnailTooltip)(
        ITaskbarList3* This,
        HWND hwnd,
        LPCWSTR pszTip);

    HRESULT (STDMETHODCALLTYPE *SetThumbnailClip)(
        ITaskbarList3* This,
        HWND hwnd,
        RECT *prcClip);

    END_INTERFACE
} ITaskbarList3Vtbl;
interface ITaskbarList3 {
    CONST_VTBL ITaskbarList3Vtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define ITaskbarList3_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITaskbarList3_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITaskbarList3_Release(This) (This)->lpVtbl->Release(This)
/*** ITaskbarList methods ***/
#define ITaskbarList3_HrInit(This) (This)->lpVtbl->HrInit(This)
#define ITaskbarList3_AddTab(This,hwnd) (This)->lpVtbl->AddTab(This,hwnd)
#define ITaskbarList3_DeleteTab(This,hwnd) (This)->lpVtbl->DeleteTab(This,hwnd)
#define ITaskbarList3_ActivateTab(This,hwnd) (This)->lpVtbl->ActivateTab(This,hwnd)
#define ITaskbarList3_SetActiveAlt(This,hwnd) (This)->lpVtbl->SetActiveAlt(This,hwnd)
/*** ITaskbarList2 methods ***/
#define ITaskbarList3_MarkFullscreenWindow(This,hwnd,fullscreen) (This)->lpVtbl->MarkFullscreenWindow(This,hwnd,fullscreen)
/*** ITaskbarList3 methods ***/
#define ITaskbarList3_SetProgressValue(This,hwnd,ullCompleted,ullTotal) (This)->lpVtbl->SetProgressValue(This,hwnd,ullCompleted,ullTotal)
#define ITaskbarList3_SetProgressState(This,hwnd,tbpFlags) (This)->lpVtbl->SetProgressState(This,hwnd,tbpFlags)
#define ITaskbarList3_RegisterTab(This,hwndTab,hwndMDI) (This)->lpVtbl->RegisterTab(This,hwndTab,hwndMDI)
#define ITaskbarList3_UnregisterTab(This,hwndTab) (This)->lpVtbl->UnregisterTab(This,hwndTab)
#define ITaskbarList3_SetTabOrder(This,hwndTab,hwndInsertBefore) (This)->lpVtbl->SetTabOrder(This,hwndTab,hwndInsertBefore)
#define ITaskbarList3_SetTabActive(This,hwndTab,hwndMDI,dwReserved) (This)->lpVtbl->SetTabActive(This,hwndTab,hwndMDI,dwReserved)
#define ITaskbarList3_ThumbBarAddButtons(This,hwnd,cButtons,pButton) (This)->lpVtbl->ThumbBarAddButtons(This,hwnd,cButtons,pButton)
#define ITaskbarList3_ThumbBarUpdateButtons(This,hwnd,cButtons,pButton) (This)->lpVtbl->ThumbBarUpdateButtons(This,hwnd,cButtons,pButton)
#define ITaskbarList3_ThumbBarSetImageList(This,hwnd,himl) (This)->lpVtbl->ThumbBarSetImageList(This,hwnd,himl)
#define ITaskbarList3_SetOverlayIcon(This,hwnd,hIcon,pszDescription) (This)->lpVtbl->SetOverlayIcon(This,hwnd,hIcon,pszDescription)
#define ITaskbarList3_SetThumbnailTooltip(This,hwnd,pszTip) (This)->lpVtbl->SetThumbnailTooltip(This,hwnd,pszTip)
#define ITaskbarList3_SetThumbnailClip(This,hwnd,prcClip) (This)->lpVtbl->SetThumbnailClip(This,hwnd,prcClip)
#endif

#endif
#endif  /* __ITaskbarList3_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ITaskbarList4 interface
 */
#ifndef __ITaskbarList4_INTERFACE_DEFINED__
#define __ITaskbarList4_INTERFACE_DEFINED__

typedef enum STPFLAG {
    STPF_NONE = 0x0,
    STPF_USEAPPTHUMBNAILALWAYS = 0x1,
    STPF_USEAPPTHUMBNAILWHENACTIVE = 0x2,
    STPF_USEAPPPEEKALWAYS = 0x4,
    STPF_USEAPPPEEKWHENACTIVE = 0x8
} STPFLAG;
DEFINE_ENUM_FLAG_OPERATORS(STPFLAG)

DEFINE_GUID(IID_ITaskbarList4, 0xc43dc798, 0x95d1, 0x4bea, 0x90,0x30, 0xbb,0x99,0xe2,0x98,0x3a,0x1a);
#if defined(__cplusplus) && !defined(CINTERFACE)
interface ITaskbarList4 : public ITaskbarList3
{
    virtual HRESULT STDMETHODCALLTYPE SetTabProperties(
        HWND hwndTab,
        STPFLAG stpFlags) = 0;

};
#else
typedef struct ITaskbarList4Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITaskbarList4* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITaskbarList4* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITaskbarList4* This);

    /*** ITaskbarList methods ***/
    HRESULT (STDMETHODCALLTYPE *HrInit)(
        ITaskbarList4* This);

    HRESULT (STDMETHODCALLTYPE *AddTab)(
        ITaskbarList4* This,
        HWND hwnd);

    HRESULT (STDMETHODCALLTYPE *DeleteTab)(
        ITaskbarList4* This,
        HWND hwnd);

    HRESULT (STDMETHODCALLTYPE *ActivateTab)(
        ITaskbarList4* This,
        HWND hwnd);

    HRESULT (STDMETHODCALLTYPE *SetActiveAlt)(
        ITaskbarList4* This,
        HWND hwnd);

    /*** ITaskbarList2 methods ***/
    HRESULT (STDMETHODCALLTYPE *MarkFullscreenWindow)(
        ITaskbarList4* This,
        HWND hwnd,
        BOOL fullscreen);

    /*** ITaskbarList3 methods ***/
    HRESULT (STDMETHODCALLTYPE *SetProgressValue)(
        ITaskbarList4* This,
        HWND hwnd,
        ULONGLONG ullCompleted,
        ULONGLONG ullTotal);

    HRESULT (STDMETHODCALLTYPE *SetProgressState)(
        ITaskbarList4* This,
        HWND hwnd,
        TBPFLAG tbpFlags);

    HRESULT (STDMETHODCALLTYPE *RegisterTab)(
        ITaskbarList4* This,
        HWND hwndTab,
        HWND hwndMDI);

    HRESULT (STDMETHODCALLTYPE *UnregisterTab)(
        ITaskbarList4* This,
        HWND hwndTab);

    HRESULT (STDMETHODCALLTYPE *SetTabOrder)(
        ITaskbarList4* This,
        HWND hwndTab,
        HWND hwndInsertBefore);

    HRESULT (STDMETHODCALLTYPE *SetTabActive)(
        ITaskbarList4* This,
        HWND hwndTab,
        HWND hwndMDI,
        DWORD dwReserved);

    HRESULT (STDMETHODCALLTYPE *ThumbBarAddButtons)(
        ITaskbarList4* This,
        HWND hwnd,
        UINT cButtons,
        LPTHUMBBUTTON pButton);

    HRESULT (STDMETHODCALLTYPE *ThumbBarUpdateButtons)(
        ITaskbarList4* This,
        HWND hwnd,
        UINT cButtons,
        LPTHUMBBUTTON pButton);

    HRESULT (STDMETHODCALLTYPE *ThumbBarSetImageList)(
        ITaskbarList4* This,
        HWND hwnd,
        HIMAGELIST himl);

    HRESULT (STDMETHODCALLTYPE *SetOverlayIcon)(
        ITaskbarList4* This,
        HWND hwnd,
        HICON hIcon,
        LPCWSTR pszDescription);

    HRESULT (STDMETHODCALLTYPE *SetThumbnailTooltip)(
        ITaskbarList4* This,
        HWND hwnd,
        LPCWSTR pszTip);

    HRESULT (STDMETHODCALLTYPE *SetThumbnailClip)(
        ITaskbarList4* This,
        HWND hwnd,
        RECT *prcClip);

    /*** ITaskbarList4 methods ***/
    HRESULT (STDMETHODCALLTYPE *SetTabProperties)(
        ITaskbarList4* This,
        HWND hwndTab,
        STPFLAG stpFlags);

    END_INTERFACE
} ITaskbarList4Vtbl;
interface ITaskbarList4 {
    CONST_VTBL ITaskbarList4Vtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define ITaskbarList4_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITaskbarList4_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITaskbarList4_Release(This) (This)->lpVtbl->Release(This)
/*** ITaskbarList methods ***/
#define ITaskbarList4_HrInit(This) (This)->lpVtbl->HrInit(This)
#define ITaskbarList4_AddTab(This,hwnd) (This)->lpVtbl->AddTab(This,hwnd)
#define ITaskbarList4_DeleteTab(This,hwnd) (This)->lpVtbl->DeleteTab(This,hwnd)
#define ITaskbarList4_ActivateTab(This,hwnd) (This)->lpVtbl->ActivateTab(This,hwnd)
#define ITaskbarList4_SetActiveAlt(This,hwnd) (This)->lpVtbl->SetActiveAlt(This,hwnd)
/*** ITaskbarList2 methods ***/
#define ITaskbarList4_MarkFullscreenWindow(This,hwnd,fullscreen) (This)->lpVtbl->MarkFullscreenWindow(This,hwnd,fullscreen)
/*** ITaskbarList3 methods ***/
#define ITaskbarList4_SetProgressValue(This,hwnd,ullCompleted,ullTotal) (This)->lpVtbl->SetProgressValue(This,hwnd,ullCompleted,ullTotal)
#define ITaskbarList4_SetProgressState(This,hwnd,tbpFlags) (This)->lpVtbl->SetProgressState(This,hwnd,tbpFlags)
#define ITaskbarList4_RegisterTab(This,hwndTab,hwndMDI) (This)->lpVtbl->RegisterTab(This,hwndTab,hwndMDI)
#define ITaskbarList4_UnregisterTab(This,hwndTab) (This)->lpVtbl->UnregisterTab(This,hwndTab)
#define ITaskbarList4_SetTabOrder(This,hwndTab,hwndInsertBefore) (This)->lpVtbl->SetTabOrder(This,hwndTab,hwndInsertBefore)
#define ITaskbarList4_SetTabActive(This,hwndTab,hwndMDI,dwReserved) (This)->lpVtbl->SetTabActive(This,hwndTab,hwndMDI,dwReserved)
#define ITaskbarList4_ThumbBarAddButtons(This,hwnd,cButtons,pButton) (This)->lpVtbl->ThumbBarAddButtons(This,hwnd,cButtons,pButton)
#define ITaskbarList4_ThumbBarUpdateButtons(This,hwnd,cButtons,pButton) (This)->lpVtbl->ThumbBarUpdateButtons(This,hwnd,cButtons,pButton)
#define ITaskbarList4_ThumbBarSetImageList(This,hwnd,himl) (This)->lpVtbl->ThumbBarSetImageList(This,hwnd,himl)
#define ITaskbarList4_SetOverlayIcon(This,hwnd,hIcon,pszDescription) (This)->lpVtbl->SetOverlayIcon(This,hwnd,hIcon,pszDescription)
#define ITaskbarList4_SetThumbnailTooltip(This,hwnd,pszTip) (This)->lpVtbl->SetThumbnailTooltip(This,hwnd,pszTip)
#define ITaskbarList4_SetThumbnailClip(This,hwnd,prcClip) (This)->lpVtbl->SetThumbnailClip(This,hwnd,prcClip)
/*** ITaskbarList4 methods ***/
#define ITaskbarList4_SetTabProperties(This,hwndTab,stpFlags) (This)->lpVtbl->SetTabProperties(This,hwndTab,stpFlags)
#endif

#endif
#endif  /* __ITaskbarList4_INTERFACE_DEFINED__ */

#ifndef __ICDBurn_INTERFACE_DEFINED__
#define __ICDBurn_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ICDBurn;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ICDBurn : public IUnknown {
  public:
    virtual HRESULT WINAPI GetRecorderDriveLetter(LPWSTR pszDrive,UINT cch) = 0;
    virtual HRESULT WINAPI Burn(HWND hwnd) = 0;
    virtual HRESULT WINAPI HasRecordableDrive(WINBOOL *pfHasRecorder) = 0;
  };
#else
  typedef struct ICDBurnVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ICDBurn *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ICDBurn *This);
      ULONG (WINAPI *Release)(ICDBurn *This);
      HRESULT (WINAPI *GetRecorderDriveLetter)(ICDBurn *This,LPWSTR pszDrive,UINT cch);
      HRESULT (WINAPI *Burn)(ICDBurn *This,HWND hwnd);
      HRESULT (WINAPI *HasRecordableDrive)(ICDBurn *This,WINBOOL *pfHasRecorder);
    END_INTERFACE
  } ICDBurnVtbl;
  struct ICDBurn {
    CONST_VTBL struct ICDBurnVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ICDBurn_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICDBurn_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICDBurn_Release(This) (This)->lpVtbl->Release(This)
#define ICDBurn_GetRecorderDriveLetter(This,pszDrive,cch) (This)->lpVtbl->GetRecorderDriveLetter(This,pszDrive,cch)
#define ICDBurn_Burn(This,hwnd) (This)->lpVtbl->Burn(This,hwnd)
#define ICDBurn_HasRecordableDrive(This,pfHasRecorder) (This)->lpVtbl->HasRecordableDrive(This,pfHasRecorder)
#endif
#endif
  HRESULT WINAPI ICDBurn_GetRecorderDriveLetter_Proxy(ICDBurn *This,LPWSTR pszDrive,UINT cch);
  void __RPC_STUB ICDBurn_GetRecorderDriveLetter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICDBurn_Burn_Proxy(ICDBurn *This,HWND hwnd);
  void __RPC_STUB ICDBurn_Burn_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICDBurn_HasRecordableDrive_Proxy(ICDBurn *This,WINBOOL *pfHasRecorder);
  void __RPC_STUB ICDBurn_HasRecordableDrive_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define IDD_WIZEXTN_FIRST 0x5000
#define IDD_WIZEXTN_LAST 0x5100

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0234_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0234_v0_0_s_ifspec;
#ifndef __IWizardSite_INTERFACE_DEFINED__
#define __IWizardSite_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWizardSite;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWizardSite : public IUnknown {
  public:
    virtual HRESULT WINAPI GetPreviousPage(HPROPSHEETPAGE *phpage) = 0;
    virtual HRESULT WINAPI GetNextPage(HPROPSHEETPAGE *phpage) = 0;
    virtual HRESULT WINAPI GetCancelledPage(HPROPSHEETPAGE *phpage) = 0;
  };
#else
  typedef struct IWizardSiteVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWizardSite *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWizardSite *This);
      ULONG (WINAPI *Release)(IWizardSite *This);
      HRESULT (WINAPI *GetPreviousPage)(IWizardSite *This,HPROPSHEETPAGE *phpage);
      HRESULT (WINAPI *GetNextPage)(IWizardSite *This,HPROPSHEETPAGE *phpage);
      HRESULT (WINAPI *GetCancelledPage)(IWizardSite *This,HPROPSHEETPAGE *phpage);
    END_INTERFACE
  } IWizardSiteVtbl;
  struct IWizardSite {
    CONST_VTBL struct IWizardSiteVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWizardSite_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWizardSite_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWizardSite_Release(This) (This)->lpVtbl->Release(This)
#define IWizardSite_GetPreviousPage(This,phpage) (This)->lpVtbl->GetPreviousPage(This,phpage)
#define IWizardSite_GetNextPage(This,phpage) (This)->lpVtbl->GetNextPage(This,phpage)
#define IWizardSite_GetCancelledPage(This,phpage) (This)->lpVtbl->GetCancelledPage(This,phpage)
#endif
#endif
  HRESULT WINAPI IWizardSite_GetPreviousPage_Proxy(IWizardSite *This,HPROPSHEETPAGE *phpage);
  void __RPC_STUB IWizardSite_GetPreviousPage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWizardSite_GetNextPage_Proxy(IWizardSite *This,HPROPSHEETPAGE *phpage);
  void __RPC_STUB IWizardSite_GetNextPage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWizardSite_GetCancelledPage_Proxy(IWizardSite *This,HPROPSHEETPAGE *phpage);
  void __RPC_STUB IWizardSite_GetCancelledPage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWizardExtension_INTERFACE_DEFINED__
#define __IWizardExtension_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWizardExtension;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWizardExtension : public IUnknown {
  public:
    virtual HRESULT WINAPI AddPages(HPROPSHEETPAGE *aPages,UINT cPages,UINT *pnPagesAdded) = 0;
    virtual HRESULT WINAPI GetFirstPage(HPROPSHEETPAGE *phpage) = 0;
    virtual HRESULT WINAPI GetLastPage(HPROPSHEETPAGE *phpage) = 0;
  };
#else
  typedef struct IWizardExtensionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWizardExtension *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWizardExtension *This);
      ULONG (WINAPI *Release)(IWizardExtension *This);
      HRESULT (WINAPI *AddPages)(IWizardExtension *This,HPROPSHEETPAGE *aPages,UINT cPages,UINT *pnPagesAdded);
      HRESULT (WINAPI *GetFirstPage)(IWizardExtension *This,HPROPSHEETPAGE *phpage);
      HRESULT (WINAPI *GetLastPage)(IWizardExtension *This,HPROPSHEETPAGE *phpage);
    END_INTERFACE
  } IWizardExtensionVtbl;
  struct IWizardExtension {
    CONST_VTBL struct IWizardExtensionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWizardExtension_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWizardExtension_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWizardExtension_Release(This) (This)->lpVtbl->Release(This)
#define IWizardExtension_AddPages(This,aPages,cPages,pnPagesAdded) (This)->lpVtbl->AddPages(This,aPages,cPages,pnPagesAdded)
#define IWizardExtension_GetFirstPage(This,phpage) (This)->lpVtbl->GetFirstPage(This,phpage)
#define IWizardExtension_GetLastPage(This,phpage) (This)->lpVtbl->GetLastPage(This,phpage)
#endif
#endif
  HRESULT WINAPI IWizardExtension_AddPages_Proxy(IWizardExtension *This,HPROPSHEETPAGE *aPages,UINT cPages,UINT *pnPagesAdded);
  void __RPC_STUB IWizardExtension_AddPages_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWizardExtension_GetFirstPage_Proxy(IWizardExtension *This,HPROPSHEETPAGE *phpage);
  void __RPC_STUB IWizardExtension_GetFirstPage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWizardExtension_GetLastPage_Proxy(IWizardExtension *This,HPROPSHEETPAGE *phpage);
  void __RPC_STUB IWizardExtension_GetLastPage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IWebWizardExtension_INTERFACE_DEFINED__
#define __IWebWizardExtension_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWebWizardExtension;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWebWizardExtension : public IWizardExtension {
  public:
    virtual HRESULT WINAPI SetInitialURL(LPCWSTR pszURL) = 0;
    virtual HRESULT WINAPI SetErrorURL(LPCWSTR pszErrorURL) = 0;
  };
#else
  typedef struct IWebWizardExtensionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWebWizardExtension *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWebWizardExtension *This);
      ULONG (WINAPI *Release)(IWebWizardExtension *This);
      HRESULT (WINAPI *AddPages)(IWebWizardExtension *This,HPROPSHEETPAGE *aPages,UINT cPages,UINT *pnPagesAdded);
      HRESULT (WINAPI *GetFirstPage)(IWebWizardExtension *This,HPROPSHEETPAGE *phpage);
      HRESULT (WINAPI *GetLastPage)(IWebWizardExtension *This,HPROPSHEETPAGE *phpage);
      HRESULT (WINAPI *SetInitialURL)(IWebWizardExtension *This,LPCWSTR pszURL);
      HRESULT (WINAPI *SetErrorURL)(IWebWizardExtension *This,LPCWSTR pszErrorURL);
    END_INTERFACE
  } IWebWizardExtensionVtbl;
  struct IWebWizardExtension {
    CONST_VTBL struct IWebWizardExtensionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWebWizardExtension_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWebWizardExtension_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWebWizardExtension_Release(This) (This)->lpVtbl->Release(This)
#define IWebWizardExtension_AddPages(This,aPages,cPages,pnPagesAdded) (This)->lpVtbl->AddPages(This,aPages,cPages,pnPagesAdded)
#define IWebWizardExtension_GetFirstPage(This,phpage) (This)->lpVtbl->GetFirstPage(This,phpage)
#define IWebWizardExtension_GetLastPage(This,phpage) (This)->lpVtbl->GetLastPage(This,phpage)
#define IWebWizardExtension_SetInitialURL(This,pszURL) (This)->lpVtbl->SetInitialURL(This,pszURL)
#define IWebWizardExtension_SetErrorURL(This,pszErrorURL) (This)->lpVtbl->SetErrorURL(This,pszErrorURL)
#endif
#endif
  HRESULT WINAPI IWebWizardExtension_SetInitialURL_Proxy(IWebWizardExtension *This,LPCWSTR pszURL);
  void __RPC_STUB IWebWizardExtension_SetInitialURL_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebWizardExtension_SetErrorURL_Proxy(IWebWizardExtension *This,LPCWSTR pszErrorURL);
  void __RPC_STUB IWebWizardExtension_SetErrorURL_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define SID_WebWizardHost IID_IWebWizardExtension
#define SHPWHF_NORECOMPRESS 0x00000001
#define SHPWHF_NONETPLACECREATE 0x00000002
#define SHPWHF_NOFILESELECTOR 0x00000004
#define SHPWHF_VALIDATEVIAWEBFOLDERS 0x00010000

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0237_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0237_v0_0_s_ifspec;
#ifndef __IPublishingWizard_INTERFACE_DEFINED__
#define __IPublishingWizard_INTERFACE_DEFINED__

  EXTERN_C const IID IID_IPublishingWizard;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IPublishingWizard : public IWizardExtension {
  public:
    virtual HRESULT WINAPI Initialize(IDataObject *pdo,DWORD dwOptions,LPCWSTR pszServiceProvider) = 0;
    virtual HRESULT WINAPI GetTransferManifest(HRESULT *phrFromTransfer,IXMLDOMDocument **pdocManifest) = 0;
  };
#else
  typedef struct IPublishingWizardVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IPublishingWizard *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IPublishingWizard *This);
      ULONG (WINAPI *Release)(IPublishingWizard *This);
      HRESULT (WINAPI *AddPages)(IPublishingWizard *This,HPROPSHEETPAGE *aPages,UINT cPages,UINT *pnPagesAdded);
      HRESULT (WINAPI *GetFirstPage)(IPublishingWizard *This,HPROPSHEETPAGE *phpage);
      HRESULT (WINAPI *GetLastPage)(IPublishingWizard *This,HPROPSHEETPAGE *phpage);
      HRESULT (WINAPI *Initialize)(IPublishingWizard *This,IDataObject *pdo,DWORD dwOptions,LPCWSTR pszServiceProvider);
      HRESULT (WINAPI *GetTransferManifest)(IPublishingWizard *This,HRESULT *phrFromTransfer,IXMLDOMDocument **pdocManifest);
    END_INTERFACE
  } IPublishingWizardVtbl;
  struct IPublishingWizard {
    CONST_VTBL struct IPublishingWizardVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IPublishingWizard_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPublishingWizard_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPublishingWizard_Release(This) (This)->lpVtbl->Release(This)
#define IPublishingWizard_AddPages(This,aPages,cPages,pnPagesAdded) (This)->lpVtbl->AddPages(This,aPages,cPages,pnPagesAdded)
#define IPublishingWizard_GetFirstPage(This,phpage) (This)->lpVtbl->GetFirstPage(This,phpage)
#define IPublishingWizard_GetLastPage(This,phpage) (This)->lpVtbl->GetLastPage(This,phpage)
#define IPublishingWizard_Initialize(This,pdo,dwOptions,pszServiceProvider) (This)->lpVtbl->Initialize(This,pdo,dwOptions,pszServiceProvider)
#define IPublishingWizard_GetTransferManifest(This,phrFromTransfer,pdocManifest) (This)->lpVtbl->GetTransferManifest(This,phrFromTransfer,pdocManifest)
#endif
#endif
  HRESULT WINAPI IPublishingWizard_Initialize_Proxy(IPublishingWizard *This,IDataObject *pdo,DWORD dwOptions,LPCWSTR pszServiceProvider);
  void __RPC_STUB IPublishingWizard_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IPublishingWizard_GetTransferManifest_Proxy(IPublishingWizard *This,HRESULT *phrFromTransfer,IXMLDOMDocument **pdocManifest);
  void __RPC_STUB IPublishingWizard_GetTransferManifest_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IFolderViewHost_INTERFACE_DEFINED__
#define __IFolderViewHost_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IFolderViewHost;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IFolderViewHost : public IUnknown {
  public:
    virtual HRESULT WINAPI Initialize(HWND hwndParent,IDataObject *pdo,RECT *prc) = 0;
  };
#else
  typedef struct IFolderViewHostVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IFolderViewHost *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IFolderViewHost *This);
      ULONG (WINAPI *Release)(IFolderViewHost *This);
      HRESULT (WINAPI *Initialize)(IFolderViewHost *This,HWND hwndParent,IDataObject *pdo,RECT *prc);
    END_INTERFACE
  } IFolderViewHostVtbl;
  struct IFolderViewHost {
    CONST_VTBL struct IFolderViewHostVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IFolderViewHost_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFolderViewHost_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFolderViewHost_Release(This) (This)->lpVtbl->Release(This)
#define IFolderViewHost_Initialize(This,hwndParent,pdo,prc) (This)->lpVtbl->Initialize(This,hwndParent,pdo,prc)
#endif
#endif
  HRESULT WINAPI IFolderViewHost_Initialize_Proxy(IFolderViewHost *This,HWND hwndParent,IDataObject *pdo,RECT *prc);
  void __RPC_STUB IFolderViewHost_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define ACDD_VISIBLE 0x0001

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0239_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0239_v0_0_s_ifspec;
#ifndef __IAutoCompleteDropDown_INTERFACE_DEFINED__
#define __IAutoCompleteDropDown_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IAutoCompleteDropDown;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IAutoCompleteDropDown : public IUnknown {
  public:
    virtual HRESULT WINAPI GetDropDownStatus(DWORD *pdwFlags,LPWSTR *ppwszString) = 0;
    virtual HRESULT WINAPI ResetEnumerator(void) = 0;
  };
#else
  typedef struct IAutoCompleteDropDownVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IAutoCompleteDropDown *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IAutoCompleteDropDown *This);
      ULONG (WINAPI *Release)(IAutoCompleteDropDown *This);
      HRESULT (WINAPI *GetDropDownStatus)(IAutoCompleteDropDown *This,DWORD *pdwFlags,LPWSTR *ppwszString);
      HRESULT (WINAPI *ResetEnumerator)(IAutoCompleteDropDown *This);
    END_INTERFACE
  } IAutoCompleteDropDownVtbl;
  struct IAutoCompleteDropDown {
    CONST_VTBL struct IAutoCompleteDropDownVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IAutoCompleteDropDown_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IAutoCompleteDropDown_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IAutoCompleteDropDown_Release(This) (This)->lpVtbl->Release(This)
#define IAutoCompleteDropDown_GetDropDownStatus(This,pdwFlags,ppwszString) (This)->lpVtbl->GetDropDownStatus(This,pdwFlags,ppwszString)
#define IAutoCompleteDropDown_ResetEnumerator(This) (This)->lpVtbl->ResetEnumerator(This)
#endif
#endif
  HRESULT WINAPI IAutoCompleteDropDown_GetDropDownStatus_Proxy(IAutoCompleteDropDown *This,DWORD *pdwFlags,LPWSTR *ppwszString);
  void __RPC_STUB IAutoCompleteDropDown_GetDropDownStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAutoCompleteDropDown_ResetEnumerator_Proxy(IAutoCompleteDropDown *This);
  void __RPC_STUB IAutoCompleteDropDown_ResetEnumerator_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define PPW_LAUNCHEDBYUSER 0x00000001

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0240_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0240_v0_0_s_ifspec;
#ifndef __IModalWindow_INTERFACE_DEFINED__
#define __IModalWindow_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IModalWindow;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IModalWindow : public IUnknown {
  public:
    virtual HRESULT WINAPI Show(HWND hwndParent) = 0;
  };
#else
  typedef struct IModalWindowVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IModalWindow *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IModalWindow *This);
      ULONG (WINAPI *Release)(IModalWindow *This);
      HRESULT (WINAPI *Show)(IModalWindow *This,HWND hwndParent);
    END_INTERFACE
  } IModalWindowVtbl;
  struct IModalWindow {
    CONST_VTBL struct IModalWindowVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IModalWindow_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IModalWindow_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IModalWindow_Release(This) (This)->lpVtbl->Release(This)
#define IModalWindow_Show(This,hwndParent) (This)->lpVtbl->Show(This,hwndParent)
#endif
#endif
  HRESULT WINAPI IModalWindow_Show_Proxy(IModalWindow *This,HWND hwndParent);
  void __RPC_STUB IModalWindow_Show_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IPassportWizard_INTERFACE_DEFINED__
#define __IPassportWizard_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IPassportWizard;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IPassportWizard : public IModalWindow {
  public:
    virtual HRESULT WINAPI SetOptions(DWORD dwOptions) = 0;
  };
#else
  typedef struct IPassportWizardVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IPassportWizard *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IPassportWizard *This);
      ULONG (WINAPI *Release)(IPassportWizard *This);
      HRESULT (WINAPI *Show)(IPassportWizard *This,HWND hwndParent);
      HRESULT (WINAPI *SetOptions)(IPassportWizard *This,DWORD dwOptions);
    END_INTERFACE
  } IPassportWizardVtbl;
  struct IPassportWizard {
    CONST_VTBL struct IPassportWizardVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IPassportWizard_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPassportWizard_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPassportWizard_Release(This) (This)->lpVtbl->Release(This)
#define IPassportWizard_Show(This,hwndParent) (This)->lpVtbl->Show(This,hwndParent)
#define IPassportWizard_SetOptions(This,dwOptions) (This)->lpVtbl->SetOptions(This,dwOptions)
#endif
#endif
  HRESULT WINAPI IPassportWizard_SetOptions_Proxy(IPassportWizard *This,DWORD dwOptions);
  void __RPC_STUB IPassportWizard_SetOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define PROPSTR_EXTENSIONCOMPLETIONSTATE L"ExtensionCompletionState"

  enum __MIDL___MIDL_itf_shobjidl_0241_0001 {
    CDBE_RET_DEFAULT = 0,CDBE_RET_DONTRUNOTHEREXTS = 0x1,CDBE_RET_STOPWIZARD = 0x2
  };
#define SID_CDWizardHost IID_ICDBurnExt

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0241_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0241_v0_0_s_ifspec;
#ifndef __ICDBurnExt_INTERFACE_DEFINED__
#define __ICDBurnExt_INTERFACE_DEFINED__
  enum __MIDL_ICDBurnExt_0002 {
    CDBE_TYPE_MUSIC = 0x1,CDBE_TYPE_DATA = 0x2,CDBE_TYPE_ALL = 0xffffffff
  };

  EXTERN_C const IID IID_ICDBurnExt;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ICDBurnExt : public IUnknown {
  public:
    virtual HRESULT WINAPI GetSupportedActionTypes(DWORD *pdwActions) = 0;
  };
#else
  typedef struct ICDBurnExtVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ICDBurnExt *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ICDBurnExt *This);
      ULONG (WINAPI *Release)(ICDBurnExt *This);
      HRESULT (WINAPI *GetSupportedActionTypes)(ICDBurnExt *This,DWORD *pdwActions);
    END_INTERFACE
  } ICDBurnExtVtbl;
  struct ICDBurnExt {
    CONST_VTBL struct ICDBurnExtVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ICDBurnExt_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICDBurnExt_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICDBurnExt_Release(This) (This)->lpVtbl->Release(This)
#define ICDBurnExt_GetSupportedActionTypes(This,pdwActions) (This)->lpVtbl->GetSupportedActionTypes(This,pdwActions)
#endif
#endif
  HRESULT WINAPI ICDBurnExt_GetSupportedActionTypes_Proxy(ICDBurnExt *This,DWORD *pdwActions);
  void __RPC_STUB ICDBurnExt_GetSupportedActionTypes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef void (*PFDVENUMREADYBALLBACK)(LPVOID pvData);

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0242_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0242_v0_0_s_ifspec;
#ifndef __IDVGetEnum_INTERFACE_DEFINED__
#define __IDVGetEnum_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDVGetEnum;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDVGetEnum : public IUnknown {
  public:
    virtual HRESULT WINAPI SetEnumReadyCallback(PFDVENUMREADYBALLBACK pfn,LPVOID pvData) = 0;
    virtual HRESULT WINAPI CreateEnumIDListFromContents(LPCITEMIDLIST pidlFolder,DWORD dwEnumFlags,IEnumIDList **ppEnumIDList) = 0;
  };
#else
  typedef struct IDVGetEnumVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDVGetEnum *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDVGetEnum *This);
      ULONG (WINAPI *Release)(IDVGetEnum *This);
      HRESULT (WINAPI *SetEnumReadyCallback)(IDVGetEnum *This,PFDVENUMREADYBALLBACK pfn,LPVOID pvData);
      HRESULT (WINAPI *CreateEnumIDListFromContents)(IDVGetEnum *This,LPCITEMIDLIST pidlFolder,DWORD dwEnumFlags,IEnumIDList **ppEnumIDList);
    END_INTERFACE
  } IDVGetEnumVtbl;
  struct IDVGetEnum {
    CONST_VTBL struct IDVGetEnumVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDVGetEnum_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDVGetEnum_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDVGetEnum_Release(This) (This)->lpVtbl->Release(This)
#define IDVGetEnum_SetEnumReadyCallback(This,pfn,pvData) (This)->lpVtbl->SetEnumReadyCallback(This,pfn,pvData)
#define IDVGetEnum_CreateEnumIDListFromContents(This,pidlFolder,dwEnumFlags,ppEnumIDList) (This)->lpVtbl->CreateEnumIDListFromContents(This,pidlFolder,dwEnumFlags,ppEnumIDList)
#endif
#endif
  HRESULT WINAPI IDVGetEnum_SetEnumReadyCallback_Proxy(IDVGetEnum *This,PFDVENUMREADYBALLBACK pfn,LPVOID pvData);
  void __RPC_STUB IDVGetEnum_SetEnumReadyCallback_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDVGetEnum_CreateEnumIDListFromContents_Proxy(IDVGetEnum *This,LPCITEMIDLIST pidlFolder,DWORD dwEnumFlags,IEnumIDList **ppEnumIDList);
  void __RPC_STUB IDVGetEnum_CreateEnumIDListFromContents_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IInsertItem_INTERFACE_DEFINED__
#define __IInsertItem_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IInsertItem;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IInsertItem : public IUnknown {
  public:
    virtual HRESULT WINAPI InsertItem(LPCITEMIDLIST pidl) = 0;
  };
#else
  typedef struct IInsertItemVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IInsertItem *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IInsertItem *This);
      ULONG (WINAPI *Release)(IInsertItem *This);
      HRESULT (WINAPI *InsertItem)(IInsertItem *This,LPCITEMIDLIST pidl);
    END_INTERFACE
  } IInsertItemVtbl;
  struct IInsertItem {
    CONST_VTBL struct IInsertItemVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IInsertItem_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IInsertItem_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IInsertItem_Release(This) (This)->lpVtbl->Release(This)
#define IInsertItem_InsertItem(This,pidl) (This)->lpVtbl->InsertItem(This,pidl)
#endif
#endif
  HRESULT WINAPI IInsertItem_InsertItem_Proxy(IInsertItem *This,LPCITEMIDLIST pidl);
  void __RPC_STUB IInsertItem_InsertItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IDeskBar_INTERFACE_DEFINED__
#define __IDeskBar_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDeskBar;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDeskBar : public IOleWindow {
  public:
    virtual HRESULT WINAPI SetClient(IUnknown *punkClient) = 0;
    virtual HRESULT WINAPI GetClient(IUnknown **ppunkClient) = 0;
    virtual HRESULT WINAPI OnPosRectChangeDB(LPRECT prc) = 0;
  };
#else
  typedef struct IDeskBarVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDeskBar *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDeskBar *This);
      ULONG (WINAPI *Release)(IDeskBar *This);
      HRESULT (WINAPI *GetWindow)(IDeskBar *This,HWND *phwnd);
      HRESULT (WINAPI *ContextSensitiveHelp)(IDeskBar *This,WINBOOL fEnterMode);
      HRESULT (WINAPI *SetClient)(IDeskBar *This,IUnknown *punkClient);
      HRESULT (WINAPI *GetClient)(IDeskBar *This,IUnknown **ppunkClient);
      HRESULT (WINAPI *OnPosRectChangeDB)(IDeskBar *This,LPRECT prc);
    END_INTERFACE
  } IDeskBarVtbl;
  struct IDeskBar {
    CONST_VTBL struct IDeskBarVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDeskBar_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDeskBar_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDeskBar_Release(This) (This)->lpVtbl->Release(This)
#define IDeskBar_GetWindow(This,phwnd) (This)->lpVtbl->GetWindow(This,phwnd)
#define IDeskBar_ContextSensitiveHelp(This,fEnterMode) (This)->lpVtbl->ContextSensitiveHelp(This,fEnterMode)
#define IDeskBar_SetClient(This,punkClient) (This)->lpVtbl->SetClient(This,punkClient)
#define IDeskBar_GetClient(This,ppunkClient) (This)->lpVtbl->GetClient(This,ppunkClient)
#define IDeskBar_OnPosRectChangeDB(This,prc) (This)->lpVtbl->OnPosRectChangeDB(This,prc)
#endif
#endif
  HRESULT WINAPI IDeskBar_SetClient_Proxy(IDeskBar *This,IUnknown *punkClient);
  void __RPC_STUB IDeskBar_SetClient_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDeskBar_GetClient_Proxy(IDeskBar *This,IUnknown **ppunkClient);
  void __RPC_STUB IDeskBar_GetClient_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IDeskBar_OnPosRectChangeDB_Proxy(IDeskBar *This,LPRECT prc);
  void __RPC_STUB IDeskBar_OnPosRectChangeDB_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IMenuBand_INTERFACE_DEFINED__
#define __IMenuBand_INTERFACE_DEFINED__
  enum __MIDL_IMenuBand_0001 {
    MBHANDCID_PIDLSELECT = 0
  };

  EXTERN_C const IID IID_IMenuBand;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IMenuBand : public IUnknown {
  public:
    virtual HRESULT WINAPI IsMenuMessage(MSG *pmsg) = 0;
    virtual HRESULT WINAPI TranslateMenuMessage(MSG *pmsg,LRESULT *plRet) = 0;
  };
#else
  typedef struct IMenuBandVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IMenuBand *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IMenuBand *This);
      ULONG (WINAPI *Release)(IMenuBand *This);
      HRESULT (WINAPI *IsMenuMessage)(IMenuBand *This,MSG *pmsg);
      HRESULT (WINAPI *TranslateMenuMessage)(IMenuBand *This,MSG *pmsg,LRESULT *plRet);
    END_INTERFACE
  } IMenuBandVtbl;
  struct IMenuBand {
    CONST_VTBL struct IMenuBandVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IMenuBand_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMenuBand_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMenuBand_Release(This) (This)->lpVtbl->Release(This)
#define IMenuBand_IsMenuMessage(This,pmsg) (This)->lpVtbl->IsMenuMessage(This,pmsg)
#define IMenuBand_TranslateMenuMessage(This,pmsg,plRet) (This)->lpVtbl->TranslateMenuMessage(This,pmsg,plRet)
#endif
#endif
  HRESULT WINAPI IMenuBand_IsMenuMessage_Proxy(IMenuBand *This,MSG *pmsg);
  void __RPC_STUB IMenuBand_IsMenuMessage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IMenuBand_TranslateMenuMessage_Proxy(IMenuBand *This,MSG *pmsg,LRESULT *plRet);
  void __RPC_STUB IMenuBand_TranslateMenuMessage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IFolderBandPriv_INTERFACE_DEFINED__
#define __IFolderBandPriv_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IFolderBandPriv;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IFolderBandPriv : public IUnknown {
  public:
    virtual HRESULT WINAPI SetCascade(WINBOOL f) = 0;
    virtual HRESULT WINAPI SetAccelerators(WINBOOL f) = 0;
    virtual HRESULT WINAPI SetNoIcons(WINBOOL f) = 0;
    virtual HRESULT WINAPI SetNoText(WINBOOL f) = 0;
  };
#else
  typedef struct IFolderBandPrivVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IFolderBandPriv *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IFolderBandPriv *This);
      ULONG (WINAPI *Release)(IFolderBandPriv *This);
      HRESULT (WINAPI *SetCascade)(IFolderBandPriv *This,WINBOOL f);
      HRESULT (WINAPI *SetAccelerators)(IFolderBandPriv *This,WINBOOL f);
      HRESULT (WINAPI *SetNoIcons)(IFolderBandPriv *This,WINBOOL f);
      HRESULT (WINAPI *SetNoText)(IFolderBandPriv *This,WINBOOL f);
    END_INTERFACE
  } IFolderBandPrivVtbl;
  struct IFolderBandPriv {
    CONST_VTBL struct IFolderBandPrivVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IFolderBandPriv_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFolderBandPriv_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFolderBandPriv_Release(This) (This)->lpVtbl->Release(This)
#define IFolderBandPriv_SetCascade(This,f) (This)->lpVtbl->SetCascade(This,f)
#define IFolderBandPriv_SetAccelerators(This,f) (This)->lpVtbl->SetAccelerators(This,f)
#define IFolderBandPriv_SetNoIcons(This,f) (This)->lpVtbl->SetNoIcons(This,f)
#define IFolderBandPriv_SetNoText(This,f) (This)->lpVtbl->SetNoText(This,f)
#endif
#endif
  HRESULT WINAPI IFolderBandPriv_SetCascade_Proxy(IFolderBandPriv *This,WINBOOL f);
  void __RPC_STUB IFolderBandPriv_SetCascade_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderBandPriv_SetAccelerators_Proxy(IFolderBandPriv *This,WINBOOL f);
  void __RPC_STUB IFolderBandPriv_SetAccelerators_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderBandPriv_SetNoIcons_Proxy(IFolderBandPriv *This,WINBOOL f);
  void __RPC_STUB IFolderBandPriv_SetNoIcons_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFolderBandPriv_SetNoText_Proxy(IFolderBandPriv *This,WINBOOL f);
  void __RPC_STUB IFolderBandPriv_SetNoText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#if 0x501 >= 0x0400
#include <pshpack8.h>
  typedef struct tagBANDSITEINFO {
    DWORD dwMask;
    DWORD dwState;
    DWORD dwStyle;
  } BANDSITEINFO;

#include <poppack.h>

  enum __MIDL___MIDL_itf_shobjidl_0247_0001 {
    BSID_BANDADDED = 0,BSID_BANDREMOVED = BSID_BANDADDED + 1
  };
#define BSIM_STATE 0x00000001
#define BSIM_STYLE 0x00000002
#define BSSF_VISIBLE 0x00000001
#define BSSF_NOTITLE 0x00000002
#define BSSF_UNDELETEABLE 0x00001000
#define BSIS_AUTOGRIPPER 0x00000000
#define BSIS_NOGRIPPER 0x00000001
#define BSIS_ALWAYSGRIPPER 0x00000002
#define BSIS_LEFTALIGN 0x00000004
#define BSIS_SINGLECLICK 0x00000008
#define BSIS_NOCONTEXTMENU 0x00000010
#define BSIS_NODROPTARGET 0x00000020
#define BSIS_NOCAPTION 0x00000040
#define BSIS_PREFERNOLINEBREAK 0x00000080
#define BSIS_LOCKED 0x00000100
#define SID_SBandSite IID_IBandSite
#define CGID_BandSite IID_IBandSite

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0247_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0247_v0_0_s_ifspec;
#ifndef __IBandSite_INTERFACE_DEFINED__
#define __IBandSite_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IBandSite;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IBandSite : public IUnknown {
  public:
    virtual HRESULT WINAPI AddBand(IUnknown *punk) = 0;
    virtual HRESULT WINAPI EnumBands(UINT uBand,DWORD *pdwBandID) = 0;
    virtual HRESULT WINAPI QueryBand(DWORD dwBandID,IDeskBand **ppstb,DWORD *pdwState,LPWSTR pszName,int cchName) = 0;
    virtual HRESULT WINAPI SetBandState(DWORD dwBandID,DWORD dwMask,DWORD dwState) = 0;
    virtual HRESULT WINAPI RemoveBand(DWORD dwBandID) = 0;
    virtual HRESULT WINAPI GetBandObject(DWORD dwBandID,REFIID riid,void **ppv) = 0;
    virtual HRESULT WINAPI SetBandSiteInfo(const BANDSITEINFO *pbsinfo) = 0;
    virtual HRESULT WINAPI GetBandSiteInfo(BANDSITEINFO *pbsinfo) = 0;
  };
#else
  typedef struct IBandSiteVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IBandSite *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IBandSite *This);
      ULONG (WINAPI *Release)(IBandSite *This);
      HRESULT (WINAPI *AddBand)(IBandSite *This,IUnknown *punk);
      HRESULT (WINAPI *EnumBands)(IBandSite *This,UINT uBand,DWORD *pdwBandID);
      HRESULT (WINAPI *QueryBand)(IBandSite *This,DWORD dwBandID,IDeskBand **ppstb,DWORD *pdwState,LPWSTR pszName,int cchName);
      HRESULT (WINAPI *SetBandState)(IBandSite *This,DWORD dwBandID,DWORD dwMask,DWORD dwState);
      HRESULT (WINAPI *RemoveBand)(IBandSite *This,DWORD dwBandID);
      HRESULT (WINAPI *GetBandObject)(IBandSite *This,DWORD dwBandID,REFIID riid,void **ppv);
      HRESULT (WINAPI *SetBandSiteInfo)(IBandSite *This,const BANDSITEINFO *pbsinfo);
      HRESULT (WINAPI *GetBandSiteInfo)(IBandSite *This,BANDSITEINFO *pbsinfo);
    END_INTERFACE
  } IBandSiteVtbl;
  struct IBandSite {
    CONST_VTBL struct IBandSiteVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IBandSite_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBandSite_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBandSite_Release(This) (This)->lpVtbl->Release(This)
#define IBandSite_AddBand(This,punk) (This)->lpVtbl->AddBand(This,punk)
#define IBandSite_EnumBands(This,uBand,pdwBandID) (This)->lpVtbl->EnumBands(This,uBand,pdwBandID)
#define IBandSite_QueryBand(This,dwBandID,ppstb,pdwState,pszName,cchName) (This)->lpVtbl->QueryBand(This,dwBandID,ppstb,pdwState,pszName,cchName)
#define IBandSite_SetBandState(This,dwBandID,dwMask,dwState) (This)->lpVtbl->SetBandState(This,dwBandID,dwMask,dwState)
#define IBandSite_RemoveBand(This,dwBandID) (This)->lpVtbl->RemoveBand(This,dwBandID)
#define IBandSite_GetBandObject(This,dwBandID,riid,ppv) (This)->lpVtbl->GetBandObject(This,dwBandID,riid,ppv)
#define IBandSite_SetBandSiteInfo(This,pbsinfo) (This)->lpVtbl->SetBandSiteInfo(This,pbsinfo)
#define IBandSite_GetBandSiteInfo(This,pbsinfo) (This)->lpVtbl->GetBandSiteInfo(This,pbsinfo)
#endif
#endif
  HRESULT WINAPI IBandSite_AddBand_Proxy(IBandSite *This,IUnknown *punk);
  void __RPC_STUB IBandSite_AddBand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IBandSite_EnumBands_Proxy(IBandSite *This,UINT uBand,DWORD *pdwBandID);
  void __RPC_STUB IBandSite_EnumBands_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IBandSite_QueryBand_Proxy(IBandSite *This,DWORD dwBandID,IDeskBand **ppstb,DWORD *pdwState,LPWSTR pszName,int cchName);
  void __RPC_STUB IBandSite_QueryBand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IBandSite_SetBandState_Proxy(IBandSite *This,DWORD dwBandID,DWORD dwMask,DWORD dwState);
  void __RPC_STUB IBandSite_SetBandState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IBandSite_RemoveBand_Proxy(IBandSite *This,DWORD dwBandID);
  void __RPC_STUB IBandSite_RemoveBand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IBandSite_GetBandObject_Proxy(IBandSite *This,DWORD dwBandID,REFIID riid,void **ppv);
  void __RPC_STUB IBandSite_GetBandObject_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IBandSite_SetBandSiteInfo_Proxy(IBandSite *This,const BANDSITEINFO *pbsinfo);
  void __RPC_STUB IBandSite_SetBandSiteInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IBandSite_GetBandSiteInfo_Proxy(IBandSite *This,BANDSITEINFO *pbsinfo);
  void __RPC_STUB IBandSite_GetBandSiteInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0248_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0248_v0_0_s_ifspec;
#ifndef __INamespaceWalkCB_INTERFACE_DEFINED__
#define __INamespaceWalkCB_INTERFACE_DEFINED__
  EXTERN_C const IID IID_INamespaceWalkCB;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct INamespaceWalkCB : public IUnknown {
  public:
    virtual HRESULT WINAPI FoundItem(IShellFolder *psf,LPCITEMIDLIST pidl) = 0;
    virtual HRESULT WINAPI EnterFolder(IShellFolder *psf,LPCITEMIDLIST pidl) = 0;
    virtual HRESULT WINAPI LeaveFolder(IShellFolder *psf,LPCITEMIDLIST pidl) = 0;
    virtual HRESULT WINAPI InitializeProgressDialog(LPWSTR *ppszTitle,LPWSTR *ppszCancel) = 0;
  };
#else
  typedef struct INamespaceWalkCBVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(INamespaceWalkCB *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(INamespaceWalkCB *This);
      ULONG (WINAPI *Release)(INamespaceWalkCB *This);
      HRESULT (WINAPI *FoundItem)(INamespaceWalkCB *This,IShellFolder *psf,LPCITEMIDLIST pidl);
      HRESULT (WINAPI *EnterFolder)(INamespaceWalkCB *This,IShellFolder *psf,LPCITEMIDLIST pidl);
      HRESULT (WINAPI *LeaveFolder)(INamespaceWalkCB *This,IShellFolder *psf,LPCITEMIDLIST pidl);
      HRESULT (WINAPI *InitializeProgressDialog)(INamespaceWalkCB *This,LPWSTR *ppszTitle,LPWSTR *ppszCancel);
    END_INTERFACE
  } INamespaceWalkCBVtbl;
  struct INamespaceWalkCB {
    CONST_VTBL struct INamespaceWalkCBVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define INamespaceWalkCB_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define INamespaceWalkCB_AddRef(This) (This)->lpVtbl->AddRef(This)
#define INamespaceWalkCB_Release(This) (This)->lpVtbl->Release(This)
#define INamespaceWalkCB_FoundItem(This,psf,pidl) (This)->lpVtbl->FoundItem(This,psf,pidl)
#define INamespaceWalkCB_EnterFolder(This,psf,pidl) (This)->lpVtbl->EnterFolder(This,psf,pidl)
#define INamespaceWalkCB_LeaveFolder(This,psf,pidl) (This)->lpVtbl->LeaveFolder(This,psf,pidl)
#define INamespaceWalkCB_InitializeProgressDialog(This,ppszTitle,ppszCancel) (This)->lpVtbl->InitializeProgressDialog(This,ppszTitle,ppszCancel)
#endif
#endif
  HRESULT WINAPI INamespaceWalkCB_FoundItem_Proxy(INamespaceWalkCB *This,IShellFolder *psf,LPCITEMIDLIST pidl);
  void __RPC_STUB INamespaceWalkCB_FoundItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI INamespaceWalkCB_EnterFolder_Proxy(INamespaceWalkCB *This,IShellFolder *psf,LPCITEMIDLIST pidl);
  void __RPC_STUB INamespaceWalkCB_EnterFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI INamespaceWalkCB_LeaveFolder_Proxy(INamespaceWalkCB *This,IShellFolder *psf,LPCITEMIDLIST pidl);
  void __RPC_STUB INamespaceWalkCB_LeaveFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI INamespaceWalkCB_InitializeProgressDialog_Proxy(INamespaceWalkCB *This,LPWSTR *ppszTitle,LPWSTR *ppszCancel);
  void __RPC_STUB INamespaceWalkCB_InitializeProgressDialog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __INamespaceWalk_INTERFACE_DEFINED__
#define __INamespaceWalk_INTERFACE_DEFINED__
  enum __MIDL_INamespaceWalk_0001 {
    NSWF_NONE_IMPLIES_ALL = 0x1,NSWF_ONE_IMPLIES_ALL = 0x2,NSWF_DONT_TRAVERSE_LINKS = 0x4,NSWF_DONT_ACCUMULATE_RESULT = 0x8,
    NSWF_TRAVERSE_STREAM_JUNCTIONS = 0x10,NSWF_FILESYSTEM_ONLY = 0x20,NSWF_SHOW_PROGRESS = 0x40,NSWF_FLAG_VIEWORDER = 0x80,
    NSWF_IGNORE_AUTOPLAY_HIDA = 0x100
  };

  EXTERN_C const IID IID_INamespaceWalk;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct INamespaceWalk : public IUnknown {
  public:
    virtual HRESULT WINAPI Walk(IUnknown *punkToWalk,DWORD dwFlags,int cDepth,INamespaceWalkCB *pnswcb) = 0;
    virtual HRESULT WINAPI GetIDArrayResult(UINT *pcItems,LPITEMIDLIST **pppidl) = 0;
  };
#else
  typedef struct INamespaceWalkVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(INamespaceWalk *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(INamespaceWalk *This);
      ULONG (WINAPI *Release)(INamespaceWalk *This);
      HRESULT (WINAPI *Walk)(INamespaceWalk *This,IUnknown *punkToWalk,DWORD dwFlags,int cDepth,INamespaceWalkCB *pnswcb);
      HRESULT (WINAPI *GetIDArrayResult)(INamespaceWalk *This,UINT *pcItems,LPITEMIDLIST **pppidl);
    END_INTERFACE
  } INamespaceWalkVtbl;
  struct INamespaceWalk {
    CONST_VTBL struct INamespaceWalkVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define INamespaceWalk_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define INamespaceWalk_AddRef(This) (This)->lpVtbl->AddRef(This)
#define INamespaceWalk_Release(This) (This)->lpVtbl->Release(This)
#define INamespaceWalk_Walk(This,punkToWalk,dwFlags,cDepth,pnswcb) (This)->lpVtbl->Walk(This,punkToWalk,dwFlags,cDepth,pnswcb)
#define INamespaceWalk_GetIDArrayResult(This,pcItems,pppidl) (This)->lpVtbl->GetIDArrayResult(This,pcItems,pppidl)
#endif
#endif
  HRESULT WINAPI INamespaceWalk_Walk_Proxy(INamespaceWalk *This,IUnknown *punkToWalk,DWORD dwFlags,int cDepth,INamespaceWalkCB *pnswcb);
  void __RPC_STUB INamespaceWalk_Walk_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI INamespaceWalk_GetIDArrayResult_Proxy(INamespaceWalk *This,UINT *pcItems,LPITEMIDLIST **pppidl);
  void __RPC_STUB INamespaceWalk_GetIDArrayResult_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IRegTreeItem_INTERFACE_DEFINED__
#define __IRegTreeItem_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IRegTreeItem;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IRegTreeItem : public IUnknown {
  public:
    virtual HRESULT WINAPI GetCheckState(WINBOOL *pbCheck) = 0;
    virtual HRESULT WINAPI SetCheckState(WINBOOL bCheck) = 0;
  };
#else
  typedef struct IRegTreeItemVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IRegTreeItem *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IRegTreeItem *This);
      ULONG (WINAPI *Release)(IRegTreeItem *This);
      HRESULT (WINAPI *GetCheckState)(IRegTreeItem *This,WINBOOL *pbCheck);
      HRESULT (WINAPI *SetCheckState)(IRegTreeItem *This,WINBOOL bCheck);
    END_INTERFACE
  } IRegTreeItemVtbl;
  struct IRegTreeItem {
    CONST_VTBL struct IRegTreeItemVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IRegTreeItem_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IRegTreeItem_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IRegTreeItem_Release(This) (This)->lpVtbl->Release(This)
#define IRegTreeItem_GetCheckState(This,pbCheck) (This)->lpVtbl->GetCheckState(This,pbCheck)
#define IRegTreeItem_SetCheckState(This,bCheck) (This)->lpVtbl->SetCheckState(This,bCheck)
#endif
#endif
  HRESULT WINAPI IRegTreeItem_GetCheckState_Proxy(IRegTreeItem *This,WINBOOL *pbCheck);
  void __RPC_STUB IRegTreeItem_GetCheckState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IRegTreeItem_SetCheckState_Proxy(IRegTreeItem *This,WINBOOL bCheck);
  void __RPC_STUB IRegTreeItem_SetCheckState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  enum __MIDL___MIDL_itf_shobjidl_0251_0001 {
    MPOS_EXECUTE = 0,
    MPOS_FULLCANCEL,MPOS_CANCELLEVEL,MPOS_SELECTLEFT,MPOS_SELECTRIGHT,
    MPOS_CHILDTRACKING
  };

  enum __MIDL___MIDL_itf_shobjidl_0251_0002 {
    MPPF_SETFOCUS = 0x1,MPPF_INITIALSELECT = 0x2,MPPF_NOANIMATE = 0x4,
    MPPF_KEYBOARD = 0x10,MPPF_REPOSITION = 0x20,MPPF_FORCEZORDER = 0x40,MPPF_FINALSELECT = 0x80,
    MPPF_TOP = 0x20000000,MPPF_LEFT = 0x40000000,MPPF_RIGHT = 0x60000000,MPPF_BOTTOM = 0x80000000,MPPF_POS_MASK = 0xe0000000
  };

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0251_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0251_v0_0_s_ifspec;
#ifndef __IMenuPopup_INTERFACE_DEFINED__
#define __IMenuPopup_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IMenuPopup;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IMenuPopup : public IDeskBar {
  public:
    virtual HRESULT WINAPI Popup(POINTL *ppt,RECTL *prcExclude,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI OnSelect(DWORD dwSelectType) = 0;
    virtual HRESULT WINAPI SetSubMenu(IMenuPopup *pmp,WINBOOL fSet) = 0;
  };
#else
  typedef struct IMenuPopupVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IMenuPopup *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IMenuPopup *This);
      ULONG (WINAPI *Release)(IMenuPopup *This);
      HRESULT (WINAPI *GetWindow)(IMenuPopup *This,HWND *phwnd);
      HRESULT (WINAPI *ContextSensitiveHelp)(IMenuPopup *This,WINBOOL fEnterMode);
      HRESULT (WINAPI *SetClient)(IMenuPopup *This,IUnknown *punkClient);
      HRESULT (WINAPI *GetClient)(IMenuPopup *This,IUnknown **ppunkClient);
      HRESULT (WINAPI *OnPosRectChangeDB)(IMenuPopup *This,LPRECT prc);
      HRESULT (WINAPI *Popup)(IMenuPopup *This,POINTL *ppt,RECTL *prcExclude,DWORD dwFlags);
      HRESULT (WINAPI *OnSelect)(IMenuPopup *This,DWORD dwSelectType);
      HRESULT (WINAPI *SetSubMenu)(IMenuPopup *This,IMenuPopup *pmp,WINBOOL fSet);
    END_INTERFACE
  } IMenuPopupVtbl;
  struct IMenuPopup {
    CONST_VTBL struct IMenuPopupVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IMenuPopup_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IMenuPopup_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IMenuPopup_Release(This) (This)->lpVtbl->Release(This)
#define IMenuPopup_GetWindow(This,phwnd) (This)->lpVtbl->GetWindow(This,phwnd)
#define IMenuPopup_ContextSensitiveHelp(This,fEnterMode) (This)->lpVtbl->ContextSensitiveHelp(This,fEnterMode)
#define IMenuPopup_SetClient(This,punkClient) (This)->lpVtbl->SetClient(This,punkClient)
#define IMenuPopup_GetClient(This,ppunkClient) (This)->lpVtbl->GetClient(This,ppunkClient)
#define IMenuPopup_OnPosRectChangeDB(This,prc) (This)->lpVtbl->OnPosRectChangeDB(This,prc)
#define IMenuPopup_Popup(This,ppt,prcExclude,dwFlags) (This)->lpVtbl->Popup(This,ppt,prcExclude,dwFlags)
#define IMenuPopup_OnSelect(This,dwSelectType) (This)->lpVtbl->OnSelect(This,dwSelectType)
#define IMenuPopup_SetSubMenu(This,pmp,fSet) (This)->lpVtbl->SetSubMenu(This,pmp,fSet)
#endif
#endif
  HRESULT WINAPI IMenuPopup_Popup_Proxy(IMenuPopup *This,POINTL *ppt,RECTL *prcExclude,DWORD dwFlags);
  void __RPC_STUB IMenuPopup_Popup_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IMenuPopup_OnSelect_Proxy(IMenuPopup *This,DWORD dwSelectType);
  void __RPC_STUB IMenuPopup_OnSelect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IMenuPopup_SetSubMenu_Proxy(IMenuPopup *This,IMenuPopup *pmp,WINBOOL fSet);
  void __RPC_STUB IMenuPopup_SetSubMenu_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellItem_INTERFACE_DEFINED__
#define __IShellItem_INTERFACE_DEFINED__
  typedef enum __MIDL_IShellItem_0001 {
    SIGDN_NORMALDISPLAY = 0,SIGDN_PARENTRELATIVEPARSING = 0x80018001,SIGDN_PARENTRELATIVEFORADDRESSBAR = 0x8001c001,
    SIGDN_DESKTOPABSOLUTEPARSING = 0x80028000,SIGDN_PARENTRELATIVEEDITING = 0x80031001,SIGDN_DESKTOPABSOLUTEEDITING = 0x8004c000,
    SIGDN_FILESYSPATH = 0x80058000,SIGDN_URL = 0x80068000
  } SIGDN;

  enum __MIDL_IShellItem_0002 {
    SICHINT_DISPLAY = 0,SICHINT_ALLFIELDS = 0x80000000,SICHINT_CANONICAL = 0x10000000
  };
  typedef DWORD SICHINTF;

DEFINE_GUID(IID_IShellItem, 0x43826d1e,0xe718,0x42ee,0xbc,0x55,0xa1,0xe2,0x61,0xc3,0x7b,0xfe);
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellItem : public IUnknown {
  public:
    virtual HRESULT WINAPI BindToHandler(IBindCtx *pbc,REFGUID rbhid,REFIID riid,void **ppvOut) = 0;
    virtual HRESULT WINAPI GetParent(IShellItem **ppsi) = 0;
    virtual HRESULT WINAPI GetDisplayName(SIGDN sigdnName,LPOLESTR *ppszName) = 0;
    virtual HRESULT WINAPI GetAttributes(SFGAOF sfgaoMask,SFGAOF *psfgaoAttribs) = 0;
    virtual HRESULT WINAPI Compare(IShellItem *psi,SICHINTF hint,int *piOrder) = 0;
  };
#else
  typedef struct IShellItemVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellItem *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellItem *This);
      ULONG (WINAPI *Release)(IShellItem *This);
      HRESULT (WINAPI *BindToHandler)(IShellItem *This,IBindCtx *pbc,REFGUID rbhid,REFIID riid,void **ppvOut);
      HRESULT (WINAPI *GetParent)(IShellItem *This,IShellItem **ppsi);
      HRESULT (WINAPI *GetDisplayName)(IShellItem *This,SIGDN sigdnName,LPOLESTR *ppszName);
      HRESULT (WINAPI *GetAttributes)(IShellItem *This,SFGAOF sfgaoMask,SFGAOF *psfgaoAttribs);
      HRESULT (WINAPI *Compare)(IShellItem *This,IShellItem *psi,SICHINTF hint,int *piOrder);
    END_INTERFACE
  } IShellItemVtbl;
  struct IShellItem {
    CONST_VTBL struct IShellItemVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellItem_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellItem_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellItem_Release(This) (This)->lpVtbl->Release(This)
#define IShellItem_BindToHandler(This,pbc,rbhid,riid,ppvOut) (This)->lpVtbl->BindToHandler(This,pbc,rbhid,riid,ppvOut)
#define IShellItem_GetParent(This,ppsi) (This)->lpVtbl->GetParent(This,ppsi)
#define IShellItem_GetDisplayName(This,sigdnName,ppszName) (This)->lpVtbl->GetDisplayName(This,sigdnName,ppszName)
#define IShellItem_GetAttributes(This,sfgaoMask,psfgaoAttribs) (This)->lpVtbl->GetAttributes(This,sfgaoMask,psfgaoAttribs)
#define IShellItem_Compare(This,psi,hint,piOrder) (This)->lpVtbl->Compare(This,psi,hint,piOrder)
#endif
#endif
  HRESULT WINAPI IShellItem_BindToHandler_Proxy(IShellItem *This,IBindCtx *pbc,REFGUID rbhid,REFIID riid,void **ppvOut);
  void __RPC_STUB IShellItem_BindToHandler_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellItem_GetParent_Proxy(IShellItem *This,IShellItem **ppsi);
  void __RPC_STUB IShellItem_GetParent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellItem_GetDisplayName_Proxy(IShellItem *This,SIGDN sigdnName,LPOLESTR *ppszName);
  void __RPC_STUB IShellItem_GetDisplayName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellItem_GetAttributes_Proxy(IShellItem *This,SFGAOF sfgaoMask,SFGAOF *psfgaoAttribs);
  void __RPC_STUB IShellItem_GetAttributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellItem_Compare_Proxy(IShellItem *This,IShellItem *psi,SICHINTF hint,int *piOrder);
  void __RPC_STUB IShellItem_Compare_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

/*****************************************************************************
 * IShellItem2 interface
 */
#ifndef __IShellItem2_INTERFACE_DEFINED__
#define __IShellItem2_INTERFACE_DEFINED__

DEFINE_GUID(IID_IShellItem2, 0x7e9fb0d3, 0x919f, 0x4307, 0xab,0x2e, 0x9b,0x18,0x60,0x31,0x0c,0x93);
__CRT_UUID_DECL(IShellItem2, 0x7e9fb0d3, 0x919f, 0x4307, 0xab,0x2e, 0x9b,0x18,0x60,0x31,0x0c,0x93)
#if defined(__cplusplus) && !defined(CINTERFACE)
interface IShellItem2 : public IShellItem
{
    virtual HRESULT STDMETHODCALLTYPE GetPropertyStore(
        GETPROPERTYSTOREFLAGS flags,
        REFIID riid,
        void **ppv) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetPropertyStoreWithCreateObject(
        GETPROPERTYSTOREFLAGS flags,
        IUnknown *punkCreateObject,
        REFIID riid,
        void **ppv) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetPropertyStoreForKeys(
        const PROPERTYKEY *rgKeys,
        UINT cKeys,
        GETPROPERTYSTOREFLAGS flags,
        REFIID riid,
        void **ppv) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetPropertyDescriptionList(
        REFPROPERTYKEY keyType,
        REFIID riid,
        void **ppv) = 0;

    virtual HRESULT STDMETHODCALLTYPE Update(
        IBindCtx *pbc) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetProperty(
        REFPROPERTYKEY key,
        PROPVARIANT *ppropvar) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetCLSID(
        REFPROPERTYKEY key,
        CLSID *pclsid) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetFileTime(
        REFPROPERTYKEY key,
        FILETIME *pft) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetInt32(
        REFPROPERTYKEY key,
        int *pi) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetString(
        REFPROPERTYKEY key,
        LPWSTR *ppsz) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetUInt32(
        REFPROPERTYKEY key,
        ULONG *pui) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetUInt64(
        REFPROPERTYKEY key,
        ULONGLONG *pull) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetBool(
        REFPROPERTYKEY key,
        BOOL *pf) = 0;

};
#else
typedef struct IShellItem2Vtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IShellItem2* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IShellItem2* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IShellItem2* This);

    /*** IShellItem methods ***/
    HRESULT (STDMETHODCALLTYPE *BindToHandler)(
        IShellItem2* This,
        IBindCtx *pbc,
        REFGUID rbhid,
        REFIID riid,
        void **ppvOut);

    HRESULT (STDMETHODCALLTYPE *GetParent)(
        IShellItem2* This,
        IShellItem **ppsi);

    HRESULT (STDMETHODCALLTYPE *GetDisplayName)(
        IShellItem2* This,
        SIGDN sigdnName,
        LPWSTR *ppszName);

    HRESULT (STDMETHODCALLTYPE *GetAttributes)(
        IShellItem2* This,
        SFGAOF sfgaoMask,
        SFGAOF *psfgaoAttribs);

    HRESULT (STDMETHODCALLTYPE *Compare)(
        IShellItem2* This,
        IShellItem *psi,
        SICHINTF hint,
        int *piOrder);

    /*** IShellItem2 methods ***/
    HRESULT (STDMETHODCALLTYPE *GetPropertyStore)(
        IShellItem2* This,
        GETPROPERTYSTOREFLAGS flags,
        REFIID riid,
        void **ppv);

    HRESULT (STDMETHODCALLTYPE *GetPropertyStoreWithCreateObject)(
        IShellItem2* This,
        GETPROPERTYSTOREFLAGS flags,
        IUnknown *punkCreateObject,
        REFIID riid,
        void **ppv);

    HRESULT (STDMETHODCALLTYPE *GetPropertyStoreForKeys)(
        IShellItem2* This,
        const PROPERTYKEY *rgKeys,
        UINT cKeys,
        GETPROPERTYSTOREFLAGS flags,
        REFIID riid,
        void **ppv);

    HRESULT (STDMETHODCALLTYPE *GetPropertyDescriptionList)(
        IShellItem2* This,
        REFPROPERTYKEY keyType,
        REFIID riid,
        void **ppv);

    HRESULT (STDMETHODCALLTYPE *Update)(
        IShellItem2* This,
        IBindCtx *pbc);

    HRESULT (STDMETHODCALLTYPE *GetProperty)(
        IShellItem2* This,
        REFPROPERTYKEY key,
        PROPVARIANT *ppropvar);

    HRESULT (STDMETHODCALLTYPE *GetCLSID)(
        IShellItem2* This,
        REFPROPERTYKEY key,
        CLSID *pclsid);

    HRESULT (STDMETHODCALLTYPE *GetFileTime)(
        IShellItem2* This,
        REFPROPERTYKEY key,
        FILETIME *pft);

    HRESULT (STDMETHODCALLTYPE *GetInt32)(
        IShellItem2* This,
        REFPROPERTYKEY key,
        int *pi);

    HRESULT (STDMETHODCALLTYPE *GetString)(
        IShellItem2* This,
        REFPROPERTYKEY key,
        LPWSTR *ppsz);

    HRESULT (STDMETHODCALLTYPE *GetUInt32)(
        IShellItem2* This,
        REFPROPERTYKEY key,
        ULONG *pui);

    HRESULT (STDMETHODCALLTYPE *GetUInt64)(
        IShellItem2* This,
        REFPROPERTYKEY key,
        ULONGLONG *pull);

    HRESULT (STDMETHODCALLTYPE *GetBool)(
        IShellItem2* This,
        REFPROPERTYKEY key,
        BOOL *pf);

    END_INTERFACE
} IShellItem2Vtbl;
interface IShellItem2 {
    CONST_VTBL IShellItem2Vtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IShellItem2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellItem2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellItem2_Release(This) (This)->lpVtbl->Release(This)
/*** IShellItem methods ***/
#define IShellItem2_BindToHandler(This,pbc,rbhid,riid,ppvOut) (This)->lpVtbl->BindToHandler(This,pbc,rbhid,riid,ppvOut)
#define IShellItem2_GetParent(This,ppsi) (This)->lpVtbl->GetParent(This,ppsi)
#define IShellItem2_GetDisplayName(This,sigdnName,ppszName) (This)->lpVtbl->GetDisplayName(This,sigdnName,ppszName)
#define IShellItem2_GetAttributes(This,sfgaoMask,psfgaoAttribs) (This)->lpVtbl->GetAttributes(This,sfgaoMask,psfgaoAttribs)
#define IShellItem2_Compare(This,psi,hint,piOrder) (This)->lpVtbl->Compare(This,psi,hint,piOrder)
/*** IShellItem2 methods ***/
#define IShellItem2_GetPropertyStore(This,flags,riid,ppv) (This)->lpVtbl->GetPropertyStore(This,flags,riid,ppv)
#define IShellItem2_GetPropertyStoreWithCreateObject(This,flags,punkCreateObject,riid,ppv) (This)->lpVtbl->GetPropertyStoreWithCreateObject(This,flags,punkCreateObject,riid,ppv)
#define IShellItem2_GetPropertyStoreForKeys(This,rgKeys,cKeys,flags,riid,ppv) (This)->lpVtbl->GetPropertyStoreForKeys(This,rgKeys,cKeys,flags,riid,ppv)
#define IShellItem2_GetPropertyDescriptionList(This,keyType,riid,ppv) (This)->lpVtbl->GetPropertyDescriptionList(This,keyType,riid,ppv)
#define IShellItem2_Update(This,pbc) (This)->lpVtbl->Update(This,pbc)
#define IShellItem2_GetProperty(This,key,ppropvar) (This)->lpVtbl->GetProperty(This,key,ppropvar)
#define IShellItem2_GetCLSID(This,key,pclsid) (This)->lpVtbl->GetCLSID(This,key,pclsid)
#define IShellItem2_GetFileTime(This,key,pft) (This)->lpVtbl->GetFileTime(This,key,pft)
#define IShellItem2_GetInt32(This,key,pi) (This)->lpVtbl->GetInt32(This,key,pi)
#define IShellItem2_GetString(This,key,ppsz) (This)->lpVtbl->GetString(This,key,ppsz)
#define IShellItem2_GetUInt32(This,key,pui) (This)->lpVtbl->GetUInt32(This,key,pui)
#define IShellItem2_GetUInt64(This,key,pull) (This)->lpVtbl->GetUInt64(This,key,pull)
#define IShellItem2_GetBool(This,key,pf) (This)->lpVtbl->GetBool(This,key,pf)
#endif

#endif
#endif

#ifndef __IImageRecompress_INTERFACE_DEFINED__
#define __IImageRecompress_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IImageRecompress;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IImageRecompress : public IUnknown {
  public:
    virtual HRESULT WINAPI RecompressImage(IShellItem *psi,int cx,int cy,int iQuality,IStorage *pstg,IStream **ppstrmOut) = 0;
  };
#else
  typedef struct IImageRecompressVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IImageRecompress *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IImageRecompress *This);
      ULONG (WINAPI *Release)(IImageRecompress *This);
      HRESULT (WINAPI *RecompressImage)(IImageRecompress *This,IShellItem *psi,int cx,int cy,int iQuality,IStorage *pstg,IStream **ppstrmOut);
    END_INTERFACE
  } IImageRecompressVtbl;
  struct IImageRecompress {
    CONST_VTBL struct IImageRecompressVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IImageRecompress_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IImageRecompress_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IImageRecompress_Release(This) (This)->lpVtbl->Release(This)
#define IImageRecompress_RecompressImage(This,psi,cx,cy,iQuality,pstg,ppstrmOut) (This)->lpVtbl->RecompressImage(This,psi,cx,cy,iQuality,pstg,ppstrmOut)
#endif
#endif
  HRESULT WINAPI IImageRecompress_RecompressImage_Proxy(IImageRecompress *This,IShellItem *psi,int cx,int cy,int iQuality,IStorage *pstg,IStream **ppstrmOut);
  void __RPC_STUB IImageRecompress_RecompressImage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IDefViewSafety_INTERFACE_DEFINED__
#define __IDefViewSafety_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDefViewSafety;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDefViewSafety : public IUnknown {
  public:
    virtual HRESULT WINAPI IsSafePage(void) = 0;
  };
#else
  typedef struct IDefViewSafetyVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDefViewSafety *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDefViewSafety *This);
      ULONG (WINAPI *Release)(IDefViewSafety *This);
      HRESULT (WINAPI *IsSafePage)(IDefViewSafety *This);
    END_INTERFACE
  } IDefViewSafetyVtbl;
  struct IDefViewSafety {
    CONST_VTBL struct IDefViewSafetyVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDefViewSafety_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDefViewSafety_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDefViewSafety_Release(This) (This)->lpVtbl->Release(This)
#define IDefViewSafety_IsSafePage(This) (This)->lpVtbl->IsSafePage(This)
#endif
#endif
  HRESULT WINAPI IDefViewSafety_IsSafePage_Proxy(IDefViewSafety *This);
  void __RPC_STUB IDefViewSafety_IsSafePage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IContextMenuSite_INTERFACE_DEFINED__
#define __IContextMenuSite_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IContextMenuSite;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IContextMenuSite : public IUnknown {
  public:
    virtual HRESULT WINAPI DoContextMenuPopup(IUnknown *punkContextMenu,UINT fFlags,POINT pt) = 0;
  };
#else
  typedef struct IContextMenuSiteVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IContextMenuSite *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IContextMenuSite *This);
      ULONG (WINAPI *Release)(IContextMenuSite *This);
      HRESULT (WINAPI *DoContextMenuPopup)(IContextMenuSite *This,IUnknown *punkContextMenu,UINT fFlags,POINT pt);
    END_INTERFACE
  } IContextMenuSiteVtbl;
  struct IContextMenuSite {
    CONST_VTBL struct IContextMenuSiteVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IContextMenuSite_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IContextMenuSite_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IContextMenuSite_Release(This) (This)->lpVtbl->Release(This)
#define IContextMenuSite_DoContextMenuPopup(This,punkContextMenu,fFlags,pt) (This)->lpVtbl->DoContextMenuPopup(This,punkContextMenu,fFlags,pt)
#endif
#endif
  HRESULT WINAPI IContextMenuSite_DoContextMenuPopup_Proxy(IContextMenuSite *This,IUnknown *punkContextMenu,UINT fFlags,POINT pt);
  void __RPC_STUB IContextMenuSite_DoContextMenuPopup_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#include <pshpack1.h>
  typedef struct tagDELEGATEITEMID {
    WORD cbSize;
    WORD wOuter;
    WORD cbInner;
    BYTE rgb[1];
  } DELEGATEITEMID;
#include <poppack.h>

  typedef const UNALIGNED DELEGATEITEMID *PCDELEGATEITEMID;
  typedef UNALIGNED DELEGATEITEMID *PDELEGATEITEMID;

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0257_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0257_v0_0_s_ifspec;
#ifndef __IDelegateFolder_INTERFACE_DEFINED__
#define __IDelegateFolder_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IDelegateFolder;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IDelegateFolder : public IUnknown {
  public:
    virtual HRESULT WINAPI SetItemAlloc(IMalloc *pmalloc) = 0;
  };
#else
  typedef struct IDelegateFolderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IDelegateFolder *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IDelegateFolder *This);
      ULONG (WINAPI *Release)(IDelegateFolder *This);
      HRESULT (WINAPI *SetItemAlloc)(IDelegateFolder *This,IMalloc *pmalloc);
    END_INTERFACE
  } IDelegateFolderVtbl;
  struct IDelegateFolder {
    CONST_VTBL struct IDelegateFolderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IDelegateFolder_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IDelegateFolder_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IDelegateFolder_Release(This) (This)->lpVtbl->Release(This)
#define IDelegateFolder_SetItemAlloc(This,pmalloc) (This)->lpVtbl->SetItemAlloc(This,pmalloc)
#endif
#endif
  HRESULT WINAPI IDelegateFolder_SetItemAlloc_Proxy(IDelegateFolder *This,IMalloc *pmalloc);
  void __RPC_STUB IDelegateFolder_SetItemAlloc_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0258_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0258_v0_0_s_ifspec;
#ifndef __IBrowserFrameOptions_INTERFACE_DEFINED__
#define __IBrowserFrameOptions_INTERFACE_DEFINED__
  typedef IBrowserFrameOptions *LPBROWSERFRAMEOPTIONS;

  enum __MIDL_IBrowserFrameOptions_0001 {
    BFO_NONE = 0,BFO_BROWSER_PERSIST_SETTINGS = 0x1,BFO_RENAME_FOLDER_OPTIONS_TOINTERNET = 0x2,BFO_BOTH_OPTIONS = 0x4,
    BIF_PREFER_INTERNET_SHORTCUT = 0x8,BFO_BROWSE_NO_IN_NEW_PROCESS = 0x10,BFO_ENABLE_HYPERLINK_TRACKING = 0x20,BFO_USE_IE_OFFLINE_SUPPORT = 0x40,
    BFO_SUBSTITUE_INTERNET_START_PAGE = 0x80,BFO_USE_IE_LOGOBANDING = 0x100,BFO_ADD_IE_TOCAPTIONBAR = 0x200,BFO_USE_DIALUP_REF = 0x400,
    BFO_USE_IE_TOOLBAR = 0x800,BFO_NO_PARENT_FOLDER_SUPPORT = 0x1000,BFO_NO_REOPEN_NEXT_RESTART = 0x2000,BFO_GO_HOME_PAGE = 0x4000,
    BFO_PREFER_IEPROCESS = 0x8000,BFO_SHOW_NAVIGATION_CANCELLED = 0x10000,BFO_USE_IE_STATUSBAR = 0x20000,BFO_QUERY_ALL = 0xffffffff
  };
  typedef DWORD BROWSERFRAMEOPTIONS;

  EXTERN_C const IID IID_IBrowserFrameOptions;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IBrowserFrameOptions : public IUnknown {
  public:
    virtual HRESULT WINAPI GetFrameOptions(BROWSERFRAMEOPTIONS dwMask,BROWSERFRAMEOPTIONS *pdwOptions) = 0;
  };
#else
  typedef struct IBrowserFrameOptionsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IBrowserFrameOptions *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IBrowserFrameOptions *This);
      ULONG (WINAPI *Release)(IBrowserFrameOptions *This);
      HRESULT (WINAPI *GetFrameOptions)(IBrowserFrameOptions *This,BROWSERFRAMEOPTIONS dwMask,BROWSERFRAMEOPTIONS *pdwOptions);
    END_INTERFACE
  } IBrowserFrameOptionsVtbl;
  struct IBrowserFrameOptions {
    CONST_VTBL struct IBrowserFrameOptionsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IBrowserFrameOptions_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBrowserFrameOptions_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBrowserFrameOptions_Release(This) (This)->lpVtbl->Release(This)
#define IBrowserFrameOptions_GetFrameOptions(This,dwMask,pdwOptions) (This)->lpVtbl->GetFrameOptions(This,dwMask,pdwOptions)
#endif
#endif
  HRESULT WINAPI IBrowserFrameOptions_GetFrameOptions_Proxy(IBrowserFrameOptions *This,BROWSERFRAMEOPTIONS dwMask,BROWSERFRAMEOPTIONS *pdwOptions);
  void __RPC_STUB IBrowserFrameOptions_GetFrameOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  typedef enum tagNWMF {
    NWMF_UNLOADING = 0x1,NWMF_USERINITED = 0x2,NWMF_FIRST = 0x4,NWMF_OVERRIDEKEY = 0x8,NWMF_SHOWHELP = 0x10,NWMF_HTMLDIALOG = 0x20,
    NWMF_FROMDIALOGCHILD = 0x40,NWMF_USERREQUESTED = 0x80,NWMF_USERALLOWED = 0x100
  } NWMF;

#define SID_SNewWindowManager IID_INewWindowManager

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0259_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0259_v0_0_s_ifspec;
#ifndef __INewWindowManager_INTERFACE_DEFINED__
#define __INewWindowManager_INTERFACE_DEFINED__
  EXTERN_C const IID IID_INewWindowManager;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct INewWindowManager : public IUnknown {
  public:
    virtual HRESULT WINAPI EvaluateNewWindow(LPCWSTR pszUrl,LPCWSTR pszName,LPCWSTR pszUrlContext,LPCWSTR pszFeatures,WINBOOL fReplace,DWORD dwFlags,DWORD dwUserActionTime) = 0;
  };
#else
  typedef struct INewWindowManagerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(INewWindowManager *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(INewWindowManager *This);
      ULONG (WINAPI *Release)(INewWindowManager *This);
      HRESULT (WINAPI *EvaluateNewWindow)(INewWindowManager *This,LPCWSTR pszUrl,LPCWSTR pszName,LPCWSTR pszUrlContext,LPCWSTR pszFeatures,WINBOOL fReplace,DWORD dwFlags,DWORD dwUserActionTime);
    END_INTERFACE
  } INewWindowManagerVtbl;
  struct INewWindowManager {
    CONST_VTBL struct INewWindowManagerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define INewWindowManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define INewWindowManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define INewWindowManager_Release(This) (This)->lpVtbl->Release(This)
#define INewWindowManager_EvaluateNewWindow(This,pszUrl,pszName,pszUrlContext,pszFeatures,fReplace,dwFlags,dwUserActionTime) (This)->lpVtbl->EvaluateNewWindow(This,pszUrl,pszName,pszUrlContext,pszFeatures,fReplace,dwFlags,dwUserActionTime)
#endif
#endif
  HRESULT WINAPI INewWindowManager_EvaluateNewWindow_Proxy(INewWindowManager *This,LPCWSTR pszUrl,LPCWSTR pszName,LPCWSTR pszUrlContext,LPCWSTR pszFeatures,WINBOOL fReplace,DWORD dwFlags,DWORD dwUserActionTime);
  void __RPC_STUB INewWindowManager_EvaluateNewWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#include <pshpack8.h>
  typedef struct tagSMDATA {
    DWORD dwMask;
    DWORD dwFlags;
    HMENU hmenu;
    HWND hwnd;
    UINT uId;
    UINT uIdParent;
    UINT uIdAncestor;
    IUnknown *punk;
    LPITEMIDLIST pidlFolder;
    LPITEMIDLIST pidlItem;
    IShellFolder *psf;
    void *pvUserData;
  } SMDATA;

  typedef struct tagSMDATA *LPSMDATA;

#define SMDM_SHELLFOLDER 0x00000001
#define SMDM_HMENU 0x00000002
#define SMDM_TOOLBAR 0x00000004

  typedef struct tagSMINFO {
    DWORD dwMask;
    DWORD dwType;
    DWORD dwFlags;
    int iIcon;
  } SMINFO;

  typedef struct tagSMINFO *PSMINFO;

  typedef struct tagSHCSCHANGENOTIFYSTRUCT {
    LONG lEvent;
    LPCITEMIDLIST pidl1;
    LPCITEMIDLIST pidl2;
  } SMCSHCHANGENOTIFYSTRUCT;

  typedef struct tagSHCSCHANGENOTIFYSTRUCT *PSMCSHCHANGENOTIFYSTRUCT;

#include <poppack.h>

  enum __MIDL___MIDL_itf_shobjidl_0260_0001 {
    SMIM_TYPE = 0x1,SMIM_FLAGS = 0x2,SMIM_ICON = 0x4
  };

  enum __MIDL___MIDL_itf_shobjidl_0260_0002 {
    SMIT_SEPARATOR = 0x1,SMIT_STRING = 0x2
  };

  enum __MIDL___MIDL_itf_shobjidl_0260_0003 {
    SMIF_ICON = 0x1,SMIF_ACCELERATOR = 0x2,SMIF_DROPTARGET = 0x4,SMIF_SUBMENU = 0x8,SMIF_CHECKED = 0x20,SMIF_DROPCASCADE = 0x40,SMIF_HIDDEN = 0x80,
    SMIF_DISABLED = 0x100,SMIF_TRACKPOPUP = 0x200,SMIF_DEMOTED = 0x400,SMIF_ALTSTATE = 0x800,SMIF_DRAGNDROP = 0x1000,SMIF_NEW = 0x2000
  };
#define SMC_INITMENU 0x00000001
#define SMC_CREATE 0x00000002
#define SMC_EXITMENU 0x00000003
#define SMC_GETINFO 0x00000005
#define SMC_GETSFINFO 0x00000006
#define SMC_GETOBJECT 0x00000007
#define SMC_GETSFOBJECT 0x00000008
#define SMC_SFEXEC 0x00000009
#define SMC_SFSELECTITEM 0x0000000A
#define SMC_REFRESH 0x00000010
#define SMC_DEMOTE 0x00000011
#define SMC_PROMOTE 0x00000012
#define SMC_DEFAULTICON 0x00000016
#define SMC_NEWITEM 0x00000017
#define SMC_CHEVRONEXPAND 0x00000019
#define SMC_DISPLAYCHEVRONTIP 0x0000002A
#define SMC_SETSFOBJECT 0x0000002D
#define SMC_SHCHANGENOTIFY 0x0000002E
#define SMC_CHEVRONGETTIP 0x0000002F
#define SMC_SFDDRESTRICTED 0x00000030

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0260_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0260_v0_0_s_ifspec;

#ifndef __IShellMenuCallback_INTERFACE_DEFINED__
#define __IShellMenuCallback_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellMenuCallback;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellMenuCallback : public IUnknown {
  public:
    virtual HRESULT WINAPI CallbackSM(LPSMDATA psmd,UINT uMsg,WPARAM wParam,LPARAM lParam) = 0;
  };
#else
  typedef struct IShellMenuCallbackVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellMenuCallback *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellMenuCallback *This);
      ULONG (WINAPI *Release)(IShellMenuCallback *This);
      HRESULT (WINAPI *CallbackSM)(IShellMenuCallback *This,LPSMDATA psmd,UINT uMsg,WPARAM wParam,LPARAM lParam);
    END_INTERFACE
  } IShellMenuCallbackVtbl;
  struct IShellMenuCallback {
    CONST_VTBL struct IShellMenuCallbackVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellMenuCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellMenuCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellMenuCallback_Release(This) (This)->lpVtbl->Release(This)
#define IShellMenuCallback_CallbackSM(This,psmd,uMsg,wParam,lParam) (This)->lpVtbl->CallbackSM(This,psmd,uMsg,wParam,lParam)
#endif
#endif
  HRESULT WINAPI IShellMenuCallback_CallbackSM_Proxy(IShellMenuCallback *This,LPSMDATA psmd,UINT uMsg,WPARAM wParam,LPARAM lParam);
  void __RPC_STUB IShellMenuCallback_CallbackSM_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IAttachmentExecute_INTERFACE_DEFINED__
#define __IAttachmentExecute_INTERFACE_DEFINED__
  typedef enum tagATTACHMENT_PROMPT {
    ATTACHMENT_PROMPT_NONE = 0,ATTACHMENT_PROMPT_SAVE = 0x1,ATTACHMENT_PROMPT_EXEC = 0x2,ATTACHMENT_PROMPT_EXEC_OR_SAVE = 0x3
  } ATTACHMENT_PROMPT;

  typedef enum tagATTACHMENT_ACTION {
    ATTACHMENT_ACTION_CANCEL = 0,ATTACHMENT_ACTION_SAVE = 0x1,ATTACHMENT_ACTION_EXEC = 0x2
  } ATTACHMENT_ACTION;

DEFINE_GUID(IID_IAttachmentExecute, 0x73db1241,0x1e85,0x4581,0x8e,0x4f,0xa8,0x1e,0x1d,0x0f,0x8c,0x57);
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IAttachmentExecute : public IUnknown {
  public:
    virtual HRESULT WINAPI SetClientTitle(LPCWSTR pszTitle) = 0;
    virtual HRESULT WINAPI SetClientGuid(REFGUID guid) = 0;
    virtual HRESULT WINAPI SetLocalPath(LPCWSTR pszLocalPath) = 0;
    virtual HRESULT WINAPI SetFileName(LPCWSTR pszFileName) = 0;
    virtual HRESULT WINAPI SetSource(LPCWSTR pszSource) = 0;
    virtual HRESULT WINAPI SetReferrer(LPCWSTR pszReferrer) = 0;
    virtual HRESULT WINAPI CheckPolicy(void) = 0;
    virtual HRESULT WINAPI Prompt(HWND hwnd,ATTACHMENT_PROMPT prompt,ATTACHMENT_ACTION *paction) = 0;
    virtual HRESULT WINAPI Save(void) = 0;
    virtual HRESULT WINAPI Execute(HWND hwnd,LPCWSTR pszVerb,HANDLE *phProcess) = 0;
    virtual HRESULT WINAPI SaveWithUI(HWND hwnd) = 0;
    virtual HRESULT WINAPI ClearClientState(void) = 0;
  };
#else
  typedef struct IAttachmentExecuteVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IAttachmentExecute *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IAttachmentExecute *This);
      ULONG (WINAPI *Release)(IAttachmentExecute *This);
      HRESULT (WINAPI *SetClientTitle)(IAttachmentExecute *This,LPCWSTR pszTitle);
      HRESULT (WINAPI *SetClientGuid)(IAttachmentExecute *This,REFGUID guid);
      HRESULT (WINAPI *SetLocalPath)(IAttachmentExecute *This,LPCWSTR pszLocalPath);
      HRESULT (WINAPI *SetFileName)(IAttachmentExecute *This,LPCWSTR pszFileName);
      HRESULT (WINAPI *SetSource)(IAttachmentExecute *This,LPCWSTR pszSource);
      HRESULT (WINAPI *SetReferrer)(IAttachmentExecute *This,LPCWSTR pszReferrer);
      HRESULT (WINAPI *CheckPolicy)(IAttachmentExecute *This);
      HRESULT (WINAPI *Prompt)(IAttachmentExecute *This,HWND hwnd,ATTACHMENT_PROMPT prompt,ATTACHMENT_ACTION *paction);
      HRESULT (WINAPI *Save)(IAttachmentExecute *This);
      HRESULT (WINAPI *Execute)(IAttachmentExecute *This,HWND hwnd,LPCWSTR pszVerb,HANDLE *phProcess);
      HRESULT (WINAPI *SaveWithUI)(IAttachmentExecute *This,HWND hwnd);
      HRESULT (WINAPI *ClearClientState)(IAttachmentExecute *This);
    END_INTERFACE
  } IAttachmentExecuteVtbl;
  struct IAttachmentExecute {
    CONST_VTBL struct IAttachmentExecuteVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IAttachmentExecute_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IAttachmentExecute_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IAttachmentExecute_Release(This) (This)->lpVtbl->Release(This)
#define IAttachmentExecute_SetClientTitle(This,pszTitle) (This)->lpVtbl->SetClientTitle(This,pszTitle)
#define IAttachmentExecute_SetClientGuid(This,guid) (This)->lpVtbl->SetClientGuid(This,guid)
#define IAttachmentExecute_SetLocalPath(This,pszLocalPath) (This)->lpVtbl->SetLocalPath(This,pszLocalPath)
#define IAttachmentExecute_SetFileName(This,pszFileName) (This)->lpVtbl->SetFileName(This,pszFileName)
#define IAttachmentExecute_SetSource(This,pszSource) (This)->lpVtbl->SetSource(This,pszSource)
#define IAttachmentExecute_SetReferrer(This,pszReferrer) (This)->lpVtbl->SetReferrer(This,pszReferrer)
#define IAttachmentExecute_CheckPolicy(This) (This)->lpVtbl->CheckPolicy(This)
#define IAttachmentExecute_Prompt(This,hwnd,prompt,paction) (This)->lpVtbl->Prompt(This,hwnd,prompt,paction)
#define IAttachmentExecute_Save(This) (This)->lpVtbl->Save(This)
#define IAttachmentExecute_Execute(This,hwnd,pszVerb,phProcess) (This)->lpVtbl->Execute(This,hwnd,pszVerb,phProcess)
#define IAttachmentExecute_SaveWithUI(This,hwnd) (This)->lpVtbl->SaveWithUI(This,hwnd)
#define IAttachmentExecute_ClearClientState(This) (This)->lpVtbl->ClearClientState(This)
#endif
#endif
  HRESULT WINAPI IAttachmentExecute_SetClientTitle_Proxy(IAttachmentExecute *This,LPCWSTR pszTitle);
  void __RPC_STUB IAttachmentExecute_SetClientTitle_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_SetClientGuid_Proxy(IAttachmentExecute *This,REFGUID guid);
  void __RPC_STUB IAttachmentExecute_SetClientGuid_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_SetLocalPath_Proxy(IAttachmentExecute *This,LPCWSTR pszLocalPath);
  void __RPC_STUB IAttachmentExecute_SetLocalPath_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_SetFileName_Proxy(IAttachmentExecute *This,LPCWSTR pszFileName);
  void __RPC_STUB IAttachmentExecute_SetFileName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_SetSource_Proxy(IAttachmentExecute *This,LPCWSTR pszSource);
  void __RPC_STUB IAttachmentExecute_SetSource_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_SetReferrer_Proxy(IAttachmentExecute *This,LPCWSTR pszReferrer);
  void __RPC_STUB IAttachmentExecute_SetReferrer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_CheckPolicy_Proxy(IAttachmentExecute *This);
  void __RPC_STUB IAttachmentExecute_CheckPolicy_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_Prompt_Proxy(IAttachmentExecute *This,HWND hwnd,ATTACHMENT_PROMPT prompt,ATTACHMENT_ACTION *paction);
  void __RPC_STUB IAttachmentExecute_Prompt_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_Save_Proxy(IAttachmentExecute *This);
  void __RPC_STUB IAttachmentExecute_Save_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_Execute_Proxy(IAttachmentExecute *This,HWND hwnd,LPCWSTR pszVerb,HANDLE *phProcess);
  void __RPC_STUB IAttachmentExecute_Execute_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_SaveWithUI_Proxy(IAttachmentExecute *This,HWND hwnd);
  void __RPC_STUB IAttachmentExecute_SaveWithUI_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAttachmentExecute_ClearClientState_Proxy(IAttachmentExecute *This);
  void __RPC_STUB IAttachmentExecute_ClearClientState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#define SMINIT_DEFAULT 0x00000000
#define SMINIT_RESTRICT_DRAGDROP 0x00000002
#define SMINIT_TOPLEVEL 0x00000004
#define SMINIT_CACHED 0x00000010
#define SMINIT_VERTICAL 0x10000000
#define SMINIT_HORIZONTAL 0x20000000
#define ANCESTORDEFAULT (UINT)-1
#define SMSET_TOP 0x10000000
#define SMSET_BOTTOM 0x20000000
#define SMSET_DONTOWN 0x00000001
#define SMINV_REFRESH 0x00000001
#define SMINV_ID 0x00000008

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0262_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0262_v0_0_s_ifspec;
#ifndef __IShellMenu_INTERFACE_DEFINED__
#define __IShellMenu_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellMenu;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellMenu : public IUnknown {
  public:
    virtual HRESULT WINAPI Initialize(IShellMenuCallback *psmc,UINT uId,UINT uIdAncestor,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI GetMenuInfo(IShellMenuCallback **ppsmc,UINT *puId,UINT *puIdAncestor,DWORD *pdwFlags) = 0;
    virtual HRESULT WINAPI SetShellFolder(IShellFolder *psf,LPCITEMIDLIST pidlFolder,HKEY hKey,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI GetShellFolder(DWORD *pdwFlags,LPITEMIDLIST *ppidl,REFIID riid,void **ppv) = 0;
    virtual HRESULT WINAPI SetMenu(HMENU hmenu,HWND hwnd,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI GetMenu(HMENU *phmenu,HWND *phwnd,DWORD *pdwFlags) = 0;
    virtual HRESULT WINAPI InvalidateItem(LPSMDATA psmd,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI GetState(LPSMDATA psmd) = 0;
    virtual HRESULT WINAPI SetMenuToolbar(IUnknown *punk,DWORD dwFlags) = 0;
  };
#else
  typedef struct IShellMenuVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellMenu *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellMenu *This);
      ULONG (WINAPI *Release)(IShellMenu *This);
      HRESULT (WINAPI *Initialize)(IShellMenu *This,IShellMenuCallback *psmc,UINT uId,UINT uIdAncestor,DWORD dwFlags);
      HRESULT (WINAPI *GetMenuInfo)(IShellMenu *This,IShellMenuCallback **ppsmc,UINT *puId,UINT *puIdAncestor,DWORD *pdwFlags);
      HRESULT (WINAPI *SetShellFolder)(IShellMenu *This,IShellFolder *psf,LPCITEMIDLIST pidlFolder,HKEY hKey,DWORD dwFlags);
      HRESULT (WINAPI *GetShellFolder)(IShellMenu *This,DWORD *pdwFlags,LPITEMIDLIST *ppidl,REFIID riid,void **ppv);
      HRESULT (WINAPI *SetMenu)(IShellMenu *This,HMENU hmenu,HWND hwnd,DWORD dwFlags);
      HRESULT (WINAPI *GetMenu)(IShellMenu *This,HMENU *phmenu,HWND *phwnd,DWORD *pdwFlags);
      HRESULT (WINAPI *InvalidateItem)(IShellMenu *This,LPSMDATA psmd,DWORD dwFlags);
      HRESULT (WINAPI *GetState)(IShellMenu *This,LPSMDATA psmd);
      HRESULT (WINAPI *SetMenuToolbar)(IShellMenu *This,IUnknown *punk,DWORD dwFlags);
    END_INTERFACE
  } IShellMenuVtbl;
  struct IShellMenu {
    CONST_VTBL struct IShellMenuVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellMenu_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellMenu_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellMenu_Release(This) (This)->lpVtbl->Release(This)
#define IShellMenu_Initialize(This,psmc,uId,uIdAncestor,dwFlags) (This)->lpVtbl->Initialize(This,psmc,uId,uIdAncestor,dwFlags)
#define IShellMenu_GetMenuInfo(This,ppsmc,puId,puIdAncestor,pdwFlags) (This)->lpVtbl->GetMenuInfo(This,ppsmc,puId,puIdAncestor,pdwFlags)
#define IShellMenu_SetShellFolder(This,psf,pidlFolder,hKey,dwFlags) (This)->lpVtbl->SetShellFolder(This,psf,pidlFolder,hKey,dwFlags)
#define IShellMenu_GetShellFolder(This,pdwFlags,ppidl,riid,ppv) (This)->lpVtbl->GetShellFolder(This,pdwFlags,ppidl,riid,ppv)
#define IShellMenu_SetMenu(This,hmenu,hwnd,dwFlags) (This)->lpVtbl->SetMenu(This,hmenu,hwnd,dwFlags)
#define IShellMenu_GetMenu(This,phmenu,phwnd,pdwFlags) (This)->lpVtbl->GetMenu(This,phmenu,phwnd,pdwFlags)
#define IShellMenu_InvalidateItem(This,psmd,dwFlags) (This)->lpVtbl->InvalidateItem(This,psmd,dwFlags)
#define IShellMenu_GetState(This,psmd) (This)->lpVtbl->GetState(This,psmd)
#define IShellMenu_SetMenuToolbar(This,punk,dwFlags) (This)->lpVtbl->SetMenuToolbar(This,punk,dwFlags)
#endif
#endif
  HRESULT WINAPI IShellMenu_Initialize_Proxy(IShellMenu *This,IShellMenuCallback *psmc,UINT uId,UINT uIdAncestor,DWORD dwFlags);
  void __RPC_STUB IShellMenu_Initialize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellMenu_GetMenuInfo_Proxy(IShellMenu *This,IShellMenuCallback **ppsmc,UINT *puId,UINT *puIdAncestor,DWORD *pdwFlags);
  void __RPC_STUB IShellMenu_GetMenuInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellMenu_SetShellFolder_Proxy(IShellMenu *This,IShellFolder *psf,LPCITEMIDLIST pidlFolder,HKEY hKey,DWORD dwFlags);
  void __RPC_STUB IShellMenu_SetShellFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellMenu_GetShellFolder_Proxy(IShellMenu *This,DWORD *pdwFlags,LPITEMIDLIST *ppidl,REFIID riid,void **ppv);
  void __RPC_STUB IShellMenu_GetShellFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellMenu_SetMenu_Proxy(IShellMenu *This,HMENU hmenu,HWND hwnd,DWORD dwFlags);
  void __RPC_STUB IShellMenu_SetMenu_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellMenu_GetMenu_Proxy(IShellMenu *This,HMENU *phmenu,HWND *phwnd,DWORD *pdwFlags);
  void __RPC_STUB IShellMenu_GetMenu_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellMenu_InvalidateItem_Proxy(IShellMenu *This,LPSMDATA psmd,DWORD dwFlags);
  void __RPC_STUB IShellMenu_InvalidateItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellMenu_GetState_Proxy(IShellMenu *This,LPSMDATA psmd);
  void __RPC_STUB IShellMenu_GetState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellMenu_SetMenuToolbar_Proxy(IShellMenu *This,IUnknown *punk,DWORD dwFlags);
  void __RPC_STUB IShellMenu_SetMenuToolbar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

/*****************************************************************************
 * IApplicationAssociationRegistration interface
 */
#ifndef __IApplicationAssociationRegistration_INTERFACE_DEFINED__
#define __IApplicationAssociationRegistration_INTERFACE_DEFINED__

typedef enum ASSOCIATIONLEVEL {
    AL_MACHINE = 0,
    AL_EFFECTIVE = 1,
    AL_USER = 2
} ASSOCIATIONLEVEL;

typedef enum ASSOCIATIONTYPE {
    AT_FILEEXTENSION = 0,
    AT_URLPROTOCOL = 1,
    AT_STARTMENUCLIENT = 2,
    AT_MIMETYPE = 3
} ASSOCIATIONTYPE;

DEFINE_GUID(IID_IApplicationAssociationRegistration, 0x4e530b0a, 0xe611, 0x4c77, 0xa3,0xac, 0x90,0x31,0xd0,0x22,0x28,0x1b);
#if defined(__cplusplus) && !defined(CINTERFACE)
interface IApplicationAssociationRegistration : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE QueryCurrentDefault(
        LPCWSTR pszQuery,
        ASSOCIATIONTYPE atQueryType,
        ASSOCIATIONLEVEL alQueryLevel,
        LPWSTR *ppszAssociation) = 0;

    virtual HRESULT STDMETHODCALLTYPE QueryAppIsDefault(
        LPCWSTR pszQuery,
        ASSOCIATIONTYPE atQueryType,
        ASSOCIATIONLEVEL alQueryLevel,
        LPCWSTR pszAppRegistryName,
        BOOL *pfDefault) = 0;

    virtual HRESULT STDMETHODCALLTYPE QueryAppIsDefaultAll(
        ASSOCIATIONLEVEL alQueryLevel,
        LPCWSTR pszAppRegistryName,
        BOOL *pfDefault) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetAppAsDefault(
        LPCWSTR pszAppRegistryName,
        LPCWSTR pszSet,
        ASSOCIATIONTYPE atSetType) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetAppAsDefaultAll(
        LPCWSTR pszAppRegistryName) = 0;

    virtual HRESULT STDMETHODCALLTYPE ClearUserAssociations(
        ) = 0;

};
#else
typedef struct IApplicationAssociationRegistrationVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IApplicationAssociationRegistration* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IApplicationAssociationRegistration* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IApplicationAssociationRegistration* This);

    /*** IApplicationAssociationRegistration methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryCurrentDefault)(
        IApplicationAssociationRegistration* This,
        LPCWSTR pszQuery,
        ASSOCIATIONTYPE atQueryType,
        ASSOCIATIONLEVEL alQueryLevel,
        LPWSTR *ppszAssociation);

    HRESULT (STDMETHODCALLTYPE *QueryAppIsDefault)(
        IApplicationAssociationRegistration* This,
        LPCWSTR pszQuery,
        ASSOCIATIONTYPE atQueryType,
        ASSOCIATIONLEVEL alQueryLevel,
        LPCWSTR pszAppRegistryName,
        BOOL *pfDefault);

    HRESULT (STDMETHODCALLTYPE *QueryAppIsDefaultAll)(
        IApplicationAssociationRegistration* This,
        ASSOCIATIONLEVEL alQueryLevel,
        LPCWSTR pszAppRegistryName,
        BOOL *pfDefault);

    HRESULT (STDMETHODCALLTYPE *SetAppAsDefault)(
        IApplicationAssociationRegistration* This,
        LPCWSTR pszAppRegistryName,
        LPCWSTR pszSet,
        ASSOCIATIONTYPE atSetType);

    HRESULT (STDMETHODCALLTYPE *SetAppAsDefaultAll)(
        IApplicationAssociationRegistration* This,
        LPCWSTR pszAppRegistryName);

    HRESULT (STDMETHODCALLTYPE *ClearUserAssociations)(
        IApplicationAssociationRegistration* This);

    END_INTERFACE
} IApplicationAssociationRegistrationVtbl;
interface IApplicationAssociationRegistration {
    CONST_VTBL IApplicationAssociationRegistrationVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IApplicationAssociationRegistration_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IApplicationAssociationRegistration_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IApplicationAssociationRegistration_Release(This) (This)->lpVtbl->Release(This)
/*** IApplicationAssociationRegistration methods ***/
#define IApplicationAssociationRegistration_QueryCurrentDefault(This,pszQuery,atQueryType,alQueryLevel,ppszAssociation) (This)->lpVtbl->QueryCurrentDefault(This,pszQuery,atQueryType,alQueryLevel,ppszAssociation)
#define IApplicationAssociationRegistration_QueryAppIsDefault(This,pszQuery,atQueryType,alQueryLevel,pszAppRegistryName,pfDefault) (This)->lpVtbl->QueryAppIsDefault(This,pszQuery,atQueryType,alQueryLevel,pszAppRegistryName,pfDefault)
#define IApplicationAssociationRegistration_QueryAppIsDefaultAll(This,alQueryLevel,pszAppRegistryName,pfDefault) (This)->lpVtbl->QueryAppIsDefaultAll(This,alQueryLevel,pszAppRegistryName,pfDefault)
#define IApplicationAssociationRegistration_SetAppAsDefault(This,pszAppRegistryName,pszSet,atSetType) (This)->lpVtbl->SetAppAsDefault(This,pszAppRegistryName,pszSet,atSetType)
#define IApplicationAssociationRegistration_SetAppAsDefaultAll(This,pszAppRegistryName) (This)->lpVtbl->SetAppAsDefaultAll(This,pszAppRegistryName)
#define IApplicationAssociationRegistration_ClearUserAssociations(This) (This)->lpVtbl->ClearUserAssociations(This)
#endif

#endif

HRESULT STDMETHODCALLTYPE IApplicationAssociationRegistration_QueryCurrentDefault_Proxy(
    IApplicationAssociationRegistration* This,
    LPCWSTR pszQuery,
    ASSOCIATIONTYPE atQueryType,
    ASSOCIATIONLEVEL alQueryLevel,
    LPWSTR *ppszAssociation);
void __RPC_STUB IApplicationAssociationRegistration_QueryCurrentDefault_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IApplicationAssociationRegistration_QueryAppIsDefault_Proxy(
    IApplicationAssociationRegistration* This,
    LPCWSTR pszQuery,
    ASSOCIATIONTYPE atQueryType,
    ASSOCIATIONLEVEL alQueryLevel,
    LPCWSTR pszAppRegistryName,
    BOOL *pfDefault);
void __RPC_STUB IApplicationAssociationRegistration_QueryAppIsDefault_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IApplicationAssociationRegistration_QueryAppIsDefaultAll_Proxy(
    IApplicationAssociationRegistration* This,
    ASSOCIATIONLEVEL alQueryLevel,
    LPCWSTR pszAppRegistryName,
    BOOL *pfDefault);
void __RPC_STUB IApplicationAssociationRegistration_QueryAppIsDefaultAll_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IApplicationAssociationRegistration_SetAppAsDefault_Proxy(
    IApplicationAssociationRegistration* This,
    LPCWSTR pszAppRegistryName,
    LPCWSTR pszSet,
    ASSOCIATIONTYPE atSetType);
void __RPC_STUB IApplicationAssociationRegistration_SetAppAsDefault_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IApplicationAssociationRegistration_SetAppAsDefaultAll_Proxy(
    IApplicationAssociationRegistration* This,
    LPCWSTR pszAppRegistryName);
void __RPC_STUB IApplicationAssociationRegistration_SetAppAsDefaultAll_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IApplicationAssociationRegistration_ClearUserAssociations_Proxy(
    IApplicationAssociationRegistration* This);
void __RPC_STUB IApplicationAssociationRegistration_ClearUserAssociations_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IApplicationAssociationRegistration_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ICustomDestinationList interface
 */
#ifndef __ICustomDestinationList_INTERFACE_DEFINED__
#define __ICustomDestinationList_INTERFACE_DEFINED__

typedef enum KNOWNDESTCATEGORY {
    KDC_FREQUENT = 1,
    KDC_RECENT = 2
} KNOWNDESTCATEGORY;

DEFINE_GUID(IID_ICustomDestinationList, 0x6332debf, 0x87b5, 0x4670, 0x90,0xc0, 0x5e,0x57,0xb4,0x08,0xa4,0x9e);
#if defined(__cplusplus) && !defined(CINTERFACE)
interface ICustomDestinationList : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE SetAppID(
        LPCWSTR pszAppID) = 0;

    virtual HRESULT STDMETHODCALLTYPE BeginList(
        UINT *pcMinSlots,
        REFIID riid,
        void **ppv) = 0;

    virtual HRESULT STDMETHODCALLTYPE AppendCategory(
        LPCWSTR pszCategory,
        IObjectArray *poa) = 0;

    virtual HRESULT STDMETHODCALLTYPE AppendKnownCategory(
        KNOWNDESTCATEGORY category) = 0;

    virtual HRESULT STDMETHODCALLTYPE AddUserTasks(
        IObjectArray *poa) = 0;

    virtual HRESULT STDMETHODCALLTYPE CommitList(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetRemovedDestinations(
        REFIID riid,
        void **ppv) = 0;

    virtual HRESULT STDMETHODCALLTYPE DeleteList(
        LPCWSTR pszAppID) = 0;

    virtual HRESULT STDMETHODCALLTYPE AbortList(
        ) = 0;

};
#else
typedef struct ICustomDestinationListVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ICustomDestinationList* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ICustomDestinationList* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ICustomDestinationList* This);

    /*** ICustomDestinationList methods ***/
    HRESULT (STDMETHODCALLTYPE *SetAppID)(
        ICustomDestinationList* This,
        LPCWSTR pszAppID);

    HRESULT (STDMETHODCALLTYPE *BeginList)(
        ICustomDestinationList* This,
        UINT *pcMinSlots,
        REFIID riid,
        void **ppv);

    HRESULT (STDMETHODCALLTYPE *AppendCategory)(
        ICustomDestinationList* This,
        LPCWSTR pszCategory,
        IObjectArray *poa);

    HRESULT (STDMETHODCALLTYPE *AppendKnownCategory)(
        ICustomDestinationList* This,
        KNOWNDESTCATEGORY category);

    HRESULT (STDMETHODCALLTYPE *AddUserTasks)(
        ICustomDestinationList* This,
        IObjectArray *poa);

    HRESULT (STDMETHODCALLTYPE *CommitList)(
        ICustomDestinationList* This);

    HRESULT (STDMETHODCALLTYPE *GetRemovedDestinations)(
        ICustomDestinationList* This,
        REFIID riid,
        void **ppv);

    HRESULT (STDMETHODCALLTYPE *DeleteList)(
        ICustomDestinationList* This,
        LPCWSTR pszAppID);

    HRESULT (STDMETHODCALLTYPE *AbortList)(
        ICustomDestinationList* This);

    END_INTERFACE
} ICustomDestinationListVtbl;
interface ICustomDestinationList {
    CONST_VTBL ICustomDestinationListVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define ICustomDestinationList_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICustomDestinationList_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICustomDestinationList_Release(This) (This)->lpVtbl->Release(This)
/*** ICustomDestinationList methods ***/
#define ICustomDestinationList_SetAppID(This,pszAppID) (This)->lpVtbl->SetAppID(This,pszAppID)
#define ICustomDestinationList_BeginList(This,pcMinSlots,riid,ppv) (This)->lpVtbl->BeginList(This,pcMinSlots,riid,ppv)
#define ICustomDestinationList_AppendCategory(This,pszCategory,poa) (This)->lpVtbl->AppendCategory(This,pszCategory,poa)
#define ICustomDestinationList_AppendKnownCategory(This,category) (This)->lpVtbl->AppendKnownCategory(This,category)
#define ICustomDestinationList_AddUserTasks(This,poa) (This)->lpVtbl->AddUserTasks(This,poa)
#define ICustomDestinationList_CommitList(This) (This)->lpVtbl->CommitList(This)
#define ICustomDestinationList_GetRemovedDestinations(This,riid,ppv) (This)->lpVtbl->GetRemovedDestinations(This,riid,ppv)
#define ICustomDestinationList_DeleteList(This,pszAppID) (This)->lpVtbl->DeleteList(This,pszAppID)
#define ICustomDestinationList_AbortList(This) (This)->lpVtbl->AbortList(This)
#endif

#endif
#endif  /* __ICustomDestinationList_INTERFACE_DEFINED__ */

#ifndef __ShellObjects_LIBRARY_DEFINED__
#define __ShellObjects_LIBRARY_DEFINED__
#define SID_PublishingWizard CLSID_PublishingWizard
  EXTERN_C const IID LIBID_ShellObjects;
  EXTERN_C const CLSID CLSID_QueryCancelAutoPlay;
#ifdef __cplusplus
  class QueryCancelAutoPlay;
#endif
  EXTERN_C const CLSID CLSID_DriveSizeCategorizer;
#ifdef __cplusplus
  class DriveSizeCategorizer;
#endif
  EXTERN_C const CLSID CLSID_DriveTypeCategorizer;
#ifdef __cplusplus
  class DriveTypeCategorizer;
#endif
  EXTERN_C const CLSID CLSID_FreeSpaceCategorizer;
#ifdef __cplusplus
  class FreeSpaceCategorizer;
#endif
  EXTERN_C const CLSID CLSID_TimeCategorizer;
#ifdef __cplusplus
  class TimeCategorizer;
#endif
  EXTERN_C const CLSID CLSID_SizeCategorizer;
#ifdef __cplusplus
  class SizeCategorizer;
#endif
  EXTERN_C const CLSID CLSID_AlphabeticalCategorizer;
#ifdef __cplusplus
  class AlphabeticalCategorizer;
#endif
  EXTERN_C const CLSID CLSID_MergedCategorizer;
#ifdef __cplusplus
  class MergedCategorizer;
#endif
  EXTERN_C const CLSID CLSID_ImageProperties;
#ifdef __cplusplus
  class ImageProperties;
#endif
  EXTERN_C const CLSID CLSID_PropertiesUI;
#ifdef __cplusplus
  class PropertiesUI;
#endif
  EXTERN_C const CLSID CLSID_UserNotification;
#ifdef __cplusplus
  class UserNotification;
#endif
  EXTERN_C const CLSID CLSID_UserEventTimerCallback;
#ifdef __cplusplus
  class UserEventTimerCallback;
#endif
  EXTERN_C const CLSID CLSID_UserEventTimer;
#ifdef __cplusplus
  class UserEventTimer;
#endif
  EXTERN_C const CLSID CLSID_NetCrawler;
#ifdef __cplusplus
  class NetCrawler;
#endif
  EXTERN_C const CLSID CLSID_CDBurn;
#ifdef __cplusplus
  class CDBurn;
#endif
  EXTERN_C const CLSID CLSID_TaskbarList;
#ifdef __cplusplus
  class TaskbarList;
#endif
  EXTERN_C const CLSID CLSID_WebWizardHost;
#ifdef __cplusplus
  class WebWizardHost;
#endif
  EXTERN_C const CLSID CLSID_PublishDropTarget;
#ifdef __cplusplus
  class PublishDropTarget;
#endif
  EXTERN_C const CLSID CLSID_PublishingWizard;
#ifdef __cplusplus
  class PublishingWizard;
#endif
  EXTERN_C const CLSID CLSID_InternetPrintOrdering;
#ifdef __cplusplus
  class InternetPrintOrdering;
#endif
  EXTERN_C const CLSID CLSID_FolderViewHost;
#ifdef __cplusplus
  class FolderViewHost;
#endif
  EXTERN_C const CLSID CLSID_NamespaceWalker;
#ifdef __cplusplus
  class NamespaceWalker;
#endif
  EXTERN_C const CLSID CLSID_ImageRecompress;
#ifdef __cplusplus
  class ImageRecompress;
#endif
  EXTERN_C const CLSID CLSID_TrayBandSiteService;
#ifdef __cplusplus
  class TrayBandSiteService;
#endif
  EXTERN_C const CLSID CLSID_PassportWizard;
#ifdef __cplusplus
  class PassportWizard;
#endif
DEFINE_GUID(CLSID_AttachmentServices, 0x4125dd96,0xe03a,0x4103,0x8f,0x70,0xe0,0x59,0x7d,0x80,0x3b,0x9c);
#ifdef __cplusplus
  class AttachmentServices;
#endif

/*****************************************************************************
 * ApplicationAssociationRegistration coclass
 */

DEFINE_GUID(CLSID_ApplicationAssociationRegistration, 0x591209c7, 0x767b, 0x42b2, 0x9f,0xba, 0x44,0xee,0x46,0x15,0xf2,0xc7);

/*****************************************************************************
 * ShellLink coclass
 */

DEFINE_GUID(CLSID_ShellLink, 0x00021401, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);

/*****************************************************************************
 * TaskbarList coclass
 */

DEFINE_GUID(CLSID_TaskbarList, 0x56fdf344, 0xfd6d, 0x11d0, 0x95,0x8a, 0x00,0x60,0x97,0xc9,0xa0,0x90);

/*****************************************************************************
 * DestinationList coclass
 */

DEFINE_GUID(CLSID_DestinationList, 0x77f10cf0, 0x3db5, 0x4966, 0xb5,0x20, 0xb7,0xc5,0x4f,0xd3,0x5e,0xd6);

/*****************************************************************************
 * EnumerableObjectCollection coclass
 */

DEFINE_GUID(CLSID_EnumerableObjectCollection, 0x2d3468c1, 0x36a7, 0x43b6, 0xac,0x24, 0xd3,0xf0,0x2f,0xd9,0x60,0x7a);

#endif

  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0263_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0263_v0_0_s_ifspec;

  unsigned long __RPC_API BSTR_UserSize(unsigned long *,unsigned long,BSTR *);
  unsigned char *__RPC_API BSTR_UserMarshal(unsigned long *,unsigned char *,BSTR *);
  unsigned char *__RPC_API BSTR_UserUnmarshal(unsigned long *,unsigned char *,BSTR *);
  void __RPC_API BSTR_UserFree(unsigned long *,BSTR *);
  unsigned long __RPC_API HBITMAP_UserSize(unsigned long *,unsigned long,HBITMAP *);
  unsigned char *__RPC_API HBITMAP_UserMarshal(unsigned long *,unsigned char *,HBITMAP *);
  unsigned char *__RPC_API HBITMAP_UserUnmarshal(unsigned long *,unsigned char *,HBITMAP *);
  void __RPC_API HBITMAP_UserFree(unsigned long *,HBITMAP *);
  unsigned long __RPC_API HGLOBAL_UserSize(unsigned long *,unsigned long,HGLOBAL *);
  unsigned char *__RPC_API HGLOBAL_UserMarshal(unsigned long *,unsigned char *,HGLOBAL *);
  unsigned char *__RPC_API HGLOBAL_UserUnmarshal(unsigned long *,unsigned char *,HGLOBAL *);
  void __RPC_API HGLOBAL_UserFree(unsigned long *,HGLOBAL *);
  unsigned long __RPC_API HICON_UserSize(unsigned long *,unsigned long,HICON *);
  unsigned char *__RPC_API HICON_UserMarshal(unsigned long *,unsigned char *,HICON *);
  unsigned char *__RPC_API HICON_UserUnmarshal(unsigned long *,unsigned char *,HICON *);
  void __RPC_API HICON_UserFree(unsigned long *,HICON *);
  unsigned long __RPC_API HMENU_UserSize(unsigned long *,unsigned long,HMENU *);
  unsigned char *__RPC_API HMENU_UserMarshal(unsigned long *,unsigned char *,HMENU *);
  unsigned char *__RPC_API HMENU_UserUnmarshal(unsigned long *,unsigned char *,HMENU *);
  void __RPC_API HMENU_UserFree(unsigned long *,HMENU *);
  unsigned long __RPC_API HWND_UserSize(unsigned long *,unsigned long,HWND *);
  unsigned char *__RPC_API HWND_UserMarshal(unsigned long *,unsigned char *,HWND *);
  unsigned char *__RPC_API HWND_UserUnmarshal(unsigned long *,unsigned char *,HWND *);
  void __RPC_API HWND_UserFree(unsigned long *,HWND *);
  unsigned long __RPC_API LPCITEMIDLIST_UserSize(unsigned long *,unsigned long,LPCITEMIDLIST *);
  unsigned char *__RPC_API LPCITEMIDLIST_UserMarshal(unsigned long *,unsigned char *,LPCITEMIDLIST *);
  unsigned char *__RPC_API LPCITEMIDLIST_UserUnmarshal(unsigned long *,unsigned char *,LPCITEMIDLIST *);
  void __RPC_API LPCITEMIDLIST_UserFree(unsigned long *,LPCITEMIDLIST *);
  unsigned long __RPC_API LPITEMIDLIST_UserSize(unsigned long *,unsigned long,LPITEMIDLIST *);
  unsigned char *__RPC_API LPITEMIDLIST_UserMarshal(unsigned long *,unsigned char *,LPITEMIDLIST *);
  unsigned char *__RPC_API LPITEMIDLIST_UserUnmarshal(unsigned long *,unsigned char *,LPITEMIDLIST *);
  void __RPC_API LPITEMIDLIST_UserFree(unsigned long *,LPITEMIDLIST *);
  unsigned long __RPC_API LPSAFEARRAY_UserSize(unsigned long *,unsigned long,LPSAFEARRAY *);
  unsigned char *__RPC_API LPSAFEARRAY_UserMarshal(unsigned long *,unsigned char *,LPSAFEARRAY *);
  unsigned char *__RPC_API LPSAFEARRAY_UserUnmarshal(unsigned long *,unsigned char *,LPSAFEARRAY *);
  void __RPC_API LPSAFEARRAY_UserFree(unsigned long *,LPSAFEARRAY *);
  unsigned long __RPC_API VARIANT_UserSize(unsigned long *,unsigned long,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserMarshal(unsigned long *,unsigned char *,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserUnmarshal(unsigned long *,unsigned char *,VARIANT *);
  void __RPC_API VARIANT_UserFree(unsigned long *,VARIANT *);

#ifdef __cplusplus
}
#endif
#endif
