#include "mpdecimal.h"
#include <stdlib.h>
#include <windows.h>
#include "malloc_fail.h"


/* Test allocation failures */
int alloc_count;
int alloc_fail;
int alloc_idx;

static void * default_mpd_malloc (size_t size){
  return HeapAlloc(GetProcessHeap(),0,size);
}

static void * default_mpd_realloc (void *ptr, size_t size){
  if(size == 0) {
    HeapFree(GetProcessHeap(),0,ptr);
    return NULL;
  }
  return HeapReAlloc(GetProcessHeap(),0,ptr,size);
}

static void * default_mpd_calloc (size_t nmemb, size_t size){
  return HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,nmemb * size);
}

static void default_mpd_free (void *ptr){
  HeapFree(GetProcessHeap(),0,ptr);
}

void *
mpd_malloc_count(size_t size)
{
	++alloc_count;
	return default_mpd_malloc(size);
}

void *
mpd_calloc_count(size_t nmemb, size_t size)
{
	++alloc_count;
	return default_mpd_calloc(nmemb, size);
}

void *
mpd_realloc_count(void *ptr, size_t size)
{
	++alloc_count;
	return default_mpd_realloc(ptr, size);
}


void *
mpd_malloc_fail(size_t size)
{

	if (++alloc_idx >= alloc_fail) {
		return NULL;
	}
	return default_mpd_malloc(size);
}

void *
mpd_calloc_fail(size_t nmemb, size_t size)
{
	if (++alloc_idx >= alloc_fail) {
		return NULL;
	}
	return default_mpd_calloc(nmemb, size);
}

void *
mpd_realloc_fail(void *ptr, size_t size)
{
	if (++alloc_idx >= alloc_fail) {
		return NULL;
	}
	return default_mpd_realloc(ptr, size);
}

void
mpd_set_alloc_count(mpd_context_t *ctx)
{
	__mingw_dfp_get_globals()->mpd_mallocfunc = mpd_malloc_count;
	__mingw_dfp_get_globals()->mpd_callocfunc = mpd_calloc_count;
	__mingw_dfp_get_globals()->mpd_reallocfunc = mpd_realloc_count;
	__mingw_dfp_get_globals()->mpd_free = default_mpd_free;

	ctx->traps = MPD_Malloc_error;
	alloc_count = 0;
}

void
mpd_set_alloc_fail(mpd_context_t *ctx)
{
	__mingw_dfp_get_globals()->mpd_mallocfunc = mpd_malloc_fail;
	__mingw_dfp_get_globals()->mpd_callocfunc = mpd_calloc_fail;
	__mingw_dfp_get_globals()->mpd_reallocfunc = mpd_realloc_fail;
	__mingw_dfp_get_globals()->mpd_free = default_mpd_free;

	ctx->traps = 0;
	alloc_idx = 0;
}

void
mpd_set_alloc(mpd_context_t *ctx)
{
	__mingw_dfp_get_globals()->mpd_mallocfunc = default_mpd_malloc;
	__mingw_dfp_get_globals()->mpd_callocfunc = default_mpd_calloc;
	__mingw_dfp_get_globals()->mpd_reallocfunc = default_mpd_realloc;
	__mingw_dfp_get_globals()->mpd_free = default_mpd_free;

	ctx->traps = MPD_Malloc_error;
}



