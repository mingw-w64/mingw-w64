#include "mpdecimal.h"
#include <stdlib.h>
#include "malloc_fail.h"


/* Test allocation failures */
int alloc_count;
int alloc_fail;
int alloc_idx;

void *
mpd_malloc_count(size_t size)
{
	++alloc_count;
	return malloc(size);
}

void *
mpd_calloc_count(size_t nmemb, size_t size)
{
	++alloc_count;
	return calloc(nmemb, size);
}

void *
mpd_realloc_count(void *ptr, size_t size)
{
	++alloc_count;
	return realloc(ptr, size);
}


void *
mpd_malloc_fail(size_t size)
{

	if (++alloc_idx >= alloc_fail) {
		return NULL;
	}
	return malloc(size);
}

void *
mpd_calloc_fail(size_t nmemb, size_t size)
{
	if (++alloc_idx >= alloc_fail) {
		return NULL;
	}
	if (rand()%2) {
		return calloc(nmemb, size);
	}
	else {
		return mpd_callocfunc_em(nmemb, size);
	}
}

void *
mpd_realloc_fail(void *ptr, size_t size)
{
	if (++alloc_idx >= alloc_fail) {
		return NULL;
	}
	return realloc(ptr, size);
}

void
mpd_set_alloc_count(mpd_context_t *ctx)
{
	mpd_mallocfunc = mpd_malloc_count;
	mpd_callocfunc = mpd_calloc_count;
	mpd_reallocfunc = mpd_realloc_count;

	ctx->traps = MPD_Malloc_error;
	alloc_count = 0;
}

void
mpd_set_alloc_fail(mpd_context_t *ctx)
{
	mpd_mallocfunc = mpd_malloc_fail;
	mpd_callocfunc = mpd_calloc_fail;
	mpd_reallocfunc = mpd_realloc_fail;

	ctx->traps = 0;
	alloc_idx = 0;
}

void
mpd_set_alloc(mpd_context_t *ctx)
{
	mpd_mallocfunc = malloc;
	mpd_callocfunc = (rand()%2) ? calloc : mpd_callocfunc_em;
	mpd_reallocfunc = realloc;

	ctx->traps = MPD_Malloc_error;
}



