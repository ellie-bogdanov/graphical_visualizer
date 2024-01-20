cmake_minimum_required(VERSION 3.0.0)
project(graphical_visualizer VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(graphical_visualizer main.cpp graphical_visualizer.hpp graphical_visualizer.cpp falling_sand.hpp falling_sand.cpp algorithm_visualizer.hpp algorithm_visualizer.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
