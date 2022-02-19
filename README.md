A simple game engine that uses [SFML](https://www.sfml-dev.org).</br>
It all started by trying to extract a somehow functioning Engine from the [SFML game dev book's code](https://github.com/SFML/SFML-Game-Development-Book).</br>
Compile with:
```bash
mkdir build
cd build
cmake ../
make
```
This creates a libengine.a file.

Compile main and link to library with:
```
g++ --std=c++17 main.cpp ./build/libengine.a
```

Core Foundation is used to retrieve the current folder path in Release mode on macOS, add link to CoreServices framework.
```
g++ --std=c++17 main.cpp ./build/libengine.a -framework CoreServices
```

The examples/ folder contains a few examples, each with its cmake file. The library has to be built separately with the above mentioned method, as the cmake file needs libengine.a in the build/ folder to compile the example.</br></br></br>
Todo:

- Category.hpp, ResourceIdentifiers.hpp and StateIdentifiers.hpp should be generated at compile time somehow
- CommandQueue is still a template. Does it need to be that way?
- ParticleNode depends on DataTables.
