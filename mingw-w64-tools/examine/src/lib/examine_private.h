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

#ifndef EXAMINE_PRIVATE_H
#define EXAMINE_PRIVATE_H

/***** Overload *****/

/*
 * WARNING
 *
 * Mofidy the value of EXM_OVERLOAD_COUNT and
 * EXM_OVERLOAD_COUNT_CRT when adding other overloaded
 * functions in overloads_instance
 */
#define EXM_OVERLOAD_COUNT 2
#define EXM_OVERLOAD_COUNT_CRT 4

typedef struct _Exm_Overload_Data_Alloc Exm_Overload_Data_Alloc;
typedef struct _Exm_Overload_Data_Free Exm_Overload_Data_Free;

typedef struct
{
    char *func_name_old;
    PROC  func_proc_old;
    PROC  func_proc_new;
} Exm_Overload;


extern Exm_Overload exm_overloads_instance[];


size_t exm_overload_data_alloc_size_get(Exm_Overload_Data_Alloc *da);
int exm_overload_data_alloc_nbr_free_get(Exm_Overload_Data_Alloc *da);
Exm_List *exm_overload_data_alloc_stack_get(Exm_Overload_Data_Alloc *da);
size_t exm_overload_data_free_size_get(Exm_Overload_Data_Free *df);

Exm_List *exm_overload_data_alloc_list(void);
Exm_List *exm_overload_data_free_list(void);
int exm_overload_data_alloc_list_count(void);
int exm_overload_data_free_list_count(void);


/***** Hook *****/

Exm_Overload *exm_hook_instance_overloads_get(void);
Exm_List *exm_hook_instance_stack_frames_get(void);


#endif /* EXAMINE_PRIVATE_H */
