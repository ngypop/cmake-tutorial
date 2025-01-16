add_executable(testsome main.cpp)
target_include_directories(testsome PRIVATE "${CMAKE_SOURCE_DIR}/src")
target_link_libraries(testsome PRIVATE adder)
