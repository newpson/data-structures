cmake_minimum_required(VERSION 2.4)
project(labs-demo)

# library examples
add_executable(demoarray array.cpp)
	target_link_libraries(demoarray array)

add_executable(demostack stack.cpp)
	target_link_libraries(demostack stack-extended)

add_executable(demoqueue queue.cpp)
	target_link_libraries(demoqueue queue-extended)

# games and demos
add_executable(balls balls.cpp)
	target_link_libraries(balls queue-extended)

add_executable(neighbours neighbours.cpp)
	target_link_libraries(neighbours stack-extended)

add_executable(burgers-fast burgers-fast.cpp)

add_executable(burgers burgers.cpp)
	target_link_libraries(burgers stack queue-extended)
