cmake_minimum_required(VERSION 3.2)
project(libsbp C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake/common")

include(GNUInstallDirs)
include(CCache)
include(SwiftCmakeOptions)
include(CompileOptions)
include(LanguageStandards)
include(ClangTidy)
swift_create_project_options(
    HAS_TESTS
    HAS_DOCS
    TEST_PACKAGES "Check"
    )
include(CodeCoverage)
include(TestTargets)
add_code_coverage_all_targets()
swift_setup_clang_tidy(PATTERNS 'src/*.c')

if(libsbp_BUILD_TESTS)
  find_package(Googletest)
endif()

add_subdirectory(src)
if(libsbp_BUILD_DOCS)
  add_subdirectory(docs)
endif()
if(libsbp_BUILD_TESTS)
  add_subdirectory(test)
endif()

option(BUILD_EXAMPLES "" OFF)
if(BUILD_EXAMPLES)
  add_subdirectory(example/cpp_example)
  add_subdirectory(example/tcp_example)
  add_subdirectory(example/tcp_2sigma_example)
endif()
