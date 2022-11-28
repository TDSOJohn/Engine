//
//  Button.hpp
//  noGravitar
//
//  Created by Giovanni Basso on
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include "Component.hpp"

#include "ResourceHolder.hpp"
#include "ResourceTypes.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


namespace eng
{
/// \class Button
/// \brief Simple Button class.
/// Clicking it causes the Callback to be called
class Button : public Component
{
public:
    /// Create std::shared_ptr<Button> with Button::Ptr syntax.
    typedef std::shared_ptr<Button>     Ptr;
    /// Create std::function<void()> with Button::Callback syntax.
    typedef std::function<void()>       Callback;

    enum Type
    {
        Default,
        Togglable,
        TypeCount
    };

    /// <table><tr><th>Normal</th><th>Button has normal texture</tr>
    /// <tr><th>Selected</th><th>Button has selected texture</tr>
    /// <tr><th>Pressed</th><th>Callback is called</tr></table>
    enum State
    {
        Normal,
        Selected,
        Toggled,
        StateCount
    };


public:
    /// \brief Constructor.
    /// \param fonts A FontHolder reference to get fonts from.
    /// \param textures A TextureHolder reference to get textures from.
                            Button(const FontHolder& fonts, Fonts::ID font_used, const TextureHolder& textures, Textures::ID texture_used, Type buttonType = Type::Default);

    /// \brief Call to set the callback function.
    /// \param callback A [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) parameter pointing to the function to be called
    void                    setCallback(Callback callback);

    /// \brief Set button text.
    /// \param text A std::string containing the text.
    void                    setText(const std::string& text);

    /// \brief Check if the Button if selectable.
    /// Override from Component::isSelectable.
    /// \return Always returns true.
    virtual bool            isSelectable() const;

    /// \brief Toggle the selection
    /// Calling this function selects the current Button
    virtual void            select();

    /// \brief Untoggle the selection
    /// Calling this function deselects the current Button
    virtual void            deselect();

    /// \brief Activate the Button.
    /// Calling this function activates the current Button.
    /// It immediately calls deactivate() automatically.
    /// This triggers a callback call if a callback [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) has been provided by a previous setCallback([std::function](https://en.cppreference.com/w/cpp/utility/functional/function)).
    virtual void            activate();

    /// \brief Deactivate the Button.
    /// Calling this function deactivates the current Button.
    virtual void            deactivate();

    /// \brief Have the Button handle a sf::Event
    /// \param event A sf::Event as the input event to process
    virtual void            handleEvent(const sf::Event& event);

    /// \brief Return the local bounds of the Button Sprite.
    sf::FloatRect           getLocalBounds() { return mSprite.getLocalBounds(); }

    /// \brief Return the global bounds of the Button Sprite.
    sf::FloatRect           getGlobalBounds() { return mSprite.getGlobalBounds(); }

private:
    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void                    changeTexture(State buttonState);

private:
    Callback                mCallback;
    sf::Sprite              mSprite;
    sf::Text                mText;
//    SoundPlayer&			mSounds;
};

}

#endif /* Button_hpp */
