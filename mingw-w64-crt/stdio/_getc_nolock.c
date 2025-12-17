#include <stdio.h>

int __cdecl _getc_nolock(FILE *stream)
{
    return --stream->_cnt >= 0 ? 0xff & *stream->_ptr++ : _filbuf(stream);
}
int __cdecl (*__MINGW_IMP_SYMBOL(_getc_nolock))(FILE *) = _getc_nolock;
