cmake_minimum_required(VERSION 3.13)

project(FastNoise)

set(SOURCES FastNoiseSIMD/FastNoiseSIMD.cpp
        FastNoiseSIMD/FastNoiseSIMD_avx2.cpp
        FastNoiseSIMD/FastNoiseSIMD_avx512.cpp
        FastNoiseSIMD/FastNoiseSIMD_internal.cpp
        FastNoiseSIMD/FastNoiseSIMD_neon.cpp
        FastNoiseSIMD/FastNoiseSIMD_sse2.cpp
        FastNoiseSIMD/FastNoiseSIMD_sse41.cpp)

add_library(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -pedantic
        -Wno-unused-parameter
        -Wno-implicit-fallthrough
        -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx)

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

add_executable(Test Main.cpp)
target_include_directories(Test PRIVATE FastNoiseSIMD)
target_link_libraries(Test ${PROJECT_NAME})
