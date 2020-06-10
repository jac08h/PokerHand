#include <gtest/gtest.h>
#include <exception>
#include <vector>

#include "../src/pokerhand.h"

TEST(TestPokerHand, InvalidInitializations) {
    EXPECT_THROW(PokerHand{"KS 2H 5C JA TD"}, std::runtime_error);

    EXPECT_THROW(PokerHand{"2S"}, std::runtime_error);
    EXPECT_THROW(PokerHand{"2S 2S 2S 2S 2S 2S"}, std::runtime_error);
}

TEST(TestPokerHand, UpdateHand) {
    PokerHand ph{"TS JS QS KS AS"};
}

TEST(TestPokerHand, RankCard) {
    PokerHand ph{"TS JS QS KS AS"};
    EXPECT_EQ(ph.rank_hand(), 10);

    ph.update_hand("3D 4D 5D 6D 7D");
    EXPECT_EQ(ph.rank_hand(), 9);

    ph.update_hand("KD KS KH KC 7D");
    EXPECT_EQ(ph.rank_hand(), 8);

    ph.update_hand("3D 4D 8D 2D AD");
    EXPECT_EQ(ph.rank_hand(), 6);

    ph.update_hand("3D 4S 5H 6D 7H");
    EXPECT_EQ(ph.rank_hand(), 5);
}