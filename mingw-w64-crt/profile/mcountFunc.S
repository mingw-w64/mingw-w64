/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <_mingw_mac.h>

	.file "mountFunc.S"
	.text
#ifdef _WIN64
	.align 8
#else
	.align 4
#endif
.globl __MINGW_USYMBOL(mcount)
        .def    __MINGW_USYMBOL(mcount);  .scl    2;      .type   32;     .endef
__MINGW_USYMBOL(mcount):
#ifndef _WIN64
	push %ebp
	mov %esp, %ebp
	push %eax
	push %ecx
	push %edx
	movl 4(%ebp),%ecx
	movl (%ebp),%eax
	movl 4(%eax),%eax
	push %ecx
	push %eax
	call __MINGW_USYMBOL(_mcount)
	add $8, %esp
	pop %edx
	pop %ecx
	pop %eax
	leave
	ret
#else
        push %rbp
        mov %rsp, %rbp
        push %rax
        push %rcx
        push %rdx
	push %r8
	push %r9
	push %r10
	push %r11
        movq 8(%rbp),%rdx
        movq (%rbp),%rax
        movq 8(%rax),%rcx
	sub $40, %rsp
        call __MINGW_USYMBOL(_mcount)
	add $40, %rsp
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rdx
        pop %rcx
        pop %rax
        leave
        ret
#endif

