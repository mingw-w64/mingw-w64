/*
    genpeimg - Modify Portable Executable flags and properties.
    Copyright (C) 2009-2016  mingw-w64 project

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "img.h"

pe_image *
peimg_load (const char *fname)
{
  pe_image *r;
  file_image *fi = fimg_create ();
  if (!fi)
    return NULL;
  if (!fimg_load (fi, fname))
    {
      fimg_free (fi);
      return NULL;
    }
  if ((r = peimg_create (fi)) != NULL)
    return r;
  fimg_free (fi);
  return NULL;
}

static size_t
find_pe_hdr (file_image *fi)
{
  unsigned char m1, m2;
  int lfanew;
  m1 = fimg_get_uchar_at (fi, 0);
  m2 = fimg_get_uchar_at (fi, 1);
  if (m1 == 'P' && m2 == 'E')
    {
      fprintf (stderr, "Starts with PE\n");
      return 0;
    }
  if (m1 != 'M' || m2 != 'Z')
    return FIMG_POS_END;
  if (fi->data_len < 256)
    return FIMG_POS_END;
  lfanew = (int) fimg_get_uint_at (fi, 60, 0);
  if (lfanew <= 0 || (size_t) lfanew >= fi->data_len)
    return FIMG_POS_END;
  m1 = fimg_get_uchar_at (fi, lfanew);
  m2 = fimg_get_uchar_at (fi, lfanew + 1);
  if (m1 != 'P' || m2 != 'E')
    return FIMG_POS_END;
  m1 = fimg_get_uchar_at (fi, lfanew + 2);
  m2 = fimg_get_uchar_at (fi, lfanew + 3);
  if (m1 != 0 || m1 != m2)
    return FIMG_POS_END;
  return (size_t) lfanew;
}

void
peimg_set_hdr_characeristics (pe_image *pe, unsigned short set, unsigned short mask)
{
  unsigned short flgs;
  if (pe->is_64bit && (mask & 0x20) == 0)
    {
      fprintf (stderr, " Can't remove for PE+ the large-address-aware flag\n");
      mask |= 0x20;
    }
  flgs = pe->pe_filehdr.characteristics;
  flgs &= mask;
  flgs |= set;
  if (flgs == pe->pe_filehdr.characteristics)
    return;
  PEIMG_SET_USHORT (pe, 22, flgs);
}

static int
fill_pe_info (pe_image *pe)
{
  /* File header is 24 bytes long.  */
  pe->pe_filehdr.machine = PEIMG_GET_USHORT (pe, 4);
  pe->pe_filehdr.numsecs = PEIMG_GET_USHORT (pe, 6);
  pe->pe_filehdr.timestamp =  PEIMG_GET_UINT (pe, 8);
  pe->pe_filehdr.pointer2SymTab = PEIMG_GET_UINT (pe, 12);
  pe->pe_filehdr.numSyms = PEIMG_GET_UINT (pe, 16);
  pe->pe_filehdr.szOptHdr = PEIMG_GET_USHORT (pe, 20);
  pe->pe_filehdr.characteristics = PEIMG_GET_USHORT (pe, 22);
  switch (pe->pe_filehdr.machine)
    {
    case 0x14c: /* i386 */
    case 0x1c4: /* ARMNT */
      pe->is_64bit = 0;
      pe->is_bigendian = 0;
      break;
    case 0x8664: /* x64 */
    case 0xaa64: /* ARM64 */
      pe->is_64bit = 1;
      pe->is_bigendian = 0;
      break;
    default:
      fprintf (stderr, "PE image for machince 0x%x not supported\n", pe->pe_filehdr.machine);
      return 0;
    }
  pe->optional_hdr_pos = 24;
  switch (PEIMG_GET_USHORT (pe, 24))
    {
    case 0x10b:
      if (pe->is_64bit == 0)
        break;
      fprintf (stderr, "PE+ image has invalid 32-bit optional header.\n");
      return 0;
    case 0x20b:
      if (pe->is_64bit)
        break;
      fprintf (stderr, "PE image has invalid 64-bit optional header.\n");
      return 0;
    default:
      fprintf (stderr, "PE image has unknown optional header with magic 0x%x.\n",
        PEIMG_GET_USHORT (pe, 24));
      return 0;
    }
  pe->section_list = pe->optional_hdr_pos + pe->pe_filehdr.szOptHdr;
  pe->section_list_sz = ((size_t) pe->pe_filehdr.numsecs) * 40;
  return 1;
}

