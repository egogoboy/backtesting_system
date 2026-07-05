cmake_minimum_required(VERSION 3.24)

project(
    backtester
    VERSION 0.1.0
    DESCRIPTION "Backtesting engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)

enable_testing()

add_subdirectory(src)
add_subdirectory(external/googletest EXCLUDE_FROM_ALL)
add_subdirectory(tests)

# include(FetchContent)

# FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
# )

# FetchContent_MakeAvailable(googletest)

option(ENABLE_ASAN "Enable AddressSanitizer" ON)
option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")

    if(ENABLE_ASAN)
        add_compile_options(-fsanitize=address)
        add_link_options(-fsanitize=address)
    endif()

    if(ENABLE_UBSAN)
        add_compile_options(-fsanitize=undefined)
        add_link_options(-fsanitize=undefined)
    endif()

endif()
