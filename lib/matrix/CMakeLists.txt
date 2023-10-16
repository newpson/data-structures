cmake_minimum_required(VERSION 3.5)

add_library(matrix-dynarr STATIC dynarr.c)
add_library(matrix-dynarr-extended STATIC dynarr-extended.c)
	target_link_libraries(matrix-dynarr-extended PRIVATE matrix-dynarr)
