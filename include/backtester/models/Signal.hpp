#pragma once

#include "backtester/enums/Direction.hpp"
#include "backtester/enums/OrderType.hpp"
#include "backtester/models/Instrument.hpp"
#include <optional>

class Signal {
  public:
    static Signal make_market(const Instrument &instrument, Direction direction,
                              std::optional<double> stop_loss = std::nullopt,
                              std::optional<double> take_profit = std::nullopt) {
        return Signal(instrument, direction, OrderType::MARKET, std::nullopt, stop_loss,
                      take_profit);
    }

    static Signal make_limit(const Instrument &instrument, Direction direction, double entry_price,
                             std::optional<double> stop_loss = std::nullopt,
                             std::optional<double> take_profit = std::nullopt) {
        return Signal(instrument, direction, OrderType::LIMIT, entry_price, stop_loss, take_profit);
    }

    static Signal make_stop(const Instrument &instrument, Direction direction, double entry_price,
                            std::optional<double> stop_loss = std::nullopt,
                            std::optional<double> take_profit = std::nullopt) {
        return Signal(instrument, direction, OrderType::STOP, entry_price, stop_loss, take_profit);
    }

    const Instrument &get_instrument() const {
        return instrument_;
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
    Signal(const Instrument &instrument, Direction direction, OrderType type,
           std::optional<double> entry_price, std::optional<double> stop_loss,
           std::optional<double> take_profit)
        : instrument_{instrument}, direction_{direction}, type_{type}, entry_price_{entry_price},
          stop_loss_price_{stop_loss}, take_profit_price_{take_profit} {}

    std::reference_wrapper<const Instrument> instrument_;
    Direction direction_;
    OrderType type_;
    std::optional<double> entry_price_;
    std::optional<double> stop_loss_price_;
    std::optional<double> take_profit_price_;
};
