# CMake Tutorial
[CMAKE TUTORIAL - YouTube](https://www.youtube.com/playlist?list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4)

## Episode 1: Understanding the Basics
### Code
[Episode 1: Understanding the Basics](./Episode-1_Understanding-The-Basics)

### Basics of CMake
- CMake makes Makefiles
- Makefiles are the basis of everything
- CMake relies on a top-level file called exactly `CMakeLists.txt`.
- Create a build directory: `mkdir -p out/build`
- Call `cmake -S . -B out/build`  
  Generates the following directory structure:
  ```
  out/build/
  ├── CMakeCache.txt
  ├── CMakeFiles
  ├── Makefile
  └── cmake_install.cmake
  ```
- Specify minimum CMake version on top of `./CMakeLists.txt`. For example, use the currently installed version. The point is that the project is tested and guaranteed to run with the specified version.  
`cmake_minimum_required(VERSION 3.28.3)`
- Spefify the project name in `./CMakeLists.txt`.  
  `project(Basics)`
- Specify the executable to be built. It needs a name and source files  
  `add_executable(${PROJECT_NAME} main.cpp)`
- Now after running `cmake` we see that generated Makefile has entries related to compiling `main.cpp`.
- It can be compiled by running `make` in `./out/build/`.

## Episode 2: Libraries | Installing | Pairing with Executables

### Install
- Code: [Install](./Episode-2_Libraries_Installing_Pairing-with-Executables/Install)
- Adding the line `install(TARGETS trim DESTINATION bin)` tells CMake to create a Makefile target called `install`.
  - `TARGETS` is a keyword that is followed by the targets that are to be installed
  - `DESTINATION` is a keyword that is followed by the installation destination. Depending on OS configuration, but usually defaults to `/usr/local/bin` for executables.
- Useful for Linux environments.

### Libraries
- Code: [Libraries](./Episode-2_Libraries_Installing_Pairing-with-Executables/Libraries)
- The CMake commands `add_subdirectory(src)` and `add_subdirectory(test)` add the subdirectories `src` and `test` respectively to the build. This means the `CMakeLists.txt` files in these subdirectories are evaluated at those points.
- The CMake command `add_library(mearlymath adder.cpp)` instructs CMake to create a target for a library called `mearlymath` from the source file `adder.cpp`. The given library name can be reference later, e.g. in `target_link_libraries`.
- The CMake command `target_include_directories(testsome PRIVATE "${CMAKE_SOURCE_DIR}/src")` adds the directory `src` to the search path for header files.
  - `src` is relative to the top-level of the source tree (i.e. the location of the top-level `CMakeLists.txt`)
  - The keyword `PRIVATE` makes sense because no other target links against `testsome` and the include directories do not need to be propagated.
- The CMake command `target_link_libraries(testsome PRIVATE mearlymath)` links the library `mearlymath` to the target `testsome`. Again `PRIVATE` because no other target links against `testsome`.

#### How to run
```
> cd Episode-2_Libraries_Installing_Pairing-with-Executables/Libraries

> mkdir build

> cd build

> cmake -S ..

> make testsome

> ./test/testsome
2 + 3 = 5
```