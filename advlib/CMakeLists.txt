# plugins
include(cmake/libtorch.cmake)
set(PLUGINS ${TORCH_LIBRARIES})

add_subdirectory(attack)
add_subdirectory(detect)
add_subdirectory(train)
