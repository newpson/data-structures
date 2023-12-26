add_library(TabDLL STATIC)
target_sources(TabDLL
	PRIVATE TabDLL.cpp FrameDLL.cpp
	PUBLIC TabDLL.hpp FrameDLL.hpp)
target_include_directories(TabDLL
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(TabDLL
    PUBLIC Qt::Widgets DLList)
