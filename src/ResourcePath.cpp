#include "ResourcePath.hpp"


namespace eng
{

std::string getResourcePath()
{
    std::stringstream ss;

    #if(CMAKE_BUILD_TYPE == Release)
        #if(APPLE)
            CFBundleRef bundle = CFBundleGetMainBundle();
            CFURLRef bundleURL = CFBundleCopyBundleURL(bundle);
            char path[PATH_MAX];
            Boolean success = CFURLGetFileSystemRepresentation(bundleURL, TRUE, (UInt8 *)path, PATH_MAX);
            assert(success);
            CFRelease(bundleURL);
            ss << path << "/Contents/Resources/";
        #else
            ss << "../Resources/";
        #endif
    #else
        ss << "../Resources/";
    #endif

    return ss.str();
}

}
