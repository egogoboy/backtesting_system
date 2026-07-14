#pragma once

#include "backtester/models/Instrument.hpp"
#include "backtester/models/MarketData.hpp"
#include <string>
#include <vector>

class CSVFileLoader {
  public:
    static std::vector<MarketData> load_file(const std::string &filename,
                                             const Instrument &instrument);

  private:
    static inline const int FILENAME_SYMBOL_LENGTH = 6;
};
