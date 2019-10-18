cmake_minimum_required(VERSION 3.2)
project(libsbp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake/common")

include(GNUInstallDirs)
include(CCache)
include(SwiftCmakeOptions)
swift_create_project_options(
    HAS_TESTS
    HAS_DOCS
    TEST_PACKAGES "Check"
    )
include(CodeCoverage)
include(TestTargets)
add_code_coverage_all_targets()

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
endif()

add_subdirectory(src)
if(libsbp_BUILD_DOCS)
  add_subdirectory(docs)
endif()
if(libsbp_BUILD_TESTS)
  add_subdirectory(test)
endif()
