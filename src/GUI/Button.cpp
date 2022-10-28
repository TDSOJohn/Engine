//
//  Button.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 09/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#include "GUI/Button.hpp"

#include "Utility.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>


namespace eng
{

Button::Button(const FontHolder& fonts, const TextureHolder& textures):
    mCallback(),
    mSprite(textures.get(Textures::Buttons)),
    mText("", fonts.get(Fonts::Mono), 18)
{
    changeTexture(Normal);

    sf::FloatRect bounds = mSprite.getLocalBounds();
    mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
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
}

void Button::activate()
{
    Component::activate();
/*    // If we are toggle then we should show that the button is pressed and thus "toggled".
    if(mIsTogglable)
        changeTexture(Pressed);
    else
*/        Button::deactivate();

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

void Button::changeTexture(Type buttonType)
{
    sf::IntRect textureRect(0, 72 * buttonType, 137, 72);
    mSprite.setTextureRect(textureRect);
}

}
