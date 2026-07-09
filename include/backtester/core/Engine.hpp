#pragma once

#include "backtester/core/EventQueue.hpp"
#include "backtester/strategy/Strategy.hpp"
#include <chrono>

class Engine {
  public:
    Engine(Strategy &strategy)
        : start_time_{std::chrono::system_clock::now()}, strategy_{strategy.shared_from_this()} {
        strategy_->set_event_queue(event_queue_);
    }

    void run();

  private:
    std::chrono::system_clock::time_point start_time_;
    std::shared_ptr<Strategy> strategy_;
    EventQueue event_queue_;
};
