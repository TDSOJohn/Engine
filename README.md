Todo:

- Category.hpp and ResourceIdentifiers.hpp should be generated at compile time somehow

compile with:
```bash
mkdir build
cd build
cmake ../
make
```

compile main and link to library with:
```
g++ --std=c++11 main.cpp ./build/libengine.a
```
