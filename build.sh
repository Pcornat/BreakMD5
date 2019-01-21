#!/usr/bin/env bash
cmake --build cmake-build-release/ --target $1 -- -j --no-print-directory
mv cmake-build-release/$1 prog
