cmake_minimum_required(VERSION 3.12)
project(libsbp C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake" "${CMAKE_CURRENT_LIST_DIR}/cmake/common")

include(GNUInstallDirs)
include(CCache)
include(SwiftCmakeOptions)
include(CompileOptions)
include(LanguageStandards)
include(ClangFormat)
include(SwiftClangTidy)
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

# Must be called after all targets have been created
swift_create_tidy_targets()
