#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <windows.h>

unsigned int sleep (unsigned int seconds)
{
  Sleep (seconds * 1000);
  return 0;
}
