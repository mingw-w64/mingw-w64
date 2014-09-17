/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

#define FCT __MINGW_USYMBOL(vwscanf)
#define FWD __MINGW_USYMBOL(__ms_vwscanf)

	.file   "vwscanf2.S"
	.text
        .p2align 4,,15
        .globl  FCT
        .def    FCT;    .scl    2;      .type   32;     .endef
#ifdef _WIN64
        .seh_proc       FCT
#endif
FCT:
#ifdef _WIN64
        .seh_endprologue
#endif
#if defined(_AMD64_) || defined(__x86_64__) || defined(_X86_) || defined(__i386__)
        jmp     FWD
#elif defined(_ARM_) || defined(__arm__)
        b       FWD
#endif
#ifdef _WIN64
        .seh_endproc
#endif
	.def    FWD;  .scl    2;      .type   32;     .endef
