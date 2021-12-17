cmake_minimum_required (VERSION 3.20)
enable_testing()

project ("Avent_Of_Code")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#NOTE: for emacs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(PythonInterp REQUIRED)

find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)


add_subdirectory("utils")
target_precompile_headers(utils PUBLIC "utils/pch.h")

link_libraries(utils)

add_subdirectory("src")
target_link_libraries(main PRIVATE Advent)

add_subdirectory("tests")
target_link_libraries(tests PRIVATE Catch2::Catch2 Advent)

add_custom_target(solution ALL
                  COMMENT "Executiong post build scripts \"${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/post_build.py\""
                  COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/post_build.py ${CMAKE_BINARY_DIR}/bin
                  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
