add_library(Deque INTERFACE)
target_sources(Deque
	PUBLIC Deque.hpp)
target_include_directories(Deque
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Deque
	INTERFACE DLList)
