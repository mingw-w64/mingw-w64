AUTOMAKE_OPTIONS = foreign subdir-objects

AM_CFLAGS = -Wall -Wstrict-aliasing=2 -pedantic

lib_LIBRARIES = libwinstorecompat.a

libwinstorecompat_a_SOURCES = \
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
  src/SetErrorMode.c
