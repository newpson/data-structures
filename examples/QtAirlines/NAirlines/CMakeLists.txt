add_subdirectory(Ticket)

add_library(NAirlines STATIC)
target_sources(NAirlines
	PRIVATE NAirlines.cpp
	PUBLIC NAirlines.hpp)
target_include_directories(NAirlines
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(NAirlines
    PUBLIC Qt::Widgets Ticket DLList)
