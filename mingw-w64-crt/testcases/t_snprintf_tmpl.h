#include <stdio.h>
#include <string.h>

int main() {
  int i;
  char buffer[10] = "XXXXXXXXXX";
  int ret = snprintf(buffer, 3, "%s", "AAA");
  if (ret != 3 || memcmp(buffer, "AA\0XXXXXXX", 10) != 0) {
    fprintf(stderr, "ret: expected=3 got=%d\n", ret);
    fprintf(stderr, "buffer:");
    for (i = 0; i < 10; i++) {
      fprintf(stderr, " 0x%02x", (int)buffer[i]);
    }
    fprintf(stderr, "\n");
    return 1;
  }
  return 0;
}
