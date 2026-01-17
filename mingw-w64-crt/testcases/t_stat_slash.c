#include <windows.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

void
test (char *path)
{
  struct stat buf;
  if (stat(path, &buf) == 0)
    printf ("OK [%s]\n", path);
  else {
    printf ("ERROR [%s]: %d\n", path, errno);
    abort();
  }
}

void
wtest (wchar_t *path)
{
  struct stat buf;
  if (wstat(path, &buf) == 0)
    wprintf (L"OK [%ls]\n", path);
  else {
    wprintf (L"ERROR [%ls]: %d\n", path, errno);
    abort();
  }
}

int
main (int argc, char **argv)
{
  wchar_t windir_wbuf[MAX_PATH + 1];
  char windir_abuf[MAX_PATH + 1];

  setvbuf (stdout, NULL, _IONBF, 0);

  if (GetWindowsDirectoryA(&windir_abuf[0], MAX_PATH))
  {
    strcat (&windir_abuf[0], "\\");
    test (&windir_abuf[0]);
  }
  test ("c:\\");
  test ("\\");
  test ("/");

  if (GetWindowsDirectoryW(&windir_wbuf[0], MAX_PATH))
  {
    wcscat (&windir_wbuf[0], L"\\");
    wtest (windir_wbuf);
  }
  wtest (L"c:\\");
  wtest (L"\\");
  wtest (L"/");
  return 0;
}
