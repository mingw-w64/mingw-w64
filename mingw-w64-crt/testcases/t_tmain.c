/**
 * This testcase should pass only if compiled with
 * -municode
 */

#include <tchar.h>

int
_tmain (void)
{
  volatile void *wmainptr = wmain;
  return 0;
}
