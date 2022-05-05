cmake_minimum_required(VERSION 2.8.9)
project(libsbp_v4_cpp_example)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-strict-prototypes -Werror -std=gnu99 -Wno-error=deprecated-declarations ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++11 -Wno-error=deprecated-declarations ${CMAKE_CXX_FLAGS}")

find_package(PkgConfig)

link_directories("/usr/local/lib/")
include_directories("/usr/local/include/")

add_executable(libsbp_v4_cpp_example cpp_example.cc)
target_link_libraries(libsbp_v4_cpp_example sbp)
