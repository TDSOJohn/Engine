
set (SRC
    Utility.cpp
	Physics/RigidBody.cpp
    GUI/Button.cpp
	GUI/Component.cpp
	GUI/Container.cpp
	GUI/Label.cpp)

add_library(engine ${SRC})

# anybody linking to MathFunctions needs to include the current source directory
# except MathFunctions itself
target_include_directories(engine
            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
            )
