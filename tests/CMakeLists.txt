add_executable(test_engine
    test_main.cpp
    test_csv_file_loader.cpp
)

target_link_libraries(test_engine
    PRIVATE
        backtester
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(test_engine)
