add_library(
    card
    card.h
    card.cpp
)

add_library(
    pokerhand
    pokerhand.h
    pokerhand.cpp
)



target_include_directories(card PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")