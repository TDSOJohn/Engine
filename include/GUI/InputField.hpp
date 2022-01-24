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
    typedef std::shared_ptr<InputField>     Ptr;
    typedef std::function<void()>           Callback;

    enum Filter
    {
        NumbersOnly,
        LettersOnly,
        Chars,
    };

    enum Type
    {
        Normal,
        Selected,
        Pressed,
        ButtonCount
    };

public:
    InputField(FontHolder& fonts, TextureHolder& textures, Filter filter, const std::string& text = "Default Text");
    ~InputField();

    /// \brief Return true if the Component is selectable.
    /// Override with the correct return value when inheriting.
    virtual bool    isSelectable() const { return 1; };

    /// \brief Toggle the selection
    /// Calling this function selects the current Button
    virtual void            select();

    /// \brief Untoggle the selection
    /// Calling this function deselects the current Button
    virtual void            deselect();

    virtual void            activate();

    virtual void            deactivate();

    void setPosition(const sf::Vector2f& position);
    void setPosition(float px, float py);

    void setDefaultText(const std::string& str);
    void setDefaultText(int n);

    /// \brief Return the local bounds of the Button Sprite.
    sf::FloatRect           getLocalBounds() { return mSprite.getLocalBounds(); }

    /// \brief Return the global bounds of the Button Sprite.
    sf::FloatRect           getGlobalBounds() { return mSprite.getGlobalBounds(); }

    void handleEvent(const sf::Event& event);

private:
    std::string             inputString;
    sf::Text                description;
    sf::Text                inputText;

    Filter                  mFilter;

    Callback                mCallback;
    sf::Sprite              mSprite;

    bool                    mIsToggle;
    bool                    mIsClickable;

private:
    void                    changeTexture(Type buttonType);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
}

#endif // inputfield_hpp
