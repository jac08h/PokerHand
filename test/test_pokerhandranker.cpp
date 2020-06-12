#include <gtest/gtest.h>
#include <exception>
#include <vector>

#include "../src/pokerhand.h"
#include "../src/pokerhandranker.h"

TEST(TestPokerHandRanker, RankCard) {
    PokerHandRanker ranker = PokerHandRanker();

    PokerHand ph{"TS JS QS KS AS"};
    EXPECT_EQ(ranker.rank_hand(ph), 10);

    ph.update_hand("3D 4D 5D 6D 7D");
    EXPECT_EQ(ranker.rank_hand(ph), 9);

    ph.update_hand("KD KS KH KC 7D");
    EXPECT_EQ(ranker.rank_hand(ph), 8);

    ph.update_hand("3D 4D 8D 2D AD");
    EXPECT_EQ(ranker.rank_hand(ph), 6);

    ph.update_hand("3D 4S 5H 6D 7H");
    EXPECT_EQ(ranker.rank_hand(ph), 5);

    ph.update_hand("8D 8S 8H 6D 7H");
    EXPECT_EQ(ranker.rank_hand(ph), 4);

    ph.update_hand("AS AD KS KD 2H");
    EXPECT_EQ(ranker.rank_hand(ph), 3);

    ph.update_hand("AS AD 3S 5D 2H");
    EXPECT_EQ(ranker.rank_hand(ph), 2);

    ph.update_hand("JS AD 3S 5D 2H");
    EXPECT_EQ(ranker.rank_hand(ph), 1);
}