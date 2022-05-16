cmake_minimum_required(VERSION 3.20)
project(Algos4j)

set(CMAKE_CXX_STANDARD 23)

add_library(Algos4j src/library.cpp src/sort/union_found.cpp headers/union_found.h headers/common.h)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        tests_proj
        tests/uf_test.cpp
        tests/priority_queue_test.cpp)
target_link_libraries(
        tests_proj
        Algos4j
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests_proj)