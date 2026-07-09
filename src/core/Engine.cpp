#include "backtester/core/Engine.hpp"
#include "backtester/events/MarketEvent.hpp"
#include <memory>

void Engine::run() {
    while (!event_queue_.empty()) {
        std::shared_ptr<Event> event = event_queue_.front();
        event_queue_.pop();

        switch (event->get_type()) {
        case EventType::MARKET:
            strategy_->on_market(*std::static_pointer_cast<MarketEvent>(event));
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
