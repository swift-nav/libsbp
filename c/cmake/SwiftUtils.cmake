macro(manifest)
  if (${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    set(OUTFLAG WRITE)
  else()
    set(OUTFLAG APPEND)
  endif()
endmacro()
  
macro(headerguard)
  manifest()
  if(TARGET ${ARGV0})
    file(${OUTFLAG} ${CMAKE_SOURCE_DIR}/manifest.txt "Not including ${PROJECT_NAME} from ${CMAKE_CURRENT_LIST_DIR}\n")
    # return from the caller context; this is why we need a macro instead of a function
    return()
  else()
    file(${OUTFLAG} ${CMAKE_SOURCE_DIR}/manifest.txt "Including ${PROJECT_NAME} from ${CMAKE_CURRENT_LIST_DIR}\n")
  endif()
  message("outflag: ${OUTFLAG}")
endmacro()

macro(swift_add_submodule)
  # NB! if(EXISTS) only behaves properly for absolute paths.  Unbelievable...
  if (EXISTS ${CMAKE_CURRENT_LIST_DIR}/${ARGV0}/CMakeLists.txt)
    add_subdirectory(${ARGV0})
  else()
    # firmware can do their thing
    find_package(${ARGV0})
  endif()
endmacro()
