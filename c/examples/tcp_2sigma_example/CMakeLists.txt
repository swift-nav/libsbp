cmake_minimum_required(VERSION 2.8.9)
project(libsbp_tcp_2sigma_example)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wno-error=deprecated-declarations -std=c++14")

add_executable(libsbp_tcp_2sigma_example tcp_2sigma_example.cc)

find_package(PkgConfig)
find_package(Eigen3)

option(SHOW_PLOT "" OFF)

link_directories("/usr/local/lib/")
include_directories("/usr/local/include/")

target_link_libraries(libsbp_tcp_2sigma_example sbp)

if (SHOW_PLOT)
  find_package(OpenCV)
  set(CMAKE_CXX_FLAGS "-DSHOW_PLOT ${CMAKE_CXX_FLAGS}")
  target_link_libraries(libsbp_tcp_2sigma_example opencv_core opencv_imgproc opencv_highgui)
endif()
