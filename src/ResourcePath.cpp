#include "ResourcePath.hpp"

#include <iostream>


std::string getResourcePath()
{
    std::stringstream ss;
    std::cout << "Entering serourcePath" << std::endl;

    #if(CMAKE_BUILD_TYPE == Release)
        #if(APPLE)
            CFBundleRef bundle = CFBundleGetMainBundle();
            CFURLRef bundleURL = CFBundleCopyBundleURL(bundle);
            char path[PATH_MAX];
            Boolean success = CFURLGetFileSystemRepresentation(bundleURL, TRUE, (UInt8 *)path, PATH_MAX);
            assert(success);
            CFRelease(bundleURL);
            ss << path << "/Contents/Resources/";
        #endif
    #else
        ss << "../Resources/";
    #endif

    std::cout << ss.str() << std::endl;

    return ss.str();
}
