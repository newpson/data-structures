cmake_minimum_required(VERSION 3.5)

add_library(stack-list STATIC list.c)
add_library(stack-list-extended STATIC list-extended.c)
	target_link_libraries(stack-list-extended PRIVATE stack-list)
