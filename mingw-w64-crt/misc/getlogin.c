#include <stddef.h>
#include <errno.h>
#include <unistd.h>
#include <windows.h>

char *getlogin(void)
{
  static char user_name[MAX_PATH];
  DWORD  length = sizeof (user_name);

  if (GetUserName (user_name, &length))
    return user_name;
  return NULL;
}

