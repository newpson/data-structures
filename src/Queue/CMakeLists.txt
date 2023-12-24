add_library(Queue INTERFACE)
target_sources(Queue
	PUBLIC Queue.hpp)
target_include_directories(Queue
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Queue
	INTERFACE SLList)
