#include <iostream>

// mingw-w64 headers
#include "libtest.h"

int main() {
  mingw_test_init ();
  std::cout << "Hello!" << std::endl; return 0;
}
