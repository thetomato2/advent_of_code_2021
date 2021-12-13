cmake_minimum_required (VERSION 3.20)

project ("Avent_Of_Code")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library (utils STATIC "utils/base_types.h" "utils/timer.h" "utils/timer.cpp")

target_precompile_headers(utils PUBLIC "utils/pch.h")

link_libraries(utils)

add_executable(day_01 "./src/day_01.cpp")
add_executable(day_02 "./src/day_02.cpp")
add_executable(day_03 "./src/day_03.cpp")
add_executable(day_04 "./src/day_04.cpp")
add_executable(day_05 "./src/day_05.cpp")
add_executable(day_06 "./src/day_06.cpp")
add_executable(day_07 "./src/day_07.cpp")
add_executable(day_08 "./src/day_08.cpp")

#TODO: maybe batch copy all input files
add_custom_command(
        TARGET day_01 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/day_01_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/day_01_input.txt)

add_custom_command(
        TARGET day_02 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/day_02_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/day_02_input.txt)

add_custom_command(
        TARGET day_03 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/day_03_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/day_03_input.txt)

add_custom_command(
        TARGET day_04 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/day_04_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/day_04_input.txt)

add_custom_command(
        TARGET day_05 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/day_05_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/day_05_input.txt)

add_custom_command(
        TARGET day_06 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/day_06_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/day_06_input.txt)

add_custom_command(
        TARGET day_07 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/day_07_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/day_07_input.txt)

add_custom_command(
        TARGET day_08 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/src/day_08_input.txt
                ${CMAKE_CURRENT_BINARY_DIR}/day_08_input.txt)
