/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifdef __arm64ec__

/*
 * Calls to this are synthesized by the linker when calling into import libraries,
 * this is referred to as an 'Adjustor Thunk' in ARM64EC documentation.
*/
        .text
        .balign 16
        .globl __icall_helper_arm64ec
__icall_helper_arm64ec:
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

#endif
