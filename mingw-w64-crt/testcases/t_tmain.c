/**
 * This testcase should pass only if compiled with
 * -municode
 */

#include <tchar.h>

int
_tmain (void)
{
  void *volatile wmainptr = wmain;
  (void)wmainptr;
  return 0;
}
