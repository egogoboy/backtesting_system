#pragma once

#include "backtester/enums/EventType.hpp"
#include <chrono>

class Event {
  public:
    Event() : timestamp_{std::chrono::system_clock::now()} {}

    std::chrono::system_clock::time_point get_time() const {
        return timestamp_;
    }

    virtual EventType get_type() const = 0;

    Event(const Event &other) = default;
    Event(Event &&other) = default;
    Event &operator=(const Event &other) = default;
    Event &operator=(Event &&other) = default;
    virtual ~Event() = default;

  private:
    std::chrono::system_clock::time_point timestamp_;
};
