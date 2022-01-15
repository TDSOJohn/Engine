//
//  Category.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 25/01/2021.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef Category_h
#define Category_h

namespace eng
{
// Entity/scene node category, used to dispatch commands
namespace Category
{
    enum Type
    {
        None                = 0,
        Background          = 1 << 0,
        Scene               = 1 << 1,
        PlayerShip          = 1 << 2,
        Npc                 = 1 << 3,
        EnemyShip           = 1 << 4,
        Pickup              = 1 << 5,
        AlliedProjectile    = 1 << 6,
        EnemyProjectile     = 1 << 7,
        Missile             = 1 << 8,
        ParticleSystem      = 1 << 9,

        Spaceship = PlayerShip | Npc | EnemyShip,
        Projectile = AlliedProjectile | EnemyProjectile | Missile,
    };
}
}

#endif /* Category_h */
