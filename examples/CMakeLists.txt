add_executable(array)
target_sources(array
	PRIVATE array.cpp)
target_link_libraries(array
	PUBLIC Array)

add_executable(matrix)
target_sources(matrix
	PRIVATE matrix.cpp)
target_link_libraries(matrix
	PUBLIC Matrix)

add_executable(sllist)
target_sources(sllist
	PRIVATE sllist.cpp)
target_link_libraries(sllist
	PUBLIC SLList)

add_executable(stack)
target_sources(stack
	PRIVATE stack.cpp)
target_link_libraries(stack
	PUBLIC Stack)

add_executable(dllist)
target_sources(dllist
	PRIVATE dllist.cpp)
target_link_libraries(dllist
	PUBLIC DLList)

add_executable(queue)
target_sources(queue
	PRIVATE queue.cpp)
target_link_libraries(queue
	PUBLIC Queue)

add_executable(deque)
target_sources(deque
	PRIVATE deque.cpp)
target_link_libraries(deque
	PUBLIC Deque)

add_executable(bstree)
target_sources(bstree
	PRIVATE bstree.cpp)
target_link_libraries(bstree
	PUBLIC BSTree)

add_executable(avltree)
target_sources(avltree
	PRIVATE avltree.cpp)
target_link_libraries(avltree
	PUBLIC AVLTree)
