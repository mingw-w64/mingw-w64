#ifndef MALLOC_FAIL_H
#define MALLOC_FAIL_H


#include <stdio.h>

extern int alloc_count;
extern int alloc_fail;
extern int alloc_idx;
void *mpd_malloc_count(size_t size);
void *mpd_calloc_count(size_t nmemb, size_t size);
void *mpd_realloc_count(void *ptr, size_t size);
void *mpd_malloc_fail(size_t size);
void *mpd_calloc_fail(size_t nmemb, size_t size);
void *mpd_realloc_fail(void *ptr, size_t size);

void mpd_set_alloc_count(mpd_context_t *ctx);
void mpd_set_alloc_fail(mpd_context_t *ctx);
void mpd_set_alloc(mpd_context_t *ctx);


#endif


