#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>

#define TEST(a, b, msg, ...) do { \
  if ((a) != (b)) { \
    fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
    fprintf(stderr, msg, ##__VA_ARGS__); \
    fputc('\n', stderr); \
    return 1; \
  } \
} while (0)

#define TEST_MEM(ptr, byte, size, msg, ...) do { \
  size_t i; \
  for (i = 0; i < size; i++) { \
    if (((unsigned char *)ptr)[i] != (unsigned char)byte) { \
      fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
      fprintf(stderr, msg, ##__VA_ARGS__); \
      fputc('\n', stderr); \
      return 1; \
    } \
  } \
} while (0)

int main() {
  void *ptr;
  size_t size;


  /*
   * Surprisingly this malloc/_msize test is failing on msvcrt10.dll and msvcrt20.dll
   * because these two CRT libraries are buggy and return _msize rounded to even number.
   * So it means that also mingw-w64 _aligned_msize function (wrapper around _msize)
   * returns wrong value when using those two CRT libraries.
   */
  ptr = malloc(231);
  assert(ptr != NULL);
  size = _msize(ptr);
  TEST(size, 231, "_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);
  free(ptr);


  ptr = malloc(1000);
  assert(ptr != NULL);

  size = _msize(ptr);
  TEST(size, 1000, "_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  memset(ptr, 0x01, 1000);

  ptr = _recalloc(ptr, 100, 1);
  assert(ptr != NULL);

  size = _msize(ptr);
  TEST(size, 100, "_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  ptr = _recalloc(ptr, 200, 1);
  assert(ptr != NULL);

  size = _msize(ptr);
  TEST(size, 200, "_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  TEST_MEM(ptr, 0x01, 100, "_recalloc: 0x%p has incorrect byte 0x%02x at %lu", ptr, ((unsigned char *)ptr)[i], (unsigned long)i);
  TEST_MEM(ptr+100, 0x00, 100, "_recalloc: 0x%p has incorrect byte 0x%02x at %lu", ptr, ((unsigned char *)ptr)[i+100], (unsigned long)i+100);

  free(ptr);


  ptr = _aligned_malloc(100, 128);
  assert(ptr != NULL);
  TEST((uintptr_t)ptr % 128, 0, "_aligned_malloc: ptr 0x%p is not aligned", ptr);

  size = _aligned_msize(ptr, 128, 0);
  TEST(size, 100, "_aligned_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  memset(ptr, 0x01, 100);

  ptr = _aligned_realloc(ptr, 2000, 128);
  assert(ptr != NULL);
  TEST((uintptr_t)ptr % 128, 0, "_aligned_realloc: ptr 0x%p is not aligned", ptr);

  size = _aligned_msize(ptr, 128, 0);
  TEST(size, 2000, "_aligned_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  TEST_MEM(ptr, 0x01, 100, "_aligned_realloc: 0x%p has incorrect byte 0x%02x at %lu", ptr, ((unsigned char *)ptr)[i], (unsigned long)i);

  memset(ptr, 0x02, 2000);

  ptr = _aligned_realloc(ptr, 10, 128);
  assert(ptr != NULL);
  TEST((uintptr_t)ptr % 128, 0, "_aligned_realloc: ptr 0x%p is not aligned", ptr);

  size = _aligned_msize(ptr, 128, 0);
  TEST(size, 10, "_aligned_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  ptr = _aligned_recalloc(ptr, 20, 1, 128);
  assert(ptr != NULL);
  TEST((uintptr_t)ptr % 128, 0, "_aligned_recalloc: ptr 0x%p is not aligned", ptr);

  size = _aligned_msize(ptr, 128, 0);
  TEST(size, 20, "_aligned_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  TEST_MEM(ptr, 0x02, 10, "_aligned_realloc: 0x%p has incorrect byte 0x%02x at %lu", ptr, ((unsigned char *)ptr)[i], (unsigned long)i);
  TEST_MEM(ptr+10, 0x00, 10, "_aligned_recalloc: 0x%p has incorrect byte 0x%02x at %lu", ptr, ((unsigned char *)ptr)[i+10], (unsigned long)i+10);

  ptr = _aligned_recalloc(ptr, 3, 2, 128);
  assert(ptr != NULL);
  TEST((uintptr_t)ptr % 128, 0, "_aligned_recalloc: ptr 0x%p is not aligned", ptr);

  TEST_MEM(ptr, 0x02, 6, "_aligned_recalloc: 0x%p has incorrect byte 0x%02x at %lu", ptr, ((unsigned char *)ptr)[i], (unsigned long)i);

  _aligned_free(ptr);


  ptr = _aligned_offset_malloc(300, 128, 7);
  TEST((uintptr_t)(ptr+7) % 128, 0, "_aligned_offset_malloc: ptr 0x%p is not aligned", ptr);

  size = _aligned_msize(ptr, 128, 7);
  TEST(size, 300, "_aligned_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  ptr = _aligned_offset_realloc(ptr, 3000, 128, 7);
  assert(ptr != NULL);
  TEST((uintptr_t)(ptr+7) % 128, 0, "_aligned_offset_realloc: ptr 0x%p is not aligned", ptr);

  size = _aligned_msize(ptr, 128, 7);
  TEST(size, 3000, "_aligned_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  memset(ptr, 0x01, 3000);

  ptr = _aligned_offset_recalloc(ptr, 100, 1, 128, 7);
  assert(ptr != NULL);
  TEST((uintptr_t)(ptr+7) % 128, 0, "_aligned_offset_recalloc: ptr 0x%p is not aligned", ptr);

  size = _aligned_msize(ptr, 128, 7);
  TEST(size, 100, "_aligned_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  memset(ptr, 0x02, 100);

  ptr = _aligned_offset_recalloc(ptr, 110, 1, 128, 7);
  assert(ptr != NULL);
  TEST((uintptr_t)(ptr+7) % 128, 0, "_aligned_offset_recalloc: ptr 0x%p is not aligned", ptr);

  size = _aligned_msize(ptr, 128, 7);
  TEST(size, 110, "_aligned_msize: ptr 0x%p has incorrect size %lu", ptr, (unsigned long)size);

  TEST_MEM(ptr, 0x02, 100, "_aligned_offset_recalloc: 0x%p has incorrect byte 0x%02x at %lu", ptr, ((unsigned char *)ptr)[i], (unsigned long)i);
  TEST_MEM(ptr+100, 0x00, 10, "_aligned_offset_recalloc: 0x%p has incorrect byte 0x%02x at %lu", ptr, ((unsigned char *)ptr)[i+100], (unsigned long)i+100);

  _aligned_free(ptr);


  return 0;
}
