/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fsrmenums.h>
#include <fsrm.h>
#include <fsrmquota.h>

#ifndef _INC_FSRMSCREEN
#define _INC_FSRMSCREEN
#if (_WIN32_WINNT >= 0x0600)

#ifndef __IFsrmAction_FWD_DEFINED__
#define __IFsrmAction_FWD_DEFINED__
typedef struct IFsrmAction IFsrmAction;
#endif /* __IFsrmAction_FWD_DEFINED__ */

#ifndef __IFsrmActionCommand_FWD_DEFINED__
#define __IFsrmActionCommand_FWD_DEFINED__
typedef struct IFsrmActionCommand IFsrmActionCommand;
#endif /* __IFsrmActionCommand_FWD_DEFINED__ */

#ifndef __IFsrmActionEmail_FWD_DEFINED__
#define __IFsrmActionEmail_FWD_DEFINED__
typedef struct IFsrmActionEmail IFsrmActionEmail;
#endif /* __IFsrmActionEmail_FWD_DEFINED__ */

#ifndef __IFsrmActionEmail2_FWD_DEFINED__
#define __IFsrmActionEmail2_FWD_DEFINED__
typedef struct IFsrmActionEmail2 IFsrmActionEmail2;
#endif /* __IFsrmActionEmail2_FWD_DEFINED__ */

#ifndef __IFsrmActionEventLog_FWD_DEFINED__
#define __IFsrmActionEventLog_FWD_DEFINED__
typedef struct IFsrmActionEventLog IFsrmActionEventLog;
#endif /* __IFsrmActionEventLog_FWD_DEFINED__ */

#ifndef __IFsrmActionReport_FWD_DEFINED__
#define __IFsrmActionReport_FWD_DEFINED__
typedef struct IFsrmActionReport IFsrmActionReport;
#endif /* __IFsrmActionReport_FWD_DEFINED__ */

#ifndef __IFsrmAutoApplyQuota_FWD_DEFINED__
#define __IFsrmAutoApplyQuota_FWD_DEFINED__
typedef struct IFsrmAutoApplyQuota IFsrmAutoApplyQuota;
#endif /* __IFsrmAutoApplyQuota_FWD_DEFINED__ */

#ifndef __IFsrmClassificationManager_FWD_DEFINED__
#define __IFsrmClassificationManager_FWD_DEFINED__
typedef struct IFsrmClassificationManager IFsrmClassificationManager;
#endif /* __IFsrmClassificationManager_FWD_DEFINED__ */

#ifndef __IFsrmClassificationRule_FWD_DEFINED__
#define __IFsrmClassificationRule_FWD_DEFINED__
typedef struct IFsrmClassificationRule IFsrmClassificationRule;
#endif /* __IFsrmClassificationRule_FWD_DEFINED__ */

#ifndef __IFsrmClassifierModuleDefinition_FWD_DEFINED__
#define __IFsrmClassifierModuleDefinition_FWD_DEFINED__
typedef struct IFsrmClassifierModuleDefinition IFsrmClassifierModuleDefinition;
#endif /* __IFsrmClassifierModuleDefinition_FWD_DEFINED__ */

#ifndef __IFsrmClassifierModuleImplementation_FWD_DEFINED__
#define __IFsrmClassifierModuleImplementation_FWD_DEFINED__
typedef struct IFsrmClassifierModuleImplementation IFsrmClassifierModuleImplementation;
#endif /* __IFsrmClassifierModuleImplementation_FWD_DEFINED__ */

#ifndef __IFsrmCollection_FWD_DEFINED__
#define __IFsrmCollection_FWD_DEFINED__
typedef struct IFsrmCollection IFsrmCollection;
#endif /* __IFsrmCollection_FWD_DEFINED__ */

#ifndef __IFsrmCommittableCollection_FWD_DEFINED__
#define __IFsrmCommittableCollection_FWD_DEFINED__
typedef struct IFsrmCommittableCollection IFsrmCommittableCollection;
#endif /* __IFsrmCommittableCollection_FWD_DEFINED__ */

#ifndef __IFsrmDerivedObjectsResult_FWD_DEFINED__
#define __IFsrmDerivedObjectsResult_FWD_DEFINED__
typedef struct IFsrmDerivedObjectsResult IFsrmDerivedObjectsResult;
#endif /* __IFsrmDerivedObjectsResult_FWD_DEFINED__ */

#ifndef __IFsrmExportImport_FWD_DEFINED__
#define __IFsrmExportImport_FWD_DEFINED__
typedef struct IFsrmExportImport IFsrmExportImport;
#endif /* __IFsrmExportImport_FWD_DEFINED__ */

#ifndef __IFsrmFileGroup_FWD_DEFINED__
#define __IFsrmFileGroup_FWD_DEFINED__
typedef struct IFsrmFileGroup IFsrmFileGroup;
#endif /* __IFsrmFileGroup_FWD_DEFINED__ */

#ifndef __IFsrmFileGroupImported_FWD_DEFINED__
#define __IFsrmFileGroupImported_FWD_DEFINED__
typedef struct IFsrmFileGroupImported IFsrmFileGroupImported;
#endif /* __IFsrmFileGroupImported_FWD_DEFINED__ */

