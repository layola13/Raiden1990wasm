#!/bin/bash

# Exit on error
set -e

# 1. Setup Emscripten environment
echo "Setting up Emscripten environment..."
source ./emsdk/emsdk_env.sh

rm -rf build
# 2. Create build directory in project root
echo "Creating build directory in root..."
mkdir -p build
cd build

# 4. Copy Assets directory to build directory
echo "Copying Assets to build directory..."
cp -r ../"Raiden Game"/Game/Assets .

# 3. Configure the project with emcmake
echo "Configuring with emcmake..."
emcmake cmake ../"Raiden Game"



# 5. Diagnostic: print current working directory and file list
echo "Diagnostic: current working directory is $(pwd)"
echo "Diagnostic: current directory contents:"
ls -l

# 6. Build the project
echo "Building with make..."
make

echo "Build complete! Output files and Assets are in 'build' directory."