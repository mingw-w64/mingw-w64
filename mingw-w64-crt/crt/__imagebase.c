/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <_mingw_mac.h>

/* This file defines __ImageBase symbol for backward compatibility with older
 * linker versions which do not provide this symbol. It is used only when linker
 * does not provide this symbol (detected by ./configure). __ImageBase symbol is
 * defined as alias to _image_base__ symbol which is provided by older linker
 * versions. Note that gcc does not allow declaring global variable as alias to
 * external symbol, so do it via inline assembly which allows it. */
#define ASM_SYM(sym) __MINGW64_STRINGIFY(__MINGW_USYMBOL(sym))
asm (
".globl\t" ASM_SYM(__ImageBase) "\n\t"
".set\t"   ASM_SYM(__ImageBase) "," ASM_SYM(_image_base__)
);
