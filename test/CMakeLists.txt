cmake_minimum_required(VERSION 3.14)

project(engine_test VERSION 0.1.0)

# set c++17 standard, require it and only allow the --std=c++17 flag
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_OSX_DEPLOYMENT_TARGET 10.12)

set(CMAKE_BUILD_TYPE Debug)
message(${CMAKE_BUILD_TYPE})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include/")

add_executable(engine_test main.cpp)

target_link_libraries(engine_test "${CMAKE_CURRENT_SOURCE_DIR}/../build/libengine.a")
