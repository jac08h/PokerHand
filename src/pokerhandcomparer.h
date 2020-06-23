#ifndef POKERHANDCOMPARER_H
#define POKERHANDCOMPARER_H

#include <utility>
#include "pokerhand.h"
#include "constants.h"
#include "pokerhandranker.h"


class PokerHandComparer
{
private:
    PokerHandRanker m_ranker = PokerHandRanker();

    std::map<int, int> count_card_occurences(const PokerHand &h);
    int get_value_of_x_of_a_kind(int x, const PokerHand &h);
    std::pair<int, int> get_sorted_values_of_two_pairs(const PokerHand &h);
    constants::Result compare_hands_with_identical_rank(const PokerHand &first, const PokerHand &second, constants::HandRank rank);
    constants::Result compare_sorted_hands(const PokerHand &first, const PokerHand &second); // make one by one comparisions starting from highest card


public:
    PokerHandComparer() {};
    constants::Result compare_cards(const PokerHand &first, const PokerHand &second);
};

#endif // POKERHANDCOMPARER_H