#pragma once

#include "backtester/enums/EventType.hpp"
#include "backtester/events/Event.hpp"
#include "backtester/models/Order.hpp"

class OrderEvent : public Event {
  public:
    OrderEvent(Order order) : data_{std::move(order)} {}

    EventType get_type() const override {
        return EventType::ORDER;
    }

    Order &get_data() {
        return data_;
    }

    Order &&take_data() {
        return std::move(data_);
    }

  private:
    Order data_;
};
