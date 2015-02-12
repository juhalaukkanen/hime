project(hime LANGUAGES C CXX ASM)

cmake_minimum_required(VERSION 3.0)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(hime hime.cpp hime.h)
target_compile_options(hime PRIVATE "--std=c++11")

add_executable(HimeTest test_hime.cpp)
target_link_libraries(HimeTest hime libgmock libgtest)
target_compile_options(HimeTest PRIVATE "--std=c++11")
add_dependencies(HimeTest libgmock libgtest)
add_test(HimeTest HimeTest)

add_executable(RotateTest test_rotate.cpp hlrotate.h)
target_link_libraries(RotateTest libgmock libgtest)
target_compile_options(RotateTest PRIVATE "--std=c++11")
add_test(RotateTest RotateTest)