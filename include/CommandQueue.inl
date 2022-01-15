//
//  CommandQueue.cpp
//  noGravitar
//
//  Created by Giovanni Basso on 23/01/2021.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

namespace eng
{

template <typename CommandType>
void CommandQueue<CommandType>::push(const CommandType& command)
{
    mQueue.push(command);
}

template <typename CommandType>
CommandType CommandQueue<CommandType>::pop()
{
    CommandType command = mQueue.front();
    mQueue.pop();
    return command;
}

template <typename CommandType>
bool CommandQueue<CommandType>::isEmpty() const
{
    return mQueue.empty();
}
}
