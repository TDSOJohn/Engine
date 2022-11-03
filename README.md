A simple 2D game engine that uses [SFML](https://www.sfml-dev.org).</br>
It all started by trying to extract an engine from the [SFML game dev book's code](https://github.com/SFML/SFML-Game-Development-Book).</br>
Currently tested on macOS and Linux (Ubuntu 22.04).
## 
## Compiling from source
Download from GitHub and compile with:
```bash
cmake -S . -B build
cd build
cmake --build .
```
This creates a libengine.a file you can statically link to your project.

Compile your project and link to library with:
```
g++ --std=c++17 main.cpp ./build/libengine.a
```

Core Foundation is used to retrieve the current folder path in Release mode on macOS. Remember to link to CoreServices framework.
```
g++ --std=c++17 main.cpp ./build/libengine.a -framework CoreServices
```

A cmake variable (set it with -D, ccmake or cmake_gui) is used to tell the Engine wich folder to build ResourceIdentifiers.hpp from. Use ResourcesFolderPath to reference the Resources folder. This should have 1 subfolder for each ResourceHolder type:
- Textures
- Fonts
- Shaders
- SoundEffects
- Music

An enum is built from the list of files in each directory. The name of the enum entry will have the file name. Es.: if Textures has 2 files
- Button.jpg
- InputField.png

the resulting ResourceIdentifiers.hpp will contain
```
namespace Textures {
	enum ID {
		Button,
		InputField
	}
}
```

Every ID will be mapped to the correct resource file path in a dedicated ```std::map<Textures::ID, std::filepath>```.


## Examples
The examples/ folder contains a few examples, each with its own cmake file. The library has to be built separately with the above mentioned method, as the example cmake files needs libengine.a in the build/ folder to compile the example.

## Project Structure
