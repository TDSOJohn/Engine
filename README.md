Todo:

- Category.hpp, ResourceIdentifiers.hpp and StateIdentifiers.hpp should be generated at compile time somehow
- CommandQueue is still a template. Does it need to be that way?
- ParticleNode depends on DataTables.

compile with:
```bash
mkdir build
cd build
cmake ../
make
```

compile main and link to library with:
```
g++ --std=c++17 main.cpp ./build/libengine.a
```

Core Foundation is used to rethrieve the current folder path in Release mode (still simple copypasta from the noGravitar folder)
```
g++ --std=c++17 main.cpp ./build/libengine.a -framework CoreServices
```
