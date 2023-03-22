#!/usr/bin/env bash
set -xeuo pipefail

rm -rf ../build
conan install . --output-folder=./build --build=missing
