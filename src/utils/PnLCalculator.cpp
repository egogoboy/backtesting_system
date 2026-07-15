#include "backtester/utils/PnLCalculator.hpp"
#include <stdexcept>

double PnLCalculator::get_position_unrealized_pnl(const Position &position, double current_price) {
    int multiplier = 1;
    if (position.get_direction() == Direction::SHORT) {
        multiplier = -1;
    }

    return (current_price - position.get_entry_price()) * position.get_instrument().get_lot_size() *
           position.get_quantity() * multiplier;
}

double PnLCalculator::get_position_realized_pnl(const Position &position) {
    if (position.get_status() != PositionStatus::CLOSE) {
        throw std::runtime_error("Position must be closed.");
    }

    return get_position_unrealized_pnl(position, position.get_exit_price().value());
}
