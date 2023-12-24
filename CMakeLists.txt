cmake_minimum_required(VERSION 3.27)
project(data-structures CXX)
set(CMAKE_CXX_STANDARD 20)

# add_compile_options(-g)

# Qt fake leaks? bruh
# add_link_options(-fsanitize=address)

add_subdirectory(external)
add_subdirectory(src)
# add_subdirectory(examples)
