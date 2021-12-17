
add_library(Advent STATIC
            "day_01.hpp"
            "day_01.cpp"
            # "day_02.cpp"
            # "day_03.cpp"
            # "day_04.cpp"
            # "day_05.cpp"
            # "day_06.cpp"
            # "day_07.cpp"
            "day_08.cpp"
            "day_08.hpp"
            )


target_include_directories(Advent
                           PUBLIC
                           $<INSTALL_INTERFACE:src>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                           )

add_executable(main "main.cpp")
