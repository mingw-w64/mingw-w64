#include <stdio.h>
#include <wchar.h>

/* mingw-w64 headers */
#include "libtest.h"

int main() {
  int i;
  wchar_t buffer[11] = L"XXXXXXXXXX";
  int ret;
  mingw_test_init ();
  ret = swprintf(buffer, 3, L"%ls", L"AAA");
  if (ret >= 0 || wmemcmp(buffer, L"AA\0XXXXXXX", 10) != 0) {
    fprintf(stderr, "ret: expected=<0 got=%d\n", ret);
    fprintf(stderr, "buffer:");
    for (i = 0; i < 10; i++) {
      fprintf(stderr, " 0x%02x", (int)(wint_t)buffer[i]);
    }
    fprintf(stderr, "\n");
    return 1;
  }

  /* ISO C95+: output of 9 wide chars plus terminator must succeed when n=10.
   * Regression for __mingw_vswprintf exact-fit check (retval == n-1). */
  {
    wchar_t exact[16] = L"XXXXXXXXXXXXXXX";
    ret = swprintf(exact, 10, L".%8x", 0xd8c7bc89U);
    if (ret != 9 || wcscmp(exact, L".d8c7bc89") != 0) {
      fprintf(stderr, "exact-fit n=10: ret expected=9 got=%d\n", ret);
      fprintf(stderr, "exact-fit buffer: %ls\n", exact);
      return 1;
    }
    ret = swprintf(exact, 9, L".%8x", 0xd8c7bc89U);
    if (ret >= 0) {
      fprintf(stderr, "exact-fit n=9: ret expected=<0 got=%d\n", ret);
      return 1;
    }
  }

  return 0;
}
