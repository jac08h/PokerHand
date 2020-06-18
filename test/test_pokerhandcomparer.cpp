#include <gtest/gtest.h>
#include <exception>
#include <vector>

#include "../src/pokerhand.h"
#include "../src/pokerhandcomparer.h"

TEST(TestPokerHandComparer, TieBreakers) {
    PokerHandComparer comparer = PokerHandComparer();

    // Royal flush on the table
    PokerHand first{"AS KS QS JS TS"}; 
    PokerHand second{"AS KS QS JS TS"}; 
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::Tie);

    // Straight flushes; 6,7,8 on the table
    first.update_hand("TS 9S 8S 7S 6S");
    second.update_hand("8S 7S 6S 5S 4S");
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::FirstWins);

    // Four-of-a-kinds
    first.update_hand("AS AH AD AC QS");
    second.update_hand("AS AH AD AC KD");
    // higher fifth card wins
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::SecondWins);

    first.update_hand("AS AH AD AC QS");
    second.update_hand("AS AH AD AC QS");
    // same hand ties
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::Tie);

    // Full house
    first.update_hand("AS AH AD KC KS");
    second.update_hand("3S 3H 3D QC QS");
    // higher triplet wins
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::FirstWins);
    first.update_hand("AS AH AD JC JS");
    second.update_hand("AS AH AD QC QS");
    // if same triplet, higher pair wins
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::SecondWins);
}
