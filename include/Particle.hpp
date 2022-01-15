//
//  Particle.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 15/07/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>


namespace eng
{

struct Particle
{
    enum Type
    {
        Propellant,
        Smoke,
        ParticleCount
    };

    sf::Vector2f    position;
    sf::Color       color;
    sf::Time        lifetime;
};
}

#endif /* Particle_hpp */
