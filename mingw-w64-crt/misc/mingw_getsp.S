/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
	.file	"ceill.S"
	.code64
	.text
	.align 4
.globl _mingw_getsp
	.def	mingw_getsp;	.scl	2;	.type	32;	.endef
mingw_getsp:
#ifdef _WIN64
    leaq  8(%rsp),%rax
#else
	lea	4(%esp),%eax
#endif
	ret
