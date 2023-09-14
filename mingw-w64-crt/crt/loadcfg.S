/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/*
This assembly source file defines the `_load_config_used` structure, which is
purely data. The main purpose is to include the metadata necessary for enabling
Control Flow Guard (CFGuard) and ARM64EC.

Many of the symbols referenced here are supplied by the linker. This file has
been constructed with LLVM/LLD in mind.
*/

#if defined(__x86_64__) || defined(__aarch64__)
#  define PTR .quad
#  define ALIGN 8
#elif defined(__i386__) || defined(__arm__)
#  define PTR .long
#  define ALIGN 4
#else
#  error "Load config structure is unimplemented for the current architecture."
#endif

#if defined(__x86_64__)
/*
GuardCFCheckDispatch is only used on x86_64. For other platforms it should be 0.
Ref: https://docs.microsoft.com/en-us/windows/win32/secbp/pe-metadata
*/
#  define CFGUARD_USE_DISPATCH
#endif

#if defined(__i386__)
#  define SYM(x) _##x
#else
#  define SYM(x) x
#endif

#ifdef HAS_CFGUARD
#  define CFGSYM(x) SYM(x)
#else
#  define CFGSYM(x) 0
#endif

#if defined(INCLUDE_MSVC_FEATURES)
/*
These features are specific to MSVC as far as I am aware.
*/
#  define HAS_GS_SECURITY_COOKIE
#  if defined(__i386__)
#    define HAS_SAFE_SE_HANDLER
#  endif
#  define HAS_ENCLAVE_CONFIG
#endif

	.section	.rdata,"dr"
	.globl	SYM(_load_config_used)
	.balign ALIGN
SYM(_load_config_used):
	.long	SYM(_load_config_used__end) - SYM(_load_config_used) /* Size */
	.long	0 /* TimeDateStamp */
	.short	0 /* MajorVersion */
	.short	0 /* MinorVersion */
	.long	0 /* GLobalFlagsClear */
	.long	0 /* GlobalFlagsSet */
	.long	0 /* CriticalSectionDefaultTimeout */
	PTR	0 /* DeCommitFreeBlockThreshold */
	PTR	0 /* DeCommitTotalFreeThreshold */
	PTR	0 /* LockPrefixTable */
	PTR	0 /* MaximumAllocationSize */
	PTR	0 /* VirtualMemoryThreshold */
	PTR	0 /* ProcessAffinityMask */
	.long	0 /* ProcessHeapFlags */
	.short	0 /* CSDVersion */
	.short	0 /* DependentLoadFlags */
	PTR	0 /* EditList */
#if defined(HAS_GS_SECURITY_COOKIE)
	PTR	SYM(__security_cookie) /* SecurityCookie */
#else
	PTR	0 /* SecurityCookie */
#endif
#if defined(HAS_SAFE_SE_HANDLER)
	PTR	SYM(__safe_se_handler_table) /* SEHandlerTable */
	PTR	SYM(__safe_se_handler_count) /* SEHandlerCount */
#else
	PTR	0 /* SEHandlerTable */
	PTR	0 /* SEHandlerCount */
#endif
	PTR	CFGSYM(__guard_check_icall_fptr) /* GuardCFCheckFunction */
#if defined(CFGUARD_USE_DISPATCH)
	PTR	CFGSYM(__guard_dispatch_icall_fptr) /* GuardCFCheckDispatch */
#else
	PTR	0 /* GuardCFCheckDispatch */
#endif
	PTR	CFGSYM(__guard_fids_table) /* GuardCFFunctionTable */
	PTR	CFGSYM(__guard_fids_count) /* GuardCFFunctionCount */
	.long	CFGSYM(__guard_flags) /* GuardFlags */
	.short	0 /* CodeIntegrity_Flags */
	.short	0 /* CodeIntegrity_Catalog */
	.long	0 /* CodeIntegrity_CatalogOffset */
	.long	0 /* CodeIntegrity_Reserved */
	PTR	CFGSYM(__guard_iat_table) /* GuardAddressTakenIatEntryTable */
	PTR	CFGSYM(__guard_iat_count) /* GuardAddressTakenIatEntryCount */
	PTR	CFGSYM(__guard_longjmp_table) /* GuardLongJumpTargetTable */
	PTR	CFGSYM(__guard_longjmp_count) /* GuardLongJumpTargetCount */
	PTR	0 /* DynamicValueRelocTable */
#if defined(__arm64ec__)
	PTR	SYM(__chpe_metadata) /* CHPEMetadataPointer */
#else
	PTR	0 /* CHPEMetadataPointer */
#endif
	PTR	0 /* GuardRFFailureRoutine */
	PTR	0 /* GuardRFFailureRoutineFunctionPointer */
	.long	0 /* DynamicValueRelocTableOffset */
	.short	0 /* DynamicValueRelocTableSection */
	.short	0 /* Reserved2 */
	PTR	0 /* GuardRFVerifyStackPointerFunctionPointer */
	.long	0 /* HotPatchTableOffset */
	.long	0 /* Reserved3 */
#if defined(HAS_ENCLAVE_CONFIG)
	PTR	SYM(__enclave_config) /* EnclaveConfigurationPointer */
#else
	PTR	0 /* EnclaveConfigurationPointer */
#endif
	PTR	0 /* VolatileMetadataPointer */
	PTR	CFGSYM(__guard_eh_cont_table) /* GuardEHContinuationTable */
	PTR	CFGSYM(__guard_eh_cont_count) /* GuardEHContinuationCount */
	PTR	0 /* GuardXFGCheckFunctionPointer */
	PTR	0 /* GuardXFGDispatchFunctionPointer */
	PTR	0 /* GuardXFGTableDispatchFunctionPointer */
	PTR	0 /* CastGuardOsDeterminedFailureMode */

SYM(_load_config_used__end):
