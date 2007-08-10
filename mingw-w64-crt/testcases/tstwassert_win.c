#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string.h>
#include <assert.h>

int WINAPI WinMain(HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  int argc = strlen (lpCmdLine);  
  assert (argc & 1);
  return 0;
}
