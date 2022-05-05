foreach(target example cpp_example cpp_traits_example)
    add_subdirectory(${target})
    add_dependencies(examples libsbp_v4_${target})
endforeach()
