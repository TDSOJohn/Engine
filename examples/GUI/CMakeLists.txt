cmake_minimum_required(VERSION 3.14)

project(gui_example VERSION 0.1.0)

# set c++17 standard, require it and only allow the --std=c++17 flag
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.12)

set(CMAKE_BUILD_TYPE Debug)
message(${CMAKE_BUILD_TYPE})

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

add_executable(gui_example GUIexample.cpp)

target_link_libraries(gui_example "${CMAKE_CURRENT_SOURCE_DIR}/../../build/libengine.a")
# Link executable to required SFML libraries
target_link_libraries(gui_example sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
