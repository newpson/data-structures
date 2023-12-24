add_library(Stack INTERFACE)
target_sources(Stack
	PUBLIC Stack.hpp)
target_include_directories(Stack
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Stack
	INTERFACE SLList)
