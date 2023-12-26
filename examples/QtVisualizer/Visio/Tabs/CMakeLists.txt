add_subdirectory(TabDLL)
add_subdirectory(TabAVLT)

add_library(Tabs INTERFACE)
target_link_libraries(Tabs
	INTERFACE TabDLL TabAVLT)
