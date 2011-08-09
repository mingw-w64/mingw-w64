#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int __mingw_asprintf(char **ret, const char *format, ...){
  va_list ap;
  int len;
  va_start(ap,format);
  /* Get Length */
  len = __mingw_vsnprintf(NULL,0,format,ap);
  if (len < 0) goto _end;
  /* +1 for \0 terminator. */
  *ret = malloc(len + 1);
  /* Check malloc fail*/
  if (!*ret) {
    len = -1;
    goto _end;
  }
  /* Write String */
  __mingw_vsnprintf(*ret,len,format,ap);
  /* Terminate explicitly */
  *ret[len] = '\0';
  _end:
  va_end(ap);
  return len;
}

int __mingw_vasprintf(char **ret, const char *format, va_list ap){
  int len;
  /* Get Length */
  len = __mingw_vsnprintf(NULL,0,format,ap);
  if (len < 0) return -1;
  /* +1 for \0 terminator. */
  *ret = malloc(len + 1);
  /* Check malloc fail*/
  if (!*ret) return -1;
  /* Write String */
  __mingw_vsnprintf(*ret,len,format,ap);
  /* Terminate explicitly */
  *ret[len] = '\0';
  return len;
}
