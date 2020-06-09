#include <gtest/gtest.h>
#include <exception>
#include <vector>

#include "../src/card.h"

TEST(TestCard, InvalidInitializations) {
    // invalid length
    EXPECT_THROW(Card{""}, std::runtime_error);
    EXPECT_THROW(Card{"A"}, std::runtime_error);
    EXPECT_THROW(Card{"2"}, std::runtime_error);
    EXPECT_THROW(Card{"AA2"}, std::runtime_error);

    // invalid card value
    EXPECT_THROW(Card{"XS"}, std::runtime_error);
    EXPECT_THROW(Card{"0S"}, std::runtime_error);
    EXPECT_THROW(Card{"1S"}, std::runtime_error);

    // invalid card suit
    EXPECT_THROW(Card{"3A"}, std::runtime_error);
    EXPECT_THROW(Card{"3K"}, std::runtime_error);
    EXPECT_THROW(Card{"3M"}, std::runtime_error);
}

TEST(TestCard, ValidInitializations) {
    std::vector<char> POSSIBLE_SUITS {'S', 'H', 'D', 'C'};
    std::vector<char> POSSIBLE_VALUES {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    std::string card_string;
    for (char suit: POSSIBLE_SUITS) {
        for (char value: POSSIBLE_VALUES) {
            card_string = std::string() + value + suit;
            ASSERT_NO_THROW(Card{card_string});
        }
    }
}

TEST(TestCard, GetCardValue) {
    EXPECT_EQ(Card{"4S"}.get_int_value(), 4);
    EXPECT_EQ(Card{"9S"}.get_int_value(), 9);
    EXPECT_EQ(Card{"TS"}.get_int_value(), 10);
    EXPECT_EQ(Card{"AS"}.get_int_value(), 14);
}