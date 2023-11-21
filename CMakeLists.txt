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

find_package(spdlog)

add_executable(spdlog_cmake main.cpp)

target_link_libraries(spdlog_cmake
  spdlog
)

add_executable(SPDLogTest src/main.cpp)

enable_testing()


add_test(NAME SanityCheckTest
         COMMAND $<TARGET_FILE:SPDLogTest> a b)