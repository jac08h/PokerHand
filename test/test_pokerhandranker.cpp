#include <gtest/gtest.h>
#include <exception>
#include <vector>

#include "../src/pokerhand.h"
#include "../src/pokerhandranker.h"

TEST(TestPokerHandRanker, RankCard) {
    PokerHandRanker ranker = PokerHandRanker();

    PokerHand ph{"TS JS QS KS AS"};
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::ROYAL_FLUSH);

    ph.update_hand("3D 4D 5D 6D 7D");
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::STRAIGHT_FLUSH);

    ph.update_hand("KD KS KH KC 7D");
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::FOUR_OF_A_KIND);

    ph.update_hand("KD KS KH 7C 7D");
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::FULL_HOUSE);

    ph.update_hand("3D 4D 8D 2D AD");
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::FLUSH);

    ph.update_hand("3D 4S 5H 6D 7H");
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::STRAIGHT);

    ph.update_hand("8D 8S 8H 6D 7H");
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::THREE_OF_A_KIND);

    ph.update_hand("AS AD KS KD 2H");
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::TWO_PAIR);

    ph.update_hand("AS AD 3S 5D 2H");
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::ONE_PAIR);

    ph.update_hand("JS AD 3S 5D 2H");
    EXPECT_EQ(ranker.rank_hand(ph), HandRank::HIGH_CARD);
}

TEST(TestPokerHandRanker, TieBreakers) {
    PokerHandRanker ranker = PokerHandRanker();

    // Royal flush on the table
    PokerHand first{"AS KS QS JS TS"}; 
    PokerHand second{"AS KS QS JS TS"}; 
    EXPECT_EQ(ranker.compare_cards(first, second), Result::Tie);

    // Straight flushes; 6,7,8 on the table
    first.update_hand("TS 9S 8S 7S 6S");
    second.update_hand("8S 7S 6S 5S 4S");
    EXPECT_EQ(ranker.compare_cards(first, second), Result::FirstWins);

    // Four-of-a-kinds
    first.update_hand("AS AH AD AC QS");
    second.update_hand("AS AH AD AC KD");
    // higher fifth card wins
    EXPECT_EQ(ranker.compare_cards(first, second), Result::SecondWins);

    first.update_hand("AS AH AD AC QS");
    second.update_hand("AS AH AD AC QS");
    // same hand ties
    EXPECT_EQ(ranker.compare_cards(first, second), Result::Tie);

    // Full house
    first.update_hand("AS AH AD KC KS");
    second.update_hand("3S 3H 3D QC QS");
    // higher triplet wins
    EXPECT_EQ(ranker.compare_cards(first, second), Result::FirstWins);
    first.update_hand("AS AH AD JC JS");
    second.update_hand("AS AH AD QC QS");
    // if same triplet, higher pair wins
    EXPECT_EQ(ranker.compare_cards(first, second), Result::SecondWins);
}
