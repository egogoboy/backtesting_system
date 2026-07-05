#pragma once

#include "../models/MarketData.hpp"
#include <string>
#include <vector>

class CSVFileLoader {
  public:
    static std::vector<MarketData> load_file(const std::string &filename);

  private:
    static inline const int FILENAME_SYMBOL_LENGTH = 6;
};