#ifndef __IFsrmFileGroupManager_FWD_DEFINED__
#define __IFsrmFileGroupManager_FWD_DEFINED__
typedef struct IFsrmFileGroupManager IFsrmFileGroupManager;
#endif /* __IFsrmFileGroupManager_FWD_DEFINED__ */

#ifndef __IFsrmFileManagementJob_FWD_DEFINED__
#define __IFsrmFileManagementJob_FWD_DEFINED__
typedef struct IFsrmFileManagementJob IFsrmFileManagementJob;
#endif /* __IFsrmFileManagementJob_FWD_DEFINED__ */

#ifndef __IFsrmFileManagementJobManager_FWD_DEFINED__
#define __IFsrmFileManagementJobManager_FWD_DEFINED__
typedef struct IFsrmFileManagementJobManager IFsrmFileManagementJobManager;
#endif /* __IFsrmFileManagementJobManager_FWD_DEFINED__ */

#ifndef __IFsrmFileScreen_FWD_DEFINED__
#define __IFsrmFileScreen_FWD_DEFINED__
typedef struct IFsrmFileScreen IFsrmFileScreen;
#endif /* __IFsrmFileScreen_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenBase_FWD_DEFINED__
#define __IFsrmFileScreenBase_FWD_DEFINED__
typedef struct IFsrmFileScreenBase IFsrmFileScreenBase;
#endif /* __IFsrmFileScreenBase_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenException_FWD_DEFINED__
#define __IFsrmFileScreenException_FWD_DEFINED__
typedef struct IFsrmFileScreenException IFsrmFileScreenException;
#endif /* __IFsrmFileScreenException_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenManager_FWD_DEFINED__
#define __IFsrmFileScreenManager_FWD_DEFINED__
typedef struct IFsrmFileScreenManager IFsrmFileScreenManager;
#endif /* __IFsrmFileScreenManager_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenTemplate_FWD_DEFINED__
#define __IFsrmFileScreenTemplate_FWD_DEFINED__
typedef struct IFsrmFileScreenTemplate IFsrmFileScreenTemplate;
#endif /* __IFsrmFileScreenTemplate_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenTemplateImported_FWD_DEFINED__
#define __IFsrmFileScreenTemplateImported_FWD_DEFINED__
typedef struct IFsrmFileScreenTemplateImported IFsrmFileScreenTemplateImported;
#endif /* __IFsrmFileScreenTemplateImported_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenTemplateManager_FWD_DEFINED__
#define __IFsrmFileScreenTemplateManager_FWD_DEFINED__
typedef struct IFsrmFileScreenTemplateManager IFsrmFileScreenTemplateManager;
#endif /* __IFsrmFileScreenTemplateManager_FWD_DEFINED__ */

#ifndef __IFsrmMutableCollection_FWD_DEFINED__
#define __IFsrmMutableCollection_FWD_DEFINED__
typedef struct IFsrmMutableCollection IFsrmMutableCollection;
#endif /* __IFsrmMutableCollection_FWD_DEFINED__ */

#ifndef __IFsrmObject_FWD_DEFINED__
#define __IFsrmObject_FWD_DEFINED__
typedef struct IFsrmObject IFsrmObject;
#endif /* __IFsrmObject_FWD_DEFINED__ */

#ifndef __IFsrmPathMapper_FWD_DEFINED__
#define __IFsrmPathMapper_FWD_DEFINED__
typedef struct IFsrmPathMapper IFsrmPathMapper;
#endif /* __IFsrmPathMapper_FWD_DEFINED__ */

#ifndef __IFsrmPipelineModuleConnector_FWD_DEFINED__
#define __IFsrmPipelineModuleConnector_FWD_DEFINED__
typedef struct IFsrmPipelineModuleConnector IFsrmPipelineModuleConnector;
#endif /* __IFsrmPipelineModuleConnector_FWD_DEFINED__ */

#ifndef __IFsrmPipelineModuleDefinition_FWD_DEFINED__
#define __IFsrmPipelineModuleDefinition_FWD_DEFINED__
typedef struct IFsrmPipelineModuleDefinition IFsrmPipelineModuleDefinition;
#endif /* __IFsrmPipelineModuleDefinition_FWD_DEFINED__ */

#ifndef __IFsrmPipelineModuleImplementation_FWD_DEFINED__
#define __IFsrmPipelineModuleImplementation_FWD_DEFINED__
typedef struct IFsrmPipelineModuleImplementation IFsrmPipelineModuleImplementation;
#endif /* __IFsrmPipelineModuleImplementation_FWD_DEFINED__ */

#ifndef __IFsrmProperty_FWD_DEFINED__
#define __IFsrmProperty_FWD_DEFINED__
typedef struct IFsrmProperty IFsrmProperty;
#endif /* __IFsrmProperty_FWD_DEFINED__ */

#ifndef __IFsrmPropertyBag_FWD_DEFINED__
#define __IFsrmPropertyBag_FWD_DEFINED__
typedef struct IFsrmPropertyBag IFsrmPropertyBag;
#endif /* __IFsrmPropertyBag_FWD_DEFINED__ */

