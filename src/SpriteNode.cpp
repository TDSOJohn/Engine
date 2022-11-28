//
//  SpriteNode.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 25/01/2021.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#include "SpriteNode.hpp"

#include <SFML/Graphics/RenderTarget.hpp>


namespace eng
{

SpriteNode::SpriteNode(const sf::Texture& texture) :
    mSprite(texture)
{
}


SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect) :
    mSprite(texture, textureRect)
{
}

sf::FloatRect SpriteNode::getLocalBounds() const
{
    return mSprite.getLocalBounds();
}

void SpriteNode::setTextureRect(const sf::IntRect& rectIn)
{
    mSprite.setTextureRect(rectIn);
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

}
