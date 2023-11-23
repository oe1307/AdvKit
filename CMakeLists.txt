cmake_minimum_required(VERSION 3.5)
project(AdvKit)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE MATCHES Debug)
  add_compile_options(-O2 -Wall -Wextra)
  include(advlib/cmake/google_test.cmake)
endif()

include(advlib/cmake/libtorch.cmake)
