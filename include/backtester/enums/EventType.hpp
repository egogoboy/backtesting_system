#pragma once

#include <cstdint>

enum class EventType : std::uint8_t { MARKET, SIGNAL, ORDER, FILL };
