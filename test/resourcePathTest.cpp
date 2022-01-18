#include <iostream>

#include "ResourcePath.hpp"


int main()
{
    std::string resourcePath = eng::getResourcePath();
    std::cout << resourcePath << std::endl;

    return 0;
}
