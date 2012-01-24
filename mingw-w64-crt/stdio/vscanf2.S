/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

#define FCT __MINGW_USYMBOL(vscanf)
#define FWD __MINGW_USYMBOL(__ms_vscanf)

	.file   "vscanf2.S"
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
        jmp     FWD
#ifdef _WIN64
        .seh_endproc
#endif
	.def    FWD;  .scl    2;      .type   32;     .endef
