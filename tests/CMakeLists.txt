add_executable(tests
                "tests.cpp"
                )


catch_discover_tests(tests
                WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
                )
