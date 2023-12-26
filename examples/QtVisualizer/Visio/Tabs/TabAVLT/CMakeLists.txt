add_library(TabAVLT STATIC)
target_sources(TabAVLT
	PRIVATE TabAVLT.cpp FrameAVLT.cpp
	PUBLIC TabAVLT.hpp FrameAVLT.hpp TreeData.hpp)
target_include_directories(TabAVLT
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(TabAVLT
	PUBLIC Qt::Widgets AVLTree)
