if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "Create a separate build directory")
endif()

cmake_minimum_required (VERSION 3.1)

project(test DESCRIPTION "Boost Serialization Test"
              LANGUAGES CXX)

find_package(Boost 1.56
             REQUIRED
             COMPONENTS
             program_options
             serialization)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)


set (TEST_VERSION_MAJOR 1)
set (TEST_VERSION_MINOR 3)
set (TEST_VERSION_PATCH 0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_PROFILE "-O3 -pg -g")
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

add_definitions(-DNTHREADS=1)

add_subdirectory(base)
add_subdirectory(module)

add_executable(test 
               main.cc
               options.h
               options.cc)

target_link_libraries(test
                      LINK_PUBLIC
                      base module
                      Boost::program_options
                      Boost::serialization
                      Threads::Threads)
