#pragma once

#include "backtester/events/Event.hpp"
#include <chrono>
#include <memory>
#include <queue>

class Engine {
  public:
    Engine() : start_time_{std::chrono::system_clock::now()} {}

    void run() {
        while (!event_queue_.empty()) {
            switch (event_queue_.front()->get_type()) {
            case EventType::MARKET:
                break;
            case EventType::SIGNAL:
                break;
            case EventType::ORDER:
                break;
            case EventType::FILL:
                break;
            }
        }
    }

  private:
    std::chrono::system_clock::time_point start_time_;
    std::queue<std::shared_ptr<Event>> event_queue_;
};
