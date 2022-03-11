cmake_minimum_required(VERSION 3.9)

project(engine VERSION 0.1.0)

# set c++17 standard, require it and only allow the --std=c++17 flag
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.12)

set(CMAKE_BUILD_TYPE Release)
message(${CMAKE_BUILD_TYPE})

# Generate config.h with:
# version number
# CMAKE_BUILD_TYPE
# CMAKE_HOST_SYSTEM_NAME
configure_file(config.h.in config.h)

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

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")


set (SRC
    src/Animation.cpp
    src/Command.cpp
    src/EmitterNode.cpp
    src/GameEntity.cpp
    src/ParticleNode.cpp
    src/PostEffect.cpp
    src/RandomUtilities.cpp
    src/ResourcePath.cpp
    src/SceneNode.cpp
    src/State.cpp
    src/StateCommand.cpp
    src/StateStack.cpp
    src/TextNode.cpp
    src/TileMap.cpp
    src/Utility.cpp
	src/Physics/RigidBody.cpp
    src/GUI/Button.cpp
	src/GUI/Component.cpp
	src/GUI/Container.cpp
    src/GUI/InputField.cpp
	src/GUI/Label.cpp
    src/GUI/Slider.cpp)

add_library(engine STATIC ${SRC})

# Link executable to required SFML libraries
target_link_libraries(engine sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
