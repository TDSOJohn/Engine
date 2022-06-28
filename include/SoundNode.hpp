//
// Created by Giovanni Basso on 28/06/22.
//

#ifndef NOGRAVITAR_SOUNDNODE_HPP
#define NOGRAVITAR_SOUNDNODE_HPP

#include <SceneNode.hpp>
#include <ResourceIdentifiers.hpp>


namespace eng
{

class SoundPlayer;

class SoundNode : public SceneNode
{
public:
    explicit				SoundNode(SoundPlayer& player);
    void					playSound(SoundEffect::ID sound, sf::Vector2f position);

    virtual unsigned int	getCategory() const;


private:
    SoundPlayer&			mSounds;
};

}

#endif //NOGRAVITAR_SOUNDNODE_HPP
