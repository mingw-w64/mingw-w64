/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <locale.h>

static BOOL WINAPI fallback_IsDBCSLeadByteEx(UINT cp, BYTE c)
{
  int i;
  CPINFO cp_info;
  if (GetCPInfo(cp, &cp_info) && cp_info.MaxCharSize == 2) {
    for (i = 0; i < MAX_LEADBYTES && cp_info.LeadByte[i]; i += 2) {
      if (c >= cp_info.LeadByte[i] && c <= cp_info.LeadByte[i+1])
        return TRUE;
    }
  }
  return FALSE;
}

_Static_assert(__builtin_types_compatible_p(__typeof__(fallback_IsDBCSLeadByteEx), __typeof__(IsDBCSLeadByteEx)),
    "Functions fallback_IsDBCSLeadByteEx() and IsDBCSLeadByteEx() are not compatible");

int __cdecl __mingw_isleadbyte_cp(int c, unsigned int cp)
{
  static __typeof__(IsDBCSLeadByteEx) *call_IsDBCSLeadByteEx = NULL;
  if (!call_IsDBCSLeadByteEx) {
    FARPROC farproc = NULL;
    HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    if (kernel32)
      farproc = GetProcAddress(kernel32, "IsDBCSLeadByteEx");
    if (!farproc)
      farproc = (FARPROC)(PVOID)fallback_IsDBCSLeadByteEx;
    (void)InterlockedExchangePointer((PVOID*)&call_IsDBCSLeadByteEx, (PVOID)farproc);
  }
  return call_IsDBCSLeadByteEx(cp, c);
}
