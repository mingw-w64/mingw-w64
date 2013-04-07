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

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#include "examine_list.h"


Exm_List *
exm_list_append(Exm_List *l, void *data)
{
    Exm_List *iter;
    Exm_List *n;

    if (!data)
        return l;

    n = (Exm_List *)malloc(sizeof(Exm_List));
    if (!n)
        return l;

    n->data = data;
    n->next = NULL;

    if (!l)
        return n;

    iter = l;
    while (iter->next)
        iter = iter->next;

    iter->next = n;

    return l;
}

Exm_List *
exm_list_append_if_new(Exm_List *l, void *data, Exm_List_Cmp_Cb cmp_cb)
{
    Exm_List *iter;
    int append = 1;

    if (!data)
        return l;

    iter = l;
    while (iter)
    {
        if (cmp_cb(iter->data, data) == 0)
        {
            append = 0;
            break;
        }
        iter = iter->next;
    }

    if (append)
        l = exm_list_append(l, data);

    return l;
}

void
exm_list_free(Exm_List *l, Exm_List_Free_Cb free_cb)
{
    Exm_List *iter;

    if (!l)
        return;

    iter = l;
    while (iter)
    {
        Exm_List *n;

        if (iter->data)
            free_cb(iter->data);
        n = iter->next;
        free(iter);
        iter = n;
    }
}

int
exm_list_count(Exm_List *l)
{
    Exm_List *iter;
    int count = 0;

    if (!l)
        return 0;

    iter = l;
    while (iter)
    {
        count ++;
        iter = iter->next;
    }

    return count;
}
