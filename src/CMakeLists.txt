set (CMAKE_CXX_STANDARD 17)

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

add_library(
    constants
    constants.h
)

set_target_properties(constants PROPERTIES LINKER_LANGUAGE CXX)



target_include_directories(card PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(
    pokerhand
    card
)

target_link_libraries(
    card
    constants
)