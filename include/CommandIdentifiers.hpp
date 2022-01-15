//
//  CommandIdentifiers.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 10/09/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef CommandIdentifiers_hpp
#define CommandIdentifiers_hpp

namespace eng
{

class Command;
class StateCommand;

template <typename CommandType>
class CommandQueue;

typedef CommandQueue<Command>       GameCommandQueue;
typedef CommandQueue<StateCommand>  StateCommandQueue;

}

#endif
