cmake_minimum_required(VERSION 3.0)

project(Calculator_project VERSION 1.0.0)

# add_library(math_lib
# addition.cpp
# division.cpp
# )
# add_library(print_lib
# print_result.cpp
# )

add_subdirectory(my_math)
add_subdirectory(my_print)

add_executable(calculator
main.cpp
)
target_link_libraries(calculator PRIVATE my_math my_print)

message("hellllloooo11111")
message(${CMAKE_INSTALL_PREFIX})
