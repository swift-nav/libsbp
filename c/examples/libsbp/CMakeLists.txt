foreach(target example cpp_example cpp_traits_example)
    add_subdirectory(${target})
    add_dependencies(examples libsbp_${target})
endforeach()
