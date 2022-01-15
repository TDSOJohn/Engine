#include "RandomUtilities.hpp"

#include <stdlib.h>


namespace eng
{

std::vector<sf::Vector2u> randomWalk(int t0_x, int t0_y, int iter)
{
    std::vector<sf::Vector2u> result;

    result.push_back(sf::Vector2u(t0_x, t0_y));
    for(int i = 0; i < iter; i++)
    {
        //  0 is north, 1 is east, 2 is south, 3 is west
        int direction = rand()%4;
        if(direction == 0)
            result.push_back(sf::Vector2u(result.back() + sf::Vector2u(0, 1)));
        else if(direction == 1)
            result.push_back(sf::Vector2u(result.back() + sf::Vector2u(1, 0)));
        else if(direction == 2)
            result.push_back(sf::Vector2u(result.back() + sf::Vector2u(0, -1)));
        else
            result.push_back(sf::Vector2u(result.back() + sf::Vector2u(-1, 0)));
    }
    return result;
}

}
