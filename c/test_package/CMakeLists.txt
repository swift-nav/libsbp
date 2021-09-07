cmake_minimum_required(VERSION 3.12)
project(test_package C CXX)

set(SBP_FILE ${CMAKE_SOURCE_DIR}/../../test_data/roundtrip.sbp CACHE FILEPATH "Path to a sample SBP file which is used for testing")

if (NOT EXISTS ${SBP_FILE} OR NOT IS_ABSOLUTE ${SBP_FILE})
  message(FATAL_ERROR "SBP_FILE variable (\"${SBP_FILE}\") needs to point to an absolute valid SBP file")
endif()

find_library(SBP_LIBRARY sbp)
if (NOT SBP_LIBRARY)
  message(FATAL_ERROR "SBP library was not found")
endif()

find_path(SBP_INCLUDE_DIRS libsbp)
if (NOT SBP_INCLUDE_DIRS)
  message(FATAL_ERROR "SBP header folder was not found")
endif()

if (NOT WIN32)
  add_executable(legacy_c legacy.c)
  target_compile_features(legacy_c PRIVATE c_std_11)
  target_link_libraries(legacy_c PRIVATE ${SBP_LIBRARY})
  target_include_directories(legacy_c PRIVATE ${SBP_INCLUDE_DIRS})
  target_compile_definitions(legacy_c PRIVATE SBP_FILE="${SBP_FILE}")

  add_executable(legacy_cxx legacy.cc)
  target_compile_features(legacy_cxx PRIVATE cxx_std_14)
  target_link_libraries(legacy_cxx PRIVATE ${SBP_LIBRARY})
  target_include_directories(legacy_cxx PRIVATE ${SBP_INCLUDE_DIRS})
  target_compile_definitions(legacy_cxx PRIVATE SBP_FILE="${SBP_FILE}")
endif()

add_executable(v4_c v4.c)
target_compile_features(v4_c PRIVATE c_std_11)
target_link_libraries(v4_c PRIVATE ${SBP_LIBRARY})
target_include_directories(v4_c PRIVATE ${SBP_INCLUDE_DIRS})
target_compile_definitions(v4_c PRIVATE SBP_FILE="${SBP_FILE}")

add_executable(v4_cxx v4.cc)
target_compile_features(v4_cxx PRIVATE cxx_std_14)
target_link_libraries(v4_cxx PRIVATE ${SBP_LIBRARY})
target_include_directories(v4_cxx PRIVATE ${SBP_INCLUDE_DIRS})
target_compile_definitions(v4_cxx PRIVATE SBP_FILE="${SBP_FILE}")
