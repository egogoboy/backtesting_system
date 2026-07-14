#pragma once

#include "backtester/models/Instrument.hpp"
#include <cstdint>
#include <functional>

struct OHLC {
    double open;
    double high;
    double low;
    double close;
};

class MarketData {
  public:
    MarketData(const Instrument &instrument, const OHLC &ohlc, uint64_t timestamp)
        : instrument_{instrument}, open_{ohlc.open}, high_{ohlc.high}, low_{ohlc.low},
          close_{ohlc.close}, timestamp_{timestamp} {}

    const Instrument &get_instrument() const {
        return instrument_;
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
    std::reference_wrapper<const Instrument> instrument_;
    double open_;
    double high_;
    double low_;
    double close_;
    uint64_t timestamp_;
};
