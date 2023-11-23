cmake_minimum_required(VERSION 3.5)
project(AdvKit)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
  add_compile_options(-O2 -Wall -Wextra)
  include(advlib/cmake/google_test.cmake)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/tests/bin)
  add_subdirectory(tests/advlib)
endif()

include(advlib/cmake/libtorch.cmake)
