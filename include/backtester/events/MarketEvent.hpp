#pragma once

#include "backtester/enums/EventType.hpp"
#include "backtester/events/Event.hpp"
#include "backtester/models/MarketData.hpp"

class MarketEvent : public Event {
  public:
    MarketEvent(const MarketData &data) : data_{data} {}

    EventType get_type() const override {
        return EventType::MARKET;
    }

    const MarketData &get_data() const {
        return data_;
    }

  private:
    MarketData data_;
};
