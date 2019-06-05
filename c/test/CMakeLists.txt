if (CMAKE_CROSSCOMPILING)
  message(STATUS "Skipping unit tests, cross compiling")
else (CMAKE_CROSSCOMPILING)

  find_package(Check)
  if (NOT CHECK_FOUND)
    message(STATUS "Skipping unit tests, Check library not found!")
  else (NOT CHECK_FOUND)

    set(TEST_LIBS ${TEST_LIBS} ${CHECK_LIBRARIES} pthread sbp m)

    # Check needs to be linked against Librt on Linux
    if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
      set(TEST_LIBS ${TEST_LIBS} rt)
    endif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

    FILE(GLOB generated_c_sources auto*.c)
    add_executable(test_libsbp check_main.c check_edc.c check_sbp.c ${generated_c_sources})

    target_link_libraries(test_libsbp ${TEST_LIBS})
    set_target_properties(test_libsbp PROPERTIES
            C_STANDARD 99
            C_STANDARD_REQUIRED ON)

    if(MSVC)
      target_include_directories(test_libsbp PRIVATE ${PROJECT_SOURCE_DIR}/include/libsbp/)
    else()
      target_include_directories(test_libsbp PRIVATE ${PROJECT_SOURCE_DIR}/include/libsbp/ /usr/local/include/)
    endif()

    add_custom_command(
      TARGET test_libsbp POST_BUILD
      COMMENT "Running unit tests"
      COMMAND test_libsbp
    )

  endif (NOT CHECK_FOUND)
endif (CMAKE_CROSSCOMPILING)
