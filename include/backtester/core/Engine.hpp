#pragma once

#include "backtester/core/EventQueue.hpp"
#include "backtester/data_feed/DataFeed.hpp"
#include "backtester/strategy/Strategy.hpp"
#include <chrono>
#include <functional>

class Engine {
  public:
    Engine(Strategy &strategy, DataFeed &data_feed)
        : start_time_{std::chrono::system_clock::now()}, strategy_{strategy},
          data_feed_(data_feed) {
        strategy_.get().set_event_queue(event_queue_);
    }

    void run();

  private:
    std::chrono::system_clock::time_point start_time_;
    std::reference_wrapper<Strategy> strategy_;
    std::reference_wrapper<DataFeed> data_feed_;
    EventQueue event_queue_;
};
