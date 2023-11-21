cmake_minimum_required(VERSION 3.15...3.25)

project(SPDLogTest
  VERSION
    1.0
  DESCRIPTION
    "Very nice project"
  LANGUAGES
    CXX
)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(external/spdlog)
add_subdirectory(external/googletest)

#find_package(spdlog)


add_executable(SPDLogTest src/main.cpp)

target_link_libraries(SPDLogTest
  spdlog
)

include(CTest)
enable_testing()


add_test(NAME SanityCheckTest
         COMMAND $<TARGET_FILE:SPDLogTest> a b)

include(GoogleTest)

add_executable(
  mytest
  src/test.cpp
)
target_link_libraries(
  mytest
  GTest::gtest_main
)


gtest_discover_tests(mytest)