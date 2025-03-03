cmake_minimum_required(VERSION 3.5)

project(gatsby)

add_executable(gatsby topk_words.cpp)

set_target_properties(gatsby PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

