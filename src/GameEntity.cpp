//
//  GameEntity.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 16/08/2020.
//  Copyright © 2020 Giovanni Basso. All rights reserved.
//

#include "GameEntity.hpp"

#include <cassert>

#include <iostream>


namespace eng
{

GameEntity::GameEntity(int hitpoints, float maxv):
    RigidBody(maxv),
    mHitpoints(hitpoints)
{}

int GameEntity::getHitpoints() const
{
    return mHitpoints;
}

void GameEntity::repair(int points)
{
    assert(points > 0);

    mHitpoints += points;
}

void GameEntity::damage(int points)
{
    assert(points > 0);

    mHitpoints -= points;
}

void GameEntity::destroy()
{
    mHitpoints = 0;
}

void GameEntity::remove()
{
    destroy();
}

bool GameEntity::isDestroyed() const
{
    return(mHitpoints <= 0);
}

void GameEntity::updateCurrent(sf::Time dt, GameCommandQueue&)
{
    computeDirectedVelocity(this->getRotation());
    move(mDirectedVelocity * dt.asSeconds());
}

void GameEntity::rotate(float angle) {
    SceneNode::rotate(angle);
    computeDirectedVelocity(getRotation());
}

}
