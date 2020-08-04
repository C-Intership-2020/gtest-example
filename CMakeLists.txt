cmake_minimum_required(VERSION 3.15)
project(project_gtest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS --coverage) #https://www.jetbrains.com/help/clion/code-coverage-clion.html#run-coverage

add_executable(projectForTesting main.cpp MyClass.cpp MyClass.h)

include(GoogleTest)
find_package(GTest REQUIRED)
enable_testing()

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)

find_package(Boost REQUIRED COMPONENTS Chrono)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(TestsExecutable MyClassTest.cpp)
target_link_libraries(TestsExecutable GTest::GTest GTest::Main)
target_link_libraries(TestsExecutable ${Boost_LIBRARIES})

gtest_discover_tests(TestsExecutable)
