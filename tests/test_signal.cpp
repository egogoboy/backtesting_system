#include "backtester/enums/Direction.hpp"
#include "backtester/enums/OrderType.hpp"
#include "backtester/models/Signal.hpp"
#include <gtest/gtest.h>

TEST(Signal, Types) {
    Signal signal = Signal::make_market("EURUSD", Direction::LONG);
    EXPECT_EQ(signal.get_type(), OrderType::MARKET);

    signal = Signal::make_limit("EURUSD", Direction::LONG, 1);
    EXPECT_EQ(signal.get_type(), OrderType::LIMIT);

    signal = Signal::make_stop("EURUSD", Direction::LONG, 1);
    EXPECT_EQ(signal.get_type(), OrderType::STOP);
}
