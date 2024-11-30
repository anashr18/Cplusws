cmake_minimum_required(VERSION 3.5.0)
project(basic VERSION 0.1.0 LANGUAGES C CXX)

# Add the car library
# add_library(car STATIC car/car.cpp)
# add_library(integer STATIC integer/Integer.cpp)
# target_include_directories(integer PUBLIC integer)

# Add the basic executable
# add_executable(basic carinit.cpp)
# add_executable(basic copyconstructor.cpp test.cpp)
add_executable(classesExec class.cpp)
# target_link_libraries(classesExec PRIVATE integer)

