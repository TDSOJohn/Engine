//
//  Container.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 08/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef Container_hpp
#define Container_hpp

#include "Component.hpp"

#include <vector>
#include <memory>


namespace eng
{

class Container : public Component
{
    public:
        typedef std::shared_ptr<Container> Ptr;


    public:
                            Container();

        void                pack(Component::Ptr component);

        virtual bool        isSelectable() const;
        virtual void        handleEvent(const sf::Event& event);


    private:
        virtual void        draw(sf::RenderTarget& target, sf::RenderStates states) const;

        bool                hasSelection() const;
        void                select(std::size_t index);
        void                selectNext();
        void                selectPrevious();

        /// \brief Return the local bounds of the Button Sprite.
        /// NOT THE BEST WAY
        sf::FloatRect           getLocalBounds() { return sf::FloatRect(0,0,0,0); }

        /// \brief Return the global bounds of the Button Sprite.
        /// NOT THE BEST WAY
        sf::FloatRect           getGlobalBounds() { return sf::FloatRect(0,0,0,0); }

    private:
        std::vector<Component::Ptr>        mChildren;
        int                                mSelectedChild;
};

}

#endif /* Container_hpp */
