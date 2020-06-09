#ifndef POKERHAND_H
#define POKERHAND_H

#include <map>
#include <vector>
#include "card.h"
#include "constants.h"

class PokerHand
{
private:
    std::vector<Card> m_cards;

    bool is_full_house();
    bool is_x_of_a_kind(int x);
    bool is_two_pair();


public:
    PokerHand(const char* pokerhand);
    int highest_card();
    bool is_straight();
    bool is_flush();
    int rank_hand(); // 1 (high card) - 10 (royal flush)
    void print_cards();
};

#endif // POKERHAND_H