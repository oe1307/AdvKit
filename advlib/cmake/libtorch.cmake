find_package(Torch QUIET)

if(Torch_FOUND)
  message(STATUS "Found libtorch")
  return()
endif()

message(STATUS "Building libtorch")

set(URL "https://download.pytorch.org/libtorch")
if(NOT DEFINED CUDA)
  message(FATAL_ERROR "CUDA not defined")
elseif(${CUDA} STREQUAL "11.8")
  set(URL "${URL}/cu118/libtorch-cxx11-abi-shared-with-deps-2.0.1%2Bcu118.zip")
elseif(${CUDA} STREQUAL "12.1")
  set(URL "${URL}/cu121/libtorch-cxx11-abi-shared-with-deps-2.1.1%2Bcu121.zip")
elseif(${CUDA} STREQUAL "MPS")
  set(URL "${URL}/cpu/libtorch-macos-2.1.1.zip")
else()
  message(FATAL_ERROR "CUDA version not supported ${CUDA}")
endif()

include(FetchContent)
FetchContent_Declare(Torch URL ${URL})
FetchContent_MakeAvailable(Torch)
list(APPEND CMAKE_PREFIX_PATH ${torch_SOURCE_DIR})
find_package(Torch REQUIRED)

message(STATUS "Building libtorch - done")
