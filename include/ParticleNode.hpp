//
//  ParticleNode.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 15/07/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef ParticleNode_hpp
#define ParticleNode_hpp

#include "SceneNode.hpp"
#include "ResourceIdentifiers.hpp"
#include "Particle.hpp"

#include <SFML/Graphics/VertexArray.hpp>

#include <deque>


namespace eng
{

class ParticleNode : public SceneNode
{
    public:
                                ParticleNode(Particle::Type type, const TextureHolder& textures);

        void                    addParticle(sf::Vector2f position);
        Particle::Type          getParticleType() const;
        virtual unsigned int    getCategory() const;


    private:
        virtual void            updateCurrent(sf::Time dt, GameCommandQueue& commands);
        virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

        void                    addVertex(float worldX, float worldY, float texCoordX, float texCoordY, const sf::Color& color) const;
        void                    computeVertices() const;


    private:
        std::deque<Particle>    mParticles;
        const sf::Texture&      mTexture;
        Particle::Type          mType;

        mutable sf::VertexArray mVertexArray;
        mutable bool            mNeedsVertexUpdate;
};
}

#endif /* ParticleNode_hpp */
