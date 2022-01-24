//
//  Component.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 08/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <memory>


namespace sf
{
    class Event;
}


namespace eng
{

/// \class Component
/// \brief Simple virtual GUI Component class.
/// Inherits from sf::Drawable, sf::Transformable, sf::NonCopyable
class Component:    public sf::Drawable,
                    public sf::Transformable,
                    public sf::NonCopyable
{
    public:
        typedef std::shared_ptr<Component> Ptr;

    public:
        /// \brief Constructor.
        /// The Component always starts deselected and deactivated.
                        Component();

        virtual         ~Component();

        /// \brief Return true if the Component is selectable.
        /// Override with the correct return value when inheriting.
        virtual bool    isSelectable() const = 0;

        /// \brief Return true if the Component is selected.
        /// Override with the correct return value when inheriting.
        bool            isSelected() const;

        /// \brief Return true if the Component is selectable.
        /// Override with the correct return value when inheriting.
        virtual void    select();

        /// \brief Return true if the Component is selectable.
        /// Override with the correct return value when inheriting.
        virtual void    deselect();

        virtual bool    isActive() const;
        virtual void    activate();
        virtual void    deactivate();

        /// \brief Return the local bounds of the Button Sprite.
        virtual sf::FloatRect           getLocalBounds() = 0;

        /// \brief Return the global bounds of the Button Sprite.
        virtual sf::FloatRect           getGlobalBounds() = 0;

        virtual void    handleEvent(const sf::Event& event) = 0;

    protected:
        bool mIsSelected;
        bool mIsActive;
};

}

#endif /* Component_hpp */
