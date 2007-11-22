/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSINIT_H
#define _GDIPLUSINIT_H

enum DebugEventLevel {
  DebugEventLevelFatal,DebugEventLevelWarning
};

typedef VOID (WINAPI *DebugEventProc)(DebugEventLevel level,CHAR *message);
typedef Status (WINAPI *NotificationHookProc)(ULONG_PTR *token);
typedef VOID (WINAPI *NotificationUnhookProc)(ULONG_PTR token);

struct GdiplusStartupInput {
  UINT32 GdiplusVersion;
  DebugEventProc DebugEventCallback;
  WINBOOL SuppressBackgroundThread;
  WINBOOL SuppressExternalCodecs;
  GdiplusStartupInput(DebugEventProc debugEventCallback = NULL,WINBOOL suppressBackgroundThread = FALSE,WINBOOL suppressExternalCodecs = FALSE) {
    GdiplusVersion = 1;
    DebugEventCallback = debugEventCallback;
    SuppressBackgroundThread = suppressBackgroundThread;
    SuppressExternalCodecs = suppressExternalCodecs;
  }
};

struct GdiplusStartupOutput {
  NotificationHookProc NotificationHook;
  NotificationUnhookProc NotificationUnhook;
};

extern "C" Status WINAPI GdiplusStartup(ULONG_PTR *token,const GdiplusStartupInput *input,GdiplusStartupOutput *output);
extern "C" VOID WINAPI GdiplusShutdown(ULONG_PTR token);

#endif
