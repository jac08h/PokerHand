#include <gtest/gtest.h>
#include <exception>
#include <vector>

#include "../src/pokerhand.h"
#include "../src/pokerhandranker.h"

TEST(TestPokerHandRanker, RankCard) {
    PokerHandRanker ranker = PokerHandRanker();

    PokerHand ph{"TS JS QS KS AS"};
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::ROYAL_FLUSH);

    ph.update_hand("3D 4D 5D 6D 7D");
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::STRAIGHT_FLUSH);

    ph.update_hand("KD KS KH KC 7D");
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::FOUR_OF_A_KIND);

    ph.update_hand("KD KS KH 7C 7D");
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::FULL_HOUSE);

    ph.update_hand("3D 4D 8D 2D AD");
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::FLUSH);

    ph.update_hand("3D 4S 5H 6D 7H");
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::STRAIGHT);

    ph.update_hand("8D 8S 8H 6D 7H");
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::THREE_OF_A_KIND);

    ph.update_hand("AS AD KS KD 2H");
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::TWO_PAIR);

    ph.update_hand("AS AD 3S 5D 2H");
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::ONE_PAIR);

    ph.update_hand("JS AD 3S 5D 2H");
    EXPECT_EQ(ranker.rank_hand(ph), constants::HandRank::HIGH_CARD);
}
