#include <stdio.h>

#undef _putc_nolock
int __cdecl _putc_nolock(int c, FILE *stream);
int __cdecl _putc_nolock(int c, FILE *stream)
{
    return _fputc_nolock(c, stream);
}
int __cdecl (*__MINGW_IMP_SYMBOL(_putc_nolock))(int, FILE *) = _putc_nolock;