#ifndef __IFsrmPropertyCondition_FWD_DEFINED__
#define __IFsrmPropertyCondition_FWD_DEFINED__
typedef struct IFsrmPropertyCondition IFsrmPropertyCondition;
#endif /* __IFsrmPropertyCondition_FWD_DEFINED__ */

#ifndef __IFsrmPropertyDefinition_FWD_DEFINED__
#define __IFsrmPropertyDefinition_FWD_DEFINED__
typedef struct IFsrmPropertyDefinition IFsrmPropertyDefinition;
#endif /* __IFsrmPropertyDefinition_FWD_DEFINED__ */

#ifndef __IFsrmQuota_FWD_DEFINED__
#define __IFsrmQuota_FWD_DEFINED__
typedef struct IFsrmQuota IFsrmQuota;
#endif /* __IFsrmQuota_FWD_DEFINED__ */

#ifndef __IFsrmQuotaBase_FWD_DEFINED__
#define __IFsrmQuotaBase_FWD_DEFINED__
typedef struct IFsrmQuotaBase IFsrmQuotaBase;
#endif /* __IFsrmQuotaBase_FWD_DEFINED__ */

#ifndef __IFsrmQuotaManager_FWD_DEFINED__
#define __IFsrmQuotaManager_FWD_DEFINED__
typedef struct IFsrmQuotaManager IFsrmQuotaManager;
#endif /* __IFsrmQuotaManager_FWD_DEFINED__ */

#ifndef __IFsrmQuotaManagerEx_FWD_DEFINED__
#define __IFsrmQuotaManagerEx_FWD_DEFINED__
typedef struct IFsrmQuotaManagerEx IFsrmQuotaManagerEx;
#endif /* __IFsrmQuotaManagerEx_FWD_DEFINED__ */

#ifndef __IFsrmQuotaObject_FWD_DEFINED__
#define __IFsrmQuotaObject_FWD_DEFINED__
typedef struct IFsrmQuotaObject IFsrmQuotaObject;
#endif /* __IFsrmQuotaObject_FWD_DEFINED__ */

#ifndef __IFsrmQuotaTemplate_FWD_DEFINED__
#define __IFsrmQuotaTemplate_FWD_DEFINED__
typedef struct IFsrmQuotaTemplate IFsrmQuotaTemplate;
#endif /* __IFsrmQuotaTemplate_FWD_DEFINED__ */

#ifndef __IFsrmQuotaTemplateImported_FWD_DEFINED__
#define __IFsrmQuotaTemplateImported_FWD_DEFINED__
typedef struct IFsrmQuotaTemplateImported IFsrmQuotaTemplateImported;
#endif /* __IFsrmQuotaTemplateImported_FWD_DEFINED__ */

#ifndef __IFsrmQuotaTemplateManager_FWD_DEFINED__
#define __IFsrmQuotaTemplateManager_FWD_DEFINED__
typedef struct IFsrmQuotaTemplateManager IFsrmQuotaTemplateManager;
#endif /* __IFsrmQuotaTemplateManager_FWD_DEFINED__ */

#ifndef __IFsrmReport_FWD_DEFINED__
#define __IFsrmReport_FWD_DEFINED__
typedef struct IFsrmReport IFsrmReport;
#endif /* __IFsrmReport_FWD_DEFINED__ */

#ifndef __IFsrmReportJob_FWD_DEFINED__
#define __IFsrmReportJob_FWD_DEFINED__
typedef struct IFsrmReportJob IFsrmReportJob;
#endif /* __IFsrmReportJob_FWD_DEFINED__ */

#ifndef __IFsrmReportManager_FWD_DEFINED__
#define __IFsrmReportManager_FWD_DEFINED__
typedef struct IFsrmReportManager IFsrmReportManager;
#endif /* __IFsrmReportManager_FWD_DEFINED__ */

#ifndef __IFsrmReportScheduler_FWD_DEFINED__
#define __IFsrmReportScheduler_FWD_DEFINED__
typedef struct IFsrmReportScheduler IFsrmReportScheduler;
#endif /* __IFsrmReportScheduler_FWD_DEFINED__ */

#ifndef __IFsrmRule_FWD_DEFINED__
#define __IFsrmRule_FWD_DEFINED__
typedef struct IFsrmRule IFsrmRule;
#endif /* __IFsrmRule_FWD_DEFINED__ */

#ifndef __IFsrmSetting_FWD_DEFINED__
#define __IFsrmSetting_FWD_DEFINED__
typedef struct IFsrmSetting IFsrmSetting;
#endif /* __IFsrmSetting_FWD_DEFINED__ */

#ifndef __IFsrmStorageModuleDefinition_FWD_DEFINED__
#define __IFsrmStorageModuleDefinition_FWD_DEFINED__
typedef struct IFsrmStorageModuleDefinition IFsrmStorageModuleDefinition;
#endif /* __IFsrmStorageModuleDefinition_FWD_DEFINED__ */

#ifndef __IFsrmStorageModuleImplementation_FWD_DEFINED__
#define __IFsrmStorageModuleImplementation_FWD_DEFINED__
typedef struct IFsrmStorageModuleImplementation IFsrmStorageModuleImplementation;
#endif /* __IFsrmStorageModuleImplementation_FWD_DEFINED__ */

