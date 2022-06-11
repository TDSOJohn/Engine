//
//  Command.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 23/01/2021.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include "Category.hpp"

#include <SFML/System/Time.hpp>

#include <functional>
#include <cassert>


namespace eng
{

class SceneNode;

/// \struct Command
/// \brief Simple Command struct.
///
///
struct Command
{
    /// \brief Define Action as a function object
    ///
    /// The function can be called on any game object represented by a scene node
    typedef std::function<void(SceneNode&, sf::Time)> Action;

    /// \brief Constructor.
    ///
    /// Default category is Category::None
    Command();

    Action                              action;

    /// \brief the category the command targets.
    ///
    /// Category is an enum defined in Category.hpp
    unsigned int                        category;
};

/// \brief Automatic downcasting from every SceneNode-derived class
template <typename GameObject, typename Function>
Command::Action                         derivedAction(Function fn)
{
    return [=] (SceneNode& node, sf::Time dt)
    {
        // Check if cast is safe
        assert(dynamic_cast<GameObject*>(&node) != nullptr);

        // Downcast node and invoke function on it
        fn(static_cast<GameObject&>(node), dt);
    };
}
}

#endif /* Command_hpp */
