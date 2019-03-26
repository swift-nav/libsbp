#########################################################
#
# A simple double include guard in the style of C/C++ 
# headers to prevent a CMakeLists.txt being included twice
#
# Pass the name of a target and if that target has already
# been defined somewhere in the build the file which calls
# this module will not be processed any further.
#
# However, this is not a substitute for carefuly
# management of dependencies, it is simply a last resort
#
#########################################################
macro(DoubleIncludeGuard TGTNAME)
  if(TARGET ${TGTNAME})
    message(WARNING "Target ${TGTNAME} already defined")
    return()
  endif()

endmacro(DoubleIncludeGuard)
  
