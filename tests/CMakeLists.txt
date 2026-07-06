add_executable(unit_tests
    test_main.cpp

    test_csv_file_loader.cpp
)

target_link_libraries(unit_tests
    PRIVATE
        backtester_core
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
