# HOWTO run the test suite

## Required

* [Cmake](https://cmake.org/)
* A C++ toolchain
* The [Criterion unit testing framework](https://github.com/Snaipe/Criterion)

## Run the test suite

1. Initialize cmake and put cmake data into a 'build' folder : `cmake -Bbuild`
4. Invoke the build system to perform the test suite (the space before `verify` is NOT a typo) :
   * either `cmake --build build -- verify` to build incrementally.
   * or `cmake --build build --clean-first -- verify` to trigger a full rebuild.
