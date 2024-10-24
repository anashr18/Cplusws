
cmake_minimum_required(VERSION 3.22)

project(UnitTestProject VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# Enable ccache
set(CMAKE_C_COMPILER_LAUNCHER ccache)
set(CMAKE_CXX_COMPILER_LAUNCHER ccache)

set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

option(ENABLE_TESTING "Enable a unit test build." ON)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
# include(AddGitSubmodule)
include(FetchContent)
include(Docs)

# Set the base directory for FetchContent to cache downloads
set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/.cmake/FetchContent)

# Optionally, prevent FetchContent from checking for updates
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

set(JSON_BuildTests OFF CACHE INTERNAL "")
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 10.2.1
    GIT_SHALLOW TRUE)
set(FMT_TEST OFF CACHE BOOL "Disable fmt tests" FORCE)
set(FMT_DOC OFF CACHE BOOL "Disable fmt documentation" FORCE)
set(FMT_INSTALL OFF CACHE BOOL "Disable fmt installation" FORCE)
FetchContent_MakeAvailable(fmt)


set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "Disable spdlog tests" FORCE)
set(SPDLOG_BUILD_EXAMPLES OFF CACHE BOOL "Disable spdlog examples" FORCE)
set(SPDLOG_BUILD_BENCH OFF CACHE BOOL "Disable spdlog benchmarks" FORCE)
set(SPDLOG_INSTALL OFF CACHE BOOL "Disable spdlog installation" FORCE)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.13.0
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(spdlog)

set(CXXOPTS_BUILD_EXAMPLES OFF CACHE BOOL "Disable cxxopts examples" FORCE)
set(CXXOPTS_BUILD_TESTS OFF CACHE BOOL "Disable cxxopts tests" FORCE)
set(CXXOPTS_ENABLE_INSTALL OFF CACHE BOOL "Disable cxxopts installation" FORCE)
FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts
    GIT_TAG v3.1.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(cxxopts)



# Optimize Catch2 build
set(CATCH_BUILD_TESTING OFF CACHE BOOL "Disable Catch2's self-tests" FORCE)
set(CATCH_INSTALL_DOCS OFF CACHE BOOL "Disable installing Catch2 documentation" FORCE)
# if(ENABLE_TESTING)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v3.5.3
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
# endif()



add_subdirectory(configured)
# add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(app)
if(ENABLE_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()



