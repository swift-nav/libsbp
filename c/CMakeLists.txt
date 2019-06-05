cmake_minimum_required(VERSION 3.9)
project(libsbp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(GNUInstallDirs)

##########################################################
# Set some reasonable default compiler flags.
# Users of LibSbp that need different flags to be used can specify them
# when invoking cmake (cmake -DLIBSBP_CFLAGS:STRING="-Os -ffunction-sections")
# or by editing the CMakeCache.txt manually after invoking cmake
##########################################################
if(MSVC)
    set(LIBSBP_CFLAGS "/Wall" CACHE STRING "Compile flags for libsbp.")
else()
    set(LIBSBP_CFLAGS "-Wall -Werror" CACHE STRING "Compile flags for libsbp.")
    link_directories("/usr/local/lib")
endif()

add_subdirectory(src)
add_subdirectory(docs)
add_subdirectory(test)