pe_image *
peimg_create (file_image *pimg)
{
  size_t pe_hdr;
  pe_image *r;
  if (!pimg)
    return NULL;
  pe_hdr = find_pe_hdr (pimg);
  if (pe_hdr == FIMG_POS_END)
    return NULL;
  /* So we might have found a PE-image.  */
  r = (pe_image *) malloc (sizeof (pe_image));
  if (!r)
    return NULL;
  memset (r, 0, sizeof (pe_image));
  r->pimg = pimg;
  r->start_pe = pe_hdr;
  r->size_pe = pimg->data_len - pe_hdr;
  if (!fill_pe_info (r))
    {
      free (r);
      r = NULL;
    }
  return r;
}  

void
peimg_free (pe_image *ppeimg)
{
  if (!ppeimg)
    return;
  if (ppeimg->pimg)
    fimg_free (ppeimg->pimg);
  memset (ppeimg, 0, sizeof (pe_image));
  free (ppeimg);
}

void
peimg_show (pe_image *ppeimg, FILE *outfp)
{
  unsigned short hdr_cha;
  if (!ppeimg || !outfp)
    return;
  fprintf (outfp, "PE image \"%s\"\n  found at position %#"PRIxPTR" in file-image\n",
    ppeimg->pimg->filename, ppeimg->start_pe);
  fprintf (outfp, "  Image has size of %#"PRIxPTR" byte(s)\n", ppeimg->size_pe);
  fprintf (outfp, "  Image machine kind is: %#x (%s)\n",
    ppeimg->pe_filehdr.machine, ppeimg->is_64bit ? "64-bit" : "32-bit");
  fprintf (outfp, "  Image contains %u section(s)\n", ppeimg->pe_filehdr.numsecs);
  fprintf (outfp, "  Optional header-size is %u\n", ppeimg->pe_filehdr.szOptHdr);
  hdr_cha = ppeimg->pe_filehdr.characteristics;
  if (hdr_cha != 0)
    {
      fprintf (outfp, "  Characterstics:");
      if ((hdr_cha & 1) != 0)
        fprintf (outfp, " relocs-stripped");
      if ((hdr_cha & 2) != 0)
        fprintf (outfp, " executable");
      if ((hdr_cha & 4) != 0)
        fprintf (outfp, " line-numbers-stripped");
      if ((hdr_cha & 8) != 0)
        fprintf (outfp, " local-syms-stripped");
      if ((hdr_cha & 16) != 0)
        fprintf (outfp, " aggressive-ws-trim");
      if ((hdr_cha & 32) != 0)
        fprintf (outfp, " large-address-aware");
      if ((hdr_cha & 0x80) != 0)
        fprintf (outfp, " bytes-reversed");
      if ((hdr_cha & 0x100) != 0)
        fprintf (outfp, " 32-bit-machine");
      if ((hdr_cha & 0x200) != 0)
        fprintf (outfp, " debug-stripped");
      if ((hdr_cha & 0x400) != 0)
        fprintf (outfp, " removable-run-from-swap");
      if ((hdr_cha & 0x800) != 0)
        fprintf (outfp, " net-run-from-swap");
      if ((hdr_cha & 0x1000) != 0)
        fprintf (outfp, " system");
      if ((hdr_cha & 0x2000) != 0)
        fprintf (outfp, " DLL");
      if ((hdr_cha & 0x4000) != 0)
        fprintf (outfp, " up-system-only");
      if ((hdr_cha & 0x8000) != 0)
        fprintf (outfp, " bytes-reversed-high");
      hdr_cha &= 0x40;
      if (hdr_cha != 0)
        fprintf (outfp, " unknown-flag-0x40");
      fprintf (outfp, "\n");
    }
  fprintf (outfp, "PE+ optional header information\n"
    "  Linker version %u.%u, Code size: 0x%x, Intialized Data size: 0x%x\n"
    "  Uninitialized Data size: 0x%x, Entry-point 0x%x\n",
      PEIMG_GET_UCHAR (ppeimg, ppeimg->optional_hdr_pos + 2),
      PEIMG_GET_UCHAR (ppeimg, ppeimg->optional_hdr_pos + 3),
      PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 4),
      PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 8),
      PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 12),
      PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 16));
  if (ppeimg->is_64bit)
    {
      fprintf (outfp,
        "  Bases: Code=0x%x ImageBase=%#"PRIxPTR"\n",
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 20),
        (size_t)PEIMG_GET_UQUAD (ppeimg, ppeimg->optional_hdr_pos + 24));
    }
  else
    {
      fprintf (outfp,
        "  Bases: Code=0x%x Data=0x%x ImageBase=0x%x\n",
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 20),
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 24),
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 28));
    }
  fprintf (outfp, "  Alignments: Section: 0x%x File:0x%x\n",
    PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 32),
    PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 36));
  fprintf (outfp, "  Versions: OS:%u.%u Image:%u.%u SubSystem:%u.%u, win32:0x%x\n",
    PEIMG_GET_USHORT (ppeimg, ppeimg->optional_hdr_pos + 40),
    PEIMG_GET_USHORT (ppeimg, ppeimg->optional_hdr_pos + 42),
    PEIMG_GET_USHORT (ppeimg, ppeimg->optional_hdr_pos + 44),
    PEIMG_GET_USHORT (ppeimg, ppeimg->optional_hdr_pos + 46),
    PEIMG_GET_USHORT (ppeimg, ppeimg->optional_hdr_pos + 48),
    PEIMG_GET_USHORT (ppeimg, ppeimg->optional_hdr_pos + 50),
    PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 52));
  fprintf (outfp, "  Size of:  Image:0x%x Headers:0x%x\n",
    PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 56),
    PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 60));
  fprintf (outfp, "  Checksum: 0x%x\n",
    PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 64));
  fprintf (outfp, "  SubSystem: ");
  switch (PEIMG_GET_USHORT (ppeimg, ppeimg->optional_hdr_pos + 68))
    {
    case 0: fprintf (outfp, "Unknown (0)\n"); break;
    case 1: fprintf (outfp, "Native (1)\n"); break;
    case 2: fprintf (outfp, "Windows GUI (2)\n"); break;
    case 3: fprintf (outfp, "Windows CUI (3)\n"); break;
    case 5: fprintf (outfp, "OS/2 CUI (5)\n"); break;
    case 7: fprintf (outfp, "Posix CUI (7)\n"); break;
    case 8: fprintf (outfp, "Native Windows (8)\n"); break;
    case 9: fprintf (outfp, "Windows CE GUI (9)\n"); break;
    case 10: fprintf (outfp, "EFI Application (10)\n"); break;
    case 11: fprintf (outfp, "EFI Service Driver (11)\n"); break;
    case 12: fprintf (outfp, "EFI Runtime Driver (12)\n"); break;
    case 13: fprintf (outfp, "EFI ROM (13)\n"); break;
    case 14: fprintf (outfp, "XBOX (14)\n"); break;
    case 16: fprintf (outfp, "Windows Boot Application (16)\n"); break;
    default:
      fprintf (outfp, "Unkown (%u)\n", PEIMG_GET_USHORT (ppeimg, ppeimg->optional_hdr_pos + 68));
      break;
    }
  hdr_cha = PEIMG_GET_USHORT (ppeimg, ppeimg->optional_hdr_pos + 70);
  if (hdr_cha != 0)
    {
      fprintf (outfp, "  Optional Characteristics:\n   ");
      if ((hdr_cha & 0x20) != 0)
	fprintf (outfp, " high-entropy-va");
      if ((hdr_cha & 0x40) != 0)
        fprintf (outfp, " dynamic-base");
      if ((hdr_cha & 0x80) != 0)
        fprintf (outfp, " force-integrity");
      if ((hdr_cha & 0x100) != 0)
        fprintf (outfp, " nx-compatible");
      if ((hdr_cha & 0x200) != 0)
        fprintf (outfp, " no-isolation");
      if ((hdr_cha & 0x400) != 0)
        fprintf (outfp, " no-SEH");
      if ((hdr_cha & 0x800) != 0)
        fprintf (outfp, " no-BIND");
      if ((hdr_cha & 0x1000) != 0)
	fprintf (outfp, " app-container");
      if ((hdr_cha & 0x2000) != 0)
        fprintf (outfp, " wdm-Driver");
      if ((hdr_cha & 0x4000) != 0)
        fprintf (outfp, " control-flow-guard");
      if ((hdr_cha & 0x8000) != 0)
        fprintf (outfp, " terminal-server-aware");
      hdr_cha &= ~(0xbfef);
      if (hdr_cha)
        fprintf (outfp, " unknown(0x%x)", hdr_cha);
      fprintf (outfp, "\n");
    }
  if (ppeimg->is_64bit)
    {
      fprintf (outfp, "Sizes Stack: Reserved:%#"PRIxPTR" Commit:%#"PRIxPTR"\n",
        (size_t)PEIMG_GET_UQUAD (ppeimg, ppeimg->optional_hdr_pos + 72),
        (size_t)PEIMG_GET_UQUAD (ppeimg, ppeimg->optional_hdr_pos + 80));
      fprintf (outfp, "Sizes Heap: Reserved:%#"PRIxPTR" Commit:%#"PRIxPTR"\n",
        (size_t)PEIMG_GET_UQUAD (ppeimg, ppeimg->optional_hdr_pos + 88),
        (size_t)PEIMG_GET_UQUAD (ppeimg, ppeimg->optional_hdr_pos + 96));
      fprintf (outfp, "LoaderFlags: 0x%x, # of rva&sizes: %u\n",
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 104),
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 108));
    }
  else
    {
      fprintf (outfp, "Sizes Stack: Reserved:%#x Commit:%#x\n",
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 72),
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 76));
      fprintf (outfp, "Sizes Heap: Reserved:%#x Commit:%#x\n",
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 80),
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 84));
      fprintf (outfp, "LoaderFlags: %#x, # of rva&sizes: %u\n",
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 88),
        PEIMG_GET_UINT (ppeimg, ppeimg->optional_hdr_pos + 92));
    }
}

void
peimg_set_hdr_opt_subsystem (pe_image *pe, unsigned short subsystem)
{
  if (subsystem != PEIMG_GET_USHORT (pe, pe->optional_hdr_pos + 68))
    PEIMG_SET_USHORT (pe, pe->optional_hdr_pos + 68, subsystem);
}

void
peimg_set_hdr_opt_dll_characteristics (pe_image *pe, unsigned short set, unsigned short mask)
{
  unsigned short flgs;

  flgs = PEIMG_GET_USHORT (pe, pe->optional_hdr_pos + 70);
  flgs &= mask;
  flgs |= set;
  if (flgs == PEIMG_GET_USHORT (pe, pe->optional_hdr_pos + 70))
    return;
  PEIMG_SET_USHORT (pe, pe->optional_hdr_pos + 70, flgs);
}

#if 0
int main(int argc, char **argv)
{
  pe_image *pe;
  pe = peimg_load (argv[0]);
  if (!pe)
    {
      fprintf (stderr, "File not found, or no PE-image\n");
      return 0;
    }
  peimg_show (pe, stderr);
  peimg_free (pe);
  return 1;
}
#endif
