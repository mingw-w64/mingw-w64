#include <windows.h>
#include <stdio.h>

#define TEST(cond, msg, ...) do { \
  if (!(cond)) { \
    fprintf(stderr, "%s:%d: " msg "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
    return 1; \
  } \
} while (0)

int main()
{
  LONG val;
  void *ptr;
  void *old;

  /* InterlockedIncrement */
  val = 0;
  TEST(InterlockedIncrement(&val) == 1, "InterlockedIncrement: expected return 1, got %ld", val);
  TEST(val == 1, "InterlockedIncrement: expected val 1, got %ld", val);
  TEST(InterlockedIncrement(&val) == 2, "InterlockedIncrement: expected return 2, got %ld", val);

  /* InterlockedDecrement */
  val = 2;
  TEST(InterlockedDecrement(&val) == 1, "InterlockedDecrement: expected return 1, got %ld", val);
  TEST(val == 1, "InterlockedDecrement: expected val 1, got %ld", val);
  TEST(InterlockedDecrement(&val) == 0, "InterlockedDecrement: expected return 0, got %ld", val);

  /* InterlockedExchange */
  val = 10;
  TEST(InterlockedExchange(&val, 20) == 10, "InterlockedExchange: expected old 10");
  TEST(val == 20, "InterlockedExchange: expected val 20, got %ld", val);

  /* InterlockedExchangeAdd */
  val = 100;
  TEST(InterlockedExchangeAdd(&val, 50) == 100, "InterlockedExchangeAdd: expected old 100");
  TEST(val == 150, "InterlockedExchangeAdd: expected val 150, got %ld", val);

  /* InterlockedCompareExchange - matching comparand */
  val = 42;
  TEST(InterlockedCompareExchange(&val, 99, 42) == 42, "InterlockedCompareExchange: expected old 42");
  TEST(val == 99, "InterlockedCompareExchange: expected val 99, got %ld", val);

  /* InterlockedCompareExchange - non-matching comparand */
  val = 99;
  TEST(InterlockedCompareExchange(&val, 0, 50) == 99, "InterlockedCompareExchange: expected old 99");
  TEST(val == 99, "InterlockedCompareExchange: expected val 99 (unchanged), got %ld", val);

  /* InterlockedCompareExchangePointer - matching comparand */
  ptr = (void *)1;
  old = InterlockedCompareExchangePointer(&ptr, (void *)2, (void *)1);
  TEST(old == (void *)1, "InterlockedCompareExchangePointer: expected old 1");
  TEST(ptr == (void *)2, "InterlockedCompareExchangePointer: expected new 2");

  /* InterlockedCompareExchangePointer - non-matching comparand */
  ptr = (void *)5;
  old = InterlockedCompareExchangePointer(&ptr, (void *)9, (void *)3);
  TEST(old == (void *)5, "InterlockedCompareExchangePointer: expected old 5");
  TEST(ptr == (void *)5, "InterlockedCompareExchangePointer: expected unchanged 5");

  /* InterlockedExchangePointer */
  ptr = (void *)10;
  old = InterlockedExchangePointer(&ptr, (void *)20);
  TEST(old == (void *)10, "InterlockedExchangePointer: expected old 10");
  TEST(ptr == (void *)20, "InterlockedExchangePointer: expected new 20");

  return 0;
}
