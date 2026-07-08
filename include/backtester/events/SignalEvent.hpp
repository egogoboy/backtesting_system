#pragma once

#include "backtester/enums/EventType.hpp"
#include "backtester/events/Event.hpp"
#include "backtester/models/Signal.hpp"

class SignalEvent : public Event {
  public:
    SignalEvent(const Signal &signal) : data_{signal} {}

    EventType get_type() const override {
        return EventType::SIGNAL;
    }

  private:
    Signal data_;
};
