# Maybe investigate the use of EXCLUDE_FROM_ALL to have cmake compile every example or test
# but not have them built as part of the normal build process.

# WHY IS CMP0048 a problem here???
# project(engine VERSION 0.1.1)

project(engine)
cmake_minimum_required(VERSION 3.9)

# set c++17 standard, require it and only allow the --std=c++17 flag
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_BUILD_TYPE Debug)

# create a cached variable to choose if identifiers are default-built or from files in the Resources folder
set(BuildDefaultIdentifiers false CACHE BOOL "Set FALSE to build the Resource Identifiers from files")

# create a variable that stores the path to the Resources/ folder
set(ResourcesFolderPath ../Resources/ CACHE FILEPATH "Set the path to the Resources/ folder")

# Generate config.h with:
# version number
# CMAKE_BUILD_TYPE
# CMAKE_HOST_SYSTEM_NAME
configure_file(config.h.in config.h)

# IMPORTANT:
# to generate ResourceIdentifiers.hpp from .json
# https://stackoverflow.com/questions/67025026/best-practice-to-run-a-prebuild-step-with-cmake
add_executable(resourceIdentifiersGenerator ${CMAKE_CURRENT_SOURCE_DIR}/src/buildtime/ResourceIdentifiersGenerator.cpp)
add_custom_command(
    OUTPUT ResourceIdentifiers.hpp
    COMMAND "./resourceIdentifiersGenerator"
    DEPENDS
        resourceIdentifiersGenerator
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)
add_custom_target(generator ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/ResourceIdentifiers.hpp)

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

# set(JSON_BuildTests OFF CACHE INTERNAL "")

# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/externals/json")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/json")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

include_directories(engine PUBLIC "${PROJECT_BINARY_DIR}")

set (SRC
    src/Animation.cpp
    src/Camera.cpp
    src/Command.cpp
    src/EmitterNode.cpp
    src/GameEntity.cpp
	src/MusicPlayer.cpp
    src/ParticleNode.cpp
    src/PostEffect.cpp
    src/RandomUtilities.cpp
    src/ResourcePath.cpp
    src/SceneNode.cpp
    src/SoundNode.cpp
    src/SoundPlayer.cpp
    src/State.cpp
    src/StateCommand.cpp
    src/StateStack.cpp
    src/TextNode.cpp
    src/TileMap.cpp
    src/Utility.cpp
    src/GUI/Button.cpp
	src/GUI/Component.cpp
	src/GUI/Container.cpp
    src/GUI/InputField.cpp
	src/GUI/Label.cpp
    src/GUI/Slider.cpp
    src/Physics/RigidBody.cpp)

add_library(engine STATIC ${SRC})

# Link executable to required SFML libraries
target_link_libraries(engine sfml-graphics sfml-audio sfml-network sfml-window sfml-system) 

# ADD NLOHMANN_JSON WITH: nlohmann_json::nlohmann_json
