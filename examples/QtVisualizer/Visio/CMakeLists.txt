add_subdirectory(Tabs)

add_library(Visio STATIC)
target_sources(Visio
	PRIVATE Visio.cpp
	PUBLIC Visio.hpp)
target_include_directories(Visio
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Visio
    PUBLIC Qt::Widgets Tabs)
