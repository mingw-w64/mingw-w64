/*
   Copyright (c) 2009-2016  mingw-w64 project

   Contributing authors: Kai Tietz, Jonathan Yong

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/
/*! \def GET_CHAR(CTX)
    \brief Get currently marked character from \a CTX.
    
    Get character from at current possition via \a CTX.
*/
/*! \def INC_CHAR(CTX)
     \brief Increments \a ctx position.
     
     Move marker to next character if it is currently not the last via \a CTX.
*/
/*! \def DEC_CHAR(CTX)
     \brief Decrements \a ctx position.
     
     Move marker to previous character if it is currently not the first via \a CTX.
*/
/*! \def SKIP_CHAR(CTX,LEN)
     \brief Increments \a CTX position by LEN
     
     Increments \a CTX marker by LEN characters, points to last character if
     marker is moved out of bounds.
*/

#ifndef _M_MS_HXX
#define _M_MS_HXX

#include "m_token.h"

#define ENCODING_TYPE_MS	1

/**
 * z-buffer for decoded names, decoded 
 * templates args and decoded args.
 * @see sMSCtx
 * @see get_zbuf_name()
 */
typedef struct sCached {
  int count;                       /**< uMToken pointers in array count. */
  uMToken *arr[10];                /**< Array of pointers to recently decoded tokens. */
} sCached;

typedef struct sMSCtx {
  libmangle_gc_context_t *gc;
  const char *name;                /**< MSVC export name. */
  const char *end;                 /**< Last character in the export name. */
  const char *pos;                 /**< Export name processing position marker. */
  int err;                         /**< Error codes. Zero indicates success. */
  int fExplicitTemplateParams;     /**< Indicates that explicit template parameters are used. */
  int fGetTemplateArgumentList;    /**< Indicates that the template argument list should be used. */
  sCached *pZNameList;             /**< z-buffer of decoded names. */
  sCached *pTemplateArgList;       /**< z-buffer of decoded template arguments. */
  sCached *pArgList;               /**< z-buffer if decoded arguments. */
} sMSCtx;

#define GET_CHAR(CTX)	((CTX)->pos == (CTX)->end ? 0 : (CTX)->pos[0])
#define INC_CHAR(CTX)	do { if ((CTX)->pos != (CTX)->end) (CTX)->pos++; } while (0)
#define DEC_CHAR(CTX)   do { if ((CTX)->pos != (CTX)->name) (CTX)->pos--; } while (0)
#define SKIP_CHAR(CTX,LEN) do { (CTX)->pos += (LEN); if ((CTX)->pos > (CTX)->end) (CTX)->pos=(CTX)->end; } while (0)

/** 
 * Decodes an MSVC export name.
 * @param[in] gc sGcCtx pointer for collecting memory allocations.
 * @param[in] name MSVC C++ mangled export string.
 * @see libmangle_sprint_decl()
 * @see libmangle_release_gc()
 * @see uMToken
 * @return Token containing information about the mangled string, 
 * use libmangle_release_gc() to free after use.
 */
uMToken *libmangle_decode_ms_name (libmangle_gc_context_t *gc, const char *name);
char *libmangle_encode_ms_name (libmangle_gc_context_t *gc, uMToken *tok);

#endif
