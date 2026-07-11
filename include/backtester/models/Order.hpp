#pragma once

#include "backtester/enums/Direction.hpp"
#include "backtester/enums/OrderStatus.hpp"
#include "backtester/enums/OrderType.hpp"
#include <cstdint>
#include <memory>
#include <string>

class Position;

class Order {
  public:
    static Order make_market(const std::string &symbol, Direction direction, double volume) {
        return Order(symbol, direction, volume, OrderType::MARKET, std::nullopt);
    }

    static Order make_limit(const std::string &symbol, Direction direction, double volume,
                            double entry_price) {
        return Order(symbol, direction, volume, OrderType::LIMIT, entry_price);
    }

    static Order make_stop(const std::string &symbol, Direction direction, double volume,
                           double entry_price) {
        return Order(symbol, direction, volume, OrderType::STOP, entry_price);
    }

    bool execute() {
        if (status_ != OrderStatus::PENDING) {
            return false;
        }

        status_ = OrderStatus::EXECUTED;
        return true;
    }

    bool cancel() {
        if (status_ != OrderStatus::PENDING) {
            return false;
        }

        status_ = OrderStatus::CANCELED;
        return true;
    }

    uint32_t get_id() const {
        return id_;
    }

    OrderStatus get_status() const {
        return status_;
    }

    const std::string &get_symbol() const {
        return symbol_;
    }

    Direction get_direction() const {
        return direction_;
    }

    double get_volume() const {
        return volume_;
    }

    OrderType get_type() const {
        return type_;
    }

    std::optional<double> get_entry_price() const {
        return entry_price_;
    }

  private:
    Order(const std::string &symbol, Direction direction, double volume, OrderType type,
          std::optional<double> entry_price)
        : id_{++last_order_id}, symbol_{symbol}, direction_{direction}, volume_{volume},
          type_{type}, entry_price_{entry_price} {}

    uint32_t id_;
    OrderStatus status_ = OrderStatus::PENDING;
    std::string symbol_;
    Direction direction_;
    double volume_;
    OrderType type_;
    std::optional<double> entry_price_;
    std::weak_ptr<Position> position_;

    static inline uint32_t last_order_id = 0;
};
