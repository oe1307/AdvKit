cmake_path(GET AdvLib_DIR PARENT_PATH ADVLIB_ROOT_DIR)
set(ADVLIB_INCLUDE_DIR ${ADVLIB_ROOT_DIR}/include)
set(ADVLIB_LIBRARIES ${ADVLIB_ROOT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ADVLIB_ROOT_DIR}/lib)

# include(${AdvLib_DIR}/../cmake/FetchOpenCV.cmake)
include(${ADVLIB_ROOT_DIR}/cmake/FetchTorch.cmake)

add_library(advlib SHARED ${ADVLIB_ROOT_DIR}/src/utils.cpp
                          ${ADVLIB_ROOT_DIR}/src/model.cpp
                          ${ADVLIB_ROOT_DIR}/src/base_config.cpp)
target_link_libraries(advlib ${TORCH_LIBRARIES})

include_directories(${ADVLIB_INCLUDE_DIR})
link_directories(${ADVLIB_LIBRARIES})
