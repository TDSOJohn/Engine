//
//  Container.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 08/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#include "GUI/Container.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <iostream>


namespace eng
{

Container::Container():
    mChildren(),
    mSelectedChild(-1),
    mActiveChild(-1)
{
}

void Container::pack(Component::Ptr component)
{
    mChildren.push_back(component);
    if(!hasSelection() && component->isSelectable())
        select(mChildren.size() - 1);
}

bool Container::isSelectable() const
{
    return false;
}

void Container::handleEvent(const sf::Event& event)
{
    //  Mouse movement hover doesn't depend on the Container state and is always active
    if(event.type == sf::Event::MouseMoved)
    {
        int index = checkComponentIntersection(event.mouseMove.x, event.mouseMove.y);

        if(index != -1)
        {
            //  If something else is selected, deselect it
            //  No need to check if object is selectable here
            if(hasSelection())
                select(mSelectedChild);
            select(index);
        }
    }
    //  If something is active
    else if(hasActive())
    {
        //  If a mouse button is pressed
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            mChildren[mActiveChild]->deactivate();
            mChildren[mSelectedChild]->deselect();
            mActiveChild = -1;
            mSelectedChild = -1;

            //  Get index of element being clicked in mChildren
            int index = checkComponentIntersection(event.mouseButton.x, event.mouseButton.y);

            //  If button is pressed inside a Component, activate it
            if(index != -1)
            {
                select(index);
                activate(index);
            }
        }
        else if(event.type == sf::Event::KeyReleased)
        {
            if( event.key.code == sf::Keyboard::Return
                || event.key.code == sf::Keyboard::Space
                || event.key.code == sf::Keyboard::Escape)
            {
                mChildren[mActiveChild]->deactivate();
                mActiveChild = -1;
            }
        }
        else
            mChildren[mActiveChild]->handleEvent(event);
    }
    //  If nothing is active but something is selected
    else if(!hasActive() && mSelectedChild != -1)
    {
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            mChildren[mSelectedChild]->deselect();
            mSelectedChild = -1;
            int index = checkComponentIntersection(event.mouseButton.x, event.mouseButton.y);

            if(index != -1)
                activate(index);
        } else if(event.type == sf::Event::KeyReleased)
        {
            if( event.key.code == sf::Keyboard::W
                || event.key.code == sf::Keyboard::Up
                || event.key.code == sf::Keyboard::Left)
                selectPrevious();

            if( event.key.code == sf::Keyboard::S
                || event.key.code == sf::Keyboard::Down
                || event.key.code == sf::Keyboard::Right)
                selectNext();

            if(event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
                activate(mSelectedChild);
        }
    }
    //  If nothing is active or selected
    else
    {
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            int index = checkComponentIntersection(event.mouseButton.x, event.mouseButton.y);

            if(index != -1)
                select(index);
        } else if(event.type == sf::Event::KeyReleased)
        {
            if( event.key.code == sf::Keyboard::W
                || event.key.code == sf::Keyboard::Up
                || event.key.code == sf::Keyboard::Left)
                select(0);

            if( event.key.code == sf::Keyboard::S
                || event.key.code == sf::Keyboard::Down
                || event.key.code == sf::Keyboard::Right)
                select(0);
        }
    }
std::cout << mSelectedChild << "\t" << mActiveChild << std::endl;
}

int Container::checkComponentIntersection(int x, int y)
{
    for(int i = 0; i < mChildren.size(); ++i)
    {
        sf::FloatRect buttonBounds = mChildren[i]->getGlobalBounds();
        sf::Vector2f pos = mChildren[i]->getPosition();
        if( (buttonBounds.left + pos.x <= x) &&
            (buttonBounds.left + buttonBounds.width + pos.x >= x) &&
            (buttonBounds.top + pos.y <= y) &&
            (buttonBounds.top + buttonBounds.height + pos.y >= y))
                return i;
    }
    return -1;
}

void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for (const Component::Ptr& child : mChildren)
    {
        target.draw(*child, states);
    }
}


bool Container::hasSelection() const
{
    return mSelectedChild >= 0;
}


void Container::select(std::size_t index)
{
    if(mChildren[index]->isSelectable())
    {
        if(hasSelection())
            mChildren[mSelectedChild]->deselect();
        mChildren[index]->select();
        mSelectedChild = index;
    }
}


void Container::selectNext()
{
    if(!hasSelection())
        return;
    // Search next component that is selectable
    int next = mSelectedChild;
    do
        next = (next + 1) % mChildren.size();
    while(!mChildren[next]->isSelectable());
    // Select that component
    select(next);
}


void Container::selectPrevious()
{
    if(!hasSelection())
        return;
    // Search previous component that is selectable
    int prev = mSelectedChild;
    do
        prev = (prev + mChildren.size() - 1) % mChildren.size();
    while (!mChildren[prev]->isSelectable());
    // Select that component
    select(prev);
}

bool Container::hasActive()
{
    return mActiveChild != -1;
}

void Container::activate(std::size_t index)
{
    if(hasActive())
        mChildren[mActiveChild]->deactivate();
    mChildren[index]->activate();
    std::cout << mChildren[index]->isTogglable() << std::endl;
    if(mChildren[index]->isTogglable())
        mActiveChild = index;
}

}
