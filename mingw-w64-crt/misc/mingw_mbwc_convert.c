#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <errno.h>
#include <windows.h>
#include <winnls.h>

int __cdecl __mingw_str_wide_utf8(const wchar_t * const wptr, char **mbptr, size_t *buflen)
{
  int len;
  char *buf;
  int ret = 0;

  len = WideCharToMultiByte(CP_UTF8, 0, wptr, -1, NULL, 0, NULL, NULL); /* Get utf-8 string length */
  if (len <= 0) {
    switch (GetLastError()) {
      case ERROR_INVALID_PARAMETER: /* CP_UTF8 is not supported */
      case ERROR_INVALID_FLAGS: /* CP_UTF8 is not supported */
        errno = ENOSYS;
        *mbptr = NULL;
        if (buflen != NULL) *buflen = 0;
        return 0;
      case NO_ERROR:
        if (len == 0)
          break;
        /* fallthrough */
      default:
        errno = EINVAL;
        *mbptr = NULL;
        if (buflen != NULL) *buflen = 0;
        return 0;
    }
  }
  buf = calloc(len + 1, sizeof (char)); /* Can we assume sizeof char always = 1? */

  if(!buf) len = 0;
  else {
    if (len != 0) {
      ret = WideCharToMultiByte(CP_UTF8, 0, wptr, -1, buf, len, NULL, NULL); /*Do actual conversion*/
      if (ret < 0 || (ret == 0 && GetLastError() != NO_ERROR)) {
        free(buf);
        errno = EINVAL;
        *mbptr = NULL;
        if (buflen != NULL) *buflen = 0;
        return 0;
      }
    }
    buf[len] = '\0'; /* Must terminate */
  }
  *mbptr = buf; /* Set string pointer to allocated buffer */
  if(buflen != NULL) *buflen = (len) * sizeof (char); /* Give length of allocated memory if needed. */
  return ret;
}

int __cdecl __mingw_str_utf8_wide(const char *const mbptr, wchar_t **wptr, size_t *buflen)
{
  int len;
  wchar_t *buf;
  int ret = 0;

  len = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, mbptr, -1, NULL, 0); /* Get converted size */
  if (len <= 0) {
    switch (GetLastError()) {
      case ERROR_INVALID_PARAMETER: /* CP_UTF8 or MB_ERR_INVALID_CHARS is not supported */
      case ERROR_INVALID_FLAGS: /* CP_UTF8 or MB_ERR_INVALID_CHARS is not supported */
        errno = ENOSYS;
        *wptr = NULL;
        if (buflen != NULL) *buflen = 0;
        return 0;
      case NO_ERROR:
        if (len == 0)
          break;
        /* fallthrough */
      default:
        errno = EINVAL;
        *wptr = NULL;
        if (buflen != NULL) *buflen = 0;
        return 0;
    }
  }
  buf = calloc(len + 1, sizeof (wchar_t)); /* Allocate memory accordingly */

  if(!buf) len = 0;
  else {
    if (len != 0) {
      ret = MultiByteToWideChar (CP_UTF8, MB_ERR_INVALID_CHARS, mbptr, -1, buf, len); /* Do conversion */
      if (ret < 0 || (ret == 0 && GetLastError() != NO_ERROR)) {
        free(buf);
        errno = EINVAL;
        *wptr = NULL;
        if (buflen != NULL) *buflen = 0;
        return 0;
      }
    }
    buf[len] = L'\0'; /* Must terminate */
  }
  *wptr = buf; /* Set string pointer to allocated buffer */
  if (buflen != NULL) *buflen = len * sizeof (wchar_t); /* Give length of allocated memory if needed. */
  return ret; /* Number of characters written */
}

void __cdecl __mingw_str_free(void *ptr)
{
  if (ptr) free(ptr);
}
