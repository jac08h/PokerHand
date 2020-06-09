#include <gtest/gtest.h>
#include <exception>
#include <vector>

#include "../src/pokerhand.h"

TEST(TestPokerHand, InvalidInitializations) {
    EXPECT_THROW(PokerHand{"KS 2H 5C JA TD"}, std::runtime_error);

    EXPECT_THROW(PokerHand{"2S"}, std::runtime_error);
    EXPECT_THROW(PokerHand{"2S 2S 2S 2S 2S 2S"}, std::runtime_error);
}

TEST(TestPokerHand, HighestCard) {
    PokerHand ph{"4S 5D 2H TD JS"};
    EXPECT_EQ(ph.highest_card(), 11);
}

// TODO: Test flush, straight