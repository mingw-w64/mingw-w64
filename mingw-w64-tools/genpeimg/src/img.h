/*
    genpeimg - Modify Portable Executable flags and properties.
    Copyright (C) 2009-2016 mingw-w64 project

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
#ifndef IMG_HXX
#define IMG_HXX

typedef struct file_image {
  unsigned char *data;
  size_t data_len;
  char *filename;
  unsigned int is_modified : 1;
  unsigned int want_save : 1;
} file_image;

file_image *fimg_create (void);
void fimg_free (file_image *pimg);
void fimg_show_stats (const file_image *pimg);
void fimg_dump_mem (const file_image *pimg, size_t len, FILE *out);
int fimg_load (file_image *pimg, const char *fname);
int fimg_rename (file_image *pimg, const char *newfname);
int fimg_save_as (file_image *pimg, const char *fname, size_t length);
int fimg_save (file_image *pimg);
int fimg_resize (file_image *pimg, size_t new_size);
file_image *fimg_clone (const file_image *pimg);
int fimg_replace_at (file_image *pimg, const void *dta, size_t pos, size_t length);
int fimg_insert_at (file_image *pimg, const void *dta, size_t pos, size_t length);
int fimg_remove_at (file_image *pimg, size_t pos, size_t length);

unsigned char fimg_get_uchar_at (const file_image *pimg, size_t pos);
int fimg_set_uchar_at (file_image *pimg, unsigned char val, size_t pos);
unsigned short fimg_get_ushort_at (const file_image *pimg, size_t pos, int big_endian);
int fimg_set_ushort_at (file_image *pimg, unsigned short val, size_t pos, int big_endian);
unsigned int fimg_get_uint_at (const file_image *pimg, size_t pos, int big_endian);
int fimg_set_uint_at (file_image *pimg, unsigned int val, size_t pos, int big_endian);
unsigned long long fimg_get_uquad_at (const file_image *pimg, size_t pos, int big_endian);
int fimg_set_uquad_at (file_image *pimg, unsigned long long val, size_t pos, int big_endian);

#define FIMG_POS_END ~((size_t) 0)

typedef struct pe_image {
  file_image *pimg;
  size_t start_pe;
  size_t size_pe;
  struct {
    unsigned short machine;
    unsigned short numsecs;
    unsigned int timestamp;
    unsigned int pointer2SymTab;
    unsigned int numSyms;
    unsigned short szOptHdr;
    unsigned short characteristics;
  } pe_filehdr;
  size_t optional_hdr_pos;
  size_t section_list;
  size_t section_list_sz; /* Each section entry has 40 bytes size.  */
  unsigned int is_64bit : 1;
  unsigned int is_bigendian : 1;
} pe_image;

pe_image *peimg_create (file_image *pimg);
pe_image *peimg_load (const char *fname);
void peimg_free (pe_image *ppeimg);
void peimg_show (pe_image *ppeimg, FILE *outfp);

void peimg_set_hdr_characeristics (pe_image *pe, unsigned short set, unsigned short mask);
void peimg_set_hdr_opt_dll_characteristics (pe_image *pe, unsigned short set, unsigned short mask);
void peimg_set_hdr_opt_subsystem (pe_image *pe, unsigned short subsystem);

#define PEIMG_GET_UCHAR(PEIMG, POS)  fimg_get_uchar_at ((PEIMG)->pimg, ((PEIMG)->start_pe + (POS)))
#define PEIMG_GET_USHORT(PEIMG, POS)  fimg_get_ushort_at ((PEIMG)->pimg, ((PEIMG)->start_pe + (POS)), (PEIMG)->is_bigendian)
#define PEIMG_GET_UINT(PEIMG, POS)  fimg_get_uint_at ((PEIMG)->pimg, ((PEIMG)->start_pe + (POS)), (PEIMG)->is_bigendian)
#define PEIMG_GET_UQUAD(PEIMG, POS)  fimg_get_uquad_at ((PEIMG)->pimg, ((PEIMG)->start_pe + (POS)), (PEIMG)->is_bigendian)

#define PEIMG_SET_UCHAR(PEIMG, POS, VAL)  fimg_set_uchar_at ((PEIMG)->pimg, (unsigned char) (VAL), ((PEIMG)->start_pe + (POS)))
#define PEIMG_SET_USHORT(PEIMG, POS, VAL)  fimg_set_ushort_at ((PEIMG)->pimg, (unsigned short) (VAL), ((PEIMG)->start_pe + (POS)), (PEIMG)->is_bigendian)
#define PEIMG_SET_UINT(PEIMG, POS, VAL)  fimg_set_uint_at ((PEIMG)->pimg, (unsigned int) (VAL), ((PEIMG)->start_pe + (POS)), (PEIMG)->is_bigendian)
#define PEIMG_SET_UQUAD(PEIMG, POS, VAL)  fimg_set_uquad_at ((PEIMG)->pimg, (unsigned long long) (VAL), ((PEIMG)->start_pe + (POS)), (PEIMG)->is_bigendian)

#endif
