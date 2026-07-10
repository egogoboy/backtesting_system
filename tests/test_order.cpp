#include "backtester/enums/Direction.hpp"
#include "backtester/enums/OrderStatus.hpp"
#include "backtester/enums/OrderType.hpp"
#include "backtester/models/Order.hpp"
#include <gtest/gtest.h>

TEST(Order, PendingAfterCreation) {
    Order order("EURUSD", Direction::LONG, 1, OrderType::MARKET, 1);

    EXPECT_EQ(order.get_status(), OrderStatus::PENDING);
}

TEST(Order, CancelAfterExecution) {
    Order order("EURUSD", Direction::LONG, 1, OrderType::MARKET, 1);
    order.execute();

    EXPECT_EQ(order.cancel(), false);
    EXPECT_EQ(order.get_status(), OrderStatus::EXECUTED);
}

TEST(Order, Id) {
    Order first_order("EURUSD", Direction::LONG, 1, OrderType::MARKET, 1);
    EXPECT_EQ(first_order.get_id(), 1);

    Order second_order("EURUSD", Direction::LONG, 1, OrderType::MARKET, 1);
    EXPECT_EQ(second_order.get_id(), 2);
}
