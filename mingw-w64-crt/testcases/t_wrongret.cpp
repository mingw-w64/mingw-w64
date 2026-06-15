#include <iostream>
#include <vector>

// mingw-w64 headers
#include "libtest.h"

int F()
{

        std::vector<char> buffer; // this can be any container
        std::cout << std::endl;
        return 12345;
        std::cout << std::endl;
}

int main()
{
        mingw_test_init ();
        std::cout << F() << std::endl; // prints something other than 12345
}
