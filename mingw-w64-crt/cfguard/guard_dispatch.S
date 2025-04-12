/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* When CFGuard is not active, directly tail-call the target address, which
 * is passed via %rax. */
        .text
        .align 16
        .def __guard_dispatch_icall_dummy;    .scl    2;    .type    32;    .endef
__guard_dispatch_icall_dummy:
        jmp *%rax
