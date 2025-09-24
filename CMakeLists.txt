cmake_minimum_required(VERSION 3.10)

message(STATUS "==================================")

project(myProgram VERSION 1.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17) # C++ Standard (z.B. C++17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE PROJECT_SRC
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.c
    ${PROJECT_SOURCE_DIR}/src/*.h
    ${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/include/*.c
    ${PROJECT_SOURCE_DIR}/include/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/include/)


if(WIN32)
    # Windows-spezifische Einstellungen
    message(STATUS "===============================")
    message(STATUS "=== Configuring for Windows ===")
    message(STATUS "===============================")
    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_CXX_COMPILER "g++")

elseif(APPLE)
    # macOS-spezifische Einstellungen
    message(STATUS "=============================")
    message(STATUS "=== Configuring for macOS ===")
    message(STATUS "=============================")
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

elseif(UNIX)
    # Linux-spezifische Einstellungen
    message(STATUS "==================================")
    message(STATUS "=== Configuring for Linux/Unix ===")
    message(STATUS "==================================")
    set(CMAKE_GENERATOR "Unix Makefiles")

    set(CMAKE_C_COMPILER "gcc")
    set(CMAKE_CXX_COMPILER "g++")

else()
    message(FATAL_ERROR "Unbekannte Plattform")

endif()