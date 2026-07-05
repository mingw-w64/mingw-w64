#include <windows.h>
#include <scrnsave.h>

LRESULT WINAPI ScreenSaverProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  return DefScreenSaverProc(hWnd, message, wParam, lParam);
}

WINBOOL WINAPI ScreenSaverConfigureDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam __attribute__((unused)))
{
  switch (message) {
  case WM_INITDIALOG:
    return TRUE;

  case WM_COMMAND:
    switch (LOWORD(wParam)) {
    case IDOK:
    case IDCANCEL:
      EndDialog(hDlg, LOWORD(wParam));
      return TRUE;
    }
    break;
  }
  return FALSE;
}

WINBOOL WINAPI RegisterDialogClasses(HANDLE hInst __attribute__((unused)))
{
  return TRUE;
}
