#pragma once

#include <cstdint>
#include <string>

struct OHLC {
    double open;
    double high;
    double low;
    double close;
};

class MarketData {
  public:
    MarketData(const std::string &symbol, const OHLC &ohlc, uint64_t timestamp)
        : symbol_{symbol}, open_{ohlc.open}, high_{ohlc.high}, low_{ohlc.low}, close_{ohlc.close},
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

    friend bool operator==(const MarketData &lhs, const MarketData &rhs) {
        return lhs.symbol_ == rhs.symbol_ && lhs.open_ == rhs.open_ && lhs.high_ == rhs.high_ &&
               lhs.low_ == rhs.low_ && lhs.close_ == rhs.close_ && lhs.timestamp_ == rhs.timestamp_;
    }

  private:
    std::string symbol_;
    double open_;
    double high_;
    double low_;
    double close_;
    uint64_t timestamp_;
};
