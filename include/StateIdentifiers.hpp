//
//  StateIdentifiers.hpp
//  noGravitar
//
//  Created by Giovanni Basso on 09/06/21.
//  Copyright © 2021 Giovanni Basso. All rights reserved.
//

#ifndef StateIdentifiers_h
#define StateIdentifiers_h


namespace eng
{

namespace States
{
    enum ID
    {
        None,
        Title,
        Menu,
        Game,
        Arena,
        Loading,
        Pause,
        Dialogue,
        Settings,
        GameOver
    };
}

}

#endif /* StateIdentifiers_h */
