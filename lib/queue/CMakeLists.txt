cmake_minimum_required(VERSION 3.5)

add_library(queue-list STATIC list.c)
add_library(queue-list-extended STATIC list-extended.c)
	target_link_libraries(queue-list-extended PRIVATE queue-list)
add_library(queue-list-fast STATIC list-fast.c)
