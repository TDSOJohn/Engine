#ifndef inputfield_hpp
#define inputfield_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#include "ResourceIdentifiers.hpp"
#include "GUI/Component.hpp"


namespace eng
{

class InputField : public Component
{
public:
    enum Type
    {
        NumbersOnly,
        LettersOnly,
        Chars,
    };

public:
    InputField(FontHolder& fonts, Type type, const std::string& text = "Default Text");
    ~InputField();

    void setPosition(const sf::Vector2f& position);
    void setPosition(float px, float py);

    void setDefaultText(const std::string& str);
    void setDefaultText(int n);

    /// \brief Return the local bounds of the Button Sprite.
    sf::FloatRect           getLocalBounds() { return inputRect.getLocalBounds(); }

    /// \brief Return the global bounds of the Button Sprite.
    sf::FloatRect           getGlobalBounds() { return inputRect.getGlobalBounds(); }

    void handleEvent(const sf::Event& event);

private:
    std::string         inputString;
    sf::Text            description;
    sf::Text            inputText;
    sf::RectangleShape  inputRect;

    Type                mType;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
}

#endif // inputfield_hpp
