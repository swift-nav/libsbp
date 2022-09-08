cmake_minimum_required(VERSION 3.12)
project(libsbp C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake/common")
option(I_KNOW_WHAT_I_AM_DOING_AND_HOW_DANGEROUS_IT_IS__LIBSBP_DISABLE_CRC_VALIDATION "Disable all CRC validation in Libsbp" OFF)

include(GNUInstallDirs)
include(CCache)
include(SwiftCmakeOptions)
include(CompileOptions)
include(LanguageStandards)
include(ClangFormat)
include(ClangTidy)
swift_create_project_options(
    HAS_TESTS
    HAS_DOCS
    TEST_PACKAGES "Check"
    )
include(CodeCoverage)
include(SwiftTargets)
include(TestTargets)
add_code_coverage_all_targets()
# TODO: Reformatting is limited to generated files; it should be expanded to cover all files
swift_setup_clang_format(PATTERNS 'include/*.h' 'test/*.c' 'test/*.h' 'test/cpp/*.cc')

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
add_subdirectory(examples)

swift_validate_targets()
swift_create_clang_tidy_targets()
