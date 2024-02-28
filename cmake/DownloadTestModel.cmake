find_package(Python3 REQUIRED)

if(NOT Python3_FOUND)
  message(FATAL_ERROR "Python3 not found")
endif()

execute_process(COMMAND "python3 -m pip install torchvision requests"
                RESULT_VARIABLE return)
if(NOT return EQUAL 0)
  message(FATAL_ERROR "Failed to install requirements")
endif()

execute_process(COMMAND "python3 -m pip install -r tests/requirements.txt"
                RESULT_VARIABLE return)
if(NOT return EQUAL 0)
  message(FATAL_ERROR "Failed to download test model")
endif()
