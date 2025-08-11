#!/bin/bash
find "/workspaces/Raiden1990wasm/Raiden Game" -type f \( -name "*.cpp" -o -name "*.h" \) -print0 | while IFS= read -r -d $'\0' file; do
    # Replace forward slash includes with angle brackets
    sed -i 's|#include "SDL/include/\(.*\)"|#include <\1>|g' "$file"
    sed -i 's|#include "SDL_image/include/\(.*\)"|#include <\1>|g' "$file"
    sed -i 's|#include "SDL_mixer/include/\(.*\)"|#include <\1>|g' "$file"

    # Replace backslash includes with angle brackets
    sed -i 's|#include "SDL\\include\\\(.*\)"|#include <\1>|g' "$file"
done

echo "Include paths fixed."