//
//  Label.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 08/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef Label_hpp
#define Label_hpp

#include "Component.hpp"

#include "ResourceHolder.hpp"
#include "ResourceTypes.hpp"

#include <SFML/Graphics/Text.hpp>


namespace eng
{

class Label : public Component
{
    public:
        typedef std::shared_ptr<Label> Ptr;


    public:
                            Label(const std::string& text, Fonts::ID font_used, const FontHolder& fonts);

        virtual bool        isSelectable() const;
        void                setText(const std::string& text);

        virtual void        handleEvent(const sf::Event& event);

        /// \brief Return the local bounds of the Button Sprite.
        sf::FloatRect           getLocalBounds() { return mText.getLocalBounds(); }

        /// \brief Return the global bounds of the Button Sprite.
        sf::FloatRect           getGlobalBounds() { return mText.getGlobalBounds(); }

    private:
        void                draw(sf::RenderTarget& target, sf::RenderStates states) const;


    private:
        sf::Text            mText;
};

}

#endif /* Label_hpp */
