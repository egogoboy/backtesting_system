#pragma once

#include "backtester/enums/EventType.hpp"
#include "backtester/events/Event.hpp"
#include "backtester/models/Position.hpp"
#include <memory>

class FillEvent : public Event {
  public:
    FillEvent(std::shared_ptr<const Position> position) : data_{std::move(position)} {}

    EventType get_type() const override {
        return EventType::FILL;
    }

    std::shared_ptr<const Position> get_data() const {
        return data_;
    }

  private:
    std::shared_ptr<const Position> data_;
};
