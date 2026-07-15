add_library(backtester_core)

target_include_directories(backtester_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_sources(backtester_core
    PRIVATE
        core/Engine.cpp

        data_feed/DataFeed.cpp

        enums/EventType.cpp

        events/Event.cpp
        events/MarketEvent.cpp

        portfolio/Portfolio.cpp

        models/MarketData.cpp

        utils/CSVFileLoader.cpp
        utils/PnLCalculator.cpp
)
