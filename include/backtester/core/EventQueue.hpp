#pragma once

#include "backtester/events/Event.hpp"
#include <queue>

class EventQueue {
  public:
    void push(std::shared_ptr<Event> event) {
        queue_.push(std::move(event));
    }

    std::shared_ptr<Event> &front() {
        return queue_.front();
    }

    void pop() {
        queue_.pop();
    }

    bool empty() const {
        return queue_.empty();
    }

  private:
    std::queue<std::shared_ptr<Event>> queue_;
};
