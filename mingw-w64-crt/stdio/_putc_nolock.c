#include <stdio.h>

int __cdecl _putc_nolock(int c, FILE *stream)
{
    return --stream->_cnt >= 0 ? 0xff & (*stream->_ptr++ = (char)c) : _flsbuf(c, stream);
}
int __cdecl (*__MINGW_IMP_SYMBOL(_putc_nolock))(int, FILE *) = _putc_nolock;
