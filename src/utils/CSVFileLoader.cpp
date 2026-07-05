#include "utils/CSVFileLoader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<MarketData> CSVFileLoader::load_file(const std::string &filename) {
    std::ifstream fin(filename);

    if (!fin.is_open()) {
        throw std::runtime_error("load_file: File not found!");
    }

    std::string symbol = filename.substr(0, FILENAME_SYMBOL_LENGTH);

    std::vector<MarketData> data;
    std::string line;

    while (std::getline(fin, line)) {
        std::stringstream line_stream(line);

        std::string string_time;
        line_stream >> string_time;
        uint64_t time = std::stoull(string_time);

        OHLC ohlc = {};
        line_stream >> ohlc.open >> ohlc.high >> ohlc.low >> ohlc.close;

        data.push_back(MarketData(symbol, ohlc, time));
    }

    fin.close();

    return data;
}
