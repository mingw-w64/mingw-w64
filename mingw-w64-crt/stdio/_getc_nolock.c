#include <stdio.h>

#undef _getc_nolock
int __cdecl _getc_nolock(FILE *stream);
int __cdecl _getc_nolock(FILE *stream)
{
    return _fgetc_nolock(stream);
}
int __cdecl (*__MINGW_IMP_SYMBOL(_getc_nolock))(FILE *) = _getc_nolock;
