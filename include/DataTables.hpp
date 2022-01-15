//
//  DataTables.hpp
//  Engine
//

#ifndef DataTables_hpp
#define DataTables_hpp

#include "ResourceIdentifiers.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>
#include <functional>


//class Spaceship;

namespace eng
{

struct Direction
{
    Direction(float angle, float distance):
        angle(angle),
        distance(distance)
    {}

    float angle;
    float distance;
};

struct SpaceshipData
{
    int                     hitpoints;
    float                   speed;
    Textures::ID            texture;
    sf::IntRect             textureRect;
    sf::Time                fireInterval;
    std::vector<Direction>  directions;
    bool                    hasRollAnimation;
};

struct ProjectileData
{
    int                     damage;
    float                   speed;
    Textures::ID            texture;
    sf::IntRect             textureRect;
};
/*
struct PickupData
{
    std::function<void(Spaceship&)>
                            action;
    Textures::ID            texture;
    sf::IntRect             textureRect;
};
*/
struct ParticleData
{
    sf::Color               color;
    sf::Time                lifetime;
};
}

#endif // datatables_hpp
