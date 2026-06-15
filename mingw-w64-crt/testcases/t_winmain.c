/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#define TITLE "WinMain"
#define WIDTH 250
#define HEIGHT 250

void Draw(HDC hdc);

LRESULT CALLBACK WindowProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{
  PAINTSTRUCT ps;
  switch (Msg)
  {
  case WM_PAINT:
    BeginPaint(hWnd,&ps);
    Draw(ps.hdc);
    EndPaint(hWnd,&ps);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd,Msg,wParam,lParam);
  }
  return 0;
}

char szClassName[] = "WinMain";

int WINAPI WinMain(HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
  HWND hwnd;
  MSG messages;
  WNDCLASSEX wincl;

  wincl.hInstance = hThisInstance;
  wincl.lpszClassName = szClassName;
  wincl.lpfnWndProc = WindowProc;
  wincl.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
  wincl.cbSize = sizeof(WNDCLASSEX);

  wincl.hIcon = LoadIcon(NULL,IDI_APPLICATION);
  wincl.hIconSm = LoadIcon(NULL,IDI_APPLICATION);
  wincl.hCursor = LoadCursor(NULL,IDC_ARROW);
  wincl.lpszMenuName = NULL;
  wincl.cbClsExtra = 0;
  wincl.cbWndExtra = 0;
  wincl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);;

  if (!RegisterClassEx(&wincl)) return 0;

  hwnd = CreateWindowEx(0, szClassName, TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WIDTH, HEIGHT,
			HWND_DESKTOP, NULL, hThisInstance, NULL);

  ShowWindow(hwnd,nCmdShow);

  while (GetMessage(&messages,NULL,0,0))
  {
    TranslateMessage(&messages);
    DispatchMessage(&messages);
  }
  return (int)messages.wParam;
}

void Draw(HDC hdc)
{
  HBRUSH pinsel;
  pinsel = CreateSolidBrush(RGB(255,255,0));
  Rectangle(hdc,10,10,110,110);
  TextOut(hdc,15,45,"Hello, World!",13);

  SelectObject(hdc,pinsel);
  Ellipse(hdc,100,100,200,200);
  Arc(hdc,120,120,180,180,100,200,200,200);
  SetPixel(hdc,130,140,0);
  SetPixel(hdc,170,140,0);
  MoveToEx(hdc,150,100,0);
  LineTo(hdc,145,90);
  LineTo(hdc,155,80);
  LineTo(hdc,150,75);
}
