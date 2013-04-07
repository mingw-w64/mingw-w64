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

#include <stdlib.h>
#include <stdio.h>

#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

#include "examine_test_dll.h"

int main(void)
{
    HANDLE hDefaultProcessHeap;
    void *data;

    printf ("process launched...\n");

    hDefaultProcessHeap = GetProcessHeap();
    data = HeapAlloc(hDefaultProcessHeap, 0, 10);
    if (!data)
    {
        printf ("no heap alloc...\n");
        return -1;
    }
    HeapFree(hDefaultProcessHeap, 0, data);

    data = malloc(10);
    if (!data)
    {
        printf ("no malloc...\n");
        return -1;
    }
    /* free(data); */

    /* test with a DLL dependency */

    examine_test_dll();

    printf ("process finished...\n");

    return 0;
}