#undef  INTERFACE
#define INTERFACE IFsrmFileGroup
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileGroup,IFsrmObject)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmFileGroup methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *name) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_Members)(THIS_ IFsrmMutableCollection **members) PURE;
    STDMETHOD_(HRESULT,put_Members)(THIS_ IFsrmMutableCollection *members) PURE;
    STDMETHOD_(HRESULT,get_NonMembers)(THIS_ IFsrmMutableCollection **nonMembers) PURE;
    STDMETHOD_(HRESULT,put_NonMembers)(THIS_ IFsrmMutableCollection *nonMembers) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileGroup_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileGroup_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileGroup_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileGroup_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileGroup_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmFileGroup_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmFileGroup_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmFileGroup_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmFileGroup_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmFileGroup_get_Name(This,name) (This)->lpVtbl->get_Name(This,name)
#define IFsrmFileGroup_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmFileGroup_get_Members(This,members) (This)->lpVtbl->get_Members(This,members)
#define IFsrmFileGroup_put_Members(This,members) (This)->lpVtbl->put_Members(This,members)
#define IFsrmFileGroup_get_NonMembers(This,nonMembers) (This)->lpVtbl->get_NonMembers(This,nonMembers)
#define IFsrmFileGroup_put_NonMembers(This,nonMembers) (This)->lpVtbl->put_NonMembers(This,nonMembers)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmFileGroupImported
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileGroupImported,IFsrmFileGroup)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmFileGroup methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *name) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_Members)(THIS_ IFsrmMutableCollection **members) PURE;
    STDMETHOD_(HRESULT,put_Members)(THIS_ IFsrmMutableCollection *members) PURE;
    STDMETHOD_(HRESULT,get_NonMembers)(THIS_ IFsrmMutableCollection **nonMembers) PURE;
    STDMETHOD_(HRESULT,put_NonMembers)(THIS_ IFsrmMutableCollection *nonMembers) PURE;

    /* IFsrmFileGroupImported methods */
    STDMETHOD_(HRESULT,get_OverwriteOnCommit)(THIS_ VARIANT_BOOL *overwrite) PURE;
    STDMETHOD_(HRESULT,put_OverwriteOnCommit)(THIS_ VARIANT_BOOL overwrite) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileGroupImported_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileGroupImported_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileGroupImported_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileGroupImported_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileGroupImported_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileGroupImported_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileGroupImported_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileGroupImported_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmFileGroupImported_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmFileGroupImported_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmFileGroupImported_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmFileGroupImported_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmFileGroupImported_get_Name(This,name) (This)->lpVtbl->get_Name(This,name)
#define IFsrmFileGroupImported_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmFileGroupImported_get_Members(This,members) (This)->lpVtbl->get_Members(This,members)
#define IFsrmFileGroupImported_put_Members(This,members) (This)->lpVtbl->put_Members(This,members)
#define IFsrmFileGroupImported_get_NonMembers(This,nonMembers) (This)->lpVtbl->get_NonMembers(This,nonMembers)
#define IFsrmFileGroupImported_put_NonMembers(This,nonMembers) (This)->lpVtbl->put_NonMembers(This,nonMembers)
#define IFsrmFileGroupImported_get_OverwriteOnCommit(This,overwrite) (This)->lpVtbl->get_OverwriteOnCommit(This,overwrite)
#define IFsrmFileGroupImported_put_OverwriteOnCommit(This,overwrite) (This)->lpVtbl->put_OverwriteOnCommit(This,overwrite)
#endif /*COBJMACROS*/


#undef  INTERFACE
#define INTERFACE IFsrmFileGroupManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileGroupManager,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmFileGroupManager methods */
    STDMETHOD_(HRESULT,CreateFileGroup)(THIS_ IFsrmFileGroup **fileGroup) PURE;
    STDMETHOD_(HRESULT,GetFileGroup)(THIS_ BSTR name,IFsrmFileGroup **fileGroup) PURE;
    STDMETHOD_(HRESULT,EnumFileGroups)(THIS_ FsrmEnumOptions options,IFsrmCommittableCollection **fileGroups) PURE;
    STDMETHOD_(HRESULT,ExportFileGroups)(THIS_ VARIANT *fileGroupNamesArray,BSTR *serializedFileGroups) PURE;
    STDMETHOD_(HRESULT,ImportFileGroups)(THIS_ BSTR serializedFileGroups,VARIANT *fileGroupNamesArray,IFsrmCommittableCollection **fileGroups) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileGroupManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileGroupManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileGroupManager_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileGroupManager_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileGroupManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileGroupManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileGroupManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileGroupManager_CreateFileGroup(This,fileGroup) (This)->lpVtbl->CreateFileGroup(This,fileGroup)
