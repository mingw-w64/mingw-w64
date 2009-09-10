#include <iostream>
#include <vector>

int F()
{

        std::vector<char> buffer; // this can be any container
        std::cout << std::endl;
        return 12345;
        std::cout << std::endl;
}

int main()
{
        std::cout << F() << std::endl; // prints something other than 12345
}

