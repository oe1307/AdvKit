add_executable(test_fgsm.exe attack/whitebox/test_fgsm.cpp)
target_include_directories(test_fgsm.exe PUBLIC ${ADVLIB})
target_link_libraries(test_fgsm.exe ${TORCH_LIBRARIES})
