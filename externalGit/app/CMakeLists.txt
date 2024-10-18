# Ensure CMake searches for the Python interpreter and development libraries
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Define the executable target from the main C++ source file
add_executable(${EXECUTABLE_NAME} "main.cpp")

# Link Python libraries to the executable
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${Python3_LIBRARIES})

# Add include directories for Python headers
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${Python3_INCLUDE_DIRS})

# Ensure the Python module directory is included in the project
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/python_modules)

# Link any additional libraries required by your project
# Replace 'LIBRARY_NAME' with the actual name of the library to link.
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})