#define IFsrmFileGroupManager_GetFileGroup(This,name,fileGroup) (This)->lpVtbl->GetFileGroup(This,name,fileGroup)
#define IFsrmFileGroupManager_EnumFileGroups(This,options,fileGroups) (This)->lpVtbl->EnumFileGroups(This,options,fileGroups)
#define IFsrmFileGroupManager_ExportFileGroups(This,fileGroupNamesArray,serializedFileGroups) (This)->lpVtbl->ExportFileGroups(This,fileGroupNamesArray,serializedFileGroups)
#define IFsrmFileGroupManager_ImportFileGroups(This,serializedFileGroups,fileGroupNamesArray,fileGroups) (This)->lpVtbl->ImportFileGroups(This,serializedFileGroups,fileGroupNamesArray,fileGroups)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmFileScreenBase
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileScreenBase,IFsrmObject)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmFileScreenBase methods */
    STDMETHOD_(HRESULT,get_BlockedFileGroups)(THIS_ IFsrmMutableCollection **blockList) PURE;
    STDMETHOD_(HRESULT,put_BlockedFileGroups)(THIS_ IFsrmMutableCollection *blockList) PURE;
    STDMETHOD_(HRESULT,get_FileScreenFlags)(THIS_ long *fileScreenFlags) PURE;
    STDMETHOD_(HRESULT,put_FileScreenFlags)(THIS_ long fileScreenFlags) PURE;
    STDMETHOD_(HRESULT,get_UserSid)(THIS_ BSTR *userSid) PURE;
    STDMETHOD_(HRESULT,get_UserAccount)(THIS_ BSTR *userAccount) PURE;
    STDMETHOD_(HRESULT,CreateAction)(THIS_ FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumActions)(THIS_ IFsrmCollection **actions) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileScreenBase_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileScreenBase_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileScreenBase_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileScreenBase_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileScreenBase_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileScreenBase_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileScreenBase_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileScreenBase_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmFileScreenBase_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmFileScreenBase_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmFileScreenBase_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmFileScreenBase_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmFileScreenBase_get_BlockedFileGroups(This,blockList) (This)->lpVtbl->get_BlockedFileGroups(This,blockList)
#define IFsrmFileScreenBase_put_BlockedFileGroups(This,blockList) (This)->lpVtbl->put_BlockedFileGroups(This,blockList)
#define IFsrmFileScreenBase_get_FileScreenFlags(This,fileScreenFlags) (This)->lpVtbl->get_FileScreenFlags(This,fileScreenFlags)
#define IFsrmFileScreenBase_put_FileScreenFlags(This,fileScreenFlags) (This)->lpVtbl->put_FileScreenFlags(This,fileScreenFlags)
#define IFsrmFileScreenBase_get_UserSid(This,userSid) (This)->lpVtbl->get_UserSid(This,userSid)
#define IFsrmFileScreenBase_get_UserAccount(This,userAccount) (This)->lpVtbl->get_UserAccount(This,userAccount)
#define IFsrmFileScreenBase_CreateAction(This,actionType,action) (This)->lpVtbl->CreateAction(This,actionType,action)
#define IFsrmFileScreenBase_EnumActions(This,actions) (This)->lpVtbl->EnumActions(This,actions)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmFileScreenException
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileScreenException,IFsrmObject)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmFileScreenException methods */
    STDMETHOD_(HRESULT,get_Path)(THIS_ BSTR *path) PURE;
    STDMETHOD_(HRESULT,get_AllowedFileGroups)(THIS_ IFsrmMutableCollection **allowList) PURE;
    STDMETHOD_(HRESULT,put_AllowedFileGroups)(THIS_ IFsrmMutableCollection *allowList) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileScreenException_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileScreenException_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileScreenException_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileScreenException_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileScreenException_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileScreenException_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileScreenException_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileScreenException_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmFileScreenException_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmFileScreenException_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmFileScreenException_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmFileScreenException_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmFileScreenException_get_Path(This,path) (This)->lpVtbl->get_Path(This,path)
#define IFsrmFileScreenException_get_AllowedFileGroups(This,allowList) (This)->lpVtbl->get_AllowedFileGroups(This,allowList)
#define IFsrmFileScreenException_put_AllowedFileGroups(This,allowList) (This)->lpVtbl->put_AllowedFileGroups(This,allowList)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmFileScreenManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileScreenManager,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmFileScreenManager methods */
    STDMETHOD_(HRESULT,get_ActionVariables)(THIS_ SAFEARRAY *variables) PURE;
    STDMETHOD_(HRESULT,get_ActionVariableDescriptions)(THIS_ SAFEARRAY *descriptions) PURE;
    STDMETHOD_(HRESULT,CreateFileScreen)(THIS_ BSTR path,IFsrmFileScreen **fileScreen) PURE;
    STDMETHOD_(HRESULT,GetFileScreen)(THIS_ BSTR path,IFsrmFileScreen **fileScreen) PURE;
    STDMETHOD_(HRESULT,EnumFileScreens)(THIS_ BSTR path,FsrmEnumOptions options,IFsrmCommittableCollection **fileScreens) PURE;
    STDMETHOD_(HRESULT,CreateFileScreenException)(THIS_ BSTR path,IFsrmFileScreenException **fileScreenException) PURE;
    STDMETHOD_(HRESULT,GetFileScreenException)(THIS_ BSTR path,IFsrmFileScreenException **fileScreenException) PURE;
    STDMETHOD_(HRESULT,EnumFileScreenExceptions)(THIS_ BSTR path,FsrmEnumOptions options,IFsrmCommittableCollection **fileScreenExceptions) PURE;
    STDMETHOD_(HRESULT,CreateFileScreenCollection)(THIS_ IFsrmCommittableCollection **collection) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileScreenManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileScreenManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileScreenManager_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileScreenManager_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileScreenManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileScreenManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileScreenManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileScreenManager_get_ActionVariables(This,variables) (This)->lpVtbl->get_ActionVariables(This,variables)
