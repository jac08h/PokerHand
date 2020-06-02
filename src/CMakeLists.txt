add_library(
    my-lib
    card.h
    card.cpp
)

target_include_directories(my-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")