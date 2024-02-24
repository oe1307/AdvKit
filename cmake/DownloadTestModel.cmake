set(RESNET18_URL "https://download.pytorch.org/models/resnet18-f37072fd.pth")
file(DOWNLOAD ${RESNET18_URL} ${CMAKE_SOURCE_DIR}/resnet18.pth)
