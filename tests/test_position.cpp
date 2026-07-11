#include "backtester/enums/Direction.hpp"
#include "backtester/enums/PositionStatus.hpp"
#include "backtester/models/Position.hpp"
#include <gtest/gtest.h>

TEST(Position, Status) {
    Position position("EURUSD", 1, Direction::LONG, 1.178);
    EXPECT_EQ(position.get_status(), PositionStatus::OPEN);

    EXPECT_EQ(position.close_position(), true);
    EXPECT_EQ(position.get_status(), PositionStatus::CLOSE);
}
