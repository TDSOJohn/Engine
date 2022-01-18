#include <iostream>

#include "Physics/Coordinates.hpp"


int main()
{
    eng::Coordinates c1(5, 5, 2, 2);
    eng::Coordinates c2(5, 5, 2, 2);
    eng::Coordinates c3(3, 7, 2, 2);

    std::cout << (c1 == c2) << std::endl;
    std::cout << !(c1 == c3) << std::endl;

    return(0);
}
