cmake_minimum_required(VERSION 2.8.9)
project(libsbp_cpp_example)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-strict-prototypes -Wno-unknown-warning-option -Werror -std=gnu99 ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-strict-prototypes -Wno-unknown-warning-option -Werror -std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(PkgConfig)

link_directories("/usr/local/lib/")
include_directories("/usr/local/include/")

add_executable(libsbp_cpp_example cpp_example.cc)
target_link_libraries(libsbp_cpp_example sbp)
