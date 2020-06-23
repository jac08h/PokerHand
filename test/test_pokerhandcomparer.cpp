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

    // Four-of-a-kindS
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

    // Flush
    // Highest hand wins
    first.update_hand("TD 9D 8D 7D 5D");
    second.update_hand("TD 9D 8D 7D 2D");
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::FirstWins);

    first.update_hand("TD 9D 8D 7D 6D");
    second.update_hand("TD 9D 8D 7D 6D");
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::Tie);

    // Straight 
    // Highest hand wins
    first.update_hand("3D 4S 5H 6S 7H");
    second.update_hand("3D 4S 5H 6S 2H");
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::FirstWins);

    // Three-of-a-kind
    // Fourth card if same triplet decides
    first.update_hand("AD AS AH 7S 6S");
    second.update_hand("AD AS AH KS 2S");
    EXPECT_EQ(comparer.compare_cards(first, second),  constants::Result::SecondWins);


}