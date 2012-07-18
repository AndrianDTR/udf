#!/bin/bash

./autogen.sh

mkdir -p build
cd build
../configure --with-wxWidgets=yes
make -j8
cd ..

