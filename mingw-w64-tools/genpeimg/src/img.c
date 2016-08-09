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

file_image *
fimg_create (void)
{
  file_image *r = (file_image *) malloc (sizeof (file_image));
  if (r)
    memset (r, 0, sizeof (file_image));
  return r;
}

static void
fimg_free_content (file_image *pimg)
{
  if (!pimg)
    return;
  if (pimg->data)
    free (pimg->data);
  if (pimg->filename)
    free (pimg->filename);
  memset (pimg, 0, sizeof (file_image));
}

void
fimg_free (file_image *pimg)
{
  if (!pimg)
    return;
  if (pimg->want_save && pimg->is_modified)
    fimg_save_as (pimg, pimg->filename, pimg->data_len);
  fimg_free_content (pimg);
  free (pimg);
}

int fimg_load (file_image *pimg, const char *fname)
{
  FILE *fp;
  size_t r;

  fp = fopen (fname, "rb");
  if (!pimg || !fp)
    return 0;
  fimg_free_content (pimg);
  pimg->filename = strdup (fname);
  if (pimg->filename == NULL)
    {
      fclose (fp);
      return 0;
    }
  fseek (fp, 0, SEEK_END);
  pimg->data_len = (size_t) ftell (fp);
  fseek (fp, 0, SEEK_SET);
  if (pimg->data_len == FIMG_POS_END)
    {
      fclose (fp);
      fimg_free_content (pimg);
      return 0;
    }
  if (pimg->data_len == 0)
    {
      fclose (fp);
      return 1;
    }
  pimg->data = (unsigned char *) malloc (pimg->data_len);
  if (pimg->data == NULL)
    {
      fclose (fp);
      fimg_free_content (pimg);
      return 0;
    }
  r = fread (pimg->data, 1, pimg->data_len, fp);
  fclose (fp);
  return r == pimg->data_len;
}

int
fimg_rename (file_image *pimg, const char *newfname)
{
  char *n = NULL;
  if (!pimg)
    return 0;
  if (newfname)
    {
      n = strdup (newfname);
      if (!n)
        return 0;
    }
  if (pimg->filename)
    free (pimg->filename);
  pimg->filename = n;
  return 1;
}

int
fimg_save_as (file_image *pimg, const char *fname, size_t length)
{
  FILE *fp;

  if (!fname || *fname == 0)
    return 0;
  fp = fopen (fname, "wb");
  if (!fp)
    return 0;
  if (length != 0)
    fwrite (pimg->data, 1, length, fp);
  fclose (fp);
  pimg->is_modified = 0;
  return 1;
}

int fimg_save (file_image *pimg)
{
  return fimg_save_as (pimg, pimg->filename, pimg->data_len);
}

file_image *
fimg_clone (const file_image *pimg)
{
  file_image *r = fimg_create ();

  if (!r)
    return NULL;
  r->filename = (pimg->filename ? strdup (pimg->filename) : NULL);
  if (pimg->filename && r->filename == NULL)
    {
      fimg_free (r);
      return NULL;
    }
  r->data_len = pimg->data_len;
  if (r->data_len)
    {
      r->data = (unsigned char *) malloc (r->data_len);
      if (r->data == NULL)
        {
	  fimg_free (r);
	  return NULL;
	}
      memcpy (r->data, pimg->data, r->data_len);
    }
  r->is_modified = 1;
  r->want_save = 0;
  return r;
}

int
fimg_resize (file_image *pimg, size_t new_size)
{
  unsigned char *h;
  if (!pimg)
    return 0;
  if (pimg->data_len >= new_size)
    {
      pimg->data_len = new_size;
      pimg->is_modified = 1;
      return 1;
    }
  h = (unsigned char *) realloc (pimg->data, new_size);
  if (!h)
    return 0;
  pimg->data = h;
  memset (h + pimg->data_len, 0, (new_size - pimg->data_len));
  pimg->data_len = new_size;
  pimg->is_modified = 1;
  return 1;
}
  
int
fimg_replace_at (file_image *pimg, const void *dta, size_t pos, size_t length)
{
  size_t end = pos + length;
  if (end > pimg->data_len)
    {
      if (!fimg_resize (pimg, end))
        return 0;
    }
  if (!length)
    return 1;
  if (!dta)
    memset (pimg->data + pos, 0, length);
  else
    memcpy (pimg->data + pos, dta, length);
  pimg->is_modified = 1;
  return 1;
}

int
fimg_insert_at (file_image *pimg, const void *dta, size_t pos, size_t length)
{
  size_t new_size, old_end, sv_len = length;
  if (!pimg)
    return 0;
  new_size = pimg->data_len + length;
  if (pos > pimg->data_len)
    length += pos - pimg->data_len;
  if (!length)
    return 1;
  old_end = pimg->data_len;
  if (!fimg_resize (pimg,new_size))
    return 0;
  if (pos < old_end)
    memmove (pimg->data + pos + length, pimg->data + pos, (old_end - pos));
  if (!dta && sv_len)
    memset (pimg->data + pos, 0, sv_len);
  else if (dta && sv_len)
    memcpy (pimg->data + pos, dta, sv_len);
  pimg->is_modified = 1;
  return 1;
}

int
fimg_remove_at (file_image *pimg, size_t pos, size_t length)
{
  size_t emax = pos + length;
  if (!pimg)
    return 0;
  if (pos > pimg->data_len)
    return 1;
  if (emax > pimg->data_len)
    length = pimg->data_len - pos;
  if (!length)
    return 1;
  if (pimg->data_len > (pos + length))
    memmove (pimg->data + pos, pimg->data + pos + length, (pimg->data_len - (pos + length)));
  fimg_resize (pimg, pimg->data_len - length);
  return 1;
}

