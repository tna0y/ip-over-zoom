#!/usr/bin/env bash
set -xeuo pipefail

mkdir -p build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build .
sudo ./bin/ip-over-zoom-cli