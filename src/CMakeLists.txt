add_library(backtester
    main.cpp
)

target_include_directories(backtester
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(backtester PUBLIC cxx_std_20)
