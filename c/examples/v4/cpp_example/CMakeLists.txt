cmake_minimum_required(VERSION 2.8.9)
project(libsbp_cpp_example_v4)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-strict-prototypes -Werror -std=gnu99 -Wno-error=deprecated-declarations ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -std=c++11 -Wno-error=deprecated-declarations ${CMAKE_CXX_FLAGS}")

find_package(PkgConfig)

link_directories("/usr/local/lib/")
include_directories("/usr/local/include/")

add_executable(libsbp_cpp_example_v4 cpp_example_v4.cc)
target_link_libraries(libsbp_cpp_example_v4 sbp)

add_dependencies(examples libsbp_cpp_example_v4)
