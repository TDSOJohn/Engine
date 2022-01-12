//
//  CommandQueue.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 23/01/2021.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef CommandQueue_hpp
#define CommandQueue_hpp

#include "Command.hpp"

#include <queue>


template <typename CommandType>
class CommandQueue
{
public:
    void                            push(const CommandType& command);
    CommandType                     pop();
    bool                            isEmpty() const;

private:
    std::queue<CommandType>         mQueue;
};

#include "CommandQueue.inl"
#endif /* CommandQueue_hpp */
