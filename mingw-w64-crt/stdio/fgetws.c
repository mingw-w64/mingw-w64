/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>
#include <errno.h>

wchar_t *__cdecl fgetws(wchar_t * __restrict__ _Dst, int _SizeInWords, FILE * __restrict__ _File)
{
    wchar_t format[19];
    int count;
    int ret;

    if (_Dst == NULL || _SizeInWords <= 0)
    {
        errno = EINVAL;
        return NULL;
    }

    if (_SizeInWords == 1)
    {
        _Dst[0] = L'\0';
        return _Dst;
    }

    /* _SizeInWords-1 must be positive as it is maximum width for %l[ format */
    if (_swprintf(format, L"%%%dl[^\n]%%n", _SizeInWords-1) < 0)
    {
        return NULL;
    }

    ret = __ms_fwscanf(_File, format, _Dst, &count);

    /* fwscanf() returns zero if the format "%l[^\n]" does not match any character
     * which means that the first character in _File has to be new line */
    if (ret == 0)
    {
        _Dst[0] = L'\0';
        count = 0;
        ret = 2;
    }

    if (ret < 2)
    {
        return NULL;
    }

    if (count < _SizeInWords-1)
    {
        if (__ms_fwscanf(_File, L"%1l[\n]", &_Dst[count]) == 1)
        {
            count++;
        }
    }

    return _Dst;
}
