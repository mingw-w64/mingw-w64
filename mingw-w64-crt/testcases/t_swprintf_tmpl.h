#include <stdio.h>
#include <wchar.h>

int main() {
  int i;
  wchar_t buffer[10] = L"XXXXXXXXXX";
  int ret = swprintf(buffer, 3, L"%ls", L"AAA");
  if (ret >= 0 || wmemcmp(buffer, L"AA\0XXXXXXX", 10) != 0) {
    fprintf(stderr, "ret: expected=<0 got=%d\n", ret);
    fprintf(stderr, "buffer:");
    for (i = 0; i < 10; i++) {
      fprintf(stderr, " 0x%02x", (int)(wint_t)buffer[i]);
    }
    fprintf(stderr, "\n");
    return 1;
  }
  return 0;
}
