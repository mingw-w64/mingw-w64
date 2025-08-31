/*
    Copyright © 2005-2020 Rich Felker, et al.

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the
    "Software"), to deal in the Software without restriction, including
    without limitation the rights to use, copy, modify, merge, publish,
    distribute, sublicense, and/or sell copies of the Software, and to
    permit persons to whom the Software is furnished to do so, subject to
    the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <wchar.h>

wchar_t *__cdecl wcstok(wchar_t *restrict s, const wchar_t *restrict sep, wchar_t **restrict p)
{
  if (!s && !(s = *p)) return NULL;
  s += wcsspn(s, sep);
  if (!*s) return *p = s, NULL;
  *p = s + wcscspn(s, sep);
  if (**p) *(*p)++ = 0;
  return s;
}
wchar_t *(__cdecl *__MINGW_IMP_SYMBOL(wcstok))(wchar_t *restrict, const wchar_t *restrict, wchar_t **restrict) = wcstok;
