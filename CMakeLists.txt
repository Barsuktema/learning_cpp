cmake_minimum_required(VERSION 3.5)

project(13.homework)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/googletest")

add_executable(test_container test/test_list.cpp test/test_array.cpp)
target_include_directories(test_container PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
add_executable(container src/container.cpp src/container.hpp)
target_link_libraries(test_container PRIVATE gtest gtest_main)
set_target_properties(container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(test_container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

