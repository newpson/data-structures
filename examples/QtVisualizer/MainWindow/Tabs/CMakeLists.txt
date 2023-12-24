add_subdirectory(TabDLL)

add_library(Tabs INTERFACE)
target_link_libraries(Tabs
	INTERFACE TabDLL)
