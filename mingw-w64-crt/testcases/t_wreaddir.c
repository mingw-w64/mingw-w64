#include <direct.h>
#include <dirent.h>
#include <errno.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

int main(int argc, char **argv)
{
  struct _wdirent *di;
  _WDIR *h;

  mingw_test_init ();

  if (_osplatform != VER_PLATFORM_WIN32_NT) {
    printf("_wopendir is not supported on non-NT systems\n");
    return 77;
  }

  h = _wopendir (L".");

  if (!h)
    return 1;

  while ((di = _wreaddir (h)) != NULL)
    printf ("%ls\n", di->d_name);

  _wclosedir (h);

  return 0;
}
