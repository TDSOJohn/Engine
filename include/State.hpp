//
//  State.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 25/01/2021.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>


namespace sf
{
    class RenderWindow;
}


namespace eng
{

class StateStack;
class Player;

class State
{
public:
    typedef std::unique_ptr<State>          Ptr;

    struct Context
    {
        Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player);
        Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts);

        sf::RenderWindow*                   window;
        TextureHolder*                      textures;
        FontHolder*                         fonts;
        Player*                             player;
    };


public:
                                            State(StateStack& stack, Context context);
    virtual                                 ~State();

    virtual void                            draw() = 0;
    virtual bool                            update(sf::Time dt) = 0;
    virtual bool                            handleEvent(const sf::Event& event) = 0;


protected:
    void                                    requestStackPush(States::ID stateID);

    void                                    requestStackPop();
    void                                    requestStateClear();

    Context                                 getContext() const;


private:
    StateStack*                             mStack;
    Context                                 mContext;
};

}

#endif /* State_hpp */
