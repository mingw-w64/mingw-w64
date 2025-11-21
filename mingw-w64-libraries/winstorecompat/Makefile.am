AUTOMAKE_OPTIONS = foreign subdir-objects

AM_CFLAGS = -Wall -Wstrict-aliasing=2 -pedantic

lib_LIBRARIES = libwinstorecompat.a \
  libwindowsappcompat.a

libwinstorecompat_a_SOURCES = \
  src/CreateEventW.c \
  src/CreateFileW.c \
  src/CreateMutexW.c \
  src/CreateSemaphoreW.c \
  src/Crypto.c \
  src/EnumProcessModules.c \
  src/GetACP.c \
  src/GetActiveProcessorCount.c \
  src/GetConsoleOutputCP.c \
  src/GetFileAttributes.c \
  src/GetFileInformationByHandle.c \
  src/GetFileSize.c \
  src/GetModuleHandle.c \
  src/GetStartupInfo.c \
  src/GetTickCount.c \
  src/GetUserName.c \
  src/InitializeCriticalSection.c \
  src/IsDBCSLeadByteEx.c \
  src/LoadLibraryW.c \
  src/LocalAlloc.c \
  src/LocalFree.c \
  src/QueueTimer.c \
  src/RtlAddFunctionTable.c \
  src/RtlCaptureContext.c \
  src/RtlRestoreContext.c \
  src/RtlVirtualUnwind.c \
  src/SHGetFolderPathW.c \
  src/SetErrorMode.c \
  src/SetFilePointer.c \
  src/SetUnhandledExceptionFilter.c \
  src/Sleep.c \
  src/SleepEx.c \
  src/SystemFunction036.c \
  src/TerminateProcess.c \
  src/Tls.c \
  src/UnhandledExceptionFilter.c \
  src/VirtualProtect.c \
  src/WaitForSingleObject.c \
  src/beginthread.c \
  src/getenv.c \
  src/getenv_s.c \
  src/getpid.c \
  $(NULL)

libwindowsappcompat_a_SOURCES = \
  src/CreateFileW.c \
  src/EnumProcessModules.c \
  src/GetActiveProcessorCount.c \
  src/GetFileSize.c \
  src/GetStartupInfo.c \
  src/GetUserName.c \
  src/LoadLibraryW.c \
  src/QueueTimer.c \
  src/RtlAddFunctionTable.c \
  src/RtlCaptureContext.c \
  src/RtlRestoreContext.c \
  src/RtlVirtualUnwind.c \
  src/SHGetFolderPathW.c \
  src/SystemFunction036.c \
  src/UnhandledExceptionFilter.c \
  src/VirtualProtect.c \
  src/getenv.c \
  src/getpid.c \
  $(NULL)
libwindowsappcompat_a_CFLAGS = $(AM_CFLAGS) -D_WIN32_WINNT=_WIN32_WINNT_WIN10
