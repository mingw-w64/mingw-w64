/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __ACCESS_CONTROL_API__
#define __ACCESS_CONTROL_API__

#include <windows.h>
#include <accctrl.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef VOID (*FN_PROGRESS)(LPWSTR pObjectName,DWORD Status,PPROG_INVOKE_SETTING pInvokeSetting,PVOID Args,WINBOOL SecuritySet);

#ifdef UNICODE
#define SetEntriesInAcl SetEntriesInAclW
#define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclW
#define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclW
#define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclW
#define GetNamedSecurityInfo GetNamedSecurityInfoW
#define SetNamedSecurityInfo SetNamedSecurityInfoW
#define GetInheritanceSource GetInheritanceSourceW
#define TreeResetNamedSecurityInfo TreeResetNamedSecurityInfoW
#define BuildSecurityDescriptor BuildSecurityDescriptorW
#define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsW
#define BuildExplicitAccessWithName BuildExplicitAccessWithNameW
#define BuildImpersonateExplicitAccessWithName BuildImpersonateExplicitAccessWithNameW
#define BuildTrusteeWithName BuildTrusteeWithNameW
#define BuildImpersonateTrustee BuildImpersonateTrusteeW
#define BuildTrusteeWithSid BuildTrusteeWithSidW
#define BuildTrusteeWithObjectsAndSid BuildTrusteeWithObjectsAndSidW
#define BuildTrusteeWithObjectsAndName BuildTrusteeWithObjectsAndNameW
#define GetTrusteeName GetTrusteeNameW
#define GetTrusteeType GetTrusteeTypeW
#define GetTrusteeForm GetTrusteeFormW
#define GetMultipleTrusteeOperation GetMultipleTrusteeOperationW
#define GetMultipleTrustee GetMultipleTrusteeW
#else
#define SetEntriesInAcl SetEntriesInAclA
#define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclA
#define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclA
#define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclA
#define GetNamedSecurityInfo GetNamedSecurityInfoA
#define SetNamedSecurityInfo SetNamedSecurityInfoA
#define GetInheritanceSource GetInheritanceSourceA
#define TreeResetNamedSecurityInfo TreeResetNamedSecurityInfoA
#define BuildSecurityDescriptor BuildSecurityDescriptorA
#define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsA
#define BuildExplicitAccessWithName BuildExplicitAccessWithNameA
#define BuildImpersonateExplicitAccessWithName BuildImpersonateExplicitAccessWithNameA
#define BuildTrusteeWithName BuildTrusteeWithNameA
#define BuildImpersonateTrustee BuildImpersonateTrusteeA
#define BuildTrusteeWithSid BuildTrusteeWithSidA
#define BuildTrusteeWithObjectsAndSid BuildTrusteeWithObjectsAndSidA
#define BuildTrusteeWithObjectsAndName BuildTrusteeWithObjectsAndNameA
#define GetTrusteeName GetTrusteeNameA
#define GetTrusteeType GetTrusteeTypeA
#define GetTrusteeForm GetTrusteeFormA
#define GetMultipleTrusteeOperation GetMultipleTrusteeOperationA
#define GetMultipleTrustee GetMultipleTrusteeA
#endif

  WINADVAPI DWORD WINAPI SetEntriesInAclA(ULONG cCountOfExplicitEntries,PEXPLICIT_ACCESS_A pListOfExplicitEntries,PACL OldAcl,PACL *NewAcl);
  WINADVAPI DWORD WINAPI SetEntriesInAclW(ULONG cCountOfExplicitEntries,PEXPLICIT_ACCESS_W pListOfExplicitEntries,PACL OldAcl,PACL *NewAcl);
  WINADVAPI DWORD WINAPI GetExplicitEntriesFromAclA(PACL pacl,PULONG pcCountOfExplicitEntries,PEXPLICIT_ACCESS_A *pListOfExplicitEntries);
  WINADVAPI DWORD WINAPI GetExplicitEntriesFromAclW(PACL pacl,PULONG pcCountOfExplicitEntries,PEXPLICIT_ACCESS_W *pListOfExplicitEntries);
  WINADVAPI DWORD WINAPI GetEffectiveRightsFromAclA(PACL pacl,PTRUSTEE_A pTrustee,PACCESS_MASK pAccessRights);
  WINADVAPI DWORD WINAPI GetEffectiveRightsFromAclW(PACL pacl,PTRUSTEE_W pTrustee,PACCESS_MASK pAccessRights);
  WINADVAPI DWORD WINAPI GetAuditedPermissionsFromAclA(PACL pacl,PTRUSTEE_A pTrustee,PACCESS_MASK pSuccessfulAuditedRights,PACCESS_MASK pFailedAuditRights);
  WINADVAPI DWORD WINAPI GetAuditedPermissionsFromAclW(PACL pacl,PTRUSTEE_W pTrustee,PACCESS_MASK pSuccessfulAuditedRights,PACCESS_MASK pFailedAuditRights);
  WINADVAPI DWORD WINAPI GetNamedSecurityInfoA(LPSTR pObjectName,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,PSID *ppsidOwner,PSID *ppsidGroup,PACL *ppDacl,PACL *ppSacl,PSECURITY_DESCRIPTOR *ppSecurityDescriptor);
  WINADVAPI DWORD WINAPI GetNamedSecurityInfoW(LPWSTR pObjectName,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,PSID *ppsidOwner,PSID *ppsidGroup,PACL *ppDacl,PACL *ppSacl,PSECURITY_DESCRIPTOR *ppSecurityDescriptor);
  WINADVAPI DWORD WINAPI GetSecurityInfo(HANDLE handle,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,PSID *ppsidOwner,PSID *ppsidGroup,PACL *ppDacl,PACL *ppSacl,PSECURITY_DESCRIPTOR *ppSecurityDescriptor);
  WINADVAPI DWORD WINAPI SetNamedSecurityInfoA(LPSTR pObjectName,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,PSID psidOwner,PSID psidGroup,PACL pDacl,PACL pSacl);
  WINADVAPI DWORD WINAPI SetNamedSecurityInfoW(LPWSTR pObjectName,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,PSID psidOwner,PSID psidGroup,PACL pDacl,PACL pSacl);
  WINADVAPI DWORD WINAPI SetSecurityInfo(HANDLE handle,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,PSID psidOwner,PSID psidGroup,PACL pDacl,PACL pSacl);
  WINADVAPI DWORD WINAPI GetInheritanceSourceA(LPSTR pObjectName,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,WINBOOL Container,GUID **pObjectClassGuids,DWORD GuidCount,PACL pAcl,PFN_OBJECT_MGR_FUNCTS pfnArray,PGENERIC_MAPPING pGenericMapping,PINHERITED_FROMA pInheritArray);
  WINADVAPI DWORD WINAPI GetInheritanceSourceW(LPWSTR pObjectName,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,WINBOOL Container,GUID **pObjectClassGuids,DWORD GuidCount,PACL pAcl,PFN_OBJECT_MGR_FUNCTS pfnArray,PGENERIC_MAPPING pGenericMapping,PINHERITED_FROMW pInheritArray);
  WINADVAPI DWORD WINAPI FreeInheritedFromArray(PINHERITED_FROMW pInheritArray,USHORT AceCnt,PFN_OBJECT_MGR_FUNCTS pfnArray);
  WINADVAPI DWORD WINAPI TreeResetNamedSecurityInfoA(LPSTR pObjectName,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,PSID pOwner,PSID pGroup,PACL pDacl,PACL pSacl,WINBOOL KeepExplicit,FN_PROGRESS fnProgress,PROG_INVOKE_SETTING ProgressInvokeSetting,PVOID Args);
  WINADVAPI DWORD WINAPI TreeResetNamedSecurityInfoW(LPWSTR pObjectName,SE_OBJECT_TYPE ObjectType,SECURITY_INFORMATION SecurityInfo,PSID pOwner,PSID pGroup,PACL pDacl,PACL pSacl,WINBOOL KeepExplicit,FN_PROGRESS fnProgress,PROG_INVOKE_SETTING ProgressInvokeSetting,PVOID Args);
  WINADVAPI DWORD WINAPI BuildSecurityDescriptorA(PTRUSTEE_A pOwner,PTRUSTEE_A pGroup,ULONG cCountOfAccessEntries,PEXPLICIT_ACCESS_A pListOfAccessEntries,ULONG cCountOfAuditEntries,PEXPLICIT_ACCESS_A pListOfAuditEntries,PSECURITY_DESCRIPTOR pOldSD,PULONG pSizeNewSD,PSECURITY_DESCRIPTOR *pNewSD);
  WINADVAPI DWORD WINAPI BuildSecurityDescriptorW(PTRUSTEE_W pOwner,PTRUSTEE_W pGroup,ULONG cCountOfAccessEntries,PEXPLICIT_ACCESS_W pListOfAccessEntries,ULONG cCountOfAuditEntries,PEXPLICIT_ACCESS_W pListOfAuditEntries,PSECURITY_DESCRIPTOR pOldSD,PULONG pSizeNewSD,PSECURITY_DESCRIPTOR *pNewSD);
  WINADVAPI DWORD WINAPI LookupSecurityDescriptorPartsA(PTRUSTEE_A *ppOwner,PTRUSTEE_A *ppGroup,PULONG pcCountOfAccessEntries,PEXPLICIT_ACCESS_A *ppListOfAccessEntries,PULONG pcCountOfAuditEntries,PEXPLICIT_ACCESS_A *ppListOfAuditEntries,PSECURITY_DESCRIPTOR pSD);
  WINADVAPI DWORD WINAPI LookupSecurityDescriptorPartsW(PTRUSTEE_W *ppOwner,PTRUSTEE_W *ppGroup,PULONG pcCountOfAccessEntries,PEXPLICIT_ACCESS_W *ppListOfAccessEntries,PULONG pcCountOfAuditEntries,PEXPLICIT_ACCESS_W *ppListOfAuditEntries,PSECURITY_DESCRIPTOR pSD);
  WINADVAPI VOID WINAPI BuildExplicitAccessWithNameA(PEXPLICIT_ACCESS_A pExplicitAccess,LPSTR pTrusteeName,DWORD AccessPermissions,ACCESS_MODE AccessMode,DWORD Inheritance);
  WINADVAPI VOID WINAPI BuildExplicitAccessWithNameW(PEXPLICIT_ACCESS_W pExplicitAccess,LPWSTR pTrusteeName,DWORD AccessPermissions,ACCESS_MODE AccessMode,DWORD Inheritance);
  WINADVAPI VOID WINAPI BuildImpersonateExplicitAccessWithNameA(PEXPLICIT_ACCESS_A pExplicitAccess,LPSTR pTrusteeName,PTRUSTEE_A pTrustee,DWORD AccessPermissions,ACCESS_MODE AccessMode,DWORD Inheritance);
  WINADVAPI VOID WINAPI BuildImpersonateExplicitAccessWithNameW(PEXPLICIT_ACCESS_W pExplicitAccess,LPWSTR pTrusteeName,PTRUSTEE_W pTrustee,DWORD AccessPermissions,ACCESS_MODE AccessMode,DWORD Inheritance);
  WINADVAPI VOID WINAPI BuildTrusteeWithNameA(PTRUSTEE_A pTrustee,LPSTR pName);
  WINADVAPI VOID WINAPI BuildTrusteeWithNameW(PTRUSTEE_W pTrustee,LPWSTR pName);
  WINADVAPI VOID WINAPI BuildImpersonateTrusteeA(PTRUSTEE_A pTrustee,PTRUSTEE_A pImpersonateTrustee);
  WINADVAPI VOID WINAPI BuildImpersonateTrusteeW(PTRUSTEE_W pTrustee,PTRUSTEE_W pImpersonateTrustee);
  WINADVAPI VOID WINAPI BuildTrusteeWithSidA(PTRUSTEE_A pTrustee,PSID pSid);
  WINADVAPI VOID WINAPI BuildTrusteeWithSidW(PTRUSTEE_W pTrustee,PSID pSid);
  WINADVAPI VOID WINAPI BuildTrusteeWithObjectsAndSidA(PTRUSTEE_A pTrustee,POBJECTS_AND_SID pObjSid,GUID *pObjectGuid,GUID *pInheritedObjectGuid,PSID pSid);
  WINADVAPI VOID WINAPI BuildTrusteeWithObjectsAndSidW(PTRUSTEE_W pTrustee,POBJECTS_AND_SID pObjSid,GUID *pObjectGuid,GUID *pInheritedObjectGuid,PSID pSid);
  WINADVAPI VOID WINAPI BuildTrusteeWithObjectsAndNameA(PTRUSTEE_A pTrustee,POBJECTS_AND_NAME_A pObjName,SE_OBJECT_TYPE ObjectType,LPSTR ObjectTypeName,LPSTR InheritedObjectTypeName,LPSTR Name);
  WINADVAPI VOID WINAPI BuildTrusteeWithObjectsAndNameW(PTRUSTEE_W pTrustee,POBJECTS_AND_NAME_W pObjName,SE_OBJECT_TYPE ObjectType,LPWSTR ObjectTypeName,LPWSTR InheritedObjectTypeName,LPWSTR Name);
  WINADVAPI LPSTR WINAPI GetTrusteeNameA(PTRUSTEE_A pTrustee);
  WINADVAPI LPWSTR WINAPI GetTrusteeNameW(PTRUSTEE_W pTrustee);
  WINADVAPI TRUSTEE_TYPE WINAPI GetTrusteeTypeA(PTRUSTEE_A pTrustee);
  WINADVAPI TRUSTEE_TYPE WINAPI GetTrusteeTypeW(PTRUSTEE_W pTrustee);
  WINADVAPI TRUSTEE_FORM WINAPI GetTrusteeFormA(PTRUSTEE_A pTrustee);
  WINADVAPI TRUSTEE_FORM WINAPI GetTrusteeFormW(PTRUSTEE_W pTrustee);
  WINADVAPI MULTIPLE_TRUSTEE_OPERATION WINAPI GetMultipleTrusteeOperationA(PTRUSTEE_A pTrustee);
  WINADVAPI MULTIPLE_TRUSTEE_OPERATION WINAPI GetMultipleTrusteeOperationW(PTRUSTEE_W pTrustee);
  WINADVAPI PTRUSTEE_A WINAPI GetMultipleTrusteeA(PTRUSTEE_A pTrustee);
  WINADVAPI PTRUSTEE_W WINAPI GetMultipleTrusteeW(PTRUSTEE_W pTrustee);

#define AccProvInit(err)

#ifdef __cplusplus
}
#endif
#endif
