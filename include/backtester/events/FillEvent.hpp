#pragma once

#include "backtester/enums/EventType.hpp"
#include "backtester/enums/FillAction.hpp"
#include "backtester/events/Event.hpp"
#include "backtester/models/Position.hpp"
#include <memory>

class FillEvent : public Event {
  public:
    FillEvent(std::shared_ptr<const Position> position, FillAction action)
        : data_{std::move(position)}, action_{action} {}

    EventType get_type() const override {
        return EventType::FILL;
    }

    std::shared_ptr<const Position> get_data() const {
        return data_;
    }

    FillAction get_action() const {
        return action_;
    }

  private:
    std::shared_ptr<const Position> data_;
    FillAction action_;
};
