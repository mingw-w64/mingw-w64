#define __USE_MINGW_ANSI_STDIO 0

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

__attribute__((__format__(scanf, 2, 3)))
static int call_vsscanf(const char *str, const char *format, ...)
{
  int ret;
  va_list ap;
  va_start(ap, format);
  ret = vsscanf(str, format, ap);
  va_end(ap);
  return ret;
}

int main()
{
  char b[51];
  call_vsscanf(
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY",
    "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
    &b[0],&b[1],&b[2],&b[3],&b[4],&b[5],&b[6],&b[7],&b[8],&b[9],&b[10],
    &b[11],&b[12],&b[13],&b[14],&b[15],&b[16],&b[17],&b[18],&b[19],&b[20],
    &b[21],&b[22],&b[23],&b[24],&b[25],&b[26],&b[27],&b[28],&b[29],&b[30],
    &b[31],&b[32],&b[33],&b[34],&b[35],&b[36],&b[37],&b[38],&b[39],&b[40],
    &b[41],&b[42],&b[43],&b[44],&b[45],&b[46],&b[47],&b[48],&b[49],&b[50]
  );
  printf("b=%.51s\n", b);
  return memcmp(b, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY", 51);
}
