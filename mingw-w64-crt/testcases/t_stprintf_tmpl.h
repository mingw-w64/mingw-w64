#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <tchar.h>

int main() {
  int i;
  TCHAR buffer[10] = { _T('X'), _T('X'), _T('X'), _T('X'), _T('X'), _T('X'), _T('X'), _T('X'), _T('X'), _T('X') };
#ifdef _UNICODE
  int exp_sizeof_buffer = 2*10;
#else
  int exp_sizeof_buffer = 10;
#endif
  /* _stprintf format:
   * %s takes _T string
   * %hs takes char* string
   * %ls takes wchar_t* string
   */
  int ret = _stprintf(buffer, _T("%sBB%hs%ls"), _T("AA"), "CC", L"DD");
  if (sizeof(buffer) != exp_sizeof_buffer) {
    fprintf(stderr, "sizeof(buffer): expected=%d got=%d\n", exp_sizeof_buffer, (int)sizeof(buffer));
    return 1;
  }
  if (ret != 8 || memcmp(buffer, _T("AABBCCDD\0X"), sizeof(buffer)) != 0) {
    fprintf(stderr, "ret: expected=8 got=%d\n", ret);
    fprintf(stderr, "buffer:");
    for (i = 0; i < 10; i++) {
      fprintf(stderr, " 0x%02x", (int)buffer[i]);
    }
    fprintf(stderr, "\n");
    return 1;
  }
  return 0;
}
