AUTOMAKE_OPTIONS = foreign subdir-objects

AM_CFLAGS = -Wall -Wstrict-aliasing=2 -pedantic

lib_LIBRARIES = libwinstorecompat.a \
  libwindowsappcompat.a

libwinstorecompat_a_SOURCES = \
  src/beginthread.c \
  src/GetModuleHandle.c \
  src/CreateEventW.c \
  src/CreateMutexW.c \
  src/CreateSemaphoreW.c \
  src/InitializeCriticalSection.c \
  src/GetFileAttributes.c \
  src/WaitForSingleObject.c \
  src/LoadLibraryW.c \
  src/CreateFileW.c \
  src/GetTickCount.c \
  src/SetUnhandledExceptionFilter.c \
  src/UnhandledExceptionFilter.c \
  src/TerminateProcess.c \
  src/IsDBCSLeadByteEx.c \
  src/SetErrorMode.c \
  src/GetACP.c \
  src/VirtualProtect.c \
  src/getenv.c \
  src/LocalAlloc.c \
  src/LocalFree.c \
  src/Sleep.c \
  src/SleepEx.c \
  src/SetFilePointer.c \
  src/GetFileSize.c \
  src/Tls.c \
  src/SHGetFolderPathW.c \
  src/QueueTimer.c \
  src/Crypto.c \
  src/GetStartupInfo.c \
  src/GetConsoleOutputCP.c \
  src/EnumProcessModules.c \
  src/RtlAddFunctionTable.c \
  src/RtlCaptureContext.c \
  src/RtlVirtualUnwind.c \
  src/RtlRestoreContext.c \
  src/GetUserName.c \
  src/getpid.c \
  src/GetFileInformationByHandle.c \
  src/SystemFunction036.c \
  $(NULL)

libwindowsappcompat_a_SOURCES = \
  src/beginthread.c \
  src/GetModuleHandle.c \
  src/LoadLibraryW.c \
  src/CreateFileW.c \
  src/UnhandledExceptionFilter.c \
  src/VirtualProtect.c \
  src/getenv.c \
  src/GetFileSize.c \
  src/SHGetFolderPathW.c \
  src/QueueTimer.c \
  src/Crypto.c \
  src/GetStartupInfo.c \
  src/EnumProcessModules.c \
  src/RtlAddFunctionTable.c \
  src/RtlCaptureContext.c \
  src/RtlVirtualUnwind.c \
  src/RtlRestoreContext.c \
  src/GetUserName.c \
  src/getpid.c \
  src/GetFileInformationByHandle.c \
  src/SystemFunction036.c \
  $(NULL)
libwindowsappcompat_a_CFLAGS = $(AM_CFLAGS) -D_WIN32_WINNT=_WIN32_WINNT_WIN10
