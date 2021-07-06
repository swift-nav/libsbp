find_package(Threads)
set(TEST_LIBS ${TEST_LIBS} check Threads::Threads sbp)

# Check needs to be linked against Librt on Linux
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  set(TEST_LIBS ${TEST_LIBS} rt)
endif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

FILE(GLOB generated_legacy_c_sources legacy/auto*.c)

FILE(GLOB generated_v4_c_sources auto*.c)

set(TEST_INCLUDES ${PROJECT_SOURCE_DIR}/include/libsbp)

if(APPLE)
  # Some libraries are available in non-standard places on apple.
  list(APPEND TEST_INCLUDES /usr/local/include)

  # This is not a great way of doing this, but the proper cmake function
  # target_link_directories() was introduced in version 3.13 and we need to support
  # older versions for the moment. We can use target_link_libraries to pass arbitrary
  # linker flags, making sure that this instance is well protected and only applies
  # to a single platform. Don't use the extant link_directories() function since
  # that leaks the path to other targets.
  list(APPEND TEST_INCLUDES "-L/usr/local/lib")
endif()

if (NOT CMAKE_C_COMPILER_ID STREQUAL "MSVC")
  swift_add_test(test-libsbp-legacy
    UNIT_TEST
    SRCS
      check_main_legacy.c
      check_edc.c
      check_sbp.c
      check_bitfield_macros.c
      ${generated_legacy_c_sources}
    INCLUDE
      ${TEST_INCLUDES}
    LINK
      ${TEST_LIBS}
    )
  swift_set_compile_options(test-libsbp-legacy
    REMOVE
      -Wconversion
      -Wpointer-arith
      -Wformat
      -Wformat-security
      -Wformat-y2k
    ADD
      -Wformat=0
  )
endif()

swift_add_test(test-libsbp-v4
  UNIT_TEST
  SRCS
    check_main.c
    check_edc.c
    check_sbp.c
    check_bitfield_macros.c
    ${generated_v4_c_sources}
  INCLUDE
    ${TEST_INCLUDES}
  LINK
    ${TEST_LIBS}
  )
swift_set_compile_options(test-libsbp-v4
  REMOVE 
    -Wpointer-arith
    -Wformat
    -Wformat-security
    -Wformat-y2k
  ADD
    -Wformat=0
)

add_subdirectory(cpp)
add_subdirectory(string)

if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  add_subdirectory(legacy/cpp)
endif()
