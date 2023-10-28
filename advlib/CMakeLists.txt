cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0135 NEW)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(AdEx_cpp)
add_compile_options(-O2 -Wall -Wextra)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/src)

# plugins
include(cmake/libtorch.cmake)
set(PLUGINS ${TORCH_LIBRARIES})

add_subdirectory(src)
