#pragma once

#include "backtester/enums/Direction.hpp"
#include "backtester/enums/OrderType.hpp"
#include <optional>
#include <string>

class Signal {
  public:
    Signal(const std::string &symbol, Direction direction, OrderType type, double entry_price,
           double stop_loss = 0, double take_profit = 0)
        : symbol_{symbol}, direction_{direction}, type_{type}, entry_price_{entry_price},
          stop_loss_price_{stop_loss}, take_profit_price_{take_profit} {}

    std::string get_symbol() const {
        return symbol_;
    }

    Direction get_direction() const {
        return direction_;
    }

    OrderType get_type() const {
        return type_;
    }

    double get_entry_price() const {
        return entry_price_;
    }

    std::optional<double> get_stop_loss_price() const {
        return stop_loss_price_;
    }

    std::optional<double> get_take_profit_price() const {
        return take_profit_price_;
    }

  private:
    std::string symbol_;
    Direction direction_;
    OrderType type_;
    double entry_price_;
    std::optional<double> stop_loss_price_;
    std::optional<double> take_profit_price_;
};
