project(graph_algos)

# Add include directories for Google Test and Google Mock
# This tells the compiler where to find the header files
#include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)


# Include directories
include_directories(${EIGEN3_INCLUDE_DIR})

# Add your test source files
add_executable(graph_test src/graph_test.cc)

# Link the executable with Google Mock and Google Test libraries
# This ensures the linker finds the required libraries
target_link_libraries(graph_test gmock_main gmock gtest_main gtest pthread)
