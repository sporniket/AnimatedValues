# SPDX-License-Identifier: GPL-3.0-or-later
# Copyright (C) 2021~2025 David SPORN
# ---
# This is part of **Animated values**.
# Created to help you go beyond a simple blinking.
# ---
# This is a source library project. As such, no deliverable binary is generated.
#
# HOWEVER there is a test suite that can be compiled and invoked
# ---
# How to build and verify
#
# 1. Create a build directory : `mkdir built-tests`
# 2. Change to this build directory : `cd build-tests`
# 3. Initialize the build system : `cmake ..`
# 4. Invoke the build system to perform the test suite :
#    * either `cmake --build . -- verify` to build incrementally.
#    * or `cmake --build . --clean-first -- verify` to trigger a full rebuild.
# ---
cmake_minimum_required(VERSION 3.28)
project(animated_values)
set(CMAKE_CXX_STANDARD 11)

# The test suite is implemented in a dedicated source folder.
add_subdirectory(src-tests)

# Add clang-format tasks
file(GLOB_RECURSE FORMATTABLE_SOURCES
       ${PROJECT_SOURCE_DIR}/include/*.hpp
       ${PROJECT_SOURCE_DIR}/src/*.cpp
       ${PROJECT_SOURCE_DIR}/src-tests/*.cpp
)

add_custom_target(check-prettier
    COMMAND clang-format
    --dry-run
    --style=file
    ${FORMATTABLE_SOURCES}
)
add_custom_target(prettier
    COMMAND clang-format
    -i
    --style=file
    ${FORMATTABLE_SOURCES}
)
