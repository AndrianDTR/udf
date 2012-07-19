#!/bin/bash

./autogen.sh

mkdir -p build
cd build
../configure --with-wxWidgets=yes
make
cd ..