#define IFsrmFileScreenManager_get_ActionVariableDescriptions(This,descriptions) (This)->lpVtbl->get_ActionVariableDescriptions(This,descriptions)
#define IFsrmFileScreenManager_CreateFileScreen(This,path,fileScreen) (This)->lpVtbl->CreateFileScreen(This,path,fileScreen)
#define IFsrmFileScreenManager_GetFileScreen(This,path,fileScreen) (This)->lpVtbl->GetFileScreen(This,path,fileScreen)
#define IFsrmFileScreenManager_EnumFileScreens(This,path,options,fileScreens) (This)->lpVtbl->EnumFileScreens(This,path,options,fileScreens)
#define IFsrmFileScreenManager_CreateFileScreenException(This,path,fileScreenException) (This)->lpVtbl->CreateFileScreenException(This,path,fileScreenException)
#define IFsrmFileScreenManager_GetFileScreenException(This,path,fileScreenException) (This)->lpVtbl->GetFileScreenException(This,path,fileScreenException)
#define IFsrmFileScreenManager_EnumFileScreenExceptions(This,path,options,fileScreenExceptions) (This)->lpVtbl->EnumFileScreenExceptions(This,path,options,fileScreenExceptions)
#define IFsrmFileScreenManager_CreateFileScreenCollection(This,collection) (This)->lpVtbl->CreateFileScreenCollection(This,collection)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmFileScreenTemplate
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileScreenTemplate,IFsrmFileScreenBase)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmFileScreenBase methods */
    STDMETHOD_(HRESULT,get_BlockedFileGroups)(THIS_ IFsrmMutableCollection **blockList) PURE;
    STDMETHOD_(HRESULT,put_BlockedFileGroups)(THIS_ IFsrmMutableCollection *blockList) PURE;
    STDMETHOD_(HRESULT,get_FileScreenFlags)(THIS_ long *fileScreenFlags) PURE;
    STDMETHOD_(HRESULT,put_FileScreenFlags)(THIS_ long fileScreenFlags) PURE;
    STDMETHOD_(HRESULT,get_UserSid)(THIS_ BSTR *userSid) PURE;
    STDMETHOD_(HRESULT,get_UserAccount)(THIS_ BSTR *userAccount) PURE;
    STDMETHOD_(HRESULT,CreateAction)(THIS_ FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumActions)(THIS_ IFsrmCollection **actions) PURE;

    /* IFsrmFileScreenTemplate methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *name) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,CopyTemplate)(THIS_ BSTR fileScreenTemplateName) PURE;
    STDMETHOD_(HRESULT,CommitAndUpdateDerived)(THIS_ FsrmCommitOptions commitOptions,FsrmTemplateApplyOptions applyOptions,IFsrmDerivedObjectsResult **derivedObjectsResult) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileScreenTemplate_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileScreenTemplate_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileScreenTemplate_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileScreenTemplate_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileScreenTemplate_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileScreenTemplate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileScreenTemplate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileScreenTemplate_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmFileScreenTemplate_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmFileScreenTemplate_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmFileScreenTemplate_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmFileScreenTemplate_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmFileScreenTemplate_get_BlockedFileGroups(This,blockList) (This)->lpVtbl->get_BlockedFileGroups(This,blockList)
#define IFsrmFileScreenTemplate_put_BlockedFileGroups(This,blockList) (This)->lpVtbl->put_BlockedFileGroups(This,blockList)
#define IFsrmFileScreenTemplate_get_FileScreenFlags(This,fileScreenFlags) (This)->lpVtbl->get_FileScreenFlags(This,fileScreenFlags)
#define IFsrmFileScreenTemplate_put_FileScreenFlags(This,fileScreenFlags) (This)->lpVtbl->put_FileScreenFlags(This,fileScreenFlags)
#define IFsrmFileScreenTemplate_get_UserSid(This,userSid) (This)->lpVtbl->get_UserSid(This,userSid)
#define IFsrmFileScreenTemplate_get_UserAccount(This,userAccount) (This)->lpVtbl->get_UserAccount(This,userAccount)
#define IFsrmFileScreenTemplate_CreateAction(This,actionType,action) (This)->lpVtbl->CreateAction(This,actionType,action)
#define IFsrmFileScreenTemplate_EnumActions(This,actions) (This)->lpVtbl->EnumActions(This,actions)
#define IFsrmFileScreenTemplate_get_Name(This,name) (This)->lpVtbl->get_Name(This,name)
#define IFsrmFileScreenTemplate_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmFileScreenTemplate_CopyTemplate(This,fileScreenTemplateName) (This)->lpVtbl->CopyTemplate(This,fileScreenTemplateName)
#define IFsrmFileScreenTemplate_CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult) (This)->lpVtbl->CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmFileScreenTemplateImported
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileScreenTemplateImported,IFsrmFileScreenTemplate)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmFileScreenBase methods */
    STDMETHOD_(HRESULT,get_BlockedFileGroups)(THIS_ IFsrmMutableCollection **blockList) PURE;
    STDMETHOD_(HRESULT,put_BlockedFileGroups)(THIS_ IFsrmMutableCollection *blockList) PURE;
    STDMETHOD_(HRESULT,get_FileScreenFlags)(THIS_ long *fileScreenFlags) PURE;
    STDMETHOD_(HRESULT,put_FileScreenFlags)(THIS_ long fileScreenFlags) PURE;
    STDMETHOD_(HRESULT,get_UserSid)(THIS_ BSTR *userSid) PURE;
    STDMETHOD_(HRESULT,get_UserAccount)(THIS_ BSTR *userAccount) PURE;
    STDMETHOD_(HRESULT,CreateAction)(THIS_ FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumActions)(THIS_ IFsrmCollection **actions) PURE;

    /* IFsrmFileScreenTemplate methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *name) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,CopyTemplate)(THIS_ BSTR fileScreenTemplateName) PURE;
    STDMETHOD_(HRESULT,CommitAndUpdateDerived)(THIS_ FsrmCommitOptions commitOptions,FsrmTemplateApplyOptions applyOptions,IFsrmDerivedObjectsResult **derivedObjectsResult) PURE;

    /* IFsrmFileScreenTemplateImported methods */
    STDMETHOD_(HRESULT,get_OverwriteOnCommit)(THIS_ VARIANT_BOOL *overwrite) PURE;
    STDMETHOD_(HRESULT,put_OverwriteOnCommit)(THIS_ VARIANT_BOOL overwrite) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileScreenTemplateImported_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileScreenTemplateImported_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileScreenTemplateImported_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileScreenTemplateImported_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileScreenTemplateImported_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileScreenTemplateImported_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileScreenTemplateImported_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileScreenTemplateImported_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmFileScreenTemplateImported_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmFileScreenTemplateImported_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmFileScreenTemplateImported_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmFileScreenTemplateImported_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmFileScreenTemplateImported_get_BlockedFileGroups(This,blockList) (This)->lpVtbl->get_BlockedFileGroups(This,blockList)
