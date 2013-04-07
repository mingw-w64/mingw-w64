/* Examine - a tool for memory leak detection on Windows
 *
 * Copyright (C) 2012-2013 Vincent Torri.
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EXM_PE_H
#define EXM_PE_H

typedef struct _Exm_Pe_File Exm_Pe_File;

Exm_Pe_File *exm_pe_file_new(const char *filename);
void exm_pe_file_free(Exm_Pe_File *file);
Exm_List *exm_pe_modules_list_get(Exm_List *l, const char *filename);
char *exm_pe_dll_path_find(const char *filename);

#endif /* EXM_PE_H */
