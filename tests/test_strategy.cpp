#include "backtester/enums/Direction.hpp"
#include "backtester/events/MarketEvent.hpp"
#include "backtester/models/Signal.hpp"
#include "backtester/strategy/Strategy.hpp"
#include <gtest/gtest.h>

TEST(Strategy, BuyOnMarketStrategy) {
    class BuyOnMarketStrategy : public Strategy {
      public:
        void on_market(const MarketEvent &event) override {
            this->signal = std::make_unique<Signal>(
                Signal::make_market(event.get_data().get_symbol(), Direction::LONG));
        }

        std::unique_ptr<Signal> signal = nullptr;
    };

    MarketData data("EURUSD", {1, 2, 3, 4}, 5);

    MarketEvent event(data);
    BuyOnMarketStrategy strategy;
    strategy.on_market(event);

    EXPECT_EQ(strategy.signal.get() != nullptr, true);
    EXPECT_EQ(strategy.signal.get()->get_direction(), Direction::LONG);
}

TEST(Strategy, DoNothingStrategy) {
    class DoNothingStrategy : public Strategy {
      public:
        void on_market(const MarketEvent &event) override {}

        std::unique_ptr<Signal> signal = nullptr;
    };

    MarketData data("EURUSD", {1, 2, 3, 4}, 5);

    MarketEvent event(data);
    DoNothingStrategy strategy;
    strategy.on_market(event);

    EXPECT_EQ(strategy.signal.get() == nullptr, true);
}
