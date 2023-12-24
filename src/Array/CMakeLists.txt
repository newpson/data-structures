add_library(Array INTERFACE)
target_sources(Array
	PRIVATE Array.cpp
	PUBLIC Array.hpp)
target_include_directories(Array
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
