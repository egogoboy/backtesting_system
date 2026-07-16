#pragma once

#include <cstdint>

enum class Direction : std::uint8_t { LONG, SHORT };

inline Direction opposite(Direction direction) {
    switch (direction) {
    case Direction::LONG:
        return Direction::SHORT;
        break;
    case Direction::SHORT:
        return Direction::LONG;
        break;
    }
}
