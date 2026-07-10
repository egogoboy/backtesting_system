#pragma once

#include "backtester/enums/Direction.hpp"
#include "backtester/enums/OrderType.hpp"
#include <optional>
#include <string>

class Signal {
  public:
    static Signal make_market(const std::string &symbol, Direction direction,
                              std::optional<double> stop_loss = std::nullopt,
                              std::optional<double> take_profit = std::nullopt) {
        return Signal(symbol, direction, OrderType::MARKET, std::nullopt, stop_loss, take_profit);
    }

    static Signal make_limit(const std::string &symbol, Direction direction, double entry_price,
                             std::optional<double> stop_loss = std::nullopt,
                             std::optional<double> take_profit = std::nullopt) {
        return Signal(symbol, direction, OrderType::LIMIT, entry_price, stop_loss, take_profit);
    }

    static Signal make_stop(const std::string &symbol, Direction direction, double entry_price,
                            std::optional<double> stop_loss = std::nullopt,
                            std::optional<double> take_profit = std::nullopt) {
        return Signal(symbol, direction, OrderType::STOP, entry_price, stop_loss, take_profit);
    }

    std::string get_symbol() const {
        return symbol_;
    }

    Direction get_direction() const {
        return direction_;
    }

    OrderType get_type() const {
        return type_;
    }

    std::optional<double> get_entry_price() const {
        return entry_price_;
    }

    std::optional<double> get_stop_loss_price() const {
        return stop_loss_price_;
    }

    std::optional<double> get_take_profit_price() const {
        return take_profit_price_;
    }

  private:
    Signal(const std::string &symbol, Direction direction, OrderType type,
           std::optional<double> entry_price, std::optional<double> stop_loss,
           std::optional<double> take_profit)
        : symbol_{symbol}, direction_{direction}, type_{type}, entry_price_{entry_price},
          stop_loss_price_{stop_loss}, take_profit_price_{take_profit} {}

    std::string symbol_;
    Direction direction_;
    OrderType type_;
    std::optional<double> entry_price_;
    std::optional<double> stop_loss_price_;
    std::optional<double> take_profit_price_;
};
