add_library(SLList INTERFACE)
target_sources(SLList
	PUBLIC SLList.hpp)
target_include_directories(SLList
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})

add_library(DLList INTERFACE)
target_sources(DLList
	PUBLIC DLList.hpp)
target_include_directories(DLList
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
