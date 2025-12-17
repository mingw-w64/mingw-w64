#include <stdio.h>

int __cdecl _fgetc_nolock(FILE *stream)
{
    return _getc_nolock(stream);
}
int __cdecl (*__MINGW_IMP_SYMBOL(_fgetc_nolock))(FILE *) = _fgetc_nolock;
