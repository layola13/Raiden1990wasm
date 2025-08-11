cmake_minimum_required(VERSION 3.13)
project(RaidenWasm CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Emscripten Flags ---
# Flags for both compiler and linker
# Flags for compiler
set(EM_COMPILE_FLAGS "-s USE_SDL=2")
set(EM_COMPILE_FLAGS "${EM_COMPILE_FLAGS} -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]'")
set(EM_COMPILE_FLAGS "${EM_COMPILE_FLAGS} -s USE_SDL_MIXER=2")

# Flags for linker only
set(EM_LINKER_FLAGS "-s ALLOW_MEMORY_GROWTH=1")
set(EM_LINKER_FLAGS "${EM_LINKER_FLAGS} -s ASSERTIONS=1")
set(EM_LINKER_FLAGS "${EM_LINKER_FLAGS} -s SAFE_HEAP=1")
set(EM_LINKER_FLAGS "${EM_LINKER_FLAGS} --shell-file /workspaces/Raiden1990wasm/emsdk/upstream/emscripten/src/shell.html --preload-file Assets@Assets")

# Apply flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EM_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${EM_LINKER_FLAGS}")
# --- End Emscripten Flags ---

# Find all source files
file(GLOB_RECURSE SOURCES "*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/log.cpp")

# Add the executable and set output name
add_executable(raiden ${SOURCES})
set_target_properties(raiden PROPERTIES SUFFIX ".html")

# Add include directory for the project's own headers.
# Emscripten will handle the SDL headers automatically.
target_include_directories(raiden PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")