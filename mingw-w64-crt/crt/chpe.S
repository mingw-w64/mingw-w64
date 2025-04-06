/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define EXPORT_SYM(x) .globl x; x:

/*
 * These symbols are updated at runtime by the dynamic linker to point to emulator
 * helper routines.
 */
	.section .00cfg, "dr"
	.balign 16
EXPORT_SYM(__os_arm64x_dispatch_call_no_redirect)
	.quad 0
EXPORT_SYM(__os_arm64x_dispatch_ret)
	.quad 0
EXPORT_SYM(__os_arm64x_check_icall)
EXPORT_SYM(__os_arm64x_dispatch_icall)
	.quad 0
EXPORT_SYM(__os_arm64x_check_call)
EXPORT_SYM(__os_arm64x_dispatch_call)
	.quad 0
EXPORT_SYM(__os_arm64x_check_icall_cfg)
EXPORT_SYM(__os_arm64x_check_dispatch_cfg)
	.quad 0
EXPORT_SYM(__os_arm64x_rdtsc)
EXPORT_SYM(__os_arm64x_get_x64_information)
	.quad 0
EXPORT_SYM(__os_arm64x_set_x64_information)
EXPORT_SYM(__os_arm64x_cpuidex)
	.quad 0
EXPORT_SYM(__os_arm64x_x64_jump)
EXPORT_SYM(__os_arm64x_dispatch_fptr)
	.quad 0
EXPORT_SYM(__os_arm64x_helper3)
	.quad 0
EXPORT_SYM(__os_arm64x_helper4)
	.quad 0
EXPORT_SYM(__os_arm64x_helper5)
	.quad 0
EXPORT_SYM(__os_arm64x_helper6)
	.quad 0
EXPORT_SYM(__os_arm64x_helper7)
	.quad 0
EXPORT_SYM(__os_arm64x_helper8)
	.quad 0

/*
 * This structure is read at runtime by the dynamic linker on ARM64EC to configure
 * metadata necessary for EC code to interface with x86_64 code.
 */
	.section	.rdata,"dr"
	.balign 16
EXPORT_SYM(__chpe_metadata)
	.long 1 /* Version */
	.rva  __hybrid_code_map /* CodeMap */
	.long __hybrid_code_map_count /* CodeMapCount */
	.rva  __x64_code_ranges_to_entry_points /* CodeRangesToEntryPoints */
	.rva __arm64x_redirection_metadata /* RedirectionMetadata */
	.rva  __os_arm64x_dispatch_call_no_redirect /* __os_arm64x_dispatch_call_no_redirect */
	.rva  __os_arm64x_dispatch_ret /* __os_arm64x_dispatch_ret */
	.rva  __os_arm64x_check_call /* __os_arm64x_dispatch_call */
	.rva  __os_arm64x_check_icall /* __os_arm64x_dispatch_icall */
	.rva  __os_arm64x_check_icall_cfg /* __os_arm64x_dispatch_icall_cfg */
	.rva  __arm64x_native_entrypoint /* AlternateEntryPoint */
	.rva  __hybrid_auxiliary_iat /* AuxiliaryIAT */
	.long __x64_code_ranges_to_entry_points_count /* CodeRangesToEntryPointsCount */
	.long __arm64x_redirection_metadata_count /* RedirectionMetadataCount */
	.rva  __os_arm64x_get_x64_information /* GetX64InformationFunctionPointer */
	.rva  __os_arm64x_set_x64_information /* SetX64InformationFunctionPointer */
	.rva  __arm64x_extra_rfe_table /* ExtraRFETable */
	.long __arm64x_extra_rfe_table_size /* ExtraRFETableSize */
	.rva  __os_arm64x_x64_jump /* __os_arm64x_dispatch_fptr */
	.rva  __hybrid_auxiliary_iat_copy /* AuxiliaryIATCopy */
	.rva  __hybrid_auxiliary_delayload_iat
	.rva  __hybrid_auxiliary_delayload_iat_copy
	.long __hybrid_image_info_bitfield
	.rva  __os_arm64x_helper3
	.rva  __os_arm64x_helper4
	.rva  __os_arm64x_helper5
	.rva  __os_arm64x_helper6
	.rva  __os_arm64x_helper7
	.rva  __os_arm64x_helper8

/*
 * Calls to this are synthesized by the linker when calling into import libraries,
 * this is referred to as an 'Adjustor Thunk' in ARM64EC documentation.
*/
        .text
        .balign 16
EXPORT_SYM(__icall_helper_arm64ec)
	.seh_proc "__icall_helper_arm64ec"
	 stp	fp, lr, [sp, #-16]!
	.seh_save_fplr_x 16
	mov	fp, sp
	.seh_set_fp
	.seh_endprologue
	adrp	x16, __os_arm64x_check_icall
	ldr	x16, [x16, #:lo12:__os_arm64x_check_icall]
	blr	x16
	.seh_startepilogue
	ldp	fp, lr, [sp], #16
	.seh_save_fplr_x 16
	.seh_endepilogue
	br	x11
	.seh_endproc
