//
// Created by Giovanni Basso on 28/06/22.
//

#include <SoundNode.hpp>
#include <SoundPlayer.hpp>

namespace eng
{

SoundNode::SoundNode(SoundPlayer& player):
    SceneNode(),
    mSounds(player)
{
}

void SoundNode::playSound(SoundEffect::ID sound, sf::Vector2f position)
{
    mSounds.play(sound, position);
}

unsigned int SoundNode::getCategory() const
{
    return Category::SoundEffect;
}

}