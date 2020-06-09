cmake_minimum_required(VERSION 3.17.1)

set(This MyTestSuite)

add_executable (${This} test_card.cpp test_pokerhand.cpp)

target_link_libraries(
    ${This} PUBLIC
    gtest_main
    card
    pokerhand
)

add_test(
    NAME ${This}
    COMMAND ${This}
)