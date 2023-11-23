# plugins
include(cmake/libtorch.cmake)
set(PLUGINS ${TORCH_LIBRARIES})

add_subdirectory(attacker)
add_subdirectory(base)
add_subdirectory(selector)
add_subdirectory(utils)

set(BASE_LIB ${PLUGINS} attacker base selector utils)

add_executable(run.exe main.cpp)
target_link_libraries(run.exe ${BASE_LIB})

add_executable(test.exe test.cpp)
target_link_libraries(test.exe ${BASE_LIB})
