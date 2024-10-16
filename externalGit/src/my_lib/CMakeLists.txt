set(LIBRARY_SOURCES
    "my_lib.cpp")
set(HEADER_SOURCES
    "my_lib.h")

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES} ${HEADER_SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC 
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")