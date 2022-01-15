//
//  EmitterNode.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 17/07/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef EmitterNode_hpp
#define EmitterNode_hpp

#include "SceneNode.hpp"
#include "Particle.hpp"


namespace eng
{

class ParticleNode;

class EmitterNode : public SceneNode
{
    public:
        explicit                EmitterNode(Particle::Type type);


    private:
        virtual void            updateCurrent(sf::Time dt, GameCommandQueue& commands);

        void                    emitParticles(sf::Time dt);


    private:
        sf::Time                mAccumulatedTime;
        Particle::Type            mType;
        ParticleNode*            mParticleSystem;
};
}

#endif /* EmitterNode_hpp */