#define IFsrmFileScreenTemplateImported_put_BlockedFileGroups(This,blockList) (This)->lpVtbl->put_BlockedFileGroups(This,blockList)
#define IFsrmFileScreenTemplateImported_get_FileScreenFlags(This,fileScreenFlags) (This)->lpVtbl->get_FileScreenFlags(This,fileScreenFlags)
#define IFsrmFileScreenTemplateImported_put_FileScreenFlags(This,fileScreenFlags) (This)->lpVtbl->put_FileScreenFlags(This,fileScreenFlags)
#define IFsrmFileScreenTemplateImported_get_UserSid(This,userSid) (This)->lpVtbl->get_UserSid(This,userSid)
#define IFsrmFileScreenTemplateImported_get_UserAccount(This,userAccount) (This)->lpVtbl->get_UserAccount(This,userAccount)
#define IFsrmFileScreenTemplateImported_CreateAction(This,actionType,action) (This)->lpVtbl->CreateAction(This,actionType,action)
#define IFsrmFileScreenTemplateImported_EnumActions(This,actions) (This)->lpVtbl->EnumActions(This,actions)
#define IFsrmFileScreenTemplateImported_get_Name(This,name) (This)->lpVtbl->get_Name(This,name)
#define IFsrmFileScreenTemplateImported_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmFileScreenTemplateImported_CopyTemplate(This,fileScreenTemplateName) (This)->lpVtbl->CopyTemplate(This,fileScreenTemplateName)
#define IFsrmFileScreenTemplateImported_CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult) (This)->lpVtbl->CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult)
#define IFsrmFileScreenTemplateImported_get_OverwriteOnCommit(This,overwrite) (This)->lpVtbl->get_OverwriteOnCommit(This,overwrite)
#define IFsrmFileScreenTemplateImported_put_OverwriteOnCommit(This,overwrite) (This)->lpVtbl->put_OverwriteOnCommit(This,overwrite)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmFileScreenTemplateManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileScreenTemplateManager,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmFileScreenTemplateManager methods */
    STDMETHOD_(HRESULT,CreateTemplate)(THIS_ IFsrmFileScreenTemplate **fileScreenTemplate) PURE;
    STDMETHOD_(HRESULT,GetTemplate)(THIS_ BSTR name,IFsrmFileScreenTemplate **fileScreenTemplate) PURE;
    STDMETHOD_(HRESULT,EnumTemplates)(THIS_ FsrmEnumOptions options,IFsrmCommittableCollection **fileScreenTemplates) PURE;
    STDMETHOD_(HRESULT,ExportTemplates)(THIS_ VARIANT *fileScreenTemplateNamesArray,BSTR *serializedFileScreenTemplates) PURE;
    STDMETHOD_(HRESULT,ImportTemplates)(THIS_ BSTR serializedFileScreenTemplates,VARIANT *fileScreenTemplateNamesArray,IFsrmCommittableCollection **fileScreenTemplates) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileScreenTemplateManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileScreenTemplateManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileScreenTemplateManager_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileScreenTemplateImported_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileScreenTemplateImported_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileScreenTemplateImported_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileScreenTemplateImported_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileScreenTemplateManager_CreateTemplate(This,fileScreenTemplate) (This)->lpVtbl->CreateTemplate(This,fileScreenTemplate)
