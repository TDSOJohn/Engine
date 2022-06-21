//
//  EmitterNode.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 17/07/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#include "EmitterNode.hpp"
#include "ParticleNode.hpp"
#include "CommandQueue.hpp"
#include "CommandIdentifiers.hpp"
#include "Command.hpp"


namespace eng
{

EmitterNode::EmitterNode(Particle::Type type):
    SceneNode(),
    mAccumulatedTime(sf::Time::Zero),
    mType(type),
    mParticleSystem(nullptr),
    mEmissionRate(30.f)
{
}

void EmitterNode::setEmissionRate(float dt)
{
    mEmissionRate = dt;
}

void EmitterNode::updateCurrent(sf::Time dt, GameCommandQueue& commands)
{
    if (mParticleSystem)
    {
        emitParticles(dt);
    }
    else
    {
        // Find particle node with the same type as emitter node
        auto finder = [this] (ParticleNode& container, sf::Time)
        {
            if (container.getParticleType() == mType)
                mParticleSystem = &container;
        };

        Command command;
        command.category = Category::ParticleSystem;
        command.action = derivedAction<ParticleNode>(finder);

        commands.push(command);
    }
}

void EmitterNode::emitParticles(sf::Time dt)
{
    const sf::Time interval = sf::seconds(1.f) / mEmissionRate;

    mAccumulatedTime += dt;

    while (mAccumulatedTime > interval)
    {
        mAccumulatedTime -= interval;
        mParticleSystem->addParticle(getWorldPosition());
    }
}

}
