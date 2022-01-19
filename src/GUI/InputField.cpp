#include <SFML/Graphics/RectangleShape.hpp>

#include "ResourceHolder.hpp"
#include "GUI/InputField.hpp"

#include <iostream>
#include <sstream>


namespace eng
{

InputField::InputField(FontHolder& fonts, TextureHolder& textures, Filter Filter, const std::string& text):
    mFilter(Filter),
    mCallback(),
    mSprite(textures.get(Textures::Buttons)),
    description("", fonts.get(Fonts::Mono), 18),
    mIsToggle(false),
    mIsClickable(true)
{
    description.setFillColor(sf::Color::White);

    inputText.setFont(fonts.get(Fonts::Mono));
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
    changeTexture(Selected);
}

void InputField::deselect()
{
    Component::deselect();
    changeTexture(Normal);
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
    else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Backspace)
    {
        std::string temp = inputText.getString();
        temp.pop_back();
        inputText.setString(temp);
    }
}

void InputField::setPosition(const sf::Vector2f& position)
{
    description.setPosition(position);
    inputText.setPosition(position.x + 10.f, position.y + 60.f);
    mSprite.setPosition(position.x, position.y + 60.f);
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
    target.draw(description, states);
    target.draw(inputText, states);
}

void InputField::changeTexture(Type buttonType)
{
    sf::IntRect textureRect(0, 72 * buttonType, 137, 72);
    mSprite.setTextureRect(textureRect);
}

}
