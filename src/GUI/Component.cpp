#include "GUI/Component.hpp"

#include <iostream>


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

void Component::setTogglable(bool flag)
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
