#ifndef statecommand_hpp
#define statecommand_hpp

#include "Category.hpp"

#include <SFML/System/Time.hpp>

#include <functional>
#include <cassert>


namespace eng
{

class State;


struct StateCommand
{
    typedef std::function<void(State&, sf::Time)> Action;

    StateCommand();

    Action                              action;
    unsigned int                        category;
};

// Automatic downcasting from every SceneNode-derived class
template <typename StateObject, typename Function>
StateCommand::Action                    derivedAction(Function fn)
{
    return [=] (State& state, sf::Time dt)
    {
        // Check if cast is safe
        assert(dynamic_cast<StateObject*>(&state) != nullptr);

        // Downcast node and invoke function on it
        fn(static_cast<StateObject&>(state), dt);
    };
}

}

#endif
