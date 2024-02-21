list(APPEND CMAKE_PREFIX_PATH ${PROJECT_BINARY_DIR})
find_package(OpenCV QUIET)

if(OpenCV_FOUND)
  message(STATUS "Found OpenCV")
  return()
endif()

set(URL "https://github.com/opencv/opencv.git")
message(STATUS "Building OpenCV")

include(FetchContent)
FetchContent_Declare(OpenCV GIT_REPOSITORY ${URL})
FetchContent_MakeAvailable(OpenCV)
message(STATUS "Building OpenCV - done")
