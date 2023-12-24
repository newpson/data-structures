cmake_minimum_required(VERSION 3.27)
project(QtAirlines CXX)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external)

find_package(Qt5Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(NAirlines)

add_executable(app)
target_sources(app
	PRIVATE main.cpp)
target_include_directories(app
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(app
    PUBLIC Qt::Widgets NAirlines)
