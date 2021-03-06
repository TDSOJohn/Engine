//
//  Label.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 08/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#include "GUI/Label.hpp"
#include "Utility.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


namespace eng
{

Label::Label(const std::string& text, const FontHolder& fonts):
    mText(text, fonts.get(Fonts::Mono), 16)
{
}


bool Label::isSelectable() const
{
    return false;
}


void Label::handleEvent(const sf::Event&)
{
}


void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText, states);
}


void Label::setText(const std::string& text)
{
    mText.setString(text);
}

}
