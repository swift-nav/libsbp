cmake_minimum_required(VERSION 2.8.9)
project(libsbp_legacy_tcp_example)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-strict-prototypes -Werror -Wno-error=deprecated-declarations -std=gnu99 ${CMAKE_C_FLAGS}")

add_executable(libsbp_legacy_tcp_example tcp_example.c)

find_package(PkgConfig)

link_directories("/usr/local/lib/")
include_directories("/usr/local/include/")

target_link_libraries(libsbp_legacy_tcp_example sbp)
