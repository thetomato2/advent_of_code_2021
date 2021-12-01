cmake_minimum_required (VERSION 3.20)

project ("AdventOfCode")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library (Utils STATIC "utils/BaseTypes.h" "utils/Timer.h" "utils/Timer.cpp" "utils/Utils.h")
target_precompile_headers(Utils PUBLIC "utils/pch.h")
link_libraries(Utils)

add_subdirectory("2020/1")


