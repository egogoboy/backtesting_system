#include "backtester/models/MarketData.hpp"
#include "backtester/utils/CSVFileLoader.hpp"

#include <fstream>
#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>

TEST(FileTest, NotFound) {
    EXPECT_ANY_THROW(CSVFileLoader::load_file("non-existent file"));
}

TEST(FileTest, ReadFromFile) {
    std::string temp_file = "temporary_csv_file.txt";

    std::ofstream fout(temp_file);

    uint64_t time = 0;
    OHLC ohlc = {1, 2, 3, 4};
    std::vector<MarketData> raw_data;

    for (int i = 0; i < 5; ++i) {
        fout << time << ", " << ohlc.open << ", " << ohlc.high << ", " << ohlc.low << ", "
             << ohlc.close << '\n';

        raw_data.push_back(MarketData("tempor", ohlc, time));

        ++ohlc.open;
        ++ohlc.high;
        ++ohlc.low;
        ++ohlc.close;
        ++time;
    }

    fout.close();

    std::vector<MarketData> loaded_data = CSVFileLoader::load_file(temp_file);

    std::filesystem::remove(temp_file);

    for (auto it1 = raw_data.begin(), it2 = loaded_data.begin();
         it1 != raw_data.end() && it2 != raw_data.end(); ++it1, ++it2) {
        EXPECT_EQ(*it1, *it2);
    }
}

TEST(FileTest, InvalidFile) {
    std::string temp_file = "temporary_csv_file.txt";

    std::ofstream fout(temp_file);

    fout << "dadf, 1, 2, 3, 4\n";
    fout << "0, 1, 2, 3, 4\n";

    fout.close();

    EXPECT_THROW(CSVFileLoader::load_file(temp_file), std::invalid_argument);

    std::filesystem::remove(temp_file);
}
