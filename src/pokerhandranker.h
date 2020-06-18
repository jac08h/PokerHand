#ifndef POKERHANDRANKER_H
#define POKERHANDRANKER_H

#include <vector>
#include <map>
#include "pokerhand.h"
#include "card.h"

enum class Result { FirstWins, Tie, SecondWins};
enum class HandRank {
    ROYAL_FLUSH,
    STRAIGHT_FLUSH,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    FLUSH,
    STRAIGHT,
    THREE_OF_A_KIND,
    TWO_PAIR,
    ONE_PAIR,
    HIGH_CARD,
};

class PokerHandRanker
{
private:
    std::vector<Card> m_cards;

    std::map<int, int> count_card_occurences();

    bool is_royal_flush();
    bool is_straight_flush();
    bool is_x_of_a_kind(int x);
    bool is_full_house();
    bool is_flush();
    bool is_straight();
    bool is_two_pair();
    int highest_card();

    int get_value_of_x_of_a_kind(int x, const PokerHand &h);
    Result compare_hands_with_identical_rank(const PokerHand &first, const PokerHand &second, HandRank rank);
    Result compare_sorted_hands(const PokerHand &first, const PokerHand &second); // make one by one comparisions starting from highest card

public:
    PokerHandRanker() {};
    HandRank rank_hand(const PokerHand &h); // 1 (high card) - 10 (royal flush)
    Result compare_cards(const PokerHand &first, const PokerHand &second);
};

#endif // POKERHANDRANKER_H