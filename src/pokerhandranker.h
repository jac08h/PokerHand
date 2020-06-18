#ifndef POKERHANDRANKER_H
#define POKERHANDRANKER_H

#include <vector>
#include <map>
#include "pokerhand.h"
#include "card.h"
#include "constants.h"



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
    constants::Result compare_hands_with_identical_rank(const PokerHand &first, const PokerHand &second, constants::HandRank rank);
    constants::Result compare_sorted_hands(const PokerHand &first, const PokerHand &second); // make one by one comparisions starting from highest card

public:
    PokerHandRanker() {};
    constants::HandRank rank_hand(const PokerHand &h); // 1 (high card) - 10 (royal flush)
    constants::Result compare_cards(const PokerHand &first, const PokerHand &second);
};

#endif // POKERHANDRANKER_H