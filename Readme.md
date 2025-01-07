# CMake Tutorial
[CMAKE TUTORIAL - YouTube](https://www.youtube.com/playlist?list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4)

## Episode 1: Understanding the Basics
### Code
[Episode 1: Understanding the Basics](./Episode-1_Understanding-The-Basics)

### Notes
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
