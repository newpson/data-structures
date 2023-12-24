add_library(BTree INTERFACE)
target_sources(BTree
	PUBLIC BTree.hpp
	PRIVATE BTree.tcc)
target_include_directories(BTree
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(BTree
	INTERFACE Queue)

add_library(BSTree INTERFACE)
target_sources(BSTree
	PUBLIC BSTree.hpp)
target_include_directories(BSTree
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(BSTree
	INTERFACE BTree)
