find_package(Python3 REQUIRED)

if(NOT Python3_FOUND)
  message(FATAL_ERROR "Python3 not found")
endif()

execute_process(COMMAND python3 tests/example/download_test_model.py)
