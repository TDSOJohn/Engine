A simple 2D game engine that uses [SFML](https://www.sfml-dev.org).</br>
It all started by trying to extract an engine from the [SFML game dev book's code](https://github.com/SFML/SFML-Game-Development-Book).</br>
Currently tested on macOS and Linux (Ubuntu 22.04).
## 
## Compiling from source
Download from GitHub and compile with:
```bash
cmake -S . -B build
cd build
make
```
This creates a libengine.a file you can statically link.

Compile your project and link to library with:
```
g++ --std=c++17 main.cpp ./build/libengine.a
```

Core Foundation is used to retrieve the current folder path in Release mode on macOS. Remember to link to CoreServices framework.
```
g++ --std=c++17 main.cpp ./build/libengine.a -framework CoreServices
```

## Examples
The examples/ folder contains a few examples, each with its cmake file. The library has to be built separately with the above mentioned method, as the cmake file needs libengine.a in the build/ folder to compile the example.