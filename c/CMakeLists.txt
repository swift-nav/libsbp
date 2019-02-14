cmake_minimum_required(VERSION 3.1)
project(libsbp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_subdirectory(src)
add_subdirectory(docs)
add_subdirectory(test)
