cmake_minimum_required(VERSION 2.4)
project(labs)

add_compile_options(-g -Wall -Wextra -Wpedantic -std=c++20)
add_link_options(-fsanitize=address)

include_directories(lib)

add_subdirectory(lib)
add_subdirectory(demo)
