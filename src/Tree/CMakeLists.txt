add_library(BTree INTERFACE)
target_sources(BTree
	PUBLIC BTree.hpp)
target_include_directories(BTree
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(BTree
	INTERFACE DLList Queue)

add_library(BSTree INTERFACE)
target_sources(BSTree
	PUBLIC BSTree.hpp)
target_include_directories(BSTree
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(BSTree
	INTERFACE BTree)

add_library(AVLTree INTERFACE)
target_sources(AVLTree
	PUBLIC AVLTree.hpp)
target_include_directories(AVLTree
	INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(AVLTree
	INTERFACE DLList Queue)
