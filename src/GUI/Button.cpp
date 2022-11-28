//
//  Button.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 09/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#include "GUI/Button.hpp"

#include "Utility.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>


namespace eng
{

Button::Button(const FontHolder& fonts, Fonts::ID font_used, const TextureHolder& textures, Textures::ID texture_used, Type buttonType):
    mCallback(),
    mSprite(textures.get(texture_used)),
    mText("", fonts.get(font_used), 18)
{
    changeTexture(Normal);

    sf::FloatRect bounds = mSprite.getLocalBounds();
    mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);

    if(buttonType == Type::Togglable)
    {
        Component::setTogglable(true);
    }
}

void Button::setCallback(Callback callback)
{
    mCallback = std::move(callback);
}

void Button::setText(const std::string& text)
{
    mText.setString(text);
    centerOrigin(mText);
}

bool Button::isSelectable() const
{
    return true;
}

void Button::select()
{
    Component::select();
    if(!mIsActive)
        changeTexture(Selected);
}

void Button::deselect()
{
    Component::deselect();
    if(!mIsActive)
        changeTexture(Normal);
    else
        changeTexture(Toggled);
}

void Button::activate()
{
    Component::activate();
    // If we are toggle then we should show that the button is pressed and thus "toggled".
    if(mIsTogglable)
        changeTexture(Toggled);
    else
        Button::deactivate();

    if(mCallback)
        mCallback();
}

void Button::deactivate()
{
    Component::deactivate();

    // Reset texture to right one depending on if we are selected or not.
    if(isSelected())
        changeTexture(Selected);
    else
        changeTexture(Normal);
}

void Button::handleEvent(const sf::Event&)
{
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mSprite, states);
    target.draw(mText, states);
}

void Button::changeTexture(State buttonState)
{
    sf::IntRect textureRect(0, (mSprite.getTexture()->getSize().y / 3) * buttonState, mSprite.getTexture()->getSize().x, mSprite.getTexture()->getSize().y / 3);
    mSprite.setTextureRect(textureRect);
}

}
