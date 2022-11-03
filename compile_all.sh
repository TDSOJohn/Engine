#! /bin/bash

rm -r build
cmake -S . -B build
cd build
cmake --build .

cd ../examples/GUI
rm -r build
cmake -S . -B build
cd build
cmake --build .

cd ../../rigidBody
rm -r build
cmake -S . -B build
cd build
cmake --build .

cd ../../rotation
rm -r build
cmake -S . -B build
cd build
cmake --build .
