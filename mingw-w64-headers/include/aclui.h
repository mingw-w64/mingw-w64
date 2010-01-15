/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _ACLUI_H_
#define _ACLUI_H_

#include <objbase.h>
#include <commctrl.h>
#include <accctrl.h>

#ifndef _ACLUI_
#define ACLUIAPI DECLSPEC_IMPORT WINAPI
#else
#define ACLUIAPI WINAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct _SI_OBJECT_INFO {
    DWORD dwFlags;
    HINSTANCE hInstance;
    LPWSTR pszServerName;
    LPWSTR pszObjectName;
    LPWSTR pszPageTitle;
    GUID guidObjectType;
  } SI_OBJECT_INFO,*PSI_OBJECT_INFO;

#define SI_EDIT_PERMS 0x00000000L
#define SI_EDIT_OWNER 0x00000001L
#define SI_EDIT_AUDITS 0x00000002L
#define SI_CONTAINER 0x00000004L
#define SI_READONLY 0x00000008L
#define SI_ADVANCED 0x00000010L
#define SI_RESET 0x00000020L
#define SI_OWNER_READONLY 0x00000040L
#define SI_EDIT_PROPERTIES 0x00000080L
#define SI_OWNER_RECURSE 0x00000100L
#define SI_NO_ACL_PROTECT 0x00000200L
#define SI_NO_TREE_APPLY 0x00000400L
#define SI_PAGE_TITLE 0x00000800L
#define SI_SERVER_IS_DC 0x00001000L
#define SI_RESET_DACL_TREE 0x00004000L
#define SI_RESET_SACL_TREE 0x00008000L
#define SI_OBJECT_GUID 0x00010000L
#define SI_EDIT_EFFECTIVE 0x00020000L
#define SI_RESET_DACL 0x00040000L
#define SI_RESET_SACL 0x00080000L
#define SI_RESET_OWNER 0x00100000L
#define SI_NO_ADDITIONAL_PERMISSION 0x00200000L
#define SI_MAY_WRITE 0x10000000L

#define SI_EDIT_ALL (SI_EDIT_PERMS | SI_EDIT_OWNER | SI_EDIT_AUDITS)

  typedef struct _SI_ACCESS {
    const GUID *pguid;
    ACCESS_MASK mask;
    LPCWSTR pszName;
    DWORD dwFlags;
  } SI_ACCESS,*PSI_ACCESS;

#define SI_ACCESS_SPECIFIC 0x00010000L
#define SI_ACCESS_GENERAL 0x00020000L
#define SI_ACCESS_CONTAINER 0x00040000L
#define SI_ACCESS_PROPERTY 0x00080000L

  typedef struct _SI_INHERIT_TYPE {
    const GUID *pguid;
    ULONG dwFlags;
    LPCWSTR pszName;
  } SI_INHERIT_TYPE,*PSI_INHERIT_TYPE;

  typedef enum _SI_PAGE_TYPE {
    SI_PAGE_PERM=0,SI_PAGE_ADVPERM,SI_PAGE_AUDIT,SI_PAGE_OWNER,SI_PAGE_EFFECTIVE,
  } SI_PAGE_TYPE;

#define PSPCB_SI_INITDIALOG (WM_USER+1)
#undef INTERFACE
#define INTERFACE ISecurityInformation
  DECLARE_INTERFACE_(ISecurityInformation,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetObjectInformation) (THIS_ PSI_OBJECT_INFO pObjectInfo) PURE;
    STDMETHOD(GetSecurity) (THIS_ SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR *ppSecurityDescriptor,WINBOOL fDefault) PURE;
    STDMETHOD(SetSecurity) (THIS_ SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor) PURE;
    STDMETHOD(GetAccessRights) (THIS_ const GUID *pguidObjectType,DWORD dwFlags,PSI_ACCESS *ppAccess,ULONG *pcAccesses,ULONG *piDefaultAccess) PURE;
    STDMETHOD(MapGeneric) (THIS_ const GUID *pguidObjectType,UCHAR *pAceFlags,ACCESS_MASK *pMask) PURE;
    STDMETHOD(GetInheritTypes) (THIS_ PSI_INHERIT_TYPE *ppInheritTypes,ULONG *pcInheritTypes) PURE;
    STDMETHOD(PropertySheetPageCallback)(THIS_ HWND hwnd,UINT uMsg,SI_PAGE_TYPE uPage) PURE;
  };
  typedef ISecurityInformation *LPSECURITYINFO;

