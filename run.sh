#!/bin/bash

autogen.sh
cd build
../configure --with_wxWidgets=yes
make -j8
cd ..

