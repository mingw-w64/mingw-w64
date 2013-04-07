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

#ifndef EXAMINE_LOG_H
#define EXAMINE_LOG_H

#include <stdarg.h>

typedef enum
{
    EXM_LOG_LEVEL_ERR,
    EXM_LOG_LEVEL_WARN,
    EXM_LOG_LEVEL_INFO,
    EXM_LOG_LEVEL_DBG,
    EXM_LOG_LEVEL_LAST
} Exm_Log_Level;

#define EXM_LOG(l, fmt, ...) \
    exm_log_print(l, fmt, ## __VA_ARGS__)

#define EXM_LOG_ERR(fmt, ...) \
    EXM_LOG(EXM_LOG_LEVEL_ERR, fmt, ## __VA_ARGS__)

#define EXM_LOG_WARN(fmt, ...) \
    EXM_LOG(EXM_LOG_LEVEL_WARN, fmt, ## __VA_ARGS__)

#define EXM_LOG_INFO(fmt, ...) \
    EXM_LOG(EXM_LOG_LEVEL_INFO, fmt, ## __VA_ARGS__)

#define EXM_LOG_DBG(fmt, ...) \
    EXM_LOG(EXM_LOG_LEVEL_DBG, fmt, ## __VA_ARGS__)

void exm_log_print_cb_stderr(Exm_Log_Level level,
                             const char *fmt,
                             void *data,
                             va_list args);

void exm_log_print_cb_stdout(Exm_Log_Level level,
                             const char *fmt,
                             void *data,
                             va_list args);

void exm_log_print(Exm_Log_Level level, const char *fmt, ...);

#endif /* EXAMINE_LOG_H */
