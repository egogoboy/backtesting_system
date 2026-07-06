add_executable(backtester_cli
    main.cpp
)

target_link_libraries(backtester_cli
    PRIVATE backtester_core
)
