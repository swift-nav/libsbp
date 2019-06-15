set(TEST_LIBS ${TEST_LIBS} ${CHECK_LIBRARIES} pthread sbp m)

# Check needs to be linked against Librt on Linux
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
  set(TEST_LIBS ${TEST_LIBS} rt)
endif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

FILE(GLOB generated_c_sources auto*.c)
add_executable(test_libsbp check_main.c check_edc.c check_sbp.c ${generated_c_sources})

target_link_libraries(test_libsbp PRIVATE ${TEST_LIBS})
set_target_properties(test_libsbp PROPERTIES
        C_STANDARD 99
        C_STANDARD_REQUIRED ON)

if(MSVC)
  target_include_directories(test_libsbp PRIVATE ${PROJECT_SOURCE_DIR}/include/libsbp/)
else()
  target_include_directories(test_libsbp PRIVATE ${PROJECT_SOURCE_DIR}/include/libsbp/)
  if(APPLE)
    # Some libraries are available in non-standard places on apple.
    target_include_directories(test_libsbp PRIVATE /usr/local/include)

    # This is not a great way of doing this, but the proper cmake function
    # target_link_directories() was introduced in version 3.13 and we need to support
    # older versions for the moment. We can use target_link_libraries to pass arbitrary
    # linker flags, making sure that this instance is well protected and only applies
    # to a single platform. Don't use the extant link_directories() function since
    # that leaks the path to other targets.
    target_link_libraries(test_libsbp PRIVATE "-L/usr/local/lib")
  endif()
endif()

add_custom_command(
  TARGET test_libsbp POST_BUILD
  COMMENT "Running unit tests"
  COMMAND test_libsbp
)
