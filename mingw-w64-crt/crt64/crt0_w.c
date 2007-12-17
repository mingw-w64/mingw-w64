#include <windows.h>

int wmain (int flags, wchar_t **cmdline, wchar_t **inst)
{
  return (int) wWinMain ((HINSTANCE) inst, NULL, (LPWSTR) cmdline,(DWORD) flags);
}
