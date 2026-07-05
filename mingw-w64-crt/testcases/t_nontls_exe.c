#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

/* mingw-w64 headers */
#include "libtest.h"

/* This test verifies that this EXE application which is not using TLS, does not have unwanted/unexpected .tls section. */
int main(void)
{
  mingw_test_init();

  extern IMAGE_DOS_HEADER __ImageBase;
  assert(__ImageBase.e_magic == IMAGE_DOS_SIGNATURE);
  IMAGE_NT_HEADERS *nt_headers = (IMAGE_NT_HEADERS *)((BYTE *)&__ImageBase + __ImageBase.e_lfanew);
  assert(nt_headers->Signature == IMAGE_NT_SIGNATURE);
  assert(nt_headers->FileHeader.SizeOfOptionalHeader >= offsetof(IMAGE_OPTIONAL_HEADER, DataDirectory));
  assert(nt_headers->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR_MAGIC);
  assert(nt_headers->FileHeader.SizeOfOptionalHeader >= offsetof(IMAGE_OPTIONAL_HEADER, DataDirectory[nt_headers->OptionalHeader.NumberOfRvaAndSizes]));

  if (nt_headers->OptionalHeader.NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_TLS) {
    printf("test pass\n");
    printf("IMAGE_DIRECTORY_ENTRY_TLS is not present because NumberOfRvaAndSizes(%lu) <= IMAGE_DIRECTORY_ENTRY_TLS(%u)\n", nt_headers->OptionalHeader.NumberOfRvaAndSizes, IMAGE_DIRECTORY_ENTRY_TLS);
    return 0;
  } else if (nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size == 0 || nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress == 0) {
    printf("test passed\n");
    printf("IMAGE_DIRECTORY_ENTRY_TLS is not present because DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS] .Size and .VirtualAddress are zeros\n");
    return 0;
  } else {
    printf("test failed\n");
    printf("IMAGE_DIRECTORY_ENTRY_TLS is present because NumberOfRvaAndSizes(%lu) > IMAGE_DIRECTORY_ENTRY_TLS(%u) and DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size(%lu) != 0 or DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress(%lu) != 0\n", nt_headers->OptionalHeader.NumberOfRvaAndSizes, IMAGE_DIRECTORY_ENTRY_TLS, nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size, nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress);
    return 1;
  }
}
