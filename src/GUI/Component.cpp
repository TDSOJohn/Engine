//
//  Component.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 08/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#include "GUI/Component.hpp"


namespace eng
{

Component::Component():
    mIsTogglable(false),
    mIsSelected(false),
    mIsActive(false)
{
}

Component::~Component()
{
}

void Component::setToggle(bool flag)
{
    mIsTogglable = flag;
}

bool Component::isSelected() const
{
    return mIsSelected;
}

void Component::select()
{
    mIsSelected = true;
}

void Component::deselect()
{
    mIsSelected = false;
}

bool Component::isActive() const
{
    return mIsActive;
}

void Component::activate()
{
    mIsActive = true;
    // If we are not a toggle then deactivate the button since we are just momentarily activated.
    if (!mIsTogglable)
        deactivate();
}

void Component::deactivate()
{
    mIsActive = false;
}

}
