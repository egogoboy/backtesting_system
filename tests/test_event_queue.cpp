#include "backtester/core/EventQueue.hpp"
#include "backtester/events/MarketEvent.hpp"
#include <gtest/gtest.h>

TEST(EventQueue, FullWorkflow) {
    EventQueue queue;
    EXPECT_EQ(true, queue.empty());

    std::shared_ptr<MarketEvent> event =
        std::make_shared<MarketEvent>(MarketData("eurusd", {1.178, 1.179, 1.1775, 1.1779}, 1));
    queue.push(event);

    EXPECT_EQ(false, queue.empty());

    EXPECT_EQ(event->get_data(), dynamic_cast<MarketEvent *>(queue.front().get())->get_data());

    queue.pop();
    EXPECT_EQ(true, queue.empty());
}
