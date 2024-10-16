# cmake_minimum_required(VERSION 3.22)

# project(CppProjectTemplate VERSION 1.0.0 LANGUAGES C CXX)

# set(CMAKE_CXX_STANDARD          20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS        OFF)

# set(LIBRARY_NAME Library)
# set(EXECUTABLE_NAME Executable)

# set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
# include(AddGitSubmodule)

# add_git_submodule(external/json)

# add_subdirectory(configured)
# add_subdirectory(external)
# add_subdirectory(src)
# add_subdirectory(app)

cmake_minimum_required(VERSION 3.22)
project(EmbedPythonHelloWorld VERSION 1.0.0 LANGUAGES C CXX)

# Find Python interpreter and libraries
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)

# Add the main.cpp executable
add_executable(main main.cpp)

# Link Python libraries to the executable
target_link_libraries(main ${Python3_LIBRARIES})

# Add include directories for Python
target_include_directories(main PRIVATE ${Python3_INCLUDE_DIRS})

# Ensure the Python module directory is included in the project
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/python_modules)

