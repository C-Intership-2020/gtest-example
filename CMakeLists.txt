cmake_minimum_required(VERSION 3.15)
project(project_gtest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(projectForTesting main.cpp MyClass.cpp MyClass.h)

include(GoogleTest)
find_package(GTest REQUIRED)
enable_testing()

add_executable(TestsExecutable MyClassTest.cpp)
target_link_libraries(TestsExecutable GTest::GTest GTest::Main)

gtest_discover_tests(TestsExecutable)
