add_subdirectory(Tabs)

add_library(MainWindow STATIC)
target_sources(MainWindow
	PRIVATE MainWindow.cpp
	PUBLIC MainWindow.hpp)
target_include_directories(MainWindow
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(MainWindow
    PUBLIC Qt::Widgets Tabs)
