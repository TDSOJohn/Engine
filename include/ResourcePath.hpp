
// CMAKE should define the variable to help with platform detection
//#define APPLE 1

#include "../build/config.h"

#if(CMAKE_BUILD_TYPE == Release)
    #if(APPLE)
        #include "CoreFoundation/CoreFoundation.h"
    #endif
    #include <unistd.h>
    #include <libgen.h>
#endif

#include <iostream>
#include <sstream>

namespace eng
{

//  If running on MacOS on Release mode, use CoreFoundation
//  to fetch the correct path
//  Otherwhise, simply use relative path to Resources folder
std::string getResourcePath();

}

//Compile with:
//      g++ --std=c++11 ResourcePath.cpp -framework CoreServices
