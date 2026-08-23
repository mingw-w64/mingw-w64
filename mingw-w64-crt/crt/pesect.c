/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>

extern IMAGE_DOS_HEADER __ImageBase;

static WINBOOL
_ValidateImageBase (PBYTE pImageBase)
{
  PIMAGE_DOS_HEADER pDOSHeader;
  PIMAGE_NT_HEADERS pNTHeader;
  PIMAGE_OPTIONAL_HEADER pOptHeader;

  pDOSHeader = (PIMAGE_DOS_HEADER) pImageBase;
  if (pDOSHeader->e_magic != IMAGE_DOS_SIGNATURE)
    return FALSE;
  pNTHeader = (PIMAGE_NT_HEADERS) ((PBYTE) pDOSHeader + pDOSHeader->e_lfanew);
  if (pNTHeader->Signature != IMAGE_NT_SIGNATURE)
    return FALSE;
  pOptHeader = (PIMAGE_OPTIONAL_HEADER) &pNTHeader->OptionalHeader;
  if (pOptHeader->Magic != IMAGE_NT_OPTIONAL_HDR_MAGIC)
    return FALSE;
  return TRUE;
}

static PIMAGE_SECTION_HEADER
_FindPESection (PBYTE pImageBase, DWORD_PTR rva)
{
  PIMAGE_NT_HEADERS pNTHeader;
  PIMAGE_SECTION_HEADER pSection;
  unsigned int iSection;

  pNTHeader = (PIMAGE_NT_HEADERS) (pImageBase + ((PIMAGE_DOS_HEADER) pImageBase)->e_lfanew);

  for (iSection = 0, pSection = IMAGE_FIRST_SECTION (pNTHeader);
    iSection < pNTHeader->FileHeader.NumberOfSections;
    ++iSection,++pSection)
    {
      if (rva >= pSection->VirtualAddress
	  && rva < pSection->VirtualAddress + pSection->Misc.VirtualSize)
	return pSection;
    }
  return NULL;
}

int __mingw_GetSectionCount (void);
PIMAGE_SECTION_HEADER __mingw_GetSectionForAddress (LPVOID p);

PIMAGE_SECTION_HEADER
__mingw_GetSectionForAddress (LPVOID p)
{
  PBYTE pImageBase;
  DWORD_PTR rva;

  pImageBase = (PBYTE) &__ImageBase;
  if (! _ValidateImageBase (pImageBase))
    return NULL;

  rva = (DWORD_PTR) (((PBYTE) p) - pImageBase);
  return _FindPESection (pImageBase, rva);
}

int
__mingw_GetSectionCount (void)
{
  PBYTE pImageBase;
  PIMAGE_NT_HEADERS pNTHeader;

  pImageBase = (PBYTE) &__ImageBase;
  if (! _ValidateImageBase (pImageBase))
    return 0;

  pNTHeader = (PIMAGE_NT_HEADERS) (pImageBase + ((PIMAGE_DOS_HEADER) pImageBase)->e_lfanew);

  return (int) pNTHeader->FileHeader.NumberOfSections;
}


PBYTE _GetPEImageBase (void);

PBYTE
_GetPEImageBase (void)
{
  PBYTE pImageBase;
  pImageBase = (PBYTE) &__ImageBase;
  if (! _ValidateImageBase (pImageBase))
    return NULL;
  return pImageBase;
}
