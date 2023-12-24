find_package(Qt5Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(MainWindow)

add_executable(QtVisualizer)
target_sources(QtVisualizer
	PRIVATE main.cpp App.cpp
	PUBLIC App.hpp)
target_include_directories(QtVisualizer
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(QtVisualizer
    PUBLIC Qt::Widgets MainWindow)

# function(get_all_targets var)
#     set(targets)
#     get_all_targets_recursive(targets ${CMAKE_CURRENT_SOURCE_DIR})
#     set(${var} ${targets} PARENT_SCOPE)
# endfunction()
#
# macro(get_all_targets_recursive targets dir)
#     get_property(subdirectories DIRECTORY ${dir} PROPERTY SUBDIRECTORIES)
#     foreach(subdir ${subdirectories})
#         get_all_targets_recursive(${targets} ${subdir})
#     endforeach()
#
#     get_property(current_targets DIRECTORY ${dir} PROPERTY BUILDSYSTEM_TARGETS)
#     list(APPEND ${targets} ${current_targets})
# endmacro()
#
# get_all_targets(all_targets)
# message("All targets: ${all_targets}")
