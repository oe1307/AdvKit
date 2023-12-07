find_package(Torch QUIET)

if(Torch_FOUND)
  message(STATUS "Found libtorch")
  return()
endif()

message(STATUS "Building libtorch")

set(URL "https://download.pytorch.org/libtorch")
if(NOT DEFINED DEVICE)
  message(FATAL_ERROR "DEVICE not defined")
elseif(${DEVICE} STREQUAL "11.8")
  set(URL "${URL}/cu118/libtorch-cxx11-abi-shared-with-deps-2.0.1%2Bcu118.zip")
elseif(${DEVICE} STREQUAL "12.1")
  set(URL "${URL}/cu121/libtorch-cxx11-abi-shared-with-deps-2.1.1%2Bcu121.zip")
elseif(${DEVICE} STREQUAL "mps")
  set(URL "${URL}/cpu/libtorch-macos-2.1.1.zip")
else()
  message(FATAL_ERROR "${DEVICE} is not supported")
endif()

include(FetchContent)
FetchContent_Declare(Torch URL ${URL})
FetchContent_MakeAvailable(Torch)
list(APPEND CMAKE_PREFIX_PATH ${torch_SOURCE_DIR})
find_package(Torch REQUIRED)

message(STATUS "Building libtorch - done")