unsigned char
fimg_get_uchar_at (const file_image *pimg, size_t pos)
{
  if (!pimg || pos >= pimg->data_len)
    return 0;
  return pimg->data[pos];
}

int
fimg_set_uchar_at (file_image *pimg, unsigned char val, size_t pos)
{
  return fimg_replace_at (pimg, &val, pos, 1);
}

unsigned short
fimg_get_ushort_at (const file_image *pimg, size_t pos, int big_endian)
{
  unsigned short r, r1;
  r = (unsigned short) fimg_get_uchar_at (pimg, pos);
  r1 = (unsigned short) fimg_get_uchar_at (pimg, pos + 1);
  if (big_endian)
    r <<= 8;
  else
    r1 <<= 8;
  return r | r1;
}

int
fimg_set_ushort_at (file_image *pimg, unsigned short val, size_t pos, int big_endian)
{
  int r = 1;
  if (big_endian)
    {
      r &= fimg_set_uchar_at (pimg, (unsigned char) ((val >> 8) & 0xff), pos);
      r &= fimg_set_uchar_at (pimg, (unsigned char) (val & 0xff), pos + 1);
    }
  else
    {
      r &= fimg_set_uchar_at (pimg, (unsigned char) ((val >> 8) & 0xff), pos + 1);
      r &= fimg_set_uchar_at (pimg, (unsigned char) (val & 0xff), pos);
    }
  return r;
}

unsigned int
fimg_get_uint_at (const file_image *pimg, size_t pos, int big_endian)
{
  unsigned int r1, r2;
  r1 = (unsigned int) fimg_get_ushort_at (pimg, pos, big_endian);
  r2 = (unsigned int) fimg_get_ushort_at (pimg, pos + 2, big_endian);
  if (big_endian)
    r1 <<= 16;
  else
    r2 <<= 16;
  return r1 | r2;
}

int
fimg_set_uint_at (file_image *pimg, unsigned int val, size_t pos, int big_endian)
{
  int r = 1;
  if (big_endian)
    {
      r &= fimg_set_ushort_at (pimg, (unsigned short) ((val >> 16) & 0xffff), pos, 1);
      r &= fimg_set_ushort_at (pimg, (unsigned short) (val & 0xffff), pos + 2, 1);
    }
  else
    {
      r &= fimg_set_ushort_at (pimg, (unsigned short) ((val >> 16) & 0xffff), pos + 2, 0);
      r &= fimg_set_ushort_at (pimg, (unsigned short) (val & 0xffff), pos, 0);
    }
  return r;
}

unsigned long long
fimg_get_uquad_at (const file_image *pimg, size_t pos, int big_endian)
{
  unsigned long long r1, r2;

  r1 = (unsigned long long) fimg_get_uint_at (pimg, pos, big_endian);
  r2 = (unsigned long long) fimg_get_uint_at (pimg, pos + 4, big_endian);
  if (big_endian)
    r1 <<= 32;
  else
    r2 <<= 32;
  return r1 | r2;
}

int fimg_set_uquad_at (file_image *pimg, unsigned long long val, size_t pos, int big_endian)
{
  int r = 1;
  if (big_endian)
    {
      r &= fimg_set_uint_at (pimg, (unsigned short) ((val >> 32) & 0xffffffffULL), pos, 1);
      r &= fimg_set_uint_at (pimg, (unsigned short) (val & 0xffffffffULL), pos + 4, 1);
    }
  else
    {
      r &= fimg_set_uint_at (pimg, (unsigned short) ((val >> 32) & 0xffffffffULL), pos + 4, 1);
      r &= fimg_set_uint_at (pimg, (unsigned short) (val & 0xffffffffULL), pos, 1);
    }
  return r;
}

void
fimg_show_stats (const file_image *pimg)
{
  fprintf (stderr, "fimg: %p", pimg);
  if (pimg)
    {
      fprintf (stderr, "{ data:%p, len:%#"PRIxPTR", name:\"%s\", mod:%s, want_save:%s }",
        pimg->data, pimg->data_len, (pimg->filename ? pimg->filename : "<unnamed>"),
        pimg->is_modified ? "yes" : "no",
        pimg->want_save ? "yes" : "no");
    }
  fprintf (stderr, "\n");
}

void
fimg_dump_mem (const file_image *pimg, size_t len, FILE *out)
{
  size_t off = 0, i;
  if (!pimg)
    return;
  while (off < len)
    {
      fprintf (out, "%#08"PRIXPTR":", off);
      for (i = 0; i < 16 && off < len; i++, off++)
        {
	  fprintf (out," %02X", fimg_get_uchar_at (pimg, off));
	}
      fprintf (out,"\n");
    }
}

#if 0
int main (int argc,char **argv)
{
  file_image *p = fimg_create ();
  if (!fimg_load (p, argv[0]))
    {
      fprintf (stderr, "Failed to load %s\n", argv[0]);
      fimg_free (p);
      return 0;
    }
  fimg_show_stats (p);
  fimg_dump_mem (p, 32, stderr);
  fprintf (stderr, "Remove leading 4 bytes\n");
  fimg_remove_at (p, 0, 4);
  fimg_show_stats (p);
  fimg_dump_mem (p, 32, stderr);
  fprintf (stderr, "Remove at pos 2 the next 10 bytes\n");
  fimg_remove_at (p, 2, 10);
  fimg_show_stats (p);
  fimg_dump_mem (p, 32, stderr);
  fprintf (stderr, "Remove at end-pos the next 10 bytes\n");
  fimg_remove_at (p, p->data_len, 10);
  fimg_show_stats (p);
  fimg_dump_mem (p, 32, stderr);
  fimg_free (p);
  return 1;
}
#endif
