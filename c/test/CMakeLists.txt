if (CMAKE_CROSSCOMPILING)
  message(STATUS "Skipping unit tests, cross compiling")
else (CMAKE_CROSSCOMPILING)

  find_package(Check)
  if (NOT CHECK_FOUND)
    message(STATUS "Skipping unit tests, Check library not found!")
  else (NOT CHECK_FOUND)

    include_directories(${CHECK_INCLUDE_DIRS})
    set(TEST_LIBS ${TEST_LIBS} ${CHECK_LIBRARIES} pthread sbp m)

    # Check needs to be linked against Librt on Linux
    if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
      set(TEST_LIBS ${TEST_LIBS} rt)
    endif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

    include_directories("${PROJECT_SOURCE_DIR}/include/libsbp")

    add_executable(test_libsbp
      check_acquisition.c
      check_bootload.c
      check_edc.c
      check_file_io.c
      check_flash.c
      check_main.c
      check_navigation.c
      check_observation.c
      check_piksi.c
      check_sbp.c
      check_settings.c
      check_system.c
      check_tracking.c
    )

    target_link_libraries(test_libsbp ${TEST_LIBS})
    add_custom_command(
      TARGET test_libsbp POST_BUILD
      COMMENT "Running unit tests"
      COMMAND test_libsbp
    )

  endif (NOT CHECK_FOUND)
endif (CMAKE_CROSSCOMPILING)
