cmake_minimum_required(VERSION 3.12)

project(digit_request)

add_executable(digit_request 
    rand.cpp
    randomdigit.cpp
    additional.h
)

set_target_properties(digit_request PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)