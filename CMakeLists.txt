cmake_minimum_required(VERSION 3.5)
project(labs)

# add_compile_options(-g -Wall -Wextra -Wpedantic)
add_compile_options(-O2 -Wall -Wextra -Wpedantic)
# add_link_options(-fsanitize=address)

# if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
# 	add_compile_options(-std=c++17)
# elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
# 	add_compile_options(-std=c++20)
# endif()

include_directories(lib)

add_subdirectory(lib)
add_subdirectory(demo)
