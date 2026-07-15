#pragma once

#include "backtester/models/Position.hpp"
class PnLCalculator {
  public:
    static double get_position_realized_pnl(const Position &position);

    static double get_position_unrealized_pnl(const Position &position, double current_price);
};
