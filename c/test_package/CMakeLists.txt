cmake_minimum_required(VERSION 3.12)
project(test_package C CXX)

set(SBP_FILE ${CMAKE_SOURCE_DIR}/../../test_data/roundtrip.sbp CACHE FILEPATH "Path to a sample SBP file which is used for testing")

if (NOT EXISTS ${SBP_FILE} OR NOT IS_ABSOLUTE ${SBP_FILE})
  message(FATAL_ERROR "SBP_FILE variable (\"${SBP_FILE}\") needs to point to an absolute valid SBP file")
endif()

find_library(SBP_LIBRARY sbp)
find_path(SBP_INCLUDE_DIRS libsbp)

if (NOT SBP_LIBRARY)
  message(FATAL_ERROR "SBP library was not found")
endif()
if (NOT SBP_INCLUDE_DIRS)
  message(FATAL_ERROR "SBP header folder was not found")
endif()

add_executable(legacy_c legacy.c)
add_executable(legacy_cxx legacy.cc)
add_executable(v4_c v4.c)
add_executable(v4_cxx v4.cc)

foreach(executable IN ITEMS legacy_c v4_c)
  target_compile_features(${executable} PRIVATE c_std_11)
endforeach()

foreach(executable IN ITEMS legacy_cxx v4_cxx)
  target_compile_features(${executable} PRIVATE cxx_std_14)
endforeach()

foreach(executable IN ITEMS legacy_c legacy_cxx v4_c v4_cxx)
  target_link_libraries(${executable} PRIVATE ${SBP_LIBRARY})
  target_include_directories(${executable} PRIVATE ${SBP_INCLUDE_DIRS})
  target_compile_definitions(${executable} PRIVATE SBP_FILE="${SBP_FILE}")
endforeach()