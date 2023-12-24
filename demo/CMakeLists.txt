cmake_minimum_required(VERSION 3.5)

# library examples
add_executable(demomatrix matrix.c)
	target_link_libraries(demomatrix matrix-extended)

add_executable(demostack stack.c)
	target_link_libraries(demostack stack-extended)

add_executable(demoqueuec queue.c)
	target_link_libraries(demoqueuec queue-extended)

add_executable(demoqueuecpp queue.cpp)

# games and demos
add_executable(balls balls.c)
	target_link_libraries(balls queue-extended)

add_executable(neighbours neighbours.c)
	target_link_libraries(neighbours stack-extended)

add_executable(burgers-fast burgers-fast.c)

add_executable(burgers burgers.c)
	target_link_libraries(burgers stack queue-extended)
