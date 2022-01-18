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

        virtual void    handleEvent(const sf::Event& event) = 0;

    private:
        bool mIsSelected;
        bool mIsActive;
};

}

#endif /* Component_hpp */
