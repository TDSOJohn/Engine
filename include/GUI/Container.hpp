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

        /// \brief Select a child
        /// - Checks if child is selectable,
        /// - deselects previous child
        /// - selects new one
        /// \param index The index of the child to select
        void                select(std::size_t index);

        /// \brief Select next child
        /// - checks if any child is selected, otherwise returns
        /// - selects next child
        void                selectNext();

        /// \brief Select previous child
        /// - checks if any child is selected, otherwise returns
        /// - selects previous child
        void                selectPrevious();

        /// \brief Check if any child is currently active
        /// \return True if any child is currently active, 0 otherwise
        bool                hasActive();

        void                activate(std::size_t index);

        /// \brief Return the local bounds of the Container.
        /// NOT THE BEST WAY
        sf::FloatRect           getLocalBounds() { return sf::FloatRect(0,0,0,0); }

        /// \brief Return the global bounds of the Container.
        /// NOT THE BEST WAY
        sf::FloatRect           getGlobalBounds() { return sf::FloatRect(0,0,0,0); }

        int                     checkComponentIntersection(int x, int y);

    private:
        std::vector<Component::Ptr>        mChildren;
        int                                mSelectedChild;
        int                                mActiveChild;
};

}

#endif /* Container_hpp */
