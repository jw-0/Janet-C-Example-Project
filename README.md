This is a minimal example project for calling C++ from Janet.

Usage:
Make sure you have [Janet](https://janet-lang.org) and [jpm](https://janet-lang.org/docs/jpm.html) installed.
Then run `jpm build` from the root of this directory. It will handle compiling the shared library (`rectangle_bindings.cpp` and `rectangle.h`) and then compile the `main.janet` file into an executable.
If you don't want to use the executable and just run `main.janet` as a script, still run `jpm build` to ensure the rectangle library is built and then just call `janet main.janet` and it should find the library in the build/ directory.

The resulting executables are in build/
