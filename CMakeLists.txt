# Specify the required version of CMake
cmake_minimum_required(VERSION 3.0)

# Specify the project name
project(TDD)

# Find Eigen
find_package(Eigen3 REQUIRED)

# Add Google Test and Google Mock as subdirectories
# Make sure that the `googletest` directory is in the project root
add_subdirectory(googletest)
add_subdirectory(soundex)
add_subdirectory(graph_algos)