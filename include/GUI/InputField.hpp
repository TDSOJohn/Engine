#ifndef inputfield_hpp
#define inputfield_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#include "ResourceIdentifiers.hpp"
#include "GUI/Component.hpp"


namespace eng
{
/// \class InputField
/// \brief Simple input field class.
/// When selected, the input field allows for user text to be entered.
/// Filtering can be applied, too: numbers only, letters only or all chars.
class InputField : public Component
{
public:
    /// Create std::shared_ptr<InputField> with InputField::Ptr syntax.
    typedef std::shared_ptr<InputField>     Ptr;
    typedef std::function<void()>           Callback;

    /// <table><tr><th>NumbersOnly</th><th>Only chars 48..57 are allowed</tr>
    /// <tr><th>LettersOnly</th><th>Only chars 65..90 and 97..122 are allowed</tr>
    /// <tr><th>Chars</th><th>All chars are allowed</tr></table>
    enum Filter
    {
        NumbersOnly,
        LettersOnly,
        Chars,
    };

    /// <table><tr><th>Normal</th><th>Input field has normal texture, no input is handled</tr>
    /// <tr><th>Selected</th><th>Input field has selected texture, no input is handled</tr>
    /// <tr><th>Pressed</th><th>Input field has active texture, input is handled</tr></table>
    enum Type
    {
        Normal,
        Selected,
        Pressed,
        ButtonCount
    };

public:
    InputField(const FontHolder& fonts, const TextureHolder& textures, Filter filter = Chars, const std::string& text = "Default Text");
    ~InputField();

    /// \brief Return true if the Component is selectable.
    /// Override with the correct return value when inheriting.
    virtual bool            isSelectable() const { return 1; };

    /// \brief Toggle the selection
    /// Calling this function selects the current Button
    virtual void            select();

    /// \brief Untoggle the selection
    /// Calling this function deselects the current Button
    virtual void            deselect();

    virtual void            activate();

    virtual void            deactivate();

    void                    setPosition(const sf::Vector2f& position);
    void                    setPosition(float px, float py);

    void                    setDefaultText(const std::string& str);
    void                    setDefaultText(int n);

    /// \brief Return the local bounds of the Button Sprite.
    sf::FloatRect           getLocalBounds() { return mSprite.getLocalBounds(); }

    /// \brief Return the global bounds of the Button Sprite.
    sf::FloatRect           getGlobalBounds() { return mSprite.getGlobalBounds(); }

    void                    handleEvent(const sf::Event& event);

private:
    std::string             inputString;
    sf::Text                inputText;

    Filter                  mFilter;

    Callback                mCallback;
    sf::Sprite              mSprite;

    bool                    mIsClickable;

private:
    void                    changeTexture(Type buttonType);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
}

#endif // inputfield_hpp
