/*
   Copyright (c) 2009 mingw-w64 project

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

#ifndef _LIBMANGLE_HXX
#define _LIBMANGLE_HXX

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Garbage collector elements.
 * Tracks allocated memory and points to the next element from the same context.
 * @see sGcCtx
 */
typedef void *pGcElem;

/**
 * Garbage collector context.
 * Tracks first and last of elements in gc context.
 * @see generate_gc()
 * @see release_gc()
 */
typedef struct sGcCtx {
  pGcElem head;                /**< Pointer to first gc element in context.*/
  pGcElem tail;                /**< Pointer to last gc element in context. */
} sGcCtx;

/**
 * Generic token instances.
 * Type of token determined by base descriptor in members.
 * Base descriptor header available in all members through type punning.
 * @see gen_tok()
 */
typedef void *pMToken;

/**
 * Releases memory tracked by context.
 * @param[in] gc Garbage collection context to work on.
 * @see generate_gc()
 */
void release_gc (sGcCtx *gc);

/**
 * Constructs a garbage collection context token.
 * @return Pointer to context.
 * @see release_gc()
 */
sGcCtx *generate_gc (void);

/**
 * Dumps pMToken to a file descriptor for debugging.
 * @param[in] fp File descriptor to print the token to.
 * @param[in] p pMToken chain to print.
 */
void dump_tok (FILE *fp, pMToken p);

/** 
 * Prints C++ name to file descriptor.
 * @param[in] fp Output file descriptor.
 * @param[in] p Token containing information about the C++ name.
 * @see decode_ms_name()
 */
void print_decl (FILE *fp, pMToken p);

/** 
 * Get pointer to decoded C++ name string.
 * Use free() to release returned string.
 * @param[in] r C++ name token.
 * @return pointer to decoded C++ name string.
 * @see decode_ms_name()
 */
char *sprint_decl (pMToken r);

/**
 * Decodes an MSVC export name.
 * @param[in] gc sGcCtx pointer for collecting memory allocations.
 * @param[in] name MSVC C++ mangled export string.
 * @see sprint_decl()
 * @see release_gc()
 * @see pMToken
 * @return Token containing information about the mangled string,
 * use release_gc() to free after use.
 */
pMToken decode_ms_name (sGcCtx *gc, const char *name);
char *encode_ms_name (sGcCtx *gc, pMToken tok);

#ifdef __cplusplus
}
#endif

#endif
