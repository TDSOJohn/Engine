//
//  GameEntity.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 16/08/2020.
//  Copyright © 2020 Giovanni Basso. All rights reserved.
//

#ifndef GameEntity_hpp
#define GameEntity_hpp

#include "SceneNode.hpp"
#include "Physics/RigidBody.hpp"


namespace eng
{

class GameEntity : public SceneNode, public RigidBody
{
public:
    explicit                    GameEntity(int hitpoints, float maxv = 0.f);

    int                         getHitpoints() const;
    void                        repair(int points);
    void                        damage(int points);
    void                        destroy();
    virtual void                remove();
    virtual bool                isDestroyed() const;
    void                        rotate(float angle);

protected:
    int                         mHitpoints;

protected:
    virtual void                updateCurrent(sf::Time dt, GameCommandQueue& commands);
};
}

#endif /* GameEntity_hpp */
