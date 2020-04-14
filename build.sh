#!/bin/bash
BUILD_FOLDER="build/"
if [ -d ${BUILD_FOLDER} ] ; then
    rm -rf ${BUILD_FOLDER}
fi

mkdir build/
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make