//
//  Button.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 09/06/21.
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
///
/// Button class
/// Inherits from GUI::Component
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
                            Button(const FontHolder& fonts, const TextureHolder& textures);
///Call to set the callback function
///Accepts a std::function parameter
    void                    setCallback(Callback callback);
    ///Set button text
    ///Accepts a std::string
    void                    setText(const std::string& text);
    ///Set toggle status of the button
    ///Accepts a bool value
    void                    setToggle(bool flag);
///Get selectable value
///Returns a bool reppresenting if the button is selectable
    virtual bool            isSelectable() const;
    ///Toogle the selection
    ///Calling this function selects the current GUI::Button
    virtual void            select();
    ///Untoogle the selection
    ///Calling this function deselects the current GUI::Button
    virtual void            deselect();

    virtual void            activate();
    virtual void            deactivate();
///Have the Button handle a sf::Event
///Accepts a sf::Event as the input event to process
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
