foreach(target example cpp_example cpp_traits_example tcp_example tcp_2sigma_example)
    add_subdirectory(${target})
    add_dependencies(examples libsbp_${target})
endforeach()
