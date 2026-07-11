#pragma once

#include "backtester/enums/Direction.hpp"
#include "backtester/enums/PositionStatus.hpp"
#include "backtester/models/Order.hpp"
#include <cstdint>
#include <memory>
#include <optional>
#include <string>

class Position {
  public:
    Position(const std::string &symbol, double volume, Direction direction, double entry_price)
        : id_{++last_position_id}, symbol_{symbol}, volume_{volume}, direction_{direction},
          entry_price_{entry_price} {}

    bool close_position() {
        if (status_ != PositionStatus::OPEN) {
            return false;
        }

        status_ = PositionStatus::CLOSE;
        return true;
    }

    uint32_t get_id() const {
        return id_;
    }

    std::string get_symbol() const {
        return symbol_;
    }

    double get_volume() const {
        return volume_;
    }

    Direction get_direction() const {
        return direction_;
    }

    double get_entry_price() const {
        return entry_price_;
    }

    std::optional<double> get_exit_price() const {
        return exit_price_;
    }

    std::weak_ptr<Order> get_stop_loss_order() const {
        return stop_loss_order_;
    }

    std::weak_ptr<Order> get_take_profit_order() const {
        return take_profit_order_;
    }

    PositionStatus get_status() const {
        return status_;
    }

  private:
    uint32_t id_;
    std::string symbol_;
    double volume_;
    Direction direction_;
    double entry_price_;
    std::optional<double> exit_price_;
    std::weak_ptr<Order> stop_loss_order_;
    std::weak_ptr<Order> take_profit_order_;
    PositionStatus status_ = PositionStatus::OPEN;

    static inline uint32_t last_position_id = 0;
};