#undef INTERFACE
#define INTERFACE ISecurityInformation2
  DECLARE_INTERFACE_(ISecurityInformation2,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD_(WINBOOL,IsDaclCanonical) (THIS_ PACL pDacl) PURE;
    STDMETHOD(LookupSids) (THIS_ ULONG cSids,PSID *rgpSids,LPDATAOBJECT *ppdo) PURE;
  };
  typedef ISecurityInformation2 *LPSECURITYINFO2;

#define CFSTR_ACLUI_SID_INFO_LIST TEXT("CFSTR_ACLUI_SID_INFO_LIST")

  typedef struct _SID_INFO {
    PSID pSid;
    PWSTR pwzCommonName;
    PWSTR pwzClass;
    PWSTR pwzUPN;
  } SID_INFO,*PSID_INFO;

  typedef struct _SID_INFO_LIST {
    ULONG cItems;
    SID_INFO aSidInfo[ANYSIZE_ARRAY];
  } SID_INFO_LIST,*PSID_INFO_LIST;

#undef INTERFACE
#define INTERFACE IEffectivePermission
  DECLARE_INTERFACE_(IEffectivePermission,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetEffectivePermission) (THIS_ const GUID *pguidObjectType,PSID pUserSid,LPCWSTR pszServerName,PSECURITY_DESCRIPTOR pSD,POBJECT_TYPE_LIST *ppObjectTypeList,ULONG *pcObjectTypeListLength,PACCESS_MASK *ppGrantedAccessList,ULONG *pcGrantedAccessListLength) PURE;
  };
  typedef IEffectivePermission *LPEFFECTIVEPERMISSION;

#undef INTERFACE
#define INTERFACE ISecurityObjectTypeInfo
  DECLARE_INTERFACE_(ISecurityObjectTypeInfo,IUnknown) {
    STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *ppvObj) PURE;
    STDMETHOD_(ULONG,AddRef) (THIS) PURE;
    STDMETHOD_(ULONG,Release) (THIS) PURE;
    STDMETHOD(GetInheritSource)(SECURITY_INFORMATION si,PACL pACL,PINHERITED_FROM *ppInheritArray) PURE;
  };
  typedef ISecurityObjectTypeInfo *LPSecurityObjectTypeInfo;

  EXTERN_GUID(IID_ISecurityInformation,0x965fc360,0x16ff,0x11d0,0x91,0xcb,0x0,0xaa,0x0,0xbb,0xb7,0x23);
  EXTERN_GUID(IID_ISecurityInformation2,0xc3ccfdb4,0x6f88,0x11d2,0xa3,0xce,0x0,0xc0,0x4f,0xb1,0x78,0x2a);
  EXTERN_GUID(IID_IEffectivePermission,0x3853dc76,0x9f35,0x407c,0x88,0xa1,0xd1,0x93,0x44,0x36,0x5f,0xbc);
  EXTERN_GUID(IID_ISecurityObjectTypeInfo,0xfc3066eb,0x79ef,0x444b,0x91,0x11,0xd1,0x8a,0x75,0xeb,0xf2,0xfa);

  HPROPSHEETPAGE ACLUIAPI CreateSecurityPage(LPSECURITYINFO psi);
  WINBOOL ACLUIAPI EditSecurity(HWND hwndOwner,LPSECURITYINFO psi);

#ifdef __cplusplus
}
#endif
#endif
