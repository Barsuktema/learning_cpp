cmake_minimum_required(VERSION 3.5)

project(13.homework)

add_executable(container container.cpp container.hpp)
set_target_properties(container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

