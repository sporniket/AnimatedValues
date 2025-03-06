# HOWTO run the test suite

## Required

* [Cmake](https://cmake.org/)
* A C++ toolchain
* The [Criterion unit testing framework](https://github.com/Snaipe/Criterion)

## Run the test suite

1. Create a build directory : `mkdir build`
2. Change to this build directory : `cd build`
3. Initialize the build system : `cmake ..`
4. Invoke the build system to perform the test suite :
   * either `cmake --build . -- verify` to build incrementally.
   * or `cmake --build . --clean-first -- verify` to trigger a full rebuild.
