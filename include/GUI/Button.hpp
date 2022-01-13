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
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <string>
#include <memory>
#include <functional>


namespace GUI
{
/// \class Button
/// \brief Simple Button class.
class Button : public Component
{
public:
    typedef std::shared_ptr<Button>     Ptr;
    typedef std::function<void()>       Callback;

    enum Type
    {
        Normal,
        Selected,
        Pressed,
        ButtonCount
    };

public:
    /// \brief Constructor.
    /// \param fonts A FontHolder reference to get fonts from.
    /// \param textures A TextureHolder reference to get textures from.
                            Button(const FontHolder& fonts, const TextureHolder& textures);

    /// \brief Call to set the callback function.
    /// \param callback A [std::function](https://en.cppreference.com/w/cpp/utility/functional/function) parameter pointing to the function to be called
    void                    setCallback(Callback callback);

    /// \brief Set button text.
    /// \param text A std::string containing the text.
    void                    setText(const std::string& text);

    /// \brief Set toggle status of the button.
    /// \param flag A bool value containing the value to set the toggle to.
    void                    setToggle(bool flag);

    /// \brief Get selectable value
    /// \return A bool reppresenting if the button is selectable
    virtual bool            isSelectable() const;

    /// \brief Toggle the selection
    /// Calling this function selects the current GUI::Button
    virtual void            select();

    /// \brief Untoggle the selection
    /// Calling this function deselects the current GUI::Button
    virtual void            deselect();

    virtual void            activate();

    virtual void            deactivate();

    /// \brief Have the Button handle a sf::Event
    /// \param event A sf::Event as the input event to process
    virtual void            handleEvent(const sf::Event& event);


private:
    virtual void            draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void                    changeTexture(Type buttonType);

private:
    Callback                mCallback;
    sf::Sprite              mSprite;
    sf::Text                mText;
    bool                    mIsToggle;
};

}

#endif /* Button_hpp */
