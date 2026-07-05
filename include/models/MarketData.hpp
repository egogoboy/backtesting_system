#pragma once

#include <cstdint>
#include <string>

class MarketData {
  public:
    MarketData(const std::string &symbol, double open, double high, double low, double close,
               uint64_t timestamp)
        : symbol_{symbol}, open_{open}, high_{high}, low_{low}, close_{close},
          timestamp_{timestamp} {}

    std::string get_symbol() const {
        return symbol_;
    }

    double get_open() const {
        return open_;
    }

    double get_high() const {
        return high_;
    }

    double get_low() const {
        return low_;
    }

    double get_close() const {
        return close_;
    }

    uint64_t get_timestamp() const {
        return timestamp_;
    }

  private:
    std::string symbol_;
    double open_;
    double high_;
    double low_;
    double close_;
    uint64_t timestamp_;
};
