cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0135 NEW)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(AdvKit)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include(advlib/cmake/libtorch.cmake)

if(CMAKE_BUILD_TYPE MATCHES Debug)
  add_compile_options(-O2 -Wall -Wextra)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/tests/bin)
  add_subdirectory(tests/advlib)
endif()
