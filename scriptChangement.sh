#!/usr/bin/env bash
cd cmake-build-release/
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=$1 -DCMAKE_CXX_COMPILER=$2 -DCMAKE_VERBOSE_MAKEFILE:BOOL=$3 -G "CodeBlocks - Unix Makefiles" ../
cd ../
