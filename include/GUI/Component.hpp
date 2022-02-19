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
/// Inherits from <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php">sf::Drawable</a>,
/// <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Transformable.php">sf::Transformable</a>,
/// <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1NonCopyable.php">sf::NonCopyable</a>.
class Component:    public sf::Drawable,
                    public sf::Transformable,
                    public sf::NonCopyable
{
    public:
        /// Create std::shared_ptr<Component> with Component::Ptr syntax.
        typedef std::shared_ptr<Component> Ptr;

    public:
        /// \brief Constructor.
        /// The Component always starts deselected, deactivated and not togglable.
                                Component();

        virtual                 ~Component();

        /// \brief Return true if the Component is selectable.
        /// Override with the correct return value when inheriting.
        virtual bool            isSelectable() const = 0;

        /// \brief Set if component it togglable.
        /// \param flag A bool value containing the value to set the internal togglable flag to.
        void                    setToggle(bool flag);

        /// \brief Return true if the Component is togglable.
        /// A togglable Component keeps the Active state until deactivate() is called.
        /// A non togglable Component immediately deactivates after being activated.
        bool                    isTogglable() { return mIsTogglable; }

        /// \brief Return true if the Component is selected.
        bool                    isSelected() const;

        /// \brief Select the Component.
        virtual void            select();

        /// \brief Deselect the Component.
        virtual void            deselect();

        /// \brief Return true if the Component is active, false otherwise.
        virtual bool            isActive() const;

        /// \brief Activate the Component.
        /// It automatically deactivates after activation if the Component is not togglable.
        virtual void            activate();

        /// \brief Deactivate the Component.
        /// Does nothing if Component is not togglable.
        virtual void            deactivate();

        /// \brief Return the local bounds of the Component as <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Rect.php">sf::FloatRect</a>.
        /// Override with the correct bounds.
        virtual sf::FloatRect   getLocalBounds() = 0;

        /// \brief Return the global bounds of the Component as <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Rect.php">sf::FloatRect</a>.
        /// Override with the correct bounds.
        virtual sf::FloatRect   getGlobalBounds() = 0;

        /// \brief handle a <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Event.php">sf::Event</a>.
        /// Override with the correct behaviour.
        virtual void            handleEvent(const sf::Event& event) = 0;

    protected:
        bool                    mIsTogglable;
        bool                    mIsSelected;
        bool                    mIsActive;
};

}

#endif /* Component_hpp */
