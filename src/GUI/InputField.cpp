#include <SFML/Graphics/RectangleShape.hpp>

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include "GUI/InputField.hpp"

#include <iostream>
#include <sstream>


namespace eng
{

InputField::InputField(const FontHolder& fonts, Fonts::ID font_used, const TextureHolder& textures, Textures::ID texture_used, const std::string& text, Filter Filter):
    Component(),
    mFilter(Filter),
    mCallback(),
    mSprite(textures.get(texture_used)),
    mIsClickable(true)
{
    Component::setTogglable(true);

    inputText.setFont(fonts.get(font_used));
    inputText.setCharacterSize(18);
    inputText.setString(text);
    inputText.setFillColor(sf::Color::White);

    inputString = text;

    changeTexture(Normal);

    sf::FloatRect bounds = mSprite.getLocalBounds();
    inputText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

InputField::~InputField()
{
}

void InputField::select()
{
    Component::select();
    if(!mIsActive)
        changeTexture(Selected);
}

void InputField::deselect()
{
    Component::deselect();
    if(!mIsActive)
        changeTexture(Normal);
}

void InputField::activate()
{
    Component::activate();

    // If we are toggle then we should show that the button is pressed and thus "toggled".
    changeTexture(Pressed);

    if (mCallback)
        mCallback();
}

void InputField::deactivate()
{
    Component::deactivate();

    if (mIsTogglable)
    {
        // Reset texture to right one depending on if we are selected or not.
        if (isSelected())
            changeTexture(Selected);
        else
            changeTexture(Normal);
    }
}

void InputField::handleEvent(const sf::Event& event)
{
    if(event.type == sf::Event::TextEntered)
    {
        char input = static_cast<char>(event.text.unicode);
        if(mFilter == NumbersOnly)
        {
            if(input >= 48 && input <= 57)
                addCharacter(input);
        }
        if(mFilter == LettersOnly)
        {
            if((input >= 65 && input <= 90) || (input >= 97 && input <= 122))
                addCharacter(input);
        }
        if(mFilter == Chars)
        {
            if(input >= 32 && input <= 126)
                addCharacter(input);
        }
    }
    else if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Backspace:
                removeCharacter();
        }
    }
}

void InputField::setPosition(const sf::Vector2f& position)
{
    inputText.setPosition(position.x + 10.f, position.y + 15.f);
    mSprite.setPosition(position.x, position.y);
}

void InputField::setPosition(float px, float py)
{
    setPosition(sf::Vector2f(px, py));
}

void InputField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
    target.draw(inputText, states);
}

void InputField::changeTexture(Type buttonType)
{
    sf::IntRect textureRect(0, 54 * buttonType, 180, 54);
    mSprite.setTextureRect(textureRect);
}

void InputField::addCharacter(char c)
{
    inputString += c;
    inputText.setString(inputText.getString() + c);
    while(inputText.getLocalBounds().width + 10 > mSprite.getLocalBounds().width)
        inputText.setString(inputText.getString().substring(1, inputText.getString().getSize() - 1));
}

void InputField::removeCharacter()
{
    if(inputString.size() > 0)
    {
        inputString.pop_back();
        inputText.setString(inputString);
        while(inputText.getLocalBounds().width + 10 > mSprite.getLocalBounds().width)
            inputText.setString(inputText.getString().substring(1, inputText.getString().getSize() - 1));
    }
}

}
