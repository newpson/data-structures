add_library(Matrix STATIC)
target_sources(Matrix
	PUBLIC Matrix.hpp
	PRIVATE Matrix.cpp)
target_include_directories(Matrix
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
