#add miniumum version
cmake_minimum_required(VERSION 3.5)
#add project name and Version
project(DynamicArray VERSION 0.1)
# add the executable
add_executable(DynamicArray dynamic-array.cpp)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#configure a header file to pass the version number to the source code
configure_file(dynamic-array.hpp.in dynamic-array.hpp)
#Since the configured file will be written into the binary tree,
# we must add that directory to the list of paths to search for include files
target_include_directories(DynamicArray PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
