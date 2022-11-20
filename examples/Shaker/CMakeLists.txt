cmake_minimum_required(VERSION 3.14)

project(shaker VERSION 0.1.0)

# set c++17 standard, require it and only allow the --std=c++17 flag
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# set(CMAKE_OSX_DEPLOYMENT_TARGET 10.12)

set(CMAKE_BUILD_TYPE Debug)

# Find SFML shared libraries
find_package(SFML 2.5
    COMPONENTS
    system window graphics REQUIRED
    )

# Platform check: better use CMAKE_HOST_SYSTEM_NAME
# Linux version
if(LINUX)
    include_directories(SFML/include)
# Might not be the best option, but works on mac
elseif(APPLE)
    include_directories("/usr/local/include/")
endif()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../include/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../build/")

add_executable(shaker Shaker.cpp)

target_link_libraries(shaker "${CMAKE_CURRENT_SOURCE_DIR}/../../build/libengine.a")
# Link executable to required SFML libraries
target_link_libraries(shaker sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
