cmake_minimum_required(VERSION 3.24)

project(backtester LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BT_ENABLE_ASAN "ASAN" ON)
option(BT_ENABLE_UBSAN "UBSAN" ON)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(apps/backtester_cli)
add_subdirectory(external/googletest EXCLUDE_FROM_ALL)
add_subdirectory(tests)
