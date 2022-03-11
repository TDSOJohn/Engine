#include <SFML/Graphics/RectangleShape.hpp>

#include "ResourceHolder.hpp"
#include "GUI/InputField.hpp"

#include <iostream>
#include <sstream>


namespace eng
{

InputField::InputField(const sf::Font& font_in, const TextureHolder& textures, Filter Filter, const std::string& text):
    Component(),
    mFilter(Filter),
    mCallback(),
    mSprite(textures.get(Textures::Buttons)),
    mIsClickable(true)
{
    Component::setTogglable(true);

    inputText.setFont(font_in);
    inputText.setCharacterSize(18);
    inputText.setString(text);
    inputText.setFillColor(sf::Color::White);

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
        if(mFilter == NumbersOnly || mFilter == Chars)
        {
            if(input >= 48 && input <= 57)
                inputText.setString(inputText.getString() + input);
        }
        if(mFilter == LettersOnly || mFilter == Chars)
        {
            if((input >= 65 && input <= 90) || (input >= 97 && input <= 122))
                inputText.setString(inputText.getString() + input);
        }
    }
    else if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Backspace:
                std::string temp = inputText.getString();
                temp.pop_back();
                inputText.setString(temp);
                break;
        }
    }
}

void InputField::setPosition(const sf::Vector2f& position)
{
    inputText.setPosition(position.x + 10.f, position.y);
    mSprite.setPosition(position.x, position.y);
}

void InputField::setPosition(float px, float py)
{
    setPosition(sf::Vector2f(px, py));
}

void InputField::setDefaultText(const std::string& str)
{
    inputText.setString(str);
}

void InputField::setDefaultText(int n)
{
    std::stringstream ss;
    ss << n;
    inputText.setString(ss.str());
}

void InputField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
    target.draw(inputText, states);
}

void InputField::changeTexture(Type buttonType)
{
    sf::IntRect textureRect(0, 72 * buttonType, 137, 72);
    mSprite.setTextureRect(textureRect);
}

}
