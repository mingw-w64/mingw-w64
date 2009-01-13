#include <stdint.h>
#include <stddef.h>
extern void abort(void);

int main()
{
  int ret = 0;
#ifndef NULL
  ret=1;
#endif
  if (ret) abort();
#ifndef offsetof
  ret=1;
#endif
  if (ret) abort();
  return 0;
}