#define IFsrmFileScreenTemplateManager_GetTemplate(This,name,fileScreenTemplate) (This)->lpVtbl->GetTemplate(This,name,fileScreenTemplate)
#define IFsrmFileScreenTemplateManager_EnumTemplates(This,options,fileScreenTemplates) (This)->lpVtbl->EnumTemplates(This,options,fileScreenTemplates)
#define IFsrmFileScreenTemplateManager_ExportTemplates(This,fileScreenTemplateNamesArray,serializedFileScreenTemplates) (This)->lpVtbl->ExportTemplates(This,fileScreenTemplateNamesArray,serializedFileScreenTemplates)
#define IFsrmFileScreenTemplateManager_ImportTemplates(This,serializedFileScreenTemplates,fileScreenTemplateNamesArray,fileScreenTemplates) (This)->lpVtbl->ImportTemplates(This,serializedFileScreenTemplates,fileScreenTemplateNamesArray,fileScreenTemplates)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmFileScreen
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileScreen,IFsrmFileScreenBase)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmFileScreenBase methods */
    STDMETHOD_(HRESULT,get_BlockedFileGroups)(THIS_ IFsrmMutableCollection **blockList) PURE;
    STDMETHOD_(HRESULT,put_BlockedFileGroups)(THIS_ IFsrmMutableCollection *blockList) PURE;
    STDMETHOD_(HRESULT,get_FileScreenFlags)(THIS_ long *fileScreenFlags) PURE;
    STDMETHOD_(HRESULT,put_FileScreenFlags)(THIS_ long fileScreenFlags) PURE;
    STDMETHOD_(HRESULT,get_UserSid)(THIS_ BSTR *userSid) PURE;
    STDMETHOD_(HRESULT,get_UserAccount)(THIS_ BSTR *userAccount) PURE;
    STDMETHOD_(HRESULT,CreateAction)(THIS_ FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumActions)(THIS_ IFsrmCollection **actions) PURE;

    /* IFsrmFileScreen methods */
    STDMETHOD_(HRESULT,get_Path)(THIS_ BSTR *path) PURE;
    STDMETHOD_(HRESULT,get_SourceTemplateName)(THIS_ BSTR *fileScreenTemplateName) PURE;
    STDMETHOD_(HRESULT,get_MatchesSourceTemplate)(THIS_ VARIANT_BOOL *matches) PURE;
    STDMETHOD_(HRESULT,ApplyTemplate)(THIS_ BSTR fileScreenTemplateName) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileScreen_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileScreen_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileScreen_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileScreen_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileScreen_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileScreen_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileScreen_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileScreen_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmFileScreen_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmFileScreen_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmFileScreen_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmFileScreen_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmFileScreen_get_BlockedFileGroups(This,blockList) (This)->lpVtbl->get_BlockedFileGroups(This,blockList)
#define IFsrmFileScreen_put_BlockedFileGroups(This,blockList) (This)->lpVtbl->put_BlockedFileGroups(This,blockList)
#define IFsrmFileScreen_get_FileScreenFlags(This,fileScreenFlags) (This)->lpVtbl->get_FileScreenFlags(This,fileScreenFlags)
#define IFsrmFileScreen_put_FileScreenFlags(This,fileScreenFlags) (This)->lpVtbl->put_FileScreenFlags(This,fileScreenFlags)
#define IFsrmFileScreen_get_UserSid(This,userSid) (This)->lpVtbl->get_UserSid(This,userSid)
#define IFsrmFileScreen_get_UserAccount(This,userAccount) (This)->lpVtbl->get_UserAccount(This,userAccount)
#define IFsrmFileScreen_CreateAction(This,actionType,action) (This)->lpVtbl->CreateAction(This,actionType,action)
#define IFsrmFileScreen_EnumActions(This,actions) (This)->lpVtbl->EnumActions(This,actions)
#define IFsrmFileScreen_get_Path(This,path) (This)->lpVtbl->get_Path(This,path)
#define IFsrmFileScreen_get_SourceTemplateName(This,fileScreenTemplateName) (This)->lpVtbl->get_SourceTemplateName(This,fileScreenTemplateName)
#define IFsrmFileScreen_get_MatchesSourceTemplate(This,matches) (This)->lpVtbl->get_MatchesSourceTemplate(This,matches)
#define IFsrmFileScreen_ApplyTemplate(This,fileScreenTemplateName) (This)->lpVtbl->ApplyTemplate(This,fileScreenTemplateName)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0600)*/
#include <fsrmreports.h>
#endif /*_INC_FSRMSCREEN*/
