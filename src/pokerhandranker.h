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

public:
    PokerHandRanker() {};
    constants::HandRank rank_hand(const PokerHand &h); // 1 (high card) - 10 (royal flush)
};

#endif // POKERHANDRANKER_H