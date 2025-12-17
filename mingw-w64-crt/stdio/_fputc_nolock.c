#include <stdio.h>

int __cdecl _fputc_nolock(int c, FILE *stream)
{
    return _putc_nolock(c, stream);
}
int __cdecl (*__MINGW_IMP_SYMBOL(_fputc_nolock))(int, FILE *) = _fputc_nolock;
