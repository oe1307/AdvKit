if(EXISTS ${ADVLIB_ROOT_DIR}/tests/example/test_model_jit.pth)
  message(STATUS "Detected TestModel")
  return()
endif()

find_package(Python3 REQUIRED)

if(NOT Python3_FOUND)
  message(FATAL_ERROR "Python3 not found")
endif()

message(STATUS "Building TestModel")
execute_process(
  COMMAND python3 -m pip install torchvision requests
  RESULT_VARIABLE STATUS
  OUTPUT_VARIABLE OUTPUT
  ERROR_VARIABLE ERROR)
if(STATUS AND NOT STATUS EQUAL 0)
  message(FATAL_ERROR "Failed to install requirements for TestModel:\n${ERROR}")
else()
  message(STATUS "Installed requirements for TestModel")
endif()

execute_process(
  COMMAND python3 ${ADVLIB_ROOT_DIR}/tests/example/download_model.py
  RESULT_VARIABLE STATUS
  OUTPUT_VARIABLE OUTPUT
  ERROR_VARIABLE ERROR)
if(STATUS AND NOT STATUS EQUAL 0)
  message(FATAL_ERROR "Failed to download TestModel:\n${ERROR}")
else()
  message(STATUS "Building TestModel - done")
endif()
