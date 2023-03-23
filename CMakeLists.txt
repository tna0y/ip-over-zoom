cmake_minimum_required(VERSION 3.18)
project(ip-over-zoom VERSION 1.0.0)

set(project                 ${PROJECT_NAME})
set(project_root            "${CMAKE_CURRENT_LIST_DIR}")
set(project_cmake           "${project_root}/cmake")
set(project_version         ${PROJECT_VERSION})

include(cmake/cppcheck.cmake)
include(cmake/cpplint.cmake)


add_subdirectory(src/common)
add_subdirectory(src/tunnel)
add_subdirectory(src/codec)
add_subdirectory(src/cli)