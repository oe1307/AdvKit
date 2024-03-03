# FIXME: file name
if(EXISTS ${ADVLIB_ROOT_DIR}/.cache/cifar-10-batches-bin)
  message(STATUS "Detected Cifar10 dataset")
  return()
endif()

set(CIFAR_URL "https://www.cs.toronto.edu/~kriz/cifar-10-binary.tar.gz")
message(STATUS "Building Cifar10 dataset")
file(MAKE_DIRECTORY ${ADVLIB_ROOT_DIR}/.cache)
file(DOWNLOAD ${CIFAR_URL} "${ADVLIB_ROOT_DIR}/.cache/cifar-10-binary.tar.gz")
execute_process(
  COMMAND ${CMAKE_COMMAND} -E tar xzf
          "${ADVLIB_ROOT_DIR}/.cache/cifar-10-binary.tar.gz"
  WORKING_DIRECTORY ${ADVLIB_ROOT_DIR}/.cache)
message(STATUS "Building Cifar10 dataset - done")
